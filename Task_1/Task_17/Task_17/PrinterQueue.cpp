#include "PrinterQueue.h"

void PrinterQueue::addRequest(PrintRequest&& request) {
    queue.push(std::move(request));
}

PrintRequest PrinterQueue::getNextRequest() {
    if (queue.empty()) {
        throw std::runtime_error("No print requests available");
    }
    PrintRequest request = std::move(const_cast<PrintRequest&>(queue.top()));
    queue.pop();
    return request;
}
