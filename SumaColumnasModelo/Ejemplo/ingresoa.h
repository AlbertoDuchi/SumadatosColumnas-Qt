#ifndef INGRESOA_H
#define INGRESOA_H

#include <QWidget>
#include "estudiante.h"
namespace Ui {
class IngresoA;
}

class IngresoA : public QWidget
{
    Q_OBJECT

public:
    explicit IngresoA(QWidget *parent = nullptr);
    ~IngresoA();
    void nuevo();
    void agregara();
    int registros=0;
private slots:
    void on_btnIngresoN_clicked();

    void on_btnnew_clicked();

    void on_btnsalire_clicked();

    void on_btnagregarE_clicked();

private:
    Ui::IngresoA *ui;
    QList<Estudiante*> m_estudiante;
};

#endif // INGRESOA_H
