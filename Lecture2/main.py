from model import fav_bro, open_url
def dashbord(url):
          print(" All  websits----------------------")
          for key,value in fav_bro.items():
                  print(f"{key}:{value}")
          print('-----------------------------------')
def main():
        while True:
                dashbord(fav_bro)
                num_web=input("Please Enter Number Your Web")
                if int(num_web)>4:
                        print("Please Enter Valid Number.......")
                        print()
                print("if you need exit enter E")
                if(num_web=='E'):
                        break        
                else:
                       open_url(fav_bro[int(num_web)]) 
                     

        
main()