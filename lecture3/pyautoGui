import pyautogui
import time 
def open_vscode_and_install_extensions():
    pyautogui.press('win')
    time.sleep(1)
    pyautogui.write('Visual Studio Code')
    time.sleep(1)
    pyautogui.press('enter')
    time.sleep(5) 

    
    extensions = [
        'clangd', 
        'c++ testmate', 
        'c++ helper', 
        'cmake', 
        'cmake tools'

    ]
    for extension in extensions:
       
        pyautogui.hotkey('ctrl', 'shift', 'x') 
        time.sleep(1)
        
        pyautogui.write(extension)
        time.sleep(1)
        pyautogui.press('enter')

        time.sleep(1)  
        install_button = pyautogui.locateCenterOnScreen('/home/abdelrahman-elkholy/button.png')
        if install_button is not None:
            pyautogui.click(install_button)
            time.sleep(2)
            # Clear the search input field
            pyautogui.hotkey('ctrl', 'a')  
            pyautogui.press('delete')  
        else:
            print(f"Could not find install button for {extension} extension.")

        pyautogui.press('esc')


open_vscode_and_install_extensions()
   
