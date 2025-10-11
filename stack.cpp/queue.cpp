#include <bits/stdc++.h> 
using namespace std;

//Queue concept-FIFO
//Pop and push will occur from the front

void reverseFirstK(queue<int> &queue,int k)
{
    //creating stack to store the elements in reverse order
    stack<int>st;
    for(int i=0;i<k;i++){
        st.push(queue.front());
        queue.pop();
    }
    while(!st.empty()){
        //pushing them to the end of q and popping from stack
        queue.push(st.top());
        st.pop();
    }
    int rem=queue.size()-k;
    for(int i=0;i<rem;i++){  //can't give directly queue.size()-k in this statement bcz size is changing
        queue.push(queue.front());
        queue.pop(); //poping the front element after inserting to the back
    }
}

int main(){
    int n;
    cout<<"Enter the size of queue: ";
    cin>>n;
    queue<int>q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    int k;
    cout<<"Enter the elements to reverse: ";
    cin>>k;
    reverseFirstK(q,k);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}