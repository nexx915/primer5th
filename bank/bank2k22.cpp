#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>

void mainscreen();

void captcha();
void reg();
void login();

void menu();

void deposit();
void withdraw();
void balance();

void logout();


int main()
{
    system("cls");
    mainscreen();
}

void mainscreen() {
    int choose;
    std::string NickName;
    system("cls");
    SetConsoleTitleA("Bank");
    std::cout << "Hello " << NickName << std::endl;
    NickName = system("echo %username%");
    std::cout << "[1] Login " << std::endl;
    std::cout << "[2] Register " << std::endl;
    std::cout << "\n[3] Exit " << std::endl;
    std::cout << "\nChoose: ";
    std::cin >> choose;
    if (choose == 1 || choose == 2) {
        system("cls");
        if (choose == 1) {
            captcha();
        }
        else if (choose == 2)
        {
            reg();
        }
        else {
            mainscreen();
        }
    }


}

void captcha() {
    int odp, random, random1, random2, random3;

    srand(time(NULL));

    random = (rand() % 42 + 1);
    random1 = (rand() % 27 + 1);
    random2 = (rand() % 31 + 1);
    random3 = random + random1 + random2;

    system("cls");
    std::cout << "Retype the CAPTCHA code: " << random3 << std::endl;
    std::cout << "CAPTCHA: ";
    std::cin >> odp;

    if (odp == random3)
    {
        login();
    }
    else
    {
        std::cout << "CAPTCHA invalid, try again!" << std::endl;
        std::cin.get();
        std::cin.get();
        captcha();
    }
}
void reg() {
    std::string ID, haslo;

    system("cls");
    SetConsoleTitleA("Registeration");
    std::cout << "[Registeration]" << std::endl;

    std::cout << "\nID: ";
    std::cin >> ID;
    std::cout << "Password: ";
    std::cin >> haslo;

    system("cls");

    std::fstream plik;
    plik.open("dane.txt", std::ios::out);

    plik << ID << std::endl;
    plik << haslo << std::endl;

    std::cout << "Account succesfully registered!" << std::endl;
    std::cin.ignore(); std::cin.ignore();
    plik.close();
    mainscreen();
}
void login() {
    std::string linia, haslo, hasloo;
    int number = 1, login, ID;

    SetConsoleTitleA("Login");
    std::cout << "\n[Login]" << std::endl;

    std::fstream plik;
    plik.open("dane.txt", std::ios::in);

    while (getline(plik, linia)) {
        switch (number) {
        case 1: ID = atoi(linia.c_str()); break;
        case 2: haslo = linia; break;
        }
        number++;
    }

    std::cout << "ID: ";
    std::cin >> login;
    std::cout << "Haslo: ";
    std::cin >> hasloo;

    if (login == ID && hasloo == haslo) {
        system("cls");
        std::cout << "Login successful!";
        std::cin.ignore(); std::cin.ignore();
        menu();
    }
    else {
        system("cls");
        std::cout << "try again" << std::endl;
        std::cin.ignore(); std::cin.ignore();
        main();
    }
    plik.close();
}

void menu() {
    int choose;
    system("cls");
    SetConsoleTitleA("Menu");
    std::cout << "[Bank]" << std::endl;
    std::cout << "[1] Deposit" << std::endl;
    std::cout << "[2] Withdraw" << std::endl;
    std::cout << "[3] Account balance" << std::endl;
    std::cout << "\n[4] Logout" << std::endl;
    std::cout << "\nChoose: "; std::cin >> choose;
    system("cls");

    switch (choose) {
    case 1: {
        deposit();
    }
    case 2: {
        withdraw();
    }
    case 3: {
        balance();
    }
    case 4: {
        logout();
    } }
}

void deposit() {
    std::string linia;
    int number = 1, suma = 0;
    float money;

    SetConsoleTitleA("Deposit");
    std::cout << "[Deposit]" << std::endl;

    std::fstream plik1;
    plik1.open("stan.txt", std::ios::in);

    while (getline(plik1, linia)) {
        switch (number) {
        case 1: suma = atoi(linia.c_str()); break;
        }
        number++; }
    std::cout << "\nAccount balance: " << suma << std::endl;
    std::cout << "How much u want to deposit: ";
    std::cin >> money;

    plik1.close();

    plik1.open("stan.txt", std::ios::out);
    suma = suma + money;

    plik1 << suma << std::endl;
    std::cout << "Account balance: " << suma << std::endl;
    std::cin.get();
    plik1.close();
    std::cin.get();
    menu();
}
void withdraw()
{
    std::string linia;
    int number = 1, suma = 0;
    float money;

    SetConsoleTitleA("Withdraw");
    std::cout << "[Withdraw]" << std::endl;

    std::fstream plik1;
    plik1.open("stan.txt", std::ios::in);

    while (getline(plik1, linia)) {
        switch (number) {
        case 1: suma = atoi(linia.c_str()); break;
        }
        number++;
    }
    std::cout << "\nAccount balance: " << suma << std::endl;
    std::cout << "How much u want to withdraw: ";
    std::cin >> money;

    plik1.close();

    plik1.open("stan.txt", std::ios::out);
    suma = suma - money;

    plik1 << suma << std::endl;
    std::cout << "Account balance: " << suma << std::endl;
    std::cin.get();
    plik1.close();
    std::cin.get();
    menu();
}
void balance() {
    std::string linia;
    int number = 1, stan = 0;

    SetConsoleTitleA("Balance");
    std::cout << "[Balance]" << std::endl;

    std::fstream plik1;
    plik1.open("stan.txt", std::ios::in);

    while (getline(plik1, linia)) {
        switch (number) {
        case 1: stan = atoi(linia.c_str()); break;
        }
        number++;
    }

    std::cout << "Account balance: " << stan << std::endl;
    std::cin.get();
    plik1.close();
    std::cin.get();
    menu();

}

void logout() {
    for (int i = 5; i >= 0; i--) {
        Sleep(500);
        std::cout << "Logging out in: " << i << std::endl;
    }
    system("cls");
    main();
}
