#include "ingresoe_n.h"
#include "ui_ingresoe_n.h"
#include "estudiante.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

IngresoE_N::IngresoE_N(QList<Estudiante*> m_estudiante, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IngresoE_N)
{
    ui->setupUi(this);

    QStringList etiqueta;
    etiqueta<< "Nombre" <<"Apellido"<< "Nota 1" << "Nota 2"<<"Nota Final";
    cvsModel = new QStandardItemModel(this);
    cvsModel->setColumnCount(5);
    cvsModel->setHorizontalHeaderLabels(etiqueta);

    ui->tvestudianten->setModel(cvsModel);
    index = cvsModel->rowCount();
    for(int i=0;i<m_estudiante.length();i++){
        cvsModel->insertRows(index,1);
        cvsModel->setData(cvsModel->index(index,0),m_estudiante.at(i)->getNombre());
        cvsModel->setData(cvsModel->index(index,1),m_estudiante.at(i)->getApellido());
        cvsModel->setData(cvsModel->index(index,2),0);
        cvsModel->setData(cvsModel->index(index,3),0);
        cvsModel->setData(cvsModel->index(index,4),0);
        cvsModel->item(index,0)->setEnabled(false);
        cvsModel->item(index,1)->setEnabled(false);
        cvsModel->item(index,4)->setEnabled(false);
        listacont=listacont+1;
    }
      connect(cvsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(suma(QModelIndex)));
}
IngresoE_N::~IngresoE_N()
{
    delete ui;
    delete cvsModel;
}

void IngresoE_N::nuevoen()
{

}

void IngresoE_N::on_btnopenn_clicked()
{
    auto filename = QFileDialog::getOpenFileName(this, "Abrir",
        QDir::rootPath(), "CSV File (*.csv)");
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        auto elements = line.split(",");
        QList<QStandardItem *> standardItemsList;
        for (QString item : line.split(";")) {
             standardItemsList.append(new QStandardItem(item));
        }
        cvsModel->insertRow(cvsModel->rowCount(), standardItemsList);
        file.close();
      }
    }

void IngresoE_N::on_btnsaveen_clicked()
{
    QString nombreArchivo;
          QFile file;
          nombreArchivo = QFileDialog::getSaveFileName(this, "G U A R D A R  C O M O", QDir::rootPath(), "CSV File (*.csv)");
          file.setFileName(nombreArchivo);
          if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
             QMessageBox::information(this,"A V I S O","Archivo no Creado");
          }else{
              QTextStream in(&file);
              int n = cvsModel->rowCount();
              int m = cvsModel->columnCount();
              QString line;
              for (int i=0; i<n; i++){
                  for (int j=0; j<m; j++){
                      if (j!=(m-1)){
                          line=cvsModel->item(i,j)->text()+";";
                      }else{
                          line=cvsModel->item(i,j)->text();
                      }

                      in<<line;
                  }
                  in<<"\n";
              }
              QMessageBox::information(this,"Aviso","Archivo Guardado");
              file.close();
          }
}
void IngresoE_N::on_btnsaliren_clicked()
{
    close();
}


void IngresoE_N::on_btnCalcularN_clicked()
{
    int nota1,nota2;
    int columnas=cvsModel->columnCount();
    int valor,filas=cvsModel->rowCount();

    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas; j++){
            QString dato=cvsModel->item(i,j)->text();
            valor=dato.toInt();
            if(j==2){
                nota1=valor;
            }
            if(j==3){
                nota2=valor;
            }
             if(j==4){
                 valor=nota1+nota2;
                 cvsModel->setData(cvsModel->index(i,4),valor);
                 qDebug()<<dato.toInt();
                 valor=0;
             }

        }
    }
}

void IngresoE_N::suma(const QModelIndex &index)
{
    QString dato=cvsModel->item(index.row(),index.column())->text();
    int valor1=dato.toInt(),resultado=0;
    int valor2=0;
    qDebug()<<"Prueba";
    //Validar que la nota nose mayor 50
    QString texto1="Nota mayor a 50\n se prondra como nota 0";

    if (valor1>50){
        QMessageBox::information(this,"Aviso",texto1);
        resultado=0;
        cvsModel->setData(cvsModel->index(index.row(),index.column()),resultado);

    }else{
        if(index.column()==2){
            QString dato1=cvsModel->item(index.row(),3)->text();
            valor2 = dato1.toInt();
        }
        if (index.column()==3){
            QString dato1=cvsModel->item(index.row(),2)->text();
            valor2 = dato1.toInt();
        }
        resultado=valor1+valor2;
    }

    cvsModel->setData(cvsModel->index(index.row(),4),resultado);
}
