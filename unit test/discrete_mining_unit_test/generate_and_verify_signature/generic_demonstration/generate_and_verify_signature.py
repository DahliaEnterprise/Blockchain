
from ecdsa import SigningKey
from ecdsa import VerifyingKey

from hashlib import sha256
from ecdsa.util import sigencode_der


from ecdsa import BadSignatureError
from ecdsa.util import sigdecode_der

#device a
##generate private key
device_a_private_key = SigningKey.generate()

##save public key to broadcast to the service(?)
public_key = device_a_private_key.verifying_key

with open("pub_key.pem", "wb") as f:
	f.write(public_key.to_pem())
	
##create a signature to broadcast(move two coins)
sig = device_a_private_key.sign_deterministic(
    b"move_two_coins",
    hashfunc=sha256,
    sigencode=sigencode_der)
		
with open("message.sig", "wb") as f:
	f.write(sig)

#device b
##read public key to verify
with open("pub_key.pem") as f:
	verifier_device_public_key = VerifyingKey.from_pem(f.read())
##read signature
with open("message.sig", "rb") as f:
    sig = f.read()

try:
    ret = verifier_device_public_key.verify(sig, b"move_two_coins", sha256, sigdecode=sigdecode_der)
    assert ret
    print("Valid signature")
except BadSignatureError:
	print("Incorrect signature")
