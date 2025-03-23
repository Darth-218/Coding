import requests
from requests.auth import HTTPBasicAuth
import jwt
import sys

creds = sys.argv[1]
url = sys.argv[2]

with open(creds, "r") as file:
    global user, passw
    lines = file.readlines()
    user, passw = lines[0].strip(), lines[1].strip()


def basicSSL() -> int:
    response = requests.get(url, auth=HTTPBasicAuth(user, passw))
    # print(response.text)
    return response.status_code


def SAMLBearer() -> int:
    token = "" # No token yet
    header = {"Authorization": f"Bearer {token}", "Content-Type": "application/json"}
    response = requests.get(url, headers=header)
    # print(response.text)
    return response.status_code


def JWTAuth() -> int:
    payload = {"sub":"amg.interface","iss":"www.oracle.com","exp":1738781433,"prn":"amg.interface","iat":1738779633}
    header = {"x5t":"rxGEBjuySs-_Bp0pDsgUgBsJbgU","kid":"trustservice","typ":"JWT","alg":"RS256"}
    key = "" # No key yet.
    print("Encoding...")
    token = jwt.encode(payload, key, headers=header, algorithm="RS256")
    header = {"Authorization": f"Bearer {token}", "Content-Type": "application/json"}
    response = requests.get(url, headers=header)
    print("Found Response...")
    print(response.text)
    return response.status_code


def main():
    print("Basic SSL:", basicSSL(), end="\n\n")
    print("SAML:", SAMLBearer(), end="\n\n")
    print("JWT:", JWTAuth(), end="\n\n")


if __name__ == "__main__":
    main()
