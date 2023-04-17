echo "CPU processors:"
grep -c processor /proc/cpuinfo
grep 'cpu cores' /proc/cpuinfo | uniq
echo "Frequency of each processor: "
grep 'cpu MHz' /proc/cpuinfo
grep 'MemTotal' /proc/meminfo
grep 'MemFree' /proc/meminfo
echo "Number of forks since boot:"
vmstat -f
echo "Number of context swtiches since boot:"
grep 'ctxt' /proc/stat