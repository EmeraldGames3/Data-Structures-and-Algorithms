#pragma once

typedef int TElem;

class BinaryTreeIteratorPreOrder;
class BinaryTreeIteratorInOrder;
class BinaryTreeIteratorPostOrder;

struct Node {
    TElem value;

    Node *parent;
    Node *leftChild;
    Node *rightChild;
};

class BinaryTree {
    friend class BinaryTreeIteratorPreOrder;
    friend class BinaryTreeIteratorInOrder;
    friend class BinaryTreeIteratorPostOrder;
private:
    Node *root;
    int nrElems;

public:
    BinaryTree();

    ~BinaryTree();

    void addLeft(TElem elem);

    void addRight(TElem elem);

    void remove(TElem elem);

    [[nodiscard]] int size() const;

    void printTreeInOrder();

    void inOrderTraversal(Node *node);
};
