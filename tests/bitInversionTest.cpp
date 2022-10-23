#include <sstream>

#include <gtest/gtest.h>

#include "bitInversion.h"


TEST(BitInv, BaseTest) {
    std::stringstream ssIn;
    ssIn << "25 1" << std::endl;
    std::stringstream ssOut;
    start(ssIn, ssOut);
    unsigned int result = 0;
    ssOut >> result;
    unsigned int expectedResult = 27;
    EXPECT_EQ(expectedResult, result);
}
