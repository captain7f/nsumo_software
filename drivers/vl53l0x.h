#ifndef VL53L0X_H
#define VL53L0X_H

#include <stdbool.h>
#include <stdint.h>

#define VL53L0X_OUT_OF_RANGE (8190)

/* Comment these out if not connected */
#define VL53L0X_FRONT
#define VL53L0X_LEFT
#define VL53L0X_RIGHT
#define VL53L0X_FRONT_LEFT
#define VL53L0X_FRONT_RIGHT

typedef enum
{
    VL53L0X_IDX_FRONT,
    VL53L0X_IDX_LEFT,
    VL53L0X_IDX_RIGHT,
    VL53L0X_IDX_FRONT_LEFT,
    VL53L0X_IDX_FRONT_RIGHT,
    VL53L0X_IDX_COUNT
} vl53l0x_idx_t;


typedef uint16_t vl53l0x_ranges_t[VL53L0X_IDX_COUNT];

/**
 * Initializes the sensors in the vl53l0x_idx_t enum.
 * @note Each sensor must have its XSHUT pin connected.
 */
bool vl53l0x_init(void);

/**
 * Does a single range measurement
 * @param idx selects specific sensor
 * @param range contains the measured range or VL53L0X_OUT_OF_RANGE
 *        if out of range.
 * @return True if success, False if error
 * @note   Polling
 */
bool vl53l0x_read_range_single(vl53l0x_idx_t idx, uint16_t *range);

/**
 * Reads all sensors. This is faster than reading sensors individually because
 * we do the measures in parallel.
 * @param ranges contains the measured ranges (or VL53L0X_OUT_OF_RANGE
 *        if out of range).
 * @return True if success, False if error
 * @note   Polling
 */
bool vl53l0x_read_range_multiple(vl53l0x_ranges_t ranges);

bool vl53l0x_start_sysrange(vl53l0x_idx_t idx);
bool vl53l0x_wait_sysrange(vl53l0x_idx_t idx);

#endif /* VL53L0X_H */
