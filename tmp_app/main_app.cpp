#include <iostream>
#include <vector>
#include <unordered_map>


void add_entity(std::vector<std::string> &players, std::string &player){
    players.push_back(player);
    std::cout << "Player added to the database \n";
}

void PrintPlayerLength(const std::string &player){
    std::cout << player.length() << '\n';
}

void InstertIntoMap(
    std::string region_name,
    std::unordered_map<std::string, std::vector<std::string>> &map,
    std::vector<std::string> &players
){
    map.insert(std::pair<std::string, std::vector<std::string>>(region_name, players));
}


int main(){
    std::unordered_map<std::string, std::vector<std::string>> map{};


    std::string player1{"MyPlayer1"};
    std::string player2{"MyPlayer22"};
    std::string player3{"MyPlayer4543"};

    std::vector<std::string> europe_players{};

    add_entity(europe_players, player1);
    add_entity(europe_players, player2);
    add_entity(europe_players, player3);

    std::cout << "----------------------------------\n";

    for(const std::string &player: europe_players){
        PrintPlayerLength(player);
    }

    std::cout << "----------------------------------\n";

    std::string player4{"MyPlayer123"};
    std::string player5{"MyPlayer34543"};
    std::string player6{"MyPlayer1236"};

    std::vector<std::string> asian_players{};

    add_entity(asian_players, player4);
    add_entity(asian_players, player5);
    add_entity(asian_players, player6);

    InstertIntoMap("Europe", map, europe_players);
    InstertIntoMap("Asia", map, asian_players);

    for(auto &region: map){
        std::cout << region.first << '\n';
        std::cout << "------------\n";
        for(auto &p: region.second){
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}