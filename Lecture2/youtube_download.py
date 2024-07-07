from pytube import YouTube

# URL of the video you want to download
video_url = "https://youtu.be/jsTPAequUV0?si=02jw_mFQs9WUXFJa"

# Create a YouTube object
yt = YouTube(video_url)

#Choose the stream to download
stream = yt.streams.filter(res="720p").first()

# Download the video
stream.download(output_path='/home/abdelrahman-elkholy/moves', filename='YuoTube.mp4')
