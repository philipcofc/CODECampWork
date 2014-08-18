# Assignment 1 - Building a star pyramid
 
pyramid_height = int(raw_input('Enter a number: '))

def build_pyramid(pyramid_height, level = 0):
	"""This function will output a single pyramid level based on the user defined
	height and the current level. It is inteded to be used recursively to build a complete pyramid."""
	if level < pyramid_height:
		print ((pyramid_height - level - 1) * " ") + ((2 * level + 1) * "*")
		level += 1

		build_pyramid(pyramid_height,level)
		
build_pyramid(pyramid_height)