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
####General:
- CMD + a -> CTRL + a
- CMD + f -> CTRL + f
- CMD + r -> CTRL + r
- CMD + m -> ALT, space, m (minimize current window)
- CMD + t -> CTRL + t 
- CMD + q -> ALT+ F4 
- CMD + z -> CTRL + z
- CMD + LEFT -> HOME
- CMD + END -> END

- CMD + b -> CTRL + b (bold)
- CMD + s -> CTRL + s
- CMD + space -> CMD
- ALT + left -> ctrl + left arrow
- ALT + right -> ctrl + right arrow
 
- for Intellij:
- CMD + [ -> CTRL + [
- CMD + ] -> CTRL + ]
- CMD + n -> CTRL + n (search class)

- CMD + SHIFT + F -> CTRL + SHIFT + F (search in path)
- CMD + SHIFT + R -> CTRL + SHIFT + R (replace in path)