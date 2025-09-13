#define sunlight A0
#define led 8
// in1 et in2 sont les pins sur la carte L298N.A mettre sur pin PWN (logo ~).
#define in1 10
#define in2 11
// up et down son ici pour vérifier que le moteur ne s'ouvre/ferme pas 2 fois. (risque de casse).
int up = 1;
int down = 0;

void setup() {
  Serial.begin (9600);
  pinMode(sunlight, INPUT);
  pinMode(led, OUTPUT); 
}

void loop() {
//Pour voir les valeurs de luminosité et donc faire son réglage personnel.
int lecture = analogRead(sunlight);
  Serial.println(lecture);
//Automatisme d'ouverture.
  if (analogRead(sunlight) >600 && down == 1){
    moteur_up();
  }
  if (analogRead(sunlight) < 300 && up == 1 ){
    moteur_down();
  }
}
// Ici les deux boucle pour l'ouverture et la fermeture.
//Pour les valeurs et le fonctionement de in1 et in2 se référer à la documentation.
void moteur_up() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  delay(1000);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  up = 1;
  down =0;
  while(analogRead(sunlight)>600);
  delay(3000);
}

void moteur_down() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  delay(1000);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  up = 0;
  down = 1;
  while(analogRead(sunlight)<300);
  delay(3000);
}