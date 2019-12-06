
from json import dumps

from flask import request

import server_data
from help_functions import is_real_channel_id, is_user_in_channel
from ld_data import dump_data, load_data
from myexcept import raise_err


def channel_addowner (token, channel_id, u_id, data):
	u_id = int(u_id)
	channel_id = int(channel_id)

	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')

	u_id_inviter = server_data.retrieveUid(token, data)


	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel')
	
	if not is_user_in_channel(u_id, channel_id, data):
		raise_err('ValueError', 'This user is not in this channel')
		
	if u_id in data.channels[channel_id].owner:
		raise_err('ValueError', 'This user is already an owner of this channel')	
		
	#channel does not exist 
	if (u_id_inviter not in data.channels[channel_id].owner) and (data.users[u_id_inviter].premission == 3):
		raise_err('AccessError', "You don't have permission to do this")
	data.channels[channel_id].owner.append(u_id)
	return {}
