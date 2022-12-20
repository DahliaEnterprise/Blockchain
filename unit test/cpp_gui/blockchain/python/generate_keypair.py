import sys
from ecdsa import SigningKey

private_key_string = ""
device_private_key = SigningKey.generate()

with open("priv_key.pem", "wb") as f:
    f.write(device_private_key.to_pem())

with open("priv_key.pem", "rb") as f:
    private_key_string = f.read()

print(private_key_string)

#verifying key
public_key_string = ""
device_verifying_key = device_private_key.verifying_key
with open("pub_key.pem", "wb") as f:
    f.write(device_verifying_key.to_pem())

with open("pub_key.pem", "rb") as f:
    public_key_string = f.read()

print(public_key_string)
