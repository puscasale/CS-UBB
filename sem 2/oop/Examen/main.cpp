#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "domain.h"
#include "Repo.h"
#include "Srv.h"
#include "Model.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_domain();
    test_repo();
    test_srv();
    Repo rep(R"(C:\Users\Ale\Desktop\untitled1\in.txt)");
    Srv srv(rep);
    GUI gui(srv);
    gui.show();
    return QApplication::exec();
}
