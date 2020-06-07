/*
 * sistem deschidere poarta culisanta
 * program scris de Nicu FLORICA (niq_ro) pentru Catalin Ba2
 * 06.06.2020, Craiova
 */

#define deschidere 2
#define inchidere 3

#define releucomanda 7
#define releusens 8

#define cuplat LOW
#define decuplat HIGH

#define deschis LOW
#define inchis HIGH

#define led 13

byte stare = 0;  // standby, 1 = deschis. 2 - inchis

unsigned long timpactionare = 20000; // 20 secunde
unsigned long timpapasare;

void setup() { // parte se ruleaza o singura data la pornire program
Serial.begin(9600); // pornire monitorizare seriala

pinMode(deschidere, INPUT);
pinMode(inchidere, INPUT);

pinMode(releucomanda, OUTPUT);
pinMode(releusens, OUTPUT);
digitalWrite(releucomanda, decuplat);
digitalWrite(releusens, inchis);

pinMode(led, OUTPUT);
digitalWrite(led, LOW);
}

void loop() { // parte ce se repeta mereu


if ((digitalRead(deschidere) == HIGH) and (stare == 0)) // daca s-a apasat butonul 1
{
 timpapasare = millis();
 stare = 1;
 digitalWrite(releucomanda, cuplat);
 digitalWrite(releusens, deschis);
 delay(500);
}

if (stare == 1)  // daca a fost apasat butonul 1
{
if ((millis() - timpapasare) > timpactionare)
{
 stare = 0;
 digitalWrite(releucomanda, decuplat);
 digitalWrite(releusens, inchis);
}
if ((digitalRead(deschidere) == HIGH) or (digitalRead(inchidere) == HIGH)) // daca se apasa unul din butoane
{
 stare = 0;
 digitalWrite(releucomanda, decuplat);
 digitalWrite(releusens, inchis);
 digitalWrite(led, HIGH);
 delay(2000);
 digitalWrite(led, LOW);
}
}

if ((digitalRead(inchidere) == HIGH) and (stare == 0)) // daca s-a apasat butonul 2
{
 timpapasare = millis();
 stare = 2;
 digitalWrite(releucomanda, cuplat);
 digitalWrite(releusens, inchis);
 delay(500);
}

if (stare == 2)  // daca a fost apasat butonul 2
{
if ((millis() - timpapasare) > timpactionare)
{
 stare = 0;
 digitalWrite(releucomanda, decuplat);
 digitalWrite(releusens, inchis);
}
if ((digitalRead(deschidere) == HIGH) or (digitalRead(inchidere) == HIGH)) // daca se apasa unul din butoane
{
 stare = 0;
 digitalWrite(releucomanda, decuplat);
 digitalWrite(releusens, inchis);
 digitalWrite(led, HIGH);
 delay(2000);
 digitalWrite(led, LOW);
}
}

delay(50);
} // sfarsit program
