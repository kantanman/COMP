from json import dumps
from flask import Flask, request
import server_data
import myexcept
from get_u_id import get_u_id
from ld_data import load_data, dump_data


def react_message(token, message_id, react_id):
    lsdata = load_data()
    if not (server_data.authToken(token)):
        err = AccessError('Invalid User')
        myexcept.defaultHandler(err)
        raise err
    u_id = server_data.retrieveUid(token, lsdata)
    message_id = int(message_id)
    react_id = int(react_id)
    #  check if valid react ID
    if react_id is not 1:
        err = myexcept.ValueError(description='react_id is not valid')
        myexcept.defaultHandler(err)
        raise err

    # var 1 checks if message_id belongs to a valid message
    var1 = False

    # var2 checks is message is already reacted to
    var2 = False

    # check if message id  
    for channel in lsdata.users[u_id].channels_in:
        for message in channel.messages:
            if message_id == message[message_id]:
                var1 = True
                if message[message_id].reaction[u_id] is None:
                    message[message_id].reaction[u_id] = react_id    
                    var2 = True 
                    break

    if var1 = False:
        err = myexcept.ValueError(description='message_id is not valid')
        myexcept.defaultHandler(err)
        raise err

    if var2 = False:
        err = myexcept.ValueError(description='message is already reacted to')
        myexcept.defaultHandler(err)
        raise err   

    dump_data(lsdata)
    return{} 
