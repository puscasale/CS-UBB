#include "activity.h"

Activity::Activity(string name, string description, string type, int time): name{name}, description{description}, type{type}, time{time}{};

string Activity::get_name() const{
    return name;
}

string Activity::get_description() const{
    return description;
}

string Activity::get_type() const{
    return type;
}

int Activity::get_time() const{
    return time;
}

void Activity::set_name(const string &namee) {
    this->name = namee;
}

void Activity::set_description(const string &descr) {
    this->description = descr;
}

void Activity::set_type(const string &typee) {
    this->type = typee;
}

void Activity::set_time(int timee) {
    this->time = timee;
}



