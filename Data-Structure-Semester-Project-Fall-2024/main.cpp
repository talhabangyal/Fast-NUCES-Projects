#include"menu.h"
#include"graph.h"
#include"crediential.h"
#include"data.h"

int main() {
    UserGraph userGraph;
    CredentialManager credentials;
    string currentLoggedInUser;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        if (choice == 0) break;

        string username, password, friendName, content, sender, receiver;
        switch (choice) {
        case 1: // Signup
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (!credentials.findUser(username)) {
                credentials.addUser(username, password);
                userGraph.addUser(username);
                cout << "Signup successful!" << endl;
            }
            else {
                cout << "Username already exists." << endl;
            }
            break;

        case 2: // Login
            if (!currentLoggedInUser.empty()) {
                cout << "You are already logged in as " << currentLoggedInUser << ". Logout first." << endl;
                break;
            }
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (credentials.authenticate(username, password)) {
                currentLoggedInUser = username;
                cout << "Login successful! Welcome, " << username << "." << endl;
            }
            else {
                cout << "Invalid username or password." << endl;
            }
            break;

        case 3: // Logout
            if (!currentLoggedInUser.empty()) {
                cout << "Goodbye, " << currentLoggedInUser << "." << endl;
                currentLoggedInUser.clear();
            }
            else {
                cout << "No user is currently logged in." << endl;
            }
            break;

        case 4: // Send Friend Request
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            cout << "Enter friend's username: ";
            cin >> friendName;
            userGraph.addFriendRequest(currentLoggedInUser, friendName);
            cout << "Friend request sent!" << endl;
            break;

        case 5: // View Notifications
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            userGraph.displayNotifications(currentLoggedInUser);
            break;

        case 6: // Post Content
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            cout << "Enter post content: ";
            cin.ignore();
            getline(cin, content);
            userGraph.postContent(currentLoggedInUser, content);
            cout << "Post added!" << endl;
            break;

        case 7: // View Posts
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            userGraph.viewPosts(currentLoggedInUser);
            break;

        case 8: // Send Message
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            cout << "Enter receiver's username: ";
            cin >> receiver;
            cout << "Enter message content: ";
            cin.ignore();
            getline(cin, content);
            userGraph.sendMessage(currentLoggedInUser, receiver, content);
            cout << "Message sent!" << endl;
            break;

        case 9: // View Messages
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            userGraph.viewMessages(currentLoggedInUser);
            break;

        case 10: // View Friends
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            userGraph.displayFriends(currentLoggedInUser);
            break;
        case 11: // View Friend Requests
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            userGraph.displayFriendRequests(currentLoggedInUser);
            break;

        case 12: // Accept Friend Request
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            cout << "Enter sender's username to accept the friend request: ";
            cin >> sender;
            userGraph.acceptFriendRequest(currentLoggedInUser, sender);
            break;

        case 13: // Reject Friend Request
            if (currentLoggedInUser.empty()) {
                cout << "Please login first." << endl;
                break;
            }
            cout << "Enter sender's username to reject the friend request: ";
            cin >> sender;
            userGraph.rejectFriendRequest(currentLoggedInUser, sender);
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}