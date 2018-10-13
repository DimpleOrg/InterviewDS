#include "pch.h"
#include "../../01 ThreeStackInOneArray/ThreeStackInOneArray.h"
TEST(TestCaseName, TestName) {

	ThreeStack<float> stackObj;

	stackObj.push(0, 11.1);
	stackObj.push(0, 12.1);
	stackObj.push(1, 21.1);
	stackObj.push(1, 22.1);
	stackObj.push(2, 31.1);
	stackObj.push(2, 32.1);


  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}