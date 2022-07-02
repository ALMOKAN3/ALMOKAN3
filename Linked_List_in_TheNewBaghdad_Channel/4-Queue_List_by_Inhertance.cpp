#include <iostream>
#include "4-Queue_List_by_Inhertance.hh"
using namespace std;

int main(){

    ds::Queue<int> queue;
    queue.push(45);
    queue.push(72);
    queue.push(15);
    queue.push(61);
    cout << "Queue: " << queue.pull() << endl;
    cout << "Queue: " << queue.pull() << endl;
    cout << "Queue: " << queue.pull() << endl;
    

    return 0;
}