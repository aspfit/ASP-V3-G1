#include <iostream>
using namespace std;

struct Queue {
	int queue[10] = { 0 };
	int front = -1;
	int rear = -1;

	void Enqueue(int info) {
		if (isEmpty())
			front = rear = 0;
		else if (isFull()) { cout << "INFO :: Queue is FULL!" << endl; return; }
		else
			// rear++
			rear = (rear + 1) % (sizeof(queue) / sizeof(int));
		queue[rear] = info;
	}
	int Dequeue() {
		auto temp = -1;
		if (isEmpty())
			throw new exception("Queue is empty!");
		if (front == rear) {
			temp = queue[front];
			front = rear = -1;
			return temp;
		}
		else
			temp = queue[front];
		/*front++;*/
		front = (front + 1) % (sizeof(queue) / sizeof(int));
		return temp;
	}
	void PrintQueue() {
		/*if (!isEmpty())
			for (int i = front; i <= rear; i++)
				cout << queue[i] << endl;*/
		if (!isEmpty()) {
			int count = (rear + (sizeof(queue) / sizeof(int)) - front) % (sizeof(queue) / sizeof(int));
			for (int i = 0; i <= count; i++) {
				int index = (front + i) % (sizeof(queue) / sizeof(int));
				cout << "index [" << index << "] = " << queue[index] << endl;
			}
		}
	};
	void PrintAll() {
		for (int i = 0; i <= 10; i++)
			cout << queue[i] << endl;
	}
	void PrintIndexStatus() {
		cout << "-----------\nFront: " << front << "\nRear: " << rear << "\n-----------\n";
	}
	bool isEmpty() {
		return front == -1;
	}
	bool isFull() {
		/*return rear == (sizeof(queue) / sizeof(int)) - 1;*/
		return (rear + 1) % (sizeof(queue) / sizeof(int)) == front;
	}
};

int main() {
	auto queue = new Queue;
	queue->Enqueue(4);
	queue->Enqueue(3);
	queue->Enqueue(5);
	cout << "IsEmpty " << boolalpha << queue->isEmpty() << endl;
	cout << "IsFull " << boolalpha << queue->isFull() << endl;
	queue->PrintIndexStatus();
	queue->PrintQueue();
	queue->PrintAll();


	getchar();
	return 0;
}
