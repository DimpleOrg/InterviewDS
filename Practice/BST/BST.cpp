#include "BST.h"

int main(int argc, char *argv[])
{
	BST<int> bst;

	bst.insert(10);
	bst.insert(12);
	bst.insert(9);
	bst.insert(14);
	bst.insert(1);
	//bst.insert(10);

	bst.inorder();

	bool result = bst.search(1);


	

	return EXIT_SUCCESS;

}