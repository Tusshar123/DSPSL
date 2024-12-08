// simple code 
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Roll {
public:
    int roll;
    string classs;
    string name;
    int attended = 0;
    float opinion = 0;

    void accept(int x) {
        cout << "Student no. " << x << endl;
        cout << "Enter the Roll No.: ";
        cin >> roll;
        cout << "Enter the Class:";
        cin >> classs;

        cout << "Enter the Name:";
        cin.ignore();
        getline(cin, name);
    }

    void display() {
        cout << setw(15) << left << classs
             << setw(15) << left << roll
             << setw(15) << left << name << endl;
    }

    void display2() {
        cout << setw(15) << left << classs
             << setw(15) << left << roll
             << setw(15) << left << name
             << setw(15) << left << opinion << endl;
    }
};

int main() {
    Roll a[20];
    int i, ch, N = 0, temproll, flag, A = 0, count = 0, tempattended, check = 0;
    int q1, q2, q3, q4, q5;
    float total = 0;
    float opi = 0;
    string tempclasss;

    do {
        cout << "\nMenu\n1.Accept\n2.Display\n3.Feed\n4.Display Feed\n5.Search(Using Linear Search)\n6.Search(Using Binary Search)\n7.FeedBack\n8.Display Opinion\n9.Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter the Total No. of Students you are going to Enter: ";
            cin >> N;
            for (i = 0; i < N; i++) {
                a[i].accept(i + 1);
            }
            break;

        case 2:
            cout << setw(15) << left << "Class"
                 << setw(15) << left << "Roll no"
                 << setw(10) << right << "Name" << endl;
            cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

            for (i = 0; i < N; i++) {
                a[i].display();
            }
            break;

        case 3:
            cout << "Enter the Total No. of Students who Attended:";
            cin >> A;

            for (i = 0; i < A; i++) {
                flag = 1;

                cout << "Student no. " << i + 1 << endl;
                cout << "Enter the Roll No.: ";
                cin >> temproll;
                cout << "Enter the Class:";
                cin.ignore();
                getline(cin, tempclasss);
                cout << endl;

                for (int j = 0; j < N; j++) {
                    if (a[j].roll == temproll && (a[j].classs == tempclasss)) {
                        a[j].attended = 1;
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    i--;
                    cout << "Student Not in Database\n";
                }
            }
            break;

        case 4:
            cout << "\nYour Feed is:\n";
            cout << setw(15) << left << "Class"
                 << setw(15) << left << "Roll no" << endl;
            cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

            for (i = 0; i < N; i++) {
                if (a[i].attended == 1) {
                    a[i].display();
                }
            }
            break;

        case 5:
            cout << "Enter the Roll no. of student You want to Search:";
            cin >> temproll;
            cout << "Enter the Class of Student:";
            cin.ignore();
            cin >> tempclasss;
            flag = 1;
            check = 0;

            for (i = 0; i < N; i++) {
                if (temproll == a[i].roll && (a[i].classs == tempclasss)) {
                    if (a[i].attended == 1) {
                        check = 1;
                        cout << "Student Has Attended the Program\n";
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag == 1) {
                cout << "Nope student Didn't Attend\n";
            } else if (check == 0) {
                cout << "\nStudent Didn't found in database\n";
            }
            break;

        case 6:
            int low, mid, high;

            for (i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j].roll > a[j + 1].roll) {
                        temproll = a[j].roll;
                        a[j].roll = a[j + 1].roll;
                        a[j + 1].roll = temproll;

                        tempclasss = a[j].classs;
                        a[j].classs = a[j + 1].classs;
                        a[j + 1].classs = tempclasss;

                        tempattended = a[j].attended;
                        a[j].attended = a[j + 1].attended;
                        a[j + 1].attended = tempattended;
                    }
                }
            }

            cout << "\nYour Sorted Feed is:\n";
            for (i = 0; i < N; i++) {
                if (a[i].attended == 1) {
                    a[i].display();
                }
            }

            high = N - 1;
            low = 0;
            mid = (low + high) / 2;

            flag = 0;

            cout << "Enter the Roll no. of student You want to Search:";
            cin >> temproll;
            cout << "Enter the Class of Student:";
            cin >> tempclasss;

            check = 0;

            while (low <= high) {
                if (temproll == a[mid].roll && (a[mid].classs == tempclasss)) {
                    if (a[mid].attended == 1) {
                        cout << "Student Has Attended the Program\n";
                        flag = 1;
                        check = 1;
                        break;
                    }
                } else if (temproll > a[mid].roll) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
                mid = (low + high) / 2;
            }
            if (flag == 0) {
                cout << "\nStudent Didn't Attend the Program\n";
            } else if (check == 0) {
                cout << "\nStudent Didn't found in database\n";
            }
            break;

        case 7:
            for (i = 0; i < N; i++) {
                if (a[i].attended == 1) {
                    q1 = q2 = q3 = q4 = q5 = 0;
                    opi = 0;
                    float average = 0;
                    cout << "Student " << i + 1 << endl;
                    cout << "1. Do you think the Training Program was worth it?\n";
                    cout << "(1) Yes\n(0) No\n";
                    cin >> q1;
                    cout << "2. Do you think the college made proper use of your precious time by inviting the respective Guest?";
                    cout << "\n(1) Yes\n(0) No\n";
                    cin >> q2;
                    cout << "Do you think we were doing time pass, by calling you on a holiday???";
                    cout << "\n(0) Yes\n(1) No\n";
                    cin >> q3;
                    cout << "Did you get the gist of the trainer's lecture or were you sleeping??\n";
                    cout << "(1) Yes\n(0) No\n";
                    cin >> q4;
                    cout << "Shall we force you again for such programs in the future again?\nNote: not like your choice matters";
                    cout << "\n(1) Yes\n(0) No\n";
                    cin >> q5;

                    opi = q1 + q2 + q3 + q4 + q5;
                    average = (opi / 5) * 100;
                    cout << average;
                    a[i].opinion = average;
                    total += opi;
                }
            }
            break;

        case 8:
            cout << "\nAttended Students' Opinion is:\n";
            cout << setw(15) << left << "Class"
                 << setw(15) << left << "Roll"
                 << setw(15) << left << "Name"
                 << setw(15) << left << "Opinion(out of 100)" << endl;

            for (i = 0; i < N; i++) {
                if (a[i].attended == 1) {
                    a[i].display2();
                }
            }

            if (((total / (A * 5)) * 100) >= 70) {
                cout << "Students Are Interested in such Future Programs...\n";
                cout << ((total / (A * 5)) * 100) << " was the Percentile";
            } else {
                cout << "Students Not Interested...\n";
                cout << ((total / (A * 5)) * 100) << " was the Percentile";
            }
            break;

        case 9:
            break;

        default:
            cout << "Wrong Choice...\n";
            break;
        }

    } while (ch != 9);

    return 0;
}




 
/*
	Assignment 3: checking students have attended the training program or not.
*/
#include<iostream>//Header file 
#include<cstring>
using namespace std;

