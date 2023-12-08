# BANK


The provided C++ code is a simple console-based program that allows the user to either enter new student data or view existing student data. It uses file handling to store and retrieve student information in a text file named "Student_data.txt." The program defines a `Student` class with attributes such as name, note1, note2, and noteMoyenne (average note). Here is a summary of the code:

### Student Class:
- Represents a student with attributes: `NameOfStudent`, `note1`, `note2`, and `noteMoyenne`.
- Provides methods to set and validate note values.
  
### Global Vector:
- `vector<Student>` bookList; is declared globally to store student objects.

### Main Function:
- Displays a menu to the user (1 for adding a new student, 2 for viewing students, 3 for exit).
- Calls corresponding functions based on user input.

### addStudent Function:
- Takes user input for a new student's name, note1, and note2.
- Calculates the average note (`noteMoyenne`).
- Appends the student data to "Student_data.txt."
### seeStuden Function:
- Reads and searches for a student by name in "Student_data.txt."
- Displays the student's information if found; otherwise, prints "Student not found."
