#include "Arduino_H7_Video.h"
#include "ArduinoGraphics.h"
#include "Arduino_GigaDisplay_GFX.h"
#include <Arduino_GigaDisplay.h>

#define INCBIN_PREFIX
#include "incbin.h"
#define BLACK 0x0000
#define WHITE 0xFFFF
#define GREEN 0x07E0  // Green: RGB(0, 255, 0)
#define YELLOW 0xFFE0 // Yellow: RGB(255, 255, 0)
#define RED 0xF800    // Red: RGB(255, 0, 0)

INCBIN(test, "C:/Users/zsong/Downloads/Gigachad-min (1).bin");
GigaDisplay_GFX display; 
GigaDisplayRGB rgb;
Arduino_H7_Video Display(800, 480, GigaDisplayShield);
Image img(ENCODING_RGB16, (uint8_t *) testData, 800, 922);

/************************Hardware Related Macros************************************/
const int AOUTpin = A1; // The AOUT pin of the alcohol sensor goes into analog pin A1 of the Arduino
const int DOUTpin = 8;  // The DOUT pin of the alcohol sensor goes into digital pin D8 of the Arduino

#define MG_PIN (A0)      // Analog input channel for the CO2 sensor
#define BOOL_PIN (2)     // Digital pin for BOOL sensor
#define DC_GAIN (8.5)    // Define the DC gain of amplifier

/***********************Software Related Macros************************************/
#define READ_SAMPLE_INTERVAL (250)  // Time interval between samples during a single read (ms)
#define READ_SAMPLE_TIMES (10)      // Number of samples for averaging in a single read
#define AVERAGE_INTERVAL (500)   // Rolling average interval (2 minutes in milliseconds)
#define SAMPLE_PERIOD (50)         // Main loop sample period (500 ms)
#define BUFFER_SIZE (AVERAGE_INTERVAL / SAMPLE_PERIOD) // Buffer size based on interval and period

/**********************Application Related Macros**********************************/
// Sensor-specific calibration values (these need to be adjusted for your specific sensor)
#define ZERO_POINT_VOLTAGE (0.43)  // Sensor output in volts at 400 ppm CO2
#define REACTION_VOLTAGE (0.80)   // Voltage drop at 1000 ppm CO2
#define CO2_DIFFERENCE_THRESHOLD (25) // CO2 deviation threshold
#define ALCOHOL_DIFFERENCE_THRESHOLD (100) // Alcohol deviation threshold

/*****************************Globals***********************************************/
float CO2Curve[3] = {2.602, ZERO_POINT_VOLTAGE, (REACTION_VOLTAGE / (2.602 - 3))}; // CO2 curve parameters
int co2Readings[BUFFER_SIZE] = {0}; // Circular buffer for CO2 values
int alcoholReadings[BUFFER_SIZE] = {0}; // Circular buffer for Alcohol values
int bufferIndex = 0; // Circular buffer index

void setup() {
  Serial.begin(9600); 
  pinMode(BOOL_PIN, INPUT); 
  digitalWrite(BOOL_PIN, HIGH); 
  Serial.println("\n");
  Serial.println("GIGGASNIFFER INITIATED");

  Display.begin();
  
  Display.beginDraw();  
  // Draw the image in the center of the display
  Display.image(img, (Display.width() - img.width()) / 2, (Display.height() - img.height()) / 2);
  Display.textFont(Font_5x7); 
  Display.textSize(6, 6); 
  Display.stroke(255, 255, 255); // Set text color (White)
  Display.text("GIGASNIFFER INITIATED", 50, 260); // Display text at position (50, 200)

  Display.endDraw();

  delay(4000);
  display.begin();                  // Initialize the display
  display.setRotation(1);          // Optional: Adjust rotation if needed
  display.setTextColor(WHITE);     // Set text color to white
  display.fillScreen(BLACK);       // Clear the screen initially

  // Initialize other components (e.g., RGB LED control)
  rgb.begin();


}

