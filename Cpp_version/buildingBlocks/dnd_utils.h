//
// Created by Vanhuljo on 22/11/2023.
//

#ifndef OOP_LEARNING_DND_UTILS_H
#define OOP_LEARNING_DND_UTILS_H

#include "iostream"
using namespace std;

/*
 * DEFAULT_CONSTRUCTORS:
 *
 * @filereader() = default;
 * @player() =  default
 * */

#define DEFAULT_ROUND 1;
#define WINDOW_WIDTH 1500;
#define WINDOW_HEIGHT 900;
#define NULL_PAR 0;

int persons, playingRounds;

void setPlayers(int people) { persons = people; }

void setRounds(int roundsToPlay) { playingRounds = roundsToPlay; }

int getPlayers() { return persons; }

int getRounds() { return playingRounds; }

void gameInit() {
  cout << "Enter the size of your group and the rounds you want to play:"
       << endl;
  cout << "Size of your group:";
  cin >> persons;
  cout << endl;
  cout << "Rounds to play:";
  cin >> playingRounds;

  setPlayers(persons);
  setRounds(playingRounds);

  getPlayers();
  getRounds();
}

#endif  // OOP_LEARNING_DND_UTILS_H
