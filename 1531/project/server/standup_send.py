from ld_data import load_data, dump_data
import server_data
from myexcept import raise_err
import time
from help_functions import is_real_channel_id, is_user_in_channel

def standup_send (token, channel_id, message, data):
	channel_id = int(channel_id)

	u_id = server_data.retrieveUid(token, data)

	if not server_data.authToken(token, data):
		raise_err('AccessError', 'This is an invalid token')
   
	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is an invalid channel_id')

	if len(message) > 9999:
		raise_err('ValueError', 'This message is too long')

	if data.channels[channel_id].status != True:
		raise_err('AccessError', 'Standup is not active')

	if not is_user_in_channel(u_id, channel_id, data):
		raise_err('AccessError', 'user is not in this channel')

	msg_id = data.message_id_ct
	data.message_id_increment()
	data.msg_id_dict[msg_id] = channel_id
	msg = server_data.Messages(message, u_id, msg_id, time.time())
	data.channels[channel_id].messages.insert(0,msg)
	
	u_handle = data.users[u_id].handle
	string = str(u_handle) + ' : ' + message
	data.channels[channel_id].standups.append(string)
	
	return {}