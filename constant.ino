#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

int voltageOutput;
int totalTime;

void setup() {
  
  Serial.begin(9600);
  dac.begin(0x62);

}

void loop() {

  Serial.println("Dual MWPC High Voltage Power Supply (Droege) Constant Voltage Output v1.2");
  Serial.println("");
  Serial.println("");
  delay(3000);
  Serial.println("Written by Mesut Caliskan on August 13 at The University of Chicago");
  Serial.println("");
  delay(2000);
  Serial.println("Before the process starts, please enter the required values...");
  Serial.println("");
  delay(2000);

  Serial.println("Please enter the voltage (in volts): ");
  Serial.println("");
  while(Serial.available()==0){
    }
  voltageOutput = Serial.parseInt();
  Serial.print("VOLTAGE is: ");
  Serial.print(voltageOutput);
  Serial.println(" V");
  Serial.println("");
  Serial.println("");
  delay(2000);

  Serial.println("Please enter the TIME (in ms): ");
  Serial.println("");
  while(Serial.available()==0){
    }
  totalTime = Serial.parseInt();
  Serial.print("TOTAL TIME is: ");
  Serial.print(totalTime);
  Serial.println(" ms");
  Serial.println("");
  Serial.println("");
  delay(2000);

  Serial.println("Your values are like the following:");
  Serial.print("VOLTAGE:  ");
  Serial.print(voltageOutput);
  Serial.println(" V");
  Serial.print("TOTAL TIME:  ");
  Serial.print(totalTime);
  Serial.println(" ms");
  delay(2000);

  Serial.println("ARE THE VALUES CORRECT? - (y/n)");
  while(Serial.available()==0){
    }
  if(Serial.readString() == "y"){
      
  Serial.println("THE PROCESS IS STARTING in 5...");
  delay(1000);
  Serial.println("THE PROCESS IS STARTING in 4...");
  delay(1000);
  Serial.println("THE PROCESS IS STARTING in 3...");
  delay(1000);
  Serial.println("THE PROCESS IS STARTING in 2...");
  delay(1000);
  Serial.println("THE PROCESS IS STARTING in 1...");
  Serial.println("");
  delay(1000);
  Serial.println("BEGIN...");
  delay(100);
  dac.setVoltage(voltageOutput, false);
  delay(totalTime);
    }

  else {

      return;
    
    }
  
}
