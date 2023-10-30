// copy last node on root node

// root node ko correct position me daalo

#include<iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    Heap()
    {
        size=0;
    }
    void insert(int value)
    {
        // value insert karo end me
        size=size+1;
        int index=size;
        arr[index]=value;

        // iss value ko sahi position me dalna hai
        while(index>1)
        {
            int parentIndex=index/2;
            if(arr[index]>arr[parentIndex])                 // parent se check karenge 
            {
                swap(arr[index],arr[parentIndex]);          // swap with parent
                index=parentIndex;                          // ab jo current index hai use bhi update kar denge parent index se jisse aage bhi check kar pae
            }
            else{
                break;
            }   
        }

    }
    int delete()
    {
        // copy last node value on root node value  
        arr[1]=arr[size];
        //  last node hata hai to bas size kam kardo
        size--;

        // place root node data in correct position
        int index=1;
        while(index<size)
        {   
            // root ke child nikale
            int left=2*index;
            int right=2*index+1;

            // root ko largest maan lia

            int largest=index;

            // ab root ko compare kia left child se aur right child se jo sabse bada hai uska index store kar lia largest me

            if(left<size    &&  arr[index]<arr[left])
            {
                largest=left;
            } 
            if(right<size   &&  arr[largest]<arr[right])
            {
                largest=right;
            }
            
            // agar index == largest to matlab root hi largest tha
            if(index==largest)
            {
                // value is at correct position
                break;
            }
            else{
                swap(arr[index],arr[largest]);
                index=largest
            }
           
        }
        return ans;
    }
};
int main()
{
    Heap h;
    h.arr[0]=-1;
    h.arr[1]=100;
    h.arr[2]=50;
    h.arr[3]=60;
    h.arr[4]=40;
    h.arr[5]=45;
    h.size=5;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);
    cout<<"Printing"<<endl;
    for(int i=0;i<=h.size;i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;
    h.insert(110);
    for(int i=0;i<=h.size;i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}