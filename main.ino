#include <Adafruit_NeoPixel.h>
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 8, 4, 4, 8, 8, 8
};

void playSong() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote <= 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(12, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(12);
  }
}

Adafruit_NeoPixel pixels;

void setup() {
  pixels = Adafruit_NeoPixel(8, 8, NEO_GRB + NEO_KHZ800);
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(A2);
  Serial.println(potVal);

  if (potVal < 20) {
    pixels.clear();
    pixels.show();
  } else if (potVal > 980) {
    playSong();
    pixels.clear();
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
    pixels.show();
    delay(300);
  } else {
    float multi = potVal / 1025.0;
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(0, 0, round(255 * multi)));
    pixels.setPixelColor(6, pixels.Color(0, 0, round(255 * multi)));
    pixels.show();
  }
  delay(200);
}
