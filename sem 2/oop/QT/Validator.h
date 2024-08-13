//
// Created by Ale on 05/16/2024.
//

#ifndef QT_VALIDATOR_H
#define QT_VALIDATOR_H
#include <string>
using namespace std;

class Exception{
private:
    string msg;
public:
    Exception(string m) : msg{m} {};
    string getMessage() {
        return this->msg;
    }
};

class Validator{
public:
    Validator(const Validator&o) = delete;
    Validator() =default;
    bool valid_string(string& str) {
        if(str.size() == 0) return false;
        for( int i = 0; i <str.size(); i++) {
            if(!(str.at(i) >= 'a' && str.at(i) <= 'z') || (str.at(i) >= 'A' && str.at(i) <= 'Z') || str.at(i) == ' ') return false;
        }
        return true;
    }

    void validateActivity(std::string name, std::string description, std::string type, int time) {
        string err;

        if(!valid_string(name)) err.append("Invalid name\n");
        if(!valid_string(description)) err.append("Invalid description\n");
        if(!valid_string(type)) err.append("Invalid type\n");
        if(time <= 0) err.append("Invalid time\n");
        if( err.size() != 0) throw Exception(err);
    }

};


#endif //QT_VALIDATOR_H
