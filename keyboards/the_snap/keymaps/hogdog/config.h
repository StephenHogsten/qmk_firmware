/* Copyright 2019 Stephen Hogsten
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// place overrides here

// help w/ help/tap keys
#define TAPPING_TERM 175
#define TAPPING_TOGGLE 3
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

#define MOUSEKEY_INTERVAL 25
#define MOUSEKEY_MAX_SPEED 8

#define COMBO_COUNT 1

#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D7 }
#define ENCODER_RESOLUTION 2

#define RGB_DI_PIN F0
#define RGBLED_NUM 16
// #define RGBLED_SPLIT 8
#define RGBLIGHT_SPLIT true