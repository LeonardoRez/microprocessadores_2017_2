int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int btn[] = {10, 11};
unsigned long changeTime;
int ledDelay(0.6);

byte n;
void setup()
{
    // n = 0;
    // Serial.begin(9600);
    // for (int i = 0; i < (sizeof(leds) / 2); i++)
    // {
    //     pinMode(leds[i], OUTPUT);
    //     // digitalWrite(leds[i],HIGH);
    // }
    // for (int i = 0; i < (sizeof(btn) / 2); i++)
    // {
    //     pinMode(btn[i], INPUT);
    // }
    for (int i = 0; i < (sizeof(leds)/2); i++)
    {
        pinMode(leds[i], OUTPUT);
    }
    while (1)
        ;
    // changeTime = millis();
}
void loop()
{
    for (n = 0; n <= pow(2, (sizeof(leds) / 2)); n++)
    {
        mostraNum(n);
        delay(100);
    }
}
void mostraNum(byte num)
{
    for (int i = 0; i <= (sizeof(leds) / 2); i++)
    {
        if (bitRead(num, i))
            digitalWrite(leds[i], HIGH);
        else
            digitalWrite(leds[i], LOW);
    }
}