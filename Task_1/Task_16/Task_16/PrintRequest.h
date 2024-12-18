#ifndef PRINTREQUEST_H
#define PRINTREQUEST_H

#include <string>
#include <chrono>

class PrintRequest {
private:
    std::string user; // ������������, ����������� ������
    std::chrono::system_clock::time_point time; // ����� �������
    int priority; // ��������� �������

public:
    PrintRequest(const std::string& user, int priority);
    PrintRequest(const PrintRequest& other); // ����������� �����������
    PrintRequest(PrintRequest&& other) noexcept = default; // ����������� ��������
    ~PrintRequest() = default;

    PrintRequest& operator=(const PrintRequest& other); // �������� ������������
    PrintRequest& operator=(PrintRequest&& other) noexcept = default; // �������� ������������ ��������

    const std::string& getUser() const;
    const std::chrono::system_clock::time_point& getTime() const;
    int getPriority() const;
};

#endif
