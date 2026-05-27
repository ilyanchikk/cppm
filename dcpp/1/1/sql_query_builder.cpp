#include "sql_query_builder.h"
#include <sstream>

SqlSelectQueryBuilder & SqlSelectQueryBuilder::AddColumn(const std::string & column) {
    m_columns.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
    m_from = table;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) {
    m_where_conditions.push_back({ column, value });
    return *this;
}


std::string SqlSelectQueryBuilder::BuildQuery() const {
    std::stringstream ss;

    
    ss << "SELECT ";
    if (m_columns.empty()) {
        //используем "SELECT *" если колонки пустые
        ss << "*";
    }
    else {
        for (size_t i = 0; i < m_columns.size(); ++i) {
            if (i > 0) {
                ss << ", ";
            }
            ss << m_columns[i];
        }
    }

    // Часть FROM
    ss << " FROM " << m_from;

    // Часть WHERE
    if (!m_where_conditions.empty()) {
        ss << " WHERE ";
        for (size_t i = 0; i < m_where_conditions.size(); ++i) {
            if (i > 0) {
                ss << " AND "; 
            }
            ss << m_where_conditions[i].first << "=" << m_where_conditions[i].second;
        }
    }

    ss << ";"; 

    return ss.str();
}