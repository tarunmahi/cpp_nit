#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 1. Insert at the Beginning
    void insertAtBeginning(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at the End
    void insertAtEnd(int newData) {
        Node* newNode = new Node(newData);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Insert at a Given Position
    void insertAtPosition(int newData, int position) {
        if (position == 1) {
            insertAtBeginning(newData);
            return;
        }
        Node* newNode = new Node(newData);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) return; // Position out of bounds
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. Delete from the Beginning
    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 5. Delete from the End
    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // 6. Delete from a Given Position
    void deleteAtPosition(int position) {
        if (!head) return;
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next; i++) {
            temp = temp->next;
        }
        if (!temp->next) return; // Position out of bounds
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // 7. Search for an Element
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // 8. Reverse the Linked List
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 9. Find the Length of the Linked List
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 10. Find the Middle Element
    Node* findMiddle() {
        if (!head) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 11. Detect a Cycle in the Linked List
    bool detectCycle() {
        if (!head) return false;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // 12. Remove a Cycle from the Linked List
    void removeCycle() {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
    }

    // 13. Merge Two Sorted Linked Lists
    Node* mergeSortedLists(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        if (head1->data < head2->data) {
            head1->next = mergeSortedLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeSortedLists(head1, head2->next);
            return head2;
        }
    }

    // 14. Remove Duplicates from a Sorted Linked List
    void removeDuplicates() {
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
    }

    // 15. Print the Linked List
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 16. Delete the Entire Linked List
    void deleteList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    // 17. Check if a Linked List is a Palindrome
    bool isPalindrome() {
        if (!head || !head->next) return true;

        Node *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = slow;
        slow = slow->next;
        prev->next = nullptr;

        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head;
        slow = prev;
        while (slow) {
            if (fast->data != slow->data) return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {
    LinkedList list;

    // Testing the linked list operations
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    list.insertAtPosition(25, 3);
    list.printList();

    list.deleteFromEnd();
    list.printList();

    list.reverse();
    list.printList();

    cout << "Length: " << list.length() << endl;
    cout << "Middle Element: " << list.findMiddle()->data << endl;

    if (list.search(20)) {
        cout << "20 found in the list" << endl;
    } else {
        cout << "20 not found in the list" << endl;
    }

    list.deleteAtPosition(2);
    list.printList();

    cout << "Is Palindrome: " << (list.isPalindrome() ? "Yes" : "No") << endl;

    list.deleteList();
    list.printList(); // Should print nothing as the list is deleted

    return 0;
}
