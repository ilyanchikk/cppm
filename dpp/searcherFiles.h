#ifndef SEARCHERFILES_H
#define SEARCHERFILES_H

#include <QString>
#include <QStringList>

class searcherFiles {
public:

    void loadConfig(const QString& path);
    QStringList foundFiles(QStringList path, QStringList extention);
    QStringList getPath();
    QStringList getExtention();
    int getMinEl();
    int getMaxEl();
private:
    QStringList __path;
    QStringList __extention;
    int __min_el_search;
    int __max_el_search;
};

#endif // SEARCHERFILES_H
