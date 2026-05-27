#pragma once

#include <string>   
#include <vector>
#include <utility>


class SqlSelectQueryBuilder {

public:

    SqlSelectQueryBuilder() = default;

    SqlSelectQueryBuilder& AddColumn(const std::string& column); 

    SqlSelectQueryBuilder& AddFrom(const std::string& table); 

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value); 

    std::string BuildQuery() const; 

private:

    std::vector<std::string> m_columns; 
    std::string m_from; 
    std::vector<std::pair<std::string, std::string>>  m_where_conditions;

};
