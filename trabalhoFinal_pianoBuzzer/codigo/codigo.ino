#include <LiquidCrystal.h>
#include "notas.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int pinoSwitchLCD = 7; // define o switch menu/LCD
int estadoSwitchLCD = 0;     // muda o estado do menu/LCD pra LOW
int estadoAnteriorLCD = 0;
int LEDazul = 6;
int contadorSwitchLCD = 0; // contador para o numero de vezes que o botao MENU foi pressionado
    // o codigo conta quantas vezes o botao MENU foi pressionado,
    // mostra ele na tela, e comeca do zero
    //quando o "modo menu" acaba

// seta a frequência das notas musicais (teclas)
int notas[] = {262, 294, 330, 349, 392, 440, 494}; // Seta notas C, D, E, F, G, A, B

void setup()
{

    Serial.begin(9600);

    lcd.begin(16, 2);
    pinMode(pinoSwitchLCD, INPUT);
    pinMode(LEDazul, OUTPUT);
    digitalWrite(LEDazul, LOW); // LED fica desligado enquanto as teclas estão ativas

}
void loop()
{

    estadoSwitchLCD = digitalRead(pinoSwitchLCD);
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    lcd.noDisplay();
    digitalWrite(LEDazul, LOW); // Desliga o led toda vez que o loop recomeça

    // ************** comeca "LCDstart" quando o botao MENU eh pressionado ***********

    if (estadoSwitchLCD == HIGH)
    {
        digitalWrite(LEDazul, HIGH); // Liga o LEDpara mostrar que as teclas estão desativadas
        //e que o circuito esta no modo "menu"
        lcd.display();
        lcd.clear();
        LCDstart();
    }
    ////// NOTAS //////
    // Use the resistor ladder you created to change the voltage of each piano key button
    // 220 ohm = C5 // 560 ohm = D5 // 1K ohm = E5 // etc...
    //identifica qual tecla tocar pelo valor lido resistido pelo resistor 
    if (keyVal == 1023)
    {
        tone(8, notas[0]); // C
    }
    else if (keyVal >= 990 & keyVal <= 1010)
    {
        tone(8, notas[1]); // D
    }
    else if (keyVal >= 960 && keyVal <= 980)
    {
        tone(8, notas[2]); // E
    }
    else if (keyVal >= 900 && keyVal <= 945)
    {
        tone(8, notas[3]); // F
    }
    else if (keyVal >= 650 && keyVal <= 710)
    {
        tone(8, notas[4]); // G
    }
    else if (keyVal >= 500 && keyVal <= 550)
    {
        tone(8, notas[5]); // A
    }
    else if (keyVal >= 5 && keyVal <= 10)
    {
        tone(8, notas[6]); // B
    }
    else if (keyVal <= 1)
    { // if no switch is pressed, do not play tone
        noTone(8);
    }

} //end frequency tone loop

/////////////////////////////////////////////////////
void LCDstart()
{
    int keyVal = analogRead(A0);
    estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button

    while (estadoSwitchLCD == LOW)
    {                                               // continue loop while menu button isn't pressed
        estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button every time loop starts

        //************* START SONG 1 TITLE LOOP ********************
        if (estadoSwitchLCD == HIGH)
        {                       // if menu button is pressed, then...
            contadorSwitchLCD++; // set button count to 1
            Serial.print("number of button pushes:  ");
            Serial.println(contadorSwitchLCD);
            delay(300); // min. time until counts adds 1 more

            Song1title();
            lcd.clear();
            break;
        }

        //************* ELSE SHOW MENU ****************
        else
        {                         // if menu button is not pressed, then...
            contadorSwitchLCD = 0; // set menu button count to 0
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("WHICH SONG WOULD");
            lcd.setCursor(0, 1);
            lcd.print("YOU LIKE TO PLAY");
            delay(50); // return to main
        }

    } // end while
} // end LCDstart loop

// ************* SONG 1 LOOP STARTS HERE **************
void Song1title()
{
    int keyVal = analogRead(A0);
    estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

    while (estadoSwitchLCD == LOW)
    {                                               // continue loop while menu button isn't pressed
        estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

        //************* START SONG 2 TITLE LOOP ********************
        if (estadoSwitchLCD == HIGH)
        {                       // if menu button is pressed, then...
            contadorSwitchLCD++; // set button count to 2
            Serial.print("number of button pushes:  ");
            Serial.println(contadorSwitchLCD);
            delay(300); // min. time until counts adds 1 more

            Song2title();
            lcd.clear();
            break;
        }

        else
        { // if menu button is not pressed
            int keyVal = analogRead(A0);
            Serial.println(keyVal);

            if (keyVal >= 2)
            {
                digitalWrite(LEDazul, LOW);
                Song1();
                break;
            } // end if

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("SUPER MARIO BROS");
            lcd.setCursor(0, 1);
            lcd.print("   THEME SONG");
            delay(50);
        }
    } // end while song 1 -> 2

} // end Song1title loop

