// wator.cpp ---
//
// Filename: wator.cpp
// Description:
// Author: James Kiernan / Zoltan Fuzesi
// Maintainer:
// LICENSE :  GPLv3
// Created: Wed Nov  8 13:47:07 2017 (+0000)
// Version:
// Package-Requires: ()
// Last-Updated:
//           By:
//     Update #: 0
// URL:
// Doc URL:
// Keywords:
// Compatibility:
//
//

// Commentary:
//
//
//
//

// Change Log:
//
//
//
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
//
//

// Code:
#include <omp.h>
#include "wator.h"
#include <iostream>



/*!
 * \brief Description of the void createWator function
 * \param row is an int variable to control watorTwoD row size
 * \param column is an int variable to control watorTwoD column size
 * \param numberOfFish is an int variable to control max number of sharks
 * \param numberOfShark is an int variable to control max number of sharks
 * \param changeWorld is an int variable to change Wator/swimmer(fish & shark) ratio
 * \param sharkoccurence is an int variable to control the occurance of sharks
 * \param watorTwoD is an vector of int variables to create the representation of the word
 * \param swimmerTwoD in an 2D array of swimmers to store objects
 * \details The createWator function used when the application starts to create random word
 */
wator::wator(int row, int column,int numberOfFish, int numberOfShark, int changeWorld, int sharkoccurence) {
    this->row = row;
    this->column = column;
    this->changeWorld = changeWorld;
    this->sharkoccurence = sharkoccurence;
    /*
     * Initialize wator 2D vector to row * column scale to the screen size
     */
    this->ROW_MAX = row - 1;
    swimmerTwoD = create2DArray(row,column);

    /*
     * Create wator when main class call the wator constructor
     */
    createWator(row, column, numberOfFish,numberOfShark, changeWorld, sharkoccurence);

}

/*!
 * \brief Description of the void create2DArray function
 * \param height is an int variable to control swimmerTwoD row size
 * \param width is an int variable to control swimmerTwoD column size
 * \param swimmerTwoD is a 2D array to store the swimmer objects
 * \details The create2DArray function used to build up the swimmerTwoD array and fill with wator empty objects
 */
swimmer** wator::create2DArray(unsigned height, unsigned width)
{
    std::cout << "SIZE IS " << height << " * " << width << std::endl;
     swimmer** swimmerTwoD = 0;
     swimmerTwoD = new swimmer*[height];

     for (int h = 0; h < height; h++)
     {
          swimmerTwoD[h] = new swimmer[width];

          for (int w = 0; w < width; w++)
          {
               // fill in some initial values
               // (filling in zeros would be more logic, but this is just for the example)
               swimmerTwoD[h][w] = swimmer(ZERO,ZERO,ZERO,true,false,false);
          }
     }

     return swimmerTwoD;
}
/*!
 * \brief Description of the void createWator function
 * \param breed local int variable to assign random value to swimmer object at creation
 * \param starve local int variable to assign random value to swimmer object at creation
 * \param age local int variable to assign random value to swimmer object at creation
 * \param fishType local int variable to assign random value to swimmer object at creation
 * \details The createWator function used when the application starts to create random word
 */
void wator::createWator(int row, int column, int numberOfFish, int numberOfShark, int changeWorld, int sharkoccurence){
    int fishType=0;
    /*
     * Need for random Age, Starvation, breeding time for fish and shark
     */
    int breed, age, starve = ZERO;
    for(int i=0;i<row;++i)
    {
        for(int y=0; y<row; ++y)
        {
            fishType = randomNumber(changeWorld);
            breed =  rand() % 15;
            age =  rand() % 25;
            starve =  rand() % 40;
            /*
             * if fistype 1 or 3 and numberOfFish > 0 create a fish
             */
            if((fishType== 1 || fishType== 3) && numberOfFish > 0){
                swimmerTwoD[i][y] = swimmer(age,breed,starve,false,true,false);
                --numberOfFish;
            }
            /*
             * if fishtype 2 & numberOfShark > 0 and column%sharkoccurance create a shark
             */
            else if(fishType== 2 && numberOfShark > ZERO && y%sharkoccurence == ZERO){
                swimmerTwoD[i][y] = swimmer(age,breed,starve,false,false,true);
                --numberOfShark;
            }
            /*
             * if fistype not 1,2,3 create a empty space
             */
            else{
                swimmerTwoD[i][y] = swimmer(ZERO,ZERO,ZERO,true,false,false);
            }
        }
    }
}

/*!
 * \brief sharkCanMove receiving two pointer of from position and to position
 * \if to position is empty return true
 * \if to position is has fish set starve time to zero and return true
 * \if to position has shark increase starve time and return false
 */
bool wator::sharkCanMove(swimmer* to,swimmer* from){
    /*
     * stay starve++
     */
    if(to->IsHasShark()){
        from->starving();
        from->breed();
        return false;
    }
    /*
     * move starve ++
     */
    if(to->IsWator()){
        from->starving();
        from->breed();
        return true;
    }
     /*
      * eat fish starve Zero
      */
    if(to->IsHasFish()){
        from->SetStarve(ZERO);
        from->breed();
        return true;
    }
    return true;
}
/*!
 * \brief copySwimerHelper copies the swimmer object 'from' position 'to' position
*/
void wator::copySwimerHelper(swimmer* from, swimmer* to){
    to->SetWator(from->IsWator());
    to->SetHasFish(from->IsHasFish());
    to->SetHasShark(from->IsHasShark());
    to->SetAge(from->GetAge());
    to->SetBreedTime(from->GetBreedTime());
    to->SetStarve(from->GetStarve());
}

