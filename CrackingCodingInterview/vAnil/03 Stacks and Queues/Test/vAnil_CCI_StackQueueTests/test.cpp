#include "pch.h"
#include "../../01 ThreeStackInOneArray/ThreeStackInOneArray.h"
#include "../../02 MinOfStack/MinOfStack.h"
#include "../../03 A_StacksOfPlates/StacksOfPlates.h"
#include "../../04 QueueUsingStacks/QueueUsingStacks.h"
#include "../../06 AnimalShelter/AnimalShelter.h"

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

	EXPECT_EQ(elem, 4);
}



TEST(AnimalShelterTests, Test1) {

	AnimalShelter obj;

	obj.enqueue({ DOG, "DTommy1" });
	obj.enqueue({ CAT, "CCAT1" });
	obj.enqueue({ DOG, "DTommy2" });
	obj.enqueue({ CAT, "CCAT2" });
	obj.enqueue({ DOG, "DTommy3" });
	obj.enqueue({ CAT, "CCAT3" });
	obj.enqueue({ DOG, "DTommy4" });

	auto var = obj.dequeue(ANY);
	var = obj.dequeue(ANY);

	EXPECT_EQ(var.name, "CCAT1");
}


TEST(AnimalShelterTests, Test2) {

	AnimalShelter obj;

	obj.enqueue({ DOG, "DTommy1" });
	obj.enqueue({ CAT, "CCAT1" });
	obj.enqueue({ DOG, "DTommy2" });
	obj.enqueue({ CAT, "CCAT2" });
	obj.enqueue({ DOG, "DTommy3" });
	obj.enqueue({ CAT, "CCAT3" });
	obj.enqueue({ DOG, "DTommy4" });

	auto var = obj.dequeue(DOG);
	
	EXPECT_EQ(var.name, "DTommy1");
}


TEST(AnimalShelterTests, Test3) {

	AnimalShelter obj;

	obj.enqueue({ DOG, "DTommy1" });
	obj.enqueue({ CAT, "CCAT1" });
	obj.enqueue({ DOG, "DTommy2" });
	obj.enqueue({ CAT, "CCAT2" });
	obj.enqueue({ DOG, "DTommy3" });
	obj.enqueue({ CAT, "CCAT3" });
	obj.enqueue({ DOG, "DTommy4" });

	auto var = obj.dequeue(CAT);
	var = obj.dequeue(CAT);


	EXPECT_EQ(var.name, "CCAT2");
}


TEST(QueueUsingStack, Test1) {

	QueueUsingStacks<int> obj;

	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);

	auto val = obj.front();

	EXPECT_EQ(val , 1);
}

TEST(QueueUsingStack, Test4) {

	QueueUsingStacks<int> obj;

	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.enqueue(10);
	obj.dequeue();

	auto val = obj.front();

	EXPECT_EQ(val, 6);
}

TEST(QueueUsingStack, Test2) {

	QueueUsingStacks<int> obj;

	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);
	obj.dequeue();


	auto val = obj.front();

	EXPECT_EQ(val, 2);
}

TEST(QueueUsingStack, Test3) {

	QueueUsingStacks<int> obj;

	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);

	obj.dequeue();
	obj.dequeue();
	obj.dequeue();


	auto val = obj.front();

	EXPECT_EQ(val, 4);
}