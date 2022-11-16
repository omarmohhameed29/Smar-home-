//smart lightning

#define led1 9 
#define led2 10
#define led3 11
#define led4 12
#define ldr_sensor A5
int ldr_value;

//fire alarm

#define buzzer 7
float temp;


//smart door

#include <Servo.h>
Servo servo;
#define IR_Sensor1 3
#define IR_Sensor2 5
int i=0;




void setup (){

  
  //smart lightning
  
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
pinMode (led3, OUTPUT);
pinMode (led4, OUTPUT);
pinMode (ldr_sensor, INPUT);
  
  //smart door
  
  {
  servo.attach(6);
  pinMode(IR_Sensor1,INPUT);
  pinMode(IR_Sensor2,INPUT);
  int i=0;

}
//fire alarm

  pinMode(buzzer,OUTPUT);
Serial.begin(9600);
  
}




void loop(){

  
//smart lightning

  ldr_value = analogRead (ldr_sensor);
if (ldr_value<400){
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);}
else{
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led3,HIGH);
digitalWrite(led4,HIGH);}
Serial.print("LDR value:

");  Serial.println(ldr_value);


  //smart door

  int reading1=digitalRead(IR_Sensor1);
  int reading2=digitalRead(IR_Sensor2);
  
  if(reading1==LOW || reading2==LOW)
  {for(i;i<=90;i++){servo.write(i); delay(20);} delay(500);}
  else
  {for(i;i>=0;i--){servo.write(i); delay(20);} delay(500);}


  //fire alarm
  
  temp=analogRead(A4);
  temp=temp*0.48828125;
  Serial.print("Temperature:");
  Serial.println(temp);
  delay(500);
  
 if(temp>=70)
  {
  digitalWrite(buzzer,HIGH);  
  }
  else {digitalWrite(buzzer,LOW);}
  delay(200);


  
}
