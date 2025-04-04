
#include <Servo.h>
Servo sg98; 
int sensor2;
int sugiris;
int sucikis;
int kirmizi=2;
int sari=3;
int yesil=4;
int buzzer=11;
int echo1=7;
int trig1=8;
int echo2=9;
int trig2=10;
int buton=6;
int fark;
int durum=0;
int a;
long zaman1;
long zaman2;
int mesafe1;
int mesafe2;

 
void setup() 
{
int a=1;
sg98.attach(13);
Serial.begin(9600);
pinMode(kirmizi,OUTPUT);
pinMode(sari,OUTPUT);
pinMode(yesil,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(1,OUTPUT);
pinMode(buton,INPUT);
pinMode(7,HIGH);
pinMode(trig1, OUTPUT); 
pinMode(echo1,INPUT); 
pinMode(trig2,OUTPUT);
pinMode(echo2,INPUT);
Serial.println("Otomatik Sel Önleme Akıllı Köprü Sistemi başlatıldı, Özyıl İnteractive");
}
void loop(){
  sg98.write(0);
  digitalWrite(yesil,HIGH);
  digitalWrite(sari,LOW);
  digitalWrite(buzzer,LOW);
  digitalWrite(kirmizi,LOW);
 
    
  if(digitalRead(buton)==0){
    a=2;
        if (a == 2) {
      Serial.print("Özyıl Entertainmet ve Özyıl İnteractive tarafından geliştirilen otomatik sel önleme akıllı köprü sistemini kullandığınız için tesekkur ederiz.");    
     while(true) {
    if(digitalRead(buton) == 0) { // Buton basıldığında
        sg98.write(90); // Servo motoru 90 derece konumuna getir
        while(digitalRead(buton) == 0); // Buton serbest bırakılıncaya kadar bekle
        delay(500); // Belirli bir süre bekle
        sg98.write(0); // Servo motoru 0 derece konumuna getir
        delay(500); // Belirli bir süre bekle
        Serial.write("Butona Basildi\n"); // Buton durumunu seri porta yazdır
        while(digitalRead(buton) == 0); // Buton serbest bırakılıncaya kadar bekle
    }
}
        }
  }
  if (a!=2){
    
  
  while(digitalRead(buton)==1){
  digitalWrite(trig1, LOW); 
  delayMicroseconds(5);
  digitalWrite(trig1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);  
  zaman1 = pulseIn(echo1, HIGH);
  mesafe1= (zaman1 /29.1)/2;       
  delay(500);
  digitalWrite(trig2, LOW); 
  delayMicroseconds(5);
  digitalWrite(trig2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);  
  zaman2 = pulseIn(echo2, HIGH);
  mesafe2= (zaman2 /29.1)/2;       
  int fark=abs(mesafe1-mesafe2);
Serial.print("Su seviyesi farkı: ");
Serial.print(fark);
Serial.println("cm by Özyıl Interactive");
  if(fark<5){
    digitalWrite(yesil,HIGH);
    digitalWrite(sari,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(kirmizi,LOW);
    sg98.write(0);
    
  }
  if(5<fark and fark<8){
    digitalWrite(yesil,LOW);
    digitalWrite(sari,HIGH);
    digitalWrite(buzzer,LOW);
    digitalWrite(kirmizi,LOW);
    sg98.write(0);
   
    
  }
  if(7<fark){
  digitalWrite(yesil,LOW);
  digitalWrite(sari,LOW);
  digitalWrite(buzzer,HIGH);
  digitalWrite(kirmizi,HIGH);
  sg98.write(90);
    
   
    
  }
  }
  }
}
