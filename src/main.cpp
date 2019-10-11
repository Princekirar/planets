#include<bits/stdc++.h>
#include <GL/glut.h>

#define INF_MASS 10000
#define SCR_SIZE 600

using namespace std;

class Vector;
class Body;
class Sun;
class Planet;

class Vector {

    float x, y;

public:

    Vector();
    Vector(float, float);
    Vector(int, int);
    void setX(float x);                          // Update x
    void setY(float y);                          // Update y
    pair<float, float> cords();                     // Return x and y
    friend Vector operator + (Vector a, Vector b);  // Vector addition
    friend Vector operator * (Vector a, float f);   // Scalar multiplication
    friend float distance (Vector a, Vector b);     // Distance between Vectors

};

class Body {

protected:

    Vector pos;         // Position Components (Coordinates)
    Vector v;           // Velocity Components
    float radius;       // Radius of body
    float mass;         // Mass of the body
    float color[3];     // Color channels of the body

public:

    Vector* position();
    Vector* velocity();
    float fieldDueTo(Body body);    // Update Velocity of *this due to field of body

};

class Planet: public Body {
    public:
        Planet(Vector pos, Vector v, float radius = 1, float mass = 100);
        void draw();  // Draws Planet
};

class Sun: public Body {
    public:
        Sun(Vector pos, Vector v, float radius = 10, float mass = INF_MASS);
        void draw();  // Draws Suns
};

vector<Body*> universe; // Contains all Suns and Planets

int main(int argc, char const *argv[])
{
    universe.push_back(new Sun(Vector(2, 3), Vector(3, 4)));
    universe.push_back(new Planet(Vector(2, 5), Vector(0, 0)));
    return 0;
}