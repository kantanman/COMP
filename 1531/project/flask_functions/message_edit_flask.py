from json import dumps
from flask import Flask, request
import server_data
import myexcept
from get_u_id import get_u_id
from ld_data import load_data, dump_data

@APP.route('/message/edit', methods=['PUT'])
def edit_message():


    token = request.form.get('token')
    message_id = request.form.get('message_id')
    message = request.form.get('message')

    u_id = server_data.retrieveUid(token, lsdata)

    #sender same as u_id var
    var2 = False
    #not owner or admin var
    var3 = False

    for channel in lsdata.users[u_id].channels_in:
        for message in channel.messages:
            if message[message_id].sender == u_id:
                var2 = True
                if lsdata.users[u_id].permission_id is not 3 and lsdata.users[u_id].permission_id is not 2:
                    var3 = True
                    channel_id = channel
                    break

    if var2 and var3 == True:
        lsdata.users[u_id].channel_in[channel_id].messages[message_id] = message
    elif var2 == False:
        err = myexcept.AccessError(description='sender is not the same as user')
        myexcept.defaultHandler(err)
        raise err
    elif var3 == False;
        err = myexcept.AccessError(description='user is not an admin or owner')
        myexcept.defaultHandler(err)
        raise err   

    dump_data(lsdata)
    return {}
