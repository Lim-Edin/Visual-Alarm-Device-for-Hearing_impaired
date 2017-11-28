/*
  #include <SoftwareSerial.h>

  const int sensorPin = A0;      //조도센서 연결
  const int ledPin = 9;         //LED 연결

  int lightLevel;
  SoftwareSerial BlueToothSerial(2,3);

  /*
  void manualTune()
  {
  //밝기 정하기
  lightLevel = map(lightLevel, 100, 1023, 15, 300);    //500 ~ 1023범위에 있는 lightLevel를 0~255범위로 바꾼다.
  lightLevel = constrain(lightLevel, 15, 300);       //만약 위 함수에서 바뀌지 않으면 이 함수에서 바뀜
  }

  void setup()
  {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  BlueToothSerial.begin(9600);//LED 핀을 출력용으로 설정
  }

  void loop()
  {

  Serial.print("cds =  ");
  Serial.println(lightLevel);

  char receivechar = BlueToothSerial.read();
  Serial.write(receivechar);

    lightLevel = analogRead(sensorPin);   //아날로그 값을 읽
    manualTune();

    if(receivechar == 'a')
    {
     //analogWrite(ledPin, lightLevel);
     digitalWrite(ledPin, HIGH);
    }
     if(receivechar == 'b')
    {
      //analogWrite(ledPin, LOW);
      digitalWrite(ledPin,LOW);
    }


  }
*/
//ver.mad

#include <SoftwareSerial.h>

const int sensorPin = A0;      //조도센서 연결
//LED 연결
int relay = 10;
//relay[0] = 10;   //릴레이0 연결
//relay[1] = 11; //릴레이1 연결
//relay[2] = 12; //릴레이2 연결
int lightLevel;
SoftwareSerial BlueToothSerial(2, 3);

void manualTune()
{
  //밝기 정하기
  lightLevel = map(lightLevel, 100, 1023, 10, 300);    //500 ~ 1023범위에 있는 lightLevel를 10~300범위로 바꾼다.
  lightLevel = constrain(lightLevel, 10, 300);       //만약 위 함수에서 바뀌지 않으면 이 함수에서 바뀜
}

void turnUp(int lightLevel, char receivechar)
{
  if (receivechar == 'a')
  {
    if (lightLevel > 100)
    {
      digitalWrite(relay, HIGH);
      //digitalWrite(relay[1], HIGH);
      //digitalWrite(relay[2], HIGH);
       Serial.print(receivechar);
    }
    else if (lightLevel <= 100 && lightLevel > 70)
    {
      digitalWrite(relay, HIGH);
      //digitalWrite(relay[1], HIGH);
      //digitalWrite(relay[2], LOW);
       Serial.print(receivechar);
    }
    else if (lightLevel <= 70)
    {
      digitalWrite(relay, HIGH);
      //digitalWrite(relay[1], LOW);
      //digitalWrite(relay[2], LOW);
       Serial.print(receivechar);
    }
  }

  if (receivechar == 'b')
  {
    digitalWrite(relay, LOW);
    //digitalWrite(relay[1], LOW);
    //digitalWrite(relay[2], LOW);
    Serial.print(receivechar);
  }


}

void setup()
{
  //아날로그 입력핀은 설정하지 않음
  Serial.begin(9600);

  BlueToothSerial.begin(9600);//LED 핀을 출력용으로 설정
  pinMode(relay, OUTPUT);
  //pinMode(relay[1], OUTPUT);
  //pinMode(relay[2], OUTPUT);
}

void loop()
{
  char receivechar = BlueToothSerial.read();
  Serial.write(receivechar); //페어링 검사용

  lightLevel = analogRead(sensorPin);   //센서 아날로그 값을 읽어옴
  manualTune(); //  lightLevel 조절

  //turnUp(lightLevel, receivechar);

}

//ver.tears
