/*      NAME: SHREYANSH
        ID  : 201601112
*/

#include<iostream>

using namespace std;

class toDoList                                                                //CLASS TODOLIST TO STORE TODO ACTIVITIES
{
    int priority;                                       //STORE PRIORITY OF ACTIVITY
    string activity;                                    //STORE ACTIVITY
    string description;                                 //STORE DESCRIPTION OF ACTIVITY

public:

    toDoList *next;                                     //STORE NEXT TO DO ACTIVITY

                                                        //SETTER FUNCTIONS

    void setActivity(string activity)          {   this->activity = activity;          }
    void setDescription(string description)    {   this->description = description;  }
    void setPriority(int priority)             {   this->priority = priority;          }

                                                        //GETTER FUNCTIONS

    string getActivity()       {   return activity;    }
    string getDescription()    {   return description; }
    int getPriority()          {   return priority;    }

    toDoList()                                                                      //CONSTRUCTOR
    {
        priority = 0;
        activity = "";
        description = "";
        next = NULL;
    }

    toDoList(const toDoList &lst)                                                   //COPY CONSTRUCTOR
    {
        priority = lst.priority;
        activity = lst.activity;
        description = lst.description;
        next = lst.next;
    }

    toDoList(string activity, string description, int priority)                     //CONSTRUCTOR WITH PARAMETERS
    {
        this->activity = activity;
        this->description = description;
        this->priority = priority;
        next = NULL;
    }

    void showToDoList()                                                             //FUNCTION TO SHOW TO DO ACTIVITY
    {
        cout<<endl<<"Activity   :\t"<<getActivity();
        cout<<endl<<"Description:\t"<<getDescription()<<endl;
    }

    void setToDoList()                                                              //FUNCTION TO SET TO DO ACTIVITY
    {
        cout<<endl<<"Enter Priority\n\t1. administrative\n\t2. academic\n\t3. research\n\t4. teaching\nPriority: ";
        cin>>priority;

        if(priority == 1)        setActivity("Administrative");                     //SETTING ACTIVITY ACC TO PRIORITY
        if(priority == 2)        setActivity("Academic");
        if(priority == 3)        setActivity("Research");
        if(priority == 4)        setActivity("Teaching");

        cout<<"Enter Activity's Description: \n";
        cin.ignore();
        getline(cin,description);
    }
};

//MAIN DATA STRUCTURE - QUEUE CLASS TO ENSURE PRIORITY IN ACTIVITIES NEED TO BE DONE

class queueLinkList
{
    toDoList *first = NULL;         //POINTER STORING FIRST(MOST PRIOR) ACTIVITY THAT NEED TO BE DONE IN LINK LIST

public:
    queueLinkList()                 //CONSTRUCTOR
    {
        first = NULL;
    }

    void enterInTodo(string activity, string description, int priority)         //ADDING IN QUEUE W.R.T PRIORITY OF ACTIVITY
    {
        toDoList *temp = new toDoList(activity,description,priority);           //CREATING NEW TODOLIST VARIABLE

        if(first == NULL)                                                       //IF FIRST ELEMENT IS NULL
        {
            first = temp;
            first->next = NULL;
            return;
        }

        else if(first->next == NULL)                                            //IF NOT THEN ADDING USING PRIORITY OF TASKS
        {
            if(priority > first->getPriority())
            {
                temp->next = first;
                first = temp;
                return;
            }
            else
            {
                first->next = temp;
                temp->next = NULL;
                return;
            }
        }

        else                                // WHEN FIRST AND ITS NEXT BOTH ARE NOT NULL, SEARCHING FOR POSITION AND ADDING
        {
            toDoList *tmp = first;

            if(priority > tmp->getPriority())
            {
                temp->next = first;
                first = temp;
                return;
            }

            if(priority == tmp->getPriority())
            {
                while(tmp->next != NULL && priority == tmp->next->getPriority())
                {
                    tmp = tmp->next;
                }
                temp->next = tmp->next;
                tmp->next = temp;
                return;
            }

            if(priority < tmp->getPriority())
            {
                while(tmp->next != NULL && priority <= tmp->next->getPriority())
                {
                    tmp = tmp->next;
                }

                temp->next = tmp->next;
                tmp->next = temp;
                return;
            }
        }
    }

