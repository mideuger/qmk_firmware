/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"om7nP/jvLP4"


#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 1

#undef  TAPPING_TERM
#define TAPPING_TERM 170
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

#define FORCE_NKRO
