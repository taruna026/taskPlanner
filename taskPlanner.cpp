#include <iostream>
#include <bits/stdc++.h>

enum severity:char{P0, P1, P2};
struct sprint{
    char name[50];
    char startDate[50];
    char endDate[50];
};
struct task{
    char title[50];
    char creator[50];
    char asignee[50];
    char status[20];
    char dueDate[20];
    char type[20];
    struct feature;
    struct bug;
    struct story;
    sprint s;
};

struct feature{
    char featureSummary[50];
    char Impact[20];
};
struct bug{
    severity sev;
};
struct story{
    char storySummary[50];
    char points[10]; 
};

task tasks[1000];
int n=0;

void addTask(){
    char ch[10];
    do
    {
        system("cls");
        cout << endl;
        cout << "-------------------Adding a Task-------------------\n";

        
        cout << "Enter task creator name: \n";
        scanf("%s", tasks[n].creator);
        cout << "Enter task title: \n";
        scanf("%s", tasks[n].title);
        cout << "Enter task assignee name: ";
        scanf("%s", tasks[n].asignee);
        cout << "Enter task status: ";
        scanf("%s", tasks[n].status);
        cout << "Enter task Type: ";
        scanf("%s", tasks[n].type);
        cout << tasks[n].type << endl;
        if(strcmp(tasks[n].type, "Feature") == 0){
            feature f;
            cout << "Enter feature summary: ";
            scanf("%s", f.featureSummary);
            cout << "Enter feature impact: ";
            scanf("%s", f.Impact);
        }
        if(strcmp(tasks[n].type, "Bug") == 0){
            bug b;
            cout << "Enter bug severity: ";
            scanf("%d", b.sev);
        }
        if(strcmp(tasks[n].type, "Story") == 0){
            story s;
            cout << "Enter story summary: ";
            scanf("%s", s.storySummary);
            cout << "Enter story points: ";
            scanf("%s", s.points);
        }
        cout << "Enter task due date: ";
        scanf("%s", tasks[n].dueDate);
        cout << "Enter task status: ";
        scanf("%s", tasks[n].s.name);
        n++;
        cout << "Do you want to add more task?(y/n): ";
        scanf("%s", ch);
    } while (*ch!='n');
    
}

void changeTaskStatus(char *title){
    cout << "Changing status of a task by title" << endl;
    for(int i=0; i<n; i++){
        if(strcmp(tasks[i].title, title) == 0){
            cout << "Enter new status: ";
            scanf("%s", tasks[i].status);
            cout << "Task updated successfully.";
        }
    }
}

void changeTaskAssignee(char *title){
    cout << "Changing status of a task by title" << endl;
    for(int i=0; i<n; i++){
        if(strcmp(tasks[i].title, title) == 0){
            cout << "Enter new assignee: ";
            scanf("%s", tasks[i].asignee);
            cout << "Task updated successfully.";
        }
    }
}

void updateTask(){
    char title[50];

    cout << "Updating a task by title" << endl;
    cout << "Enter title you need to modify: " << endl;
    gets(title);
    cout << "1. Change status of task\n";
    cout << "2. Change assignee of task\n";

    switch (getchar())
    {
    case '1':
        changeTaskStatus(title);
        break;

    case '2':
        changeTaskAssignee(title);
        break;
    
    default:
        break;
    }
}

void displayTask(){
    cout << "----Displaying all the tasks-----\n";
    for(int i=0; i<n; i++){
        cout << "Title: " << tasks[i].title << " " << "Status: " << tasks[i].status << endl;
    }
}

int main(){
    char ch;
    {
        cout << "TASK PLANNER" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Update a task" << endl;
    cout << "3. Display the tasks" << endl;
    switch (getchar())
    {
    case '1':
        addTask();
        break;

    case '2':
        updateTask();
        break;

    case '3':
        displayTask();
        break;
    
    default:
        break;
    }
    }
    return 0;
}