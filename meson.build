# If meson not building/pulling deps, try:
# meson setup build --wipe --clearcache \
#        --wrap-mode=forcefallback
#
## and then
#
# meson compile -C ./build/

project(
    'event_horizon',
    'c',
    meson_version: '>= 1.3.0',
    version: '0.0.1',
    default_options: [
        'c_std=c23',
        'warning_level=2',
        'force_fallback_for=sdl2,sdl2_ttf',
        'wrap_mode=forcefallback',
    ],
)

# ---------------------------------------------------------------------------
# Dependencies
# ---------------------------------------------------------------------------
sdl2_dep = dependency('sdl2', static: true)
sdl2_ttf_dep = dependency('sdl2_ttf', static: true)

ascii_sources = [
    'main_ascii.c',
]

sources = [
    'main.c',
]

cc = meson.get_compiler('c')

std_c_math = cc.find_library('m', required: true)

full_exe = executable(
    'event_horizon',
    sources,
    dependencies: [sdl2_dep, sdl2_ttf_dep, std_c_math],
    install: true,
)

ascii_exe = executable(
    'event_horizon_ascii',
    ascii_sources,
    dependencies: [std_c_math],
    install: true,
)

full_exe.outdir()
ascii_exe.outdir()