void loop() { 
  static unsigned long lastSampleTime = 0;
  unsigned long currentTime = millis();

  float volts = MGRead(MG_PIN);
  int co2Percentage = MGGetPercentage(volts, CO2Curve);
    
  if (co2Percentage == -1 or co2Percentage == 0) {
      Serial.print("Invalid CO2 Reading"); // Default value when sensor reading is invalid
    }   
  else {
      co2Readings[bufferIndex] = co2Percentage;  // Use the valid sensor reading
    }
  
  int alcoholValue = analogRead(AOUTpin);
  alcoholReadings[bufferIndex] = alcoholValue;

if (currentTime - lastSampleTime >= SAMPLE_PERIOD) {
    // Increment buffer index and wrap it around using modulo
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;  // Ensure it wraps around when reaching BUFFER_SIZE
    lastSampleTime = currentTime;  // Reset the sample time
}

  int lastIndex = (bufferIndex == 0) ? (BUFFER_SIZE - 1) : (bufferIndex - 1);

  // Calculate averages
  int co2Sum = 0;
  int alcoholSum = 0;
  int A = 0;
  for (A = 0; A <= lastIndex; A++) {
      co2Sum += co2Readings[A];
      alcoholSum += alcoholReadings[A];
  }

  int co2Average = co2Sum / (A);
  int alcoholAverage = alcoholSum / (A);


 Serial.println("--------------------------------------------");

    //    Print buffer contents every cycle
    Serial.println("Buffer Contents:");
    Serial.println("Index\tCO2 Reading (ppm)\tAlcohol Reading");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        Serial.print(i);
        Serial.print("\t");
        Serial.print(co2Readings[i]); // Print CO2 reading with 2 decimal precision
        Serial.print("\t\t\t");
        Serial.println(alcoholReadings[i]); // Print Alcohol reading
    }

    Serial.print("Buffer Index: ");
    Serial.println(bufferIndex);
    Serial.println();  // Blank line for readability
    Serial.print("A: ");
    Serial.println(A);
    Serial.println();  // Blank line for readability

    Serial.print("SEN0159: ");
    Serial.print(volts, 2);  // 2 decimal places for voltage
    Serial.print("V | CO2: ");
    Serial.print(co2Readings[lastIndex]);
    Serial.print(" | Alcohol: ");
    Serial.println(alcoholReadings[lastIndex]);  // Use println for a newline

