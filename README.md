#Description
Use with qmk. Map apple USB keybaord A1242 to windows 10. It was tested for converter/usb_usb/hasu.

###usage:

copy config.h
     keymap.c
to your project in qmk     
ex.:
./keyboards/converter/usb_usb/keymaps/<project_name>/

qmk compile

dfu-programmer atmega32u4 erase
dfu-programmer atmega32u4 flash converter_usb_usb_hasu_farynam.hex
dfu-programmer atmega32u4 reset


###Mappings:
- CMD + a -> CTRL + a
- CMD + f -> CTRL + f
- CMD + m -> CTRL + m (minimize current window
- CMD + t -> CTRL + t 
- CMD + q -> ALT+ F4 
- CMD + z -> CTRL + z
- CMD + LEFT -> HOME
- CMD + END -> END
- CMD + b -> CTRL + b