#include"crediential.h"

CredentialManager::CredentialManager() {
    head = nullptr;

}

void CredentialManager::addUser(string username, string password) {
    if (!findUser(username)) {
        CredentialNode* newNode = new CredentialNode(username, password);
        newNode->next = head;
        head = newNode;
    }
}

bool CredentialManager::authenticate(string username, string password) {
    CredentialNode* temp = head;
    while (temp) {
        if (temp->username == username && temp->password == password)
            return true;
        temp = temp->next;
    }
    return false;
}

bool CredentialManager::findUser(string username) {
    CredentialNode* temp = head;
    while (temp) {
        if (temp->username == username)
            return true;
        temp = temp->next;
    }
    return false;
}