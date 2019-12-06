class Data:
    def __init__(self):
        self.users = {}
        self.token_dict= {}
        self.channel = {}
        self.u_id_ct = 0
        self.message_id_ct = 0
        self.channel_id_ct = 0
        self.reset_code = {}

    def u_id_increment(self):
        self.u_id_ct = self.u_id_ct + 1

    def message_id_increment(self):
        self.message_id_ct = self.message_id_ct + 1

    def channel_id_increment(self):
        self.channel_id_ct = self.channel_id_ct + 1
    
 
