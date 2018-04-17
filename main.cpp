// main.cpp ---
//
// Filename: main.cpp
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

/*!
 * \author Zoltan Fuzesi / James Kiernan
 * \version 1.0
 * \date 13/11/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Wator - Simulator
 * \section name_sec Software Engineering
 * ConDev - Joseph Kehoe
 * \subsection Wator - Simulator Description
 * The wator - simulator ....<br>
 * Compile and run:
 * 1. open terminal
 * 2. navigate to the folder where wator simulator downloaded
 * 3. Type in : make - and it will compile and run the program<br>
 * The Makefile runs the Doxygen to generate the documentation when the project build
 *
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include "wator.h"
#include <omp.h>


/*
 * Set fish size to fit  to the window
 */
/*!
 * \brief Description of create2DArray function
 *  The function is receiving the height and the witdht of the 2D array
 *  and creates the 2D array to swimmer object
 */
swimmer** create2DArray(unsigned height, unsigned width) {
    swimmer** swimmerTwoD = 0;
    swimmerTwoD = new swimmer*[height];

    for (int h = 0; h < height; h++) {
        swimmerTwoD[h] = new swimmer[width];

        for (int w = 0; w < width; w++) {
            // fill in some initial values
            // (filling in zeros would be more logic, but this is just for the example)
            swimmerTwoD[h][w] = swimmer(0, 0, 0, true, false, false);
        }
    }
    return swimmerTwoD;
}

/*!
 * \brief Description of main function
 *  The main function is running the SFML loop to display the wator simulator
 */
int main() {


    /*
     * Change fish and shark max values obviously!!!!
     */
    const int numberOfFish = 100000;
    const int numberOfShark = 100000;
    /*
     * Change for Wator/swimmer(fish & shark) ratio!!!!
     */
    const int changeWorld = 5;
    const int sharkoccurence = 6;
    /*
     * Change screen size!!!!
     */
    const int ROW = 600;
    /*
     * CHANGE FOR WATOR SIZE!!!
     * SIZE 200 IS 200 * 200 = 40000 
     * TEST VALUES ARE 100 , 120 , 150 , 200
     * SOME VALUE CAUSING SEGMENTATION FAULT !!!!!!
     */

    int SIZE = 100;
    std::cout << "ENTER THE SIZE OF THE WATOR ? (EG: 100,120,150,200): " << std::endl;
    std::cin >> SIZE ;
    
    /*
     * DO NOT CHANGE !!!!
     */
    const int COLUMN = ROW;
    
    const int PER_ROW = ROW / SIZE;
    const int PER_COLUMN = COLUMN / SIZE;
    std::shared_ptr<wator>wObj(new wator(ROW / PER_ROW, COLUMN / PER_COLUMN, numberOfFish, numberOfShark, changeWorld, sharkoccurence));
    swimmer** swimmerTwoD = create2DArray(ROW / PER_ROW, COLUMN / PER_COLUMN);
   
    int fishSize = 5;
    
    if(SIZE<=100)
    {
        fishSize = 5;
    }
    else if(SIZE>100)
    {
       fishSize = 3; 
    }
//    else if(ROW<=500)
//    {
//        fishSize = 2; 
//    }
//    else if(ROW<=800)
//    {
//        fishSize = 5; 
//    }
//    else if(ROW<=100)
//    {
//        fishSize = 8; 
//    }
    sf::RectangleShape shark;
    shark.setFillColor(sf::Color(sf::Color::Black));
    shark.setSize(sf::Vector2f(fishSize, fishSize));
    /*
     * Fish shape. Lower number is smaller shape
     */
    sf::RectangleShape fish;
    fish.setFillColor(sf::Color(sf::Color::White));
    fish.setSize(sf::Vector2f(fishSize, fishSize));

    /*
     * SFML engine vector array to store and represent Swimmer shapes
     */
    std::vector<std::vector < sf::RectangleShape>> SFML_Vector;
    /*
     * set wator size to ROW(800) * COLUMN(800) & all position = fish (swimmer)
     */
    SFML_Vector.resize(ROW / PER_ROW, std::vector<sf::RectangleShape>(COLUMN / PER_COLUMN, fish));
    /*
     * create Window
     */

    sf::RenderWindow window(sf::VideoMode(ROW, COLUMN), "C++ Wator Simulation");
   
    /*
     * set timepeFrame to 1 60th of a second. 60 frames per second
     */
    sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    /*
     * the clock object keeps the time.
     */
    int testCounter = 0;
    sf::Clock clock;
    clock.restart();
    
    /*
     * TIme test
     */
    sf::Clock testClock;
    testClock.restart();

    while (window.isOpen()) {


        /*
         * check if the close window button is clicked on.
         */
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        /*
         *  Wator (Window) for testing !!!!
         */
        if (testCounter == 1000) {
            window.close();
            sf::Time testTime = testClock.getElapsedTime();
            std::cout << "TIME is : " << testTime.asSeconds() << std::endl;
            // clock_t fStart = clock();
           // std::cout << "Time taken " << ((fStart - tStart)/CLOCKS_PER_SEC) << std::endl;
            //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        /*
         * get the time since last update and restart the clock
         */
        timeSinceLastUpdate += clock.restart();
        /*
         * update every 60th of a second
         * only when the time since last update is greate than 1/60 update the world.
         */
        if (timeSinceLastUpdate > timePerFrame) {
            /*
             * clear the screen and draw all the shapes
             */
           // window.clear();
            window.clear(sf::Color::Blue);
            /*
             * get the Wator array from game logic
             */
            swimmerTwoD = wObj->getWator2DObj();
            /*
             * Sample to draw Wator 2D_Array
             */
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < ROW; ++i) {
                //std::cout << "Number of threads in main" << omp_get_num_threads() << std::endl;

                for (int y = 0; y < COLUMN; ++y) {
                    //std::cout << "Number of threads in main" << omp_get_num_threads() << std::endl;
                    if (i % PER_ROW == 0 && y % PER_COLUMN == 0) {
                        /*
                         * Shark
                         */
                        #pragma omp critical(swimmerTwoD)

                        if (swimmerTwoD[i / PER_ROW][y / PER_COLUMN].IsHasShark()) {
                            SFML_Vector[i / PER_ROW][y / PER_COLUMN] = shark;
                            SFML_Vector[i / PER_ROW][y / PER_COLUMN].setPosition(sf::Vector2f(i, y));
                            window.draw(SFML_Vector[i / PER_ROW][y / PER_COLUMN]);
                        }                            /*
                                     * Fish
                                     */
                        else if (swimmerTwoD[i / PER_ROW][y / PER_COLUMN].IsHasFish()) {
                            SFML_Vector[i / PER_ROW][y / PER_COLUMN] = fish;
                            SFML_Vector[i / PER_ROW][y / PER_COLUMN].setPosition(sf::Vector2f(i, y));
                            window.draw(SFML_Vector[i / PER_ROW][y / PER_COLUMN]);
                        }                            /*
                                      * Is wator
                                      */
                        else {
                            SFML_Vector[i / PER_ROW][y / PER_COLUMN].setPosition(sf::Vector2f(-30, -30));
                        }
                    


                       // window.draw(SFML_Vector[i / PER_ROW][y / PER_COLUMN]);

                    }
                }
            }
             
            window.display();
            testCounter += 1;
            /*
             *  reset the timeSinceLastUpdate to 0
             */
            timeSinceLastUpdate = sf::Time::Zero;
        }
    }

    return 0;

}

//
// main.cpp ends here
