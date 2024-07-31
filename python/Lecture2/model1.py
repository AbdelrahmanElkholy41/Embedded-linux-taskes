import webbrowser
fav_bro= {
          1: "https://www.facebook.com/abdelrahman.elkholy.5473",
          2: "www.linkedin.com/in/abdelrahman-elkholy-19230724a",
          3: "https://x.com/Abdelra75109302",
          4: "https://instagram.com/abdelrahman_atef_elkholy/"



}
def open_url(url):
          webbrowser.get('firefox').open(url)
