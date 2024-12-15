#include <iostream>
using namespace std;
template <typename T>
class queue{
    public:
    int front ,rear;
    T *arr;
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
        cout<<"element deleted"<<arr[front].height<<arr[front].weight<<endl;
        front=(front+1)%length;
        if(front==rear){
            front=rear=0;
        }
    }
    void dislplay(){
        int temp=front;
        while(temp!=rear){
            cout<<arr[temp].height<<arr[temp].weight<<endl;
            temp=(temp+1)%length;
        }
    }

};

struct yash{
    int height;
    long long weight;
};

int main(){
    queue<yash> *q=new queue<yash>(10);
    yash mera_yashu;
    mera_yashu.height=5;
    mera_yashu.weight=198471938;
    // cout<<q->is();
    q->insert(mera_yashu);
    // q->insert(mera_yashu);
    // q->insert(1351);
    q->dislplay();
    q->remove();
    q->dislplay();
    // q->remove();
    // q->remove();
    // q->remove();
    // q->remove();
    return 0;
}