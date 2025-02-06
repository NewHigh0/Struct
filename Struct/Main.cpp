#include <iostream>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;
};

void printBooks(Book books[], int size) {
    std::cout << "\nList of books:\n";
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << books[i].title << " - " << books[i].author
            << " (" << books[i].publisher << ", " << books[i].genre << ")\n";
    }
}

void editBook(Book books[], int size) {
    int index;
    std::cout << "Enter the book number to edit (1-" << size << "): ";
    std::cin >> index;
    std::cin.ignore();

    if (index < 1 || index > size) {
        std::cout << "Invalid book number!\n";
        return;
    }

    index--;
    std::cout << "Enter new title: ";
    getline(std::cin, books[index].title);
    std::cout << "Enter new author: ";
    getline(std::cin, books[index].author);
    std::cout << "Enter new publisher: ";
    getline(std::cin, books[index].publisher);
    std::cout << "Enter new genre: ";
    getline(std::cin, books[index].genre);

    std::cout << "Book updated!\n";
}

void searchByAuthor(Book books[], int size, std::string author) {
    bool found = false;
    std::cout << "\nSearch results:\n";
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            std::cout << books[i].title << " (" << books[i].publisher << ", " << books[i].genre << ")\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found by this author.\n";
    }
}

void searchByTitle(Book books[], int size, std::string title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            std::cout << "Book found: " << books[i].title << " - " << books[i].author
                << " (" << books[i].publisher << ", " << books[i].genre << ")\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Book not found.\n";
    }
}

void sortByTitle(Book books[], int size) {
    std::sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
}

void sortByAuthor(Book books[], int size) {
    std::sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}

void sortByPublisher(Book books[], int size) {
    std::sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
}

int main() {

    Book books[10] = {
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
        std::cout << "0. Exit\n";
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
    } while (choice != 0);

    return 0;
}
