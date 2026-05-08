#ifndef DATA_H
#define DATA_H
#pragma once
#include"data.h"
#include"menu.h"

// Linked List for User Credentials
struct CredentialNode {
    string username;
    string password;
    CredentialNode* next;
    CredentialNode(string uname, string pwd);
};

// Linked List Node for Posts
struct Post {
    string timestamp;
    string content;
    Post* next;
    Post(string content);
};

// Stack for Posts
struct PostStack {
    Post* top;
    PostStack();
    void push(string content);
    void display();
};

// Queue for Friend Requests or Notifications
struct QueueNode {
    string message;
    QueueNode* next;
    QueueNode(string msg);
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
    Queue();
    void enqueue(string msg);
    string dequeue();
    bool isEmpty();
    void display();
    bool removeMessage(const string& msg);
};

// Stack for Messages
struct MessageNode {
    string sender;
    string content;
    MessageNode* next;
    MessageNode(string sndr, string msg);
};

struct MessageStack {
    MessageNode* top;
    MessageStack();
    void push(string sender, string content);
    void display();
};

// Graph for User Relationships
struct FriendNode {
    string username;
    FriendNode* next;
    FriendNode(string uname);
};

struct UserFriend {
    string username;
    FriendNode* friendsHead;
    UserFriend* next;
    Queue friendRequests;
    Queue notifications;
    PostStack posts;
    MessageStack messages;

    UserFriend(string uname);
};


#endif