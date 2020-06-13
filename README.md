# Log-seeker
Log Seeker, an easy way to search your logs

## Install:

$ `cd logseeker`

$ `make`

$ `sudo make install`



## To Run, Example:

[serach vis regex] $ `logseeker -f /var/log/error.log -r "(.*)secret(.*)"`

[serach vis word] $ `logseeker -f /var/log/error.log -s "secret"`

## Dump results to a file

$ `logseeker -f /var/log/error.log -s "core:notice"`> core-notices.txt

## Flags:

`-f` = Log file to scan

`-s` = Search word OR `-r` = Regex expression

`-h` = Help menu

`-v` = Version
