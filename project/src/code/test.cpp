#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

std::string getCurrentDateTime()
{
    // Get current time from system clock
    auto now = std::chrono::system_clock::now();

    // Convert to time_t (seconds since epoch)
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convert to local time
    std::tm *local_time = std::localtime(&now_time);

    // Format: YYYY-MM-DD HH:MM:SS
    char buffer[20];
    std::strftime(buffer, sizeof(buffer),
                  "%Y-%m-%d %H:%M:%S", local_time);

    return std::string(buffer);
}

int main()
{
    std::cout << "Current date & time: "
              << getCurrentDateTime() << std::endl;
}
