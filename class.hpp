#include <iostream>
#include <string>
#include<fstream>
#include<stdlib.h>
using namespace std;

class invoice;

class address{
    protected:
    string street;
    string house;
    string city;
    string country;
    void setdet(){
        cout<<"Please enter the house location: ";
        getline(cin,house);
        cout<<"Please enter the street name: ";
        getline(cin, street);
        cout<<"Please enter city/state name, along with pin code: ";
        getline(cin, city);
        cout<<"Please enter the country name: ";
        getline(cin, country);
    };
    void editdet(){
        cout<<"You will now choose what part of the address you wish to edit: \n";
        cout<<"1. House \n2. Street \n3. City/State & Pin Code \n4. Country \nPlease enter your choice: ";
        int choice=0;
        while (choice<1||choice>5){
            cin>>choice;
            switch (choice)
            {
            case 1:
                cout<<"Enter the new house details: ";
                getline(cin, house);
                getline(cin, house);
                break;
            case 2:
                cout<<"Enter the new street name: ";
                getline(cin, street);
                getline(cin, street);
                break;
            case 3:
                cout<<"Enter the new city/state name with the pin code: ";
                getline(cin, city);
                getline(cin, city);
                break;
            case 4:
                cout<<"Enter the new country name: ";
                getline(cin, country);
                getline(cin, country);
                break;
            default:
                cout<<"Incorrect choice option chosen! Please retry: ";
                break;
            }
        }
    };
    void display(){
        cout<<house<<endl;
        cout<<street<<endl;
        cout<<city<<endl;
        cout<<country<<endl<<endl;
    }
    friend class invoice;
};

class to: public address{
    string name;
    public:
    friend class invoice;
    void to_setdeets(){
        cout<<"You will now be expected to enter the details of the bill-to address."<<endl;
        cout<<"Please enter the name: ";
        getline(cin, name);
        setdet();
    };
    void to_disp(){
        cout<<"The biller's address is: \n\n";
        cout<<name<<"\n";
        display();
    };
    void to_editdeets(){
        cout<<"Before we move on, please read the current address and details: ";
        this->to_disp();
        int choice=0;
        cout<<"You have entered the editing address menu. Please select an option: \n";
        cout<<"1. Name \n2. Address \nChoice: ";
        while(choice<1||choice>3){
            cin>>choice;
            switch (choice)
            {
            case 1:
                cout<<"Please enter the new billing company/proprietor: ";
                getline(cin, name);
                getline(cin, name);
                break;
            case 2:
                editdet();
                break;
            default:
                cout<<"Incorrect menu option was entered. Please retry. \n";
                break;
            }
        }
        cout<<"The details were changed as required.";
    }
};

class send: public address{
    friend class invoice;
    string name;
    public:
    void send_setdeets(){
        cout<<"You will now be expected to enter the details of the sender's address."<<endl;
        cout<<"Please enter the name: ";
        getline(cin, name);
        setdet();
    };
    void send_disp(){
        cout<<"The sender's address: \n\n";
        cout<<name<<"\n";
        display();
    };
    void send_editdeets(){
        cout<<"Before we move on, please read the current address and details: ";
        this->send_disp();
        int choice=0;
        cout<<"You have entered the editing address menu. Please select an option: \n";
        cout<<"1. Name \n2. Address \nChoice: ";
        while(choice<1||choice>3){
            cin>>choice;
            switch (choice)
            {
            case 1:
                cout<<"Please enter the new billing company/proprietor: ";
                getline(cin, name);
                getline(cin, name);
                break;
            case 2:
                editdet();
                break;
            default:
                cout<<"Incorrect menu option was entered. Please retry. \n";
                break;
            }
        }
        cout<<"The details were changed as required.";
    }
};

class Listing {
protected:
    string item_name;
    double item_cost;
    int item_quantity;
    double total_price;

public:
    friend class invoice;
    void read_details() {
        char cost[50];
        char quantity[50];
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, item_name);
        costre:
        cout << "Enter item cost: ";

