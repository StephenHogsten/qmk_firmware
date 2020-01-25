/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
// #define MATRIX_COL_PINS { B5, B4, E6, D7, C6 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }

// help w/ help/tap keys
#define TAPPING_TERM 175
#define TAPPING_TOGGLE 3
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING