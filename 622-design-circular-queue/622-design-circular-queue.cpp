class MyCircularQueue {
private:
    int cnt, size, headIdx;
    vector<int>q;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        cnt=0;
        size=k;
        headIdx=0;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        q[(headIdx + cnt)%size]=value;
        cnt+=1;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        headIdx= (headIdx + 1)%size;
        cnt-=1;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return q[headIdx];
    }
    
    int Rear() {
        if(isEmpty())return-1;
        return q[(headIdx + cnt - 1)%size];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
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