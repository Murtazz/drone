#ifndef __DRONE_H__
#define __DRONE_H__

#include <iostream>

struct Position {
  int ew, ns;
  Position( int ew = 0, int ns = 0 );
};

extern const int MAX_STEPS;

struct Drone {
  enum Direction { NORTH, EAST, SOUTH, WEST };
  Position cur;
  Direction direction; 
  int numSteps;
  Position *steps;
  bool fail;
  
  void switchdir(const int lr);  // to switch directions. More details in drone.cc
  void addPosition(Position *steps, Position *cur, int *numSteps, const int m);  // to move forward or backwards. More details in drone.cc
  Drone();
  ~Drone();
  void forward(); 
  void backward(); 
  void left();
  void right();
  Position current() const;
  int totalDistance() const;
  int manhattanDistance() const;
  bool repeated() const;
};

#endif
