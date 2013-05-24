#include "characters.h"
#define START_LED 3
#define END_LED 9
void ledbar_setup()
{
    int i;
    for(i = START_LED; i <= END_LED; i++) pinMode(i, OUTPUT);
}
void ledbar_write_char(int delay_time, char c)
{
    char* current;
    char* column;
    int j, k;
    int i = 0;
    do
    {
        current = characters[i];
        if(c == current[0])
        {
            for(j = 0; j < 5; j++)
            {
                column = characters[i + j + 1];
                for(k = 0; k < 7; k++)
                {
                    digitalWrite(START_LED + k, column[k + 1] == '*');
                }
                delay(delay_time);
            }
        }
        i += 6;
    }
    while(current);
}
void ledbar_write_blank(int delay_time)
{
    int k;
    for(k = 0; k < 7; k++)
        digitalWrite(START_LED + k, 0);
    delay(delay_time);
}
void ledbar_write_text(int delay_time, char* text)
{
    char c;
    while(c = *(text++))
    {
        ledbar_write_char(delay_time, c);
        ledbar_write_blank(delay_time);
    }
}
