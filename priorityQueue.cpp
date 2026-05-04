#include <bits/stdc++.h> 
#include "path.h"
using namespace std;

class MinPQ{
    public:
        vector <Path*> pq;
    public:

        bool greater(long long i, long long j){
            if(pq[i]->weight != pq[j]->weight){
                return pq[i]->weight >pq[j]->weight;
            }
            return pq[i]->ID>pq[j]->ID;
        }

        void exch(long long i, long long j){
            Path * t = pq[i];
            pq[i] = pq[j];
            pq[i]->indexPQ = i;
            pq[j] = t;
            pq[j]->indexPQ = j;
        }

        MinPQ(){
            pq.push_back(nullptr);
        }

        bool isEmpty(){
            return pq.size() == 1;
        }

        void insert(Path * x){
            pq.push_back(x);
            swim(pq.size()-1);
        }

        Path * min(){
            if(pq.empty()){
                return nullptr;
            }
            else{
                return pq[1];
            }
        }
        void remove(long long x){
            // Key min = pq[x];
            exch(x, pq.size()-1);
            pq.pop_back();
            if(x < pq.size()){
                swim(x);
                sink(x);
            }
        }

        void swim(long long k){
            while(k>1 && greater(k/2, k)){
                exch(k/2, k);
                k = k/2;
            }
        }
        
        void sink(long long k){
            while(2*k < pq.size()){
                long long j = 2*k;
                if(j+1 < pq.size() && greater(j, j+1)){
                    j++;
                }
                if(!greater(k, j)){
                    break;
                }
                exch(k, j);

                k=j;
            }
        }
        void print(){
            for(long long i =1; i<pq.size(); i++){
                cout << pq[i]->weight << endl;
            }
        }   
};

int main(){
    MinPQ test;
    Path * first = new Path(1, 2, 10, nullptr, nullptr, 10);
    first->indexPQ = 1;
    test.insert(first);

    Path * second = new Path(1,2,5, nullptr, nullptr, 10);
    second->indexPQ = 2;
    test.insert(second);

    Path * third = new Path(1,3,20, nullptr, nullptr, 10);
    third->indexPQ = 3;
    test.insert(third);

    Path * fourth = new Path(1,2,1, nullptr, nullptr, 10);
    third->indexPQ = 4;
    test.insert(fourth);

    while(!test.isEmpty()){
        cout << test.min()->weight << endl;
        test.remove(1);
    }

}