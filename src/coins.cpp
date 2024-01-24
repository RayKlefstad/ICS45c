#include "coins.hpp"
#include <iostream>

using namespace std;

// Constructs 'this' Coins object with the specified number of coins.
Coins::Coins(int q, int d, int n, int p) : quarters(q), dimes(d), nickels(n), pennies(p) {}

// Deposits coins from another Coins object into 'this' Coins object.
void Coins::deposit_coins(Coins& coins) {
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;
}

// Checks if 'this' Coins object has enough of each type of coin for the specified coins.
bool Coins::has_exact_change_for_coins(const Coins& coins) const {
    return quarters >= coins.quarters && dimes >= coins.dimes &&
           nickels >= coins.nickels && pennies >= coins.pennies;
}

// Extracts the specific number of each type of coin from 'this' Coins object.
Coins Coins::extract_exact_change(const Coins& coins) {
    if (has_exact_change_for_coins(coins)) {
        quarters -= coins.quarters;
        dimes -= coins.dimes;
        nickels -= coins.nickels;
        pennies -= coins.pennies;
        return coins;
    }
    return Coins(0, 0, 0, 0);
}

// Returns the total value in cents of the coins in 'this' object.
int Coins::total_value_in_cents() const {
    return quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME +
           nickels * CENTS_PER_NICKEL + pennies * CENTS_PER_PENNY;
}

// Prints out the coin information in the specified format.
void Coins::print(std::ostream& out) const {
    out << quarters << " quarters, " << dimes << " dimes, "
        << nickels << " nickels, " << pennies << " pennies";
}

// Output stream inserter for a Coins object.
std::ostream& operator<<(std::ostream& out, const Coins& coins) {
    coins.print(out);
    return out;
}

// Calculates the coins required for a given amount in cents.
Coins coins_required_for_cents(int amount_in_cents) {
    int quarters = amount_in_cents / CENTS_PER_QUARTER;
    amount_in_cents %= CENTS_PER_QUARTER;
    int dimes = amount_in_cents / CENTS_PER_DIME;
    amount_in_cents %= CENTS_PER_DIME;
    int nickels = amount_in_cents / CENTS_PER_NICKEL;
    amount_in_cents %= CENTS_PER_NICKEL;
    int pennies = amount_in_cents;

    return Coins(quarters, dimes, nickels, pennies);
}

// Prints the given number of cents in the "$x.xx" format.
void print_cents(int cents, std::ostream& out) {
    out << "$" << cents / 100 << "." << cents % 100;
}

// Asks for coins and returns a Coins object with the entered values.
Coins ask_for_coins(std::istream& in, std::ostream& out) {
    int q, d, n, p;
    out << "Quarters? ";
    in >> q;
    out << "Dimes? ";
    in >> d;
    out << "Nickels? ";
    in >> n;
    out << "Pennies? ";
    in >> p;
    return Coins(q, d, n, p);
}

// Presents a coins menu and handles deposits, extractions, and balance printing.
void coins_menu(std::istream& in, std::ostream& out) {
    Coins wallet(0, 0, 0, 0); // Initialize an empty wallet
    int choice;

    do {
        // Display menu options
        out << "\nCoins Menu:\n";
        out << "1. Deposit Coins\n";
        out << "2. Extract Exact Change\n";
        out << "3. Print Balance\n";
        out << "4. Exit\n";
        out << "Enter your choice: ";
        in >> choice;

        switch (choice) {
            case 1: {
                out << "Deposit Coins:\n";
                Coins deposit = ask_for_coins(in, out);
                wallet.deposit_coins(deposit);
                out << "Coins deposited successfully.\n";
                break;
            }
            case 2: {
                out << "Extract Exact Change:\n";
                Coins extract = ask_for_coins(in, out);
                if (wallet.has_exact_change_for_coins(extract)) {
                    wallet.extract_exact_change(extract);
                    out << "Coins extracted successfully.\n";
                } else {
                    out << "Not enough coins for this extraction.\n";
                }
                break;
            }
            case 3:
                out << "Current Balance: ";
                wallet.print(out);
                out << "\n";
                break;
            case 4:
                out << "Exiting Coins Menu.\n";
                break;
            default:
                out << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

