#include <cstdint>
// hp type
/* std::uint16_t is standard 32 bits on all systems
unsigned int is not standard */
typedef std::uint16_t well_type;

// stat types 
typedef std::uint8_t stat_type; // 0 - 255

// Experience Type
typedef std::uint64_t experience_type;

// Level Type
typedef std::uint16_t level_type;