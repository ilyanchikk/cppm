#include "sql_query_builder.h"
#include <iostream>            
#include <cassert> 
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // объект-строитель
    SqlSelectQueryBuilder query_builder;

    query_builder.AddColumn("name").AddColumn("phone"); // добавили колонки
    query_builder.AddFrom("students");                 // указали таблицу
    query_builder.AddWhere("id", "32").AddWhere("name", "John"); // добавили условия

    // запрос
    std::string query = query_builder.BuildQuery();

    // Ожидаемый результат для проверки построения
    const std::string expected_query = "SELECT name, phone FROM students WHERE id=32 AND name=John;";

    std::cout << "Построенный запрос: " << query << std::endl;
    std::cout << "Исходный запрос:  " << expected_query << std::endl;

    // проверяем 
    assert(query == expected_query);
    std::cout << "Запрос совпадает" << std::endl;

    // Проверка SELECT *
    SqlSelectQueryBuilder query_builder_all;
    query_builder_all.AddFrom("users"); 
    query_builder_all.AddWhere("year", "1996");

    std::string query_all = query_builder_all.BuildQuery();
    const std::string expected_all = "SELECT * FROM users WHERE year=1996;";

    std::cout << std::endl << "Построенный запрос (SELECT): " << query_all << std::endl;
    std::cout << "Исходный запрос (SELECT *): " << expected_all << std::endl;
    assert(query_all == expected_all);
    std::cout << "Запрос (SELECT *) совпадает" << std::endl;

    //Проверка на перезапись AddFrom
    SqlSelectQueryBuilder query_builder_from;
    query_builder_from.AddFrom("old_table");
    query_builder_from.AddFrom("new_table");
    query_builder_from.AddColumn("test");

    std::string query_from = query_builder_from.BuildQuery();
    const std::string expected_from = "SELECT test FROM new_table;";

    std::cout << std::endl <<  "Построенный запрос (from): " << query_from << std::endl;
    std::cout << "Исходный запрос (from): " << query_from << std::endl;
    assert(query_from == expected_from);
    std::cout << "Запрос (AddFrom) совпадает!" << std::endl;

    return 0;
}