// Print averages, aligned and concise
    Serial.print("Avg CO2: ");
    Serial.print(co2Average);
    Serial.print(" | Avg Alcohol: ");
    Serial.println(alcoholAverage);  // Use println to move to the next line


    // Check for significant deviations and print alerts
    float co2Difference = abs(co2Readings[lastIndex] - co2Average);
    float alcoholDifference = abs(alcoholReadings[lastIndex] - alcoholAverage);

    if (co2Difference > CO2_DIFFERENCE_THRESHOLD) {
      Serial.print("Hi CO2: ");
      Serial.print(co2Readings[lastIndex]);
      Serial.print(" ppm\n");
    }

    if (alcoholDifference > ALCOHOL_DIFFERENCE_THRESHOLD) {
      Serial.print("Hi Alco: ");
      Serial.print(alcoholReadings[lastIndex]);
      Serial.print("\n");
    }



    bool fresh = true; 
    bool soon = true; 
    bool rot = true; 
    if(alcoholDifference > ALCOHOL_DIFFERENCE_THRESHOLD){
      fresh = false;  
      soon = false; 
      rot = true; 
    }
    else if((co2Difference > CO2_DIFFERENCE_THRESHOLD)&&(alcoholDifference < ALCOHOL_DIFFERENCE_THRESHOLD)){
      fresh = false;
      soon = true; 
      rot = false; 
    }
    else{ 
      fresh = true; 
      soon = false; 
      rot = false; 
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int lineHeight = 10; // Adjust this value to control row spacing
    display.fillScreen(BLACK);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setTextSize(2); 
    // Print header
    display.print(" ");
    display.println("Buffer Contents:");
    display.println(" Index  CO2      Alcohol");

    // Loop through the buffer and print values
    for (int i = 0; i < BUFFER_SIZE; i++) { 
        display.setTextColor(WHITE);
        display.print(" "); // Adjust spacing for alignment
        display.print(i);
        display.print("      "); // Adjust spacing for alignment
        display.print(co2Readings[i]); // Print CO2 reading
        display.print("      "); // Adjust spacing for alignment
        display.println(alcoholReadings[i]); // Print Alcohol reading

        int currentX = display.getCursorX();
        int currentY = display.getCursorY();
        display.setCursor(currentX, currentY + lineHeight);
    }

    display.setCursor(350, 0);
    display.setTextColor(WHITE);
    display.print("Buffer Index: ");
    display.print(bufferIndex); // Print Buffer Index
    display.print("   A: ");     // Label for A
    display.println(A);          // Print A value

    display.setCursor(350, 50);
    display.print("SEN0159: ");
    display.print(volts, 2); // 2 decimal places for voltage
    display.print("V");
    display.setCursor(350, 100);
    display.print("CO2: ");
    display.print(co2Readings[lastIndex]);
    display.print(" | Alcohol: ");
    display.println(alcoholReadings[lastIndex]);

    // Print averages
    display.setCursor(350, 150);
    display.print("Avg CO2: ");
    display.print(co2Average);
    display.print(" | Avg Alcohol: ");
    display.println(alcoholAverage);

    // Print alerts if deviations exceed thresholds
    if (co2Difference > CO2_DIFFERENCE_THRESHOLD) {
      display.setCursor(350, 200);
      display.setTextColor(RED);
      display.print("Hi CO2: ");
      display.print(co2Readings[lastIndex]);
      display.print(" ppm");
    }

    if (alcoholDifference > ALCOHOL_DIFFERENCE_THRESHOLD) {
      display.setCursor(350, 250);
      display.setTextColor(RED);
      display.print("Hi Alco: ");
      display.print(alcoholReadings[lastIndex]);
      display.print(" ");
    }



    // Control the LED based on the state
    if (rot) {
      display.setTextSize(4); 
      display.setCursor(10, 350);
      rgb.on(255, 0, 0); // Red for rotten
      display.setTextColor(RED); 
      Serial.println("Rotten: Red LED On");
      display.print("Rotten: Red LED On");
    } 
    else if (soon) {
      display.setTextSize(4); 
      display.setCursor(10, 300);
      rgb.on(255, 255, 0);
      display.setTextColor(YELLOW); 
      Serial.println("Soon: Yellow LED On");
      display.print("Soon: Yellow LED On");
   } 
    else if (fresh) {
      display.setTextSize(4); 
      display.setCursor(10, 300);
      rgb.on(0, 255, 0); // Green for fresh
      display.setTextColor(GREEN); 
      Serial.println("Fresh: Green LED On");
      display.print("Fresh: Green LED On");
    } 
    else {
      rgb.off();
    }
        

    Serial.println("--------------------------------------------");
    delay(500); // Short delay for readability in serial output
}

/*****************************  MGRead *********************************************/
float MGRead(int mg_pin) {
    float voltageSum = 0;

    for (int i = 0; i < READ_SAMPLE_TIMES; i++) {
        voltageSum += analogRead(mg_pin); // Read analog value
        delay(READ_SAMPLE_INTERVAL); // Wait for next sample
    }
    // Calculate average voltage
    float avgVoltage = (voltageSum / READ_SAMPLE_TIMES) * 5.0 / 1024.0;
    return avgVoltage;
}

/*****************************  MGGetPercentage ************************************
Input:   volts   - Sensor output voltage
         pcurve  - Pointer to the calibration curve
Output:  ppm of the target gas
Remarks: Uses the calibration curve to calculate ppm
************************************************************************************/
int MGGetPercentage(float volts, float *pcurve) {
   if ((volts / DC_GAIN) >= ZERO_POINT_VOLTAGE) {
      return -1; // Out of measurable range
   } else {
      // Logarithmic calculation to get ppm
      return pow(10, ((volts / DC_GAIN) - pcurve[1]) / pcurve[2] + pcurve[0]);
   }
}


