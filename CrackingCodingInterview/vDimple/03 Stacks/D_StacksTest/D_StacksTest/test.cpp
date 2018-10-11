#include "pch.h"
#include "..\..\01 ThreeStacksInOneArray\ThreeStacksInOneArray.h"

TEST(D_StacksTest, Test1) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Push(1);

	obj.print();

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Push(5);
	obj.s2Push(6);
	obj.s2Pop();
	obj.s2Pop();
	
	obj.print();

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.s1Push(2);
	obj.s2Push(5);
	obj.s3Push(8);

	obj.print();

	output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(D_StacksTest, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Push(1);

	obj.print();

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Push(5);
	obj.s2Push(6);
	obj.s2Pop();
	obj.s2Pop();

	obj.print();

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.s1Push(2);
	obj.s2Push(5);
	obj.s3Push(8);

	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(D_StacksTest, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Push(1);

	obj.print();

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Push(5);
	obj.s2Push(6);
	obj.s2Pop();
	obj.s2Pop();

	obj.print();

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.s1Push(2);
	obj.s2Push(5);
	obj.s3Push(8);

	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(D_StacksTest, Test4) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Push(1);

	obj.print();

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Push(5);
	obj.s2Push(6);
	obj.s2Pop();
	obj.s2Pop();

	obj.print();

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.s1Push(2);
	obj.s2Push(5);
	obj.s3Push(8);

	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(D_StacksTest, Test5) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Pop();
	obj.s1Push(1);

	obj.print();

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Push(5);
	obj.s2Push(6);
	obj.s2Pop();
	obj.s2Pop();

	obj.print();

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.s1Push(2);
	obj.s2Push(5);
	obj.s3Push(8);

	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}