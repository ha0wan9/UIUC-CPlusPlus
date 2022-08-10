/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // Prints out the state of the game:
  cout << *this << endl
  // @TODO -- Finish solving the game!
  int height = stacks_[0].size();
  while (stacks_[2].size() < height){
    for (int i = 1; i < 3; i++){
      if ((stacks_[i].size() == 0 && stacks_[i-1].size() != 0)||
        (stacks_[i].peekTop() > stacks_[i-1].peekTop())) {
        stacks_[i].push_back(stacks_[i-1].peekTop()); 
        stacks_[i-1].removeTop();
      } else if ((stacks_[i].size() != 0 && stacks_[i-1].size() == 0) || 
                (stacks_[i].peekTop() < stacks_[i-1].peekTop())) {
        stacks_[i-1].push_back(stacks_[i].peekTop()); 
        stacks_[i].removeTop();
      }
    }
  }
}
}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
