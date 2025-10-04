#include <fstream>
#include <iostream>
#include "tele/packet.hpp"

using namespace tele;

int main() {
    { // write
    std::ofstream out("../data/test.log", std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "Error: Could not create data/test.log (make sure 'data' directory exists)\n";
        return 1;
    }
    Packet p1{1727130000000ULL, 123, 6.9271, 79.8612, 12.5f, 88};
    Packet p2{1727130060000ULL, 123, 6.9272, 79.8613, 0.0f, 87};
    serialize(out, p1);
    serialize(out, p2);
  }
  { // read
    std::ifstream in("../data/test.log", std::ios::binary);
    Packet p{};
    while (deserialize(in, p)) {
        std::cout << "timestamp: " << p.timestamp
                  << ", vehicle_id: " << p.vehicle_id
                  << ", lat: " << p.lat
                  << ", lon: " << p.lon
                  << ", speed: " << p.speed
                  << ", battery: " << static_cast<int>(p.battery)
                  << "\n";
    }
  }
}