
**Dump a specific sector of a disk, super simple C++ example code.**

### Compile

```
g++ -O -Wall -std=c++11 sector.cpp -o sector
```

or statically

```
g++ -static -O -Wall -std=c++11 sector.cpp -o sector
```

A huge binary, but you can use it in almost every Linux system.

### Usage

```
sudo ./sector <disk> [sector] (default is 0)
```

### Examples

```
sudo ./sector /dev/nvme0n1 1 | strings
```

which does the exact same as

```
sudo dd if=/dev/nvme0n1 skip=1 bs=512 count=1 2>/dev/null | strings
```

Find a sector, holding the string "model", within a range of sectors:

```
for s in `seq 2048 100000`
do
  echo -ne "------${s}------\r"
  sector /dev/sda $s | strings | grep -q 'model' && echo && break
done
```
