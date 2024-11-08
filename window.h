#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QCheckBox;
class QPushButton;
QT_END_NAMESPACE

class Window : public QWidget
{
Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private slots:
    void toggleIDField(bool checked);
    void togglePasswordField(bool checked);
    void connect();

private:
    QLineEdit *idLineEdit;
    QLineEdit *passwordLineEdit;
    QCheckBox *showIDCheckBox;
    QCheckBox *showPasswordCheckBox;
};

#endif // WINDOW_H
