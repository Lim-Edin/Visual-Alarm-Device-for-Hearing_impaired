#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // SoftwareSerial(RX, TX)
int count = 0;
const int button1Pin = 12;
const int ledPin =  7;

void setup() {
//2번 핀을 입력 핀으로 설정합니다.
  pinMode(button1Pin, INPUT);
//13번 핀을 출력 핀으로 설정합니다.
  pinMode(ledPin, OUTPUT);  
// 블루투스
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.print("Hello World!\n");
}
void loop() 
{
  count++;
  BTSerial.write('b');
  
  if(digitalRead(button1Pin)==LOW)
  { 
    digitalWrite (ledPin, HIGH); 
    BTSerial.write('a');
    Serial.write("a\n");
    for(;;)
    {
      if(digitalRead(button1Pin)==HIGH)
      {
        Serial.write("c\n");
        break;
      }
    }
    digitalWrite(ledPin, HIGH);
    BTSerial.write('a');
    Serial.write("a\n");
    delay(5000);
    
  }
  digitalWrite(ledPin, LOW);

  
  // 블루투스


//   if (BTSerial.available()) 
//
//   { //블루투스에서 넘어온 데이터가 있다면
//
//   Serial.write(BTSerial.read()); //시리얼모니터에 데이터를 출력
//
//  }
//
//  if (Serial.available()) 
//
//  {    //시리얼모니터에 입력된 데이터가 있다면
//    BTSerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
//
//  } 



}
