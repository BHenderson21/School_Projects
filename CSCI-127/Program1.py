# ---------------------------------------
# CSCI 127, Joy and Beauty of Data
# Program 1: Flag Designer
# Author: Daniel DeFrance
# (c) Copyright Daniel DeFrance and Montana State University
# You may modify this code and use it for class
# You may NOT publish this code to any website
# ---------------------------------------
# Assignment: Modify this program as described in D2L
# ---------------------------------------
#
# Modified by: Brandon Henderson, 9/15/2021
#
# ---------------------------------------

import turtle


# Setting up the window
width = 800
height = 500
turtle.setup(width, height)
wn = turtle.Screen()
wn.bgcolor("lightgray")


# Settuing up the turtle that will draw the empty sections
draw_color = "gray"
color_1, color_2, color_3 = draw_color, draw_color, draw_color
section = turtle.Turtle()
section.color(draw_color, "lightgray")
section.shapesize(2)
section.speed(0)
section.penup()


# Setting up the turtle that will write tge messages, and writting the initial instructions.
message = turtle.Turtle()
message.hideturtle()
message.penup()
message.goto(-100, -150)
message.color("gray")
message.speed(0)
message.write("Click anywhere to begin designing a flag.", font = ("Arial", 12))


# Defining the function that will draw each empty section.
def draw_section():
    section.begin_fill()
    section.pendown()
    for i in range(2):
        section.forward(100)
        section.right(90)
        section.forward(200)
        section.right(90)
    section.end_fill()
    section.penup()
    section.goto(-250, 0)


# Calling the function to draw the empty sections for each of the 3 sections
def draw_first():
    section.goto(-150,100)
    draw_section()

def draw_second():
    section.goto(-50,100)
    draw_section()

def draw_third():
    section.goto(50,100)
    draw_section()


# Setting up the definition to cycle the colors, and returns the color
def cycle_color(current_color):
    if current_color == "yellow" or current_color == "gray" :
        new_color = "white"
    elif current_color == "white":
        new_color = "blue"
    elif current_color == "blue":
        new_color = "red"
    elif current_color == "red":
        new_color = "green"
    elif current_color == "green":
        new_color = "yellow"
    else:
        print("There seems to be a mistake with the color cycling.")
        new_color = "gray"
        
    return new_color


# Defines the function to color the sections of the flag to the current color, if the user clicks in the section
def color_flag(x, y):
    global draw_color, color_1, color_2, color_3

    print("x: ", x, "y: ", y)

    if (-150 < x < -50) and (100 > y > -100):
        draw_first()
        color_1 = draw_color
    elif (-50 < x < 50) and (100 > y > -100):
        draw_second()
        color_2 = draw_color
    elif (50 < x < 150) and (100 > y > -100):
        draw_third()
        color_3 = draw_color
    else:
        draw_color = cycle_color(draw_color) 
        section.color(draw_color)
        
    erase_message()
    check_flag(color_1, color_2, color_3)


# Defines function to clear the current message so a new one can be written without overlap.
def erase_message():
    message.fillcolor("lightgray")
    message.begin_fill()
    message.goto(-300, -120)
    for i in range(2):
        message.forward(600)
        message.right(90)
        message.forward(40)
        message.right(90)
    message.end_fill()
    message.goto(-100, -150)


# Defines definition to check the flag against the recognized flags to see if its already in use, and if not says that its available.
def check_flag(one, two, three):

    print("left: " + one + ", center: " + two + ", right: " + three)
    erase_message()
    
    if (one == "gray" or two == "gray" or three == "gray"):
        erase_message()
        message.write("Color all three sections.", font = ("Arial", 20))
    elif (one == "blue" and two == "white" and three == "red"):
        erase_message()
        message.write("National Flag of France.", font = ("Arial", 20))
    elif (one == "green" and two == "white" and three == "red"):
        erase_message()
        message.write("National Flag of Italy.", font = ("Arial", 20))
    elif (one == "red" and two == "white" and three == "red"):
        erase_message()
        message.write("National Flag of Peru.", font = ("Arial", 20))
    elif (one == "green" and two == "white" and three == "green"):
        erase_message()
        message.write("National Flag of Nigeria.", font = ("Arial", 20))
    elif (one == "blue" and two == "yellow" and three == "red"):
        erase_message()
        message.write("National Flag of Romania.", font = ("Arial", 20))
    elif (one == "green" and two == "yellow" and three == "red"):
        erase_message()
        message.write("National Flag of Mali.", font = ("Arial", 20))
    else:
        erase_message()
        message.write("This flag is available.", font = ("Arial", 20))

# Draws the initial, empty sections
draw_first()
draw_second()
draw_third()

# Detects when the user clicks to call the function to either cycle the color or color the section based on where they click.
wn.onclick(color_flag)
# mainloop so that the program does not exit when waiting for user input
wn.mainloop()
      

    
    
