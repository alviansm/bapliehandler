#ifndef HANDLEBAPLIE_H
#define HANDLEBAPLIE_HR

#include <QObject>
#include <QString>
#include <qqml.h>

class HandleBaplie : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString baplieURI READ baplieURI WRITE setBaplieURI NOTIFY baplieURIChanged)
    Q_PROPERTY(QString baplieContent READ baplieContent WRITE setBaplieContent NOTIFY baplieContentChanged FINAL)
    Q_PROPERTY(double loadingStatus READ loadingStatus WRITE setLoadingStatus NOTIFY loadingStatusChanged FINAL)
    QML_ELEMENT

public:
    explicit HandleBaplie(QObject *parent = nullptr);

    QString baplieURI() const;
    void setBaplieURI(const QString &baplieURI);

    QString baplieContent() const;
    void setBaplieContent(const QString &newBaplieContent);

    double loadingStatus() const;
    void setLoadingStatus(double newLoadingStatus);

signals:
    void baplieURIChanged();
    void baplieContentChanged();

    void loadingStatusChanged();

public slots:
    void readBaplie(QString baplieURI);

private:
    QString m_baplieURI = "File Not Selected";
    QString m_baplieContent = "Please open BAPLIE file (.EDI) by clicking Files -> Open BAPLIE -> Select .EDI file -> OK";
    double m_loadingStatus = 0.00;
};

#endif // HANDLEBAPLIE_H
