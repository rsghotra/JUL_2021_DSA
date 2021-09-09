#include "TwoHeaps.h"

void TwoHeaps::InsertNum(int num) {
    if(this->maxHeap.empty() || this->maxHeap.top() >= num) {
        maxHeap.push(num);
    } else {
        minHeap.push(num);
    }
    //re-balancing
    if(maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    } else if(maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double TwoHeaps::FindStreamMedian() {
    if(maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top())/2.0;
    }
    return maxHeap.top();
}

void TwoHeaps::RebalanceRHeaps() {
    if(this->maxRHeap.size() > this->minRHeap.size() + 1) {
        minRHeap.push(maxRHeap.top());
        maxRHeap.pop();
    } else if(this->maxRHeap.size() < this->minRHeap.size()) {
        maxRHeap.push(minRHeap.top());
        minRHeap.pop();
    }
}


vector<double> TwoHeaps::FindSlidingWindowMedian(const vector<int>& arr, int k) {
    vector<double> result(arr.size() - k + 1);
    for(int windowEnd = 0; windowEnd < int(arr.size()); windowEnd++) {
        if(this->maxRHeap.empty() || arr[windowEnd] <= this->maxRHeap.top()) {
            maxRHeap.push(arr[windowEnd]);
        } else {
            minRHeap.push(arr[windowEnd]);
        }
        this->RebalanceRHeaps();
        //now check
        if(windowEnd - k + 1 >= 0) {
            //we have minimum k ele
            //calculate median of the window & then remove one element from the sliding window
            if(minRHeap.size() == maxRHeap.size()) {
                result[windowEnd-k+1] = minRHeap.top()/2.0 + maxRHeap.top()/2.0;
            } else {
                result[windowEnd-k+1] = maxRHeap.top();
            }
            //remove kerna hai element but konsa?
            int elementToBeRemoved = arr[windowEnd-k+1];
            if(elementToBeRemoved <= maxRHeap.top()) {
                maxRHeap.remove(elementToBeRemoved);
            } else {
                minRHeap.remove(elementToBeRemoved);
            }
            this->RebalanceRHeaps();
        }
    }
    return result;
}

int TwoHeaps::FindMaximumCapital(const vector<int>& capital, const vector<int>& profit, int initialCapital, int numProjectsAllowed) {
    int n = capital.size();
    //1, create min & max heaps
    priority_queue<pair<int, int>, vector<pair<int, int>>, CapitalCompare> minCapitalHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, ProfitCompare>  maxProfitHeap;

    //2, insert capital in minHeap
    for(int i = 0; i < capital.size(); i++) {
        minCapitalHeap.push(make_pair(capital[i], i));
    }
    //3, create availableCapital
    int availableCapital = initialCapital;
    for(int i = 0; i < numProjectsAllowed; i++) {
        while(!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
            int capitalIndex = minCapitalHeap.top().second;
            minCapitalHeap.pop();
            maxProfitHeap.push(make_pair(profit[capitalIndex], capitalIndex));
        }
        //if maxprofit is empty, it means no more project is available.
        if(maxProfitHeap.empty()) {
            break;
        }
        availableCapital += maxProfitHeap.top().first;
        maxProfitHeap.pop();
    }
    return availableCapital;
}