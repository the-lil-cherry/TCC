#include <bits/stdc++.h> 
#include "path.h"
#include "priorityQueue.h"
using namespace std;


int main(){
    // colocar os asserts
    MinPQ test;
    Path * first = new Path(1, 2, 10, nullptr, nullptr, 10);
    test.insert(first);

    Path * second = new Path(1,2,5, nullptr, nullptr, 10);
    test.insert(second);

    Path * third = new Path(1,3,20, nullptr, nullptr, 10);
    test.insert(third);

    Path * fourth = new Path(1,2,1, nullptr, nullptr, 10);
    test.insert(fourth);

    Path * aux;

    while(!test.isEmpty()){
        aux = test.min();
        cout << aux->weight << endl;
        test.remove(aux);
    }

}