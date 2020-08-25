#include <iostream>
#include <assert.h>
#include "TeleCo_Color_Coder_file.h"
void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor){
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

std::string ToString() {
    std::cout<<"REFERENCE MANUAL OF NUMBER TO COLOR MAPPING"<<std::endl;
    std::string colorPairString = "";
    int Number = 1;
    int TotalNoOfColorPairs = TelCoColorCoder::TotalNumberOfColorPairs;
    while(Number <= TotalNoOfColorPairs){
        TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(Number);
        colorPairString += Number;
        colorPairString += " ";
        colorPairString += colorPair.ToString();
        Number++;
    }
    return colorPairString;
}
int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    ToString();
    return 0;
}
