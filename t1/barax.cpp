#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *Baraxeshkon(Node *head, int k, int n) {
    if (head == NULL || head->next == NULL) return head;
    Node *keep = new Node;
    keep->next = head;
    Node *pre = keep;
    Node *current;
    Node *next;
    while (n >= k) {
        current = pre->next;
        next = current->next;
        for (int i = 1; i < k; i++) {
            current->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = current->next;
        }
        pre = current;
        n -= k;
    }
    return keep->next;
}

void push(Node **head, int new_elm) {
    Node *new_node = new Node();
    new_node->data = new_elm;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node *head = NULL;
    int m, n, k, num;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        push(&head, num);
    }
    head = Baraxeshkon(head, n, n);
    //printList(head);
    for (int i = 0; i < m; ++i) {
        cin >> k;
        if (k != 0)
            head = Baraxeshkon(head, k, n);
    }
    printList(head);

    return (0);
}
