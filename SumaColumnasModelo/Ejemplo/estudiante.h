#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>

class Estudiante : public QObject
{
    Q_OBJECT
public:
    explicit Estudiante(QObject *parent = nullptr);
    Estudiante(QString nombre, QString apellido, int nota);
    QString getNombre();
    QString getApellido();
    int getnota();

signals:
private:
    QString m_nombre;
    QString m_apellido;
    int m_nota;
};

#endif // ESTUDIANTE_H
