import os
from gtts import gTTS
import pygame
from time import ctime
import speech_recognition as sr
import webbrowser

# Initialize the pygame mixer
pygame.mixer.init()

r = sr.Recognizer()

def speak(voice_data):
    t = gTTS(text=voice_data, lang='en')
    audio = 'voice.mp3'
    t.save(audio)
    pygame.mixer.music.load(audio)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        pass
    print(voice_data)
    os.remove(audio)

def record(ask=False):
    with sr.Microphone(device_index=None) as source:
        r.adjust_for_ambient_noise(source)
        if ask:
            speak(ask)
        audio = r.listen(source)
        voice_data = ''
        try:
            voice_data = r.recognize_google(audio, language="en")
        except sr.UnknownValueError:
            speak("sorry")
        return voice_data.lower()

def response(voice_data):
    if 'name' in voice_data:
        speak('Elkholy')
    if 'time' in voice_data or 'hour' in voice_data:
        speak(ctime())
    if 'bye' in voice_data:
        speak('bye bye')
    if 'open facebook' in voice_data:
        webbrowser.open("https://www.facebook.com/abdelrahman.elkholy.5473")
        speak('okay')
    if 'what is your name' in voice_data:
        speak('my name is smart chat')
    if  'date' in voice_data:
         current_date = ctime().split(" ")[0]
         speak(current_date)
while True:
    voice_data = record()
    response(voice_data)
