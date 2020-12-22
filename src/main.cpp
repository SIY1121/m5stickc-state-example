#include <Arduino.h>
#include <M5StickC.h>
#include "state/state.h"
#include "state/stateA.h"
#include "state/stateB.h"


State* stateMap[] = {
  new StateA(),
  new StateB()
};

StateNo current = StateNo::A;//初期状態

void setup() {
  M5.begin();
  M5.Lcd.setTextColor(TFT_WHITE, TFT_DARKCYAN);
  M5.Lcd.fillScreen(TFT_DARKCYAN);
}

void loop() {
  M5.update();
  StateNo next = stateMap[current]->exec();
  if(current != next) {
    current = next;
    M5.Lcd.fillScreen(TFT_DARKCYAN); //画面クリア
  }
  delay(10);
}