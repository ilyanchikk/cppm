#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};

void saveTo(std::ofstream &file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}

/*
Проблема разделения интерфейса:
класс родитель Printable содержит в себе реализацию сохранения данных в форматах html,text,json. В классах наследниках необходимо
переопределять или инорировать методы базового класса, которые не используются. Так же нарушается принцип едиственной ответственности
(класс выполняет не одну задачу). Так же при изменения класса(удалении, изменении, добавления другого расширения) необходимы изменения
в других частях программы(class Printable,class Data,void saveTo).

Проблема открытости/закрытости:
Принцип: открыты для расширения, закрыты для изменения. Тут наборот. Масштабировать ПО без изменений в действущих классах невозможно.
Для добавления нового расширения необходимы правки в  class Printable,class Data,void saveTo, void saveToAs*

Проблема нарушения lsp
Наследник класс Data выбрасывает исключения, которые базовый класс Pritntable не предполагал. Подкласс выполняет больше задач чем базовый класс.
*/