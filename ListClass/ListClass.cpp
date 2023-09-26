#include <iostream>

template <typename T>
class List {
private:

	struct Node {
		Node* next;
		K element;
		Node(T& x) :element(x), next(nullptr) {}
	};
	Node* head;
public:
	List() :head(nullptr) {}

	void push_back(const T& x) {
		Node* currentnode = head;
		whlie(currentnode->next != nullptr) {
			currentnode = currentnode->next;
		}
		currentnode->next = new Node(x);
	}

};
int main()
{

}


