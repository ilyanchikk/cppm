#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string data1 = data;
        std::reverse(data1.begin(),data1.end());
        std::cout << data1;
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& link, const std::string& data) const {
        std::cout << "<a href =";
        text_->render(link);
        std::cout << ">";
        text_->render(data);
        std::cout << "< / a>";
    }
};

int main() {
    std::cout << "\nClass Text" << std::endl;
    auto text_block1 = new Text();
    text_block1->render("Hello world");
    std::cout << std::endl;

    std::cout << "\nClass Paragraph" << std::endl;
    auto text_block2 = new Paragraph(new Text());
    text_block2->render("Hello world");
    std::cout << std::endl;

    std::cout << "\nClass Link" << std::endl;
    auto text_block3 = new Link(new Text());
    text_block3->render("netology.ru","Hello World!");
    std::cout << std::endl;
}