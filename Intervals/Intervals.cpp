#include "Intervals.h"

/*
Merge Interval
*/
vector<vector<int>> Intervals::MergeIntervals(vector<vector<int>>& intervals) {
	if(intervals.size() < 2) return intervals;
	sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y){ return x[0] < y[0];});
	vector<vector<int>> result;
	vector<vector<int>>::iterator intervalItr = intervals.begin();
	vector<int> interval = *intervalItr;
	intervalItr++;
	int start = interval[0];
	int end = interval[1];
	while(intervalItr != intervals.end()) {
		interval = *intervalItr++;
		if(interval[0] <= end) {
			end = max(end, interval[1]);
		} else {
			result.push_back({start, end});
			start = interval[0];
			end = interval[1];
		}
	}
	result.push_back({start, end});
	return result;
}


void Intervals::MergeIntervals() {
	vector<vector<int>> input = {{1, 3}, {2, 5}, {7, 9}};
	cout << "Merged intervals: ";
	for (auto interval : MergeIntervals(input)) {
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	}
	cout << endl;

	input = {{6, 7}, {2, 4}, {5, 9}};
	cout << "Merged intervals: ";
	for (auto interval : MergeIntervals(input)) {
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	}
	cout << endl;

	input = {{1, 4}, {2, 6}, {3, 5}};
	cout << "Merged intervals: ";
	for (auto interval : MergeIntervals(input)) {
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	}
	cout << endl;
}

/*
Insert Interval
*/

vector<vector<int>> Intervals::InsertIntervals(vector<vector<int>>& intervals, vector<int>& newInterval) {
	if(intervals.empty()) {
		return {newInterval};
	}
	unsigned int i = 0;
	vector<vector<int>> result;
	//go to appropriate place
	while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
		result.push_back(intervals[i]);
		i++;
	}
	//keep going and merging
	while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
		newInterval[0] = min(newInterval[0], intervals[i][0]);
		newInterval[1] = max(newInterval[1], intervals[i][1]);
		i++;
	}
	result.push_back(newInterval);
	while(i < intervals.size()) {
		result.push_back(intervals[i]);
		i++;
	}
	return result;
}

void Intervals::InsertIntervals() {
	vector<vector<int>> input = {{1, 3}, {5, 7}, {8, 12}};
	cout << "Intervals after inserting the new interval: ";
	vector<int> newInterval = {4,6};
	for (auto interval : InsertIntervals(input, newInterval)) {
		cout << "[" << interval[0] << "," << interval[1]<< "] ";
	}
	cout << endl;

	newInterval = {4, 10};
	cout << "Intervals after inserting the new interval: ";
	for (auto interval : InsertIntervals(input, newInterval)) {
		cout << "[" << interval[0] << "," << interval[1]<< "] ";
	}
	cout << endl;

	input = {{2, 3}, {5, 7}};
	newInterval = {1,4};
	cout << "Intervals after inserting the new interval: ";
	for (auto interval : InsertIntervals(input, newInterval)) {
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	}
	cout << endl;
}

/*
Interval Intersection
*/

vector<vector<int>> Intervals::IntervalsIntersection(vector<vector<int>>& intervals1, vector<vector<int>>& intervals2) {
	vector<vector<int>> result;
	int i = 0, j = 0;
	while(i < int(intervals1.size()) && j < int(intervals2.size())) {
		if((intervals1[i][0] >= intervals2[j][0] && intervals1[i][0] <= intervals2[j][1]) || (intervals2[j][0] >= intervals1[i][0] && intervals2[j][0] <= intervals1[i][1])) {
			result.push_back({max(intervals1[i][0], intervals2[j][0]), min(intervals1[i][1], intervals2[j][1])});
		}
		if(intervals1[i][1] < intervals2[j][1]) {
			i++;
		} else {
			j++;
		}
	}
	return result;
}

void Intervals::IntervalsIntersection() {
	vector<vector<int>> input1 = {{1, 3}, {5, 6}, {7, 9}};
	vector<vector<int>> input2 = {{2, 3}, {5, 7}};
	vector<vector<int>> result = IntervalsIntersection(input1, input2);
	cout << "Intervals Intersection: ";
	for (auto interval : result) {
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	}
	cout << endl;

	input1 = {{1, 3}, {5, 7}, {9, 12}};
	input2 = {{5, 10}};
	result = IntervalsIntersection(input1, input2);
	cout << "Intervals Intersection: ";
	for (auto interval : result) {
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	}
}

/*
Can Attend All Appointments
*/

