#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void titel_bank();
void meun();
void AddAccount();
void seeAccount();
void editmontant();
void repat();
class Account {
public:
    string firstName;
    string lastName;
    int Cin;
    int montant;

    Account(string firstName, string lastName,int Cin, int montant) {
        this->firstName = firstName;
        this->lastName = lastName;
      //  this->Cin = Cin;
        setCin(Cin);
      //  this->montant = montant;
        setMontant(montant);
      //  setnoteMoyenne(noteMoyenne);
    }

    void setMontant(int montant) {
       this->montant = (montant < 0) ? 0 : montant;
    }
    void setCin(int Cin) {
       this->Cin = (Cin < 0) ? 0 : Cin;
    }


    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }
};

int main(){

    int menu ;

    system("cls");
    returns :
    titel_bank();
    meun();

    do{
        printf("\n\n");
        printf("donnez choix : ");
        scanf("%d", &menu);

        if (menu>4 || menu < 1){
            printf("Your choice must be between (1 and 4): ");
        }
    } while (menu > 4 || menu < 1);
    switch (menu)
    {
    case 1:
        system("cls");
        printf(" ********************************* 1.Create an account *********************************\n");
        AddAccount();

        repat();
        break;
    case 2:
        system("cls");
        printf(" ********************************* 2. Operations *********************************\n\n");
        editmontant();
        repat();
        break;
    case 3 :

        system("cls");
        printf(" ********************************* 3. Display *********************************\n\n");
        seeAccount();
        repat();
       break;

    case 4:

        break;
    default:

        printf("error !! ");
        break;

    }

    return 0;
}

void repat() {
    int repeat;
    cout << "\nDo you want to return? \n1: Yes \n2: No\nSelect 1 or 2: ";
    cin >> repeat;

    if (repeat == 1) {
        system("cls");
      main();
    } else {
        return;  // Handle other cases if needed
    }
}

void titel_bank(){
    printf("===================================================================\n");
    printf("==========================    bank     ============================\n");
    printf("===================================================================\n");
};

void meun(){
    printf("Hello what do you want : \n\n");
    printf("1 .Create an account \n\n");
    printf("2 .Operations  \n\n");
    printf("3 .Display  \n\n");
    printf("4 .Exit  \n\n");
}

void AddAccount(){
    vector<Account> bookList;
    string Fname,Lname;
    int Cin, montant;

    printf("\nWrite your cin :");
    cin >> Cin;
    printf("\nType your first name :");
    cin >> Fname;
    printf("\nEnter your last name :");
    cin >> Lname;
    printf("\nType your amount :");
    cin >> montant;


    Account newAccount(Fname, Lname, Cin, montant);
    bookList.push_back(newAccount);

    ofstream outputFile("Bank_data.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
    }

    outputFile << "Cin: " << newAccount.Cin << "\n";
    outputFile << "montant: " << newAccount.montant << "\n";
    outputFile << "first name: " << newAccount.getFirstName() << "\n";
    outputFile << "last name: " << newAccount.getLastName() << "\n";
    outputFile << "-----------------\n";

    outputFile.close();

    cout << "New account data has been appended" << endl;
}

void seeAccount() {
    std::ifstream inputFile("Bank_data.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
    }

    string searchcin;
    cout << "Enter the Cin of the account you want to search for : ";
    cin >> searchcin;

    std::string line;
    bool found = false;
    while (std::getline(inputFile, line)) {
        size_t foundPos = line.find("Cin: " + searchcin);
        if (foundPos != string::npos) {
            cout << line << endl;
            std::getline(inputFile, line);
            cout << line << endl;
            std::getline(inputFile, line);
            cout << line << endl;
            std::getline(inputFile, line);
            cout << line << endl;
            std::getline(inputFile, line);
            cout << line << endl;
            found = true;
        }
    }

    inputFile.close();

    if (!found) {
        cout << "Account not found!" << endl;
    }
}

void editmontant() {
    ifstream inputFile("Bank_data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string searchcin;
    cout << "Enter the Cin of the account you want to edit montant for: ";
    cin >> searchcin;

    string line;
    bool found = false;
    ofstream tempFile("temp.txt");

    while (getline(inputFile, line)) {
        size_t foundPos = line.find("Cin: " + searchcin);
        if (foundPos != string::npos) {
            cout << "Account found. Current details:\n";
            cout << line << endl;

// Extract existing details
string firstName, lastName, montant;

// Read the line with "montant: ..."
getline(inputFile, line);
istringstream issMontant(line.substr(line.find(":") + 1));
issMontant >> montant;

// Read the line with "first name: ..."
getline(inputFile, line);
istringstream issFirstName(line.substr(line.find(":") + 1));
getline(issFirstName, firstName);

// Read the line with "last name: ..."
getline(inputFile, line);
istringstream issLastName(line.substr(line.find(":") + 1));
getline(issLastName, lastName);

// Prompt for the new montant
int newMontant;
cout << "Enter the new montant: ";
cin >> newMontant;

// Update the line with the new montant
line = "Cin: " + searchcin + "\n" +
       "montant: " + to_string(newMontant) + "\n" +
       "first name: " + firstName + "\n" +
       "last name: " + lastName + "\n";

            found = true;
        }

        tempFile << line << endl;  // Write the line to temp file
    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cout << "Account not found!" << endl;
        remove("temp.txt");  // Remove temp file if no changes were made
        return;
    }

    remove("Bank_data.txt");
    rename("temp.txt", "Bank_data.txt");

    cout << "Data updated successfully." << endl;
}
