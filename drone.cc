#include <iostream>
#include "drone.h"

const int MAX_STEPS = 50;

Position::Position( int ew, int ns): ew{ew}, ns{ns} {}

bool operator==(const Position& lhs, const Position& rhs) {  // overloading in order to compare two positions
  return (lhs.ew == rhs.ew && lhs.ns == rhs.ns);
}

Drone::Drone() {  // ctor creates drone facing NORTH with 0 steps
  direction = NORTH;
  numSteps = 0;
}

Drone::~Drone(){};  // dtor

void Drone::switchdir(const int lr) {  // switching direction based on lr (90 degrees left lr == -1 || 90 degrees right if lr == 1). 
  if (direction == NORTH) {  // if on NORTH and lr is -1 then change direction to 3 (i.e. WEST)
    if (lr == -1) {
      direction = Drone::Direction(direction + 3);
    } else {  
      direction = Drone::Direction(direction + lr); 
    }
  } else if (direction == SOUTH) {
    direction = Drone::Direction(direction + lr);
  } else if (direction == EAST) {
    direction = Drone::Direction(direction + lr);
  } else if (direction == WEST) {
    if (lr == 1) {
      direction = Drone::Direction(direction - 3);  // if on WEST and lr is 1 then change direction to 0 (i.e. NORTH)
    } else {
      direction = Drone::Direction(direction + lr);
    }  // in all other cases add lr to direction, convert into Direction, and replace current direction
  }
}

void Drone::addPosition(Position *steps, Position *cur, int *numSteps, const int m) { // adds 1 step forward (if int m is 1) or backwards (if int m is -1)
  steps[*numSteps].ew = cur->ew;  // adds current position to the list of visited steps
  steps[*numSteps].ns = cur->ns;
  if (direction == NORTH) {  // adds m depending on the direction
    cur->ns += m;
  } else if (direction == SOUTH) {
    cur->ns -= m;
  } else if (direction == EAST) {
    cur->ew += m;
  } else if (direction == WEST) {
    cur->ew -= m;
  }
  (*numSteps)++;  // add one to total steps taken
}
  
void Drone::forward() {  // moves forward 1 step adds one to numSteps
  addPosition(steps, &cur, &numSteps, 1);
}
  
void Drone::backward() {  // moves backwards 1 step adds one to numSteps
  addPosition(steps, &cur, &numSteps, -1);
}

void Drone::left() {  // changes direction 90 degrees to the left (e.g. NORTH to WEST)
  switchdir(-1);
}

void Drone::right() {  // changes direction 90 degrees to the right (e.g. NORTH to EAST)
  switchdir(1);
}

Position Drone::current() const {  // displays current position 
  return cur;
}
  
int Drone::totalDistance() const {  // displays the number of steps taken
  return numSteps; 
}
  
int Drone::manhattanDistance() const {  // display the manhattan distance using abs value
  return (abs(cur.ew) + abs(cur.ns)); 
}

bool Drone::repeated() const {  // checks the array of steps visited and compares with the current position
  for (int i = 0; i < numSteps; ++i) {       
    if (cur == steps[i]) {  // using the overloaded "==" operator to compare two positions
      return true;  // returns true if there is a match
    }
  }
  return false;  // false if not
}