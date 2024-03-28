#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Class of Book

class Book {
private:
    string title;
    string author;
    double price;
    int quantity;

public:
    Book(string _title, string _author, double _price, int _quantity) : title(_title), author(_author), price(_price), quantity(_quantity) {}


    //Getters


    string getTitle() const {

        return title;
    }

    string getAuthor() const { 

        return author;
    }

    double getPrice() const {

        return price;
    }

    int getQuantity() const {

        return quantity; 
    }


    //Update Quantity


    void updateQuantity(int soldQuantity) {
        if (soldQuantity <= quantity) {

            quantity -= soldQuantity;
        }

        else {

            cout << "Not enough stock available for " << title << endl;
        }
    }
};


// Class of ShoppingCart


class ShoppingCart {
private:

    vector<Book*> cart;

public:
    
    void addToCart(Book* book) {
        if (book->getQuantity() > 0){

            cart.push_back(book);
            cout << book->getTitle() << " added to the cart." << endl;
            book->updateQuantity(1);
        }
        else {

            cout << "Sorry, " << book->getTitle() << " is out of stock." << endl;
        }
    }

    //View Cart

    void viewCart(){

        if (cart.empty()) {

            cout << "Your cart is empty." << endl;
            return;
        }

        cout << "Cart Contents:" << endl;

        for (const auto& book : cart) {

            cout << "- " << book->getTitle() << " by " << book->getAuthor() << " - $" << book->getPrice() << endl;
        }
    }

    // Checkout

    void checkout() {
        if (cart.empty()) {

            cout << "Your cart is empty. Nothing to checkout." << endl;
            return;
        }

        double total = 0;
        cout << "Items Purchased:" << endl;
        for (const auto& book : cart) {

            cout << "- " << book->getTitle() << " - $" << book->getPrice() << endl;
            total += book->getPrice();
        }

        cout << "Total: $" << total << endl;
        cart.clear(); // Empty the cart after checkout
    }
};

int main() {
    

    cout << "                             --------------------ONLINE BOOKSTORE SYSTEM--------------------" << endl;


    ShoppingCart cart;

    Book book1("Percy Jackson", "A.Murphey", 9.99, 10);
    Book book2("The Red Cross Knight", "Cilian Douglas", 8.99, 10);
    Book book3("The Lost Island", "George Washington", 7.99, 10);

    // Menu loop

    int choice;
    do {

        cout << "\nMenu:\n1. View Books\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {

            // Display available books

            cout << "\nAvailable Books:" << endl;
            cout << "- " << book1.getTitle() << " by " << book1.getAuthor() << " - $" << book1.getPrice() << " (Quantity: " << book1.getQuantity() << ")" << endl;
            cout << "- " << book2.getTitle() << " by " << book2.getAuthor() << " - $" << book2.getPrice() << " (Quantity: " << book2.getQuantity() << ")" << endl;
            cout << "- " << book3.getTitle() << " by " << book3.getAuthor() << " - $" << book3.getPrice() << " (Quantity: " << book3.getQuantity() << ")" << endl;
            break;
        }
        case 2: {

            // Add a book to cart
            cout << "\nEnter the index of the book you want to add to your cart (1, 2, or 3): ";
            int bookNumber;
            cin >> bookNumber;
            switch (bookNumber) {
            case 1:
                cart.addToCart(&book1);
                break;
            case 2:
                cart.addToCart(&book2);
                break;
            case 3:
                cart.addToCart(&book3);
                break;
            default:
                cout << "Invalid book number." << endl;
            }
            break;
        }
        case 3:
            // View cart contents
            cart.viewCart();
            break;
        case 4:
            // Checkout
            cart.checkout();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
