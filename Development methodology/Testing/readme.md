# Why testing is important?
- **Easier bug catching**: Test code helps catch bugs early on when a test fails
- **Confidence after code changes**: Test code ensures that new code changes do not introduce bugs or break existing functionality.
- **Easier understanding of the code**: Test code acts as documentation for the application. They provide clear examples of what behavior is expected, which helps understand the codebase more easily and facilitates collaboration within the team.

Complex components must have test code in case they are modified to be sure that there are no bugs after modifying them!!

# Test pattern
1. **Given** this state(pre-conditions)
2. **When** this action is performed
3. **Then** this outcome is expected

## Unit test
In unit tests, external dependencies are replaced with mock dependencies for the unit to be isolated.

~~~java
class CalculatorTest{
  Calculator calc = new Calculator();

  @Test
  void plus(){
    //Given
    int a = 10;
    int b = 20;

    //When
    int result = calc.plus(a,b);

    //Then
    assertEquals(result, 30);
  }
}

class Calculator{
  public int plus(int a, int b){
    return a+b;
  }
}
~~~

# Test Driven Development
Test Driven Development (TDD) is a software development practice that focuses on creating unit test cases before developing the actual code.
