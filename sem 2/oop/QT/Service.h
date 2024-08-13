//
// Created by Ale on 05/16/2024.
//

#ifndef QT_SERVICE_H
#define QT_SERVICE_H
#include <string>
#include "Activity.h"
#include "Repo.h"
#include "DinamicVector.h"
#include "Validator.h"
#include "Cart.h"
#include <functional>
#include "Undo.h"
#include <memory>
using std::string;

class ActivityCount {
private:
    int count;
    string type;
public:
    /**
     * Constructor
     */
    ActivityCount() =default;

    /**
     * Increments the count
     */
    void IncrementCount() {
        count++;
    }

    /**
     * Returns the count
     */
    int get_count() const{
        return count;
    }
};


class Service
{
private:
    RepoAbs& rep;
    Validator& valid;
    Cart cart;
    vector<unique_ptr<Undo>> undo;
public:
    //Service() = default;

    explicit Service(RepoAbs &rep, Validator &valid) : rep{rep }, valid{valid}{};


    /**
     * Adds an activity
     * @param name : the name of the activity (string)
     * @param description : the description of the activity (string)
     * @param type : the type of the activity (string)
     * @param time : the time of the activity (int)
     */
    void add(string name, string description, string type, int time);

    /**
     * Delets an activity by a given index
     * @param index: the given index
     */
    void del(const Activity& act);

    /***
     * Modifies an anctivity by a given index
     * @param new_name : the new name
     * @param new_description : the new description
     * @param new_type : the new type
     * @param new_time : the new time
     * @param index : the given index
     */
    void modify(const Activity& act_rm, const Activity& act);

    /***
     * Filters the list by a given type
     * @param type : the given type
     * @return : the filtered list
     */
    void filter_type(string type, vector<Activity>& filtered);

    /***
     * Filters the list by a vigen description
     * @param descr : the given description
     * @return : the filtered list
     */
    void filter_descr(string descr, vector<Activity>& filtered);

    /***
     * Sorts the list by name
     * @return : the sorted list
     */
    void sort_name(vector<Activity>& copy);

    /***
     * Sorts the list by description
     * @return : the sorted list
     */
    void  sort_descr(vector<Activity> & copy);

    /**
     * Sorts the list by type & time
     * @return : the sorted list
     */
    void sort_type_time(vector<Activity> & copy);

    /***
     * Gets an anctivity by a given index
     * @param index : the given index
     * @return : the activity
     */
    const Activity* get_activity(const string& name, const string& descr, const string& type, int time);

    /**
     * Returns all the activities
     */
    const vector<Activity>& get_all() {
        return rep.get_all();
    }


    /**
     * Adds an anctivity with a given name in the cart
     * @param name : the name of the activity
     */
    void add_cart(string name);

    /**
     * Adds a random amount of activities in the cart
     * @param n : how many activities to add
     * @return : the number of activities added
     */
    int add_random(int n);

    /**
     * Empties all the activities form the cart
     */
    void empty_cart();

    /**
     * Gets all the activities form the cart
     * @return
     */
    const vector<Activity>& get_all_cart();

    /**
     * Makes a raport of all the activities
     * @return : the raport
     */
    std::unordered_map<string ,ActivityCount> raport() const;

    void export_html(const string& file_name);

    int Undo();

    //~Service() = default;

};
#endif //QT_SERVICE_H
