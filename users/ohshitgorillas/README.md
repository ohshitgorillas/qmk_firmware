# ohshitgorillas's QMK Userspace

Shared code across my QMK keyboards:
- Luminkey LX60
- KBDfans Tofu60 2.0
- Drop x OLKB Planck rev7

## Features

### Universal (All Keyboards)
- **OS Detection**: Automatically switches to layer 0 for macOS/iOS, layer 1 for Windows/Linux
- **Leader Key Sequences**: Shared leader key functionality (to be implemented)

### 60% Specific (LX60 & Tofu60)
- Shared timing configurations (to be implemented)
- Identical keymap layouts (to be implemented)

## Structure

- `ohshitgorillas.c` - Main implementation
- `ohshitgorillas.h` - Header file with function declarations
- `config.h` - Shared configuration options
- `rules.mk` - Build rules for source files

## License

Copyright 2025 ohshitgorillas

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
