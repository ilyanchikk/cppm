#include <iostream>
#include <fstream>
#include <string>

class Data {
private:
	std::string __data;
public:
	explicit Data(std::string data) : __data(std::move(data)) {}
	const std::string& get_data() const {
		return __data;
	}
};

class Formating {
public:
	virtual ~Formating() = default;
	virtual std::string format(const Data& data) const = 0;
};

class HTMLFormating : public Formating {
public:
	std::string format(const Data& data) const override {
		return "<html>" + data.get_data() + "</html>";
	}
};

class JSONFormating : public Formating {
public:
	std::string format(const Data& data) const override {
		return "{ \"data\" - \"" + data.get_data()+ "\"}";
	}
};

class TXTFormating : public Formating {
public:
	std::string format(const Data& data) const override {
		return data.get_data();
	}
};

void saveTo(std::ofstream& file, const Data& data, const Formating& formating)
{
	file << formating.format(data) << std::endl;
}

void saveToAsHTML(std::ofstream& file, const Data& data) {
	HTMLFormating formating;
	saveTo(file, data, formating);
	std::cout << "out HTML in file" << std::endl;
}

void saveToAsJSON(std::ofstream& file, const Data& data) {
	JSONFormating formating;
	saveTo(file, data, formating);
	std::cout << "out JSON in file" << std::endl;
}

void saveToAsTXT(std::ofstream& file, const Data& data) {
	TXTFormating formating;
	saveTo(file, data, formating);
	std::cout << "out txt in file" << std::endl;
}

int main(){
	std::ofstream file("out.txt");
	Data data("TEST TEXT");

	saveToAsHTML(file, data);
	saveToAsJSON(file, data);
	saveToAsTXT(file, data);
	
	return 0;
}
