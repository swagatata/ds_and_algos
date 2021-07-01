/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lsum = new ListNode;
        ListNode* lsum_i = lsum;
        
        int remainder = 0;
        while(l1 != nullptr && l2 != nullptr) {
            int digisum = l1->val + l2->val + remainder;
            
            lsum_i->next = new ListNode;
            lsum_i = lsum_i->next;
            lsum_i->val = digisum%10;
            
            remainder = digisum/10;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2 != nullptr && l1 == nullptr) {
            l1 = l2;
        }
        if (l1 != nullptr) {
            while(l1 != nullptr) {
                lsum_i->next = new ListNode;
                lsum_i = lsum_i->next;
                lsum_i->val = (l1->val + remainder)%10;
                remainder = (l1->val + remainder)/10;
                
                l1 = l1->next;
            }
        }
        if (remainder > 0) {                            
            lsum_i->next = new ListNode;
            lsum_i = lsum_i->next;
            lsum_i->val = remainder;
        }
        

        return lsum->next;
    }
};

int main() {
  return 0;
}
