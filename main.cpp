#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "class.hpp"


int main(){
    cout<<"Welcome to our Invoice Management System! We will help you produce your invoice in CSV format. \n";
    to a;
    send b;
    List c;
    invoice d;
    char choice;
    b.send_setdeets();
    a.to_setdeets();
    int num1=0;
    cout<<"Welcome"<<endl;
    main_menu:cout<<"\n1. Sender's address\n2. Biller's address\n3. Add Listing"<<endl;
    cin>>choice;

        switch(choice){
        case '1':
            sender_menu:cout<<"\n1. Edit address\n2. Display address"<<endl;
            cin>>choice;

            switch(choice){
            case '1':
                b.send_editdeets();
                goto main_menu;

            case '2':
                b.send_disp();
                goto main_menu;

            default:
                cout<<"\n Enter a valid option"<<endl;
                goto sender_menu;
            }
            break;
        case '2':
            if(num1==0){
                a.to_setdeets();
                num1++;
            }
            to_menu:cout<<"\n1. Edit address\n2. Display address"<<endl;
            cin>>choice;

            switch(choice){
            case '1':
                a.to_editdeets();
                goto main_menu;

            case '2':
                a.to_disp();
                goto main_menu;

            default:
                goto to_menu;
            }
            break;
        case '3':
            c.add_list();
            goto second_menu;
        default:
            cout << "Invalid choice. Please try again." << endl;
            goto main_menu;
        }


    second_menu:cout<<"\n1. Sender's address\n2. Biller's address\n3. Add Listing\n4. Edit listing\n5. Remove listing\n6. Exit"<<endl;
    cin>>choice;

        switch(choice){
        case '1':
            send_menu:cout<<"\n1. Edit address\n2. Display address"<<endl;
            cin>>choice;

            switch(choice){
            case '1':
                b.send_editdeets();
                goto second_menu;

            case '2':
                b.send_disp();
                goto second_menu;

            default:
                cout<<"\n Enter a valid option"<<endl;
                goto send_menu;
            }
            break;
        case '2':
            to2_menu:cout<<"\n1. Edit address\n2. Display address"<<endl;
            cin>>choice;

            switch(choice){
            case '1':
                a.to_editdeets();
                goto second_menu;

            case '2':
                a.to_disp();
                goto second_menu;

            default:
                goto to2_menu;
            }
            break;
        case '3':
            c.add_list();
            goto second_menu;
         case '4':
            c.display_all_listings();
            if (c.hasListings()) {
                cout << "Enter the index of the listing to edit: ";
                int edit_index;
                cin >> edit_index;
                c.edit_list(edit_index);
            }
            goto second_menu;
        case '5':
            c.display_all_listings();
            if (c.hasListings()) {
                cout << "Enter the index of the listing to remove: ";
                int remove_index;
                cin >> remove_index;
                c.remove_listing(remove_index);
            }
            goto second_menu;
        case '6':
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            goto second_menu;
        }
    cout<<"Generating Invoice"<<endl;
    d.generate_invoice(a,b,c);
}
