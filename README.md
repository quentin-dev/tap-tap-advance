# Tap Tap Advance

This is an attempt at a GBA rythm game, most likely my entry for [GBA JAM 2021](https://itch.io/jam/gbajam21).

## Building the game

### Requirements

This project has the same requirements as [butano](https://github.com/GValiente/butano), so you need devkitArm and its GBA toolchain installed.

### Instructions

1. Clone the repo and `cd` into it
2. `git submodule update --init`
3. `make -j$(nproc)`
4. Open `tap-tap-advance.gba` with your favorite emulator and play!