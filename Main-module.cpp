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

std::string GetNumberToColorPairList() {
    std::cout<<"REFERENCE MANUAL OF NUMBER TO COLOR MAPPING"<<std::endl;
    std::string colorPairString;
    int TotalNoOfColorPairs = TelCoColorCoder::TotalNumberOfColorPairs;
    for(int Number = 1; Number <= TotalNoOfColorPairs; Number++){
        TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(Number);
        colorPairString += std::to_string(Number);
        colorPairString += " maps to ";
        colorPairString += colorPair.ToString();
        colorPairString += " || ";
    }
    return colorPairString;
}
int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    std::cout<<GetNumberToColorPairList()<<std::endl;
    return 0;
}
