//#define relay_ch1 2 //릴레이 채널1
//#define relay_ch2 3 //릴레이 채널2
#include <SoftwareSerial.h>
int relay_ch1=4;
int relay_ch2=3;
int relay_ch3=2;
const int sensorPin = A1;
const int moterPin = 7;
int lightLevel;
SoftwareSerial BTSerial(11,12);
char receivechar;

void manualTune()
{
  //밝기 정하기
  lightLevel = map(lightLevel, 100, 1023, 10, 300);    //500 ~ 1023범위에 있는 lightLevel를 10~300범위로 바꾼다.
  lightLevel = constrain(lightLevel, 10, 300);       //만약 위 함수에서 바뀌지 않으면 이 함수에서 바뀜
} 

void lightOn()
{
  digitalWrite(moterPin, HIGH);
  if(lightLevel > 80)
  {
    digitalWrite(relay_ch1, HIGH);// 릴레이 On
    digitalWrite(relay_ch2, HIGH);// 릴레이 On
    digitalWrite(relay_ch3, HIGH);//
  }
  if(lightLevel <=80 && lightLevel > 50)
  {
    digitalWrite(relay_ch1, HIGH);// 릴레이 On
    digitalWrite(relay_ch2, HIGH);// 릴레이 On
    digitalWrite(relay_ch3, LOW);
  }
   if(lightLevel <=50)
  {
    digitalWrite(relay_ch1, HIGH);// 릴레이 On
    digitalWrite(relay_ch2, LOW);// 릴레이 On
    digitalWrite(relay_ch3, LOW);
  }
}
void lightOff()
{
    digitalWrite(moterPin, LOW);
    digitalWrite(relay_ch1, LOW);// 릴레이 On
    digitalWrite(relay_ch2, LOW);// 릴레이 On
    digitalWrite(relay_ch3, LOW);
}
void setup() 
{  //초기화
  pinMode(relay_ch1, OUTPUT); //릴레이1채널 핀 출력포트 설정
  pinMode(relay_ch2, OUTPUT);
  pinMode(relay_ch3, OUTPUT);//릴레이2채널 핀 출력포트 설정
  pinMode(moterPin, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}
void loop() 
{ // 무한루프

  lightLevel = analogRead(sensorPin); //조도센서값 읽기
  receivechar = BTSerial.read(); //블루투스값 읽기
  manualTune(); //  lightLevel 조절

  //읽어온 값 시리얼 창 표기
  Serial.print("cds = ");
  Serial.println(lightLevel);
  Serial.print("BT = ");
  Serial.println(receivechar); 

  if(receivechar == 'a')
    lightOn();
  else if(receivechar == 'b')
  {
    lightOff();
  }
  else
  {
    Serial.print("Pairing disconnected");
  }
 
 
}
