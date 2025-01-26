from tkinter import *
from gpiozero import AngularServo
from time import sleep
from threading import Thread

# Initialize the main window
root = Tk()
root.geometry('600x200')

# Function to control servo rotation
def rotate():
    servo = AngularServo(17, min_angle=-90, max_angle=90)
    angle = V1.get()  # Get the angle from the slider
    servo.angle = angle
    sleep(2)  # Give the servo some time to rotate

# Threaded function to handle servo without freezing GUI
def threaded_rotate():
    Thread(target=rotate).start()

# GUI Elements
V1 = DoubleVar()
TitleLabel = Label(root, text="Select the angle of rotation using slider")
TitleLabel.config(font=('Helvetica', 15))
TitleLabel.config(fg="#DE3163")

Slider = Scale(root, variable=V1, from_=-90, to=90, length=720, tickinterval=15, orient=HORIZONTAL)
SubmitBtn = Button(root, text="Click here to rotate", command=threaded_rotate, bg='Yellow')

# Place widgets
TitleLabel.pack(anchor=CENTER, pady=10)
Slider.pack(anchor=CENTER, pady=10)
SubmitBtn.pack(anchor=CENTER, pady=10)

# Start the GUI loop
root.mainloop()
