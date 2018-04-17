// swimmer.h --- 
// 
// Filename: swimmer.h
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

#ifndef SWIMMER_H
#define SWIMMER_H

class swimmer {
public:
    swimmer();
    swimmer(int l_age, int l_breedTime, int l_starving, bool l_wator, bool l_fish, bool l_shark):age(l_age),breedTime(l_breedTime), starve(l_starving), wator(l_wator), hasFish(l_fish), hasShark(l_shark){};

    virtual ~swimmer();
    void SetWator(bool wator);
    bool IsWator() const;
    void SetBreedTime(int breedTime);
    int GetBreedTime() const;
    void SetAge(int age);
    int GetAge() const;
    void SetHasShark(bool hasShark);
    bool IsHasShark() const;
    void SetHasFish(bool hasFish);
    bool IsHasFish() const;
    void starving();
    void breed();
    void SetStarve(int starve);
    int GetStarve() const;
    void makeWator(swimmer* swimerFish);
    void copySwimmer(swimmer* from);
    
protected:
    /*!
     * \brief variable int age is used to determine the age of the swimmer object (fish, shark) 
     */
    int age;
    /*!
     * \brief variable int creedTime is used to check the breading time to the swimmer object (fish, shark) 
     */
    int breedTime;
    /*!
     * \brief variable int starve is used to check the starvation time of the swimmer object (fish, shark) 
     */
    int starve;
    /*!
     * \brief variable boolean wator is used to determine the type of the swimmer object (fish, shark, wator)
     */
    bool wator;
    /*!
     * \brief variable boolean hasFish is used to determine the type of the swimmer object (fish, shark, wator)
     */
    bool hasFish;
    /*!
     * \brief variable boolean hasShark is used to determine the type of the swimmer object (fish, shark, wator)
     */
    bool hasShark;

};

#endif /* SWIMMER_H */

