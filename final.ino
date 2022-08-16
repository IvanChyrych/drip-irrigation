int a = 1;
int b = 1;

#include <Servo.h>
Servo servo;

unsigned int timer3;
unsigned int timer2;
unsigned int timer1;

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  servo.attach(2);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (!digitalRead(3)  && digitalRead(4))
  {
    if (millis() - timer3 >= 5000)
    {
      if (millis() - timer2 >= 600 && a == 0 && !digitalRead(7) )
      {
        analogWrite(11, 0);
        analogWrite(5, 225);
        timer2 = millis();
        servo.write(30);
        a++;
      }
      if (millis() - timer2 >= 1000 && a == 1 )
      {
        timer2 = millis();
        analogWrite(5, 225);
        analogWrite(11, 110);
        a++;
      }
      if (millis() - timer2 >= 600 && a == 2 && !digitalRead(7) )
      {
        timer2 = millis();
        servo.write(150);
        analogWrite(5, 225);
        analogWrite(11, 0);
        a++;
      }
      if (millis() - timer2 >= 1000 && a == 3  )
      {
        timer2 = millis();
        analogWrite(5, 225);
        analogWrite(11, 110);
        a -= 3;
      }
    }
    if (millis() - timer3 >= 60000)
    { servo.write(90);
      analogWrite(5, 0);
      analogWrite(11, 0);
    }
  }
  if (digitalRead(3) && !digitalRead(4))
  {
    if (millis() - timer3 >= 5000)
    {
      if (millis() - timer2 >= 600 && a == 0 && !digitalRead(7) )
      {
        analogWrite(11, 0);
        analogWrite(5, 225);
        timer2 = millis();
        servo.write(90);
        a++;
      }
      if (millis() - timer2 >= 1000 && a == 1 )
      {
        timer2 = millis();
        analogWrite(5, 225);
        analogWrite(11, 110);
        a++;
      }
      if (millis() - timer2 >= 600 && a == 2 && !digitalRead(7) )
      {
        timer2 = millis();
        servo.write(90);
        analogWrite(5, 225);
        analogWrite(11, 0);
        a++;
      }
      if (millis() - timer2 >= 1000 && a == 3  )
      {
        timer2 = millis();
        analogWrite(5, 225);
        analogWrite(11, 110);
        a -= 3;
      }
    }
    if (millis() - timer3 >= 60000)
    { servo.write(90);
      analogWrite(5, 0);
      analogWrite(11, 0);
    }
  }
  if (!digitalRead(3) && !digitalRead(4))
  {
    { servo.write(90);
      analogWrite(5, 0);
      analogWrite(11, 0);
    }
  }
}