        cin >> cost;
        if(atoi(cost)){
            item_cost=atoi(cost);
        }else{
            cout<<"Invalid entry! Please retry. \nDon't panic, it's organic!\n";
            goto costre;
        }
        quantre:
        cout << "Enter item quantity: ";
        cin >> quantity;
        if(atoi(quantity)){
            item_quantity=atoi(quantity);
        }else{
            cout<<"Invalid entry! Please retry. \nDon't panic, it's organic!\n";
            goto quantre;
        }
    }

    void process_details() {
        total_price = item_quantity* item_cost;
    }

    void print_details() {
        cout << "Item Name: " << item_name << endl;
        cout << "Item Cost: Rs." << item_cost << endl;
        cout << "Item Quantity: " << item_quantity << endl;
        cout << "Total Price: Rs." << total_price << endl;
    }
    friend class invoice;
};

class List {
protected:
    Listing list[200];
    int count;
    bool has_listings;

public:
    friend class invoice;
    List() {
        count = 0;
        has_listings = false;
    }

    void add_list() {
        if (count < 200) {
            Listing new_listing;
            new_listing.read_details();
            new_listing.process_details();
            list[count++] = new_listing;
            has_listings = true;
        }
        else {
            cout << "List is full. Cannot add more listings." << endl;
        }
    }

    void edit_list(int in) {
        if (hasListings()) {
            if (in-1 >= 0 && in-1 < count) {
                list[in-1].read_details();
                list[in-1].process_details();
            }
            else {
                cout << "Invalid index." << endl;
            }
        }
        else {
            cout << "No listings added. Please add a listing first." << endl;
        }
    }

    void remove_listing(int in) {
        if (hasListings()) {
            if (in-1 >= 0 && in-1 < count) {
                for (int i = in; i < count - 1; ++i) {
                    list[i] = list[i + 1];
                }
                count--;
                cout<<"Removed listing!"<<endl;
            }
            else {
                cout << "Invalid index." << endl;
            }
        }
        else {
            cout << "No listings added. Please add a listing first." << endl;
        }
    }

    void display_all_listings() {
        if (hasListings()) {
            for (int i = 0; i < count; ++i) {
                cout << "Listing " << i + 1 << ":" << endl;
                list[i].print_details();
                cout << endl;
            }
        }
        else {
            cout << "No listings added yet." << endl;
        }
    }

    bool hasListings() const {
        return has_listings;
    }
};

class invoice{
    int choice;
    double total_amount=0;
public:
    void generate_invoice(to toad, send sendad, List lister){
        cout<<"Please ensure that you change the location of the generated invoice once produced or rename it. It may be overwritten if it remains there.\n";
        string name;
        int id;
            cout<<"Enter name: ";
            getline(cin, name);
            getline(cin,name);
            cout<<"Enter ID number: ";
            cin>>id;
            ofstream ffout;
            ffout.open("log.csv",ios::app);
            ffout<<name<<","<<id<<endl;
            ffout.close();
        ofstream fout;
        fout.open("invoice_sheet.csv");
        if(fout.fail()){
                fout.close();
                cout<<"There was an error opening the file"<<endl;
                exit(1);
            }
        fout<<"Bill To:"<<endl;
        fout<<toad.name<<endl<<toad.house<<endl<<toad.street<<endl<<toad.city<<endl<<toad.country<<endl<<endl;
        fout<<"Description"<<","<<"Quantity"<<","<<"Rate"<<","<<"Amount"<<endl;
        int counter=lister.count;
        for(int i=0;i<counter;i++){
            fout<<lister.list[i].item_name<<","<<lister.list[i].item_quantity<<","<<lister.list[i].item_cost<<","<<lister.list[i].total_price<<endl;
        }
        for(int i=0;i<counter;i++){
            total_amount+=lister.list[i].total_price;
        }
        fout<<"Total"<<","<<","<<","<<total_amount<<endl<<endl;
        fout<<"Sent By:"<<endl;
        fout<<sendad.name<<endl<<sendad.house<<endl<<sendad.street<<endl<<sendad.city<<endl<<sendad.country<<endl<<endl;
        fout.close();
    }
};
