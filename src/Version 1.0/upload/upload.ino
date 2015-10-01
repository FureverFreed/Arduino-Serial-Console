/*

This is a simple serial console that allows you to control pin states and communicate easily with the Arduino
through PuTTY. Circuit: Arduino UNOR3, USB-A male to USB-B male cable, computer with PuTTY. Use the help command
for commands that you can send to the Arduino. The built in controllable LED will flash to communicate current
system status. If the LED is off, then the Arduino will not respond to keystrokes. If it is on, it will respond.
LED codes:
OFF=System is processing and is not responding to keystrokes.
BLINKING=A fatal error occured and the system must be restarted to continue use.
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
  // no code yet, so write error to screen.
  Serial.println("ERROR: No system interface code. Arduino will now flash LED.");
}

void loop() {
  // put your main code here, to run repeatedly:
  // no code yet, so flash light.
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
