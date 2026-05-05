#include <bits/stdc++.h> 
#include "path.h"
using namespace std;

class MinPQ{
    private:
        vector <Path*> pq;
    private:

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
        
    public: 

        MinPQ(){
            pq.push_back(nullptr);
        }

        bool isEmpty(){
            return pq.size() == 1;
        }

        void insert(Path * x){
            pq.push_back(x);
            x->indexPQ = pq.size()-1;
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
        void remove(Path * x){
            // Key min = pq[x];
            long long index = x->indexPQ;
            exch(index, pq.size()-1);
            pq.pop_back();
            if(index < pq.size()){
                swim(index);
                sink(index);
            }
        }

        void print(){
            for(long long i =1; i<pq.size(); i++){
                cout << pq[i]->weight << endl;
            }
        }   
};