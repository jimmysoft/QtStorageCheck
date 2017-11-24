#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess process;
    process.start("df -h");
    process.waitForFinished();
    QString output(process.readAllStandardOutput());

    QStringList outputList = output.split("/");
    //get second line
    QString result = outputList[2];
    //split with space
    QStringList resultList = result.split(QRegExp("\\s+"));

    QString diskSize = resultList[1];
    QString diskUsed = resultList[2];
    QString diskAvail = resultList[3];
    QString diskUsePercentage = resultList[4];

    qDebug()<<"Size: "<<diskSize<<", Used: "<<diskUsed<<", Avail: "<<diskAvail<<", %: "<<diskUsePercentage;

    return a.exec();
}
