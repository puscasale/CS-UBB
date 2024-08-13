#include <QApplication>
#include <QPushButton>
#include "Elevi.h"
#include "Repo.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RepoInFile rep(R"(C:\Users\Ale\Desktop\sim_elevi\file.txt)");
    Service srv(rep);
    GUI gui(srv);
    gui.show();
    return a.exec();
}
