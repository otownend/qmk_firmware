# Owen’s Iris layout

To clean and build:  
`$ qmk compile --clean --keyboard keebio/iris/rev6 --keymap otownend`
or
`$ qmk compile --clean --keyboard keebio/iris/rev8 --keymap otownend`

To flash:  
`$ qmk --verbose flash --keyboard keebio/iris/rev6 --keymap otownend`

Or for the rev8:
* Go to `~/CLionProjects/Keyboard/qmk_firmware`
* Then copy `keebio_iris_rev8_otownend.uf2` onto the RP2040 drive once it's mounted.
