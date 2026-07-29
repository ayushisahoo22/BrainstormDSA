#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    
    while (prev->next != NULL && prev->next->next != NULL) {
        ListNode* first = prev->next;
        ListNode* second = prev->next->next;
        
        // Adjust pointers to swap the nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;
        
        // Move prev two nodes ahead for the next pair
        prev = first;
    }
    return dummy.next;
}

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}


void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val;
        if (curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

void freeList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    cout << "Original List: ";
    printList(head);
    head = swapPairs(head);
    cout << "Swapped List:  ";
    printList(head);
    freeList(head);
    
    return 0;
}
