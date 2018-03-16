### Compile

```
g++ -O -Wall -std=c++11 sector.cpp -o sector
```

### Examples

```
sudo ./sector /dev/nvme0n1 1 | strings
```

which does the exact same as

```
sudo dd if=/dev/nvme0n1 skip=1 bs=512 count=1 2>/dev/null | strings
```

Another example:

```
sudo ./sector /dev/sda 32347 | hexdump -C
```
