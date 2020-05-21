/** program_agent.hpp ---
*
*
* Authors: Misgana <misganayoseph@gmail.com> and Elias Tsegaw<tsegawelias@gmail.com>
* Copyright (c) 2020 misgana96
* This program is free software; you can redistribute it and/or modify
* it under the terms of the  MIT License as
* published by the Free Software Foundation
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* MIT License for more details.
*
* You should have received a copy of the MIT License
* along with this program; if not, write to:
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef WUMPUS_AGENT_HPP_INCLUDED
#define WUMPUS_AGENT_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <array>

using namespace std;

namespace Wumpus
{
namespace wumpus
{
class Agent
{
private:
    World world;
    set<Coordinates>visited();
    map<Coordinates, Percept>knowledgeBase();
    vector<Coordinates>moves();
    array<string, 100> moveList();
    Coordinates currentPosition;
    bool goldCollected = false;
    int runs = 0;
    int maxRuns = 50;
    Coordinates getNextMove(Coordinates playerPosition);
    void findSouthWestTiles(Coordinates playerPosition);
    Coordinates popMove();
    Coordinates backTrack();
    Coordinates locateWumpus();
    void clearStenchPercept();
    Coordinates getUnvisitedSpot(Coordinates basePosition);
    Coordinates confirmDanger(Coordinates playerPosition);
    Coordinates getVisitedAdjacentCell(Coordinates playerPosition);
    bool checkVisited(Coordinates playerPosition);
public:
    Agent(World world);
    void moveAgent();
    void goBackToStart();
    Coordinates getRandomDirection(Coordinates playerPosition);
    void updateMoves(Coordinates newPoint);
    bool checkPreviousPercepts(Coordinates possibleDangerCoordinate, Coordinates checkInitPosition);

};
}
}
#endif