
#ifndef LAB6_7_ACTIVITY_H
#define LAB6_7_ACTIVITY_H
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

    /**
     * Constructor
     * @param name : the name of the activity
     * @param description : the description of the activity
     * @param type : the type of the activity
     * @param time : the time of the activity
     */
    Activity(string name, string description, string type, int time);

    /**
     * Copy constructor
     * @param a
     */
    Activity(const Activity& other) :name{ other.name }, description{ other.description }, type{ other.type }, time{ other.time } {
        std::cout << "*\n";
    }
};
#endif //LAB6_7_ACTIVITY_H
