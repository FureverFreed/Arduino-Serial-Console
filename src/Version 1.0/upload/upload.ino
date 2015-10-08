/*

This is a simple serial console that allows you to control pin states and communicate easily with the Arduino
through Termite-3.2. Circuit: Arduino UNO R3, USB-A male to USB-B male cable, computer with PuTTY. Use the help command
for commands that you can send to the Arduino. The built in controllable LED will flash to communicate current
system status. If the LED is off, then the Arduino will not respond to keystrokes. If it is on, it will respond.
LED codes:
OFF=System is processing and is not responding to keystrokes.
BLINKING=A fatal error occured and the Arduino must be restarted to continue use.
ON=System is running fine and is responding to keystrokes.

*/
int ledPin=13;
void setup() {
  // put your setup code here, to run once:
  // initialize pins here:
  pinMode(ledPin, OUTPUT);
  // add pins being used to this array:
  int pinArray[]={13};
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  Serial.println("Initializing serial operating system, please wait...");
  // place initializing code here, such as a clock synchronization system, switch detection, etc.
  
  // tell user initialization is complete.
  Serial.println("Initialization complete. Serial console will now activate.");
}
// define functions.
void fatal(String error){
  // fatal is a simple command which will essentially freeze the Arduino. Call this command when a fatal error occurs.
  Serial.println("ERROR: "+error+" RESULT: System freeze.");
  while(true){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
  Serial.println("Welcome to Brainstormers Club Serial Console. Here are system specifications:");
  Serial.println("System Flash Memory: 32 KB, .5 KB used by bootloader.");
  Serial.println("System SRAM: 2 KB.");
  Serial.println("System EEPROM: 1 KB.");
  Serial.println("Microprocessor type: ATmega328.");
  Serial.println("Clock speed: 16 MHz.");
  Serial.println("Specification list complete.");
  Serial.println("Type help for a help menu, or exit to freeze the system until reset.");
  Serial.print(">>> ");
  while(true){
    if(Serial.available()){
      String input = Serial.readString();
      if(input=="exit\n"){
        fatal("System exit.");
      }
      if(input=="help\n"){
        Serial.println("Console Help");
        Serial.println("This console is run by Termite-3.2, please do not use other software.");
      }
      Serial.print(">>> ");
    }
  }
}
