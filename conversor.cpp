#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectar el dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2cent(int)));

    connect(ui->inkelv, SIGNAL(valueChanged(int)),
            this, SLOT (kelv2cent(int)));

}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int f = (grados * 9.0/5) + 32;
        int k = grados + 273.15;
        ui->inFahr->setValue(f);
        ui->inkelv->setValue(k);
    }
}

void Conversor::fahr2cent(int grados)
{
    if (ui->inFahr->hasFocus()){
        int c = (grados - 32) * 5.0/9;
        int k = 5.0/9 * (grados - 32) + 273.15;
        ui->inkelv->setValue(k);
        ui->inCent->setValue(c);

    }
}

void Conversor::kelv2cent(int grados)
{
    if (ui->inkelv->hasFocus()){
        int c = grados - 273.15;
        int f = 1.8 * (grados - 273.15) + 32;
        ui->inFahr->setValue(f);
        ui->inCent->setValue(c);
    }
}
