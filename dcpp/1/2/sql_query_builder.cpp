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

    SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::vector<std::string>&columns) noexcept {
        // Мы можем просто вставить весь диапазон из входного вектора 
        // в конец нашего внутреннего вектора columns_
        m_columns.insert(m_columns.end(), columns.begin(), columns.end());

        return *this; // Возвращаем себя для "цепочки"
    }

    SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>&kv) noexcept {
        for (const auto& m_pair : kv) {
            AddWhere(m_pair.first, m_pair.second);
        }

        return *this;
    }