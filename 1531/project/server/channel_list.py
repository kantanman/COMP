from flask import request

import server_data
from ld_data import dump_data, load_data
from myexcept import raise_err


def channel_list (token, data):
	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')
	u_id = server_data.retrieveUid(token, data)
	c_list = []
	for channel_id in data.users[u_id].channel_in:
		tmp_dict = {
			'channel_id' : channel_id,
			'name' : data.channels[channel_id].name
		} 
		c_list.append(tmp_dict)
	return {'channels' : c_list}
