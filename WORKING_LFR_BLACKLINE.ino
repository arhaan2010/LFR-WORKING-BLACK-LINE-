
#define S1 2             // left sensor
#define S2 3            // right sensor
#define S3 4           // extreme right 
#define S4 6          //extreme left 
#define LM1 8        // left motor
#define LM2 9       // left motor
#define RM1 12     // right motor
#define RM2 13    // right motor
#define ena 10
#define enb 11
void setup()
{
  pinMode(S1, INPUT);  //set these pins as inputs
  pinMode(S2, INPUT);  //set these pins as inputs
  pinMode(LM1, OUTPUT);  //set these pins as outputs
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ena, OUTPUT);    //Enable pins for Motor Driver 
  pinMode(enb, OUTPUT);
  
}

void loop()
{
  if((digitalRead(S1)==0)&&(digitalRead(S2)==0))     // When Both Sensors are on White Surface Move Forward 
  {
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ena,120);   //Motor Speed, Pins must be connected with PWM pins "~"
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(enb,120);  //Motor Speed, Pins must be connected with PWM pins "~"
    
    
  }
  
  else if((digitalRead(S1)==0) && (digitalRead(S2)==1))     // When Right sensor detects Black tape 
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ena,120);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    analogWrite(enb,120);
     
  }

  else if((digitalRead(S1)==1) && (digitalRead(S2)==0))     // When Left Sensor detects Black tape 
  {
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(ena,120);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(enb,200);
    
  }
  else if ((digitalRead(S4)==1)&&(digitalRead(S3)==1)){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ena,200);   //Motor Speed, Pins must be connected with PWM pins "~"
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(enb,200);  //Motor Speed, Pins must be connected with PWM pins "~"
     
  }
  

  else           // When Both Sensors detects Black Tape 
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    
   
  }
  

}
