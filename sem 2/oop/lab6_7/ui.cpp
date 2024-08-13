#include "ui.h"
#include <iostream>
using std::cin;
using std::cout;

void UI::print_menu() {
    cout<<"1. Add activity\n";
    cout<<"2. Delete activity\n";
    cout<<"3. Modify activity\n";
    cout<<"4. Find activity\n";
    cout<<"5. Filter activity\n";
    cout<<"6. Sort activity\n";
    cout<<"7. Print activities\n";
    cout<<"8. Shopping cart menu\n";
    cout<<"9. Raport\n";
    cout<<"10. Undo\n";
    cout<<"11. Add default\n";
    cout<<"0. Exit\n";
}

void UI::print_cart_menu() {
    cout<<"\nCART MENU\n";
    cout<<"1. Add activity in cart\n";
    cout<<"2. Add random\n";
    cout<<"3. Empty cart\n";
    cout<<"4. Export cart\n";
    cout<<"5. Print cart\n";
    cout<<"6. Back to main menu\n";
}


void UI::add_ui() {
    string name, description, type;
    int time;
    printf("\nEnter a name:");
    cin >> name;
    printf("Enter a description:");
    cin >> description;
    printf("Enter a type:");
    cin >> type;
    printf("Enter a time:");
    cin >> time;
    try{
        srv.add(name, description, type, time);
        printf("\nAdded activity!\n");
    }
    catch (RepoException& rex) {
        cout << rex.get_Message();
    }
    catch (Exception& ex  ) {
        cout << ex.getMessage();
    }

}

void UI::afis_ui(const vector<Activity>& all_elements){

    if (all_elements.size() == 0) {
        printf("\nList empty.\n");
    }
    else {
        printf("\nActivities:\n");
        for (const auto& element : all_elements) {
            cout << " Name: " << element.get_name() << " | Description: " << element.get_description() << " | Type: "
                 << element.get_type() << " | Time: " << element.get_time()<<"\n";
        }

    }

}

void UI::del_ui(){
    int poz = 0;
    printf("\nEnter an index:");
    cin >> poz;
    srv.del(poz);
    printf("\nActivity deleted!");

}

void UI::modify_ui(){
    string name, description, type;
    int time, poz;
    printf("\nEnter an index:");
    cin >> poz;
    printf("Enter a new name:");
    cin >> name;
    printf("Enter a new description:");
    cin >> description;
    printf("Enter a new type:");
    cin >> type;
    printf("Enter a new time:");
    cin >> time;
    try{
        srv.modify(name, description, type, time, poz);
        cout << "Activity modified!";
    }
    catch (RepoException &rex) {
        cout << rex.get_Message();
    }
    catch (Exception& ex) {
        cout << ex.getMessage();
    }
}

void UI::filter_ui() {
    printf("\n1.Description\n2.Type\n");
    printf("Pick a filter type:");
    int cmd;
    cin >> cmd;
    switch (cmd) {
        case 1:{
            printf("Enter a description:");
            string descr;
            cin >> descr;
            vector<Activity> copie;
            srv.filter_descr(descr, copie);
            afis_ui(copie);
            break;

        }
        case 2:{
            printf("Enter a type:");
            string type;
            cin >> type;
            vector<Activity> copie;
            srv.filter_type(type, copie);
            afis_ui(copie);
            break;

        }

        default:{
            cout<<"Invalid command\n";
        }

    }

}

void UI::sort_ui() {
    printf("\n1.Name\n2.Description\n3.Type+Time");
    printf("\nPick a sorting type:");
    int cmd;
    cin >> cmd;
    switch (cmd) {
        case 1: {
            vector<Activity> copy;
            srv.sort_name(copy);
            afis_ui(copy);
        }
        case 2: {
            vector<Activity> copy;
            srv.sort_descr(copy);
            afis_ui(copy);
        }
        case 3: {
            vector<Activity> copy;
            srv.sort_type_time(copy);
            afis_ui(copy);
        }
        default: {
            cout<<"Invalid command\n";
        }

    }
}

