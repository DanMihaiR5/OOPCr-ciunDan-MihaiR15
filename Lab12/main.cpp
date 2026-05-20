#include <iostream>
#include <vector>
#include <memory>
#include <string>

enum class ContactType {
    Friend,
    Acquaintance,
    Colleague
};

class Contact {
protected:
    std::string name;
    ContactType type;

public:
    Contact(const std::string& name, ContactType type)
        : name(name), type(type) {}

    virtual ~Contact() = default;

    std::string getName() const {
        return name;
    }

    ContactType getType() const {
        return type;
    }

    virtual void print() const = 0;
};

class Friend : public Contact {
private:
    std::string birthDate;
    std::string phoneNumber;
    std::string address;

public:
    Friend(const std::string& name,
           const std::string& birthDate,
           const std::string& phoneNumber,
           const std::string& address)
        : Contact(name, ContactType::Friend),
          birthDate(birthDate),
          phoneNumber(phoneNumber),
          address(address) {}

    void print() const override {
        std::cout << "Friend\n";
        std::cout << "Name: " << name << '\n';
        std::cout << "Birth date: " << birthDate << '\n';
        std::cout << "Phone: " << phoneNumber << '\n';
        std::cout << "Address: " << address << "\n\n";
    }
};

class Acquaintance : public Contact {
private:
    std::string phoneNumber;

public:
    Acquaintance(const std::string& name,
                 const std::string& phoneNumber)
        : Contact(name, ContactType::Acquaintance),
          phoneNumber(phoneNumber) {}

    void print() const override {
        std::cout << "Acquaintance\n";
        std::cout << "Name: " << name << '\n';
        std::cout << "Phone: " << phoneNumber << "\n\n";
    }
};

class Colleague : public Contact {
private:
    std::string phoneNumber;
    std::string company;
    std::string address;

public:
    Colleague(const std::string& name,
              const std::string& phoneNumber,
              const std::string& company,
              const std::string& address)
        : Contact(name, ContactType::Colleague),
          phoneNumber(phoneNumber),
          company(company),
          address(address) {}

    void print() const override {
        std::cout << "Colleague\n";
        std::cout << "Name: " << name << '\n';
        std::cout << "Phone: " << phoneNumber << '\n';
        std::cout << "Company: " << company << '\n';
        std::cout << "Address: " << address << "\n\n";
    }
};

class AddressBook {
private:
    std::vector<std::shared_ptr<Contact>> contacts;

public:
    void addContact(std::shared_ptr<Contact> contact) {
        contacts.push_back(contact);
    }

    void deleteContact(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->getName() == name) {
                contacts.erase(it);
                std::cout << "Contact deleted.\n";
                return;
            }
        }

        std::cout << "Contact not found.\n";
    }

    std::shared_ptr<Contact> searchByName(const std::string& name) {
        for (auto& contact : contacts) {
            if (contact->getName() == name) {
                return contact;
            }
        }

        return nullptr;
    }

    std::vector<std::shared_ptr<Friend>> getFriends() {
        std::vector<std::shared_ptr<Friend>> friendsList;

        for (auto& contact : contacts) {
            if (contact->getType() == ContactType::Friend) {
                friendsList.push_back(
                    std::dynamic_pointer_cast<Friend>(contact)
                );
            }
        }

        return friendsList;
    }

    void printAll() const {
        for (const auto& contact : contacts) {
            contact->print();
        }
    }
};

int main() {

    AddressBook book;

    book.addContact(
        std::make_shared<Friend>(
            "Alice",
            "12/05/2000",
            "0711111111",
            "Bucharest"
        )
    );

    book.addContact(
        std::make_shared<Acquaintance>(
            "Bob",
            "0722222222"
        )
    );

    book.addContact(
        std::make_shared<Colleague>(
            "Charlie",
            "0733333333",
            "Microsoft",
            "Cluj"
        )
    );

    std::cout << "ALL CONTACTS\n\n";
    book.printAll();

    std::cout << "SEARCH CONTACT\n\n";

    auto contact = book.searchByName("Alice");

    if (contact != nullptr) {
        contact->print();
    }
    else {
        std::cout << "Contact not found.\n";
    }

    std::cout << "FRIENDS LIST\n\n";

    auto friends = book.getFriends();

    for (auto& f : friends) {
        f->print();
    }

    std::cout << "DELETE CONTACT\n\n";

    book.deleteContact("Bob");

    std::cout << "\nUPDATED CONTACTS\n\n";

    book.printAll();

    return 0;
}