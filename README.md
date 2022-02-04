# Binary_Search_Trees_Special_Transformations

* In This Repository, We Implement The Binary Tree Data Structure.
* After That We Perform Some Very Special Transformations On The Tree Using Some Nice Algorithms

## Binary Search Tree Structure

* the structure of our tree is special
* because every node contains two values:
    1- the data value
    2- the color value (white or black)

* there is only two colors so the color value is a boolean
    1- true if the color is black
    2- false if it is white

* the root is a special node, because it have a value that is greater than all values in the tree and its color is black



## After the construction, The tree should look like this:

![tree](./out/tree.jpg)


# now coming to the transformations

>## The first transformation is an easy one
* it makes the right subtree an increasing list of nodes having only exactly one right child
* and it makes the left subtree a decreasing list of nodes having only exactly one left child
* this transoformation is obtained by:
>1- for the right subtree:
>> * starting from the right child of the root
>> * perform right rotations for each node until no left child remains
>> * after that go right and repeat the second step
    
>2- for the left subtree:
>> * starting from the left child of the root
>> * perform left rotations for each node until no right child remains
>> * after that go left and repeat the second step

    
* after performing this simple algorithm we should obtain the following result:
>![first](./out/first_transformation.jpg)

>## The second transformation is different
* first the tree must be transformed via the first transformation in order for this to work!
* it makes the every node in the right and left subtrees have a determined number of left/right children
* this determined number is generated using the formula:
> * Un = Un-1 + k
> * U0 = 0
> * where k is an integer number given in the input

* this transformation is obtained by:
> 1- starting from the left/right subtrees of the root
>>
> 2- set i = 1
>>
> 3- perform exacly (k * i) iterations:
>> * in each iteration perform left/right rotations on the every right/left node
>>
> 4- after that test if you came to a leaf
>>
> 5- if it is a leaf, don't do anything and continue for the other subtree
>>
> 6- if both are leaves then stop the algorithm!



* so we have the following tree and we want to make the second transformation on it
>![second_before](./out/second_transformation_before.jpg)

* after performing this algorithm (with k = 2) we should obtain the following result:
>![second_after](./out/second_transformation_after.jpg)