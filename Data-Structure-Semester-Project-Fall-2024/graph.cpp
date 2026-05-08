#include"graph.h"

UserGraph::UserGraph() {
    head = nullptr;
}

void UserGraph::addUser(string username) {
    if (!findUser(username)) {
        UserFriend* newUser = new UserFriend(username);
        newUser->next = head;
        head = newUser;
    }
}

// Function to add a friend request
void UserGraph::addFriendRequest(string sender, string receiver) {
    UserFriend* user = findUser(receiver);
    if (user) {
        user->friendRequests.enqueue(sender + " sent you a friend request.");
    }
}

// Function to display incoming friend requests for a user
void UserGraph::displayFriendRequests(string username) {
    UserFriend* user = findUser(username);
    if (user) {
        cout << "Friend Requests for " << username << ":" << endl;
        user->friendRequests.display();
        cout << "Do you want to accept or reject any request? (Enter 'accept' or 'reject')" << endl;
    }
}

// Function to accept a friend request
void UserGraph::acceptFriendRequest(string username, string sender) {
    UserFriend* user = findUser(username);
    if (user) {
        // Add the sender to the user's friend list
        FriendNode* newFriend = new FriendNode(sender);
        newFriend->next = user->friendsHead;
        user->friendsHead = newFriend;

        // Remove the notification
        string notificationMessage = sender + " sent you a friend request.";
        if (user->friendRequests.removeMessage(notificationMessage)) {
            cout << "Friend request accepted!" << endl;
        }
        else {
            cout << "Friend request not found." << endl;
        }
    }
}

// Function to reject a friend request
void UserGraph::rejectFriendRequest(string username, string sender) {
    UserFriend* user = findUser(username);
    if (user) {
        // Remove the notification
        string notificationMessage = sender + " sent you a friend request.";
        if (user->friendRequests.removeMessage(notificationMessage)) {
            cout << "Friend request rejected!" << endl;
        }
        else {
            cout << "Friend request not found." << endl;
        }
    }
}

void UserGraph::displayNotifications(string username) {
    UserFriend* user = findUser(username);
    if (user) {
        user->notifications.display();
    }
}

void UserGraph::displayFriends(string username) {
    UserFriend* user = findUser(username);
    if (user) {
        FriendNode* temp = user->friendsHead;
        cout << "Friends of " << username << ": ";
        while (temp) {
            cout << temp->username << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void UserGraph::postContent(string username, string content) {
    UserFriend* user = findUser(username);
    if (user) {
        user->posts.push(content);
        user->notifications.enqueue("New post added: " + content);
    }
}

void UserGraph::viewPosts(string username) {
    UserFriend* user = findUser(username);
    if (user) {
        user->posts.display();
    }
}

void UserGraph::sendMessage(string sender, string receiver, string content) {
    UserFriend* user = findUser(receiver);
    if (user) {
        user->messages.push(sender, content);
        user->notifications.enqueue(sender + " sent you a message: " + content);
    }
}

void UserGraph::viewMessages(string username) {
    UserFriend* user = findUser(username);
    if (user) {
        user->messages.display();
    }
}