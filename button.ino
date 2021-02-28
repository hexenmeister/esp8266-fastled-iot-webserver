#ifdef BTN_PIN

bool direction;
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
      direction = !direction;
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
          // compute brightness step
          uint8_t delta = brightness < 10U ? 1U : brightness < 150U ? 5U : 10U;
          setBrightness(direction ? brightness > delta ? brightness - delta : 1U : brightness < 255U - delta ? brightness + delta : 255U);
          break;
  		  }
       
  		  // after one click => change speed
  		  case 1U: {
          // TODO
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
