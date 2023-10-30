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