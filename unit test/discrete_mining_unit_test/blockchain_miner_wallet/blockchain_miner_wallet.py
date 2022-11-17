import hashlib
from ecdsa import SigningKey
from ecdsa import VerifyingKey
import time
import random


#generate device a key pair
device_a_private_key = SigningKey.generate()
device_a_public_key = device_a_private_key.verifying_key
device_a_public_key_as_string = ""
print(device_a_public_key.to_pem())

##convert to string; store then open as file to convert to string
device_a_public_key_as_string = ""

with open("device_a_pub_key.pem", "wb") as f:
	f.write(device_a_public_key.to_pem())
with open("device_a_pub_key.pem") as f:
	device_a_public_key_as_string = f.read()

	
#initialize new blockchain(in network terms simulated here as a in-script only database)
blockchain_list_of_txhashes = []
blockchain_list_of_txinfo = []
blockchain_list_of_index = 0;

#mine first block
difficulty = 3;
character = "0"
keep_finding_genesisblock = 1
while keep_finding_genesisblock == 1:
	genesis_message = "genesisblock_"+str(difficulty)+"_"+str(time.time())+"_"+device_a_public_key_as_string
	nonce=random.SystemRandom().randint(1, 9223372036854775807)
	block_message = genesis_message+"_"+str(nonce)
	#print(block_message)
	m = hashlib.sha256()
	m.update(bytes(block_message, 'utf-8'))
	digest = m.hexdigest()
	atleast_difficulty_found = 1;
	difficulty_check_index = 0
	#print(digest)
	while difficulty_check_index < difficulty:
		if digest[difficulty_check_index] != character[0]:
			#stop while loop(no need to keep searching)
			difficulty_check_index = difficulty
			atleast_difficulty_found = 0
		else:
			difficulty_check_index += 1
	
	#difficulty is atleast satasfactory
	if atleast_difficulty_found == 1:
		keep_finding_genesisblock = 0;
		blockchain_list_of_txhashes[blockchain_list_of_index] = digest
		blockchain_list_of_txinfo[blockchain_list_of_index] = blockmessage
		blockchain_list_of_index += 1
		
