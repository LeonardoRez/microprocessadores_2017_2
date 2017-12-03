/*
    Aluno: Leonardo Rezende
    Aula: Microprocessadores
*/

#define LIN_1 6
#define LIN_2 A2
#define LIN_3 2
#define LIN_4 9
#define LIN_5 12
#define LIN_6 A0
#define LIN_7 11
#define LIN_8 7

#define COL_8 A3
#define COL_7 3
#define COL_6 5
#define COL_5 A1
#define COL_4 4
#define COL_3 13
#define COL_2 8
#define COL_1 10

const byte LINHAS[] = {
    LIN_1, LIN_2, LIN_3, LIN_4, LIN_5, LIN_6, LIN_7, LIN_8};

//Binário das letras 8x8
byte TODOS[] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};
byte EX[] = {B00000000, B00010000, B00010000, B00010000, B00010000, B00000000, B00010000, B00000000};
byte A[] = {B00000000, B00011000, B00100100, B00100100, B00111100, B00100100, B00100100, B00000000};
byte AH[] = {B00001000, B00011000, B00100100, B00100100, B00111100, B00100100, B00100100, B00000000};
byte B[] = {B01111000, B01001000, B01001000, B01110000, B01001000, B01000100, B01000100, B01111100};
byte C[] = {B00000000, B00011110, B00100000, B01000000, B01000000, B01000000, B00100000, B00011110};
byte D[] = {B00000000, B00111000, B00100100, B00100010, B00100010, B00100100, B00111000, B00000000};
byte E[] = {B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00111100, B00000000};
byte EH[] = {B00001000, B00010000, B00111100, B00100000, B00111000, B00100000, B00111100, B00000000};
byte F[] = {B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00100000, B00000000};
byte G[] = {B00000000, B00111110, B00100000, B00100000, B00101110, B00100010, B00111110, B00000000};
byte H[] = {B00000000, B00100100, B00100100, B00111100, B00100100, B00100100, B00100100, B00000000};
byte I[] = {B00000000, B00111000, B00010000, B00010000, B00010000, B00010000, B00111000, B00000000};
byte J[] = {B00000000, B00011100, B00001000, B00001000, B00001000, B00101000, B00111000, B00000000};
byte K[] = {B00000000, B00100100, B00101000, B00110000, B00101000, B00100100, B00100100, B00000000};
byte L[] = {B00000000, B00100000, B00100000, B00100000, B00100000, B00100000, B00111100, B00000000};
byte M[] = {B00000000, B00000000, B00101000, B01010100, B01000100, B01000100, B00000000, B00000000};
byte N[] = {B00000000, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000, B00000000};
byte O[] = {B00000000, B00111100, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000};
byte P[] = {B00000000, B00111000, B00100100, B00100100, B00111000, B00100000, B00100000, B00000000};
byte Q[] = {B00000000, B00111100, B01000010, B01000010, B01000010, B01000110, B00111110, B00000001};
byte R[] = {B00000000, B00111000, B00100100, B00100100, B00111000, B00100100, B00100100, B00000000};
byte S[] = {B00000000, B00111100, B00100000, B00111100, B00000100, B00000100, B00111100, B00000000};
byte T[] = {B00000000, B01111100, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000};
byte U[] = {B00000000, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00000000};
byte V[] = {B00000000, B00100010, B00100010, B00100010, B00010100, B00010100, B00001000, B00000000};
byte W[] = {B00000000, B10000010, B10010010, B01010100, B01010100, B00101000, B00000000, B00000000};
byte X[] = {B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000};
byte Y[] = {B00000000, B01000100, B00101000, B00010000, B00010000, B00010000, B00010000, B00000000};
byte Z[] = {B00000000, B00111100, B00000100, B00001000, B00010000, B00100000, B00111100, B00000000};

void setup()
{
    //ativar todos os pinos como saída
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop()
{
    desenha(A);
    desenha(V);
    desenha(I);
    desenha(D);
    desenha(A);
    desenha(EH);
    desenha(B);
    desenha(E);
    desenha(L);
    desenha(A);
}
void desenha(byte buffer2[])
{

    //plota a letra e desliza pela matriz
    for (byte j = 0; j < 160; j++)
    {
        //pisca todos os leds, linha por linha
        for (byte i = 0; i < 8; i++)
        {
            int p = 0 + buffer2[i]; //joga o padrão em um inteiro (com o dobro de bits)
            p = p << 8; //desloca para a esquerda para poder "deslizar" sem perder informação
            desligaColunas((p) >> (16 - j / 10)); // pisca a linha deslocada "16-j/10" campos para percorrer
                                                // toda a matriz 
            digitalWrite(LINHAS[i], HIGH);
            delay(2); //tempo que os leds da linha ficam acesos
            digitalWrite(LINHAS[i], LOW);
        }
    }
}

void desligaColunas(byte b)
{
    //retirar o '~' se a matriz por ativo baixo
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Pega o 1º bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Pega o 2º bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Pega o 3º bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Pega o 4º bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Pega o 5º bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Pega o 6º bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Pega o 7º bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Pega o 8º bit: 00000001

}