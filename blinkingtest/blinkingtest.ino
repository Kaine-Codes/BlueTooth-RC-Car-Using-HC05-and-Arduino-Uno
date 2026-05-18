int in1=8;
int in2=9;
int in3=10;
int in4=11;
String predir;
int steerspeedpin=7;
String dir;
void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(9600);
}

void loop(){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,HIGH);
}
