#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

int increment;
int startValue;
int endValue;
int timeValue;

float calc_startValue;
float calc_endValue;
float calc_increment;

int bits_startValue;
int bits_endValue;
int bits_increment;

float calc_writtenVoltage;
int writtenVoltage;

int analogInput;
float r_monitor;
float r_real;
int readVoltage;


void setup() {
  
  Serial.begin(9600);
  dac.begin(0x62);
  
}

void loop() {

  dac.setVoltage(0, false);
  delay(250);
  Serial.println("");
  Serial.println("Dual MWPC High Voltage Power Supply (Droege) Ramp Programme v1.2");
  Serial.println("");
  delay(1000);
  Serial.println("Written by Mesut Caliskan on August 13, 2018 at The University of Chicago");
  Serial.println("");
  delay(1000);
  Serial.println("Before the process starts, you enter the values which spesify your ramp...");
  Serial.println("");
  delay(2000);

  
  Serial.println("Please enter the INITIAL VOLTAGE value (in volts): ");
  Serial.println("");
  while(Serial.available()==0){
    }
  startValue = Serial.parseInt();
  calc_startValue = ((startValue - 8.2286)/2.192);
  bits_startValue = round(calc_startValue);
  Serial.print("INITIAL VOLTAGE value (in volts) is: ");
  Serial.print(startValue);
  Serial.println(" V");
  Serial.print("This value corresponds to ");
  Serial.print(bits_startValue);
  Serial.println(" bits");
  Serial.println("");
  Serial.println("");
  delay(250);

  
  Serial.println("Please enter the FINAL VOLTAGE value (in volts): ");
  Serial.println("");
  while(Serial.available()==0){
    }
  endValue = Serial.parseInt();
  calc_endValue = ((endValue - 8.2286)/2.192);
  bits_endValue = round(calc_endValue);
  Serial.print("FINAL VOLTAGE value (in volts) is: ");
  Serial.print(endValue);
  Serial.println(" V");
  Serial.print("This value corresponds to ");
  Serial.print(bits_endValue);
  Serial.println(" bits");
  Serial.println("");
  Serial.println("");
  delay(250);

  
  Serial.println("Please enter the TIME VALUE (in ms) for each step: ");
  Serial.println("");
  while(Serial.available()==0){
    }
  timeValue = Serial.parseInt();
  Serial.print("TIME VALUE for each step is: ");
  Serial.print(timeValue);
  Serial.println(" ms");
  Serial.println("");
  Serial.println("");
  delay(250);

  
  Serial.println("Please enter the VOLTAGE INCREASE (in volts) with each step: ");
  Serial.println("");
  while(Serial.available()==0){
    }
  increment = Serial.parseInt();
  calc_increment = (increment/2.192);
  bits_increment = round(calc_increment);
  Serial.print("Each INCREMENT is: ");
  Serial.print(increment);
  Serial.println(" V");
  Serial.print("This value corresponds to ");
  Serial.print(bits_increment);
  Serial.println(" bits");
  Serial.println("");
  Serial.println("");
  delay(1000);

  
  Serial.println("Your values are like the following:");
  Serial.print("INITIAL VOLTAGE:  ");
  Serial.print(startValue);
  Serial.println(" V");
  Serial.print("FINAL VOLTAGE:  ");
  Serial.print(endValue);
  Serial.println(" V");
  Serial.print("TIME VALUE:  ");
  Serial.print(timeValue);
  Serial.println(" ms");
  Serial.print("INCREMENT:  ");
  Serial.print(increment);
  Serial.println(" V");
  Serial.println("");
  delay(1000);

  
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
  delay(2000);
  Serial.println("Bits written (b) | Voltage written (w) | Voltage Read (r) | Time (t)");
  Serial.println("");

  for(int v = bits_startValue; v <= bits_endValue; v = v + bits_increment){
        if ( analogRead(A3) < 550) {
        dac.setVoltage(v, false);
        calc_writtenVoltage = ((2.192*v)+8.2286);
        writtenVoltage = round(calc_writtenVoltage);
        analogInput = analogRead(A3);
        r_monitor = ((4.9562 * analogInput) + 8.417);
        r_real = (r_monitor);
        readVoltage = round(r_real);
        
        
        Serial.print("b: ");
        Serial.print(v);
        Serial.print("  |  ");
        Serial.print("w: ");
        Serial.print(writtenVoltage);
        Serial.print("  |  ");
        Serial.print("r: ");
        Serial.print(readVoltage);
        Serial.print("  |  ");
        Serial.print("t: ");
        Serial.println(millis());
        Serial.println("");
        
        delay(timeValue);
    }

    else {
        return;
      }
    
    
    }
  dac.setVoltage(0,false); //this is to make sure that Droege does NOT output any voltage after the ramp ends
  delay(1000);
  Serial.println("RAMP HAS ENDED SUCCESSFULLY...");
  delay(5000);
  Serial.println("To exit please use Ctrl+A Ctrl+X");
  delay(5000);
  return;
    }
    
  else {

      return;
    
    }
  
}
