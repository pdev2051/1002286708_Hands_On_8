
#include <iostream>
#define SIZE 10

class Stack {
private:
    int arr[SIZE];
    int top;
public:
    Stack() : top(-1) {}
    bool isFull() { return top == SIZE - 1; }
    bool isEmpty() { return top == -1; }
    void push(int val) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

class Queue {
private:
    int arr[SIZE];
    int front, rear, count;
public:
    Queue() : front(0), rear(-1), count(0) {}
    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }
    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
        count++;
    }
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return val;
    }
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

class SinglyLinkedList {
private:
    struct Node {
        int data;
        int next;
    } nodes[SIZE];
    int head, freeIndex;
public:
    SinglyLinkedList() : head(-1), freeIndex(0) {
        for (int i = 0; i < SIZE - 1; i++)
            nodes[i].next = i + 1;
        nodes[SIZE - 1].next = -1;
    }
    bool isFull() { return freeIndex == -1; }
    void insert(int val) {
        if (isFull()) {
            std::cout << "List is full\n";
            return;
        }
        int newNode = freeIndex;
        freeIndex = nodes[freeIndex].next;
        nodes[newNode].data = val;
        nodes[newNode].next = head;
        head = newNode;
    }
    void remove(int val) {
        int curr = head, prev = -1;
        while (curr != -1 && nodes[curr].data != val) {
            prev = curr;
            curr = nodes[curr].next;
        }
        if (curr == -1) return;
        if (prev == -1) head = nodes[curr].next;
        else nodes[prev].next = nodes[curr].next;
        nodes[curr].next = freeIndex;
        freeIndex = curr;
    }
    void display() {
        int curr = head;
        while (curr != -1) {
            std::cout << nodes[curr].data << " -> ";
            curr = nodes[curr].next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    std::cout << "Stack Pop: " << s.pop() << "\n";

    Queue q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    std::cout << "Queue Dequeue: " << q.dequeue() << "\n";

    SinglyLinkedList list;
    list.insert(10); list.insert(20); list.insert(30);
    list.display();
    list.remove(20);
    list.display();
    return 0;
}
