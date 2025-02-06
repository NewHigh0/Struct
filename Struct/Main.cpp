#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//struct Book {
//    std::string title;
//    std::string author;
//    std::string publisher;
//    std::string genre;
//};
//
//void printBooks(Book books[], int size) {
//    std::cout << "\nList of books:\n";
//    for (int i = 0; i < size; i++) {
//        std::cout << i + 1 << ". " << books[i].title << " - " << books[i].author
//            << " (" << books[i].publisher << ", " << books[i].genre << ")\n";
//    }
//}
//
//void editBook(Book books[], int size) {
//    int index;
//    std::cout << "Enter the book number to edit (1-" << size << "): ";
//    std::cin >> index;
//    std::cin.ignore();
//
//    if (index < 1 || index > size) {
//        std::cout << "Invalid book number!\n";
//        return;
//    }
//
//    index--;
//    std::cout << "Enter new title: ";
//    getline(std::cin, books[index].title);
//    std::cout << "Enter new author: ";
//    getline(std::cin, books[index].author);
//    std::cout << "Enter new publisher: ";
//    getline(std::cin, books[index].publisher);
//    std::cout << "Enter new genre: ";
//    getline(std::cin, books[index].genre);
//
//    std::cout << "Book updated!\n";
//}
//
//void searchByAuthor(Book books[], int size, std::string author) {
//    bool found = false;
//    std::cout << "\nSearch results:\n";
//    for (int i = 0; i < size; i++) {
//        if (books[i].author == author) {
//            std::cout << books[i].title << " (" << books[i].publisher << ", " << books[i].genre << ")\n";
//            found = true;
//        }
//    }
//    if (!found) {
//        std::cout << "No books found by this author.\n";
//    }
//}
//
//void searchByTitle(Book books[], int size, std::string title) {
//    bool found = false;
//    for (int i = 0; i < size; i++) {
//        if (books[i].title == title) {
//            std::cout << "Book found: " << books[i].title << " - " << books[i].author
//                << " (" << books[i].publisher << ", " << books[i].genre << ")\n";
//            found = true;
//            break;
//        }
//    }
//    if (!found) {
//        std::cout << "Book not found.\n";
//    }
//}
//
//void sortByTitle(Book books[], int size) {
//    std::sort(books, books + size, [](const Book& a, const Book& b) {
//        return a.title < b.title;
//        });
//}
//
//void sortByAuthor(Book books[], int size) {
//    std::sort(books, books + size, [](const Book& a, const Book& b) {
//        return a.author < b.author;
//        });
//}
//
//void sortByPublisher(Book books[], int size) {
//    std::sort(books, books + size, [](const Book& a, const Book& b) {
//        return a.publisher < b.publisher;
//        });
//}

struct Man {
    std::string lastName;
    std::string firstName;
    int age;
    std::string birthDate;
};

void printPeople(const std::vector<Man>& people) {
    std::cout << "\nList of people:\n";
    for (const auto& person : people) {
        std::cout << person.lastName << " " << person.firstName
            << ", Age: " << person.age << ", Birthday: " << person.birthDate << "\n";
    }
}

void sortByLastName(std::vector<Man>& people) {
    std::sort(people.begin(), people.end(), [](const Man& a, const Man& b) {
        return a.lastName < b.lastName;
        });
}

void sortByFirstName(std::vector<Man>& people) {
    std::sort(people.begin(), people.end(), [](const Man& a, const Man& b) {
        return a.firstName < b.firstName;
        });
}

void showBirthdaysInMonth(const std::vector<Man>& people, int month) {
    std::cout << "\nBirthdays in month " << month << ":\n";
    bool found = false;
    for (const auto& person : people) {
        int personMonth = std::stoi(person.birthDate.substr(5, 2));
        if (personMonth == month) {
            std::cout << person.firstName << " " << person.lastName << " - " << person.birthDate << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No birthdays found for this month.\n";
    }
}

void addPerson(std::vector<Man>& people) {
    Man newPerson;
    std::cout << "Enter last name: ";
    std::cin >> newPerson.lastName;
    std::cout << "Enter first name: ";
    std::cin >> newPerson.firstName;

    while (true) {
        std::cout << "Enter age: ";
        std::cin >> newPerson.age;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a valid age.\n";
        }
        else {
            break;
        }
    }

    std::cout << "Enter birth date (YYYY-MM-DD): ";
    std::cin >> newPerson.birthDate;

    people.push_back(newPerson);
    std::cout << "Person added successfully.\n";
}

