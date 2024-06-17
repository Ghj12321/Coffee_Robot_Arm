#include <Stepper.h>

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

unsigned int val1 = 6400, val2 = 50, val3 = 1;  //입력할 변수값 스텝수, 회전속도 딜레이, 회전방향
unsigned int i;     //for문에 사용할 변수

unsigned int val12 = 6400, val22 = 50, val32 = 0;  //입력할 변수값 스텝수, 회전속도 딜레이, 회전방향
unsigned int ii;     //for문에 사용할 변수

int gripperbutton = 2;

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
}

void loop()
{

    digitalWrite(dir, val3);      //회전방향 출력
    digitalWrite(dir2, val32);      //회전방향 출력2

      for(i=0; i<val1; i++)
      {          //정해진 스텝수만큼 펄스입력
        digitalWrite(steps, HIGH);
        delayMicroseconds(val2);          //딜레이값
        digitalWrite(steps, LOW);
        delayMicroseconds(val2);
        digitalWrite(steps2, HIGH);
        delayMicroseconds(val22);          //딜레이값
        digitalWrite(steps2, LOW);
        delayMicroseconds(val22);
       
      
      
     }
    if (digitalRead(gripperbutton) == LOW)
    {
      for(int b = 0; b < 30; b++)
        {
          for(ii=0; ii<val12; ii++)
          {          //정해진 스텝수만큼 펄스입력
            digitalWrite(steps2, HIGH);
            delayMicroseconds(val22);          //딜레이값
            digitalWrite(steps2, LOW);
            delayMicroseconds(val22);
          }
        }
    }
    
    
}
