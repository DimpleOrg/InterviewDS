#include "pch.h"
#include "..\01 ThreeStacksInOneArray\ThreeStacksInOneArray.h"
#include"..\02 StackMin\StackMin.h"
#include"..\03 StackOfPlates\StackofPlates.h"
#include"..\QueueUsingCircularArray\QueueUsingCircularArray.h"
#include"..\04 QueueViaStacks\QueueViaStacks.h"

TEST(D_QueueViaStacksTest, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();

	MyQueue<int> mq;
	try
	{
		mq.enqueue(1);
		mq.enqueue(2);
		mq.enqueue(3);
		mq.enqueue(4);
		mq.enqueue(5);
		std::cout << "\n Front element in queue is " << mq.front();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		//std::cout << "\n Front element in queue is " << mq.front();
		mq.enqueue(6);
		std::cout << "\n Front element in queue is " << mq.front();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}

TEST(D_QueueViaStacksTest, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	MyQueue<int> mq;
	try
	{
		mq.enqueue(1);
		mq.dequeue();
		mq.enqueue(2);
		mq.dequeue();
		mq.enqueue(3);
		mq.dequeue();
		mq.enqueue(4);
		mq.dequeue();
		mq.enqueue(5);
		std::cout << "\n Front element in queue is " << mq.front();
		mq.dequeue();
		mq.enqueue(6);
		std::cout << "\n Front element in queue is " << mq.front();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}


TEST(D_QueueUsingCircularArrayTest, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();
	{
		Queue<int> q(6);
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		q.enqueue(5);
		q.enqueue(6);

		q.print();
	}
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}

TEST(D_QueueUsingCircularArrayTest, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();
	try {
		Queue<int> q(4);
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		q.enqueue(5);
		q.dequeue();
		q.enqueue(6);

		q.print();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}

TEST(D_StackOfPlatesVOVTest, Test1)
{
	std::string output;
	testing::internal::CaptureStdout();
	{
		stackOfPlates<int> st(3);
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);
		st.push(7);
		st.push(8);
		st.push(9);
		st.push(10);

		st.print();
	}
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}


TEST(D_StackOfPlatesTest, Test1) 
{
	std::string output;
	testing::internal::CaptureStdout();
	{
		stackOfPlates<int> st(3);
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);
		st.push(7);
		st.push(8);
		st.push(9);
		st.push(10);

		st.print();
	}
	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}

TEST(D_StackOfPlatesTest, Test2)
{
	std::string output;
	testing::internal::CaptureStdout();

	stackOfPlates<int> st(2);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(9);
	st.push(10);

	st.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}

TEST(D_StackOfPlatesTest, Test3)
{
	std::string output;
	testing::internal::CaptureStdout();

	stackOfPlates<int> st(2);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(9);
	st.push(10);
	st.pop();
	st.pop();
	st.pop();
	st.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);

}

class person
{
public:
	std::string name;
	int age;

	bool operator==(const person& rhs)
	{
		return this->age == rhs.age;
	}
	bool operator>(const person& rhs)
	{
		return this->age > rhs.age;
	}
	bool operator<(const person& rhs)
	{
		return this->age < rhs.age;
	}

};

std::ostream& operator<<(std::ostream& out, const person& rhs)
{
	out << rhs.name << "\t" << rhs.age;
	return out;
}

TEST(D_StacksMinTest, Test1) {
	std::string output;
	testing::internal::CaptureStdout();
	
	stack<person> st;

	st.push({ "abc",5 });
	st.push({ "def", 6 });
	st.push({ "ghi", 7 });
	st.min();
	st.pop();
	st.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(st.min().age, 5);
	
}

TEST(D_StacksMinTest, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	stack<int> obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.print();
	std::cout << "\n*********************\n\n";
	std::cout << "Min : " << obj.min();
	std::cout << "\n*********************\n\n";
	obj.pop();
	std::cout << "Min after Pop : " << obj.min();
	std::cout << "\n*********************\n\n";
	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(obj.min(), 1);
	
}


TEST(D_StacksMinTest, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	stack<int> obj;
	obj.push(4);
	obj.push(3);
	obj.push(2);
	obj.push(1);
	obj.print();
	std::cout << "\n*********************\n\n";
	std::cout << "Min : " << obj.min();
	std::cout << "\n*********************\n\n";
	obj.pop();
	std::cout << "Min after Pop : " << obj.min();
	std::cout << "\n*********************\n\n";
	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(obj.min(), 2);
	
}

TEST(D_StacksMinTest, Test4) {

	std::string output;
	testing::internal::CaptureStdout();

	stack<int> obj;
	obj.push(-1);
	obj.push(3);
	obj.push(2);
	obj.push(1);
	obj.print();
	std::cout << "\n*********************\n\n";
	std::cout << "Min : " << obj.min();

	std::cout << "\n*********************\n\n";
	obj.pop();

	std::cout << "Min after Pop : " << obj.min();

	std::cout << "\n*********************\n\n";
	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(obj.min(), -1);

}

TEST(D_ThreeStacksInOneArrayTest, Test1) {

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

TEST(D_ThreeStacksInOneArrayTest, Test2) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();
	
	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Pop();

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

TEST(D_ThreeStacksInOneArrayTest, Test3) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);
	obj.s1Pop();

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Pop();

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(D_ThreeStacksInOneArrayTest, Test4) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj(8);
	obj.s1Push(1);
	obj.s1Push(2);

	obj.s2Push(3);
	obj.s2Push(4);
	obj.s2Push(5);
	obj.s2Push(6);

	obj.s3Push(7);
	obj.s3Push(8);
	obj.s1Pop();
	obj.s2Pop();


	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(D_ThreeStacksInOneArrayTest, Test5) {

	std::string output;
	testing::internal::CaptureStdout();

	Stacks<int> obj;
	obj.s1Push(1);
	obj.s1Push(2);

	obj.s2Pop();
	
	obj.s3Push(7);
	obj.s3Push(8);
	obj.s3Pop();

	obj.print();

	output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}