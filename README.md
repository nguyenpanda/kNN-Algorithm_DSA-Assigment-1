# <span style="color:cyan">Color rules</span>
- <span style="color:GREEN">`GREEN:` program marker</span>
- <span style="color:CYAN">`CYAN:` testcase marker</span>
- <span style="color:MAGENTA">`MAGENTA:` when a specific/importance method is called</span>
- <span style="color:YELLOW">`YELLOW:` instance's property or `COUNT_DELETE`</span>
- <span style="color:RED">`RED:` R.I.P</span>

# <span style="color:RED">BUG</span>
- When using `Operator=` for `Image class`, `data` (has same location) has been deleted one, causing `destructor` fail.

# <span style="color:cyan">Checklist</span>
## Arraylist
### <span style="color:skyblue">Constructors</span> 
`ArrayList()`, `ArrayList(int capacity)`
### <span style="color:skyblue">Delete - test_0( )</span> 
`remove()`, `pop()`
### <span style="color:skyblue">Add - test_1( )</span> 
`push_back()`, `push_back()`, `insert()`
### <span style="color:skyblue">Access - test_0( ) - test_2( ):</span>
`operator[]`, `get()`
### <span style="color:skyblue">Clear/Reverse - test_3( ):</span>
`Clear()`, `Reverse()`

## Image
### <span style="color:skyblue">Constructors</span>



# <span style="color:cyan">Note</span>
### <span style="color:skyblue">Remove print color statement:</span>
- `Resizing` from `ArrayList->resize()`
- `Copy constructor` from `ArrayList(ArrayList& other)`
- `= operator` from `ArrayList->operator=()`
- `Destructor` from `ArrayList->~ArrayList()`
- `Empty` from `ArrayList->print()`
-
### <span style="color:skyblue">Other note:</span>
- Remember to remove `COUNT_DELETE` from `LinkedList->print()`
- Remember to set `ArrayList->resize` into `private`
- Remember to set `Image->setLabel` into `private`