from flask import request
from ld_data import load_data, dump_data
from json import dumps
import server_data
from myexcept import raise_err
def channel_listall (token, data):
	if not (server_data.authToken(token, data)):
		raise_err ('AccessError', 'This is an invalid token')
	c_list = []
	for channel_id in data.channels.keys():
		tmp_dict = {
			'channel_id' : channel_id,
			'name' : data.channels[channel_id].name
		}
		c_list.append(tmp_dict)
	return {
		'channels' : c_list
		}
