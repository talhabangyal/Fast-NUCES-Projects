#include"menu.h"

// Main Menu
void displayMenu() {
    cout << "--- Mini Instagram ---" << endl;
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cout << "3. Logout" << endl;
    cout << "4. Send Friend Request" << endl;
    cout << "5. View Notifications" << endl;
    cout << "6. Post Content" << endl;
    cout << "7. View Posts" << endl;
    cout << "8. Send Message" << endl;
    cout << "9. View Messages" << endl;
    cout << "10. View Friends" << endl;
    cout << "11. View Friend Request" << endl;
    cout << "12. Accept Friend Request" << endl;
    cout << "13. Reject Friend Request" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Helper Function to Get Current Timestamp
string getCurrentTimestamp() {
    time_t now = time(0);  // Get current time
    char buffer[26];       // Buffer to hold the formatted time
    ctime_s(buffer, sizeof(buffer), &now);  // Safe version of ctime
    return string(buffer); // Return as a string
}