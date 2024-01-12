#include "HandleBaplie.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

HandleBaplie::HandleBaplie(QObject *parent)
    : QObject{parent}
{
    qDebug() << "HandleBaplie created";
}

QString HandleBaplie::baplieURI() const
{
    return m_baplieURI;
}

void HandleBaplie::setBaplieURI(const QString &baplieURI)
{
    if (baplieURI == m_baplieURI)
        return;

    m_baplieURI = baplieURI;
    emit baplieURIChanged();
}

void HandleBaplie::readBaplie(QString baplieURI)
{
    baplieURI.remove(0, 8);
    QFile file(baplieURI);
    if (!file.open(QIODevice::ReadWrite)) {
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        qDebug() << baplieURI;
        return;
    }

    setBaplieContent(file.readLine());
    emit baplieContentChanged();


}

QString HandleBaplie::baplieContent() const
{
    return m_baplieContent;
}

void HandleBaplie::setBaplieContent(const QString &newBaplieContent)
{
    if (m_baplieContent == newBaplieContent)
        return;
    m_baplieContent = newBaplieContent;
    emit baplieContentChanged();
}

double HandleBaplie::loadingStatus() const
{
    return m_loadingStatus;
}

void HandleBaplie::setLoadingStatus(double newLoadingStatus)
{
    if (qFuzzyCompare(m_loadingStatus, newLoadingStatus))
        return;
    m_loadingStatus = newLoadingStatus;
    emit loadingStatusChanged();
}
