#LogSeeker, easy way to search your logs

##Install:

$ `cd logseeker`

$ `make`

$ `sudo make install`



##To Run:

[serach vis regex] $ `logseeker -f ./bin/errorLog -r "(.*)secret(.*)"`

[serach vis word] $ `logseeker -f ./bin/errorLog -s "secret"`


##Flags:

`-f` = path to; log file, `-s` = search word, `-r` = regex expression
