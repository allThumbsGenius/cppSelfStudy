#include<iostream>
#include<string>

template <class someType>
someType small(someType first, someType second){
	std::cerr << "test print : " << first << " " << second << std::endl;
	return first<second?first:second;
}
//
//std::string small(std::string first, std::string second){
//	std::cerr << "test print : " << first << " " << second << std::endl;
//	return first<second?first:second;
//}

int main(){
	int firstInt, secondInt, chooseType;
	std::string firstString, secondString;
	char firstChar, secondChar;

	std::cout << "type which case do you like? 1. string 2. integer 3. char : ";
	std::cin >> chooseType;
	std::cout << "type your thing which type you chosen : "; 

	switch(chooseType){
		case 1:
			std::cin >> firstString >> secondString;
			std::cout << small(firstString, secondString);
			break;
		case 2:
			std::cin >> firstInt >> secondInt;
			std::cout << small(firstInt, secondInt);
			break;
		case 3:
			std::cin >> firstChar >> secondChar;
			std::cout << small(firstChar, secondChar);
			break;
		default:
			std::cout << "you typed other choice goodbye" << std::endl;
	}
	
	return 0;
}
