# Bluetrum Tools

by: https://github.com/kagaimiq/bluetrum-tools
Some tools for some obscure RISC-V bluetooth audio chips made by Bluetrum (the "AB"/"A3" and "BT" branded chips).
These ones seem to begin dominating the low-end previously held with chips made by companies such as JieLi or Buildwin.

## What's up

### download.py

A simple tool that allows to read and write flash of an bluetrum chip.

It supports both the USB and UART interfaces.

For the USB interface it depends on the `scsiio` library which I have made myself and I haven't bothered making it a proper package, so if you want that, you can find it in [jl-uboot-tool](https://github.com/kagaimiq/jl-uboot-tool), however getting into the USB bootloader is a much more involved task than getting into the UART bootloader so you probably won't care about that one anyway. ~ the UART bootloader works fine, and is easy to use anyway.

For the UART interface, it depends on the `pyserial` library to talk to the serial port.

In terms of hardware, you need a 3.3v UART bridge adapter, where the TX and RX are being connected together (this tool assumes data sent over TX is echoed back on RX), the manufacturer suggested way of accomplishing that is to use a 200 Ohm resistor.

Then you need to find a UART download pin, from chip's point of view this is usually the `PB3` GPIO (usually wired out together with USB's D+ line aka `USB_DP`, so if your device happens to have a USB port, you can try that), also it's usually available on the `PA7` GPIO, and on some other pins depending on the specific chip you have, for example AB560x/PRAO chips can use the `VUSB` pin for that too.

When you've done it correctly, the tool should be able to talk with the chip:

```
$ python3 download.py --port /dev/ttyUSB0
Trying to synchronize... done.
 Chip ID:       b'BLUEPRAO\x01\x00\x00\x00'
 Load address:  $00012000
 Init. commkey: $ECA4756B
 New commkey:   $8D1814D7
Changing baudrate to 921600 baud...
- Code key: >>>> 5C3CEDB4 <<<<
- Flash device ID: 856013
- Flash unique ID: 42503150363035060112b13847032078
- Flash size: 524288 bytes
```

Currently the interface is rather limited, yet it's fully suitable for basic flash programming.

If you don't specify an action, it's going to print out some bootloader info, and if the code blob has been executed correctly, the "code key" (key used for additional scrambling of the code blob in the firmware), the flash IDs (the JEDEC ID with opcode $9F and the unique ID with opcode $4B), and the calculated size of the flash.

The `-r`/`--reboot` option can be used to reboot the chip after the tool has done doing its thing.

As for the actual operation, the type of the operation is specified as `read`, `write` or `erase` (at present it can do only a single type of operation at a time), and the parameters (address, size and path) follow.

The `read` operaton takes one or more pairs of `<address> <size> <file>`, that will dump an area of `<size>` bytes (zero means 'whole flash') starting at `<address>` into file `<file>`.

The `write` operation takes one or more pairs of `<address> <file>`, that will write the `<file>` into the flash starting at `<address>`.
The erase of the section is performed automatically, so you don't have to do it manually, and the address/size alignment situation needs to be considered.

The `erase` operation takes one or more pairs of `<address> <size>` and erases an area of `<size>` bytes (again, zero means 'whole flash') starting at `<address>`. Note that the address and size will be adjusted to the size of an small eraseblock (4096 bytes).

----

This tool has been tested only with the "PRAO" (AB560x series) chips, so it's not guaranteed to work on other chips (with the code blob being a biggest concern).
Also it assumes the chip has an SPI NOR flash chip attached internally to GPIOG, so OTP chips, or an SPI NAND, I²C EEPROM or whatever might be on/with your chip, are out of question at the moment.

### fwunpack.py

A firmware image unpacker.

Each supplied image is unpacked to a respective `<image filename>_unpack` directory, that has a following structure:
```
 <image>_unpack
  |--- decrypted.bin     <== the image after all of the decryption processes were performed with it
  |--- header.bin        <== the image's boot header and boot code (in a format used by the xmaker, etc)
  |--- boot-code.bin     <== the boot code itself (without any metadata such as the load address, etc.)
  |--- app.bin           <== main application code blob
  |--- res.bin           <== resources blob
  '--- res               <== unpacked resources
       |--- 00__order__00.txt    <== file that has the original order of the resources
       '--- **everything else**  <== resource files

```

If you have a flash dump, most likely than not you need to obtain the key that is used for the scrambling of the code area.

### fwmake1.py

A firmware image maker.

