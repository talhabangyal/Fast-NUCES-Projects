#ifndef CREDIENTIAL_H
#define CREDIENTIAL_H
#pragma once
#include"menu.h"
#include"data.h"

class CredentialManager {
    CredentialNode* head;

public:
    CredentialManager();
    void addUser(string username, string password);
    bool authenticate(string username, string password);
    bool findUser(string username);
};
#endif