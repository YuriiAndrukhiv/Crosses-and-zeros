#include "crossesandzeros.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <iostream>
#include <QMessageBox>

const int BUTTONS_COUNT = 9;

CrossesAndZeros::CrossesAndZeros(QWidget *parent) : QWidget(parent)
{
    init();
    setSignalMapper();
    connect(mSignalMapper, SIGNAL(mapped(int)), this, SLOT(pressed(int)));
    connect(mNewGameButton , SIGNAL(aboutToShow()) , this , SLOT(newGame()));
}

void CrossesAndZeros::newGame()
{
    isPlayer1Beginner = !isPlayer1Beginner;

    for(int i = 0 ; i < BUTTONS_COUNT ; i++)
    {
        mBoard[i] = "";
    }

    for(int i = 0 ; i < BUTTONS_COUNT ; i++)
    {
        auto tempBtn = (QPushButton*)mSignalMapper->mapping(i);
        tempBtn->setText(QString());
        tempBtn->setEnabled(true);
    }

    if(isPlayer1Beginner)
    {
        isPlayer1 = true;
        mLabel->setText(QString("NEXT: PLAYER 1"));
    }
    else {
        isPlayer1 = false;
        mLabel->setText(QString("NEXT: PLAYER 2"));
    }
}

void CrossesAndZeros::pressed(const int id)
{
    auto pressedButton = (QPushButton*)mSignalMapper->mapping(id);
    if(isPlayer1)
    {
        pressedButton->setText("X");
        mBoard.at(id) = QString("X");
        mLabel->setText("NEXT: Player 2");
    }
    else
    {
        pressedButton->setText("O");
        mBoard.at(id) = QString("O");
        mLabel->setText("NEXT: Player 1");
    }
    if(!winnerFound())
    {
        isPlayer1 = !isPlayer1;
        pressedButton->setEnabled(false);
    }
    else
    {
        if(isPlayer1)
        {
            QMessageBox::information(this, QString("Congratulations") , "Winner: Player 1"  , QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this, QString("Congratulations") , "Winner: Player 2"  , QMessageBox::Ok);
        }
        endGame();
    }
}

void CrossesAndZeros::init()
{
    mLabel = new QLabel("Player 1");

    mPushButton = new QPushButton();
    mPushButton2 = new QPushButton();
    mPushButton3 = new QPushButton();
    mPushButton4 = new QPushButton();
    mPushButton5 = new QPushButton();
    mPushButton6 = new QPushButton();
    mPushButton7 = new QPushButton();
    mPushButton8 = new QPushButton();
    mPushButton9 = new QPushButton();

    QVBoxLayout *boxLayout = new QVBoxLayout(this);

    QMenuBar* menuBar = new QMenuBar();
    mNewGameButton = new QMenu("New game");
    menuBar->addMenu(mNewGameButton);

    QHBoxLayout *lHBoxLayoutArgumentOne = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentTwo = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentThree = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentFour = new QHBoxLayout;

    lHBoxLayoutArgumentOne -> addWidget(mLabel);
    lHBoxLayoutArgumentTwo -> addWidget(mPushButton);
    lHBoxLayoutArgumentTwo -> addWidget(mPushButton2);
    lHBoxLayoutArgumentTwo -> addWidget(mPushButton3);
    lHBoxLayoutArgumentThree -> addWidget(mPushButton4);
    lHBoxLayoutArgumentThree -> addWidget(mPushButton5);
    lHBoxLayoutArgumentThree -> addWidget(mPushButton6);
    lHBoxLayoutArgumentFour -> addWidget(mPushButton7);
    lHBoxLayoutArgumentFour -> addWidget(mPushButton8);
    lHBoxLayoutArgumentFour -> addWidget(mPushButton9);

    boxLayout -> setMenuBar(menuBar);
    boxLayout -> addLayout(lHBoxLayoutArgumentOne);
    boxLayout -> addLayout(lHBoxLayoutArgumentTwo);
    boxLayout -> addLayout(lHBoxLayoutArgumentThree);
    boxLayout -> addLayout(lHBoxLayoutArgumentFour);

    setWindowTitle("Crosses 'N Zeros");

    for(int i = 0; i < BUTTONS_COUNT; i++)
    {
        mBoard.push_back(QString());
    }
}

void CrossesAndZeros::setSignalMapper()
{
    mSignalMapper = new QSignalMapper(this);
    mSignalMapper->setMapping(mPushButton, 0);
    mSignalMapper->setMapping(mPushButton2, 1);
    mSignalMapper->setMapping(mPushButton3, 2);
    mSignalMapper->setMapping(mPushButton4, 3);
    mSignalMapper->setMapping(mPushButton5, 4);
    mSignalMapper->setMapping(mPushButton6, 5);
    mSignalMapper->setMapping(mPushButton7, 6);
    mSignalMapper->setMapping(mPushButton8, 7);
    mSignalMapper->setMapping(mPushButton9, 8);

    connect(mPushButton, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton2, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton3, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton4, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton5, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton6, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton7, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton8, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(mPushButton9, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
}

void CrossesAndZeros::endGame()
{
    for(int i = 0 ; i < BUTTONS_COUNT ; i++)
    {
        auto button = (QPushButton*)mSignalMapper->mapping(i);
        button->setEnabled(false);
    }
}

bool CrossesAndZeros::winnerFound()
{
    for(int i = 0, j = 0; i < BUTTONS_COUNT; i+=3, j++)
    {
        if (mBoard[i] == mBoard[i+1] && mBoard[i+1] == mBoard[i+2] && !mBoard[i].isEmpty())
        {
            return true;
        }
        if (mBoard[j] == mBoard[j+3] && mBoard[j+3] == mBoard[j+6] && !mBoard[j].isEmpty())
        {
            return true;
        }
    }

    if(mBoard[0] == mBoard[4] && mBoard[4] == mBoard[8] && !mBoard[0].isEmpty())
    {
        return true;
    }

    if(mBoard[2] == mBoard[4] && mBoard[4] == mBoard[6] && !mBoard[2].isEmpty())
    {
        return true;
    }

    return false;
}
