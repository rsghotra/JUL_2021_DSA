#include "Test1.h"

struct EndCompare {
	bool operator()(const vector<int>& x, const vector<int>& y) {
		return x[1] > y[1];
	}
};


int Test1::MinimumMeetingRooms(vector<vector<int>>& meetings) {
	std::sort(meetings.begin(), meetings.end(), [](const vector<int>&x, const vector<int>& y) {
		return x[0] < y[0];
	});
	int minMeetingRooms = INT32_MIN;
	priority_queue<vector<int>, vector<vector<int>>, EndCompare> minHeap;
	for(auto meeting: meetings) {
		while(!minHeap.empty() && minHeap.top()[1] <= meeting[0]) {
			minHeap.pop();
		}
		minHeap.push(meeting);
		minMeetingRooms = max(minMeetingRooms, int(minHeap.size()));
	}
	return minMeetingRooms;
}

void Test1::MinimumMeetingRooms() {
	cout << "Minimum meeting rooms needed: " ;
	vector<vector<int>> meetings = {{1,4}, {2,5}, {7,9}};
	cout << MinimumMeetingRooms(meetings) << endl;
}

int Test1::MaxCPULoad(vector<vector<int>>& cpu) {
	int cuurentCPULoad = 0;
	int maxCPULoad = INT32_MIN;
	sort(cpu.begin(), cpu.end(),[](const vector<int>& x, const vector<int>& y) {
		return x[0] < y[0];
	});
	priority_queue<vector<int>, vector<vector<int>>, EndCompare> minHeap;

	for(auto job: cpu) {
		while(!minHeap.empty() && minHeap.top()[1] < job[0]) {
			cuurentCPULoad -= minHeap.top()[2];
			minHeap.pop();
		}
		cuurentCPULoad += job[2];
		maxCPULoad = max(maxCPULoad, cuurentCPULoad);
		minHeap.push(job);
	}
	return maxCPULoad;
}

void Test1::MaxCPULoad() {
	vector<vector<int>> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
	cout << "Maximum CPU load at any time: " << MaxCPULoad(input) << endl;

	input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
	cout << "Maximum CPU load at any time: " << MaxCPULoad(input) << endl;

	input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
	cout << "Maximum CPU load at any time: " << MaxCPULoad(input) << endl;
}

