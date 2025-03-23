import requests

def check_saml_metadata(server_url):
    metadata_url = f"{server_url}/saml/metadata"
    try:
        response = requests.get(metadata_url)
        if response.status_code == 200:
            print("SAML metadata found!")
            print(response.text)
        else:
            print("No SAML metadata found.")
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")

# Example usage
check_saml_metadata("https://iajugs-test.fa.ocs.oraclecloud.com/fscmRestApi/resources/11.13.18.05/inventoryOnhandBalances?q=SummaryLevel%3DOrganization%3BItemNumber%3D001-001-005-00003&onlyData=true")
