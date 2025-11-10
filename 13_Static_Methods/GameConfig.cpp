#include <iostream>

// Enumeration (enum)
enum Difficulty {Easy, Normal, Hard};

class GameConfig {
public:

    GameConfig() : playerDifficulty(defaultDifficulty) {}

    static int getDefaultDifficulty(){
       return defaultDifficulty;
    }
     int getPlayerDifficulty(){
       return playerDifficulty;
    }

    static void setDefaultDifficulty(int level) {
        if (level >= Easy && level <= Hard){
            defaultDifficulty = level;
        }
    }

    static std::string difficultyToString(int level){
        switch(level) {
            case 0: return "Easy";
            case 1: return "Normal";
            case 2: return "Hard";
            default: return "Unknown";
        }
    }

private:
    static int defaultDifficulty;
    int playerDifficulty;


};

int GameConfig::defaultDifficulty = Normal;

int main(void) {
    Difficulty d = Easy;

    

    std::cout << d << std::endl;
    std::cout << "Default difficulty is " << GameConfig::difficultyToString(GameConfig::getDefaultDifficulty()) << std::endl;

    GameConfig player;
    std::cout << GameConfig::difficultyToString(player.getPlayerDifficulty()) << std::endl;
    return 0;
}