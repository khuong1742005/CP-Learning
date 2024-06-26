#include <iostream>
#include <libpq-fe.h> // Thư viện libpq

int main()
{
    // Khởi tạo kết nối đến cơ sở dữ liệu
    PGconn *conn = PQconnectdb("dbname=mydatabase user=myuser password=mypassword");

    // Kiểm tra xem kết nối có thành công không
    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Kết nối tới cơ sở dữ liệu thất bại: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return 1;
    }

    // Thực hiện truy vấn SQL
    PGresult *res = PQexec(conn, "SELECT * FROM mytable");

    // Kiểm tra kết quả truy vấn
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "Lỗi trong quá trình thực hiện truy vấn: " << PQresultErrorMessage(res) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    // Lấy và in kết quả
    int rows = PQntuples(res);
    int cols = PQnfields(res);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << PQgetvalue(res, i, j) << "\t";
        }
        std::cout << std::endl;
    }

    // Giải phóng tài nguyên
    PQclear(res);
    PQfinish(conn);

    return 0;
}
