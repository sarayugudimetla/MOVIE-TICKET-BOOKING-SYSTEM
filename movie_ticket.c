#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class User {
public:
    string username;
    string password;

    User(string username, string password) : username(username), password(password) {}
};

class Show {
public:
    string title;
    string time;
    int availableSeats;

    Show(string title, string time, int availableSeats) : title(title), time(time), availableSeats(availableSeats) {}
};

class MovieTicketBooking {
public:
    vector<User> users;
    vector<Show> shows;
    vector<pair<string, string > > bookedTickets;

    void registerUser(string username, string password) {
        users.push_back(User(username, password));
    }

    void addShow(string title, string time, int availableSeats) {
        shows.push_back(Show(title, time, availableSeats));
    }

    bool validateLogin(string username, string password) {
        for (User user : users) {
            if (user.username == username && user.password == password) {
                return true;
            }
        }
        return false;
    }

    bool bookTicket(string username, string title) {
        cout << "Booking ticket for " << title << " for user " << username << endl;
        for (Show& show : shows) {
            if (show.title == title) {
                if (show.availableSeats > 0) {
                    show.availableSeats--;
                    saveTicket(username, title);
                    return true;
                } else {
                    cout << "Sorry, no seats available for " << title << endl;
                    return false;
                }
            }
        }
        cout << "No such movie available for booking" << endl;
        return false;
    }

    void saveTicket(string username, string title) {
        bookedTickets.push_back(make_pair(username, title));
    }

    void displayShows() {
        cout << "Available Shows:" << endl;
        for (Show show : shows) {
            cout << show.title << " - " << show.time << " - " << show.availableSeats << " seats available" << endl;
        }
    }

    void displayBookedTickets() {
        cout << "Booked Tickets:" << endl;
        for (pair<string, string> ticket : bookedTickets) {
            cout << ticket.first<< " has booked Ticket for " << ticket.second << endl;
        }
    }

    void logout() {
        cout << "Logout Successful!" << endl;
    }
};

int main() {
    system("clear");
    MovieTicketBooking movieTicketBooking;
    movieTicketBooking.registerUser("nikhil", "12345");
    movieTicketBooking.registerUser("jayadeep", "12345");
    movieTicketBooking.registerUser("sarayu", "12345");
    movieTicketBooking.registerUser("harshitha", "12345");
    movieTicketBooking.addShow("KING", "06:00 PM", 9);
    movieTicketBooking.addShow("Inception", "12:00 PM", 5);
    movieTicketBooking.addShow("Titanic", "02:00 PM", 7);
    top:
     string username, password, title;
     cout << "Enter username: ";
     cin >> username;
     cout << "Enter password: ";
     cin >> password;
     if(!movieTicketBooking.validateLogin(username,password)){
       printf("Invalid Credentials!!!\n");
       goto top;
     }
    string choice;
    do {
        cout << "1. Show Available Shows" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Show Booked Tickets" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "2") {
            cout << "Enter the movie title you want to book:";
            cin >> title;
            if (movieTicketBooking.bookTicket(username, title)) {
                cout << "Ticket booked successfully!" << endl;
            }
        }
         else if (choice == "1") {
            movieTicketBooking.displayShows();
        } else if (choice == "3") {
            movieTicketBooking.displayBookedTickets();
        } else if (choice == "4") {
            movieTicketBooking.logout();
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != "4");

    return 0;
}
