#include <iostream>
#include "BinaryHeap.h"
#include "BinarySearchTree.h"
#include "RecursiveMethods.h"
#include "Algorithmer.h"

int main()
{
    /* Test af getNumberEqual
    int n = 8;
    int x[8] = { 7, 4, 1, 4, 5, 6, 4, 8 };
    RecursiveMethods y;
    int test = y.getNumberEqual(x, n, 4);
    std::cout << test << std::endl;
    */

    /*
    BinarySearchTree tree;
    tree.insert(38);
    tree.insert(32);
    tree.insert(99);
    tree.insert(6);
    tree.insert(37);
    tree.insert(87);
    tree.insert(1);
    tree.insert(94);
    tree.insert(89);
    tree.insert(95);
    tree.preOrderTraversal();
    std::cout << std::endl;
    tree.inOrderTraversal();
    std::cout << std::endl;
    tree.postOrderTraversal();
    std::cout << std::endl;
    tree.levelOrderTraversal();
    std::cout << std::endl;
    std::cout << tree.internalPathlength() << std::endl;
    */

    Algorithmer A;
    std::cout << A.longestChain(10000) << std::endl;
    std::cout << A.pythagoranTriplets(1000) << std::endl;

    return 0;
}
