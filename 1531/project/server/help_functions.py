

def is_real_channel_id(channel_id, data):
    if channel_id in data.channels.keys():
        return True
    return False

def is_user_in_channel(u_id, channel_id, data):
    
    if channel_id in data.users[u_id].channel_in:
        return True
    return False

def is_real_u_id(u_id, data):
    
    if u_id in data.users.keys():
        return True
    return False

def is_channel_public(channel_id, data):
    if data.channels[channel_id].is_public == False:
        return False 
    else: 
        return True

def is_user_owner(u_id, channel_id, data):
    
    if u_id in data.channels[channel_id].owner:
        return True
    return False

def is_permitted(u_id, data):
    
    if data.users[u_id].permission_id != 3:
        return True
    return False

def is_legal_length(length, string):
    return len(string) <= length

def is_email_used(email, data):
    
    for u_id in data.users.keys():
        if email == data.users[u_id].email:
            return True # not avaliable email
    return False # available email

def is_real_message(message_id, data):
    
    if message_id in data.msg_id_dict.keys():
        return True
    return False

