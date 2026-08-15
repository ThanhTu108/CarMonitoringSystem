#include <logger.hpp>
int main() {
    Logger logger(
        "/home/tu/work/CarMonitoringSystem/src/"
        "common/tests/log/test_log");
    int a = 10;
    logger.info("INFO ");

    return 0;
}