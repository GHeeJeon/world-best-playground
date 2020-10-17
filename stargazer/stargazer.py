import random
import time

width = 0


def how_many_rows_do_you_want():
    rows = int(input("칸 수(너비)를 입력하세요. "))
    return rows


def random_number_zero_to_five():
    return random.randint(0, 5)


def width_fixer():
    global width
    width = how_many_rows_do_you_want()
    return width


def star_printer():
    for i in range(width):
        print("*" if random_number_zero_to_five() % 3 == 0 else " ", end='')
    print()


def star_gazer():
    while True:
        star_printer()
        time.sleep(0.3)


width_fixer()
star_gazer()