The result is byte-exact to the ones found to be made with the vendor's tools (xmaker);
One difference right now is that additional stuff residing in the header area (i.e. everything except the boot header, boot code and the region table with its CRC)
is not being generated, since I haven't figured out them well enough,
meaning that it's not yet suitable to be used to modify the firmware (previously decomposed with the `fwunpack.py` script above, for example).

The `--no-res-scramble` option disables the scrambling of the resource blob area, if you so desire.
Note that a proper resource blob is not automatically generated if you e.g. specify a directory instead of a file, instead it should be generated separately somehow.

### mkheader.py

Makes the `header.bin` file (or a minimal bootable image, if such option has been provided with a `-b`/`--bootagle` flag).

### mkresblob.py

Makes the `res.bin` file containing resource files in the format used by the firmware.

It takes either a directory (from which it will recursively scan files and add into the blob's flat structure) or a "layout file".

## Extra info

Here I'll put some 'useful' info until I find a proper place for them.

### How to decipher the chip markings

Let's say you have a chip that is marked as "PHSA15E2F".
What does that mean?

Look closely at the last five figures, in this example these are "15E2F".

The first four figures are in fact the model number itself encoded in a hexidecimal form, so if you convert "15E2" to decimal you'll get "5602".
And the last figure is the designation of a specific variation of the chip, in this case it is "F".

So the actual model of the chip turns out to be "AB5602F". Where did the "AB" part come from?

Well, you can judge it by the logo that your chip has. If it is "AB" (or "A3" depending on how you read it), that would be "AB".
If it is "BT" (a letter 'B' with a tilted letter 'T' inside of it), that would be "BT".

Let's take another example, "C1618C". What could *that* even mean?
Here, it's basically the same thing as above, it's just the first three letters missing.
With the same tricks as above, it turns out to be: "AB" + 0x1618 -> "5656" + "C" = "AB5656C".

And just for the sake of it, what does "JHEB14F2C" mean? Once again, "AB" + 0x14F2 -> "5362" + "C" = "AB5362C".

Here is the detailed breakdown of several known chip markings:

```
  .-----------. .------------. .-------------. .-------------.
  |  CDDDDE   | |  ppnnnnEi  | |  ABBCDDDDE  | |  ppnnnnEi   |
  |  xxxxxx   | |   CDDDDE   | |   xxxxxx    | |  ABBCDDDDE  |
  '-----------' |   xxxxxx   | |    yyww     | |   xxxxxx    |
                '------------' '-------------' |    yyww     |
                                               '-------------' 

A      = apparently the chip code name, e.g. 'P' = 'PRAO', 'C' = 'CRWN', 'E' = 'EPIC', 'J' = 'JAZZ', etc.
BB     = unknown
C      = unknown
DDDD   = model number in hexadecimal form (e.g. "15E2" means 5602)
E      = chip variant letter (A, B, C, D, etc.)

xxxxxx = manufacturing code

yy     = production year
ww     = production week

pp     = prefix (AB/BT)
nnnn   = model number in decimal form (e.g. 8918)
i      = flash density code (in Mbits), presumeably.
```

### Known code names

Each chip design carries its own "code name", which, among other things, is reflected in the "chip ID" field in the bootloader protocol, and in the boot header.

| Codename | Chips            |
|----------|------------------|
| CRWN     | AB530x / AB32VG1 |
| DREM     |                  |
| EPIC     | AB532x           |
| GOAL     |                  |
| HONR     | AB537x, AB535x(?) |
| IDEA     |                  |
| JAZZ     | AB536x           |
| KING     |                  |
| LUCK     |                  |
| MAGI     |                  |
| NOVA     | AB561x           |
| OSCR     |                  |
| ABLE     |                  |
| PRAO     | AB560x           |
| QUEN     | BT895x           |
| RCKT     |                  |
| SMAT     | AB563x, BT892x, BT891x(?) |
| TYPC     |                  |
| ZOOM     | AB571x           |
| EAGR     | AB568x           |

## Resources

- Bluetrum seemingly-official [GitHub](https://github.com/BLUETRUM) and [Gitee](https://gitee.com/Bluetrum) organizations
  * Here you can find some resources for the "AB32VG1" (aka AB5301A) chip.
- [Their website](https://www.bluetrum.com/)
- [Random SDK dump repo](https://github.com/ZhiqingLi/Sdk_Refresh) containing among other things, SDKs for the Bluetrum Crown (AB530x) and Epic (AB532x) chips.
