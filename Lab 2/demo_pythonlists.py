"""
Demo for python lists
"""

print("fruits:")
fruits=['apple', 'banana', 'dragonfruit']
print(fruits)

print("append strawberry")
fruits.append('strawberry')
print(fruits)

print("copy fruits to fruits_copy: fruits_copy")
fruits_copy = fruits.copy()
print(fruits_copy)

print("clear fruits:")
fruits.clear()
print(fruits)

print("copy fruits_copy into fruits")
fruits = fruits_copy.copy()
print(fruits)

print("append banana x2")
fruits.append('banana')
fruits.append('banana')
print(fruits)

print("count banana")
print(fruits.count('banana'))

print("extend fruits with fruits_copy")
fruits.extend(fruits_copy)
print(fruits)

print("index of dragonfruit")
fruits.index('dragonfruit')
print(fruits)

print("insert watermelon at index 3")
fruits.insert(3, 'watermelon')
print(fruits)

print("pop index 4")
print(fruits.pop(4))

print("remove 'apple'")
fruits.remove('apple')
print(fruits)

print("reverse list")
fruits.reverse()
print(fruits)

print("sort list")
fruits.sort()
print(fruits)
