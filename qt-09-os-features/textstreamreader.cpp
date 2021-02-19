#include "textstreamreader.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

TextStreamReader::TextStreamReader(QObject *parent) : QObject(parent)
{

}

TextStreamReader::~TextStreamReader()
{
    qDebug() << "~TextStreamReader()";
}

void TextStreamReader::readFromFile(QString fileName)
{
    // TODO: open file in readonly mode
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    // TODO: create QTextStream
    QTextStream stream(&file);
    forever {
        // TODO: read from stream and emit required signal on each row
        QString line = stream.readLine();

        if(line.isNull() || line.isEmpty())
        {
            break;
        }

        double data = line.toDouble();
        emit dataReaded(data);
    }

    emit allDataReaded();
    qDebug() << "End of input file";
}
