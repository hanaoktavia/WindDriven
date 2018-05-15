#ifndef WINDSPEEDUI_H
#define WINDSPEEDUI_H

#include <QWidget>

namespace Ui {
class WindspeedUI;
}

class WindspeedUI : public QWidget
{
    Q_OBJECT

public:
    explicit WindspeedUI(QWidget *parent = 0);
    ~WindspeedUI();

private:
    Ui::WindspeedUI *ui;
};

#endif // WINDSPEEDUI_H
