#include "Service.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <memory>

void Service::add(string name, string description, string type, int time){
    valid.validateActivity(name,description,type,time);
    const Activity& a{name, description, type, time};
    rep.store(a);
    undo.push_back(make_unique<AddUndo>(rep, a));
}

void Service::del(const Activity& act){
    valid.validateActivity(act.get_name(), act.get_description(), act.get_type(), act.get_time());
    rep.remove(act);
    undo.push_back(make_unique<DeleteUndo>(rep,act));
}


void Service::modify(const Activity& act_rm, const Activity& act){
    valid.validateActivity(act.get_name(), act.get_description(), act.get_type(), act.get_time());
    valid.validateActivity(act_rm.get_name(), act_rm.get_description(), act_rm.get_type(), act_rm.get_time());

    rep.modify(act_rm, act);
    undo.push_back(make_unique<ModifyUndo>(rep, act_rm, act));
}


void  Service::filter_type(string type, vector<Activity>& filtered) {
    const vector<Activity>& all = rep.get_all();
    std::copy_if(all.begin(), all.end(), back_inserter(filtered),[type](const Activity& a) {
        return a.get_type() == type;
    });
}

void Service::filter_descr(string descr, vector<Activity>& filtered) {
    const vector<Activity>& all = get_all();
    std::copy_if(all.begin(), all.end(), back_inserter(filtered),[descr](const Activity& a) {
        return a.get_description() == descr;
    });
}

bool compare_name(const Activity& a1, const Activity& a2) {
    return a1.get_name() < a2.get_name();
}

bool compare_descr(const Activity& a1, const Activity& a2) {
    return a1.get_description() < a2.get_description();
}

bool compare_type_time(const Activity& a1, const Activity& a2) {
    if(a1.get_type() == a2.get_type())
        return a1.get_time() < a2.get_time();
    return a1.get_type() < a2.get_type();
}

void Service::sort_name(vector<Activity>& copy) {
    copy = rep.get_all();
    std::sort(copy.begin(), copy.end(), compare_name);
}

void Service::sort_descr(vector<Activity>& copy) {
    copy = rep.get_all();
    std::sort(copy.begin(), copy.end(), compare_descr);
}

void Service::sort_type_time(vector<Activity>& copy) {
    copy = rep.get_all();
    std::sort(copy.begin(), copy.end(), compare_type_time);
}

const Activity* Service::get_activity(const string& name, const string& descr, const string& type, int time) {
    return rep.get_activity(name, descr, type, time);
}


void Service::add_cart(string name) {
    const auto& activity= rep.find_act_name(name);
    cart.add_cart(activity);
}


int Service::add_random(int n) {
    cart.random_activity(n, this->get_all());
    return cart.get_all_cart().size();
}

void Service::empty_cart() {
    cart.empty();
}

const vector<Activity>& Service::get_all_cart() {
    return cart.get_all_cart();
}

std::unordered_map<string ,ActivityCount> Service::raport() const {
    std::unordered_map<string , ActivityCount> counter;
    const vector<Activity> activities = rep.get_all();

    for(const auto& activity:activities)
        counter[activity.get_type()].IncrementCount();

    return counter;
}

void Service::export_html(const string& file_name) {
    std::ofstream file(file_name);

    file << "<html>\n";
    file << "<head><title>Export cart</title></head>\n";
    file << "<style>\n";
    file << "body {";
    file << "    background-color: #FCE4EC;";
    file << "    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;";
    file << "}";
    file << "h1 {";
    file << "    color: #9C27B0;";
    file << "}";
    file << "table {";
    file << "    border-collapse: collapse;";
    file << "    width: 100%;";
    file << "    border-radius: 8px;";
    file << "}";
    file << "th, td {";
    file << "    padding: 12px;";
    file << "    text-align: left;";
    file << "}";
    file << "th {";
    file << "    background-color: #E1BEE7;";
    file << "    color: #9C27B0;";
    file << "}";
    file << "tr:nth-child(even) {";
    file << "    background-color: #F8BBD0;";
    file << "}";
    file << "tr:hover {";
    file << "    background-color: #FFCDD2;";
    file << "}";
    file << "</style>\n";
    file << "<body>\n";
    file << "<h1>Shopping cart:</h1>\n";
    file << "<table>\n";
    file << "<tr><th>Name</th><th>Description</th><th>Type</th><th>Time</th><tr>\n";

    const vector<Activity>& cartt = cart.get_all_cart();
    file<<cartt.size();
    for(const Activity& a : cartt){
        file << "<tr><td>" << a.get_name() << "</td><td>" << a.get_description() << "</td><td>" << a.get_type() << "</td><td>" << a.get_time() <<"</td><tr>\n";
    }

    file << "</table>\n";
    file << "</body>\n";
    file << "</html>\n";

    file.close();
}

int Service::Undo() {
    if(undo.size() <= 0) return -1;
    this->undo.back()->undo();
    this->undo.pop_back();
    return 0;

}
