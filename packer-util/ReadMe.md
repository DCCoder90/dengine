# Packer-util

The purpose of packer util is to pack all game assets into a singular .dat file.  This will allow for all assets to be compressed and then decompressed on game load, as well allow easier checksum verification to ensure the data hasn't been corrupted.

## Data Structure

| Bytes    |Purpose|
|----------|---|
| 8        |Filename|
| 8        |Type|
| 12       |Size|
| Variable | Content|