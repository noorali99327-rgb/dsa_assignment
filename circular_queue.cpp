#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int CAPACITY = 5;
    int items[CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

public:
    CircularQueue() : frontIndex(0), rearIndex(-1), count(0) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == CAPACITY;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full; cannot enqueue " << value << ".\n";
            return;
        }
        rearIndex = (rearIndex + 1) % CAPACITY;
        items[rearIndex] = value;
        ++count;
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty; cannot dequeue.\n";
            return;
        }
        cout << items[frontIndex] << " dequeued.\n";
        frontIndex = (frontIndex + 1) % CAPACITY;
        --count;
        if (count == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }
    }

    void front() const {
        if (isEmpty()) {
            cout << "Queue is empty; there is no front element.\n";
            return;
        }
        cout << "Front element: " << items[frontIndex] << '\n';
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < count; ++i) {
            int index = (frontIndex + i) % CAPACITY;
            cout << items[index] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    CircularQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.front();
    queue.dequeue();
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();
    return 0;
}
