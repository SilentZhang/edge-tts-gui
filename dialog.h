#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include "communicate.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void send();

    void stop();

private:
    void checkDuplicate(const QString& text, const QString& voice);

    void setCommunicate(const QString& text, const QString& voice, const QString& fileName);


private slots:
    void on_pushButtonPlay_clicked();

    void on_radioButtonXiaoxiao_clicked(bool checked);

    void on_radioButtonXiaoyi_clicked(bool checked);

    void on_radioButtonYunjian_clicked(bool checked);

    void on_radioButtonYunxi_clicked(bool checked);

    void on_radioButtonYunxia_clicked(bool checked);

    void on_radioButtonYunyang_clicked(bool checked);

    void on_pushButtonStop_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::Dialog *ui;
    Communicate m_comm;
    QString m_lastText;
    QString m_lastVoice;
    QString voice = "zh-CN, XiaoyiNeural";
    QString lastDir = "";

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
}; // class Dialog

#endif // DIALOG_H
