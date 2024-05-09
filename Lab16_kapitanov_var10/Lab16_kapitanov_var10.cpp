#include <iostream>
#include <locale>

using namespace std;

class Customer {
private:
    string surname;
    string name;
    string patronymic;
    string address;
    string phone;
    long long creditCardNumber;
    long long bankAccountNumber;

public:
    Customer(string sn, string n, string pt, string addr, string ph, long long ccn, long long ban)
        : surname(sn), name(n), patronymic(pt), address(addr), phone(ph), creditCardNumber(ccn), bankAccountNumber(ban) {}

    void show() const {
        cout << "покупець: " << surname << " " << name << " " << patronymic << endl
            << "адреса: " << address << endl
            << "телефон: " << phone << endl
            << "номер кредитноi карти: " << creditCardNumber << endl
            << "номер банкiвського акаунту: " << bankAccountNumber << endl;
    }

    string getSurname() const { return surname; }
    long long getCreditCardNumber() const { return creditCardNumber; }
};
void sortCustomers(Customer customers[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (customers[j].getSurname() > customers[j + 1].getSurname()) {
                Customer temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
            }
        }
    }
}
void printCustomersInCardRange(Customer customers[], int size, long long low, long long high) {
    for (int i = 0; i < size; i++) {
        if (customers[i].getCreditCardNumber() >= low && customers[i].getCreditCardNumber() <= high) {
            customers[i].show();
        }
    }
}
int main() {
    setlocale(LC_ALL, "ukr");
    Customer customers[] = {
        Customer("Петренко", "Василь", "Iванович", "вул. Зелена, 12", "0501234567", 4731000011110000, 38001234567890),
        Customer("Iваненко", "Iван", "Петрович", "вул. Синя, 8", "0507654321", 4731000099990000, 38009876543210),
        Customer("Коваленко", "Олексiй", "Георгiйович", "пр. Перемоги, 3", "0501122334", 4731000055550000, 38005678349012)
    };
    int numCustomers = sizeof(customers) / sizeof(customers[0]);
    sortCustomers(customers, numCustomers);
    cout << "Список покупцiв в алфавiтному порядку:" << endl;
    for (int i = 0; i < numCustomers; i++) {
        customers[i].show();
    }
    long long lowRange = 4731000000000000;
    long long highRange = 4731000100000000;
    cout << "\nСписок покупцiв, номер кредитноi картки яких знаходиться в заданому iнтервалi:" << endl;
    printCustomersInCardRange(customers, numCustomers, lowRange, highRange);
    return 0;
}