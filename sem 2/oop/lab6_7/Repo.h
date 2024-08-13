#ifndef LAB6_7_REPO_H
#define LAB6_7_REPO_H
#include <vector>
#include <map>
#include <random>
#include "Activity.h"
#include "DinamicVector.h"
using std::vector;

class RepoException{
private:
    string msg;

public:
     RepoException(string m): msg{m} {};
     string get_Message() {
         return this->msg;
     }
};

class RepoAbs {
public:
    RepoAbs() = default;
    RepoAbs(const RepoAbs& o) = delete;

    virtual void store(const Activity& o) = 0;
    virtual void remove(int position) = 0;
    virtual void modify(int position, const Activity& o) = 0;
    virtual const Activity& get_activity(int position) = 0;
    virtual vector<Activity>& get_all() =0;
    virtual const Activity& find_act_name(string name)= 0;
    virtual void remove_last() =0;

};

class Repo : public RepoAbs
{

private:
    vector<Activity> act;

public:
    Repo(const Repo& ot) = delete;

    Repo() = default;

    /**
     * Store/Add the activity in the list of activities
     * @param activity : the activity that will be added
     */
   virtual void store(const Activity &activity);

    /**
     * Remove the activity at a given postion
     * @param position : the postion of the search activity
     */
    virtual void remove(int position);

    /**
     * Modify the activity at a given position
     * @param position : the position of the searched activity
     * @param newActivity : the new activity
     */
    virtual void modify(int position, const Activity& newActivity);

    /**
     * Get an activity at a given position
     * @param position : the position of the searched activity
     * @return activity
     */
    const Activity& get_activity(int position);

    /**
     * Get all activities
     * @return activities
     */
     vector<Activity>& get_all() {
        return act;
    }


    /**
     * Find an activity by a given name
     * @param name : the name of the searched activity
     * @return the activity
     */
    const Activity& find_act_name(string name);

    void remove_last();

};


class RepoInFile: public Repo{
private:
    string file_name;
    void write_to_file();
    void read_from_file();

public:
    RepoInFile(string file_name) : Repo(), file_name(file_name){
        read_from_file();
    }
    void store(const Activity& activity) override {
        Repo::store(activity);
        write_to_file();
    }

    void remove(int position) override {
        Repo::remove(position);
        write_to_file();
    }

    void modify(int position,const  Activity&a) override{
        Repo::modify(position,a);
        write_to_file();
    }

};

class RepoLab : public RepoAbs {
private:
    std::map<int, Activity> activities;
    double prob;
    void random_prob();

public:

    ~RepoLab() = default;
    RepoLab() {
        prob = 0.5;

    }
    void set_prob(double probabilitate) {
        prob = probabilitate;
    }
    void store(const Activity& a) override;
    void remove( int poz) override;
    void modify(int poz, const Activity& a) override;
    void remove_last() override;
    const Activity& get_activity(int position) override;
    const Activity& find_act_name(string name) override;
    vector<Activity> all;
    vector<Activity>& get_all() override;


};

class Prob_Exception {
private:
    string msg;
public:
    Prob_Exception(string msg) : msg(msg) {};
    string get_message() {
        return this->msg;
    }
};
#endif //LAB6_7_REPO_H
