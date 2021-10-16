// creates a "type" for the function
typedef void Something(int x);

// adds the name Foo to the global "namespace" so you don't have to continually type "struct Foo"
typedef struct Foo Foo;
struct Foo
{
  // pointer to the function type
  Something *something;
};

// the actual function
void something(int x)
{
  // whatever you want it to do
}

// fills in the struct's data 
Foo init_foo()
{
  Foo foo;
  // links the function pointer to the actual function
  foo.something = something;
  return foo;
}

int main()
{
  Foo foo = init_foo();
  
  // calls the function pointer, which in turn points to the original function
  foo.something(1);

  return 0;
}