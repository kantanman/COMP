from json import dumps

from flask import Flask, request

import server_data
from help_functions import is_legal_length
from ld_data import dump_data, load_data
from myexcept import raise_err


def channels_create(token, name, is_public, data):

	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')

	if not is_legal_length(20, name):
		raise_err('ValueError', 'Channel name is too long')

	u_id = server_data.retrieveUid(token, data)
	if is_public == 'false':
		is_public = False
	is_pblic = True
	data.channel_id_increment()
	channel_id = data.channel_id_ct
	new_channel = server_data.Channels(u_id, is_public, name, channel_id)
	
	data.channels[channel_id] = new_channel
	data.users[u_id].channel_in.append(channel_id)
	return {
		'channel_id' : channel_id
		}
