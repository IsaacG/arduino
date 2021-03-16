/* ***
 * Knitting Register
 * Helps track where in your knitting pattern you are at.
 * *** */

#include <stdio.h>
#include <M5StickC.h>
#include "pattern.h"

// Initial row count.
int row = 0;

// Print the pattern and current row.
void printPattern() {
    int size = sizeof pattern / sizeof *pattern;

    M5.Lcd.fillScreen(bg_color);
    M5.Lcd.setCursor(0, 0);
    for (int i = 0; i < size; i++) {
        M5.Lcd.println("");
        if (i == (row % size)) {
            M5.Lcd.setTextColor(cur_color);
            M5.Lcd.printf(cur_line_format, pattern[i]);
        } else {
            M5.Lcd.setTextColor(other_color);
            M5.Lcd.printf(other_line_format, pattern[i]);
        }
    }
}


void setup() {
    M5.begin();
    Serial.println("Event: Setup");

    M5.Lcd.setRotation(rotation);
    M5.Lcd.setTextColor(other_color, bg_color);
    M5.Lcd.setTextSize(text_size);
    printPattern();
}

void loop() {
    M5.update();

    // Main button. Move to the next row.
    if(M5.BtnA.wasPressed())
    {
        Serial.println("Event: BtnA");
        row++;
        printPattern();
    }

    // Secondary button. Sleep.
    if(M5.BtnB.wasPressed())
    {
        Serial.println("Event: BtnB");
        delay(10);
        M5.Axp.PowerOff();
    }

    delay(20);
}

// vim:expandtab:ts=4:sw=4
