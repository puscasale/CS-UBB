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


void Repo::remove(int position) {
    if (position  != act.size() - 1) {
        for (position; position   < act.size() - 1; position++) {
            act[position ] = act[position + 1];
        }
        act.pop_back();
    }
    else {
        act.pop_back();
    }
}

void Repo::modify(int position, const Activity& newActivity) {
    if (position > act.size()) {
        throw RepoException("\nInvalid index!\n\n");
    }

    act[position] = newActivity;
}

const Activity& Repo::get_activity(int position)  {
    if (position > act.size()) {
        throw RepoException("\nInvalid index!\n\n");
    }
    return act[position ];
}


const Activity& Repo::find_act_name(string name) {
    vector<Activity>::iterator f = std::find_if(this->act.begin(), this->act.end(), [=](const Activity& a){
        return a.get_name() == name;
    });
    if(f != this->act.end())
        return (*f);
}

void Repo::remove_last() {
    this->act.pop_back();
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
    activities.insert(std::make_pair(activities.size(),a));

}

void RepoLab::remove(int poz) {
    random_prob();
    activities.erase(poz);
    std::map<int, Activity> act;
    act.clear();
    for( auto&it : activities)
        act.insert(std::make_pair(act.size(),it.second));
    activities = act;
}

vector<Activity> &RepoLab::get_all() {
    all.clear();
    for(auto& it: activities) {
        all.push_back(it.second);
    }
    return all;
}

void RepoLab::modify(int poz, const Activity &a) {
    random_prob();
    for( auto& it: activities) {
        if(it.first == poz) {
            activities.erase(poz);
            activities.insert(std::make_pair(poz,a));
            break;
        }
    }
}

void RepoLab::remove_last() {
    activities.erase((int)activities.size() -1);
}

const Activity &RepoLab::get_activity(int position) {
    random_prob();
    return activities.at(position);
}

const Activity &RepoLab::find_act_name(string name) {
     for(auto& it : activities) {
         if(it.second.get_name() == name)
             return it.second;
     }
}

