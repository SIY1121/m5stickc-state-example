#include "state.h"
#include <M5StickC.h>

class StateB: public State {
  int counter = 0;
public:
  StateNo exec() override;
};

StateNo StateB::exec() {
  M5.Lcd.drawCentreString("Count", 40,50,4);
  M5.Lcd.drawNumber(counter, 0 , 80, 7);
  
  // ボタンBが押されたら切り替え
  if(M5.BtnB.wasPressed())
    return StateNo::A;
  // ボタンAが押されたらカウント
  else if(M5.BtnA.wasPressed())
    counter++;    

  return StateNo::B;
}