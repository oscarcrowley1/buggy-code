#include <SPI.h>
#define CTRL_PIN 3 // motor pin 3 

String inputString = "";
boolean stringComplete = false;

void setup() {
  pinMode(3,OUTPUT); 
  analogWrite(3,0); 
  Serial.begin(9600);
  Serial.print("+++");
  delay(1500); 
  Serial.println("ATID 3208, CH C, CN");
  delay(1100);
  while(Serial.read() != -1){};
}

void loop(){
  if(stringComplete){
    if (inputString == "Go\n"){
      toComputer("Run");
      Run();
    }
    else if (inputString == "Stop\n"){
      toComputer("Stop");
      Stop();
    }
    else{
      
      toComputer("NOT MESSAGE "+inputString+"\n");
    }
    stringComplete = false; 
    inputString = "";
  }

}

void serialEvent(){
  while (Serial.available()){
    char enteredchar = (char)Serial.read();
    inputString += enteredchar;
    if (enteredchar == '\n'){
      stringComplete = true; //signals end of message
    }
  }
}

void toComputer(String outputString){
  Serial.println(outputString);
  Serial.flush();
}

void Run(){
  delay(20);
  analogWrite(CTRL_PIN, 127);
  toComputer("Written 3");
}

void Stop(){
  delay(20);
  analogWrite(CTRL_PIN, 0); 
}
