# Multi Layered Project Example

In this example we can see a number of practices that can be used in a project 
that is above trivial. A project that is comprised of multiple classes and 
organized in multiple layers. Our classes support abstraction, composition, 
inheritance and make use of some of the techniques that modern C++ offers.

### Namespaces

Namespaces is a way to organize our code in logical sections. They also help us 
to avoid collisions of symbols and keep the global namespace clean.

Here we make use of namespaces and in particular the nested feature (C++17).
Also we follow the java model where a namespace is backed by a physical folder 
in the filesystem. So we have "node" and "node::graph" namespaces.

In case you have not payed attention, a namespace like "node::graph" is a bit 
different than lets say java a package in that it includes also the symbols 
from the "node" namespace. We can understand thss if we consider that it is 
simply a shorter form of the equivalent:

```
namespace node {
	namespace graph {
		// ...
	}
}
```

### Using namespace std

We want our code to be clean and tidy as much as possible. There is a good deal 
of advice to not use the using statement, which imports symbols in to our scope.

It is true, because of the peculiarities of C/C++ with regard to combining code 
through the prepocessor, "using" can be problematic *if* we use it carelessly, 
especially in header files that are included by client code. We do not want to 
polute our client namespace after all.

Having said this, we can use this feature in in implementation files (.cpp).
In addition we can use it inside our own namespaces.

Now, the controversial assumption. We import the std namespace in its entirety. 
And actually, this should not be weird. In any other programming language, you 
take for granted the standard library and simply avoid colliding your symbols 
with the standard ones. When you program in java, Object. String, Date, Long, 
etc. are by default included in your namespace. This is not a problem. You 
simply not collide your symbols with the standard ones. The same holds even 
for symbols that are not imported by default. You simply take care to not name 
your class Map or List or Vector. And if you did, having the standard symbols 
imported is good because it will make you fix your code.

So we use "using" in our implementation code but also in our declaration code, 
encapsulated in our namespace.

```
unordered_map<string, shared_ptr<Node>>
```

is way better than:

```
std::unordered_map<std::string, std::shared_ptr<Node>>
```

noise out, signal in.

### Consolidated includes

Another popular advice is to only include the headers you use at each specific 
file. It make sense. We choose to go against this advice.

Figuring out which includes should go to which headers, implementations, and 
in which order can be a big pain - and then multiplied by the number of source 
files in the project.

I have personally discovered this technique from the open source library cocos. 
One header file that consolidates all headers, in the correct order. Every 
other file, header or implementation, simply includes this file. Done. Simple. 
No more pain.

You can even turn this file into a precompiled header for extra joy.

Of course there can be more than one such consolidation files, so that we 
maintain sanity of our organization. Here we use one per layer.

### Strive for runtime instead of compile time polymorphism

This might be one of the most controversial decisions one has to make while 
programming with C++. And that is because, even though C++ was born with 
runtime polymorphism in mind, early on it took a steep turn towards compile 
time polymorphism and has kept on that direction ever since.

STL is all about templates and duck typing. For a language that was concieved 
as "C with classes" you tend to not find a lot of them in the standard library.

And that is ok! It is just not my style. Besides I have some objections that 
can seem theoritical, though they are not. Runtime polymophism will always be 
more powerfull than compile time. And simpler. Maybe a bit slower, and that is 
a big maybe. Practically every other programming language out there (at least 
that I am familiar with) is based on leveraging the runtime.
Forget the J family. If you have doubts, look at Objective-C. Runtime rules!

Full runtime polymorphism. Every object allocated on the heap. All reference 
counted. Performance not an issue.

https://www.mikeash.com/pyblog/autorelease-is-fast.html

Back on topic. Parameterizing a class is cool. Not having an interface for 
it is not. I made a composite Iterator the other day. I was interested in 
parameterizing on the collection value type. But I could not hold the 
encapsulated iterator instances without parameterizing on its type.

You know why. Because iterators have no freakin base class! Darn!
Can I please have an interface for vector, list, etc.? That, they say, would be 
a virtual reality.

### No implementation in header files

We strongly prefer header files to contain only declarations. No single line of 
code in them. No matter how small or cute. It is a policy.

The only exception, might be templates. Unfortunatelly they have to carry their 
whole implementation along to the client code that uses them. We still may code 
them in separate files and include the implementation from the header, instead 
of the usual inverse scenario in plain classes.
