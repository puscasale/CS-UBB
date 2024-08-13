#include "Activity.h"

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

Activity::Activity(string name, string description, string type, int time): name{name}, description{description}, type{type}, time{time}{};

