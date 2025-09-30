#include "tele/packet.hpp"
#include <ostream>
#include <istream>

namespace tele {

    void serialize(std::ostream& os, const Packet& pkt) {
        write_le(os, pkt.timestamp);
        write_le(os, pkt.vehicle_id);
        write_le(os, pkt.lat);
        write_le(os, pkt.lon);
        write_le(os, pkt.speed);
        write_le(os, pkt.battery);
    }

    bool deserialize(std::istream& is, Packet& out) {
        out.timestamp = read_le<std::uint64_t>(is);
        out.vehicle_id = read_le<uint32_t>(is);
        out.lat = read_le<double>(is);
        out.lon = read_le<double>(is);
        out.speed = read_le<float>(is);
        out.battery = read_le<uint8_t>(is);
        return static_cast<bool>(is);
    }
}