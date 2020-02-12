//CSE_110_500_Sean_Eriksson_Lab_8 - Password creation and validation

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;


void get_input(char stringInput[], int SIZE, int &attempt, bool &goodPassword);  //gain the first input from the user

void get_input2(char stringInput[], int SIZE);  //gain the second input from the user

void validate_input(char stringInput[], int SIZE, int &attempt, bool &goodPassword); //validate the first input

void validate_input2(char stringInput[], int SIZE, int &attempt, bool &goodPassword); //validate the second input

void compare_strings(char stringInput[], char stringInput2[], int &attempt, bool &goodPassword, bool &goodPassword2); //compare the first string to the second string

void output_instructions(); //print the output instructions string


int main()
{
    int attempt = 0;  //keep track of the user attempts
    const int SIZE = 20;  //max size of the password
    char userInput[SIZE];  //first string for the user input
    char userInput2[SIZE];  //second string for the user input
    bool goodPassword = false;  //variable to track if the first password is good
    bool goodPassword2 = false;  //variable to track if the second password is good

    while (attempt < 3 && goodPassword == 0)  //perform loop for 3 attempts

    {
        get_input(userInput, SIZE, attempt, goodPassword);  //get the first input from the user

        while (attempt < 3 && goodPassword == 1 && goodPassword2 == 0)  //if attempts is less then 3 and the first password is good proceed to second validation
        {
            get_input2(userInput2, SIZE);  //gain second input from the user
            compare_strings(userInput, userInput2, attempt, goodPassword, goodPassword2); //compare the second input to the first input
        }

        attempt = attempt + 1;  //increase attempt amount
    }


    return 0;
}


void get_input(char stringInput[], int SIZE, int &attempt, bool &goodPassword)  //get the first string from the user
{


    output_instructions();  //output the instructions for the password

    cin.getline(stringInput, SIZE);  //take in the input

    validate_input(stringInput, SIZE, attempt, goodPassword); //validate the input

}

void get_input2(char stringInput[], int SIZE)  //gain input from the user

{
    cin.getline(stringInput, SIZE);  //get the second string from the user

}


void validate_input(char stringInput[], int SIZE, int &attempt, bool &goodPassword) //validate the input

{

    //list of errors
    int errorOccured = 0;  //s

    bool stringLengthError = false;

    bool digitFoundError = false;

    bool upperFoundError = false;

    bool lowerFoundError = false;



    //check for string length

    int stringLengthCheck = 0;

    int stringLength = strlen(stringInput);  //set the string length

    if (stringLength > 7)  //check to see if the string length is at least 8 characters long
        {
            stringLengthCheck = 1;
        }

    else  //flag the string length error if necessary
        {
            errorOccured = 1;
            stringLengthError = true;
        }



    //check for digit

    int counter;

    int digitFound = 0;

    for (counter = 0; counter < stringLength; counter++)  //iterrate through the string
        {
            if (isdigit(stringInput[counter]))  //check to see if the function contains at least one number
                {
                    digitFound = digitFound + 1;
                }
        }

    if (digitFound == 0)  //flag the digit not found error if necessary
        {
            errorOccured = 1;
            digitFoundError = true;
        }



    //check for at least one upper case letter

    int upperFound = 0;

    for (counter = 0; counter < stringLength; counter++) //iterrate through the string
        {
            if (isupper(stringInput[counter]))  //check to see if the function contains at least one number
                {
                    upperFound = upperFound + 1;
                }
        }

    if (upperFound == 0)  //flag the upper case letter error if necessary
        {
            errorOccured = 1;
            upperFoundError = true;
        }


    //check for at least one lower case letter

    int lowerFound = 0;

    for (counter = 0; counter < stringLength; counter++)  //iterrate through the string
        {
            if (islower(stringInput[counter]))  //check to see if the function contains at least one number
                {
                    lowerFound = lowerFound + 1;
                }
        }

    if (lowerFound == 0)  //flag the lower found error if necessary
        {
            errorOccured = 1;
            lowerFoundError = true;
        }

    if (errorOccured > 0)  //if errors occurs alert the user that the password is not valid
        {
            goodPassword = false;
            cout << "" << endl;
            cout << stringInput << " is not a valid password." << endl;
        }

    if (errorOccured == 0)  //if no errors proceed
        {
            goodPassword = true;
            cout << "" << endl;
            cout << stringInput << " is a valid password." << endl;
            cout << "   Re-enter the password for validation: ";
        }

    //handle the output strings for the errors

    if (stringLengthError == true) cout << "It does not contain at least 8 characters."<< endl;  //print string length error

    if (digitFoundError == true) cout << "It does not contain at least one number." << endl;  //print digit not found error

    if (upperFoundError == true) cout << "It does not contain an upper case letter."<< endl; //print upper not found error

    if (lowerFoundError == true) cout << "It does not contain a lower case letter."<< endl;  //print lower not found error

    if (errorOccured > 0)
    {
        //whitespace
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
    }

}

void compare_strings(char stringInput[], char stringInput2[], int &attempt, bool &goodPassword, bool &goodPassword2) //validate the second input by comparing it to the first input

{

    if (strcmp(stringInput, stringInput2)==0)  //compare string 1 to string 2
    {
        cout << "" << endl;
        cout << "Passwords match.";
        cout << "" << endl;
        attempt = 3;
        goodPassword2 = true;
    }

    else
    {
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "<<<   This password \""<< stringInput <<"\" does not match the second entry \"" << stringInput2 <<"\"   >>>";
        goodPassword = false;
        goodPassword2 = false;
        //whitespace
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
    }
}

void output_instructions() //print the instructions

{
    cout << "--------------------------------" << endl;
    cout << "Enter a password that contains:" << endl;
    cout << "At least eight (8) characters, including" << endl;
    cout << "at least one number," << endl;
    cout << "at least one upper case letter," << endl;
    cout << "and at least one lower case letter." << endl;
    cout << "" << endl;
    cout << "Password: ";
}
