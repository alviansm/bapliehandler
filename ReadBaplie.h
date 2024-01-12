#ifndef READBAPLIE_H
#define READBAPLIE_H

#include <QObject>

class ReadBaplie : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString baplieURI READ baplieURI WRITE baplieURI NOTIFY baplieURIChanged)

public:
    explicit ReadBaplie(QObject *parent = nullptr);
    void baplieURI(const QString &newBaplieURI);
    QString baplieURI() const;

public slots:
    void switchBaplieURI();

signals:
    void baplieURIChanged();

private:
    QString m_baplieURI = "None";
};

#endif // READBAPLIE_H
