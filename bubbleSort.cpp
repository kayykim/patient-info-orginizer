// The goal of this code is to
// 1. Read files from a seperate file of patientInfo.txt
// 2. Ask user which category of age, id, first name, last name, sex they would like to sort by
// 3. Sort by category entered by user (age, id, first name, last name, sex)
// 4. Output sorted patient info in tabular form
#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
#include <fstream>
using namespace std; 

const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified

// PART 1A: Create the data struct
struct patientInfo {
    int age;
    int id;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char sex[1];
};

int main()
{
    // PART 1B: Read the patient record
    ifstream infile;
    infile.open("patientInfo.txt");

    // create an array of patient info called record with num patient elements
    patientInfo record[NUM_PATIENTS];

    //read from patientInfo.txt
    for (int i = 0; i < NUM_PATIENTS; i++) {
        // sort into age, id, firstName, lastName, sex arrays
        infile >> (record[i].age);
        infile >> (record[i].id);
        infile >> (record[i].firstName);
        infile >> (record[i].lastName);
        infile >> (record[i].sex);

    }


    // PART 2: Select a primary sorting category from user input
    string input;
    // prompt user for an input for records to be sorted by 
    cout << "Please input a category to sort patient records by." << endl;
    cout << "Options (case senstive) are Age, ID, First, Last, Sex: ";
    cin >> input;    // store user's input into variable called input

    // while loop for error checking
    while (true) {

        // variable temp to swap the ENTIRE patient info when being rearranged for a specific category
        patientInfo temp;

        // PART 5: Tiebreaker 
        // if selected cateogry has the same value the program will sort in accordance to first name

        // sort (char array) first name ALPHABETICALLY before sorting other categories
        for (int n = 0; n< NUM_PATIENTS - 1; n++) {
            for (int i = 0; i < NUM_PATIENTS -1 -n; i++) {
                // swap if (firstName left) alphabetically later than (firstName right) - (>0)
                if (strcmp (record[i].firstName, record[i+1].firstName) > 0) {
                    temp = record[i+1];
                    record[i+1] = record[i];
                    record[i] = temp;
                }
            }
        }

        // PART 4: Sorting patient Records

        // Age is selected. Sort by age.
        if (input == "Age") {
            cout << "Case 1, sorting by Age." << endl;

            // bubble sort (integer) age from LEAST - GREATEST
            for (int n = 0; n< NUM_PATIENTS - 1; n++) {
                for (int i = 0; i < NUM_PATIENTS -1 -n; i++) {
                    // swap if (age left) > (age right)
                    if (record[i].age > record[i+1].age){ 
                        // swap the entire block of patient info using the temp variable
                        temp = record[i+1];
                        record[i+1] = record[i];
                        record[i] = temp;
                    }
                }
            }
            break; // break to cout the sorted list

        }

        // ---- REPEAT this sorting process ----- 

        // ID is selected. Sort by id.
        else if (input == "ID") {
            cout << "Case 2, sorting by ID." << endl;

            // bubble sort (integer) id from LEAST - GREATEST
            for (int n = 0; n< NUM_PATIENTS - 1; n++) {
                for (int i = 0; i < NUM_PATIENTS -1 -n; i++) {
                    // swap if (id left) > (id right)
                    if (record[i].id > record[i+1].id){
                        // swap the entire block of patient info
                        temp = record[i+1];
                        record[i+1] = record[i];
                        record[i] = temp;
                    }
                }
            }
            
            break; // break out to cout sorted list
        }

        // First is selected. Sort by first name.
        else if (input == "First") {
            cout << "Case 3, sorting by First Name." << endl;
            // firstName is already be sorted
            break; // break out to cout sorted list
        }

        // Last is selected. Sort by last name.
        else if (input == "Last") {
            cout << "Case 4, sorting by Last Name." << endl;

            // sort (char array) last name ALPHABETICALLY
            for (int n = 0; n< NUM_PATIENTS - 1; n++) {
                for (int i = 0; i < NUM_PATIENTS -1 -n; i++) {
                    // swap if (lastName left) alphabetically later than (lastName right)
                    if (strcmp (record[i].lastName, record[i+1].lastName) > 0) {
                        temp = record[i+1];
                        record[i+1] = record[i];
                        record[i] = temp;
                    }
                }
            }
            break; // break out to cout sorted list
        }

        // Sex is selected. Sort by Sex. 
        else if (input == "Sex") {
            cout << "Case 5, sorting by Sex." << endl;

                // sort (char) sex ALPHABETICALLY
            for (int n = 0; n< NUM_PATIENTS - 1; n++) {
                for (int i = 0; i < NUM_PATIENTS -1 -n; i++) {
                    // swap if (sex left) alphabetically later than (sex right)
                    if (strcmp (record[i].sex, record[i+1].sex) > 0) {
                        temp = record[i+1];
                        record[i+1] = record[i];
                        record[i] = temp;
                    }
                }
            }
            break; // break out to cout sorted list
        }

        // Invalid input is entered
        else {
            // clear error
            cin.clear(); 
            cin.ignore(100, '\n');

            // ask for input again
            cout << "Unexpected Input. Please input either Age, ID, First, Last, or Sex: " << endl;
            cin >> input;
        }
    }


    // PART 3: Outputting patient records to terminal in tabular form
    cout << "Age:";
    // print out age of all 10 patients in a row 
    for (int k = 0; k < NUM_PATIENTS; k++) {
        cout << setw(10) << record[k].age; // setw(10) == 10 rows
    }

    cout << endl;
    cout << "ID:       ";
    // print out id of all 10 patients in a row
    for (int k = 0; k < NUM_PATIENTS; k++) {
        cout << setw(10) << record[k].id; 
    }
    
    cout << endl;
    cout << "FirstName:";
    // print out first name of all 10 patients in a row
    for (int k = 0; k < NUM_PATIENTS; k++) {
        cout << setw(10) << record[k].firstName;
    }
    
    cout << endl;
    cout << "Last:     ";
    // print out last name of all 10 patients in a row
    for (int k = 0; k < NUM_PATIENTS; k++) {
        cout << setw(10) << record[k].lastName;
    }

    cout << endl;
    cout << "Sex:      ";
    // print out the sex of all 10 patients in a row
    for (int k = 0; k < NUM_PATIENTS; k++) {
        cout << setw(10) << record[k].sex;
    }

    // close file
    infile.close();
    return 0;
}