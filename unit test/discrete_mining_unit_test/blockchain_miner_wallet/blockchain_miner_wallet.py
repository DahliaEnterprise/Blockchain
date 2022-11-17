import hashlib
from ecdsa import SigningKey
from ecdsa import VerifyingKey
import time
import random


#functions
def generate_keypair():
	keypair = []
	private_key = SigningKey.generate()
	public_key = private_key.verifying_key
	public_key_as_string = ""
	
	##convert to string; store then open as file to convert to string
	public_key_as_string = ""
	
	with open("temp_pub_key.pem", "wb") as f:
		f.write(public_key.to_pem())
	with open("temp_pub_key.pem") as f:
		public_key_as_string = f.read()
	
	keypair.append(private_key)
	keypair.append(public_key)
	keypair.append(public_key_as_string)
	return keypair



#generate device a key pair
device_a_keypair = generate_keypair()
device_a_private_key = device_a_keypair[0]
device_a_public_key = device_a_keypair[1]
device_a_public_key_as_string = device_a_keypair[2]

#generate a device keypair for transaction demonstration
device_b_keypair = generate_keypair()
device_b_private_key = device_b_keypair[0]
device_b_public_key = device_b_keypair[1]
device_b_public_key_as_string = device_b_keypair[2]

	
#initialize new blockchain(in network terms simulated here as a in-script only database)
blockchain_list_of_txhashes = []
blockchain_list_of_txinfo = []

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
		blockchain_list_of_txhashes.append(digest)
		blockchain_list_of_txinfo.append(block_message)
		
