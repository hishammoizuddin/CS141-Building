// Author: Mohammed Hisham Moizuddin - CS141 SUMMER 2020
// Program 1- Building

/*  Running the program looks like:
        Choose from among the following options:
        1. Display original graphic
        2. Display Building
        3. Exit the program
        Your choice -> 1

####################################################################
####   |  |        |        |  |\    |   ______   |   ______    ####
####   |  |        |        |  | \   |  |      |  |  |          ####
####   |  |        |        |  |  \  |  |      |  |  |______    ####
####   |  |        |        |  |   \ |  |      |  |         |   ####
####   |  |______  |______  |  |    \|  |______|  |   ______|   ####
####################################################################

 */


#include <iostream>   // for cin and cout
#include <iomanip>    // for setw() and setfill()
using namespace std;  // so that we don't need to preface every cin and cout with std::

//I've Created various functions to display different parts of the tower, called collectively and sequentially in the main()

void top_section(int total)              //This function prints the top section of the tower
{
    cout<<setw(total)<<" "<<" /\\\n"
        <<setw(total)<<" "<<" ||\n"
        <<setw(total)<<" "<<" ||\n"
        <<setw(total)<<" "<<" --\n"
        <<setw(total)<<" "<<"|++|\n"
        <<setw(total)<<" "<<"====\n";
}

void mid_lines(int current_sec,int total)  //This function prints the line seperating the different no. of sections of the tower
{
    cout<<setw(total+1)<<setfill(' ');

    for(int i=current_sec;i>=0;i--)
    {
        cout << "/";
        cout << setfill('-')
             << setw((i*2)+1)
             <<"\\";
        break;
    }

}


void mid_secs(int current_sec, int total)   //This Function prints the sections by taking the current as well as total no. of sections as parameters
{
    int x=current_sec;  //variable x to store the value of current_sec, where current_sec is the section being worked on in the loop.

    for(int i=x;i>0;i--)         //Loop to print the top half of the section
    {
        cout<<setw(total+1)<<setfill(' ');

        cout<<"|";
        cout<<setfill(':')
            <<setw((x-i+1))<<"\\"<<setw((x-1)*2-2*(x-i)+1)<<"/"<<setw(x-i+1)<<"|"<<endl;

    }

    for(int i=1;i<=x;i++)         //Loop to print bottom half of the section
    {
        cout<<setw(total+1)<<setfill(' ');

        cout<<"|";
        cout<<setfill(':')
            <<setw(x-i+1)<<"/"<<setw((x-1)*2-2*(x-i)+1)<<"\\"<<setw(x-i+1)<<"|"<<endl;
    }
    mid_lines(current_sec,total);          //Calling function mid_lines() to print the seperation base
}


void base_dots(int total)        //This function prints the '.' on the base of the tower
{

    cout <<' '
         <<setfill('.')
         << setw((4+2*total)+1)
         <<"\n";
}

void base_plus(int total)     //This function prints the '+' on the base of the tower
{
    cout << setfill('+')
         << setw((6+2*total)+1);
}


int main()   //main function
{
    int userOption = 0;    //user choice
    int num_of_secs=0;     //no. of sections of the building to be displayed (user input).

    cout << "Choose from among the following options:  \n"
         << "1. Display original graphic  \n"
         << "2. Display building          \n"
         << "3. Exit the program          \n"
         << "Your choice -> ";
    cin >> userOption;                          //accepting user choice.


    if( userOption == 3) {    //exits the program if exit was chosen by user
        exit(0);
    }

    else if( userOption == 1) {        //Displaying "ILLINOIS" as ASCII Art i.e the original graphic.
        for( int i=0; i<68; i++) {
            cout << "#";
        }
        cout << endl;

        cout << setfill('#')
             << setw( 5) << " " << "  |  |        |        |  |\\    |   ______   |   ______  "<<"  "<<setw( 5)<<"\n"
             << setw( 5) << " " << "  |  |        |        |  | \\   |  |      |  |  |        "<<"  "<<setw( 5)<<"\n"
             << setw( 5) << " " << "  |  |        |        |  |  \\  |  |      |  |  |______  "<<"  "<<setw( 5)<<"\n"
             << setw( 5) << " " << "  |  |        |        |  |   \\ |  |      |  |         | "<<"  "<<setw( 5)<<"\n"
             << setw( 5) << " " << "  |  |______  |______  |  |    \\|  |______|  |   ______| "<<"  "<<setw( 5)<<"\n";
        for( int i=0; i<68; i++) {
            cout <<"#";
        }
        cout << endl;
    }

    else if(userOption == 2)     //displaying the building with num_of_secs sections (based on user input),
    {
        cout<<"\nNumber of building sections -> ";
        cin>>num_of_secs;
        cout<<endl;

        int total=num_of_secs+1;
        top_section(total);                  //Always Displaying top section first.

        for(int i=1;i<=num_of_secs;i++)   //Loop to call function mid_secs() as many times as the user input for sections, to display those many sections
        {
            mid_secs(i,total);
            cout<<endl;
            total--;
        }

        base_dots(num_of_secs);         //Function call to display the base dots '.'
        base_plus(num_of_secs);        // Function call to display the base plus '+'

        cout<<"\n";


    }

    cout << endl;
    return 0;
}                  //end of main()
