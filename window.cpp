#include "window.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    // id
    QLabel *idLabel = new QLabel(tr("Identifiant:"));
    idLineEdit = new QLineEdit;
    idLineEdit->setPlaceholderText("Entrer votre identifiant");

    // mdp
    QLabel *passwordLabel = new QLabel(tr("Mot de passe:"));
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setPlaceholderText("Entrer votre mot de passe");

    // case afficher/masquer
    showIDCheckBox = new QCheckBox(tr("Afficher l'identifiant"));
    connect(showIDCheckBox, &QCheckBox::toggled, this, &Window::toggleIDField);

    // case afficher/masquer
    showPasswordCheckBox = new QCheckBox(tr("Afficher le mot de passe"));
    connect(showPasswordCheckBox, &QCheckBox::toggled, this, &Window::togglePasswordField);

    // Layout principal
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(idLabel, 0, 0);
    layout->addWidget(idLineEdit, 0, 1);
    layout->addWidget(showIDCheckBox, 0, 2);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(passwordLineEdit, 1, 1);
    layout->addWidget(showPasswordCheckBox, 1, 2);

    setLayout(layout);
    setWindowTitle(tr("Identifiant et Mot de Passe"));
}

void Window::toggleIDField(bool checked)
{
    idLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::PasswordEchoOnEdit);
}

void Window::togglePasswordField(bool checked)
{
    passwordLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::PasswordEchoOnEdit);
}
