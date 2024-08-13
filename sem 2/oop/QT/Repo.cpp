#include "Repo.h"
#include <algorithm>
#include <fstream>
#include <random>

void Repo::store(const Activity &activity){
    for (const Activity& e : act) {
        if(e.get_name() == activity.get_name() && e.get_description() == activity.get_description() && e.get_type() == activity.get_type() && e.get_time() == activity.get_time()){
            throw RepoException("\nThis activity already exists!\n\n");
        }
    }
    this->act.push_back(activity);
}


void Repo::remove(const Activity& a) {
    auto it = std::remove_if(act.begin(), act.end(), [a](const Activity& a_cmp){
        return a.get_name() == a_cmp.get_name() and a.get_description() == a_cmp.get_description() and a.get_type() == a_cmp.get_type() and a.get_time() == a_cmp.get_time();

    });
    act.erase(it);
}

void Repo::modify(const Activity& a, const Activity& newActivity) {

    for( auto& activity: Repo::get_all()) {
        if(activity.get_name() == a.get_name() and activity.get_description() == a.get_description() and activity.get_type() == a.get_type() and activity.get_time() == a.get_time()) {
            activity.set_name(newActivity.get_name());
            activity.set_description(newActivity.get_description());
            activity.set_type(newActivity.get_type());
            activity.set_time(newActivity.get_time());
        }
    }
}

const Activity* Repo::get_activity(const string& name, const string& descr, const string& type, int time)  {

    auto pred = [name, descr, type, time](const Activity& activity){
        return activity.get_name() == name and activity.get_description() == descr and activity.get_type() == type and activity.get_time() == time;
    };

    auto iterator = std::find_if(act.begin(), act.end(),pred);
    if(iterator != act.end())
        return &(*iterator);
    else{
        return nullptr;
    }
}


const Activity& Repo::find_act_name(string name) {
    vector<Activity>::iterator f = std::find_if(this->act.begin(), this->act.end(), [=](const Activity& a){
        return a.get_name() == name;
    });
    if(f != this->act.end())
        return (*f);
}


void RepoInFile::read_from_file() {
    std::ifstream file;
    file.open(file_name);

    string line, word;

    while (!file.eof())
    {
        getline(file, line);

        if(line.size())
        {
            vector<string> activity_info;


            auto found = line.find(',');
            while (found != -1)
            {
                word = line.substr(0, found);
                line.erase(line.begin(), line.begin() + found + 1);

                activity_info.push_back(word);

                found = line.find(',');
            }


            const Activity& a{ activity_info.at(0), activity_info.at(1) ,activity_info.at(2),stoi(line)};
            Repo::store(a);

            activity_info.clear();
        }

    }

    file.close();
}


void RepoInFile::write_to_file() {
    std::ofstream file;
    file.open(file_name);

    for (const auto& activity : get_all())
    {
        string line;
        line.append(activity.get_name());
        line.append(",");
        line.append(activity.get_description());
        line.append(",");
        line.append(activity.get_type());
        line.append(",");
        line.append(std::to_string(activity.get_time()));
        line.append("\n");
        file << line;
    }

    file.close();
}


void RepoLab::random_prob() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double probability = dis(gen);
    if( probability > prob)
        throw RepoException("Eroare!\n\n");

}

void RepoLab::store(const Activity &a) {
    random_prob();
    activities.insert(std::make_pair(a.get_name(),a));

}

void RepoLab::remove(const Activity& a) {
    random_prob();
    activities.erase(a.get_name());
}

vector<Activity> &RepoLab::get_all() {
    all.clear();
    for(auto& it: activities) {
        all.push_back(it.second);
    }
    return all;
}

void RepoLab::modify(const Activity& a_rm, const Activity &a) {
    random_prob();
    activities.erase(a_rm.get_name());
    activities.insert(std::make_pair(a.get_name(), a));
}


const Activity* RepoLab::get_activity(const string& name, const string& descr, const string& type, int time) {

    random_prob();
    for(const auto& p: activities)
        if(p.second.get_name() == name and p.second.get_description() == descr and p.second.get_type() == type and p.second.get_time() ==time)
            return &p.second;
    return nullptr;
}

const Activity &RepoLab::find_act_name(string name) {
    for(auto& it : activities) {
        if(it.second.get_name() == name)
            return it.second;
    }
}



