class Messages:
	def __init__(self, content, u_id, channel_id, message_id):
		self.message_id = message_id
		self.content = content
		self.sender = u_id
		self.status = False
		self.reaction = {}