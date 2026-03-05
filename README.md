# event_horizon

`event_horizon` is a small C project that renders an event-horizon inspired
visualization in two forms:

- `event_horizon`: SDL2 window renderer.
- `event_horizon_ascii`: terminal ASCII renderer.

## Requirements

You need:

- Meson
- Ninja
- A C compiler (`cc`)
- SDL2 and SDL2_ttf (or Meson wrap fallback downloads)

## Build

From the project root:

> If you're struggling to get it to compile with the below command, remove the
> `--wrap-mode=forcefallback` and `--force-fallback-for=sdl2,sdl2_ttf` flags to allow Meson to find your system's SDL2 installation.
> Note that SDL2 maybe have upgraded/changed since this project was last updated,
> so you may need to adjust the code to work with newer versions of SDL2.

- If you're on Windows; well, good luck bud.

```bash
mkdir -p ./build/
meson setup build --wipe --clearcache \
  --wrap-mode=forcefallback \
  --force-fallback-for=sdl2,sdl2_ttf
meson compile -C ./build
```

## Run

Run the SDL build:

```bash
./build/event_horizon
```

Run the ASCII build:

```bash
./build/event_horizon_ascii
```

## Notes

- On Windows, Meson emits `.exe` binaries.
- On Linux and similar systems, math functions like `sqrtf` and `floorf`
  require linking `libm` (configured in `meson.build`).
