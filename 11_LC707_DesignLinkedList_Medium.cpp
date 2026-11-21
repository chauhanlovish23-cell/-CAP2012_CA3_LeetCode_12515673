
class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    // Get value at index
    int get(int index) {
        Node* temp = head;

        for (int i = 0; temp != NULL; i++) {
            if (i == index)
                return temp->val;

            temp = temp->next;
        }

        return -1;
    }

    // Add node at beginning
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    // Add node at end
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Add node at given index
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete node at given index
    void deleteAtIndex(int index) {
        if (head == NULL)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }
};
