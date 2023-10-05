# Behavior Patterns

## Pattern: Iterator and Vistor

I put them together not to emphasize how much similarities they share. On the contrary,
it is important to know how the Vistor pattern differs from the Iterator patten in *what problem they are solving*:

> [Vistor Pattern] Represent an operation to be performed on the elements of an
object structure. Visitor lets you define a new operation without changing the
classes of the elements on which it operates.

On the other hand, the iterator pattern is more straightforward to its name:

> [Iterator Pattern] Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

It is easier to understand, more versatile, and no need for further examples.

Visitor pattern concerns decoupling the subject (elements with the context
information to have operations acted upon) from the object (the actors knowing what
operations it can and will perform given the subject). For example, in compiler frontend
implementation, subjects are parsed nodes from the source code, and the
objects (various routines/passes in the compilation) need to perform
various operations like `TypeCheck()`, `GenCode()`, `PrettyPrint()`.

The key problem here is, that we have 2 kinds of variables here: the subject is dynamic
(could be an assignment or a variable), and the object is also dynamic
(depending on the compilation pipeline, we could be doing type check, or should
start to generate code). The idea to solve the problem here is "double-dispatching":

```cpp
// Visitor only defines the object for the operations
class Visitor {
public:
    virtual bool VisitAssignment(AssignmentNode *) = 0;
    virtual bool VisitVariable(VariableNode *) = 0;
};

// Concrete objects for the details of the operations
class TypeCheckingVisitor : public Vistor{
public:
    bool VisitAssignment(AssignmentNode *);
    bool VisitVariable(VariableNode *);
}

class CodeGenVisitor : public Vistor{
public:
    bool VisitAssignment(AssignmentNode *);
    bool VisitVariable(VariableNode *);
}
```

Now the different type of node will use `Accpet()` method to dispatch the correct method by picking the right type:

```cpp
class Node {
public:
    virtual void Accpet(Visitor v) = 0;
}

class AssignmentNode {
    public Accept(Visitor v) {
        v->VisitAssignment(this); // this is the key: dispatch to the right type
    }
}

class AssignmentNode {
    public Accept(Visitor v) {
        v->VisitVariable(this);
    }
}
```

Note how the subject (`Node`) knows nothing about the details of the visitor. This is
how it allows for having new visitor types (objects) without changing the logic
of traversal nor subjects' implementations.

Here the dispatch ("which function of `Visit*` to call?") is determined by *2*
factors (and happens to be both in the runtime, which gives good flexibility): the type of
the `Node` (via implementation of Accept) and the subclass of the visitor
(via polymorphism in the Visitor class).

Note also that it makes it easy to add a new operation to have a new subclass
of Visitor, but hard to have a new type of the `Node` (need to update all visitors). Indeed,
the above double-dispatch is not symmetric, and using this pattern requires good judgment
in how the future the code base will evolve and be extended. Usually, the compiler will get more
features to be implemented (new operations) than having a new `Node` type (new grammar/syntax),
so in this case, the visitor subclasses are operations, not the type of the nodes in the parsed tree.

Curiously, iterator patterns and visitor patterns are not replacements, they usually
can be used together: the compiler parsing can expose a cursor that emits an abstract node,
using iterator pattern to hide the underlying non-linear, lazily evaluated data structure,
and each node can call `Accept` over the visitor(s) configured in the compiler. Another good
example of using an iterator to hide the fact of aggregation (sometimes even in a lazy manner)
is merging multiple other iterators using customized sorting/merging policies, like in LSM trees
tombstones are "collapsed" and no need to be emitted.

## Pattern: Observer

Simple, effective, and versatile. Since this pattern concerns about object dependency itself directly,
many class design involves this pattern and is usually the first one in many's arsenal.

> Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

![structure](https://i.imgur.com/fgZZ2xT.png)
