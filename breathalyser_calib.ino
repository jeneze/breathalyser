 /*Biomedical Engineering Project 2
 Aston University, Biomedical Engineering
 Final Version produced 07/12/2018
 Written by Jennifer Ezebuenyi, Prelate Romanus, Michael Oshionya, and Chisom Okwara
 Module Leader: Dr Antonio Fratini
 Brethalyser with Lcd Screen code for use with Arduino Uno and MQ3 gas sensor
 LCD pins 1 and 2 connected to ground and 5v+ respectively
 Lcd pin 3 connected to Arduino 6
 Lcd pin 4 connected to pin 12 of Arduino
 Lcd pin5 connected to 5v+
 Lcd pin 6 connected to pin 11
 Lcd pins 11, 12, 13, 14 connected to pins 5, 4, 3, 2 respectively
 Lcd pin 15 connected to pin 9
 Lcd pin 16 connected to ground*/
  
  #include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);      //initiates the pins of the lcd that send information
int Contrast = 255;                         //states the contrast of the screen to 20
int sensorPin = A1;                         //states the sensor's information recieving pin as the Analog 1 on the Arduino
int GreenLed = 13;                          //states the GreenLed's voltage pin as digital 13 Arduino
int RedLed = 7;                             //states the RedLed's voltage pin as digital 7 of the Arduino
int LcdBIn = 9;                             //states pin 9 of the Arduino as the LcdBacklightIn
float sensor_volt;
float RS_air; //  Get the value of RS via in a clear air
float R0;  // Get the value of R0 via in Alcohol
int myCounter = 0;
int sensorValue = analogRead(sensorPin);
float RS_gas; // Get value of RS in a GAS
float ratio; // Get ratio RS_GAS/RS_air
void setup(){

Serial.begin(9600);                         //sets the data rate in bits per second
analogWrite(6, Contrast);                   //uses Arduino's potentionmeter to generate a PWM output proportionate 
                                            //to the contrast value
lcd.begin (16,2);                           //tells the arduino that the lcd is a 16x2 lcd
pinMode(GreenLed, OUTPUT);                  //sets the GreenLed pin as an output
pinMode(RedLed, OUTPUT);                    //sets the RedLed pin as an output
pinMode(LcdBIn, OUTPUT);                    //sets the Lcd Backlight pin as an output
pinMode(sensorPin, INPUT);                  //sets the sensor's pin as an input
}


void loop() {

lcd.setCursor(0,0);                         //puts the cursor of the lcd at the start of the top line
lcd.print("Welcome.");                      //writes "Welcome"
lcd.setCursor(0,1);                         //puts cursor on the second line
lcd.print("Warming up...");
delay(20000);                               //delay for 20seconds as the sensor warms up
lcd.clear();                                //clears writing on lcd and returns cursor to (0,0)
lcd.print("Please breathe into");
lcd.setCursor(0,1);
lcd.print("sensor for 10 sec");
delay(10000);                               //delay for 10seconds as person breathes again
float sensorValue;                          //states the integer value corresponds to whatever value the sensor pin returns
lcd.print("Amount of Alc:");
lcd.print(sensorValue);
Serial.print(sensorValue);                        //Allows a person running Arduino to see the values without the lcd
{
if (sensorValue>400)
{

  //Serial.print("above limit sequence");   //Debugging line. Used to check what stage of execution the code was in.
  lcd.setCursor(0,0);
  lcd.print("Warning!");
  lcd.setCursor(0,1);
  lcd.print("Above Limit");
  digitalWrite(GreenLed, HIGH);           //Turns the GreenLed on
  digitalWrite(RedLed, HIGH);             //The next section makes the RedLed flash with a 0.5s delay between on and off for 9 secon
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW); 
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
  delay(500);
  digitalWrite(RedLed, HIGH);
}
else if ((sensorValue)==0)
{
  // Serial.print("Insufficient sequence");   //Debugging line
  lcd.setCursor(0,0);
  lcd.print("Insufficient");
  delay(3000);                                //delays the code for 3 seconds as the data obtained was not enough to get a reading
                                              //mainly a fail safe for if the 20second warmup failed
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please breathe");
  lcd.setCursor(0,1);
  lcd.print("Again for 10 sec");               //user has to breathe again to obtain a set of values
  digitalWrite(GreenLed, LOW);                 //GreenLed is off, and only RedLed is on
  digitalWrite(RedLed, HIGH);
  delay (10000);                               //delays code for 10 seconds
}
else ((sensorValue)<400);
{
 // Serial.print("no alcohol sequence");        //Debugging line
  lcd.setCursor(0,0);
  lcd.print("No Alcohol");
  lcd.setCursor(0,1);
  lcd.print("Detected");
  digitalWrite(GreenLed, HIGH);                 //GreenLed is on, RedLed is off
  digitalWrite(RedLed, LOW);
 // Serial.print("delaying");                   //Debugging Line
  delay(5000);                                  //Delays code for 5 seconds
//  Serial.print("delay done");                 //Debugging Line
}

}

digitalWrite(GreenLed, LOW);                    //Turns all of the LEDs off
digitalWrite(RedLed, LOW);


lcd.setCursor(0,1);
lcd.print("Thank you");

delay(8000);                                    //delays for 8 seconds before starting the whole loop again

}

