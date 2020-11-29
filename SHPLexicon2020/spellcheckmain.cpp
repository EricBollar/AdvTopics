#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "shplexicon.h"

using namespace std;
using namespace sf;


int main() {
    srand(time(nullptr));
    RenderWindow window(VideoMode(640,480,32),"Spell Checker");

    Font font;
    font.loadFromFile("resources/fonts/Courier New.ttf");
    Text label;
    label.setFont(font);
    label.setCharacterSize(32);
    label.setString("");
    label.setPosition(window.getSize().x/2 - label.getGlobalBounds().width/2,
                     window.getSize().y/2 - label.getGlobalBounds().height/2);
    label.setFillColor(Color::Black);

    Text topLabel;
    topLabel.setFont(font);
    topLabel.setCharacterSize(14);
    topLabel.setPosition(0, 14);
    topLabel.setFillColor(Color::Black);

    Text bottomLabel;
    bottomLabel.setFont(font);
    bottomLabel.setCharacterSize(28);
    bottomLabel.setPosition(window.getSize().x/2 - label.getGlobalBounds().width/2,
                            window.getSize().y - 45);
    bottomLabel.setFillColor(Color::Blue);

    shplexicon words("words.txt");

    while(window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if (event.type == Event::TextEntered) {
                char ch = static_cast<char>(event.text.unicode);
                if (ch == ' ' || ch == '\n') {
                    // your code here
                    topLabel.setString(topLabel.getString()+' '+label.getString());
                    if (topLabel.getGlobalBounds().width > window.getSize().x) {
                        topLabel.setString(label.getString());
                    }
                    label.setString("");
                } else if (ch == 8) {  // backspace is 8 on the ASCII chart
                    // your code here
                    string str = label.getString();
                    label.setString(str.substr(0, str.length()-1));
                } else {
                    // your code here
                    label.setString(label.getString()+ch);
                }
                // your code here
                if (words.containsWord(label.getString())) {
                    label.setFillColor(Color::Black);
                } else {
                    label.setFillColor(Color::Red);
                }
                string str = label.getString();
                bottomLabel.setString("");
                if (str.length() > 3) {
                    set<string> outcomes = words.getWordsWithPrefix(label.getString());
                    if (0 < outcomes.size() <= 5) {
                        for (auto itr = outcomes.begin(); itr != outcomes.end(); itr++) {
                            bottomLabel.setString(bottomLabel.getString() + ' ' + *itr);
                            cout << *itr;
                        }
                    }
                }
                label.setPosition(window.getSize().x/2-label.getGlobalBounds().width/2,
                                  window.getSize().y/2-label.getGlobalBounds().height/2);
                bottomLabel.setPosition(window.getSize().x/2 - bottomLabel.getGlobalBounds().width/2,
                                        window.getSize().y - 30);
            }

        }

        window.clear(Color::White);
        window.draw(topLabel);
        window.draw(label);
        window.draw(bottomLabel);
        window.display();
    }

    return 0;
}