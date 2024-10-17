#include <Servo.h>
Servo Servo1;
#define steps 5
#define dir 6
#define ms1 8
#define ms2 9
#define ms3 10      //핀연결

#define steps2 23
#define dir2 22
#define ms12 24
#define ms22 25
#define ms32 26      //핀연결

#define steps3 47
#define dir3 46
#define ms13 48
#define ms23 49
#define ms33 50      //핀연결

int value1 = 70;
int value2 = 170;
int value3 = 90;
int gripperbutton = 2;

unsigned int val1 = 3200 , val2 = 100, val3 = 0;  //입력할 변수값 스텝수, 회전속도 딜레이, 회전방향
unsigned int i;     //for문에 사용할 변수

unsigned int val12 = 3200, val22 = 100, val32 = 0;  //입력할 변수값 스텝수, 회전속도 딜레이, 회전방향
unsigned int ii;     //for문에 사용할 변수

unsigned int val13 = 3200 , val23 = 50, val33 = 0;  //입력할 변수값 스텝수, 회전속도 딜레이, 회전방향
unsigned int iii; 



void setup(){
  Serial.begin(9600);
  pinMode(steps, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(ms1, OUTPUT);
  pinMode(ms2, OUTPUT);
  pinMode(ms3, OUTPUT);   //신호보낼 핀 출력설정
  
  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, HIGH);
  digitalWrite(ms3, HIGH);    //분주설정

  pinMode(steps2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(ms12, OUTPUT);
  pinMode(ms22, OUTPUT);
  pinMode(ms32, OUTPUT);   //신호보낼 핀 출력설정
  
  digitalWrite(ms12, HIGH);
  digitalWrite(ms22, HIGH);
  digitalWrite(ms32, HIGH);    //분주설정

  pinMode(steps3, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(ms13, OUTPUT);
  pinMode(ms23, OUTPUT);
  pinMode(ms33, OUTPUT);   //신호보낼 핀 출력설정
  
  digitalWrite(ms13, HIGH);
  digitalWrite(ms23, HIGH);
  digitalWrite(ms33, HIGH);    //분주설정
  Servo1.attach(3);
  pinMode(gripperbutton, INPUT_PULLUP);

}

void loop()
{
  /*if(Serial.available())
  {   //시리얼 입력이 있을경우
    val1=Serial.parseInt();   //스텝수 입력
    val2=Serial.parseInt();   //회전속도를 결정하는 딜레이값 입력(값이 작을수록 회전속도가 빨라짐)
    val3=Serial.parseInt();   //회전방향을 결정하는 입력*/

    digitalWrite(dir, val3);      //회전방향 출력
    digitalWrite(dir2, val32);      //회전방향 출력2
    digitalWrite(dir3, val33);      //회전방향 출력2
    if (digitalRead(gripperbutton) == LOW)
    {

     for(int a = 0; a < 5; a++)
      {
     for(i=0; i<val1; i++)
       {          //정해진 스텝수만큼 펄스입력
         digitalWrite(steps, HIGH);
         delayMicroseconds(val2);          //딜레이값
         digitalWrite(steps, LOW);
         delayMicroseconds(val2);
       }
      }
          for(int b = 0; b < 5; b++)
          {
           for(ii=0; ii<val12; ii++)
            {          //정해진 스텝수만큼 펄스입력
             digitalWrite(steps2, HIGH);
             delayMicroseconds(val22);          //딜레이값
             digitalWrite(steps2, LOW);
             delayMicroseconds(val22);
            }
          }
            for(int c = 0; c < 10; c++)
          {
             for(iii=0; iii<val13; iii++)
           {          //정해진 스텝수만큼 펄스입력
            digitalWrite(steps3, HIGH);
            delayMicroseconds(val23);          //딜레이값
            digitalWrite(steps3, LOW);
            delayMicroseconds(val23);
            }
           }

      Servo1.write(value1);
      delay(1000);
      Servo1.write(value3);
       }
}
     /*  for(int b = 0; b < 10; b++)
    {
      for(ii=0; ii<val12; ii++)
      {          //정해진 스텝수만큼 펄스입력
        digitalWrite(steps2, HIGH);
        delayMicroseconds(val22);          //딜레이값
        digitalWrite(steps2, LOW);
        delayMicroseconds(val22);
      }
     }*/

     /*for(int c = 0; c < 30; c++)
    {
      for(iii=0; iii<val13; iii++)
      {          //정해진 스텝수만큼 펄스입력
        digitalWrite(steps3, HIGH);
        delayMicroseconds(val23);          //딜레이값
        digitalWrite(steps3, LOW);
        delayMicroseconds(val23);
      }
     }
      pinMode(40,OUTPUT);
      pinMode(41,OUTPUT);
      delay(2000);
      
      Servo1.write(value1);
      delay(1000);
      Servo1.write(value3);
    
    */
