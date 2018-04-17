// swimmer.cpp --- 
// 
// Filename: swimmer.cpp
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

#include "swimmer.h"
/*!
 * \brief Description of constructor
 * Default swimmer constructor
 */
swimmer::swimmer() {
}

/*!
 * \brief Description of de-constructor
 * Default swimmer de-constructor
 */
swimmer::~swimmer() {
}

/*!
 * \brief Description of the void makeWator function
 * Receiving a swimmer pointer and sets the values to default for wator representation
 */
void swimmer::makeWator(swimmer* swimerFish){
    swimerFish->SetAge(0);
    swimerFish->SetBreedTime(0);
    swimerFish->SetHasFish(false);
    swimerFish->SetHasShark(false);
    swimerFish->SetStarve(0);
    swimerFish->SetWator(true);
}

/*!
 * \brief Description of the void copySwimmer function
 * Receiving a swimmer pointer and copies the object values to the new object position in the array
 */
void swimmer::copySwimmer(swimmer* from){
    this->SetAge(from->GetAge());
    this->SetBreedTime(from->GetBreedTime());
    this->SetStarve(from->GetStarve());
    this->SetHasFish(from->IsHasFish());
    this->SetHasShark(from->IsHasShark());
    this->SetWator(from->IsWator());
}
/*!
 * \brief SetWator is a setter for wator variable
 */
void swimmer::SetWator(bool wator) {
    this->wator = wator;
}
/*!
 * \brief IsWator is a getter for wator variable
 */
bool swimmer::IsWator() const {
    return wator;
}
/*!
 * \brief SetBreedTime is a setter for breedTime variable
 */
void swimmer::SetBreedTime(int breedTime) {
    this->breedTime = breedTime;
}
/*!
 * \brief GetBreedTime is a getter for breedTime variable
 */
int swimmer::GetBreedTime() const {
    return breedTime;
}
/*!
 * \brief SetAge is a setter for age variable
 */
void swimmer::SetAge(int age) {
    this->age = age;
}
/*!
 * \brief GetAge is a getter for agr variable
 */
int swimmer::GetAge() const {
    return age;
}
/*!
 * \brief SetHasShark is a setter for hasShark variable
 */
void swimmer::SetHasShark(bool hasShark) {
    this->hasShark = hasShark;
}
/*!
 * \brief IsHasShark is a getter for hasShark variable
 */
bool swimmer::IsHasShark() const {
    return hasShark;
}
/*!
 * \brief SetHasFish is a setter for hasFish variable
 */
void swimmer::SetHasFish(bool hasFish) {
    this->hasFish = hasFish;
}
/*!
 * \brief IsHasFish is a getter for hasFish variable
 */
bool swimmer::IsHasFish() const {
    return hasFish;
}
/*!
 * \brief breed is a setter for breedTime variable
 */
void swimmer::breed(){
    this->breedTime = this->breedTime + 1;
}
/*!
 * \brief starving is increasing the starve variable 
 */
void swimmer::starving(){
    this->starve = this->starve + 1;
}
/*!
 * \brief SetStarve is a setter for starve variable 
 */
void swimmer::SetStarve(int starve) {
    this->starve = starve;
}
/*!
 * \brief GetStarve is a getter for starve variable 
 */
int swimmer::GetStarve() const {
    return starve;
}
