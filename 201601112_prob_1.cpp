/*      NAME: SHREYANSH
        ID  : 201601112
*/


#include<iostream>
#include<string>

using namespace std;

class date                                            //CLASS FOR STORING DATE
{
    int day, month, year;

public:

    date()                                             // DEFAULT CONSTRUCTOR
    {
        day = month = year = 0;
    }

    date(int day, int month, int year)                  //CONSTRUCTOR WITH PARAMETERS
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    date(const date &dt)                                //COPY CONSTRUCTOR
    {
        day = dt.day;
        month = dt.month;
        year = dt.year;
    }

                                                        //SETTER FUNCTION

    void setDay(int day)    {   this->day = day;    }
    void setMonth(int month){   this->month = month;}
    void setYear(int year)  {   this->year = year;  }

                                                        //GETTER FUNCTIONS

    int getDay()    {   return day;     }
    int getMonth()  {   return month;   }
    int getYear()   {   return year;    }

    void getDate()                                       //FUNCTION FOR SETTING UP DATE
    {
        int Day, Month, Year;
        cout<<"\tEnter day: ";
        cin>>Day;   setDay(Day);
        cout<<"\tEnter month: ";
        cin>>Month; setMonth(Month);
        cout<<"\tEnter year: ";
        cin>>Year;  setYear(Year);
    }

    void showDate()                                     //FUNCTION FOR SHOWING DATE
    {
        cout<<" "<<getDay()<<" - "<<getMonth()<<" - "<<getYear()<<endl;
    }
};

//CLASS EMPLOYEE FOR STORING DETAILS OF AN EMPLOYEE

class Employee
{
    int empId;
    string empName;
    date dateOfJoining;

public:

    Employee()                                                  //CONSTRUCTOR
    {
        empId = 0;
        empName = "";
    }

    Employee(int empId, char empName[], date dateOfJoining)     //CONSTRUCTOR WITH PARAMETERS
    {
        this->empId = empId;
        this->empName = empName;
        this->dateOfJoining = dateOfJoining;
    }

    Employee(const Employee &emp)                               //COPY CONSTRUCTOR
    {
        empId = emp.empId;
        empName = emp.empName;
        dateOfJoining = emp.dateOfJoining;
    }

                                                                //SETTER FUNCTIONS

    void setEmpId(int eid)          {   empId = eid;        }
    void setEmpName(string name)    {   empName = name;     }
    void setDateOfJoining(date dt)  {   dateOfJoining = dt; }

                                                                //GETTER FUNCTIONS

    int getEmpId()          {   return empId;       }
    string getEmpName()     {   return empName;     }

    void getEmployee()                                          //FUNCTION FOR INPUT OF EMPLOYEE
    {
        cout<<endl<<"Enter Employee Id: ";
        cin>>empId;
        cout<<"Enter Employee Name: ";
        cin.ignore();
        getline(cin,empName);
        cout<<"Enter Date of Joining: \n";
        dateOfJoining.getDate();
    }

    void showEmployee()                                         //FUNCTION TO SHOW DATA OF EMPLOYEE
    {
        cout<<endl<<"Employee Id: "<<getEmpId();
        cout<<endl<<"Employee Name: "<<getEmpName();
        cout<<endl<<"Date Of Joining: ";
        dateOfJoining.showDate();
        cout<<endl;
    }
};

//CLASS ARRAYLIST FOR CREATING DATA STRUCTURE arrayList WHICH IS USED AS STACK IN GIVEN PROBLEM

template <typename E>
class arrayList
{
    int arraySize;              //MAXIMUM SIZE OF ARRAYLIST
	int currentSize;            //CURRENT SIZE OF ARRAYLIST
	int currentLocation;        //CURRENT LOCATION IN ARRAYLIST
	E* dataArray;               //ARRAY OF DATA OF DATATYPE E

public:

	arrayList(int size)                                 //CONSTRUCTOR
	{
		arraySize = size;
		currentSize = 0;
		currentLocation = -1;
		dataArray = new E[arraySize];
	}

	~arrayList()                                          //DESTRUCTOR
	{
		delete [] dataArray;
	}

	int numberOfElements()  const                           //FUNCTION TO RETURN NUMBER OF ELEMENTS IN LIST
	{
        return currentSize;
	}

	const E& getData() const                                //FUNCTION TO RETURN DATA AT CURRENT LOCATION
	{
        return dataArray[currentLocation];
	}

