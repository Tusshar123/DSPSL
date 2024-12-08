#include<iostream>
#include<cstring>
using namespace std;

class book {
    public:
        int price;
        string title;

        void accept() {
            cout << "Enter Title of Book: ";
            cin >> title;
            cout << "Enter Price of Book: ";
            cin >> price;
        }

        void display() {
            cout << "|" << title << "\t|" << price << endl;
        }
};

int main() {
    book b[10], a[10], c[10];
    int ch, i, n, n1 = 0, count = 0, tuk = 0;

    do {
        cout << "Enter Your Choice:\n"
             << "1. Accept New Lot\n"
             << "2. Display\n"
             << "3. Sort in Decending Order\n"
             << "4. Displaying Books Less than 500\n"
             << "5. Books Having Price Greater Than 500\n"
             << "6. Deleting Duplicate Books\n"
             << "7. Duplicate Books\n"
             << "8. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter the Lot Size: ";
                cin >> n;

                for (i = 0; i < n; i++) {
                    b[i].accept();
                }
                break;
            }

            case 2: {
                cout << "|Title\t|Price" << endl;
                for (i = 0; i < n; i++) {
                    b[i].display();
                }
                break;
            }

            case 3: {
                count = 0;

                for (i = 0; i < n; i++) {
                    for (int j = 0; j < n - 1; j++) {
                        if (b[j].price < b[j + 1].price) {
                            int temp = b[j].price;
                            b[j].price = b[j + 1].price;
                            b[j + 1].price = temp;

                            string temp2 = b[j].title;
                            b[j].title = b[j + 1].title;
                            b[j + 1].title = temp2;
                        }
                    }

                    if (b[i].price <= 500) {  // Copying in Another Array: Books Less than 500 rupees
                        a[n1].price = b[i].price;
                        a[n1].title = b[i].title;
                        n1 += 1;
                    } else {
                        count += 1;  // Counting Count of Books Greater than 500 rupees
                    }
                }

                cout << "Books Arranged As per Descending Order: " << endl;
                cout << "|Title\t|Price" << endl;
                for (i = 0; i < n; i++) {
                    b[i].display();
                }
                break;
            }

            case 4: {
                cout << "Cost of Book less than 500: " << endl;
                cout << "|Title\t|Price" << endl;
                for (i = 0; i < n1; i++) {
                    a[i].display();
                }
                break;
            }

            case 5: {
                cout << "Books Having Price Greater Than 500 Are: " << count << endl << endl;
                break;
            }

            case 6: {
                for (i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if ((b[i].title.compare(b[j].title)) == 0) {
                            c[tuk].title = b[j].title;
                            c[tuk].price = b[j].price;
                            tuk += 1;

                            for (int k = j; k < n - 1; k++) {
                                b[k].title = b[k + 1].title;
                                b[k].price = b[k + 1].price;
                            }

                            n--;
                            j--;
                        }
                    }
                }
                break;
            }

            case 7: {
                cout << "Array of Duplicate Books is:\n";
                cout << "|Title\t|Price" << endl;
                for (i = 0; i < tuk; i++) {
                    c[i].display();
                }
                break;
            }

            default:
                break;
        }
    } while (ch != 8);

    return 0;
}