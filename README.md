# Drone

a C++ class for a drone where we control a simple robotic drone exploring some terrain. 

The drone starts at coordinates (0,0), facing north.


forward(): Move the drone one unit forward.

backward(): Moves the drone one unit backward.

left(), right(): Turns the drone 90 degrees to the left or right, while remaining in
the same location.

current(): returns current pos

totalDistance(): Returns the total units of distance travelled by the drone.

manhattanDistance() Returns the ”Manhattan distance” between the current position and the origin where the Manhattan distance defined as the absolute north-south displacement plus the absolute east-west displacement.

bool repeated() Returns true if the current position is one that the drone
has previously visited.
