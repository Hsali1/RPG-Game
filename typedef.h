#include <cstdint>
// hp type
/* std::uint16_t is standard 32 bits on all systems
unsigned int is not standard */
typedef std::uint16_t hp_type;

// stat types 
typedef std::uint8_t stat_type; // 0 - 255