#ifndef LAB6_7_UI_H
#define LAB6_7_UI_H
#include "Service.h"
class UI
{

    Service& srv;
public:
    UI(Service& srv) :srv{ srv }{
    }
    UI(const UI& ot) = delete;
    void start();
    void add_ui();
    void del_ui();
    void modify_ui();
    void filter_ui();
    void sort_ui();
    void get_ui();
    void afis_ui(const vector<Activity>& all_elements);
    void random_ui();
    void exp_html();
    void empty_cos_ui();
    void add_cos_ui();
    void raport_ui();
    void print_menu();
    void print_cart_menu();
    void cart();
    void add_default();
    void undo_ui();
};
#endif //LAB6_7_UI_H
