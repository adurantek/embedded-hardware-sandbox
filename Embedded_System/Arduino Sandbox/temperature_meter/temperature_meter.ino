#define POTANT A0
#define LED 9
struct sensorVerisi {
  int id;
  int hamdeger;
  int sicaklik;
};

struct sensorVerisi istasyon1;
int analogSicaklik;

void setup() {
  Serial.begin(9600);
  pinMode(POTANT, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  istasyon1.id = 1;
  istasyon1.hamdeger = analogRead(POTANT);
  istasyon1.sicaklik = map(istasyon1.hamdeger, 0,1023,-10,40);
  analogSicaklik = map(istasyon1.hamdeger, 0,1023,0,255);
  analogWrite(LED,analogSicaklik);
  Serial.print("id : ");
  Serial.println(istasyon1.id);
  Serial.print("Ham deger : ");
  Serial.println(istasyon1.hamdeger);
  Serial.print("Sicaklik degeri : ");
  Serial.println(istasyon1.sicaklik);
  delay(1000);
}