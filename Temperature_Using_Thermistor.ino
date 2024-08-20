void setup() {
  Serial.begin(9600); //opens serial port and set baud to 9600
}


void loop() {
  int adcVal = analogRead(A0);                                  //creates an interger called adcVal and assigns it the value of A0
  float v = adcVal * 5.0 / 1024;                                //creates a float value for calculating the voltage
  float rt = 10 * v / (5 - v);                                  //creates a float for resistance using the voltage
  float tempK = 1 / (log(rt / 10) / 3950 + 1 / (273.15 + 25));  //creates a float value for the temperatue in kelvin
  float tempC = tempK - 273.15;                                 //creates a float value for the temerature in celsius
  
  //prints the following in the serial monitor
  Serial.print ("The temperature is currently");
  Serial.print (tempK);
  Serial.print ("K ");
  Serial.print (tempC);
  Serial.println ("C");
  delay(500); //waits 500ms before looping the program
}
