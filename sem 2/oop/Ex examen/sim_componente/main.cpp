#include <QApplication>
#include <QPushButton>
#include "RepoProcesoare.h"
#include "RepoPlaca.h"
#include "Service.h"
#include "GUI.h"
#include "tests.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_all();
    RepoProcesoare proc{R"(C:\Users\Ale\Desktop\sim_componente\procesor.txt)"};
    RepoPlaca placa{R"(C:\Users\Ale\Desktop\sim_componente\placa.txt)"};
    Service srv{proc,placa};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
