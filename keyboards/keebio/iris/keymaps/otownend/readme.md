# Owen’s Iris layout

## Rev 8
To clean and build:  
`$ qmk compile --clean --keyboard keebio/iris/rev8 --keymap otownend`

To flash:
* Go to `~/CLionProjects/Keyboard/qmk_firmware`
* Then copy `keebio_iris_rev8_otownend.uf2` onto the RP2040 drive once it's mounted.

## Rev 6
Pre-step
`$ git submodule update --init --recursive lib/lufa`
Go to config.h and uncomment the define for REV6
Go to rules.mk and change the booloader to atmel-dfu

To clean and build:  
`$ qmk compile --clean --keyboard keebio/iris/rev6 --keymap otownend`

To flash:  
`$ qmk --verbose flash --keyboard keebio/iris/rev6 --keymap otownend`
