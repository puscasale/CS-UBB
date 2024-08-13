#ifndef LAB6_7_UNDO_H
#define LAB6_7_UNDO_H
#include "Activity.h"
#include "Repo.h"
#include <vector>
#include <algorithm>

class Undo{
public:
    virtual void undo() = 0;
    virtual ~Undo() =default;
};

class AddUndo : public Undo {
private:
    RepoAbs& repo;
public:
    AddUndo(RepoAbs& Rep) : repo(Rep) {}
    void undo() override{
        repo.remove_last();
    }
};

class DeleteUndo : public Undo {
private:
    RepoAbs& repo;
    Activity a;
    int index;
public:
    DeleteUndo(RepoAbs& Rep, const Activity a,const  int index) : repo(Rep), a(a), index(index) {}
    void undo() override {
        auto it = repo.get_all().begin();
        it += index;
        repo.get_all().insert(it, a);
    }
};

class ModifyUndo : public Undo {
private:
    RepoAbs& repo;
    Activity a;
    int index;
public:
    ModifyUndo(RepoAbs& Rep, Activity a, int index) : repo(Rep), a(a), index(index) {}
    void undo() override {
        repo.modify(index,a);
    }
};
#endif //LAB6_7_UNDO_H
