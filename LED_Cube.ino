/**
 *  4x4x4 LED Cube
 *  Reno Philibert
 * 
 *  Course:      GBCC IST112G (CRN 20318 / Spring 2015)
 *  Instructor:  Michael Harrison
 *
 *  Connection Setup
 * 
 *  Columns [(x,y) - Pin]
 *      (1,1) - 13
 *      (1,2) - 12
 *      (1,3) - 11
 *      (1,4) - 10
 *      (2,1) - 9
 *      (2,2) - 8
 *      (2,3) - 7
 *      (2,4) - 6
 *      (3,1) - 5
 *      (3-2) - 4
 *      (3-3) - 3
 *      (3,4) - 2
 *      (4,1) - 1
 *      (4,2) - 0
 *      (4,3) - A5
 *      (4,4) - A4
 * 
 *  Layers [layer - Pin]
 *      a - A0
 *      b - A1
 *      c - A2
 *      d - A3
 **/

// Declare the pins for the 16 columns (x/y)
int c[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A4, A5};
// Declare the vertical layers (z)
int z[4] = {A0, A1, A2, A3};
// Declare a timed delay so effects are visible (250ms)
int t = 250

// Intialize columns and layers
void setup() {
  // Initialize the columns
  for(int i = 0; i < 16; i++) {
    pinMode(c[i], OUTPUT);
  }
  
  // Initialize the layers
  for(int i = 0; i < 4; i++) {
    pinMode(z[i], OUTPUT);
  }

  // Seed random for different patterns
  randomSeed(analogRead(10));
}

// Main function, loops continuously
void loop() {
    // Turn everything off
    turnEverythingOff();
    // Flicker everything on
    flickerOn();
    // Turn everything on
    turnEverythingOn();
    // Delay 250ms
    delay(t);
    // Turn all on and off by layer up and down
    turnOnAndOffAllByLayerUpAndDownNotTimed();
    // Stomp layers up and down
    layerStompUpAndDown();
    // Turn everything on and off by column sideways
    turnOnAndOffAllByColumnSideways();
    // Delay 250ms
    delay(time);
    // Circle the top perimiter down
    aroundEdgeDown();
    // Turn everything off
    turnEverythingOff();
    // Random flicker
    randomFlicker();
    // Rain falling down
    randomRain();
    // Diagonal rectangle
    diagonalRectangle();
    // Turn each LED on one at a time
    goThroughAllOneAtATime();
    // Propeller spiral
    propeller();
    // Spiral clockwise and counter-clockwise
    spiralInAndOut();
    // Flicker everything off
    flickerOff();
    // Turn everything off
    turnEverythingOff();
    // Delay 2 seconds before repeating
    delay(2000);
}

// *********************************
// Functions
// *********************************

// Turns all LEDs off
void turnAllOff() {
    // Columns
    for(int i = 0; i < 16; i++) {
        digitalWrite(c[i], 1);
    }

    // Layers
    for(int i = 0; i < 4; i++) {
        digitalWrite(z[i], 0);
    }
}

// Turns all LEDs off
void turnEverythingOn() {
    // Columns
    for(int i = 0; i < 16; i++) {
        digitalWrite(c[i], 0);
    }

    // Layers
    for(int i = 0; i < 4; i++) {
        digitalWrite(z[i], 1);
    }
}

// Turns all columns off
void turnEverythingOff() {
    // Columns
    for(int i = 0; i < 16; i++) {
        digitalWrite(c[i], 1);
    }
}

// Flickers everything on with a delay
void flickerOn() {
    // Delay 150ms
    int d = 150;
    while(d != 0) {
        turnEverythingOn();
        delay(d);
        turnEverythingOff();
        delay(d);
        d-= 5;
    }
}

