# steps:
#    1. install instaloader package: pip3 install instaloader, pip install pyserial, pip install pygame
#    2. in cmd, cd to file location and >>> python flowglobe.py

import instaloader
import serial
import time
import pygame

prevFollowerCount = 0
# arduino serial port is COM3 on my device
ser=serial.Serial('COM3', 9600, timeout=1)

def play_sound(file_path):
    pygame.init()
    pygame.mixer.init()

    try:
        pygame.mixer.music.load(file_path)
        pygame.mixer.music.play()
        time.sleep(1)

    except pygame.error as e:
        print(f"Error playing sound: {str(e)}")

    pygame.mixer.quit()
    pygame.quit()


def get_followers_count(username):
        # Get profile from username
        profile = instaloader.Profile.from_username(loader.context, username)

        # Retrieve the follower count
        followers_count = profile.followers
        return followers_count


if __name__ == "__main__":
        # the target account
        target_username = 'kimkardashian'
        # Create an Instaloader instance
        loader = instaloader.Instaloader()
        loader.interactive_login('justin.yooo') # required to login to any instagram account first.

        while True:

                # Get followers count
                followerCount = get_followers_count(target_username)
                print(f"The number of followers for {target_username} is: {followerCount}")

                # send to serial
                ser.write(str(followerCount).encode())
                print(f"sent")

                if followerCount > prevFollowerCount:
                        play_sound('gain.wav')
                if followerCount < prevFollowerCount:
                        play_sound('lose.wav')

                prevFollowerCount=followerCount
                                
                time.sleep(2) # adjust the refresh rate here in seconds
    

