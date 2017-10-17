/*******************************************************************************
*	to resolve leetcode programs with array
*	the first time,begin on 8,16,2017
*	Author : North D.K.
********************************************************************************/
#include "array.h"


int removeElement(vector<int>& nums, int val) {
	vector<int>::iterator iter = nums.begin();
	for (;iter != nums.end();) {
		if (*iter == val) 
			iter = nums.erase(iter);
		else
			iter++;

	
			//cout << *iter << endl;
	}
	return nums.size();
}

ListNode* removeListElements(ListNode* head, int val)
{
	ListNode* curNode = head;
	while (true)
	{
		if (curNode == NULL)
			return NULL;
		if (curNode->val != val)
			break;
		else
		{
			curNode = curNode->next;
			head = curNode;
		}
	}

	while (curNode->next)
	{
		if (curNode->next->val != val)
			curNode = curNode->next;
		else
			curNode->next = curNode->next->next;			
	}
	return head;
}

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 1)
		return 1;
	//int length = *iter;
	for (vector<int>::iterator iter = nums.begin() + 1;iter != nums.end();) {
		cout << "iter is " << *iter << " and iter -1 is " << *(iter - 1) << endl;
		if (*iter == *(iter - 1))
			iter = nums.erase(iter);
		else
		{
			iter++;
		}
	}
	return nums.size();
}

vector<vector<int>> threeSum(vector<int>& nums) {
	set<vector<int>> result;
	if (nums.size() < 3)
		return vector<vector<int>>(result.begin(), result.end());
	sort(nums.begin(), nums.end());
	vector<int>::iterator iter = nums.begin();
	for (;iter != nums.end() - 2 && *iter <= 0;iter++) {
		//if(*iter == *(iter + 1))
		//   continue;
		vector<int>::iterator left = iter + 1;
		vector<int>::iterator right = nums.end() - 1;
		while (left < right) {
			vector<int> tmp;
			int sum = *iter + *left + *right;
			if (sum == 0) {
				tmp.push_back(*iter);
				tmp.push_back(*left);
				tmp.push_back(*right);
				result.insert(tmp);
				while (++left < right && *left == *(left - 1));
				while (left < --right && *right == *(right + 1));
			}
			else if (sum < 0)
				left++;
			else
				right--;
		}
	}
	return vector<vector<int>>(result.begin(), result.end());
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	set<vector<int>> result;
	if (nums.size() < 4)
		return vector<vector<int>>(result.begin(), result.end());
	sort(nums.begin(), nums.end());
	vector<int>::iterator iter = nums.begin();
	for (;iter != nums.end() - 3;iter++) {
		//if(*iter == *(iter + 1))
		//   continue;
		vector<int>::iterator iter2 = iter + 1;
		for (;iter2 != nums.end() - 2;iter2++) {			
			vector<int>::iterator left = iter2 + 1;
			vector<int>::iterator right = nums.end() - 1;
			while (left < right) {
				vector<int> tmp;
				int sum = *iter + *iter2 + *left + *right;
				if (sum == target) {
					tmp.push_back(*iter);
					tmp.push_back(*iter2);
					tmp.push_back(*left);
					tmp.push_back(*right);
					result.insert(tmp);
					while (++left < right && *left == *(left - 1));
					while (left < --right && *right == *(right + 1));
				}
				else if (sum < target)
					left++;
				else
					right--;
			}
		}
	}
	return vector<vector<int>>(result.begin(), result.end());
}

int threeSumClosest(vector<int>& nums, int target) {
	int result = 0;
	if (nums.size() < 3)
		return result;
	sort(nums.begin(), nums.end());
	vector<int>::iterator iter = nums.begin();
	result = *iter + *(iter + 1) + *(iter + 2);
	int diff = abs(result - target);
	for (;iter != nums.end() - 2;++iter) {
		vector<int>::iterator left = iter + 1;
		vector<int>::iterator right = nums.end() - 1;
		while (left < right) {
			int sum = *iter + *left + *right;
			int newDiff = abs(sum - target);
			if (newDiff < diff) {
				result = sum;
				diff = newDiff;
			}
			//if (newDiff == diff && sum > result) result = sum;
			if (sum < target) left++;
			else right--;
		}
	}
	return result;
}

int maxArea(vector<int>& height)
{
	int result = 0;
	for (int m = 0;m < height.size() - 1;m++)
	{
		for (int n = m + 1;n < (int)height.size();n++)
		{
			int container = (n - m) * min(height[n],height[m]);
			result = max(result,container);
		}
	}
	return result;
}

void nextPermutation(vector<int>& nums) {
	if (nums.size() < 2) return;
	int index = nums.size() - 1;
	while (index > 0) {
		if (nums[index] > nums[index - 1]) break;
		index--;
	}
	if (0 == index) {
		sort(nums.begin(), nums.end());
		return;
	}
	int nextIndex = index;
	for (;nextIndex < nums.size();++nextIndex) {
		if (nums[nextIndex] <= nums[index - 1])
			break;
	}	
	int tmp = nums[index - 1];
	nums[index - 1] = nums[nextIndex - 1];
	nums[nextIndex - 1] = tmp;
	sort(nums.begin() + index, nums.end());
}

int search(vector<int>& nums, int target) {
	if (nums.size() < 1) return -1;
	//if(nums.size() == 1 && nums[0] == target) return 0;
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (nums[mid] == target) return mid;
		if (nums[mid] < nums[left]) {
			if (nums[mid] <= target && nums[right] >= target) left = mid + 1;
			else right = mid - 1;
		}
		else  {
			if (nums[mid]  >= target && nums[left] <= target) right = mid - 1;
			else left = mid + 1;
		}
	}
