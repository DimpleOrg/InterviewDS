#include "pch.h"
#include "../../01 A_RouteBetweenNodes/routebetweennodes.h"
#include "../../02 MinimalTree/MinimalTree.h"

TEST(TreeGraphTests, Test1) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });

	bool val = gh.IsRouteExist("A", "E");

	EXPECT_EQ(val, true);
}

TEST(TreeGraphTests, Test2) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });

	bool val = gh.IsRouteExist("B", "D");

	EXPECT_EQ(val, true);
}

TEST(TreeGraphTests, Test3) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });

	bool val = gh.IsRouteExist("B", "H");

	EXPECT_EQ(val, false);
}

TEST(TreeGraphTests, Test4) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });
	gh.addEdge("G", { "F", 0 });

	bool val = gh.IsRouteExist("A", "G");

	EXPECT_EQ(val, false);
}


TEST(TreeGraphTests, Test5) {
	Graph gh;
	gh.addEdge("A", { "B", 0 });
	gh.addEdge("B", { "C", 0 });
	gh.addEdge("C", { "E", 0 });
	gh.addEdge("E", { "D", 0 });
	gh.addEdge("E", { "F", 0 });
	gh.addEdge("D", { "B", 0 });
	gh.addEdge("G", { "F", 0 });

	bool val = gh.IsRouteExist("A", "A");

	EXPECT_EQ(val, false);
}


TEST(MinimalTreeTests, Test1) {	
	auto result = makeMinimalTree({1,2,3,4,5,6,7,8,9,10});
}