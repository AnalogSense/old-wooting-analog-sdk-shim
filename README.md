# old-wooting-analog-sdk-shim

Drop-in replacement for [Wooting's old analog SDK](https://github.com/WootingKb/wooting-analog-sdk-old) which unfortunately doesn't work anymore with their new keyboards or even old keyboards with new firmware.

## 64-bit version

The 64-bit version is quite straight-forward as it can simply leverage [the new analog SDK](https://github.com/WootingKb/wooting-analog-sdk), so it is compatible with its plugins as well.

## 32-bit version

Unfortunately, the new analog SDK can't be loaded into a 32-bit process, so this version instead uses [soup::AnalogueKeyboard](https://github.com/calamity-inc/Soup/blob/senpai/soup/AnalogueKeyboard.cpp) which does support more than just Wooting keyboards, but no such thing as plugins.
