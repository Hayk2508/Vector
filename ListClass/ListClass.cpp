#include <iostream>

template <typename T>
class List {
private:

	struct Node {
		Node* next;
		T element;
		Node(const T& x) :element(x), next(nullptr) {}
		~Node() {
			delete next;
		}
	};
	Node* head;
public:
	List() :head(nullptr) {}
	~List() {
		delete head;
	}
	void push_back(const T& x) {
		Node* currentnode = head;
		if (currentnode == nullptr) {
			head = new Node(x);
			return;
		}
		while (currentnode->next != nullptr) {
			currentnode = currentnode->next;
		}
		currentnode->next = new Node(x);
	}
	void printList() {
		Node* currentnode = head;
		while (currentnode != nullptr) {
			std::cout << currentnode->element << " ";
			currentnode = currentnode->next;
		}
		std::cout << std::endl;
	}

};
int main()
{
	List <int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.printList();
}


