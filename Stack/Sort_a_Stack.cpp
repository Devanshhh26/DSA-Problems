#include <iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& s, int target) {
        //base case
        if(s.empty()) {
                s.push(target);         // agar stack empty hai to directly push kardo kyoki single element to sorted hi hoga
                return;
        }
        if(s.top() >= target) {         // agar stack ke top me bada element hai to target ko push krdo kyoki sorted hi rahega top to bottom 
                s.push(target);
                return;
        }
                                        // but agar top me chota element hai target se to fir top element ko nikalo aur firse recursive call maar do
        int topElement = s.top();
        s.pop();
        insertSorted(s, target);

        //BT                            // end me aake backtracking karni hai aur jo element pehle nikala tha use firse push kar dena hai
        s.push(topElement);
}

void sortStack(stack<int> &s) {
        //base case
        if(s.empty()) {
                return;
        }

        int topElement = s.top();
        s.pop();

        sortStack(s);

        insertSorted(s, topElement);
}


int main() {
  stack<int> s;
  s.push(7);
  s.push(11);
  s.push(3);
  s.push(5);
  s.push(9);

  sortStack(s);

  cout << "Printing" << endl;
  while(!s.empty()) {
          cout << s.top() << " ";
          s.pop();
  }
  cout << endl;
  return 0;
}