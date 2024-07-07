import webbrowser
import pyautogui
from time import sleep
import os

# URL to open
url = 'https://mail.google.com/mail/u/0/#inbox'

# Path to the image you want to locate and click
image_path = 'ph.png'

# Open the URL in Firefox
webbrowser.get('firefox').open(url)

# Give the browser some time to load the page
# Adjust the sleep time if your network or machine is slower or faster
sleep(10)

# Check if the image file exists
if not os.path.exists(image_path):
    print(f"Image file {image_path} not found.")
else:
    try:
        # Locate the image on the screen
        # Adjust confidence for fuzzy matching if needed (requires OpenCV)
        loc = pyautogui.locateCenterOnScreen(image_path, confidence=0.7)
        
        if loc:
            print(f"Image found at: {loc}, clicking on it.")
            pyautogui.click(loc)
        else:
            print("Image not found on the screen.")

    except pyautogui.ImageNotFoundException:
        print("Image not found exception raised.")
    except Exception as e:
        print(f"An error occurred: {e}")
