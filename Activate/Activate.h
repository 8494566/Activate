#pragma once

#include <QtWidgets/QWidget>
#include <QSqlDatabase>
#include "ui_Activate.h"

class Activate : public QWidget
{
    Q_OBJECT

public:
    Activate(QWidget *parent = Q_NULLPTR);

private slots:
	void onActivateButtunButtonGroup();
    void onUnActivateButtunButtonGroup();

private:
    QSqlDatabase m_db;
private:
    Ui::ActivateClass ui;
};
