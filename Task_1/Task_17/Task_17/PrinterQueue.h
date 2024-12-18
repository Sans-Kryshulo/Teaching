#ifndef PRINTERQUEUE_H
#define PRINTERQUEUE_H

#include "PrintRequest.h"
#include <queue>
#include <vector>
#include <stdexcept>

class PrinterQueue {
public:
    void addRequest(PrintRequest&& request);
    PrintRequest getNextRequest();

private:
    struct Compare {
        bool operator()(const PrintRequest& a, const PrintRequest& b) {
            return a.priority < b.priority;
        }
    };

    std::priority_queue<PrintRequest, std::vector<PrintRequest>, Compare> queue;
};

#endif // PRINTERQUEUE_H
