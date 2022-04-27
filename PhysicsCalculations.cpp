/*************************************************************
 * 1. Name:
 *      Austin Eldredge
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#include <iostream>  // for CIN and COUT
#include <math.h> //this is because C++ does not provide an operator for exponents, this library provides support
#include <numbers> //this library has pi in it as a double
#include <string> //this allows us to more easily print a string instead of working with complex c strings.
using namespace std;

#define WEIGHT 15103.00   // Weight in KG
#define GRAVITY -1.625    // Vertical acceleration due to gravity, in m/s^2
#define THRUST 45000.00   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDistance(double s, double v, double a, double t) {
    //instantiate a variable to hold the new value
    double newPosition;
    //apply the equation to get the new position.
    newPosition = s + v * t + .5 * a * (pow(t,2));
    //return the new position 
    return newPosition;
}

 /**************************************************
  * COMPUTE ACCELERATION
  * Find the acceleration given a thrust and mass.
  * This will be done using Newton's second law of motion:
  *     f = m * a
  * INPUT
  *     f : force, in Newtons (kg * m / s^2)
  *     m : mass, in kilograms
  * OUTPUT
  *     a : acceleration, in meters/second^2
  ***************************************************/
double computeAcceleration(double f, double m) {
    //instantiate a variable to hold the accelleration in meters/second^2
    double a;
    //compute the new accelleration
    a = f / m; 
    //return the acceleration 
    return a; 
}

  /***********************************************
   * COMPUTE VELOCITY
   * Starting with a given velocity, find the new
   * velocity once acceleration is applied. This is
   * called the Kinematics equation. The
   * equation is:
   *     v = v + a t
   * INPUT
   *     v : velocity, in meters/second
   *     a : acceleration, in meters/second^2
   *     t : time, in seconds
   * OUTPUT
   *     v : new velocity, in meters/second
   ***********************************************/
double computeVelocity(double v, double a, double t) {
    //instantiate a new variable to hold the new velocity
    double newVelocity;
    //claculate new velocity
    newVelocity = v + a * t;
    //return the new velocity
    return newVelocity;
}


   /***********************************************
    * COMPUTE VERTICAL COMPONENT
    * Find the vertical component of a velocity or acceleration.
    * The equation is:
    *     cos(a) = y / total
    * This can be expressed graphically:
    *      x
    *    +-----
    *    |   /
    *  y |  / total
    *    |a/
    *    |/
    * INPUT
    *     a : angle, in radians
    *     total : total velocity or acceleration
    * OUTPUT
    *     y : the vertical component of the total
    ***********************************************/
double computeVerticalComponent(double a, double total) {
    //create a variable to hold the vertical componenent of the total
    double newTotal;
    //use the equation above to create the new total
    newTotal = cos(a) * total;
    //return the new total.
    return newTotal;
}

    /***********************************************
     * COMPUTE HORIZONTAL COMPONENT
     * Find the horizontal component of a velocity or acceleration.
     * The equation is:
     *     sin(a) = x / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     x : the vertical component of the total
     ***********************************************/
double computeHorizontalComponent(double a, double total) {
    //make a variable to hold the vertical component of the total
    double newTotal;
    //compute the new total
    newTotal = sin(a) * total;
    //return the new total
    return newTotal;
}

     /************************************************
      * COMPUTE TOTAL COMPONENT
      * Given the horizontal and vertical components of
      * something (velocity or acceleration), determine
      * the total component. To do this, use the Pythagorean Theorem:
      *    x^2 + y^2 = t^2
      * where:
      *      x
      *    +-----
      *    |   /
      *  y |  / total
      *    | /
      *    |/
      * INPUT
      *    x : horizontal component
      *    y : vertical component
      * OUTPUT
      *    total : total component
      ***********************************************/
double computeTotalComponent(double x, double y) {
    //create a new variable to hold the total
    double total;
    //calculate the total
    total = pow(x, 2) + pow(y, 2);
    total = sqrt(total);
    //return the total
    return total;
}


      /*************************************************
       * RADIANS FROM DEGEES
       * Convert degrees to radians:
       *     radians / 2pi = degrees / 360
       * INPUT
       *     d : degrees from 0 to 360
       * OUTPUT
       *     r : radians from 0 to 2pi
       **************************************************/
double convertToRadians(double d) {
    //create variable to hold radians
    double radians;
    //calculate the radians
    radians = d / 360;
    radians = radians / 2 * (atan(1) * 4); //this atan part is how we can calculate pi in C++, its not perfect but the percision is close to so. 
    //return the radians
    return radians;
}

       /**************************************************
        * PROMPT
        * A generic function to prompt the user for a double
        * INPUT
        *      message : the message to display to the user
        * OUTPUT
        *      response : the user's response
        ***************************************************/
double prompt(string message) {
    //create a variable to hold the users response
    double response;
    //display the message to the user and allow them to input a value
    cout << message;
    cin >> response;
    //return the response
    return response;
}

        /****************************************************************
         * MAIN
         * Prompt for input, compute new position, and display output
         ****************************************************************/
int main()
{
    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double x = prompt("What is your position (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double t = prompt("What is the time interval (s)? ");
    double aRadians;      // Angle in radians
    double totalThrust;   // Total thrust 
    double ddxThrust;     // Horizontal acceleration due to thrust
    double ddyThrust;     // Vertical acceleration due to thrust
    double ddx;           // Total horizontal acceleration
    double ddy;           // Total vertical acceleration
    double v;             // Total velocity

    // Go through the simulator five times
    for (int i = 0; i < 5; i++)
    {
        //first we compute the new location of the lander by coputing acceleration, 
        //then velocity, then the new location with those things
        
        computeAcceleration();

        
        // Output
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << "\tNew position:   (" << x << ", " << y << ")m\n";
        cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
        cout << "\tTotal velocity:  " << v << "m/s\n\n";
    }

    return 0;
}