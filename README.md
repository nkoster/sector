### Compile

```
g++ -O -Wall -std=c++11 sector.cpp -o sector
```

### Examples

```
sudo ./sector /dev/nvme0n1 1 | strings
sudo ./sector /dev/sda 0 | hexdump -C
```
