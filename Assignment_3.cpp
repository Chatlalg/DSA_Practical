#include <iostream>
using namespace std;
template <typename T>
class queue{
    public:
    int front ,rear;
    int *arr;
    int length;
    queue(int size){
        front=0;
        rear=0;
        arr=new T[size];
        length=size;
    }
    void insert(T input){
       if(!isfull()){
        arr[rear]=input;
        rear=(rear+1)%length;
       }
       else{
        cout<<"full "<<endl;
       }
    }
    bool isfull(){
       return (rear+1)%length==front;
    }
    bool is(){
        return front==rear;
    }
    void remove(){
        if(is()){
            cout<<"em"<<endl;
            return;
        }
        cout<<"element deleted"<<arr[front]<<endl;
        front=(front+1)%length;
        if(front==rear){
            front=rear=0;
        }
    }
    void dislplay(){
        int temp=front;
        while(temp!=rear){
            cout<<arr[temp]<<endl;
            temp=(temp+1)%length;
        }
    }

};
int main(){
    queue<int> *q=new queue<int>(10);
    cout<<q->is();
    q->insert(10);
    q->insert(51);
    q->insert(1351);
    q->dislplay();
    q->remove();
    q->dislplay();
    q->remove();
    q->remove();
    q->remove();
    q->remove();
    return 0;
}