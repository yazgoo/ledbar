#include "Arduino.h"
#include "ledbar.c"
void setup() {
    ledbar_setup();
}
void loop()
{
    ledbar_write_text(200, "HELLO WORLD");
}
