#include"menu.h"
#include"data.h"

// Linked List for User Credentials
CredentialNode::CredentialNode(string uname, string pwd) {
	username = uname;
	password = pwd;
	next = nullptr;
}

// Linked List Node for Posts
Post::Post(string content) {
	timestamp = getCurrentTimestamp();
	this->content = content;
	next = nullptr;
}

// Stack for Posts
PostStack::PostStack() {
	top = nullptr;
}
void PostStack::push(string content) {
	Post* newPost = new Post(content);
	newPost->next = top;
	top = newPost;
}

void PostStack::display() {
	Post* temp = top;
	if (!temp) {
		cout << "No posts available." << endl;
		return;
	}
	while (temp) {
		cout << temp->timestamp << ": " << temp->content << endl;
		temp = temp->next;
	}
}

// Queue for Friend Requests or Notifications
QueueNode::QueueNode(string msg) {
	message = msg;
	next = nullptr;
}

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
}

void Queue::enqueue(string msg) {
	QueueNode* newNode = new QueueNode(msg);
	if (rear) {
		rear->next = newNode;
	}
	else {
		front = newNode;
	}
	rear = newNode;
}

string Queue::dequeue() {
	if (!front) return "Queue is empty.";
	QueueNode* temp = front;
	string msg = front->message;
	front = front->next;
	if (!front) rear = nullptr;
	delete temp;
	return msg;
}

bool Queue::isEmpty() {
	return front == nullptr;
}

void Queue::display() {
	QueueNode* temp = front;
	if (!temp) {
		cout << "Queue is empty." << endl;
		return;
	}
	while (temp) {
		cout << temp->message << endl;
		temp = temp->next;
	}
}
bool Queue::removeMessage(const string& msg) {
	if (!front) return false;  // Queue is empty

	// If the message is at the front
	if (front->message == msg) {
		QueueNode* temp = front;
		front = front->next;
		if (!front) rear = nullptr;
		delete temp;
		return true;
	}

	// Search for the message in the rest of the queue
	QueueNode* temp = front;
	while (temp->next) {
		if (temp->next->message == msg) {
			QueueNode* toDelete = temp->next;
			temp->next = temp->next->next;
			if (temp->next == nullptr) rear = temp; // Update rear if necessary
			delete toDelete;
			return true;
		}
		temp = temp->next;
	}

	return false;  // Message not found
}

// Stack for Messages
MessageNode::MessageNode(string sndr, string msg) {
	sender = sndr;
	content = msg;
	next = nullptr;
}

MessageStack::MessageStack() {
	top = nullptr;
}

void MessageStack::push(string sender, string content) {
	MessageNode* newNode = new MessageNode(sender, content);
	newNode->next = top;
	top = newNode;
}

void MessageStack::display() {
	MessageNode* temp = top;
	if (!temp) {
		cout << "No messages available." << endl;
		return;
	}
	while (temp) {
		cout << temp->sender << ": " << temp->content << endl;
		temp = temp->next;
	}
}

// Graph for User Relationships
FriendNode::FriendNode(string uname) {
	username = uname;
	next = nullptr;
}

UserFriend::UserFriend(string uname) {
	username = uname;
	friendsHead = nullptr;
	next = nullptr;
}
