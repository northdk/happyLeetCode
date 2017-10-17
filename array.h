#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}	
};

int removeElement(vector<int>& nums, int val);
int removeDuplicates(vector<int>& nums);
vector<vector<int>> threeSum(vector<int>& nums);
vector<vector<int>> fourSum(vector<int>& nums, int target);
int threeSumClosest(vector<int>& nums, int target);
int maxArea(vector<int>& height);
void nextPermutation(vector<int>& nums);
int search(vector<int>& nums, int target);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
int trap(vector<int>& height);
bool canJump(vector<int>& nums);
int jump2(vector<int>& nums);
bool cmp(const Interval& a, const Interval& b);
vector<Interval> merge(vector<Interval>& intervals);
vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval);
bool containsDuplicate(vector<int>& nums);
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c);
bool containsDuplicate(vector<int>& nums);
bool containsNearbyDuplicate(vector<int>& nums, int k);
int findMin(vector<int>& nums);