bool Intervals::CanAttendAllAppointments(vector<vector<int>>& appointments) {
	if(appointments.size() < 2) return true;
	//sort by start time
	sort(appointments.begin(), appointments.end(), [](const vector<int>& x, const vector<int>& y) { return x[0] < y[0];});
	vector<vector<int>>::iterator intervalItr = appointments.begin();
	vector<int> interval = *intervalItr;
	intervalItr++;
	int start = interval[0];
	int end = interval[1];

	while(intervalItr != appointments.end()) {
		interval = *intervalItr;
		intervalItr++;
		if(interval[0] <= end) {
			return false;
		} else {
			start = interval[0];
			end = interval[1];
		}
	}
	return true;
}

void Intervals::CanAttendAllAppointments() {
	vector<vector<int>> intervals = {{1, 4}, {2, 5}, {7, 9}};
	bool result = CanAttendAllAppointments(intervals);
	cout << "\nCan attend all appointments: " << result << endl;

	intervals = {{6, 7}, {2, 4}, {8, 12}};
	result = CanAttendAllAppointments(intervals);
	cout << "Can attend all appointments: " << result << endl;

	intervals = {{4, 5}, {2, 3}, {3, 6}};
	result = CanAttendAllAppointments(intervals);
	cout << "Can attend all appointments: " << result << endl;
}

struct EndCompare {
	bool operator()(vector<int>& x, vector<int>& y) {
		return x[1] > y[1];
	}
};

int Intervals::MinimumMeetingRooms(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y){return x[0] < y[0];});
	priority_queue<vector<int>, vector<vector<int>>, EndCompare> minHeap;
	int minRooms = 0;
	for(auto interval: intervals) {
		while(!minHeap.empty() && minHeap.top()[1] <= interval[0]) {
			minHeap.pop();
		}
		minHeap.push(interval);
		minRooms = max(minRooms, int(minHeap.size()));
	}
	return minRooms;
}

void Intervals::MinimumMeetingRooms() {
	vector<vector<int>> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
	int result = MinimumMeetingRooms(input);
	cout << "Minimum meeting rooms required: " << result << endl;

	input = {{1, 4}, {2, 5}, {7, 9}};
	result = MinimumMeetingRooms(input);
	cout << "Minimum meeting rooms required: " << result << endl;

	input = {{6, 7}, {2, 4}, {8, 12}};
	result = MinimumMeetingRooms(input);
	cout << "Minimum meeting rooms required: " << result << endl;

	input = {{1, 4}, {2, 3}, {3, 6}};
	result = MinimumMeetingRooms(input);
	cout << "Minimum meeting rooms required: " << result << endl;

	input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
	result = MinimumMeetingRooms(input);
	cout << "Minimum meeting rooms required: " << result << endl;
}

int Intervals::MaximumCPULoad(vector<vector<int>>& jobs) {
	if(jobs.size() < 2) return jobs.size();
	sort(jobs.begin(), jobs.end(), [](const vector<int>& x, const vector<int>& y){ return x[1] < y[1];});
	priority_queue<vector<int>, vector<vector<int>>, EndCompare> minHeap;
	int currentCPULoad = 0;
	int maxCPULoad = 0;

	for(int i = 0; i < int(jobs.size()); i++) {
		while(!minHeap.empty() && jobs[i][0] > minHeap.top()[1]) {
			currentCPULoad -= minHeap.top()[2];
			minHeap.pop();
		}
		minHeap.push(jobs[i]);
		currentCPULoad += jobs[i][2];
		maxCPULoad = max(maxCPULoad, currentCPULoad);
	}

	return maxCPULoad;
}

void Intervals::MaximumCPULoad() {
	vector<vector<int>> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
	cout << "Maximum CPU load at any time: " << MaximumCPULoad(input) << endl;

	input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
	cout << "Maximum CPU load at any time: " << MaximumCPULoad(input) << endl;

	input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
	cout << "Maximum CPU load at any time: " << MaximumCPULoad(input) << endl;
}

vector<vector<int>> Intervals::EmployeeFreeTime(vector<vector<vector<int>>>& schedule) {
	
}

void Intervals::EmployeeFreeTime() {
	vector<vector<vector<int>>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
	vector<vector<int>> result = EmployeeFreeTime(input);
	cout << "Free intervals: ";
	for (auto interval : result) {
		cout << "[" << interval[0] << ", " << interval[1] << "] ";
	}
	cout << endl;

	input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
	result = EmployeeFreeTime(input);
	cout << "Free intervals: ";
	for (auto interval : result) {
		cout << "[" << interval[0] << ", " << interval[1] << "] ";
	}
	cout << endl;

	input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
	result = EmployeeFreeTime(input);
	cout << "Free intervals: ";
	for (auto interval : result) {
		cout << "[" << interval[0] << ", " << interval[1] << "] ";
	}
}
