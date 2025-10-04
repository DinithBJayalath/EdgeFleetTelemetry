#include <algorithm>
#include <bit>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace tele {

    struct Packet {
        std::uint64_t timestamp;
        std::uint32_t vehicle_id;
        double lat;
        double lon;
        float speed;
        std::uint8_t battery;
    };

    template <class T>
    inline void write_le(std::ostream& os, T& value) {
        static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
        unsigned char bytes[sizeof(T)];
        std::memcpy(bytes, &value, sizeof(T));
        if constexpr (sizeof(T) > 1) {
            if constexpr (std::endian::native == std::endian::big) {
                std::reverse(bytes, bytes + sizeof(T));
            }
        }
        os.write(reinterpret_cast<const char*>(bytes), sizeof(T));
    }

    template <class T>
    inline T read_le(std::istream& is) {
        static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
        unsigned char bytes[sizeof(T)];
        is.read(reinterpret_cast<char*>(bytes), sizeof(T));
        if (!is) return T{};
        if constexpr (sizeof(T) > 1) {
            if constexpr (std::endian::native == std::endian::big) {
                std::reverse(bytes, bytes + sizeof(T));
            }
        }
        T value{};
        std::memcpy(&value, bytes, sizeof(T));
        return value;
    }

    void serialize(std::ostream& os, const Packet& pkt);
    bool deserialize(std::istream& is, Packet& out);
}