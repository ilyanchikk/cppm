#include "searcherFiles.h"
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QSettings>
#include <QFileInfo>

void searcherFiles::loadConfig(const QString& path) {
    if(!QFileInfo::exists(path)) {
         qWarning() << "Невозможно открыть файл конфигурации для индексации файлов, будут установлены настройки по умолчанию";
    }

   QSettings settings(path, QSettings::IniFormat);
   settings.beginGroup("index");
     __path     = settings.value("path","./catalog_files/").toStringList();                 // путь
     __extention   = settings.value("extention", "txt").toStringList();  //расширение файлов
     __min_el_search = settings.value("min_el_search", "3").toInt(); // минимальное количество букв в слове
     __max_el_search = settings.value("max_el_search", "32").toInt(); // максимальное количество букв в слове
     settings.endGroup();
     qInfo() << "Произведено чтение конфигурационного файла";
     qInfo() << "Путь для поиска __path записан: " << __path;
     qInfo() << "Загруженные расширения: " <<  __extention;
     qInfo() << "Минимальное количество букв в слове: " <<  __min_el_search;
     qInfo() << "Максимальное количество букв в слове: " <<  __max_el_search;

}
QStringList searcherFiles::getPath() {
    return __path;
}
QStringList searcherFiles::getExtention(){
    return __extention;
}
int searcherFiles::getMinEl(){
    return __min_el_search;
}
int searcherFiles::getMaxEl(){
    return __max_el_search;
}
QStringList searcherFiles::foundFiles(QStringList path, QStringList extention) {
    QStringList found;      // сюда накапливаем полные пути всех подходящих файлов

      QStringList masks;     // extentions .txt
      for (const QString& ext : extention) {
          masks << ("*." + ext);
      }

      for (const QString& pth : path) {
          if (!QDir(pth).exists()) {    //Наличие каталога
              qDebug() << QString("Каталог не найден").arg(pth);
              continue;
          }

          QDirIterator file(pth, masks, QDir::Files, QDirIterator::Subdirectories);
          int count_file{0};
          while (file.hasNext()) {           // hasNext() — есть ли ещё файлы; next() — перейти к следующему и вернуть его путь
               found << file.next();     // полный путь к очередному найденному файлу
               count_file++;
          }
          qInfo() << QString("Произведено индексирование файлов, файлов найдено: %1").arg(count_file);
      }

      return found;
}
