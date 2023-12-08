# BANK

It appears that your provided code is a C++ program for a simple banking system. The program includes functionalities such as creating an account, displaying account details, and editing the account balance. Additionally, it utilizes file input/output for data storage.

# Here's a brief summary of the main components and functionalities in the code:

### Class Definition (`Account`):

- Represents an individual bank account with attributes such as first name, last name, Cin (assuming it's a unique identifier), and montant (balance).

### Main Function:
- Displays a menu for creating an account, performing operations, displaying account details, and exiting the program.
- Utilizes a switch-case structure to execute the chosen menu option.

### Menu Functions:
- `AddAccount():` Allows the user to create a new bank account and appends the details to a file named "Bank_data.txt."
- `seeAccount():` Enables the user to search for and display details of an account based on Cin from the file.
- `editmontant():` Facilitates the modification of the balance (montant) for a specific account based on Cin.
  
### File Handling:
- Uses file streams (`ifstream` and `ofstream`) to read from and write to a file ("Bank_data.txt").
- Data is stored in a structured format within the file.

### Repetition Function (`repat()`):
- Asks the user if they want to return to the main menu and restart the program.


## Each account entry in the file is formatted with the following structure:
```
Cin: <Cin>
montant: <montant>
first name: <first name>
last name: <last name>
-----------------
```
## Here are 10 examples of account data entries in the specified format:
```
  Cin: 111111
  montant: 5000
  first_name: Alice
  last_name: Johnson
  -----------------
  Cin: 222222
  montant: 3000
  first_name: Bob
  last_name: Smith
  -----------------
  Cin: 333333
  montant: 1500
  first_name: Carol
  last_name: Williams
  -----------------
  Cin: 444444
  montant: 2000
  first_name: David
  last_name: Miller
  -----------------
  Cin: 555555
  montant: 4500
  first_name: Emily
  last_name: Davis
  -----------------
  Cin: 666666
  montant: 2800
  first_name: Frank
  last_name: Wilson
  -----------------
  Cin: 777777
  montant: 6000
  first_name: Grace
  last_name: Anderson
  -----------------
  Cin: 888888
  montant: 1200
  first_name: Henry
  last_name: Taylor
  -----------------
  Cin: 999999
  montant: 3500
  first_name: Iris
  last_name: Clark
  -----------------
  Cin: 101010
  montant: 1800
  first_name: Jack
  last_name: Martin
  -----------------
```
