#include <bits/stdc++.h>
using namespace std;

class ColourGame {
    // Dictionary with Items and Corresponding colours
    map<string, vector<string>> items;

    // List of Subscribed Items;
    set<string> subscribedItems;

    // List of Available Colour
    vector<string> colours;

public:
    // Initalize Items with available colours
    void initializeItems() {
        items = {
            {"banana" , {"green" , "yellow"}}, 
            {"ink" , {"red" , "black"}}, 
            {"salt" , {"white"}},
            {"frog" , {"blue" , "yellow"}},
            {"blood" , {"red"}},
            {"sky" , {"blue" , "black"}},
            {"apple" , {"red" , "green"}} 
        };
    }

    // Initialize Available colours list
    void initializeColour() {
        colours = {"red", "green", "blue", "white", "black", "yellow"};
    }

    // Subsribe to any Item
    void subscribe(string item) {
        if (items.find(item) != items.end()) {
            subscribedItems.insert(item);
            cout << "Subscribed " << item << endl;
        } 
        else {
            cout << "Invalid Thing or Already Subscribed!!" << endl;
        }
    }

    // Unsubscribe to any Item
    void unSubscribe(string item) {
        if (subscribedItems.find(item) != subscribedItems.end()) {
            subscribedItems.erase(item);
            cout << "Unubscribed " << item << endl;
        } else {
            cout << "Invalid thing or Not subscribed!!" << endl;
        }
    }

    //  Show subscribed Item list
    void showSubscribedList() {
        if(subscribedItems.size() == 0) {
            cout << "You haven't subscribed to any item" << endl;
            return;
        }
        for (auto item : subscribedItems) {
            cout << item << " ";
        }
        cout << endl;
    }

    // Dispalying items for give colour
    void showMagic(string colour) {
        if (count(colours.begin(), colours.end(), colour)) {
            for (auto item : subscribedItems) {
                if (items[item].size() > 1 && count(items[item].begin(), items[item].end(), colour)) {
                    if ( item != "frog") {
                        cout << "I'm " + item + "! and I am sometimes " + colour << endl;
                    } 
                    else {
                        cout << "I'm frog! and I am " + colour + " today!" << endl;
                    }
                }
                else if (count(items[item].begin(), items[item].end(), colour)) {
                    cout << "I'm " + item + "! and I am always " + colour << endl;
                }
            }
        } else { 
            cout << "What are you talking about? Invalid Command" << endl;
        }
    }
};



int main() {
    ColourGame colourGame;

    colourGame.initializeItems();
    colourGame.initializeColour();

    cout << "Presenting the Colour Game: " << endl;
    cout << "Type +ItemName to add it into your subscribed list" << endl;
    cout << "Type Colour Name to check the magic" << endl;
    cout << "Type list to check the subsribed list" << endl;
    cout << "Type exit to exit the game" << endl;

    while (true) {
        string command;
        cin >> command;

        if (command[0] == '+') {
            colourGame.subscribe(command.substr(1));
        } 
        else if (command[0] == '-') {
            colourGame.unSubscribe(command.substr(1));
        } 
        else if (command == "exit") {
            cout << "See you next time. Thanks for Playing the game" << endl;
            break;
        } 
        else if (command == "list") {
            colourGame.showSubscribedList();
        } 
        else {
            colourGame.showMagic(command);
        }
    }

    return 0;
}