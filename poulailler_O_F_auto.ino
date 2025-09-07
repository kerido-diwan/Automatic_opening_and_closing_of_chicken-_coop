#define photo_res A0
#define led 8
#define in1 10
#define in2 11 
int UP = 1;
int DOWN = 0;


void setup() {
  Serial.begin (9600);
  pinMode(photo_res, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
int lecture = analogRead(photo_res);
Serial.println(lecture);
  if (analogRead(photo_res) >600 & DOWN == 1){
    moteur_up();
    
  }
  if (analogRead(photo_res) < 300 & UP == 1 ){
    moteur_down();
  }


}

void moteur_up() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  delay(1000);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  UP = 1;
  DOWN =0;
  while(analogRead(photo_res)>600);
  delay(3000);
}

void moteur_down() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  delay(1000);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  UP = 0;
  DOWN = 1;
  while(analogRead(photo_res)<300);
  delay(3000);
  
}