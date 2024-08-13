//
// Created by Ale on 05/16/2024.
//

#ifndef QT_UNDO_H
#define QT_UNDO_H
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
    Activity a;
public:
    AddUndo(RepoAbs& Rep, const Activity& a) : repo(Rep), a(a) {}
    void undo() override{
        repo.remove(a);
    }
};

class DeleteUndo : public Undo {
private:
    RepoAbs& repo;
    Activity act;
public:
    DeleteUndo(RepoAbs& Rep, const Activity& a) : repo(Rep), act(a) {}
    void undo() override {
        repo.store(act);
    }
};

class ModifyUndo : public Undo {
private:
    RepoAbs& repo;
    Activity a_rm;
    Activity a;
public:
    ModifyUndo(RepoAbs& Rep, const Activity& a_rm, const Activity& a) : repo(Rep), a_rm(a_rm), a(a) {}
    void undo() override {
        repo.modify(a, a_rm);
    }
};
#endif //QT_UNDO_H
