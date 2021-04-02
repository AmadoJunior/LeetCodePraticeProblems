//Problem =========================
/*
    Given the heads of two singly linked-lists headA and headB, 
    return the node at which the two lists intersect. 
    If the two linked lists have no intersection at all, return nullptr.
*/

//Singly-Linked List Implementation ===========
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

//Tools =====================
#include <unordered_map> //unordered_map (hash table implementation)
#include <utility> //make_pair, pair

//Naive Solution: Method 1(Simply use two loops)  ================== 
// O(M*N) Time (Exponential), O(1) Space.
class NaiveSolution {
public:
    ListNode *getIntersectionNodeNaive(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;
        while(listA){
            while(listB){
                if(listA == listB){
                    return  listA;
                } else {
                    listB = listB->next;
                }
            }
            listA = listA->next;
            listB = headB;
        }
        return nullptr;
    }
};

//Improved Solution: Method 2 (Save Visited Nodes (Use Hashing))  ==================
//This solution takes O(N) space which is bad is the list is very long.
//O(N+M) Time, O(N) Space.
class MapSolution {
public:
    ListNode *getIntersectionNodeMap(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;
        std::unordered_map<ListNode*, bool> visited;
        while(listA){
            visited.insert(std::pair<ListNode*, bool>(listA, 1));
            listA = listA->next;
        }
        while(listB){
            if(visited.count(listB)){
                return listB;
            } else {
                listB = listB->next;
            }
        }
        return nullptr;
    }
};

//Fastest Solution: Method 3(Using difference of node counts)  ==================
//O(N+M) Time, O(1) Space.
class Solution {
public:
    int getLength(ListNode* headNode){
        int count = 0;
        while(headNode){
            count++;
            headNode = headNode->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;
        int countA = getLength(listA);
        int countB = getLength(listB);
        int difference = abs(countA - countB);
        
        if(countA > countB){
            while(difference){
                listA = listA->next;
                difference--;
            }
        } else {
            while(difference){
                listB = listB->next;
                difference--;
            }
        }
        
        while(listA){
            if(listA == listB){
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }
        
        return nullptr;
    }
};