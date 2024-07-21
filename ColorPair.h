#ifndef COLOR_CODE_H
#define COLOR_CODE_H

const int MAX_COLORPAIR_NAME_CHARS = 16;

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct {
  enum MajorColor majorColor;
  enum MinorColor minorColor;
} ColorPair;

//const char* MajorColorNames[];
//const char* MinorColorNames[];

//int numberOfMajorColors;
//int numberOfMinorColors;

void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
void PrintColorCode(void);

#endif
