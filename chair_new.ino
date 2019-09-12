#include <Keypad.h>
#include <SoftwareSerial.h>
#include<NewPing.h>

int trig1 = 30;
int echo1 = 34;                //left
int trig2 = 32;
int echo2 = 36;

float maxi= 400;

NewPing sonar1(trig1,echo1,maxi);
NewPing sonar2(trig2,echo2,maxi);
float u1,u2;

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    SoftwareSerial mySerial(10, 11);

int rm1 = 26;
int rm2 = 28;
int lm1 = 22;
int lm2 = 24;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//void readsens() {
// u1 = sonar1.ping_cm();
//Serial.print("a :");
//Serial.println(u1);
 
  //u2 = sonar2.ping_cm();
 //Serial.print("b :");
 //Serial.println(u2);
//}

  
void Stop()                          //stop
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}
void forward()                        //forward
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
} 

void right()                        //right
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}
void left()                          //left
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

void reverse()                        //forward
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
} 

void setup(){
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}
  
void loop()
{
  //readsens();
  char c=Serial.read();
  Serial.println(c);
   char key = keypad.getKey();
  //if (Serial.available()>0)
  if(key =='1')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("AM HUNGRY, GET ME SOMETHING TO EAT");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='2')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("AM THIRSTY GET ME A GLASS OF WATER");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

else if(key =='3')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("TAKE ME TO THE RESTROOM");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='4')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("TIME FOR MEDICINES ");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='5')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("AM SLEEPY, TAKE ME TO THE BEDROOOM");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='6')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("AM BORED SWITCH ON THE TELEVISON");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='7')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("SWITCH ON THE AC");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='8')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("SWITCH ON THE FAN");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='9')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("SWITCH ON THE LIGHT");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='0')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("I WANNA CHARGE MY MOBILE PHONE");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='*')
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918778462725\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("!!!!!EMERGENCY!!!!!");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
 }

 else if(key =='A')
 {
  forward(); 
 }

 else if(key =='B')
 {
  left();
 }

else if(key =='C')
 {
  right();
 }

 else if(key =='D')
 {
  reverse();
 }
 else if(key =='#')
 {
Stop();
 }
  else if(c=='f')
  {
   reverse();
  }
  else if(c=='s')
  {
    Stop();
  }
  else if(c=='b')
  {
    forward();
  }
  else if(c=='l')
  {
    right();
  }
  else if(c=='r')
  {
    left();
  }

   else if((u1<=15)||(u2<=15))
    {
    Stop();
    }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
    
}
        
