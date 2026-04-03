#include <iostream>
#include <Windows.h>
#include <string>
#include <pqxx/pqxx>

class db_manager {
private:
	pqxx::connection* conn;
	std::string connection_string;
public:
	db_manager(const std::string& con_str) : connection_string(con_str), conn(nullptr) { // соединение с бд в конструкторе
		try {
			conn = new pqxx::connection(connection_string);
	
			if (conn->is_open()) {
				std::cout << "DB open " << conn->dbname() << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			throw;
		}
	}
	int get_id_client(std::string f_name, std::string s_name) { //получаем айди клиента
		try {
			pqxx::work tx(*conn);
			return  tx.query_value<int>("SELECT id FROM users WHERE f_name = '"+f_name+"' AND s_name = '"+s_name+"'");
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void create_table() { //создаем таблицы
		try {
			pqxx::work tx(*conn);
			tx.exec(
				"CREATE TABLE IF NOT EXISTS users (" 
				"id SERIAL PRIMARY KEY,"
				"f_name VARCHAR(30) NOT NULL,"
				"s_name VARCHAR(30) NOT NULL,"
				"email VARCHAR(30) NOT NULL);"
			);

			std::cout << "table users created or created earlier " << std::endl;

			tx.exec(
				"CREATE TABLE IF NOT EXISTS phone("  
				"id_user INTEGER REFERENCES users(id),"
				"phone VARCHAR(30));"
			);
			std::cout << "table phone created or created earlier" << std::endl;
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void add_client(std::string f_name, std::string s_name, std::string email) { //добавляем клиентов
		try {
			pqxx::work tx(*conn);
			tx.exec("INSERT INTO users(f_name,s_name,email) VALUES('"+ tx.esc(f_name)+"','"+ tx.esc(s_name) +"','"+ tx.esc(email) +"')");
			tx.commit();
			std::cout << "client " << f_name << " " << s_name << " add in DB " << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void add_phone_client(std::string f_name, std::string s_name, std::string number) { //добавляем телефон клиента
		try {
			std::string id_client = std::to_string(get_id_client(f_name, s_name));
			pqxx::work tx(*conn);
			tx.exec("INSERT INTO phone(id_user,phone) VALUES('"+ tx.esc(id_client) + "','" + tx.esc(number) + "')");
			tx.commit();
			std::cout << "client " << f_name << " " << s_name << " with id= " << get_id_client(f_name, s_name) << " add phone " << number << " in db. " << std::endl; //get_id_client(f_name, s_name)
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void update_client(std::string f_name, std::string s_name, std::string email, std::string new_f_name, std::string new_s_name, std::string new_email) {// обновление данных клиента
		try {
			pqxx::work tx(*conn);
			tx.exec("UPDATE users SET f_name = '" + new_f_name + "', s_name = '" + new_s_name + "', email = '" + new_email + "' WHERE f_name = '" + f_name + "' AND s_name = '" + s_name + "';");
			tx.commit();
			std::cout << "UPDATE client " << f_name << " " << s_name << "  in db ON " << new_f_name << " " << new_s_name << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void delete_phone(std::string f_name, std::string s_name) {// удалить телефон
		try {
			std::string id_client = std::to_string(get_id_client(f_name, s_name));
			pqxx::work tx(*conn);
			tx.exec("DELETE FROM phone WHERE id_user = '"+ id_client +"'");
			tx.commit();
			std::cout << "DELEETE phone client " << f_name << " " << s_name << " with id= " << get_id_client(f_name, s_name) << " in db. " << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void delete_client(std::string f_name, std::string s_name) {// удалить клиента
		try {
			pqxx::work tx(*conn);
			tx.exec("DELETE FROM users WHERE f_name = '"+f_name+"' AND s_name = '"+s_name+"'");
			tx.commit();
			std::cout << "DELETE client " << f_name << " " << s_name << "  in db " << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	void find_client(std::string search_str) {// найти клиента 
		try {
			pqxx::work tx(*conn);
			for (auto [f_name, s_name] : tx.query<std::string, std::string>(
				"SELECT f_name, s_name FROM users JOIN phone on id = id_user WHERE f_name ILIKE '%" + search_str + "%' OR s_name ILIKE '%" + search_str + "%' OR email ILIKE '%" + search_str + "%' OR phone ILIKE '%" + search_str + "%'"))
			{
				std::cout << "FOUND CLIENT " << f_name << " " << s_name << "  in db " << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
};

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	const std::string con_str{ "host=localhost port=5432 dbname=test user=postgres password=admin" };
	db_manager db(con_str);
	db.create_table();
	db.add_client("Ilya", "Polot", "123@mail.ru");
	db.add_client("Vasya", "Molot", "456@mail.ru");
	//db.add_phone_client("Ilya", "Polot", "89991233322"); // Для проверки методов раскомментировать нужный
	//db.add_phone_client("Vasya", "Molot", "89212234135");
	//db.delete_phone("Ilya", "Polot");
	//db.delete_client("Ilya", "Polot");
	//db.add_client("Ilya", "Polot", "123@mail.ru");
	//db.update_client("Ilya","Polot","456@mail.ru", "IIlya", "PPolot", "123456@mail.ru");
	//db.find_client("456");
	//db.find_client("322");

	return 0;
	
}