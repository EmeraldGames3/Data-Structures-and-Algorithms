#include "SLL.h"

SLL::SLL() {
    head = nullptr;
    size = 0;
}

SLL::~SLL() {
    SLLNode *deletedNode;
    SLLNode *current = head;
    while (current != nullptr){
        deletedNode = current;
        current = current->next;
        delete deletedNode;
    }
}

int SLL::getSize() const {
    return size;
}

bool SLL::isEmpty() const {
    if(size == 0)
        return true;
    return false;
}

TElem SLL::deleteElement(TElem element) {
    if(isEmpty())
}