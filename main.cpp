#include <iostream>
#include <assert.h>
#include "TeleCo_Color_Coder_file.h"

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
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

void ToString() {
    std::cout<<"REFERENCE MANUAL OF NUMBER TO COLOR MAPPING"<<std::endl;
    std::cout<<" "<<"Number"<<" "<<"Major Minor"<<std::endl;
    
    int Number = 1;
    while(Number<=25){
        TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(Number);
        std::cout<<" "<<Number<<"      "<<colorPair.ToString()<<std::endl;
        Number++;
    }
}
        

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    ToString();
    return 0;
}
