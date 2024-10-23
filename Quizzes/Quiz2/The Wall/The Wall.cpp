#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Node.h"

using namespace std;

void addMember(int& partySize) {
    while (true) {
        system("cls");
        cout << "How many members would you like to add to the party? ";
        cin >> partySize;

        if (cin.fail() || partySize < 1) {
            cin.clear(); 
            cin.ignore(9999, '\n'); 
            cout << "INVALID INPUT. Please enter a positive integer." << endl;
            system("pause");
        }
        else {
            cin.ignore(9999, '\n');
            break;
        }
    }
}


void displayMembers(Node*& head) {
    cout << endl;
    cout << "Party Members Alive:" << endl;
    Node* traverse = head;
    while (traverse != nullptr) {
        cout << traverse->name << endl;
        traverse = traverse->next;
    }
    cout << "++++++++++++++++" << endl;
    cout << endl;
}

Node* getRandomNode(Node* head, int partySize) {
    int startingPoint = rand() % partySize;

    Node* current = head;
    for (int i = 0; i < startingPoint; ++i) {
        current = current->next;
    }

    return current;
}

void eliminateMember(Node*& head, Node* startingMember, int& drawnNum, int& partySize) {
    Node* toDelete = startingMember;

    // Move to the drawn number
    for (int i = 0; i < drawnNum - 1; i++) {
        if (toDelete->next != nullptr) {
            toDelete = toDelete->next;
        }
        else {
            toDelete = head; // wrap around to the beginning
        }
    }

    cout << toDelete->name << " has been eliminated." << endl;

    // Remove the node from the linked list
    if (toDelete->previous != nullptr) {
        toDelete->previous->next = toDelete->next;
    }
    else {
        head = toDelete->next; // Updating head if we are deleting the first node
    }

    if (toDelete->next != nullptr) {
        toDelete->next->previous = toDelete->previous;
    }

    delete toDelete;
    partySize--;
}

int main() {
    srand(time(NULL));

    int partySize, roundNum = 1, drawnNum;
    string nameToAdd;

    // Track these 3 pointers while building a linked list
    Node* head = nullptr;
    Node* current = nullptr;
    Node* previous = nullptr;

    addMember(partySize);

    for (int i = 0; i < partySize; i++) {
        nameToAdd = "";
        cout << "What's your name soldier? ";
        cin >> nameToAdd;

        current = new Node;
        current->name = nameToAdd;
        current->next = nullptr;
        current->previous = previous;

        if (previous != nullptr) {
            previous->next = current;
        }
        else {
            head = current;
        }

        previous = current;
    }

    while (partySize > 1) {
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++" << endl;
        cout << "ROUND " << roundNum << endl;
        cout << "++++++++++++++++++++++++++++++++" << endl;

        displayMembers(head);

        // Determine Starting Member
        Node* startingMember = getRandomNode(head, partySize);

        drawnNum = rand() % partySize + 1; // Random number from 1 to partySize
        cout << startingMember->name << " has drawn " << drawnNum << endl;
        Sleep(1000);

        eliminateMember(head, startingMember, drawnNum, partySize); // Start elimination from the random member
        Sleep(1000);

        roundNum++;
        Sleep(1000);
    }

    cout << endl;
    cout << "++++++++++++++++++++++++++++++++" << endl;
    cout << "FINAL RESULT " << roundNum << endl;
    cout << "++++++++++++++++++++++++++++++++" << endl;

    cout << head->name << " will go to seek for reinforcements" << endl;
    cout << endl;

    system("pause");
    system("cls");

    return 0;
}
