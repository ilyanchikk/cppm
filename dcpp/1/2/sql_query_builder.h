#pragma once

#include <string>   
#include <vector>
#include <utility>
#include <map>


class SqlSelectQueryBuilder {

public:

    SqlSelectQueryBuilder() = default;

    SqlSelectQueryBuilder& AddColumn(const std::string& column); 

    SqlSelectQueryBuilder& AddFrom(const std::string& table); 

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value); 

    std::string BuildQuery() const; 
    SqlSelectQueryBuilder& AddColumn(const std::vector<std::string>& columns) noexcept;
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

private:

    std::vector<std::string> m_columns; 
    std::string m_from; 
    std::vector<std::pair<std::string, std::string>>  m_where_conditions;

};
