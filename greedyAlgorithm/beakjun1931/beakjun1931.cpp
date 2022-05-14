#include<iostream>
#include<vector>
#include<algorithm>

class Meeting{
	public:
		int startingTime;
		int finishingTime;

		Meeting(int _startingTime, int _finishingTime)
			:startingTime(_startingTime), finishingTime(_finishingTime){
		}
};

bool compareByFinishingTime(const Meeting &a, const Meeting &b){
	return a.finishingTime < b.finishingTime;
}


bool compareByStartingTime(const Meeting &a, const Meeting &b){
	return a.startingTime < b.startingTime;
}

int main(){
	int n;
	std::vector<Meeting> meetings;
	int count = 1;

	std::cin >> n;

	for(int i = 0; i < n; ++i){
		int a, b;
		std::cin >> a >> b;
		meetings.push_back(Meeting(a, b));
	}

	std::sort(meetings.begin(), meetings.end(), compareByStartingTime);
	std::sort(meetings.begin(), meetings.end(), compareByFinishingTime);

	int curruntFinishingTime = meetings[0].finishingTime;
	
	for(int i = 1; i < n; ++i){
		if(curruntFinishingTime <= meetings[i].startingTime){
			curruntFinishingTime = meetings[i].finishingTime;
			++count;
		}
	}

	std::cout << count;

	return 0;
}


