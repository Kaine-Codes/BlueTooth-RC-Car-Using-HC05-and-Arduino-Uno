int in1=8;
int in2=9;
int in3=10;
int in4=11;
String dir="S";
void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(9600);
}

void loop(){
    Serial.println("Which direction: ");
    while(Serial.available()==0){}
    dir=Serial.readString();
    if (dir=="forward"){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);    
      digitalWrite(in3,LOW );
      digitalWrite(in4,HIGH);
    }else if(dir=="backward"){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }else (dir=="stop"){
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
    }
}
