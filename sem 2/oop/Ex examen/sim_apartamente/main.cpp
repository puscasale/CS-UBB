#include <QApplication>
#include <QPushButton>
#include "Repo.h"
#include "Service.h"
#include "GUI.h"
#include "tests.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_all();
    RepoInFile rep(R"(C:\Users\Ale\Desktop\sim_apartamente\merge.txt)");
    //Repo rep;
    Service srv(rep);
    GUI gui(srv);
    gui.show();
    return a.exec();
}
