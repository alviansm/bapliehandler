#include "ReadBaplie.h"

ReadBaplie::ReadBaplie(QObject *parent)
    : QObject{parent}
{}

void ReadBaplie::baplieURI(const QString &newBaplieURI)
{

}

QString ReadBaplie::baplieURI() const
{
    return m_baplieURI;
}

void ReadBaplie::switchBaplieURI()
{

}
