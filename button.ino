#ifdef BTN_PIN

bool brightDirection;
static bool startButtonHolding = false;                     // Flag: botton hold


void buttonTick()
{
  if (!buttonEnabled)                                       // ignore, if not enalbled
  {
    return;
  }

  touch.tick();
  uint8_t clickCount = touch.hasClicks() ? touch.getClicks() : 0U;


  // one click
  if (clickCount == 1U)
  {
    // toggle power
    setPower((power == 1) ? 0 : 1);
  }


  // two clicks
  if (clickCount == 2U)
  {
    // TODO: next effect
  }


  // 3 clicks
  if (clickCount == 3U)
  {
    // TODO: previous effect
  }


  // 4 clicks
  if (clickCount == 4U)
  {
    // nothing yet
  }


  // 5 clicks
  if (clickCount == 5U)
  {
    // nothing yet
  }


  // 6 clicks
  if (clickCount == 6U)
  {
    // nothing yet
  }


  // 7 clicks
  if (clickCount == 7U)
  {
    // nothing yet
  }


  // button holding start 
  if (touch.isHolded()) {
    if(power == 1) {
      brightDirection = !brightDirection;
      startButtonHolding = true;
    }
  }


  // continue holding
  if (touch.isStep()) {
    if(power == 1) {
  		// hold button with or without previous clicks 
  		switch (touch.getHoldClicks()) {
  		  // no clicks => change brightness
  		  case 0U: {
  		    // определение шага изменения яркости: при яркости [1..10] шаг = 1, при [11..16] шаг = 3, при [17..255] шаг = 15
  			//uint8_t delta = modes[currentMode].Brightness < 10U ? 1U : 5U;
  			//modes[currentMode].Brightness = constrain(brightDirection ? modes[currentMode].Brightness + delta : modes[currentMode].Brightness - delta, 1, 255);
  			// TODO
  			break;
  		  }
  		  // after one click => change speed
  		  case 1U: {
  			// modes[currentMode].Speed = constrain(brightDirection ? modes[currentMode].Speed + 1 : modes[currentMode].Speed - 1, 1, 255);
  			break;
  		  }
            // after two clicks => ?
  		  case 2U: {
  			// nothing yet
  			break;
  		  }
  
  		  default:
  			break;
  		}
    }
  }

  // botton released after holding
  if (!touch.isHold() && startButtonHolding) {
    if(power == 1) {
		startButtonHolding = false;
		// TODO: notify?
	  }
  }
  
}
#endif
