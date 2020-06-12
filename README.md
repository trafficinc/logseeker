# Log-seeker
Log Seeker, an easy way to search your logs

## Install:

$ `cd logseeker`

$ `make`

$ `sudo make install`



## To Run:

[serach vis regex] $ `logseeker -f ./bin/errorLog -r "(.*)secret(.*)"`

[serach vis word] $ `logseeker -f ./bin/errorLog -s "secret"`

## Dump results to a file

$ `logseeker -f ./bin/errorLog -s "core:notice"`> core-notices.txt

## Flags:

`-f` = path/log file, `-s` = search word OR `-r` = regex expression
