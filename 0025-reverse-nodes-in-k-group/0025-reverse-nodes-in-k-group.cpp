/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* currentN = head;
        ListNode* prevN = NULL;
        ListNode* nextN = head->next;
        while(currentN != NULL){
            nextN = currentN->next;  
            currentN->next = prevN;  
            prevN = currentN;        
            currentN = nextN;   
        }
        return prevN;
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp!= NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;  
        ListNode* temp = head;
        ListNode* nextNode;
        ListNode* prevNode = NULL;
        ListNode* newHead = NULL;
        // while(temp != NULL){
        //     ListNode* kthNode = getKthNode(temp, k);
        //     if(kthNode == NULL){
        //         if(prevNode){
        //             prevNode->next = temp;
        //         }
        //     }
        //     nextNode = kthNode->next;
        //     kthNode->next = NULL;
        //     reverseLL(temp);
        //     if(temp == head){
        //         head = kthNode;
        //     }
        //     else{
        //         prevNode->next = kthNode;
        //     }
        //     prevNode = temp;
        //     temp = nextNode;
        // }
        // return head;
        while(temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k); 
            if(kthNode == NULL) break;  

            nextNode = kthNode->next;   
            kthNode->next = NULL;       
            
            ListNode* reversedHead = reverseLL(temp);  
            
            if (!newHead) newHead = reversedHead;
            if (prevNode) prevNode->next = reversedHead;
            temp->next = nextNode;
            prevNode = temp;
            temp = nextNode;
        }
        
        return newHead ? newHead : head;
    }
};