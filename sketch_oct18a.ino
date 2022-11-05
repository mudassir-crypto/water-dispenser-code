#define trigger 9

#define echo 8

#define LED 13

#define MOSFET 12

 


 

float time=0,distance=0;

 

void setup()

{

Serial.begin(9600);


 pinMode(trigger,OUTPUT);

 pinMode(echo,INPUT);

 pinMode(LED,OUTPUT);

 pinMode(MOSFET,OUTPUT);


 delay(1000);

}

 

void loop()

{

long dur;
long dis;
long tocm;
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
dur=pulseIn(echo,HIGH);
tocm=microsecondsToCentimeters(dur);
Serial.println(String(tocm));

 if(tocm<15)

 {

   digitalWrite(LED,HIGH);
   digitalWrite(MOSFET,HIGH);

 }

 else

 {

   digitalWrite(LED,LOW);
   digitalWrite(MOSFET,LOW);

 }

delay(100);

}


void measure_distance()

{

 digitalWrite(trigger,LOW);

 delayMicroseconds(1);

 digitalWrite(trigger,HIGH);

 delayMicroseconds(10);

 digitalWrite(trigger,LOW);

 delayMicroseconds(1);

 time=pulseIn(echo,HIGH);


 distance=time*240/30000;

  return distance;

}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}