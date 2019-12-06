from json import dumps
from flask import Flask, request
import server_data
import myexcept
from ld_data import load_data, dump_data



@APP.route('/message/remove', methods=['DELETE'])
def remove_message():
    lsdata = load_data()

    #request data from user
    #get u_id from the token
    u_id = server_data.retrieveUid(token, lsdata) 
    

    #message_id var
    var1 = False
    #sender same as u_id var
    var2 = False
    #not owner or admin var
    var3 = False

    for channel in lsdata.users[u_id].channels_in:
        for message in channel.messages:
            if message_id == message['message_id']:
                var1 = True
                if message[message_id].sender == u_id:
                    var2 = True
                if lsdata.users[u_id].permission_id is not 3 and lsdata.users[u_id].permission_id is not 2:
                    var3 = True    
                break
    #if message_id does not exist, throw exception
 
    if var3 == False:
        err = myexcept.ValueError(description='User is not an owner or admin')
        myexcept.defaultHandler(err)
        raise err 


    if var2 == False:
        err = myexcept.ValueError(description='Sender is not the same as the user')
        myexcept.defaultHandler(ValueError)
        raise err

    if var1 = True:
        channel.messages.remove(message[message_id])

    dump_data(lsdata)
    return{}

