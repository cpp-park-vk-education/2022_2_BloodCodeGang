#include <sstream>

#include <gtest/gtest.h>

#include "bitCounter.h"


TEST(BitCount, BaseTest) {
    std::stringstream ssIn;
    ssIn << "0" << std::endl;
    std::stringstream ssOut;
    run(ssIn, ssOut);
    unsigned int result = 0;
    ssOut >> result;
    unsigned int expectedResult = 0;
    EXPECT_EQ(expectedResult, result);
    ssIn << "2332";
    run(ssIn, ssOut);
    ssOut >> result;
    expectedResult = 3;
    EXPECT_EQ(expectedResult, result);
}
