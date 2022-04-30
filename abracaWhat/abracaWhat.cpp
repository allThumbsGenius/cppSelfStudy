#include<iostream>
#include<unordered_map>

#define STONE_COUNT_MAX 36

class Stone{
	int spellNumber;
	bool stoneUsedCheck;
	const std::unordered_map<int, std::string> spellName; 

	public:
		Stone() : spellName(
			{	
				{1, "★Red Dargon Fist★"},
				{2, "Vagabond of Darkness"},
				{3, "Exciting Wind"},
				{4, "Owl Owl teleparty"},
				{5, "Lightning Storm"},
				{6, "Blizzard"},
				{7, "Fire Ball"},
				{8, "Magic Potion"}
			}
		)
		{
		}

		int getSpellNumber(){
			return spellNumber;
		}
		void setSpellNumber(int spellNumber){
			this->spellNumber = spellNumber;
		}

		bool getStoneUsedCheck(){
			return stoneUsedCheck;
		}
		void setStoneUsedCheck(bool stoneUsedCheck){
			this->stoneUsedCheck = stoneUsedCheck;
		}

		std::unordered_map<int, std::string> const getSpellName(){
			return spellName;
		}
};

class Players{
	Stone indivisualStone[5];
	int score;
	int life;
	std::vector<int> owlOwlTelepartyNumber;
	
	public:
		int getLife(){
			return life;
		}

		int getScroe(){
			return score;
		}
		
		void setLife(int life){
			this->life = life;
		}

		void setScore(int score){
			this->score = score;
		}

		void setOwlOwlTelepartyNumber(int spellNumber){
			this->owlOwlTelepartyNumber.push_back(spellNumber);
		}

};

class Game{
	const bool STONE_NOT_USED;
	const bool STONE_USED;

	int countOfPlayers;
	Players *players; 
	Stone magicStone[STONE_COUNT_MAX]; 
	
	public:
		Game() : 
			STONE_NOT_USED(false), 
			STONE_USED(true)
		{
		}
		
		void gameStart(){
			getInputCountOfPlayers();
			setCountOfPlayers();
			gameInitialize();
			roundStart();
		}

		void getInputCountOfPlayers(){
			std::cout << "How many players do you want to set? : ";
			std::cin >> countOfPlayers;
		}

		void setCountOfPlayers(){
			players = new Players[countOfPlayers];
		}
		
		void gameInitialize(){
			const int BASIC_SCORE = 1;
			for(int i = 0; i < countOfPlayers; ++i){
				players[i].setScore(BASIC_SCORE);
			}
		}
		
		void roundStart(){
			roundInitialize();
			divideStone();
			//need to make more on here
		}
		
		void roundInitialize(){
			const int BASIC_LIFE = 6;
			for(int i = 0; i < countOfPlayers; ++i){
				players[i].setLife(BASIC_LIFE);
			}
			stoneInitialize();
		}

		void stoneInitialize(){
			const int MAX_SPELL_NUMBER = 8;
			for(int spellNumberMinusOne = 0, stoneCount = 0; spellNumberMinusOne < MAX_SPELL_NUMBER; ++spellNumberMinusOne){
				for(int j = 0; j <= spellNumberMinusOne; ++j, ++stoneCount){
					magicStone[stoneCount].setSpellNumber(spellNumberMinusOne + 1);
					magicStone[stoneCount].setStoneUsedCheck(STONE_NOT_USED);
				}
			}
		}

		void divideStone(){
			//need to make more on here

		void const gameTest(){
			std::unordered_map<int, std::string> magicStoneSpellNameHash = magicStone[0].getSpellName();
			for(int i = 0; i < STONE_COUNT_MAX; ++i){
				int spellNumber = magicStone[i].getSpellNumber();
				std::string magicStoneSepllName = magicStoneSpellNameHash.at(spellNumber);
				
				std::cout << i << " : " << magicStoneSepllName << std::endl;
			}
		}

};

int main(){
	Game *game = new Game();
	game->gameStart();
	return 0;
}
