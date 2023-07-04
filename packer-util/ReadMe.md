# Packer-util

The purpose of packer util is to pack all game assets into a singular .dat file.  This will allow for all assets to be compressed and then decompressed on game load, as well allow easier checksum verification to ensure the data hasn't been corrupted.

## Structure

### Table of contents

The table of contents is included at the top of the file for easy indexing and quick loading.

|Item|Bytes|
|---|---|
|Name|12|
|Separator|1|
|Location|12|

The location denotes the starting address of the file within the packed file.  This allows the program to look at the table of contents to find a specific file and then immediately jump to it's data structure as defined below.
### Data

| Bytes    |Purpose|Compressed|
|----------|---|---|
| 12       |Filename|N|
| 8        |Type|N|
| 12       |Size|N|
| Variable | Content|Y|

## Compilation notes

Run zlibinstall.bat to install zlib for windows.