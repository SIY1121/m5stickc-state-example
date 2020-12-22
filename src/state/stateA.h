#include "state.h"
#include <M5StickC.h>

class StateA: public State {
  bool active = false;
  unsigned long time = 0;
public:
  StateNo exec() override;
};

StateNo StateA::exec() {
  M5.Lcd.drawCentreString("Timer", 40,50,4);

  M5.Lcd.drawNumber(active ? (millis() - time) / 1000 : 0, 0 , 80, 7);

  // ボタンBが押されたら切り替え
  if(M5.BtnB.wasPressed())
    return StateNo::B;
  // ボタンAが押されたらタイマースタート・リセット
  else if(M5.BtnA.wasPressed()) {
    if(!active) {
      active = true;
      time = millis();
    }
    else {
      active = false;
      M5.Lcd.fillScreen(TFT_DARKCYAN);
    }
  }

  return StateNo::A;
}