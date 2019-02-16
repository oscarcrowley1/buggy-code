import controlP5.*;
import processing.serial.*;

Serial port;
ControlP5 p5;

Button startButton, stopButton;

void setup()
{
  size(700,600);
  
  
  String portName = Serial.list()[2]; 
  port = new Serial(this, portName, 9600);
  port.write("+++");
  delay(1100); 
  port.write("ATID 3208, CH C, CN");
  delay(1100); 
  
 port.bufferUntil(10); 
 
 p5 = new ControlP5(this);
  
 startButton = p5.addButton("Go");
 stopButton = p5.addButton("Stop");
  
 startButton.setPosition(100,300);
 startButton.setSize(200,200);
 stopButton.setPosition(400,300);
 stopButton.setSize(200,200);
  
}

public void controlEvent( ControlEvent event){
  println( event.getController().getName());
  
  if(event.isFrom(startButton)){
    port.write("Start\n");
  }
  if(event.isFrom(stopButton)){
    port.write("Stop\n");
}
}

void serialEvent(Serial xbeeInput){
  
println("Received: " + xbeeInput.readString());

}


void draw(){
}
