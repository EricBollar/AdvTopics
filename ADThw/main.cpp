#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

void removeEvens(stack<int> &numStack){
    stack<int> temp;
    while(!numStack.empty()){
        if(numStack.top()%2 == 1)
            temp.push(numStack.top());
        numStack.pop();
    }
    while(!temp.empty()){
        numStack.push(temp.top());
        temp.pop();
    }
}

void assignTask(queue<string>&taskQueue, set<string> &currentTasks){
    for(int i = 0; i<taskQueue.size(); i++){
        if(currentTasks.count(taskQueue.front())== 0){
            currentTasks.insert(taskQueue.front());
            taskQueue.pop();
            return;
        } else{
            taskQueue.push(taskQueue.front());
            taskQueue.pop();
        }
    }
}

map<string, set<string>> getCorrectClubMap(map<string, set<string>> & origMap){
    map<string, set<string>> newMap;
    auto itr = origMap.begin();
    while(itr!=origMap.end()){
        set<string> names = itr->second;
        string club = itr->first;
        for(string name:names){
            newMap[name].insert(club);
        }
        itr++;
    }
    return newMap;
}

int main() {
    queue<string> tasks;
    set<string> takenTasks;
    tasks.push("Hi");
    tasks.push("Bye");
    tasks.push("Hello");
    tasks.push("Goodbye!");
    takenTasks.insert("Hi");
    assignTask(tasks, takenTasks);
    while(!tasks.empty()){
        cout<<tasks.front()<<endl;
        tasks.pop();
    }
    return 0;
}