// ************* SONG 2 LOOP STARTS HERE **************
void Song2title()
{
    int keyVal = analogRead(A0);
    estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

    while (estadoSwitchLCD == LOW)
    {                                               // continue loop while menu button isn't pressed
        estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

        //************* START SONG 3 TITLE LOOP ********************
        if (estadoSwitchLCD == HIGH)
        {                       // if menu button is pressed, then...
            contadorSwitchLCD++; // set button count to 3
            Serial.print("number of button pushes:  ");
            Serial.println(contadorSwitchLCD);
            delay(300); // min. time until counts adds 1 more

            Song3title();
            lcd.clear();
            break;
        }

        else
        { // if menu button is not pressed
            int keyVal = analogRead(A0);
            Serial.println(keyVal);

            if (keyVal >= 2)
            {
                digitalWrite(LEDazul, LOW);
                Song2();
                break;
            } // end if

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("SUPER MARIO BROS");
            lcd.setCursor(0, 1);
            lcd.print("   UNDERWORLD");
            delay(50);
        }

    } // end while song 2 -> 3

} // end Song2title loop

// ************* SONG 3 LOOP STARTS HERE **************
void Song3title()
{
    int keyVal = analogRead(A0);
    estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

    while (estadoSwitchLCD == LOW)
    {                                               // continue loop while menu button isn't pressed
        estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

        //************* START SONG 4 TITLE LOOP ********************
        if (estadoSwitchLCD == HIGH)
        {                       // if menu button is pressed, then...
            contadorSwitchLCD++; // set button count to 4
            Serial.print("number of button pushes:  ");
            Serial.println(contadorSwitchLCD);
            delay(300); // min. time until counts adds 1 more

            Song4title();
            lcd.clear();
            break;
        }

        else
        { // if menu button is not pressed
            int keyVal = analogRead(A0);
            Serial.println(keyVal);

            if (keyVal >= 2)
            {
                digitalWrite(LEDazul, LOW);
                Song3();
                break;
            } // end if

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("    JEOPARDY");
            lcd.setCursor(0, 1);
            lcd.print("   THEME SONG");
            delay(50);
        }

    } // end while song 3 -> 4

} // end Song3title loop

// ************* SONG 4 LOOP STARTS HERE **************
void Song4title()
{
    int keyVal = analogRead(A0);
    estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

    while (estadoSwitchLCD == LOW)
    {                                               // continue loop while menu button isn't pressed
        estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

        //************* START SONG 5 TITLE LOOP ********************
        if (estadoSwitchLCD == HIGH)
        {                       // if menu button is pressed, then...
            contadorSwitchLCD++; // set button count to 5
            Serial.print("number of button pushes:  ");
            Serial.println(contadorSwitchLCD);
            delay(300); // min. time until counts adds 1 more

            Song5title();
            lcd.clear();
            break;
        }

        else
        { // if menu button is not pressed
            int keyVal = analogRead(A0);
            Serial.println(keyVal);

            if (keyVal >= 2)
            {
                digitalWrite(LEDazul, LOW);
                Song4();
                break;
            } // end if

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("     SONG 4");
            lcd.setCursor(0, 1);
            lcd.print("   TITLE HERE");
            delay(50);
        }

    } // end while song 4 -> 5

} // end Song4title loop

// ************* SONG 5 LOOP STARTS HERE **************
void Song5title()
{
    int keyVal = analogRead(A0);
    estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

    while (estadoSwitchLCD == LOW)
    {                                               // continue loop while menu button isn't pressed
        estadoSwitchLCD = digitalRead(pinoSwitchLCD); // check state of menu button again

        //************* START SONG 4 TITLE LOOP ********************
        if (estadoSwitchLCD == HIGH)
        {                         // if menu button is pressed, then...
            contadorSwitchLCD = 0; // set button count to 0
            Serial.print("number of button pushes:  ");
            Serial.println(contadorSwitchLCD);
            delay(300); // min. time until counts adds 1 more
            lcd.clear();
        }

        else
        { // if menu button is not pressed
            int keyVal = analogRead(A0);
            Serial.println(keyVal);

            if (keyVal >= 2)
            {
                digitalWrite(LEDazul, LOW);
                Song5();
                break;
            } // end if

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("     SONG 5");
            lcd.setCursor(0, 1);
            lcd.print("   TITLE HERE");
            delay(50);
        }

    } // end while song 4 -> 5

} // end Song5title loop