    toDoList * completeTask()                                   //FUNCTION TO REMOVE ACTIVITY WHICH HAS BEEN COMPLETED
    {
        toDoList *temp = first;
        first = first->next;
        return temp;
    }

    toDoList * nextPendingTask()                                //FUNCTION TO RETURN NEXT ACTIVITY WHICH NEED TO BE DONE
    {
        return first;
    }

    void displayAllTasks()                                      //FUNCTION TO SHOW ALL THE ACTIVITIES PRESENT IN THE LIST
    {
        toDoList *temp = first;
        int i=1;
        while(temp != NULL)
        {
            cout<<"TASK       :\t"<<i<<endl;
            cout<<"Activity   :\t"<<temp->getActivity()<<endl;
            cout<<"Description:\t"<<temp->getDescription()<<endl<<endl;
            temp = temp->next;
            i++;
        }
    }
};

// INT MAIN

int main()
{
    queueLinkList todoList;                 //LINK LIST FOR STORING TO DO ACTIVITIES
    toDoList tdList, *List;                 //LIST FOR POINTING TO ACTIVITIES AND PRIORITES

    int choice = 0, numberOfTasks = 0;
    while(choice != 5)                                  //CONTROLLING LOOP WITH MENU FOR DIFFERENT FUNCTIONS
    {
        cout<<endl<<"---------------- MENU ----------------"<<endl;
        cout<<endl<<"CHOOSE FROM FOLLOWING:";
        cout<<endl<<"1. Add new Task in the List";
        cout<<endl<<"2. See next pending Task";
        cout<<endl<<"3. Complete the next pending Task";
        cout<<endl<<"4. Display all the pending Tasks";
        cout<<endl<<"5. Exit\n";
        cout<<endl<<"---------------- MENU ----------------"<<endl;
        cout<<endl<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
        case    1:  numberOfTasks++;                                               //CALLING FUNCTION TO ADD TO TO DO LIST
                    cout<<"Enter details of Task: "<<numberOfTasks<<endl;
                    tdList.setToDoList();
                    todoList.enterInTodo( tdList.getActivity(), tdList.getDescription(), tdList.getPriority() );
                    cout<<endl<<"TASK ADDED SUCCESSFULLY"<<endl;
                    break;

        case    2:  if(numberOfTasks > 0)                                       //SHOWING NEXT TASK TO DO
                    {
                        List = todoList.nextPendingTask();
                        List->showToDoList();
                    }
                    else
                        cout<<endl<<"No Next Task Exists"<<endl;
                    break;

        case    3:  if(numberOfTasks > 0)                                       //COMPLETEING THE NEXT TAST i.e DELETING
                    {
                        cout<<endl<<"Following Task is Done:"<<endl;
                        List = todoList.completeTask();
                        List->showToDoList();
                        numberOfTasks--;
                    }
                    else
                        cout<<endl<<"NO TASK TO COMPLETE"<<endl;
                    break;

        case    4:  if(numberOfTasks > 0)                                       //SHOWING ALL THE ACTIVITIES IN TO DO LIST
                    {
                        cout<<endl<<"ALL TASKS IN THEIR SEQUENCE TO BE COMPLETED:"<<endl<<endl;
                        todoList.displayAllTasks();
                    }
                    else
                        cout<<endl<<"NO TASKS TO SHOW"<<endl;
                    break;

        default  :  if(choice != 5)
                        cout<<endl<<"WRONG CHOICE GIVEN.. PLEASE TRY AGAIN"<<endl;
                    break;
        }
    }
    return 0;
}


