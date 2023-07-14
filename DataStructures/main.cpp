#include <iostream>
#include <cassert>
#include "BinaryTree/SimpleBinaryTree/BinaryTree.h"

using std::cout;

int main() {
    BinaryTree binaryTree;
    binaryTree.addLeft(5);
    binaryTree.addLeft(3);
    binaryTree.addRight(7);
    binaryTree.addLeft(2);
    binaryTree.addLeft(4);
    binaryTree.addRight(6);
    binaryTree.addRight(8);
    return 0;
}