byte ledPin[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int ledDelay(0.6);
int direction = 1;
int currentLed = 0;
unsigned long changeTime;
int potPin = 2;

void setup()
{

    for (int i = 0; i < 10; i++)
    {
        pinMode(ledPin[i], OUTPUT);
	}
	
    changeTime = millis();
}

void loop()
{
	ledDelay = analogRead(potPin);
    if ((millis() - changeTime) > ledDelay)
    {
        changeLed();
        changeTime = millis();
    }
}
void changeLed()
{
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[currentLed], HIGH);
    currentLed += direction;
    if (currentLed == 0)
        direction = 1;
    if (currentLed == 9)
        direction = -1;
}