// Turn everything on and off by one layer up and down
// This function is not timed
void turnOnAndOffAllByLayerUpAndDownNotTimed() {
    // 75ms delay
    int x = 75;

    // Turn layers on and off
    for(int i = 5; i != 0; i--) {
        // Turn everything on
        turnEverythingOn();

        for(int i = 4; i != 0; i--) {
            digitalWrite(z[i-1], 0);
            delay(x);
        }

        for(int i = 0; i < 4; i++) {
            digitalWrite(z[i], 1);
            delay(x);
        }

        for(int i = 0; i < 4; i++) {
            digitalWrite(z[i], 0);
            delay(x);
        }

        for(int i = 4; i != 0; i--) {
            digitalWrite(z[i-1], 1);
            delay(x);
        }
    }
}

// Turn everything on and off by column, sideways
void turnOnAndOffAllByColumnSideways() {
    // 75ms delay
    int x = 75;
    // Turn everything off
    turnEverythingOff();

    // Turn on layers
    for(int i = 0; i < 4; i++) {
        digitalWrite(x[i], 1);
    }

    for(int y = 0; y < 3; y++) {
        // Turn on columns 0-3
        for(int i = 0; i < 4; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn on columns 4-7
        for(int i = 4; i < 8; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn on columns 8-11
        for(int i = 8; i < 12; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn on columns 12-15
        for(int i = 12; i < 16; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn off columns 0-3
        for(int i = 0; i < 4; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn off columns 4-7
        for(int i = 4; i < 8; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn off columns 8-11
        for(int i = 8; i < 12; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn off columns 12-15
        for(int i = 12; i < 16; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn on columns 12-15
        for(int i = 12; i < 16; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn on columns 8-11
        for(int i = 8; i < 12; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn on columns 4-7
        for(int i = 4; i < 8; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn on columns 0-3
        for(int i = 0; i < 4; i++) {
            digitalWrite(c[i], 0);
            delay(x);
        }

        // Turn off columns 12-15
        for(int i = 12; i < 16; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn off columns 8-11
        for(int i = 8; i < 12; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn off columns 4-7
        for(int i = 4; i < 8; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }

        // Turn off columns 0-3
        for(int i = 0; i < 4; i++) {
            digitalWrite(c[i], 1);
            delay(x);
        }
    }
}

// Single layer stomp, up and down
void layerStompUpAndDown() {
    // 75ms delay
  int x = 75;

  for(int i = 0; i < 4; i++) {
    digitalWrite(z[i], 0);
  }

  for(int y = 0; y < 5; y++) {
    for(int cnt = 0; cnt < 1; cnt++) { 
      for(int i = 0; i < 4; i++) {
        digitalWrite(z[i], 1);
        delay(x);
        digitalWrite(z[i], 0);
      }

      for(int i = 4; i != 0; i--) {
        digitalWrite(z[i-1], 1);
        delay(x);
        digitalWrite(z[i-1], 0);
      }
    }

    for(int i = 0; i < 4; i++) {
      digitalWrite(z[i], 1);
      delay(x);
    }

    for(int i = 4; i != 0; i--) {
      digitalWrite(z[i-1], 0);
      delay(x);
    }
  }
}

// Flicker off
void flickerOff() {
    // Turn everything on
  turnEverythingOn();

  for(int i = 0; i != 150; i+=5) {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
}

// Around via perimiter of the cube going down
void aroundEdgeDown() {
  for(int x = 200; x != 0; x-=50) {
      // Turn everything off
    turnEverythingOff();

    for(int i = 4; i != 0; i--) {
      digitalWrite(z[i-1], 1);
      digitalWrite(c[5], 0);
      digitalWrite(c[6], 0);
      digitalWrite(c[9], 0);
      digitalWrite(c[10], 0);
      
      digitalWrite(c[0], 0);
      delay(x);
      digitalWrite(c[0], 1);
      digitalWrite(c[4], 0);
      delay(x);
      digitalWrite(c[4], 1);
      digitalWrite(c[8], 0);
      delay(x);
      digitalWrite(c[8], 1);
      digitalWrite(c[12], 0);
      delay(x);
      digitalWrite(c[12], 1);
      digitalWrite(c[13], 0);
      delay(x);
      digitalWrite(c[13], 1);
      digitalWrite(c[15], 0);
      delay(x);
      digitalWrite(c[15], 1);
      digitalWrite(c[14], 0);
      delay(x);
      digitalWrite(c[14], 1);
      digitalWrite(c[11], 0);
      delay(x);
      digitalWrite(c[11], 1);
      digitalWrite(c[7], 0);
      delay(x);
      digitalWrite(c[7], 1);
      digitalWrite(c[3], 0);
      delay(x);
      digitalWrite(c[3], 1);
      digitalWrite(c[2], 0);
      delay(x);
      digitalWrite(c[2], 1);
      digitalWrite(c[1], 0);
      delay(x);
      digitalWrite(c[1], 1);
    }
  }
}

// Random flicker
void randomFlicker() {
    // Turn everything off
    turnEverythingOff();
    // 10ms delay
    int x = 10;

    for(int i = 0; i != 750; i+=2) {
        // Pick a random layer
        int randomLayer = random(0,4);
        // Pick a random column
        int randomColumn = random(0,16);

        // Turn selected on
        digitalWrite(z[randomLayer], 1);
        digitalWrite(c[randomColumn], 0);
        delay(x);

        // Turn selected off
        digitalWrite(z[randomLayer], 0);
        digitalWrite(c[randomColumn], 1);
        delay(x); 
    }
}

// Random rain falling from top down
void randomRain() {
    // Turn everything off
    turnEverythingOff();
    // 100ms delay
    int x = 100;

    for(int i = 0; i != 60; i+=2) {
        // Select a random column
        int randomColumn = random(0,16);

        // Turn on/off the top LED
        digitalWrite(c[randomColumn], 0);
        digitalWrite(z[0], 1);
        delay(x+50);

        // Turn on/off the LED next layer down
        digitalWrite(z[0], 0);
        digitalWrite(z[1], 1);
        delay(x);

        // Turn on/off the LED next layer down
        digitalWrite(z[1], 0);
        digitalWrite(z[2], 1);
        delay(x);

        // Turn on/off the LED next layer down
        digitalWrite(z[2], 0);
        digitalWrite(z[3], 1);
        delay(x+50);

        // Turn off the last LED and column
        digitalWrite(z[3], 0);
        digitalWrite(c[randomColumn], 1);
    }
}

// Diagonal rectangle
void diagonalRectangle() {
    // 350ms delay
    int x = 350;
    // Turn everything off
    turnEverythingOff();

    for(int count = 0; count<5; count++) {
        // Top left
        for(int i = 0; i < 8; i++) {
            digitalWrite(c[i], 0);
        }

        digitalWrite(z[3], 1);
        digitalWrite(z[2], 1);
        delay(x);
        turnEverythingOff();

        // Middle center
        for(int i = 4; i < 12; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[1], 1);
        digitalWrite(z[2], 1);
        delay(x);
        turnEverythingOff();

        // Bottom right
        for(int i = 8; i < 16; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[0], 1);
        digitalWrite(z[1], 1);
        delay(x);
        turnEverythingOff();

        // Bottom middle
        for(int i = 4; i < 12; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[0], 1);
        digitalWrite(z[1], 1);
        delay(x);
        turnEverythingOff();

        // Bottom left
        for(int i = 0; i < 8; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[0], 1);
        digitalWrite(z[1], 1);
        delay(x);
        turnEverythingOff();

        // Middle center
        for(int i = 4; i < 12; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[1], 1);
        digitalWrite(z[2], 1);
        delay(x);
        turnEverythingOff();

        // Top right
        for(int i = 8; i < 16; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[2], 1);
        digitalWrite(z[3], 1);
        delay(x);
        turnEverythingOff();

        // Top center
        for(int i = 4; i < 12; i++) {
            digitalWrite(c[i], 0);
        }
        digitalWrite(z[2], 1);
        digitalWrite(z[3], 1);
        delay(x);
        turnEverythingOff();
    }

    // Top left
    for(int i = 0; i < 8; i++) {
        digitalWrite(c[i], 0);
    }
    digitalWrite(z[3], 1);
    digitalWrite(z[2], 1);
    delay(x);
    turnEverythingOff();
}

// Propeller spiral
void propeller() {
    // Turn everything off
    turnEverythingOff();
    // 90ms delay
    int x = 90;

    for(int y = 4; y > 0; y--) {
        for(int i = 0; i < 6; i++) {
            // Turn on layer
            digitalWrite(z[y-1], 1);

            // A1
            turnColumnsOff();
            digitalWrite(c[0], 0);
            digitalWrite(c[5], 0);
            digitalWrite(c[10], 0);
            digitalWrite(c[15], 0);
            delay(x);

            // B1
            turnColumnsOff();
            digitalWrite(c[4], 0);
            digitalWrite(c[5], 0);
            digitalWrite(c[10], 0);
            digitalWrite(c[11], 0);
            delay(x);

            // C1
            turnColumnsOff();
            digitalWrite(c[6], 0);
            digitalWrite(c[7], 0);
            digitalWrite(c[8], 0);
            digitalWrite(c[9], 0);
            delay(x);

            // D1
            turnColumnsOff();
            digitalWrite(c[3], 0);
            digitalWrite(c[6], 0);
            digitalWrite(c[9], 0);
            digitalWrite(c[12], 0);
            delay(x);

            // D2
            turnColumnsOff();
            digitalWrite(c[2], 0);
            digitalWrite(c[6], 0);
            digitalWrite(c[9], 0);
            digitalWrite(c[13], 0);
            delay(x);

            // D3
            turnColumnsOff();
            digitalWrite(c[1], 0);
            digitalWrite(c[5], 0);
            digitalWrite(c[10], 0);
            digitalWrite(c[14], 0);
            delay(x);
        }
    }

  // D4
  turnColumnsOff();
  digitalWrite(c[0], 0);
  digitalWrite(c[5], 0);
  digitalWrite(c[10], 0);
  digitalWrite(c[15], 0);
  delay(x);
}

// Spiral in and out
void spiralInAndOut() {
    // Turn everything on
    turnEverythingOn();
    // 60ms delay
    int x = 60;

    for(int i = 0; i < 6; i++) {
        // Spiral in clockwise
        digitalWrite(c[0], 1);
        delay(x);
        digitalWrite(c[1], 1);
        delay(x);
        digitalWrite(c[2], 1);
        delay(x);
        digitalWrite(c[3], 1);
        delay(x);
        digitalWrite(c[7], 1);
        delay(x);
        digitalWrite(c[11], 1);
        delay(x);
        digitalWrite(c[15], 1);
        delay(x);
        digitalWrite(c[14], 1);
        delay(x);
        digitalWrite(c[13], 1);
        delay(x);
        digitalWrite(c[12], 1);
        delay(x);
        digitalWrite(c[8], 1);
        delay(x);
        digitalWrite(c[4], 1);
        delay(x);
        digitalWrite(c[5], 1);
        delay(x);
        digitalWrite(c[6], 1);
        delay(x);
        digitalWrite(c[10], 1);
        delay(x);
        digitalWrite(c[9], 1);
        delay(x);

        // Spiral out counter clockwise
        digitalWrite(c[9], 0);
        delay(x);
        digitalWrite(c[10], 0);
        delay(x);
        digitalWrite(c[6], 0);
        delay(x);
        digitalWrite(c[5], 0);
        delay(x);
        digitalWrite(c[4], 0);
        delay(x);
        digitalWrite(c[8], 0);
        delay(x);
        digitalWrite(c[12], 0);
        delay(x);
        digitalWrite(c[13], 0);
        delay(x);
        digitalWrite(c[14], 0);
        delay(x);
        digitalWrite(c[15], 0);
        delay(x);
        digitalWrite(c[11], 0);
        delay(x);
        digitalWrite(c[7], 0);
        delay(x);
        digitalWrite(c[3], 0);
        delay(x);
        digitalWrite(c[2], 0);
        delay(x);
        digitalWrite(c[1], 0);
        delay(x);
        digitalWrite(c[0], 0);
        delay(x);

        // Spiral in counter clock wise
        digitalWrite(c[0], 1);
        delay(x);
        digitalWrite(c[4], 1);
        delay(x);
        digitalWrite(c[8], 1);
        delay(x);
        digitalWrite(c[12], 1);
        delay(x);
        digitalWrite(c[13], 1);
        delay(x);
        digitalWrite(c[14], 1);
        delay(x);
        digitalWrite(c[15], 1);
        delay(x);
        digitalWrite(c[11], 1);
        delay(x);
        digitalWrite(c[7], 1);
        delay(x);
        digitalWrite(c[3], 1);
        delay(x);
        digitalWrite(c[2], 1);
        delay(x);
        digitalWrite(c[1], 1);
        delay(x);
        digitalWrite(c[5], 1);
        delay(x);
        digitalWrite(c[9], 1);
        delay(x);
        digitalWrite(c[10], 1);
        delay(x);
        digitalWrite(c[6], 1);
        delay(x);

        // Spiral out clock wise
        digitalWrite(c[6], 0);
        delay(x);
        digitalWrite(c[10], 0);
        delay(x);
        digitalWrite(c[9], 0);
        delay(x);
        digitalWrite(c[5], 0);
        delay(x);
        digitalWrite(c[1], 0);
        delay(x);
        digitalWrite(c[2], 0);
        delay(x);
        digitalWrite(c[3], 0);
        delay(x);
        digitalWrite(c[7], 0);
        delay(x);
        digitalWrite(c[11], 0);
        delay(x);
        digitalWrite(c[15], 0);
        delay(x);
        digitalWrite(c[14], 0);
        delay(x);
        digitalWrite(c[13], 0);
        delay(x);
        digitalWrite(c[12], 0);
        delay(x);
        digitalWrite(c[8], 0);
        delay(x);
        digitalWrite(c[4], 0);
        delay(x);
        digitalWrite(c[0], 0);
        delay(x);
    }
}
// Go through all LEDs one at a time
void goThroughAllOneAtATime() {
    // 15ms delay
    int x = 15;
    // Turn everything off
    turnEverythingOff();

    for(int y = 0; y < 5; y++) {
        // 0-3
        for(int cnt = 4; cnt != 0; cnt--) {
            digitalWrite(z[count-1], 1);

            for(int i = 0; i < 4; i++) {
                digitalWrite(c[i], 0);
                delay(x);
                digitalWrite(c[i], 1);
                delay(x);
            }

            digitalWrite(z[cnt-1], 0);
        }

        // 4-7
        for(int cnt = 0; cnt < 4; cnt++) {
            digitalWrite(z[cnt], 1);

            for(int i = 4; i < 8; i++) {
                digitalWrite(c[i], 0);
                delay(x);
                digitalWrite(c[i], 1);
                delay(x);
            }

            digitalWrite(z[cnt], 0);
        }

        // 8-11
        for(int cnt = 4; cnt != 0; cnt--) {
            digitalWrite(z[cnt-1], 1);

            for(int i = 8; i < 12; i++) {
                digitalWrite(c[i], 0);
                delay(x);
                digitalWrite(c[i], 1);
                delay(x);
            }

            digitalWrite(z[cnt-1], 0);
        }

        // 12-15
        for(int count = 0; count < 4; count++) {
            digitalWrite(z[cnt], 1);

            for(int i = 12; i < 16; i++) {
                digitalWrite(c[i], 0);
                delay(x);
                digitalWrite(c[i], 1);
                delay(x);
            }

            digitalWrite(z[cnt], 0);
        }
    }
}
