#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include <QString>
#include <QHash>

class textHandler
{
public:
    QHash<QString, int> wordCount(const QString& textt, int minEl, int maxEl) const;
    QString readTextFile(const QString& filePath);
private:
};
#endif // TEXTHANDLER_H
