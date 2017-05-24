# Structural Patterns

In addition to inheritance and composition, which are compile-time static,
structural patterns describe the new ways to use objects together so that new
functionalities can be achieved in the runtime. User input cannot change the
inheritance chain or has-a relationship for the classes, but the carefully used
structural patterns allow for new behaviors determined by the runtime. This
provides great value for reusing pieces so that without code change new desired
functionalities can be realized.

## Pattern: Composite and Decorator (a.k.a wrappers)

In both patterns, the key idea is to use recursive inheritance.

1. Decorator classes inherits the base class, and also has a data member of the base class,
   which can be the actual object, or another decorator with different added methods and
   data. The key is they are share and override the method to be decorated, say `DoWork()`,
   which is present  in the object to be decorated.
2. Composite classes inherits the base class, and can have more than one data member of the
   base class, which can in turn be another composite class, or an object without further children.
   This is effectively a tree.

A good example of decorator pattern is to use recursive inheritance to add
layers of subclass, each with overriding the actual work `DoWork()`, and calls the data
member `DoWork()`.
![structure/decorator](https://i.imgur.com/8UmEYX4.png)

A good example of composite is to unify/create a view that captures the common dependencies
of the objects so that client code can easily operate on them. A binary tree seralizer can
have `Node` class with 2 subclasses `Leaf` and `Index` , where the first performs the operation
directly, and the second will iterate its child `Node` classes, gather the result, and return
them in a concat manner. Many other UI element data structure follows the similar tree structure
and are structured in a composite pattern for common processing.
![structure/composite](https://i.imgur.com/838xfvM.png)

## Pattern: Bridge (a.k.a impl pattern) and Adapters

(TBD)

## Pattern: Proxying

(TBD)
