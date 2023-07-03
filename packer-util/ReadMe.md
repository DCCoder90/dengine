# Packer-util

The purpose of packer util is to pack all game assets into a singular .dat file.  This will allow for all assets to be compressed and then decompressed on game load, as well allow easier checksum verification to ensure the data hasn't been corrupted.

## Data Structure

| Bytes    |Purpose|Compressed|
|----------|---|---|
| 12       |Filename|N|
| 8        |Type|N|
| 12       |Size|N|
| Variable | Content|Y|

## Compilation notes

Run zlibinstall.bat to install zlib for windows.