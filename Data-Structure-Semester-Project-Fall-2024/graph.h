#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include "menu.h"
#include "data.h"

class UserGraph {
    UserFriend* head;
    UserFriend* findUser(string username) {
        UserFriend* temp = head;
        while (temp && temp->username != username) {
            temp = temp->next;
        }
        return temp;
    }
public:
    UserGraph();
    void addUser(string username);
    void addFriendRequest(string sender, string receiver);
    void displayFriendRequests(string username);
    void acceptFriendRequest(string username, string sender);
    void rejectFriendRequest(string username, string sender);
    void displayNotifications(string username);
    void displayFriends(string username);
    void postContent(string username, string content);
    void viewPosts(string username);
    void sendMessage(string sender, string receiver, string content);
	void viewMessages(string username);
};
#endif