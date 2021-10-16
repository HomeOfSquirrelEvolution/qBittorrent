#!/bin/env python3

import bencodepy as bc
from collections import OrderedDict
from pprint import pprint

with open("1.torrent", "rb") as source_file:
    data = source_file.read()
    ret = bc.decode(data)

def nest_decode(data):
    if type(data) is bytes:
        try:
            data = data.decode('utf-8')
        except:
            data = data.hex()
        return data
    elif type(data) is dict or type(data) is OrderedDict:
        for key,val in data.items():
            data[key] = nest_decode(val)
        return data
    elif type(data) is list:
        return [nest_decode(item) for item in data]
    elif type(data) is int:
        return data
    else:
        print(type(data))
        assert False

ret = nest_decode(ret)
pprint(ret[b'info'][b'files'])
