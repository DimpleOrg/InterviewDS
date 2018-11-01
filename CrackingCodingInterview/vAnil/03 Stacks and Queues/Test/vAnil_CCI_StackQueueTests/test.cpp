#include "pch.h"
#include "../../01 ThreeStackInOneArray/ThreeStackInOneArray.h"
#include "../../02 MinOfStack/MinOfStack.h"
#include "../../03 A_StacksOfPlates/StacksOfPlates.h"
TEST(ThreeStackTests, TestName) {

	ThreeStack<int> stackObj;

	stackObj.push(0, 11);
	stackObj.push(0, 12);
	stackObj.push(1, 21);
	stackObj.push(1, 22);
	stackObj.push(2, 31);
	stackObj.push(2, 32);
	stackObj.pop(0);
	stackObj.pop(2);

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(MinStackTests, Test1) {

	StackMin<int> stackObj;

	stackObj.push(11);
	stackObj.push(12);
	stackObj.push(21);
	stackObj.push(22);
	stackObj.push(31);
	stackObj.push(32);

	int min = stackObj.min();

	EXPECT_EQ(min, 11);

}

TEST(MinStackTests, Test2) {

	StackMin<int> stackObj;

	stackObj.push(11);
	stackObj.push(12);
	stackObj.push(1);
	stackObj.push(22);
	stackObj.push(31);
	stackObj.push(32);

	int min = stackObj.min();

	EXPECT_EQ(min, 1);

}

TEST(MinStackTests, Test3) {

	StackMin<int> stackObj;

	stackObj.push(11);
	stackObj.push(12);
	stackObj.push(1);
	stackObj.push(22);
	stackObj.push(31);
	stackObj.push(32);
	stackObj.push(4);

	int min = stackObj.min();

	EXPECT_EQ(min, 1);

}

TEST(StacksOfPlates, Test1) {

	StacksOfPlates<int> stackObj(3);

	stackObj.push(11);
	stackObj.push(12);
	stackObj.push(1);
	stackObj.push(22);
	stackObj.push(31);
	stackObj.push(32);
	stackObj.push(4);
	stackObj.pop();
	stackObj.pop();
	stackObj.pop();
	stackObj.pop();

	int elem = stackObj.peek();

	EXPECT_EQ(elem, 1);
}


TEST(StacksOfPlates, Test2) {

	StacksOfPlates<int> stackObj(3);

	stackObj.push(11);
	stackObj.push(12);
	stackObj.push(1);
	stackObj.push(22);
	stackObj.push(31);
	stackObj.push(32);
	stackObj.push(4);
	stackObj.subStackPop(0);


	int elem = stackObj.peek();

	EXPECT_EQ(elem, 1);
}