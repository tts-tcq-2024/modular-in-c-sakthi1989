#include "color_code.h"
#include <stdio.h>
#include <assert.h>

const char* MajorColorNames[] = {
  "White", "Red", "Black", "Yellow", "Violet"
};
int numberOfMajorColors =
  sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const char* MinorColorNames[] = {
  "Blue", "Orange", "Green", "Brown", "Slate"
};
const int MAX_COLORPAIR_NAME_CHARS = 16;
int numberOfMinorColors =
  sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
  sprintf(buffer, "%s %s",
          MajorColorNames[colorPair->majorColor],
          MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
  ColorPair colorPair;
  int zeroBasedPairNumber = pairNumber - 1;
  colorPair.majorColor =
      (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
  colorPair.minorColor =
      (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
  return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
  return colorPair->majorColor * numberOfMinorColors +
         colorPair->minorColor + 1;
}

void PrintColorCode(void) {
  printf("Color Code:\n");
  printf("  Major Color | Minor Color\n");
  printf("----------------------------\n");
  for (int major = 0; major < numberOfMajorColors; major++) {
    for (int minor = 0; minor < numberOfMinorColors; minor++) {
      ColorPair colorPair;
      colorPair.majorColor = (enum MajorColor)major;
      colorPair.minorColor = (enum MinorColor)minor;
      char buffer[MAX_COLORPAIR_NAME_CHARS];
      ColorPairToString(&colorPair, buffer);
      printf("  %s          | %s\n", MajorColorNames[major], buffer);
    }
  }
}
