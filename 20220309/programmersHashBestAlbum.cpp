#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <typeinfo>

class songData{
    public:
    	int totalPlays;
    	std::vector<int> code;
        std::vector<int> plays;
    	songData();
    	~songData();
};

class songMethod{
	private:
		songData *data;
	public:
    	void insert(int code, int plays);
    	int getTotalPlays();
    	std::vector<int> getCode();
    	std::vector<int> getPlays();
    	std::vector<int> getFirstAndSecond();
    	songData getData();
    	songMethod();
		~songMethod();
};

bool compare(songMethod, songMethod);

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays) {
    std::unordered_map<std::string, songMethod> genresAndPlaysTotal;
    std::vector<int> answer;
    std::vector<songMethod> usingForSongSort;
    
    for(int i = 0; i < genres.size(); ++i){
        genresAndPlaysTotal[genres[i]].insert(i, plays[i]);
    }
    
   	for(auto& iter : genresAndPlaysTotal){
		songMethod temp = iter.second;
    	std::cerr << temp.getData().totalPlays << "\n";
		std::cerr << "iters type is : " << typeid(temp).name() << "\n";
   	   	usingForSongSort.push_back(temp);
   	}
   	
    //std::sort(usingForSongSort.begin(), usingForSongSort.end(), compare);
    
    std::cerr << "works here\n";
	std::cerr << usingForSongSort[0].getTotalPlays() << std::endl;
    for(auto& iter : usingForSongSort){
        std::vector<int> temp = iter.getFirstAndSecond();
        answer.push_back(temp[0]);
        answer.push_back(temp[1]);
    }
    
    return answer;
}

songData::songData(){
    totalPlays = 0;
}
songData::~songData(){
}

songMethod::songMethod(){
    data = new songData();
}
songMethod::~songMethod(){
    delete data;
	data = NULL;
}
void songMethod::insert(int code, int plays){
    data->totalPlays += plays;
    data->code.push_back(code);
    data->plays.push_back(plays);
}
std::vector<int> songMethod::getCode(){
    return data->code;
}
std::vector<int> songMethod::getPlays(){
    return data->plays;
}
std::vector<int> songMethod::getFirstAndSecond(){
    int index[2];
    std::vector<int> temp = data->plays;
    std::sort(temp.begin(), temp.end(), std::greater<int>());
    std::vector<int> FirstAndSecond;
    if(temp[0] == temp[1]){
        std::vector<int>::iterator tempIter;
        tempIter = std::find(data->plays.begin(), data->plays.end(), temp[0]);
        index[0] = tempIter - data->plays.begin();
        index[1] = std::find(tempIter + 1, data->plays.end(), temp[0]) - data->plays.begin();
    }
    else{
        index[0] = std::find(data->plays.begin(), data->plays.end(), temp[0]) - data->plays.begin();
        index[1] = std::find(data->plays.begin(), data->plays.end(), temp[1]) - data->plays.begin();
    }
    FirstAndSecond.push_back(data->code[index[0]]);
    FirstAndSecond.push_back(data->code[index[1]]);
    
    return FirstAndSecond;
}
int songMethod::getTotalPlays(){
    return data->totalPlays;
}
songData songMethod::getData(){
    return *data;
}

bool compare(songMethod a, songMethod b){
    if(a.getData().totalPlays > b.getData().totalPlays){
        return true;
    }
    else{
        return false;
    }
}


int main(){
	std::vector<int> result;
	std::vector<std::string> genres = {"classic", "pop", "classic", "classic", "pop"};
	std::vector<int> plays = {500, 600, 150, 800, 2500};

	result = solution(genres, plays);
	for(int i = 0; i < result.size(); ++i){
		 std::cout << result[i] << std::endl;
	}
	return 0;
}
