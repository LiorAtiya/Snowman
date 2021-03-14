#include <cstring>
#include <iostream>
#include "snowman.hpp"
#include <array>
using namespace std;

namespace ariel
{
    string snowman(int input)
    {
        const std::array<string,4> hat {"_===_"," ___\n.....","  _\n /_\\"," ___\n(_*_)"};
        const std::array<string,4> nose {",",".","_"," "};
        const std::array<string,4> eye {".","o","O","-"};
        const std::array<string,4> leftArm {"<","\\","/",""};
        const std::array<string,4> rightArm {">","/","\\",""};
        const std::array<string,4> torso {" : ","] [","> <","   "};
        const std::array<string,4> base {" : ","\" \"","___","   "};

        string number = to_string(input);
        string snowman;
        //Checks the correctness of the string length
        const int validLength = 8;
        if (number.length() != validLength)
        {
            throw invalid_argument("Invalid code '" + number + "'");
        }

        //Checks the correctness of each character in the string
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] < '1' || number[i] > '4')
            {
                throw invalid_argument("Invalid code '" + number + "'");
            }
        }

        const int H = 0; //Hat
        const int N = 1; //Nose
        const int L = 2; //Left eye
        const int R = 3; //Right eye
        const int X = 4; //Left arm
        const int Y = 5; //Right arm
        const int T = 6; //Torso
        const int B = 7; //Base
        const int a = 49; //for convert char to int

        //Checks if the snowman with left arm
        if (number[X] != '4')
        {
            snowman += " " + hat.at(number[H] - a) + "\n";
            const int six = 6;
            const int five = 5;
            if (number[H] == '4' || number[H] == '2')
            {
                snowman.insert(six, " ");
            }
            else if (number[H] == '3')
            {
                snowman.insert(five, " ");
            }
        }
        else
        {
            snowman += hat.at(number[H] - a) + "\n";
        }

        //Head
        if (number[X] == '2') //If left hand up
        {
            snowman += '\\';
        }
        else if (number[X] != '4') //If have left arm
        {
            snowman += " ";
        }
        snowman += "(" + eye.at(number[L] - a) + nose.at(number[N] - a) + eye.at(number[R] - a) + ")";
        if (number[Y] == '2') //If right hand up
        {
            snowman += '/';
        }
        snowman += '\n';

        //Chest
        if (number[X] == '2') //If left hand up = put space in the chest
        {
            snowman += " ";
        }
        else
        {
            snowman += leftArm.at(number[X] - a);
        }
        snowman += "(" + torso.at(number[T] - a) + ")";
        if (number[Y] != '2') //If the right hand is not up = put by number[Y]
        {
            snowman += rightArm.at(number[Y] - a);
        }
        snowman += '\n';

        //Bottom part
        if (number[X] != '4') //If there is a left arm
        {
            snowman += " ";
        }
        snowman += "(" + base.at(number[B] - a) + ")";

        return snowman;
    }
};