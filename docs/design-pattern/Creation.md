# Creation Patterns

- [Creation Patterns](#creation-patterns)
  - [Example and Naive Approaches](#example-and-naive-approaches)
  - [Pattern: Factory Method and Abstract Factory Method](#pattern-factory-method-and-abstract-factory-method)
  - [Pattern: Builder](#pattern-builder)

Instantiation and initialization is the first and most important construct
in large-scale software systems. This is because complexity is more often
managed using composition (dividing into smaller domains) than other abstraction
mechanisms like inheritances.

We call the larger, final desired overall state the "system", and its composing
classes "products". Systems are structured so that composing classes can have different
subclasses of products to have aspects of the system's functionalities changed.

## Example and Naive Approaches

Consider the following example of a maze design:
![structure](https://i.imgur.com/6coKEpc.png)

When using the maze class, in the system (`MazeGame` class), the initialization with reasonable
class definition would look like this:

```cpp
Maze* MazeGame::CreateMaze () {
    Maze* aMaze = new Maze;

    // Create the "products" that maze depends on
   Room* rl = new Room(l);
   Room* r2 = new Room (2);
   Door* theDoor = new Door(rl, r2);

    // Call maze functions to include the products
    aMaze->AddRoom(rl);
    aMaze->AddRoom(r2);

    // We are not done yet, the implementation details
    // also consists of setting the right states for the Wall
    // and Door products
    rl->SetSide(North, new Wall);
    rl->SetSide(East, theDoor);
    rl->SetSide(South, new Wall);
    rl->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, theDoor);
    return aMaze;
}
```

It is important to understand why the above naive instantiation approach for the maze
is not good enough.

**Inflexibility: The layout of the maze is coded with the details of the products making up for it.**

For example, if we would like to have a maze with special doors `DoorNeedingSpell`,
or `EnchantedRoom` that subclasses rooms with other features inside, then the problem
arises that we need to modify the above code which encodes both the layout of the
product and what are the products involved.

To summarize, the hard-coding of the classes that serve as the products for the
system is the biggest barrier, and there are in general 4 ways to remove these
explicit references:

1. The first and easiest approach is to remove constructors to `Room`, `Door`, etc,
and replace them with virtual functions `CreateRoom`, `CreateDoor`. Then a subclass
that overrides these methods can reuse the above layout logic, but supply different
types of these products. This is the *Factory Method* pattern.

2. Similar to 1), but with some variation that instead of having the creating class
itself implement the `CreateRoom`, `CreateDoor` methods, have a different object that
supplies these methods, and pass these objects around to achieve different combinations
of the product types. This is the *Abstract Factory Method* pattern.

## Pattern: Factory Method and Abstract Factory Method

Similarities:
Both rely on overriding methods that create the products.

Differences:
The system that uses the product creates the product directly in the Factory
Method via the creator class:

```cpp
// Factory Method: the creator itself has the logic for layout and factory methods
class MazeGame {
public:
    virtual Maze* MakeMaze() const
        { return new Maze; }
    // factory methods, override these to achieve differently
    // rooms
    virtual Room* MakeRoom(int n) const
        { return new Room(n); }
    virtual Wall* MakeWall() const
        { return new Wall; }
    virtual Door* MakeDoor(Room* rl, Room* r2) const
        { return new Door(rl, r2);

    // Don't override this so layout logic is shared
    Maze* CreateMaze() {
        Maze* aMaze = MakeMaze(),

        Room* rl = MakeRoom(1),
        Room* r2 = MakeRoom(2);
        Door* theDoor = MakeDoor(rl, r2);
        // Layout logic goes here...
    }
};
```

but a different object (the creator object) is used
having different product creation methods in the Abstract Factory Method:

```cpp
// Abstract Factory Method: this object can be passed around for different layout logic
class MazeFactory {
public:
    MazeFactory();
    virtual Maze* MakeMaze() const
        { return new Maze; }
    virtual Wall* MakeWall() const
        { return new Wall; }
    virtual Room* MakeRoom(int n) const
        { return new Room(n); }
    virtual Door* MakeDoor(Room* rl, Room* r2) const
        { return new Door(rl, r2); }
};

Maze* MazeGame::CreateMaze (MazeFactory& factory) {
    Maze* aMaze = factory.MakeMaze();

    Room* rl = factory.MakeRoom(1);
    Room* r2 = factory.MakeRoom(2);
    Door* aDoor = factory.MakeDoor(rl, r2);
    // Layout logic goes here...
}
```

But why? In what uses cases these 2 differences matter?

First, having the factory method in the inheritance chain enables sharing of common
and default behaviors. In the abstract factory method, to have different
products is to have different factory objects, which results in very limited
sharing. Use factory method when common behavior and internal details are to be
shared across all subclass products.

Second, factory methods can also be used for composite objects, and this
connects parallel class hierarchies. This happens when a product itself is further
composed of other products. A simple example is a `Figure` class chain
and a `Manipulator` class chain below, where each subclass of `Figure` has a unique
subclass of `Manipulator`, since different figures need different rendering
manipulation implementations. Now apart for creator/initialization objects,
each `Figure` class will have a factory method that creates the
corresponding manipulator. This can and should be used in the client code
when composing these figure objects to the system and controlling rendering
behaviors:

![structure](https://i.imgur.com/RhpnS0m.png)

More details on the factory method:

1. Default or not default in the creator class.
2. Parameters can be defined in the factory methods for finer control of
   the subclass created together with inheritance.
3. This can result in too much subclassing. [2] has a good treatment on
performance optimization in C++ using policy classes.

## Pattern: Builder

(TBD)
