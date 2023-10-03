#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class to_do_list
{
    int count;

    int menu()      // menu function
    {
        cout << "Select A Valid Operation\n";
        cout << "1. Enter A Task\n";
        cout << "2. View Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Task As Completed\n";
        cout << "5. Count Total Number of Task\n";
        cout << "6. Exit\n";

        int opt;
        while (1)
        {
            cin >> opt;
            if (opt >= 1 && opt <= 6)           //end loop if input lies between 1 to 6
                break;
            else
                cout << "Enter a Valid Option\n";
        }
        system("cls");
        return opt;
    }
    void add_task()
    {
        ofstream off;
        off.open("To_Do_List", ios::app);       //opening file in append mode
        string data;
        cout << "Enter The Task : ";

        while (1)
        {
            getline(cin, data);  // get line input
            getline(cin, data);  // get line input
            char opt;
            cout << "Confirm Add This Task ? (y/n) : ";        // confirm the task
            cin >> opt;
            if (opt == 'Y' || opt == 'y')
                break;
            else
                cout << "Enter The Task Again\n";
        }
        off << data << endl;
        count++;                //update the count
        off.close();
    }
    void view_task()        //display all task
    {
        ifstream file;
        file.open("To_Do_List");        
        string temp;

        cout << "Displaying To Do List" << endl;
        //getline(file, temp);
        for (int i = 1; i <= count; i++)
        {
            getline(file, temp);
            cout << i << ". " << temp << endl;      
        }

        file.close();
    }
    void delete_task()
    {
        view_task();
        int index;
        cout << "Enter The Index of Task You want To delete : ";        
        while (1)
        {
            cin >> index;
            if (index > 0 && index <= count)        // geting the valid index other wise we give out error
                break;
            else
                cout << "Enter Valid Index : ";
        }
        ifstream ifile;
        ofstream ofile;
        ifile.open("To_Do_List");
        ofile.open("temp");     //only creating to copy old data

        string temp;
        for (int i = 1; i <= count; i++)
        {
            getline(ifile, temp);
            
            if (i != index)         // coping all other tasks into a temporary file besides the one we want to delete
                ofile << temp << endl;
        }

        ifile.close();
        ofile.close();
        count--;            //update count
        cout << count << endl;
        copy_back();        // now copy the updated data back to orignal file
    }
    void copy_back()
    {
        string temp;
        ifstream iff;
        ofstream off;

        iff.open("temp");
        off.open("To_Do_List");

        for (int i = 1; i <= count; i++)
        {
            getline(iff, temp);         //coping data from temporary file to original file
            off << temp << endl;
        }

        iff.close();
        off.close();
        
        remove("temp"); // removing the temporary file
    }
    void mark_read()
    {
        view_task();
        int index;
        string temp;

        cout << "Enter The Index of Task You want To Mark as Complete : ";
        while (1)
        {
            cin >> index;
            if (index > 0 && index <= count)        //taking valid input
                break;
            else
                cout << "Enter Valid Index : ";

        }
        ifstream iff;
        iff.open("To_Do_List");
        //checking if task is already been marked or not
        for (int i = 1; i <= index; i++)
        {
            getline(iff, temp);
            if (i == index)
            {
                if (temp[temp.length() - 1] == '\t')        // using /t as a invisible character to check if task is already marked as completed or not
                {
                    cout << "This Task Is Alredy Marked As Completed\n";
                    return;         // if its already marked , return to menu
                }
            }
        }
        ifstream ifile;
        ofstream ofile;
        ifile.open("To_Do_List");
        ofile.open("temp");     //only creating to copy old data

        // maeking the task by adding (task completed) next to it
        for (int i = 1; i <= count; i++)
        {
            getline(ifile, temp);

            if (i == index)
                ofile << temp << "     (Task Completed)\t" << endl; //putting /t as invisible character 
            else
                ofile << temp << endl;
        }
        copy_back();
        cout << "Task Marked as Completed\n";
    }

public:
    to_do_list()
    {
        count = 0;                  // default value of count
        ifstream iff;
        iff.open("count.txt");     // if count file already exits then we get count from there
        if(iff)
        iff >> count;
    }
    void start()        // starting function
    {
        while(1)
        { 
        cout << "******** Welcome To Menu ********\n";
        switch (menu())         // display menu and and then call the corsposning function
        {
        case 1:
        {
            add_task();
        }
        break;
        case 2:
        {
            if (count == 0)
                cout << "No Task To Display" << endl;
            else
            view_task();
        }
        break;
        case 3:
        {
            if (count == 0)
                cout << "All Task Already Deleted" << endl;
            else
            {
                delete_task();
                cout << "Task Deleted\n";
            }

        }
        break;
        case 4:
        {
            mark_read();
        }
        break;
        case 5:
        {
            cout << "There Are total " << count << " Task in the List" << endl;
        }
        break;
        case 6:
        {
            return;         // return aka end the function and ending the run
        }
        }
        }
    }

    ~to_do_list()       //updating the total count of task saved
    {
        ofstream file;
        file.open("Count.txt");
        file << count;
        cout << count << endl;
    }

};

int main()
{    
    to_do_list list1;
    list1.start();
    return 0;
}