	void insert(const E& data)                              //FUNCTION TO INSERT DATA IN GIVEN ARRAYLIST
	{
		if(currentSize<arraySize)
		{
			currentLocation++;
			dataArray[currentLocation] = data;
			currentSize++;
		}
		else
		{
		cout<<"Overflow\n";
		}
	}

	E Delete()                                              //FUNCTION TO DELETE DATA IN GIVEN ARRAYLIST
	{
	    E temp = dataArray[currentLocation];
		currentLocation--;
		currentSize--;
		return temp;
    }
};

/* CLASS STACK WHICH IS OVER BASIC DATA STRUCTURE FOR PROBLEM
  ARRAYLIST WILL BE AS A VARIABLE IN STACK INSTEAD OF ARRAY SO THAT WE HAVE INBUILT FUNCTIONS */

template <typename E>
class StackArrayList
{
    int stackSize;                  //MAXIMUM SIZE OF STACK
    int currentLocation;            //CURRENT LOCATION IN STACK
    arrayList<E> *stackArray;       //STACKARRAY TO STORE DATA INSERTED

public:

    StackArrayList(int size)                    //CONSTRUCTOR
    {
        stackSize=size;
        currentLocation =0;
        stackArray= new arrayList<E>(size);
    }

    int length()                                            //FUNCTION TO RETURN NUMBER OF ELEMENTS IN STACK
    {
        return stackArray->numberOfElements();
    }


    void push(const E& element)                             //FUNCTION TO PUSH DATA INTO STACK
    {
        stackArray->insert(element);
        currentLocation++;
    }

    E pop()                                                 //FUNCTION TO POP/REMOVE DATA IN THE STACK
    {
        return stackArray->Delete();
    }

    const E& currentElement()                               //FUNCTION TO RETURN TOP OF THE STACK
    {
        return stackArray->getData();
    }
};

// INT MAIN FUNCTION

int main()
{
    Employee employee;

    int size, choice = 0, numberOfEmployees = 0;
    cout<<"Enter Number of Employees (expected): ";             //TAKING MAXIMUM SIZE OF STACK NEEDED
    cin>>size;                                                  //i.e. MAXIMUM NUMBER OF EMPLOYEES

    StackArrayList<Employee> emp(size);                         //DECLARING STACK LIST OF DATA TYPE EMPLOYEE

    while(choice != 4 )                                         //CONTROLLING LOOP OF PROGRAM FEATURING
    {                                                           //MAIN FUNCTIONS OF PROGRAM
        cout<<endl<<"---------------- MENU ----------------"<<endl;
        cout<<endl<<"CHOOSE FROM FOLLOWING:";
        cout<<endl<<"1. Hire an Employee";
        cout<<endl<<"2. Fire an Employee";
        cout<<endl<<"3. Show detail of newest employee";
        cout<<endl<<"4. Exit\n";
        cout<<endl<<"---------------- MENU ----------------"<<endl;
        cout<<endl<<"Enter Choice: ";
        cin>>choice;


        switch(choice)
        {
            case    1:  if(numberOfEmployees < size)                                           //INSERT EMPLOYEE FUNCTION
                        {
                            numberOfEmployees++;
                            cout<<endl<<"Enter Details of Employee "<<numberOfEmployees;
                            employee.getEmployee();

                            emp.push(employee);                                                 //CALLING PUSH FUNCTION
                        }
                        else
                            cout<<endl<<"MAXIMUM NUMBER OF EMPLOYEES EXCEEDED"<<endl;
                        break;

            case    2:  if(numberOfEmployees >= 1)                                              //DELETEING EMPLOYEE
                        {
                            cout<<"\nNewest employee is fired !! \nEmployee details:\n";
                            employee=emp.pop();                                                 //CALLING POP FUNCTION
                            employee.showEmployee();
                            cout<<endl;
                            numberOfEmployees--;
                        }
                        else
                            cout<<endl<<"NO EMPLOYEE TO DELETE"<<endl;
                        break;

            case    3:  if(numberOfEmployees >= 1)                                              //SHOWING MOST RECENT EMPLOYEE
                        {
                            employee = emp.currentElement();
                            employee.showEmployee();
                        }
                        else
                            cout<<endl<<"NO EMPLOYEE EXISTS"<<endl;
                        break;

            default  :  if(choice != 4)
                            {
                                cout<<"WRONG CHOICE ENTERED Please Try Again\n\n";
                            }
                        break;

        }
    }
    return 0;
}
