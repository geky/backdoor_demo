#!/usr/bin/env python2

import re

data = open('dump.s').read()
datad = data.split('<door_enter>:')[1].split('<door_leave>:')[0]
datac = re.findall(r'\b([0-9a-f]{2})\b', datad)

out = open('door_store.c', 'w')
out.write('unsigned char door_store[] = {')
out.write(','.join('0x%s'%d for d in datac))
out.write('};')
