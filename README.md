# ZMK Configuration - Local Build Instructions

This is a ZMK (Zephyr-based Mechanical Keyboard) firmware configuration for the Corne keyboard with nice!nano v2 and nice!oled display.

## Prerequisites

Before building locally, you'll need to install:

1. **West Tool** - Zephyr's meta-tool for managing workspaces
   ```bash
   pip3 install west
   ```

2. **Zephyr SDK** - The Zephyr development environment
   - Download from: https://github.com/zephyrproject-rtos/sdk-ng/releases
   - Or follow Zephyr's installation guide: https://docs.zephyrproject.org/latest/develop/getting_started/index.html

3. **CMake** (usually included with Zephyr SDK or install separately)

4. **Git**

## Building the Firmware

### Step 1: Initialize the West Workspace

From the project root directory, initialize and update the workspace:

```bash
west init -l config
west update
```

This will:
- Initialize the West workspace
- Download the ZMK firmware (as specified in `config/west.yml`)
- Download any additional dependencies (like `zmk-nice-oled`)

### Step 2: Build the Firmware

Based on your `build.yaml`, you can build:

**Left half:**
```bash
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=corne_left\ nice_oled -DZMK_CONFIG="$(pwd)/config"
```

**Right half:**
```bash
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=corne_right\ nice_oled -DZMK_CONFIG="$(pwd)/config"
```

### Step 3: Find the Build Output

After building, the firmware files will be located in:
- `build/zephyr/zmk.uf2` - UF2 file for flashing

## Flashing the Firmware

1. Put your nice!nano v2 into bootloader mode (usually by double-pressing the reset button)
2. Copy the `zmk.uf2` file to the mounted USB drive
3. The device will automatically flash and reboot

## Project Structure

- `config/` - Your ZMK configuration files
  - `corne.keymap` - Keyboard keymap definition
  - `corne.conf` - Build configuration (display settings, etc.)
  - `west.yml` - West manifest for dependencies
  - `display/corne_widget.c` - Custom display widget
- `build.yaml` - GitHub Actions build matrix (for CI/CD)
- `zephyr/module.yml` - Zephyr module configuration

## Troubleshooting

- If `west init` fails, make sure you're in the project root directory
- If dependencies fail to download, check your internet connection and try `west update` again
- If build fails, ensure all prerequisites are installed and the Zephyr SDK is properly configured

## Additional Resources

- ZMK Documentation: https://zmk.dev/docs
- ZMK Discord: https://zmk.dev/community/discord
- nice!nano Documentation: https://nicekeyboards.com/docs/nice-nano

