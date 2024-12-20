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
