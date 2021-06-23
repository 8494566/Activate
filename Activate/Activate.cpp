#include "Activate.h"
#include <QMessageBox>
#include <QSqlQuery>

Activate::Activate(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    m_db = QSqlDatabase::addDatabase("QODBC"); //数据库对象
	m_db.setDatabaseName(QString("DRIVER={SQL SERVER};"
		"SERVER=%1;" //服务器名称
		"DATABASE=%2;"//数据库名
		"UID=%3;"           //登录名
		"PWD=%4;"        //密码
	)
		.arg("49.234.10.172")
		.arg("GameDB")
		.arg("sa")
		.arg("wl1634968804.")
	);
	if (!m_db.open())
	{
		QMessageBox::about(NULL, u8"提示", u8"<font color='red'>数据库打开失败</font>");
		return;
	}

    connect(ui.activateButtun, SIGNAL(clicked()), this, SLOT(onActivateButtunButtonGroup()));
    connect(ui.unActivateButtun, SIGNAL(clicked()), this, SLOT(onUnActivateButtunButtonGroup()));
}

void Activate::onActivateButtunButtonGroup()
{
    QString id = ui.textEdit->toPlainText();
    QString name = ui.textEdit_2->toPlainText();
	if (id.isEmpty())
	{
		QMessageBox::about(NULL, u8"提示", u8"<font color='red'>id为空</font>");
		return;
	}
    QString sql = QString("INSERT INTO GameActor_Activate(SoleID,name)VALUES ('%1','%2');").arg(id).arg(name);
    QSqlQuery query;
    if(query.exec(sql))
		QMessageBox::about(NULL, u8"提示", u8"激活成功");
	else
		QMessageBox::about(NULL, u8"提示", u8"激活失败");
}

void Activate::onUnActivateButtunButtonGroup()
{
    QString name = ui.textEdit_2->toPlainText();
    if (name.isEmpty())
    {
        QMessageBox::about(NULL, u8"提示", u8"<font color='red'>请输入名字</font>");
        return;
    }
	QString sql = QString("DELETE FROM GameActor_Activate WHERE name = '%1';").arg(name);
	QSqlQuery query;
	if(query.exec(sql))
		QMessageBox::about(NULL, u8"提示", u8"删除成功");
	else
		QMessageBox::about(NULL, u8"提示", u8"删除失败");
}
