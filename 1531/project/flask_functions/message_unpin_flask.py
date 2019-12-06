from json import dumps
from flask import Flask, request
import server_data
import myexcept
from get_u_id import get_u_id
from ld_data import load_data, dump_data
from error import AccessError

def unpin_message(token, message_id):
    lsdata = load_data()
    if not (server_data.authToken(token)):
        err = AccessError('Invalid User')
        myexcept.defaultHandler(err)
        raise err

    u_id = server_data.retrieveUid(token, lsdata)

    #var1 shows if the message_id belongs to a valid message
    var1 = False

    #var2 shows if the message is unpinned
    var2 = False

    if lsdata.users[u_id].permission_id != 2:
        err = myexcept.ValueError(description='user is not an admin')
        myexcept.defaultHandler(err)
        raise err

    # looping through all the messages in all the channels that the user is apart of. By default, if the user is not a member of the channel, var1 and var2 will remain false
    for channel in lsdata.users[u_id].channels_in:
        for message in channel.messages:
            if message_id == message['message_id']:
                var1 = True
                if message[message_id].status == True:
                    var2 = True
                    message[message_id].status == False
                    break

    if var1 == False:
        err = myexcept.ValueError(description='message_id does not belong to a valid message')
        myexcept.defaultHandler(err)
        raise err

    if var2 == False:
        err = myexcept.ValueError(description='message is already unpinned')
        myexcept.defaultHandler(err)
        raise err

    dump_data(lsdata)
    return {}
