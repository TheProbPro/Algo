#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryHeap.h"

int secondLargestElem(int arr[], int length, int largest, int previous) {
    if (length < 1) {
        return previous;
    }
    int current = arr[length-1];
    if (largest < current) {
        previous = largest;
        largest = current;
    }
    if (largest > current > previous) {
        return secondLargestElem(arr, length - 1, largest, current);
    }
    return secondLargestElem(arr, length-1, largest, previous);
}

int main()
{
    //int arr1[] = { 23, 117, 10, 14, 18, 22, 29, 39, 51, 45, 49, 61, 65, 68, 81, 89 };
    //int arr2[] = {200, 300, 400, 500, 450, 250};
    //std::cout << secondLargestElem(arr1, 16, 0, 0) << std::endl;
    //std::cout << secondLargestElem(arr2, 6, 0, 0) << std::endl;
    /*
    BinarySearchTree tree;

    tree.insert(22);
    tree.insert(10);
    tree.insert(36);
    tree.insert(8);
    tree.insert(15);
    tree.insert(26);
    tree.insert(40);
    tree.insert(6);
    tree.insert(11);
    tree.insert(24);
    tree.insert(28);
    tree.insert(45);
    tree.insert(2);
    tree.insert(7);
    tree.insert(13);
    tree.insert(27);
    tree.insert(30);
    tree.insert(48);
    tree.insert(12);
    tree.insert(14);
    tree.insert(29);
    tree.insert(32);
    tree.insert(46);
    tree.insert(50);

    std::cout << tree.numberOfTwigs() << std::endl;
    */
    BinaryHeap<int> heap;
    heap.insert(13);
    heap.insert(21);
    heap.insert(16);
    heap.insert(24);
    heap.insert(31);
    heap.insert(19);
    heap.insert(68);
    heap.insert(65);
    heap.insert(26);
    heap.insert(32);
    heap.showXthElem(5);

    return 0;
}

