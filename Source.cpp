#include<iostream>

using namespace std;

class node {
public:
	int data;
	node* prev;
	node* next;
	node() {
		data = 0;
		prev = next = NULL;
	}
};

class Dlist {
	node* head;
public:
	Dlist() {
		head = NULL;
	}
	int insertFront(int data);
	int insertBack(int data);
	int removeFront();
	int removeBack();
	int remove_kth_element(int index);
	int remove_byVal(int val);
	int returnFront();
	int returnBack();
	int isEmpty();
	int lengthOfList();
	int getAt(int index);
	int delAll();
	void display();
};

int Dlist::delAll() {
	node* temp = head;
	if (head == NULL) {
		cout << "List is empty. There is nothing to remove." << endl;
		return 0;
	}
	node* temp1 = temp;
	while (temp->next != NULL) {
		temp = temp->next;
		temp->prev = NULL;
		temp1->next = temp1->prev = NULL;
		delete temp1;
		temp1 = temp;
	}
	temp->next = temp->prev = NULL;
	delete temp;
	head = NULL;
	return 1;
}

int Dlist::getAt(int index) {
	int count = 1;
	int lengthofList = 1;

	node* temp = head;
	while (temp->next != NULL) {
		lengthofList++;
		temp = temp->next;
	}
	if (index > lengthofList) {
		cout << "Your input index does not present in the list. INDEX OUT OF RANGE" << endl;
		return 0;
	}
	temp = head;
	if (head == NULL) {
		cout << "List is empty. There is nothing to delete." << endl;
	}
	else {
		while (temp->next != NULL) {
			if (count == index) {
				return temp->data;
			}
			// To check last element of list.
			if (count == index) {
				return temp->data;
			}
			temp = temp->next;
			count++;

		}
	}
}

int Dlist::lengthOfList() {
	int lengthofList = 1;
	node* temp = head;
	while (temp->next != NULL) {
		lengthofList++;
		temp = temp->next;
	}
	return lengthofList;
}

int Dlist::isEmpty() {
	if (head == NULL)return 1;
	else return 0;
}

int Dlist::returnFront() {
	return head->data;
}

int Dlist::returnBack() {
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp->data;
}

int Dlist::remove_byVal(int val) {
	if (head == NULL) {
		cout << "List is empty. There is nothing to delete from the list." << endl;
		return 0;
	}
	else {
		bool found = 0;
		node* temp = head;
		while (temp->next != NULL) {
			if (temp->data == val) {
				found = 1;
				break;
			}
			temp = temp->next;
		}
		if (temp->data == val) {
			found = 1;
			if (temp->next != NULL) {
				node* temp1 = temp;
				if (temp->prev == NULL) {
					temp = temp->next;
					head = temp;
					temp1->next = NULL;
					delete temp1;
				}
				else {
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp1->next = temp1->prev = NULL;
					delete temp1;
				}
			}
			else if (temp->next == NULL) {
				if (temp->prev == NULL) {
					delete temp;
					head = NULL;
				}
				else {
					temp->prev->next = NULL;
					temp->prev = NULL;
					delete temp;
				}
			}
		}
		if (found == 0) {
			cout << "Value not present in the list. " << endl;
			return 0;
		}
	}
	return 1;
}

void Dlist::display() {
	node* temp = head;
	if (head == NULL) {
		cout << "List is empty. There is nothing to print." << endl;
		return;
	}
	while (temp->next != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";
}

int Dlist::remove_kth_element(int index) {
	int count = 0;
	int lengthofList = 1;

	node* temp = head;
	while (temp->next != NULL) {
		lengthofList++;
		temp = temp->next;
	}
	if (index > lengthofList) {
		cout << "Your input index does not present in the list. INDEX OUT OF RANGE" << endl;
		return 0;
	}
	temp = head;
	if (head == NULL) {
		cout << "List is empty. There is nothing to delete." << endl;
	}
	else {
		while (temp->next != NULL) {
			if (count == index) {
				break;
			}
			temp = temp->next;
			count++;
		}
		if (temp->next != NULL) {
			node* temp1 = temp;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp1->next = temp1->prev = NULL;
			delete temp1;

		}
		else if (temp->next == NULL) {
			temp->prev->next = NULL;
			temp->prev = NULL;
			delete temp;
		}
	}
	return 1;
}

int Dlist::insertFront(int data) {
	node* newNode = new node;
	newNode->data = data;
	node* temp = head;
	if (head == NULL) {
		head = newNode;
	}
	else {

		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	return 1;
}

int Dlist::insertBack(int data) {
	node* newNode = new node;
	newNode->data = data;
	node* temp = head;
	if (head == NULL) {
		head = newNode;
	}
	else {

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	return 1;
}

int Dlist::removeFront() {
	if (head == NULL) {
		cout << "List is empty. There is nothing to delete." << endl;
	}
	else {
		node* temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		delete temp;
	}
	return 1;
}

int Dlist::removeBack() {
	if (head == NULL) {
		cout << "List is empty. There is nothing to delete." << endl;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->prev->next = NULL;
		temp->prev = NULL;
		delete temp;
	}
	return 1;
}


int main() {
	Dlist l;
	l.insertFront(2);
	l.insertFront(1);
	l.insertBack(3);
	l.insertBack(4);
	l.insertBack(5);
	l.insertBack(6);
	l.insertBack(7);
	l.insertBack(8);
	l.display();
	cout << endl;
	l.removeFront();
	l.removeBack();
	l.remove_kth_element(8);
	l.remove_byVal(2);
	l.display();
	cout << endl;
	cout << l.returnFront();
	cout << endl;
	cout << l.returnBack();
	cout << endl;
	cout << l.lengthOfList();
	cout << endl;
	cout << l.getAt(2);
	cout << endl;
	l.display();
	l.delAll();
	cout << endl;
	l.display();

	return 0;
}