/*!
 * \brief breedHelper copies the swimmer object 'from' position 'to' position, and leave new swimmer at 'from' position
*/
void wator::breedHelper(swimmer* from, swimmer* to, int age, int breed, int starve, bool isFish, bool isShark, bool isWator){
    from->SetAge(age);
    from->SetBreedTime(breed);
    to->SetBreedTime(breed);
    from->SetStarve(starve);
    from->SetHasFish(isFish);
    from->SetHasShark(isShark);
    from->SetWator(isWator);
}
/*!
 * \brief copySwimmer receiving two pointer of from position and to position and the direction to move(direction is for future function)
 * \if from position empty then not doing anything
 * \if from position fish, checking the target position and if empty then move to the position
 * \if NOT empty stay in the same position
 * \if from position is shark, then check the to position, if to position shark then stay an increase starve
 * \if to position fish, then move set starve to Zero
 * \booth fish and shark at every cycle increase the breed time
 * \if swimmer (fish, shark) breedTime equals or bigger the breed time then from position create new swimmer
 */
void wator::copySwimmer(swimmer* from, swimmer* to, int direction) {
    if(from->IsWator()){
        /*
         * If wator not fish/shark, Do nothing
         */
    }else{
        /*
         * if the swimmer object is fish
         */
        if(from->IsHasFish()){
            if(fishCanMove(to,from)){
                /*
                 * copy fish to new position, leave wator at old position
                 */
                copySwimerHelper(from, to);
                if(from->GetBreedTime()>30){
                    /*
                     * copy fish to new position, leave new fish at old position
                     */
                    breedHelper(from, to, ZERO, ZERO, ZERO, true, false, false);
                }
                /*
                     * Fish old position set to wator
                     * Fish dies only if Shark eat it, shark logic control
                     */
                else {
                    from->makeWator(from);
                }

            }
        }            /*
        * If the object is shark
        */
        else if (from->IsHasShark()) {
            if (sharkCanMove(to, from)) {
                if (from->GetStarve() <= 40) {
                    /*
                     * copy shark to new position, leave wator at old position
                     */
                    copySwimerHelper(from, to);
                    if (from->GetBreedTime() >= 51) {
                        /*
                         * copy shark to new position, leave new shark at old position
                         */
                        breedHelper(from, to, ZERO, ZERO, ZERO, false, true, false);
                    }                        /*
                     * Shark old position set to wator
                     */
                    else {
                        from->makeWator(from);
                    }
                }                    /*
                * If shark dies
                */
                else {
                    from->makeWator(from);
                }

            }
        }
    }
}

/*!
 * \brief moveWator function looping through the swimmerTwoD 2D array to change swimmer position
 */
void wator::moveWator() {

    //std::cout << "Openmp max threads " << omp_get_max_threads() << std::endl;
    #pragma omp parallel for num_threads(4) 
    for (int i = 0; i < row; ++i) {
        //std::cout << "Number of threads in moveWator" << omp_get_num_threads() << std::endl;
        for (int y = 0; y < column; ++y) {

            int randMove = fishMoveRandomNumber();
            /*
             * Move LEFT
             */
            #pragma omp critical(swimmerTwoD)
            {
                if (randMove == LEFT) {
                    if (i == ZERO) {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[ROW_MAX][y], ROW_MIN);
                    } else {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[i - moveOne][y], ROW_MIN);
                    }
                }
                /*
                 * Move RIGHT
                 */
                else if (randMove == RIGHT) {
                    if (i == ROW_MAX) {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[ROW_MIN][y], 1);
                    } else {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[i + moveOne][y], 1);
                    }
                }
                /*
                 * Move UP
                 */
                else if (randMove == UP) {
                    if (y == ZERO) {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[i][ROW_MAX], 1);
                    } else {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[i][y - moveOne], 1);
                    }
                } 
                /*
                 * Move DOWN
                 */
                else if (randMove == DOWN) {
                    if (y == ROW_MAX) {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[i][ROW_MIN], 1);
                    } else {
                        copySwimmer(&swimmerTwoD[i][y], &swimmerTwoD[i][y + moveOne], 1);
                    }
                }
            }

        }
    }
}

/*!
 * \brief getWator2DObj return a 2D array to the main SFML loop to display it
 * The moveWator() function call makes the movement of the swimmwer objects in the 2D array 
 */
swimmer** wator::getWator2DObj()
{
  moveWator();
  return swimmerTwoD;
}

/*!
 * \brief fishMoveRandomNumber return a value between 0 and 5, movements are 0-3 0->up 1->right 2->down 3->left
 */
int wator::fishMoveRandomNumber(){
    return  rand() % 5;
}

/*!
 * \brief fishCanMove receiving two pointer of from position and to position
 * \if to position is empty return true otherwise return false
 */
bool wator::fishCanMove(swimmer* to,swimmer* from){
    if(to->IsHasFish() || to->IsHasShark())
        return false;
    from->breed();
    return true;
}

/*!
 * \brief randomNumber function Return a random number between 0 and up to changeWorld-1 value
 */
int wator::randomNumber(int changeWorld){
    return  rand() % changeWorld;
}

/*!
 * \brief setNumberOfShark is a setter for numberOfShark
 */
void wator::setNumberOfShark(int numberOfShark) {
    this->numberOfShark = numberOfShark;
}

/*!
 * \brief setNumberOfShark is a getter for numberOfShark
 */
int wator::getNumberOfShark() const {
    return numberOfShark;
}

/*!
 * \brief setNumberOfFish is a setter for numberOfFish
 */
void wator::setNumberOfFish(int numberOfFish) {
    this->numberOfFish = numberOfFish;
}

/*!
 * \brief getNumberOfFish is a getter for numberOfFish
 */
int wator::getNumberOfFish() const {
    return numberOfFish;
}

//
// wator.cpp ends here
