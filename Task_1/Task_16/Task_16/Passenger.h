#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger {
private:
    int timeArrival;

public:
    Passenger(int timeArrival);
    Passenger(const Passenger& other) = delete; 
    Passenger(Passenger&& other) noexcept = default;
    ~Passenger() = default;

    Passenger& operator=(const Passenger& other) = delete;
    Passenger& operator=(Passenger&& other) noexcept = default;

    int getTimeArrival() const;
};

#endif
