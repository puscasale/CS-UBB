//
// Created by Ale on 05/16/2024.
//

#ifndef QT_ACTIVITY_H
#define QT_ACTIVITY_H
#include <string>
#include <iostream>
using std::string;


class Activity{

private:
    string name;
    string description;
    string type;
    int time;

public:

    /**
     * Constructor
     * @param name : the name of the activity
     * @param description : the description of the activity
     * @param type : the type of the activity
     * @param time : the time of the activity
     */
    Activity(string name,string description, string type, int time);

    Activity() = default;

    /**
     * Getter for name
     * @return name
     */
    string get_name() const;

    /**
     * Getter for description
     * @return description
     */
    string get_description() const;

    /**
     * Getter for type
     * @return type
     */
    string get_type() const;

    /**
     * Getter for time
     * @return time
     */
    int get_time() const;

    void set_name(const string& namee);

    void set_description(const string& descr);

    void set_type(const string& typee);

    void set_time(int timee);

};
#endif //QT_ACTIVITY_H
