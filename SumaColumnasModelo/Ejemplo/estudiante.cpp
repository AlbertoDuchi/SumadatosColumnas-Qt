#include "estudiante.h"

Estudiante::Estudiante(QObject *parent) : QObject(parent)
{
    m_nombre=" ";
    m_apellido=" ";
    m_nota=0;
}

Estudiante::Estudiante(QString nombre, QString apellido,int nota)
{
    m_nombre=nombre;
    m_apellido=apellido;
    m_nota=nota;
}

QString Estudiante::getNombre()
{
    return m_nombre;
}

QString Estudiante::getApellido()
{
    return m_apellido;
}

int Estudiante::getnota()
{
    return m_nota;
}
