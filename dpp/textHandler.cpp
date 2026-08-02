#include "textHandler.h"
#include <QRegularExpression>
#include <QStringList>
#include <QFile>

QHash<QString, int> textHandler::wordCount(const QString& text, int minEl, int maxEl) const
{
    QHash<QString, int> frequencies;     // таблица результатов слово - счетчик

    static const QRegularExpression noWordChars("[^\\p{L}\\p{Nd}]+");

    QString cleanedText = text;
    cleanedText.replace(noWordChars, " ");

    const QStringList wordList = cleanedText.toLower().split(' ', Qt::SkipEmptyParts);

    for (const QString& word : wordList) {
        if (word.size() < minEl || word.size() > maxEl) {     // проверка минимума и максимума количества букв в слове из конфигурационного файла
            continue;
        }
        ++frequencies[word];
    }

    return frequencies;
}

QString textHandler::readTextFile(const QString& filePath)
{

   QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {     // Text — режим, приводящий переносы строк Windows (\r\n) к \n
       return QString();
        qDebug()<< "Ошибка открытия файла " << filePath;
     }

    QTextStream stream(&file);
    return stream.readAll();
}
