#ifndef INGRESOE_N_H
#define INGRESOE_N_H

#include <QWidget>
#include "estudiante.h"
#include <QStandardItemModel>
#include "ingresoa.h"
namespace Ui {
class IngresoE_N;
}

class IngresoE_N : public QWidget
{
    Q_OBJECT

public:
    explicit IngresoE_N(QList<Estudiante*> m_estudiante, QWidget *parent = nullptr);
    ~IngresoE_N();
    void nuevoen();
    int index=0;
    int listacont=0;
    //int valorcambio=0;

private slots:
    void on_btnopenn_clicked();
    void on_btnsaveen_clicked();
    void on_btnsaliren_clicked();
    void on_btnCalcularN_clicked();
    void suma(const QModelIndex &index);

private:
    Ui::IngresoE_N *ui;
    QStandardItemModel *cvsModel;

};

#endif // INGRESOE_N_H
