#include<iostream>
#include<queue>

using namespace std;
queue<long long>que;

long long bfs(int n){
  while(!que.empty()){//Infinite loop
    long long front = que.front();//get the first numbers of the queue!
    que.pop();//update queue
    if(front % n ==0)return front;
    que.push(front*10);
    que.push(front*10+1);
  }
  return 0;
}

int main(){
  int n;
  while(cin>>n){
    if(n==0)
      break;
    while(!que.empty()){
      que.pop();//make sure the queue is empty!
    }
    que.push(1);//init the queue!
    cout<<bfs(n)<<endl;
  }
  return 0;
}
