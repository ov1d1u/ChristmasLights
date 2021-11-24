#include <Arduino.h>

#include <CircularBuffer.h>
#include <Tasker.h>
#include "Limits.h"
#include "Christmas.h"

#define RESUME_DELAY 60000

CircularBuffer<int,8> buffer;
Tasker tasker(true);
dimmerLamp yellowChannel(10);
dimmerLamp redChannel(6);
dimmerLamp greenChannel(9);
dimmerLamp blueChannel(11);
Christmas christmas(&redChannel, &greenChannel, &blueChannel, &yellowChannel);
bool isPausedForMusic = false;

void resetChristmasMode() {
  isPausedForMusic = false;
}

void setup() {
  Serial.begin(9600);
  yellowChannel.begin(NORMAL_MODE, ON);
  greenChannel.begin(NORMAL_MODE, ON);
  redChannel.begin(NORMAL_MODE, ON);
  blueChannel.begin(NORMAL_MODE, ON);
  christmas.begin();
}

void loop() {
  tasker.loop();
  
  if (!isPausedForMusic) {
    christmas.loop();
  }

  if (Serial.available()) {
    buffer.push(Serial.read());
  }

  if (buffer[0] == 65 && buffer[1] == 86 && buffer[2] == 65 && buffer.isFull()) {
    // Received AVA packet
    int command = buffer[3];
    tasker.cancel(resetChristmasMode);
    isPausedForMusic = true;

    if (command == 0) {
      greenChannel.setPower(map(0, 0, 255, 0, MAX_GREEN));
      redChannel.setPower(map(0, 0, 255, 0, MAX_RED));
      blueChannel.setPower(map(0, 0, 255, 0, MAX_BLUE));
      yellowChannel.setPower(map(0, 0, 255, 0, MAX_YELLOW));
    } else if (command == 1) {
      int r = buffer[4];
      int g = buffer[5];
      int b = buffer[6];
      int y = buffer[7];
  
      greenChannel.setPower(map(g, 0, 255, 0, MAX_GREEN));
      redChannel.setPower(map(r, 0, 255, 0, MAX_RED));
      blueChannel.setPower(map(b, 0, 255, 0, MAX_BLUE));
      yellowChannel.setPower(map(y, 0, 255, 0, MAX_YELLOW));
    } else if (command == 2) {
      isPausedForMusic = false;
    }

    buffer.clear();
    tasker.setTimeout(resetChristmasMode, 30000);
  }
}
