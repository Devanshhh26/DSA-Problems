#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this -> data = data;
                this -> next = NULL;
        }
};

Node* startingPointLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }
        // jis bhi point pe slow aur fast milenge vaha se loop ke starting point ka distance equal hoga head se loop ke starting point ke distance tak ka
        // yaha slow head pe hai aur fast uss position pe hai jaha slow aur fast ek baar meet hue the
        while(slow != fast) {
                slow = slow -> next;
                fast =fast -> next;
        }

        return slow;
        

}
int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
  Node* seventh = new Node(70);
  Node* eighth = new Node(80);
  Node* ninth = new Node(90);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = fourth;


  cout << "Starting Point of LOOP is: " << startingPointLoop(head) -> data << endl;



  return 0;
}