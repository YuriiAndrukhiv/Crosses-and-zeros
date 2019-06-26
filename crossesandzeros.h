#ifndef CROSSESANDZEROS_H
#define CROSSESANDZEROS_H

#include <QWidget>
#include <QSignalMapper>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <vector>
#include <QString>
#include <QMenu>

class CrossesAndZeros : public QWidget
{
    Q_OBJECT
public:
    explicit CrossesAndZeros(QWidget *parent = nullptr);

signals:

private slots:
    void newGame();
    void pressed(const int id);

private:
    void init();
    void setSignalMapper();
    void endGame();
    bool winnerFound();


private:
    QLabel *mLabel;

    QSignalMapper *mSignalMapper;

    QPushButton *mPushButton;
    QPushButton *mPushButton2;
    QPushButton *mPushButton3;
    QPushButton *mPushButton4;
    QPushButton *mPushButton5;
    QPushButton *mPushButton6;
    QPushButton *mPushButton7;
    QPushButton *mPushButton8;
    QPushButton *mPushButton9;

    std::vector <QString> mBoard;
    QMenu *mNewGameButton;

    bool isPlayer1 = true;
    bool isPlayer1Beginner = true;
};

#endif // CROSSESANDZEROS_H
