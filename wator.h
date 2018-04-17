// wator.h ---
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
#ifndef WATOR_H
#define WATOR_H
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "swimmer.h"
#include <omp.h>

class wator {

public:
    wator(int row, int column,int numberOfFish, int numberOfShark, int changeWorld, int sharkoccurence);

    virtual ~wator(){};

    std::vector<std::vector<int> > getWator2D();
    swimmer** getWator2DObj();
    //swimmer **getWator2DObjects();

    int randomNumber(int changeWorld);
    int fishMoveRandomNumber();
    void createWator(int row,int column, int numberOfFish, int numberOfShark, int changeWorld, int sharkoccurence);
    void setNumberOfShark(int numberOfShark);
    int getNumberOfShark() const;
    void setNumberOfFish(int numberOfFish);
    int getNumberOfFish() const;
    void moveWator();
    void copySwimmer(swimmer* from, swimmer* to, int direction);
    void copySwimerHelper(swimmer* from, swimmer* to);
    void breedHelper(swimmer* from, swimmer* to, int age, int breed, int starve, bool isFish, bool isShark, bool isWator);
    bool fishCanMove(swimmer* to,swimmer* from);
    bool sharkCanMove(swimmer* to,swimmer* from);
    swimmer** create2DArray(unsigned height, unsigned width);
    void copyToSwimmerTwoD();
private:
    /*!
     * \brief variable int row used to the number of rows in the 2D array
     */
    int row;
    /*!
     * \brief variable int column used to the number of columns in the 2D array
     */
    int column;
    /*!
     * \brief variable int numberOfFish used to the max number of numberOfFish in the 2D array
     */
    int numberOfFish;
    /*!
     * \brief variable int numberOfShark used to the max number of numberOfShark in the 2D array
     */
    int numberOfShark;
    /*!
     * \brief variable int changeWorld used to change the ration between swimmer objects (fish, shark, wator)
     */
    int changeWorld;
    /*!
     * \brief variable int sharkoccurence used to control the maximun number of sharks in the 2D array
     */
    int sharkoccurence;
 

    /*!
     * \brief constant variable use to make code more readable and understandable with meaningful text instaed number
     */
	const int ZERO = 0;
    /*!
     * \brief variable use to make code more readable and understandable with meaningful text instaed number
     */
	int ROW_MAX = 99;
    /*!
     * \brief constant variable use to make code more readable and understandable with meaningful text instaed number
     */
	const int ROW_MIN = 0;
    /*!
     * \brief constant variable use to make code more readable and understandable with meaningful text instaed number
     */
	const int LEFT  = 0; 
    /*!
     * \brief constant variable use to make code more readable and understandable with meaningful text instaed number
     */
	const int RIGHT = 1;
    /*!
     * \brief constant variable use to make code more readable and understandable with meaningful text instaed number
     */
	const int UP    = 2;
    /*!
     * \brief constant variable use to make code more readable and understandable with meaningful text instaed number
     */
	const int DOWN  = 3;
    /*!
     * \brief swimmerTwoD is a 2D array to store swimmer objects
     */
      swimmer** swimmerTwoD; 
    /*!
     *
     */
        const int moveOne = 1;


};

#endif /* WATOR_H */

//
// wator.h ends here
