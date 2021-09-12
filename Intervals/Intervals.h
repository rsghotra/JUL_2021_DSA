#ifndef INTERVALS_H
#define INTERVALS_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Intervals {
	private:
		static vector<vector<int>> MergeIntervals(vector<vector<int>>& intervals);
		static vector<vector<int>> InsertIntervals(vector<vector<int>>& intervals, vector<int>& newInterval);
		static vector<vector<int>> IntervalsIntersection(vector<vector<int>>& intervals1, vector<vector<int>>& intervals2);
		static bool CanAttendAllAppointments(vector<vector<int>>& appointments);
		static int MinimumMeetingRooms(vector<vector<int>>& intervals);
		static int MaximumCPULoad(vector<vector<int>>& jobs);
		static vector<vector<int>> EmployeeFreeTime(vector<vector<vector<int>>>& schedule);
	public:
		static void MergeIntervals();
		static void InsertIntervals();
		static void IntervalsIntersection();
		static void CanAttendAllAppointments();
		static void MinimumMeetingRooms();
		static void MaximumCPULoad();
		static void EmployeeFreeTime();
};

#endif