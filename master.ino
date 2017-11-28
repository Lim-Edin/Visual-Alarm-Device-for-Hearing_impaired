#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // SoftwareSerial(RX, TX)

//버튼 및 LED
// push button을 디지털 2번 핀에 연결합니다.
const int button1Pin = 12; 
// led를 디지털 13번 핀에 연결합니다.
const int ledPin =  7;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
void setup() {
  //2번 핀을 입력 핀으로 설정합니다.
  pinMode(button1Pin, INPUT);
  //13번 핀을 출력 핀으로 설정합니다.
  pinMode(ledPin, OUTPUT);  

// 블루투스
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.print("Hello World!");

}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행합니다.
void loop() 
{
  // 버튼에서 읽어 올 디지털 값을 저장할 변수를 선언합니다.
  int button1State;     
  // 버튼이 눌렸는 지 아닌지 버튼의 상태를 읽어와서 앞에 선언한 변수에 저장
  button1State = digitalRead(button1Pin);    
    
    // 버튼이 눌렸다면
  if(button1State == LOW)
  {         
    // LED를 ON 시킵니다.
    digitalWrite (ledPin, HIGH);    
    BTSerial.write("a");    
  } 
  // 버튼이 눌리지 않았다면
  else
  {         
    //LED를 OFF 시킵니다.
    digitalWrite(ledPin, LOW);      
    BTSerial.write("b");
  }

  // 블루투스

   if (BTSerial.available()) 
   { //블루투스에서 넘어온 데이터가 있다면
   Serial.write(BTSerial.read()); //시리얼모니터에 데이터를 출력
  }
  if (Serial.available()) 
  {    //시리얼모니터에 입력된 데이터가 있다면
    BTSerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  } 

}

/*
SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
#define LED 12
#define BUTTON 7

void setup() {
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }


  Serial.println("Hello World!");

  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);
}

void loop() { //코드를 무한반복합니다.
  if (digitalRead(BUTTON)==HIGH)
  {a
    digitalWrite(LED,HIGH);  
  }
  if (mySerial.available()) { //블루투스에서 넘어온 데이터가 있다면
    Serial.write(mySerial.read()); //시리얼모니터에 데이터를 출력
  }
  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }
  
}*/
