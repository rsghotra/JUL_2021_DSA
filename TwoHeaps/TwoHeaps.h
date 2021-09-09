#ifndef TWOHEAPS_H
#define TWOHEAPS_H
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//extending priorirty_queue
template <typename T, class Container = vector<T>,
          class Compare = less<typename Container::value_type>>
class priority_queue_with_remove: public priority_queue<T, Container, Compare> {
    public:
        bool remove(const & valueToRemove) {
            auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
            if(itr == this->c.end()) {
                return false;
            }
            this->c.erase(itr);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
};


class TwoHeaps {
    private:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue_with_remove<int> maxRHeap;
        priority_queue_with_remove<int, vector<int>, greater<int>> minRHeap;
        //minheap
        struct CapitalCompare {
            bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
                return x.first > y.first;
            }
        };
        struct ProfitCompare {
            bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
                return x.first < y.first;
            }
            
        };
    public:
        void InsertNum(int);
        double  FindStreamMedian();
        vector<double> FindSlidingWindowMedian(const vector<int>& arr, int k);
        void RebalanceRHeaps();
        int FindMaximumCapital(const vector<int>& capital, const vector<int>& profit, int initialCapital, int numProjectsAllowed);
};



#endif