
#include <IRremote.h>                       
int RECV_PIN = 2;                          
IRrecv irrecv(RECV_PIN);                    
decode_results results;

int led1= 8;
int led2=7;
int led3=6;
                     
void setup()
{
  Serial.begin(9600);                       
  irrecv.enableIRIn(); 
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);                     
}
void loop()
{
  if (irrecv.decode(&results))              
  {
    Serial.println(results.value, HEX);     
    if (results.value == 0xFFA25D){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
    }   
    else if(results.value == 0xFF629D){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, LOW); 
    }  
    else if(results.value == 0xFFE21D){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW); 
      digitalWrite(led3, HIGH);   
    }                  
    delay(10);                              
  }
  irrecv.resume();
}