class student
{
public:
    int rollno;
    string name,branch,div,tn;

    void accept()//Accepting th data from the user
    {
        cout << "Enter the roll no of the student: ";
        cin >> rollno;
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the branch of the student: ";
        cin >> branch;
        cout << "Enter the class of the student: ";
        cin >> div;
        cout << "Enter the name of training program which student have done: ";
        cin >> tn;
    }

    void display()//Display the data of the student
    {
        cout << "\n\nThe roll no of the student is: "<<rollno<<endl;
        cout << "The name of the student is: "<<name<<endl;
        cout << "The branch of the student is: "<<branch<<endl;
        cout << "The class of the student is: "<<div<<endl;
        cout << "The name of training program which student have attended is: "<<tn<<endl;
       
    }

    static void linearsearch(int n,int r,student s[])//Searching the student present for the training program or not using linear search
    {
        int i;
        int flag=0;
        for(int i=0;i<n;i++)
        {
           if(s[i].rollno==r)
           {
               flag=1;
               cout<<"\nThe Data of the student who attended the training program is :"<<endl;
               s[i].display();
            }
        }      
        if(flag==0)
        {
            cout<<"\nStudent was not present for the training program.\n";
        }
    }
    
    void bubblesort(int n, student s[])//code for bubble sort
    {
        int t1;
        string t2,t3,t4,t5;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (s[j].rollno > s[j + 1].rollno)
                {
                    t1 = s[j].rollno;
                    s[j].rollno = s[j + 1].rollno;
                    s[j + 1].rollno = t1;

                    t2 = s[j].name;
                    s[j].name = s[j + 1].name;
                    s[j + 1].name = t2;
                    
                    t3 = s[j].branch;
                    s[j].branch = s[j + 1].branch;
                    s[j + 1].branch = t3;
                    
                    t4 = s[j].div;
                    s[j].div = s[j + 1].div ;
                    s[j + 1].div = t4;
                    
                    t5 = s[j].tn;
                    s[j].tn = s[j + 1].tn;
                    s[j + 1].tn = t5;
                }
            }
        }
    }
    
    static void binarysearch(int n,int r,student s[])//searchin with binary search function
    {
        int low = 0, high = n - 1;
        int flag=0;
   
        while(low<=high)
        {
            int mid =(high + low)/ 2;
   
            if (s[mid].rollno == r)
            {
                cout<<"\nThe Data of the student who attended the training program is :\n"<<endl;
                s[mid].display();
                flag=1;
                break;
            }
                           
            else if (s[mid].rollno < r)
                low = mid + 1;      
            else
                high = mid - 1; 
                   
        }
        if(flag==0)
        {
            cout<<"\nStudent was not present for the training program.\n";
        }
    }
   
}s[100];

int main()//Main function
{
 
    int n;
    int r;
    int choice;

    while (true)
    {
        cout << "\n\n--- Menu ---";
        cout << "\n1. Add the data of students who attended the training program";
        cout << "\n2. Display the data of students who attended the training program";
        cout << "\n3. Search wheather the perticular student attented the training program or not with linear search";
        cout << "\n4. Search wheather the perticular student attented the training program or not with linear search";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the number of students who attended the training program:";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    s[i].accept();
                }
                break;

            case 2:
                cout<<"\nThe data of students who attended the training program is as follows:"<<endl;
                for (int i = 0; i < n; i++)
                {
                    s[i].display();
                }
                break;


            case 3:
                cout<<"\nEnter the roll no of student to check he/she attended the training program or not:";
                cin>>r;
                student::linearsearch(n,r,s);
                break;
           
            case 4:
                n = sizeof(s) / sizeof(s[0]);
                cout<<"\nEnter the roll no of student to check he/she attended the training program or not:";
                cin>>r;
                for (int i = 0; i < n; i++)
                {
                    s[i].bubblesort(n, s);
                }
                student::binarysearch(n,r,s);
                break;

            case 5 :
                cout << "\nExiting program.\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 4.";
        }
    }
}


 