void removePerson(std::vector<Man>& people) {
    std::string lastName;
    std::cout << "Enter last name of the person to remove: ";
    std::cin >> lastName;

    auto it = std::remove_if(people.begin(), people.end(), [&](const Man& person) {
        return person.lastName == lastName;
        });

    if (it != people.end()) {
        people.erase(it, people.end());
        std::cout << "Person removed successfully.\n";
    }
    else {
        std::cout << "No person found with last name: " << lastName << "\n";
    }
}

void searchPerson(const std::vector<Man>& people) {
    std::cin.ignore();
    std::string key;
    std::cout << "Enter name or last name to search: ";
    std::getline(std::cin, key);

    bool found = false;
    for (const auto& person : people) {
        if (person.lastName == key || person.firstName == key) {
            std::cout << person.lastName << " " << person.firstName
                << ", Age: " << person.age << ", Birthday: " << person.birthDate << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No matching person found.\n";
    }
}

void editPerson(std::vector<Man>& people) {
    std::string lastName;
    std::cout << "Enter last name of the person to edit: ";
    std::cin >> lastName;

    for (auto& person : people) {
        if (person.lastName == lastName) {
            std::cout << "Enter new first name: ";
            std::cin >> person.firstName;
            std::cout << "Enter new age: ";
            while (!(std::cin >> person.age)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Enter a valid age: ";
            }
            std::cout << "Enter new birth date (YYYY-MM-DD): ";
            std::cin >> person.birthDate;
            std::cout << "Record updated successfully.\n";
            return;
        }
    }
    std::cout << "No person found with last name: " << lastName << "\n";
}

int main() {

    /*Book books[10] = {
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"Moby-Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", "Psychological"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown", "Novel"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott", "Fiction"},
        {"The Lord of the Rings", "J.R.R. Tolkien", "Allen & Unwin", "Fantasy"},
        {"The Odyssey", "Homer", "Ancient Greece", "Epic Poetry"}
    };

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print all books\n";
        std::cout << "2. Edit a book\n";
        std::cout << "3. Search by author\n";
        std::cout << "4. Search by title\n";
        std::cout << "5. Sort by title\n";
        std::cout << "6. Sort by author\n";
        std::cout << "7. Sort by publisher\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            printBooks(books, 10);
            break;
        case 2:
            editBook(books, 10);
            break;
        case 3: {
            std::string author;
            std::cout << "Enter author name: ";
            getline(std::cin, author);
            searchByAuthor(books, 10, author);
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Enter book title: ";
            getline(std::cin, title);
            searchByTitle(books, 10, title);
            break;
        }
        case 5:
            sortByTitle(books, 10);
            std::cout << "Books sorted by title.\n";
            break;
        case 6:
            sortByAuthor(books, 10);
            std::cout << "Books sorted by author.\n";
            break;
        case 7:
            sortByPublisher(books, 10);
            std::cout << "Books sorted by publisher.\n";
            break;
        default:
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);*/

    std::vector<Man> people = {
        {"Smith", "John", 30, "1994-06-15"},
        {"Doe", "Jane", 25, "1999-03-22"},
        {"Brown", "Michael", 40, "1984-11-09"},
        {"Taylor", "Emma", 28, "1996-07-30"},
        {"Johnson", "Chris", 35, "1988-05-17"},
        {"Miller", "Sarah", 32, "1992-02-12"}
    };

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print all records\n";
        std::cout << "2. Sort by last name\n";
        std::cout << "3. Sort by first name\n";
        std::cout << "4. Show birthdays in a specific month\n";
        std::cout << "5. Add a new record\n";
        std::cout << "6. Remove a record\n";
        std::cout << "7. Search by last name or first name\n";
        std::cout << "8. Edit a record\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            printPeople(people);
            break;
        case 2:
            sortByLastName(people);
            std::cout << "Sorted by last name.\n";
            break;
        case 3:
            sortByFirstName(people);
            std::cout << "Sorted by first name.\n";
            break;
        case 4:
            int month;
            std::cout << "Enter month (1-12): ";
            std::cin >> month;
            showBirthdaysInMonth(people, month);
            break;
        case 5:
            addPerson(people);
            break;
        case 6:
            removePerson(people);
            break;
        case 7:
            searchPerson(people);
            break;
        case 8:
            editPerson(people);
            break;
        default:
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
