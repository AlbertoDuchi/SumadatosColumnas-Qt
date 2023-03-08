#include "ingresoa.h"
#include "ui_ingresoa.h"
#include "ingresoe_n.h"
#include "QDate"
#include <QMessageBox>
#include <estudiante.h>
#include "ingresoe_n.h"
IngresoA::IngresoA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IngresoA)
{
    ui->setupUi(this);
    nuevo();
}

IngresoA::~IngresoA()
{
    delete ui;
}

void IngresoA::nuevo()
{
    ui->lnnombre->setText("");
    ui->lnapellido->setText("");
    QString fecha=QDate::currentDate().toString();
    ui->lbfecha->setText(fecha);
    QStringList cabecera= {"Nombre","Apellido"};
    ui->tblista->setColumnCount(2);
    ui->tblista->setHorizontalHeaderLabels(cabecera);
    ui->tblista->setColumnWidth(0,226);
    ui->tblista->setColumnWidth(1,226);
    ui->tblista->setRowCount(0);
    registros=0;
    m_estudiante.clear();
}

void IngresoA::agregara()
{
    QString nombre=ui->lnnombre->text();
    QString apellido=ui->lnapellido->text();
    if(!nombre.isEmpty() and !apellido.isEmpty()){
        int posicion=ui->tblista->rowCount();
        ui->tblista->insertRow(posicion);
        ui->tblista->setItem(posicion,0,new QTableWidgetItem(ui->lnnombre->text()));
        ui->tblista->setItem(posicion,1,new QTableWidgetItem(ui->lnapellido->text()));
        m_estudiante.append(new Estudiante(ui->lnnombre->text(),ui->lnapellido->text(),0));
        ui->lnnombre->setText(" ");
        ui->lnapellido->setText(" ");
        registros=registros+1;
    }else{
        QMessageBox::critical(0,"Aviso","Revise el ingreso de Datos\nNo puede ser datos vacios");
    }


}
void IngresoA::on_btnIngresoN_clicked()
{
    if(m_estudiante.size()>0){
        IngresoE_N *ingresoEN = new IngresoE_N(m_estudiante);
        ingresoEN->show();
    }else{
         QMessageBox::critical(0,"Aviso","Lista Vacia");
    }

}

void IngresoA::on_btnnew_clicked()
{
 nuevo();
}

void IngresoA::on_btnagregarE_clicked()
{
    agregara();
}
void IngresoA::on_btnsalire_clicked()
{
  close();
}
