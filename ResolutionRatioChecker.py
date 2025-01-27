# ResolutionRatioChecker
# Author: St7530
# Date: 2025/1/27

# 1. Set a length-to-width ratio.
ratio_length=16
ratio_width=9

# 2. Input the length and width of a video.
length=int(input("Input length: "))
width=int(input("Input width: "))

# 3. Then we'll check if the given length and width match the ratio.
if length/width==ratio_length/ratio_width:
    print("\nIt's ",ratio_length,":",ratio_width,"!")
else:
    print("\nIt's NOT",ratio_length,":",ratio_width,"!")
    # 4. If not, we'll recommend a new resolution that matches the ratio.
    if length/width>ratio_length/ratio_width:
        length=width//ratio_width*ratio_length
        width=width//ratio_width*ratio_width
    if length/width<ratio_length/ratio_width:
        width=length//ratio_length*ratio_width
        length=length//ratio_length*ratio_length
    print("Recommended ",ratio_length,":",ratio_width," resolution: ",length,"*",width)