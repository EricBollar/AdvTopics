#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

const int radius = 2;

void createDots(vector<CircleShape> &dots, Vertex trianglePoints[], int howManyDots) {
    CircleShape firstDot(radius);
    firstDot.setFillColor(Color::Red);
    Vertex randomVertex = trianglePoints[rand() % 3];
    firstDot.setPosition(randomVertex.position.x, randomVertex.position.y);
    dots.push_back(firstDot);
    CircleShape prevDot = firstDot;
    for (int i = 0; i < howManyDots - 1; i++) {
        CircleShape nextDot(radius);
        nextDot.setFillColor(Color::Red);
        randomVertex = trianglePoints[rand() % 3];
        nextDot.setPosition(randomVertex.position.x + prevDot.getPosition().x/2, randomVertex.position.y + prevDot.getPosition().y/2);
        dots.push_back(nextDot);
        prevDot = nextDot;
    }
}

int main() {

    RenderWindow window(VideoMode(640,480,32),"Chaos Game");

    Vertex trianglePoints[4];
    int numPoints = 0;

    vector<CircleShape> dots;

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed){
                window.close();
            } else if (event.type == Event::MouseButtonReleased) {
                Vertex point = Vertex(Vector2f(event.mouseButton.x, event.mouseButton.y));
                point.color = Color::Black;
                trianglePoints[numPoints] = point;
                numPoints++;
                if (numPoints == 3) {
                    trianglePoints[numPoints] = trianglePoints[0];
                    numPoints = 4;
                    createDots(dots, trianglePoints, 10000);
                }
            }
            window.clear(Color::White);
            window.display();

            for (auto dot : dots) {
                window.draw(dot);
            }
        }
    }

    return 0;
}