void UI::get_ui() {
    printf("\nEnter an index:");
    int poz;
    cin >> poz;
    try{
        const Activity& a = srv.get_activity(poz);
        cout << "Name: " << a.get_name() << " | Description: " << a.get_description() << " | Type: "
             << a.get_type() << " | Time: " << a.get_time();
    }
    catch (RepoException &ex) {
        cout << ex.get_Message();
    }

}

void UI::add_cos_ui() {
    string name;
    cout<<"Enter the name of the activity:";
    cin>>name;
    try {
        srv.add_cart(name);
        cout<<"Activity added\n";
    }
    catch (RepoException& ex) {
        cout<<ex.get_Message();
    }
    catch (Exception& e) {
        cout<<e.getMessage();
    }
}

void UI::empty_cos_ui() {
    srv.empty_cart();
    cout<<"Cart empty\n";
}


void UI::random_ui() {
    int n;
    cout<<"Enter a number for random activities:";
    cin >> n;
    //cin.ignore(1000,'\n');
    try {
        srv.add_random(n);
        cout<<"Added!\n";
    }
    catch (RepoException& ex) {
        cout<<ex.get_Message();
    }
}


void UI::raport_ui() {
    unordered_map<string,ActivityCount> counter = srv.raport();
    for (const auto& pair:counter)
        cout<<"Type:"<<pair.first<<" "<<"Number:"<< pair.second.get_count()<<'\n';
}

void UI::exp_html() {
    string file_name;
    cout<<"Enter a file name:\n";
    cin>>file_name;
    srv.export_html(file_name);
    cout<<"Exported\n";
}

void UI::undo_ui() {
    if(srv.Undo() == -1)
        cout<<"Cant do undo\n";
    else
        afis_ui(srv.get_all());
}
void UI::cart() {
    int cmd;
    int running = 1;
    while(running) {
        print_cart_menu();
        cout<<"Enter command:";
        cin>>cmd;
        switch (cmd) {
            case 1:
                add_cos_ui();
                break;
            case 2:
                random_ui();
                break;
            case 3:
                empty_cos_ui();
                break;
            case 4:
                exp_html();
                break;
            case 5:
                afis_ui(srv.get_all_cart());
                break;
            case 6:
                running = 0;
                break;
            default:
                cout<<"Invalid command\n";
                break;
        }
    }
}

void UI::add_default() {
    try{
        srv.add("coachella","music","festival",8);
        srv.add("oktoberfest","celebration","festival",15);
        srv.add("comiccon","convention","convention",25);
        srv.add("carnival","festivity","festival",10);
        srv.add("tedtalks","inspiration","conference",12);
        srv.add("mardigras","parade","festival",8);
        srv.add("burningman","art","festival",7);
        srv.add("sxsw","multimedia","festival",18);
        srv.add("artbasel","exhibit","fair",4);

    }
    catch (RepoException& ex) {
        cout<<ex.get_Message();
    }

}

void UI::start() {
    int running = 1;
    int cmd;
    //add_default();
    while (running) {
        print_menu();
        cout<<"Enter command:";
        cin>>cmd;
        switch (cmd) {
            case 1:
                add_ui();
                break;
            case 2:
                del_ui();
                break;
            case 3:
                modify_ui();
                break;
            case 4:
                get_ui();
                break;
            case 5:
                filter_ui();
                break;
            case 6:
                sort_ui();
                break;
            case 7:
                afis_ui(srv.get_all());
                break;
            case 8:
                cart();
                break;
            case 9:
                raport_ui();
                break;
            case 10:
                undo_ui();
                break;
            case 11:
                add_default();
                break;
            case 0:
                running = 0;
                break;
            default:
                cout<<"Invalid command\n";
                break;
        }
    }
}