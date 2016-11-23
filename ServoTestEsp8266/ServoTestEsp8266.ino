// Sweep サンプルを元に弄ったものです
// http://arduino.cc/en/Tutorial/Sweep

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
void setup() 
{ 
  // attaches the servo on GIO2 to the servo object 
  // SG-90 を駆動するのでそれ向けに設定する
  // SG-90 は以下のパルスで動く
  // -90度（0.5ms） ~ 0度(1.45ms) ~ 90度（2.4ms）、50Hz（20ms単位）
  // Servo は 0度が0.544ms、180度が2.400ms、がデフォルトなので、デフォルトで良い
  myservo.attach(2);  
} 
 
void loop() 
{ 
  int pos;

  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    // SG-90 は20ms周期なのでその倍待ってみる
    // 60度を0.1秒なので、1度動くには1.6ms程度、こちらは問題にならなさそうである
    delay(40);
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(40);
  } 
} 

