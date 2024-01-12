#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QObject>

class ApplicationWindow : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationWindow(QObject *parent = nullptr);

signals:
};

#endif // APPLICATIONWINDOW_H
