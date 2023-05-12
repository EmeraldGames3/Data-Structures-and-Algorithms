#include "Matrix.h"
#include <exception>

/** the constructor initializes the variables which we'll use in the implementations. It initializes head and tail with nullptr
    Time Complexity: Best Case: Θ(1)
                     Worst Case: Θ(1)
                     Average Case: Θ(1)
 */

Matrix::Matrix(int nrLines, int nrCols) {
    this->numRows = nrLines;
    this->numColumns = nrCols;
    this->head = nullptr;
    this->tail = nullptr;
}

/** the nrLines method returns the number of rows in the matrix
    Time Complexity: Best Case: Θ(1)
                     Worst Case: Θ(1)
                     Average Case: Θ(1)
 */
int Matrix::nrLines() const {
    return this->numRows;
}

/** the nrColumns method returns the number of columns in the matrix
    Time Complexity: Best Case: Θ(1)
                     Worst Case: Θ(1)
                     Average Case: Θ(1)
 */
int Matrix::nrColumns() const {
    return this->numColumns;
}

/** the element method iterates through the DLL and searches the node whose indexes match with the indexes given as parameters
    it returns the value of that node or an exception if the indexes are out of bounds

    Time Complexity: Best Case: Θ(1), when the searched node is at the beginning of the list
                     Worst Case: Θ(n), where n represents the total number of nodes in the list, when the searched is at the end of the list
                     Average Case: Θ(n), where n represents the total number of nodes in the list
 */
TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= this->numRows || j < 0 || j >= this->numColumns) {
        throw std::exception();
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->row == i && current->column == j) {
            return current->value;
        }
        current = current->next;
    }
    return NULL_TELEM;
}

/** the modify method takes 4 cases into account:
    1. when old value == 0 and e != 0, then we need to add a node to the list
    2. when old value != 0 and e == 0, then we need to delete a node from the list
    3. when old value != 0 and e != 0, then we simply have to change the value of the current node
    4. when old value == 0 and e == 0, then we don't have to do anything

    Time Complexity: Best Case: Θ(1), when the node to be updated is at the head of the list, and we only have to update the value of the node
                     Worst Case: Θ(n), where n represents the total number of nodes in the list, when the node to be updated is at the end of the list
                     Average Case: Θ(n), where n represents the total number of nodes in the list
 */
TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= numRows || j < 0 || j >= numColumns) {
        throw std::exception();
    }
    TElem old_value;
    Node* current = head;

    // lexicographical way to search for the indexes of a node
    while (current != nullptr && current->row < i) {
        current = current->next;
    }
    while (current != nullptr && current->row == i && current->column < j) {
        current = current->next;
    }

    // First, establish the old value
    if (current != nullptr && current->row == i && current->column == j){
        old_value = current->value;
    }
    else{
        old_value = NULL_TELEM;
    }

    // Case 1: old_value == 0 && e != 0 (add a node to the list)
    if (old_value == NULL_TELEM && e != NULL_TELEM){
        Node* newNode = new Node{i, j, e, nullptr, nullptr};
        if (current == nullptr){  // Checking if the current node doesn't exist in the list
            if (head == nullptr){   // Checking if the list is empty
                head = newNode;
                tail = newNode;
            }
            else{   // Add the new node at the back of the list if the list doesn't contain the current node
                newNode->previous = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
        else{   // If the current node does exist, we add the new node before the current node, since the current node contains the indexes
                // of the element after the new node
            if (current == head){
                head = newNode;
            }
            else{
                newNode->previous = current->previous;
                current->previous->next = newNode;
            }
            newNode->next = current;
            current->previous = newNode;
        }
    }

    // Case 2: old_value != 0 && e == 0 (delete a node from the list)
    if (old_value != NULL_TELEM && e == NULL_TELEM){
        // We take into account three different cases, when the node is the first, when it is the last or somewhere in the middle of the list
        if (current == head){
            head = current->next;
            head->previous = nullptr;
        }
        else if (current == tail){
            tail = current->previous;
            tail->next = nullptr;
        }
        else{
            current->previous->next = current->next;
            current->next->previous = current->previous;
        }
        delete current;
    }
    // Case 3: old_value != 0 && e != 0
    else if (old_value != NULL_TELEM && e != NULL_TELEM){
        current->value = e;
    }
    // Case 4: old_value == 0 && e == 0, doesn't need any implementation
    return old_value;
}

/** the destructor destroys the nodes of the list and sets the head and tail pointers to be null
    Time Complexity: Best Case: Θ(n), where n represents the number of nodes in the list
                     Worst Case: Θ(n), where n represents the number of nodes in the list
                     Average Case: Θ(n), where n represents the number of nodes in the list
 */
Matrix::~Matrix() {
    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }

    head = nullptr;
    tail = nullptr;
}