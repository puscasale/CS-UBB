#include <QApplication>
#include <QPushButton>
#include "Echipe.h"
#include "Repo.h"
#include "Service.h"
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_all();
    Repo rep(R"(C:\Users\Ale\Desktop\test_oop\file.txt)");
    Service srv(rep);
    GUI gui(srv);
    gui.show();
    return a.exec();
}
