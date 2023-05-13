#include "Queue.h"
#include <exception>
#include <iostream>

///ADT Queue – repräsentiert mithilfe eines zirkulären dynamischen Arrays von Elementen

using namespace std;

///this method initializes the variables which will be used in processing the queue. It also creates a dynamic array named queue
/**Complexity: Best Case: Θ(1), we just verify a condition
               Worst Case: Θ(1)
               Average Case: Θ(1)*/
Queue::Queue() {
	//TODO - Implementation
    this->capacity = 5;
    this->front = -1;
    this->rear = -1;
    this->queue = new TElem[this->capacity];
}

/**This method checks if the queue is empty, and if so, adds the element as the first element in the queue and sets the front and rear
    indexes accordingly. It then checks if the current queue needs to be resized and calls the resize method if so. After that, it
    adds the element at the end of the queue (pushes the element) and increments the rear index and if it reaches the capacity and there
    is still space at the beginning, it wraps around to the beginning**/

/**Complexity: Best Case: Θ(1), since it just has to add an element to the end of the queue
               Worst Case: Θ(n), when the resizing happens
               Average Case: Θ(1), cushioned (amortizat) complexity, resizing doesn't happen every time it needs to push an element*/
void Queue::push(TElem elem) {
    TElem printQueue;
    if (this->front == -1){
        this->queue[0] = elem;
        this->front = 0;
        this->rear = 0;
    }

    if ((this->capacity - this->front + this->rear) % this->capacity == this->capacity - 1){
        resize_push();
    }
    this->queue[this->rear++] = elem;
    if (this->rear == this->capacity){
        this->rear = 0;
    }
}

///This method checks if the queue is empty and if yes, it throws an exception, if not, it returns the first element in the queue
/**Complexity: Best Case: Θ(1), it just verifies a condition and returns an element
               Worst Case: Θ(1)
               Average Case: Θ(1)*/
TElem Queue::top() const {
	//TODO - Implementation
    if (isEmpty()){
        throw exception();
    }
    else{
        return this->queue[this->front];
    }
}

/**This method checks if the queue is empty and if yes, it throws an exception. It then stores the element from the front of the queue in a
   variable of type TElem named elem and increments the front index. The method also checks if the front index needs to wrap around when it
   reaches the capacity. If there are less than a quarter of elements in the queue, it performs a resize. It is a more efficient approach
   than working with the number of elements, due to the fact that it has a constant best case time complexity, rather than a linear one.**/

/**Complexity: Best Case: Θ(1), since it just needs to update the index and move it to the next element, basically increment the index
               Worst Case: Θ(n), when the resizing happens
               Average Case: Θ(1), cushioned (amortizat) complexity, resizing doesn't happen every time it needs to pop an element*/
TElem Queue::pop() {
    //TODO - Implementation
    if (isEmpty()) {
        throw exception();
    }
    TElem elem = this->queue[this->front++];
    if (this->front == this->capacity) {
        this->front = 0;
    }
    if (this->rear > this->front && this->rear - this->front < this->capacity/4){
        resize_pop();
    }
    return elem;
}

TElem Queue::print_helper() {
    //TODO - Implementation
    if (isEmpty()) {
        throw exception();
    }
    int copy_front;
    TElem* printQueue = this->queue;
    TElem elem = printQueue[copy_front++];
    if (this->front == this->capacity) {
        this->front = 0;
    }
    return elem;
}


///This method simply checks if the front index has reached the rear index. If yes, it means that the queue is empty
/**Complexity: Best Case: Θ(1), it just verifies a condition
               Worst Case: Θ(1)
               Average Case: Θ(1)*/
bool Queue::isEmpty() const {
	//TODO - Implementation
    return this->front == this->rear;
}

/**The resize method for the push operation is called when the queue is full, it doubles the capacity and then checks if the code has or has not
   wrapped around. If not, it simply iterates through the old queue and copies elements into the new queue.
   If yes, then it first iterates from the front to the end, and from 0 to rear and copies the elements into the new queue. It then sets the indexes
   accordingly and finally it destroys the current queue and replaces it with the new one.**/

/**Complexity: Best Case: Θ(n), because it always has to copy the elements from the initial queue into the newly created one
            Worst Case: Θ(n)
            Average Case: Θ(n)*/
void Queue::resize_push() {
    int size;
    if (this->rear >= this->front){
        size = this->rear - this->front;
    }
    else{
        size = this->capacity - this->front + this->rear;
    }
    this->capacity *= 2;
    TElem* queue2 = new TElem[this->capacity];

    if (this->rear > this->front) {
        for (int i = this->front; i < this->rear; i++){
            queue2[i - this->front] = this->queue[i];
        }
    }
    else {
        int i = 0;
        for (int j = this->front; j < this->capacity / 2; j++) {
            queue2[i++] = this->queue[j];
        }
        for (int j = 0; j < this->rear; j++) {
            queue2[i++] = this->queue[j];
        }
    }
    this->rear = size;
    this->front = 0;
    delete[] this->queue;
    this->queue = queue2;
}

/**The resize method for the pop operation is called when the queue has fewer than capacity/4 elements, it halves the capacity.
   It simply iterates through the old queue and copies elements into the new queue.
   It then sets the indexes accordingly and finally it destroys the current queue and replaces it with the new one.**/

/**Complexity: Best Case: Θ(n), because it always has to copy the elements from the initial queue into the newly created one
            Worst Case: Θ(n)
            Average Case: Θ(n)*/
void Queue::resize_pop() {
    int size;
    if (this->rear >= this->front){
        size = this->rear - this->front;
    }
    else{
        size = this->capacity - this->front + this->rear;
    }
    if (size >= this->capacity/4) {
        return;
    }
    this->capacity /= 2;
    TElem* new_queue = new TElem[this->capacity];
    for (int i = this->front; i < this->rear; i++) {
        new_queue[i - this->front] = this->queue[i];
    }
    this->rear = size;
    this->front = 0;
    delete[] queue;
    this->queue = new_queue;
}

/**descr: it prints the the current elements in the queue
   pre: q e Q
   post: elemnts from front to the rear
   throws: an exception, if the queue is empty

   Complexity: Best Case: Θ(n), because it has to move the front index until it reaches the rear index, where n reprsents the size of the queue
               Worst Case: Θ(n), because it has to move the front index until it reaches the rear index, where n reprsents the size of the queue
               Average Case: Θ(n)

Pseudocode:
function print_queue() is:
   if isEmpty() = True then
       @error - queue is empty
   else
       q.copy_front = q.front
       while (q.copy_front != q.rear)
            write q.queue[q.rear]
            q.copy_front = (q.copy_front + 1) % q.capacity
       end-while
   end-if
end-function
*/

void Queue::print_queue(){
    if (isEmpty()){
        throw exception();
    }
    else{
        TElem* printQueue = this->queue;
        int copy_front = this->front;
        while(!isEmpty()){
            print_helper();
            cout << printQueue[copy_front] << " ";
        }
    }
}

///This method destroys the queue
/**Complexity: Best Case: Θ(1)
               Worst Case: Θ(1)
               Average Case: Θ(1)*/
Queue::~Queue() {
	//TODO - Implementation
    delete[] this->queue;
}