//	if (nums[left] == target) return left;
//	if (nums[right] == target) return right;
	return -1;
}

void searchPath(vector<int>& nums, int target, int pos, vector<int>& path, vector<vector<int>>& result);
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if (candidates.size() < 1) return result;
	vector<int> path;
	sort(candidates.begin(), candidates.end());
	searchPath(candidates, target, 0, path, result);
	return result;
}

void searchPath(vector<int>& nums, int target, int pos, vector<int>& path, vector<vector<int>>& result) {
	if (0 == target) {
		result.push_back(path);
		return;
	}
	for (int i = pos;i < nums.size();++i) {
		int tmp = target - nums[i];
		if (tmp < 0) return;
		path.push_back(nums[i]);
		searchPath(nums, tmp, i, path, result);
		path.pop_back();
	}
}

void searchPath2(vector<int> nums, int target, int pos, vector<int>& path, vector<vector<int>>& result) {
	if (0 == target) {
		result.push_back(path);
		return;
	}
	for (int i = pos;i < nums.size();++i) {
		if (i > pos && nums[i] == nums[i - 1]) continue;
		int tmp = target - nums[i];
		if (tmp < 0) return;
		path.push_back(nums[i]);
		//nums.erase(i);
		searchPath2(nums, tmp, i + 1, path, result);
		path.pop_back();
	}
}

int trap(vector<int>& height) {
	int result = 0;
	if (height.size() <= 0) return result;
	vector<int> leftMaxHeight(height.size(), 0), rightMaxHeight(height.size(), 0);
	int maxHeight = 0;
	for (int i = 0; i < height.size();++i) {
		leftMaxHeight[i] = maxHeight;
		if (maxHeight < height[i]) maxHeight = height[i];
	}
	maxHeight = 0;
	for (int i = height.size() - 1; i >= 0;--i) {
		rightMaxHeight[i] = maxHeight;
		if (maxHeight < height[i]) maxHeight = height[i];
	}

	for (int i = 0;i < height.size();++i) {
		int tmp = min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
		if (tmp > 0) result += tmp;
	}
	return result;
}

/*******************************************************************************************************
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
					********************************
For example:
			A = [2,3,1,1,4], return true.
			A = [3,2,1,0,4], return false.
*******************************************************************************************************/
bool canJump(vector<int>& nums) {	
	if (nums.size() < 1) return false;
	int maxDistance = 0;
	for (int i = 0;i < nums.size() && i <= maxDistance;++i) {
		//if(maxDistance >= nums.size() -1) return true;
		maxDistance = max(nums[i] + i, maxDistance);
	}
	return maxDistance >= nums.size() - 1 ? true : false;
}

int jump2(vector<int>& nums) {
	if (nums.size() < 1) return 0;
	int distance = 0, steps = 0, maxDistance = 0;
	for (int i = 0;i < nums.size();++i) {
		if (distance > nums.size() - 1) return steps;
		if (distance < i) {
			distance = maxDistance;
			steps++;
		}
		maxDistance = max(nums[i] + i, maxDistance);


	}
	return steps;
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> result;
	int count = intervals.size();
	if (count <= 0) return result;
	sort(intervals.begin(), intervals.end(), cmp);
	Interval last = intervals[0];
	//bool updateFlag = false;
	for (int i = 1;i < count;++i) {
		if (intervals[i].start > last.end) {
			result.push_back(last);
			last = intervals[i];
			//updateFlag = true;
			continue;
		}
		last.end = max(last.end, intervals[i].end);
		//if (updateFlag) updateFlag = false;
	}
	//if (!updateFlag) 
	result.push_back(last);
	return result;
}

bool cmp(const Interval& a, const Interval& b) {
	return a.start < b.start;
}

vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> result;
	int length = intervals.size(), count = 0;
	while (count < length && intervals[count].end < newInterval.start) {
		result.push_back(intervals[count++]);
	}
	result.push_back(newInterval);
	while (count < length && newInterval.end >= intervals[count].start) {
		result.back().start = min(result.back().start, intervals[count].start);
		result.back().end = max(result.back().end, intervals[count].end);
		count++;
	}
	while (count < length) {
		result.push_back(intervals[count++]);
	}
	return result;
}



vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	if (nums.empty())
		return nums;
	int r_length = nums.size();
	int c_length = nums[0].size();
	if ((r * c) != r_length * c_length)
		return nums;
	vector<int> tmparray(r_length * c_length, 0);
	vector<vector<int>> result;
	int flag = 0;
	for (int i = 0;i < r_length;++i) {
		for (int j = 0;j < c_length;++j) {
			tmparray[flag++] = nums[i][j];
		}
	}
	flag = 0;
	for (int i = 0;i < r;++i) {
		vector<int> tmp;
		for (int j = 0;j < c;++j) {
			tmp.push_back(tmparray[flag++]);
		}
		result.push_back(tmp);
	}
	return result;
}

bool containsDuplicate(vector<int>& nums) {
	if (nums.empty()) return false;
	sort(nums.begin(), nums.end());
	//int flag = 1;
	for (int i = 1;i < nums.size() - 1;++i) {
		if (nums[i] == nums[i - 1])
		{
			return true;
		}
	}
	return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if (nums.empty()) return false;
	int len = nums.size();
	for (int i = 0;i < len - 1;++i) {
		int j = i + 1;
		while ((j < len) && (j - i <= k)) {
			if (nums[i] == nums[j])
				return true;
			++j;
		}
	}
	return false;
}

int findMin(vector<int>& nums) {
	if (nums.empty())
		return -1;
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (left - right) >> 1;
		if (nums[mid] <= nums[right])
			right = mid;
		else
			left = mid + 1;
	}
	return nums[left];
}