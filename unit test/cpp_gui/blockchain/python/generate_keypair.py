import sys
from ecdsa import SigningKey
sys.stdout.write("TST\n")
private_key_string = ""
device_private_key = SigningKey.generate();
with open("priv_key.pem", "wb") as f:
    f.write(device_private_key.to_pem())

with open("priv_key.pem", "rb") as f:
    private_key_string = f.read()

print(private_key_string)
print("test")
