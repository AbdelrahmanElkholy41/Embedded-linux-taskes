import requests


ip= requests.get("https://api.ipify.org/?format=json")
print(ip.content)

location=input("enter your ip: ")
re=requests.get("https://ipinfo.io/"+str(location)+"/geo")

print(re.content)