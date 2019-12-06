from json import dumps
import time

from flask import request

import server_data
from ld_data import dump_data, load_data
from myexcept import raise_err
from help_functions import is_real_channel_id

def get_info(u_id, channel_id, start, end, data):
	messages_list = []
	for ct in range(start, end):
		if data.channels[channel_id].messages[ct].time > time.time():
			continue
		reaction_lst = []
		for rct in data.channels[channel_id].messages[ct].reaction.keys():
			data.channels[channel_id].messages[ct].reaction[rct]['is_this_user_reacted'] = False
			if u_id in data.channels[channel_id].messages[ct].reaction[rct]['u_ids']:
				data.channels[channel_id].messages[ct].reaction[rct]['is_this_user_reacted'] = True
			rct_dict = {
				'react_id' : rct,
				'u_ids' : data.channels[channel_id].messages[ct].reaction[rct]['u_ids'],
				'is_this_user_reacted' : data.channels[channel_id].messages[ct].reaction[rct]['is_this_user_reacted']
			}
			reaction_lst.append(rct_dict)
		msg_dict = {
			'message_id' : data.channels[channel_id].messages[ct].message_id, 
			'u_id' : data.channels[channel_id].messages[ct].sender, 
			'message' : data.channels[channel_id].messages[ct].content, 
			'time_created' : data.channels[channel_id].messages[ct].time, 
			'reacts' : reaction_lst,
			'is_pinned' :data.channels[channel_id].messages[ct].status
		}
		messages_list.append(msg_dict)
	print (messages_list)
	return messages_list


def channel_messages(token, channel_id, start, data):
	start = int(start)
	channel_id = int(channel_id)

	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')

	u_id = server_data.retrieveUid(token, data)
	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel_id')

	len_messages = len(data.channels[channel_id].messages)
	
	if start > len_messages:
		raise_err('ValueError', 'Start is wrong!')
	
	if channel_id not in data.users[u_id].channel_in:
		return {
		'messages' : [],
		'start' : start,
		'end' : -1
		}
	
	end = start + 50

	if (start + 50) >= len_messages:
		end = -1

	if end == -1:
		messages_list = get_info(u_id, channel_id, start, len_messages, data)
	elif len_messages == 0:
		pass
	else:
		messages_list = get_info(u_id, channel_id, start, end, data)
	
	return {
		'messages' : messages_list,
		'start' : start,
		'end' : end
		}
