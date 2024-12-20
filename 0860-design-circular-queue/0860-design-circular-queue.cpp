class MyCircularQueue {
public:
    vector<int>arr;
    int s;
    int f;
    int b;
    MyCircularQueue(int k) {
        s=0;
        vector<int>v(k);
        arr = v;
        f=0;
        b=0;
    }
    
    bool enQueue(int value) {
        if(s==arr.size())return false;
        else{
            if(b==arr.size())b=0;
            arr[b] = value;
            b++;
        }
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s==0)return false;
        s--;
        f++;
        if(f==arr.size())f=0;
        return true;
    }
    
    int Front() {
        if(s==0)return -1;
        return arr[f];
    }
    
    int Rear() {
        if(s==0)return -1;
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0)return true;
        return false;
    }
    
    bool isFull() {
        if(s==arr.size())return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */