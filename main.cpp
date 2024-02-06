#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <string>
#include <map>
#include <vector>

bool canTravelTo(std::vector<std::vector<bool>>& gameMatrix, int fromRow, int fromColumn, int toRow, int toColumn)
{
    // note: this function is used in the void function boatMovements()

    // my thought process:

    // if abs(toRow - fromRow) == 2:
    // then check if those toRow is true
    // else:
    // if abs(toCol - fromCol) == 1:
    // then check if the toCol is true or not
    // else:
    // return 0

    // for the test: https://www.testdome.com/tests/cpp-online-test/34

    int verticalDistance = toRow - fromRow;
    int horizontalDistance = toColumn - fromColumn;

    // case 1: the destination is two spaces up or down
    if ((abs(verticalDistance) == 2) && (abs(horizontalDistance) == 0)){

        // if both spaces are water
        if (gameMatrix[toRow][toColumn] && gameMatrix[toRow + (verticalDistance < 0 ? 1 : -1)][toColumn])
            return true;
        return false;
    }
    // case 2: the destination is one space left or right
    else if(verticalDistance == 0 && abs(horizontalDistance) == 1){

        // if both spaces are water
        if (gameMatrix[toRow][toColumn])
            return true;

        return false;

    }
    // case 3: any other combinations are not legal in ONE step, so return false
    return false;

}

void boatMovements(){
    std::vector<std::vector<bool>> gameMatrix {
            {false, false, true, true, false},
            {false, false, true, false, false},
            {false, false, true, true, false},
            {false, true, false, true, false},
            {false, false, true, false, false}
    };

    std::cout << canTravelTo(gameMatrix, 2, 2, 0, 2) << std::endl;
    std::cout << canTravelTo(gameMatrix, 2, 2, 2, 1) << std::endl;
    std::cout << canTravelTo(gameMatrix, 2, 2, 2, 3) << std::endl;
    std::cout << canTravelTo(gameMatrix, 2, 2, 4, 2) << std::endl;

}

std::pair<double, double> findRoots(double a, double b, double c)
{
    // code here
    double sqrtPart = std::sqrt(((std::pow(b, 2)) - (4 * (a * c))));
    std::pair<double, double> roots;
    roots.first = ((-b) + sqrtPart) / (2 * a);
    roots.second = ((-b) - sqrtPart) / (2 * a);

    return roots;
}

void quadraticEquation(){
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}

// 1. Two Sum challenge on LeetCode, using a one-pass hash table
std::vector<int> twoSum(std::vector<int>& nums, int target) {

    std::map<int, int> map {};


    for (int i = 0; i < nums.size(); ++i) {

        int complement = target - nums[i]; // ex. 9 - 2 = 7;
        // if we already added the complement, return
        if(map.contains(complement) && map[complement] != i){
            return {i, map[complement]};
        }
        // if not, then add it
        // key: each elements value; value: element's index
        map.insert({nums[i], i});

    }

    // in case there is no solution
    return {-1};


}

int main()
{
    // for this challenge: https://www.testdome.com/tests/cpp-online-test/34
    boatMovements();

    // for this challenge: https://www.testdome.com/questions/cpp/quadratic-equation/84852
    quadraticEquation();
    






}