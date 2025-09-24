#include <cstdint>

namespace tele {

    struct packet {
        std::uint64_t timestamp;
        std::uint32_t vehical_id;
        double lat;
        double lon;
        float speed;
        std::uint8_t battery;
    };

}