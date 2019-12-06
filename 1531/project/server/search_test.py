from search import search_mes
from myexcept import ValueError, AccessError
import pytest
from auth_register import auth_register
from channel_messages import channel_messages
from channel_list import channel_list
from datetime import datetime

'''
def search_test():

    authDict = auth_register(hello@unsw.com, blue123, john, smith)
    token = authDict['token']
    channelDict = channels_create(token, "Channel 1", TRUE)
    channelId = channelDict['Channel_id']

    message_send(token, channelId, "g'day")
    message_send(token, channelId, "good morning")
    message_send(token, channelId, "Bye Bye")
    message_send(token, channelId, "test")
    #list of all the channels John is apart of

    m_list = search (token, 'g')

    assert m_list = ["g'day", "good morning"]
    
def No_match_test ():


    authDict = auth_register(hello@unsw.com, blue123, john, smith)
    token = authDict['token']
    channelDict = channels_create(token, "Channel 1", TRUE)
    channelId = channelDict['Channel_id']

    message_send(token, channelId, "g'day")
    message_send(token, channelId, "good morning")
    message_send(token, channelId, "Bye Bye")
    message_send(token, channelId, "test")

    assert search (token, 'a') = []
'''