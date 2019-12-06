from ld_data import load_data, dump_data
from server_data import authToken, retrieveUid
from myexcept import raise_err

def search_mes(token, query_str, data):
    if not authToken(token, data):
        raise_err('AccessError', 'This is an invalid token from seach')

    u_id = retrieveUid(token, data)

    msg_list = []
    for channel_id in data.channels.keys():
        for message in data.channels[channel_id].messages:
            if message.content.find(query_str) != -1:
                react_lst = []
                for rct in message.reaction.keys():
                    message.reaction[rct]['is_this_user_reacted'] = False
                    if u_id in message.reaction[rct]['u_ids']:
                        message.reaction[rct]['is_this_user_reacted'] = True
                    rct_dict = {
                        'react_id' : rct,
                        'u_ids' : message.reaction[rct]['u_ids'],
                        'is_this_user_reacted' : message.reaction[rct]['is_this_user_reacted']
                    }
                    react_lst.append(rct_dict)
                msg_dict = {
                    'message_id' : message.message_id,
                    'u_id' : message.sender,
                    'message' : message.content,
                    'time_created' : message.time,
                    'is_pinned' : message.status,
                    'reacts' : react_lst
                }
                msg_list.append(msg_dict)
    return {'messages' : msg_list}