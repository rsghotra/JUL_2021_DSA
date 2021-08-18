#include<iostream>
#include<vector>
using namespace std;

struct order {
    uint64_t order_token;
    uint64_t shares;
    uint64_t price;
    bool side;
    uint64_t created_at;
    uint64_t cancelled_or_executed_at;
};

struct query {
    uint64_t query_time;
};

struct Interval {
    int start = 0;
    int end = 0;
    int num_of_shares = 0;
    Interval(int start, int end, int num) {
        this->start = 0;
        this->end = 0;

    }
};

std::vector<uint64_t> your_solution(vector<order>& orders, vector<order>& query) {
    if(orders.empty() == true || query.empty() == true) {
        return {};
    }

    for(auto ord: orders) {
        
    }
}