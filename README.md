# LinkedListCpp
A custom implemention of a linked list class in C++.

## Usage
Because the linked list class is a template you can specify any data type to be used with it.
```cpp
LinkedList<int> list;
list.insert(5);
list.insert(3); // will insert at end
list.insertAt(0) // will insert at specified index, in this case at the front

list.get(0);

list.remove(); // will remove last element
list.clear();
```
Iterators have also been implemented so you can use range based for loops to iterate over the linked lists.
```cpp
for (auto it : list)
{
  std::cout << it << std::endl;
}
```

## Lessons learned
In making this class I listened a few interesting things.

### Template classes
If you want to have the class definitions and implementations in separate files (as you usually do) it is a little different for template classes because of how the linker works with templates. It is best to name the implementations file with a `.tpp` and then you need to `#include` the `.tpp` file in the header file (at the bottom). This is because the linker will throw an error without access to the implementations. There are other methods that work but this is the preferred method.

### Dependant Variables
When using templates and having variables that depend on that template type, if you use that type as a return type you'll have to declare to the compiler that it's a typename or it will be unable to infer the type. I had this issue with my Node struct.

### Pointers
Even when you're being careful, they are very easy to get wrong and end up with memory leaks/segmentation faults. Best to have a good debugger that can show memory is being released and that you aren't trying to access a nullptr!
