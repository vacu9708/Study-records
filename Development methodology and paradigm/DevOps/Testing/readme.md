# What testing contibutes to?
- **Easier bug catching**: Test cases induce developers to think about bugs and helps catch bugs early on on test fails
- **Confidence after code changes**: Test code ensures that new code changes do not introduce bugs or break existing functionality.
- **Encouraged good architecture**: Unit tests induce developers to write "testable code". Writing unit tests often requires breaking down complex systems into smaller, independent units. This encourages modular code with clear responsibilities, as units are easier to test in isolation.
- **Easier understanding of the code**: Unit tests act as documentation for the units. They provide clear examples of what behavior is expected, which helps understand the code more easily and facilitates collaboration within the team.

Complex components must have test code in case they are modified to be sure that there are no bugs after modifying them!!

# Test pattern
1. **Given** this state(pre-conditions)
2. **When** this action is performed
3. **Then** this outcome is expected

## Unit test
Unit testing focuses on testing individual components or functions of the software in isolation.<br>
In unit tests, external dependencies are replaced with mock dependencies for the unit to be isolated.
### Pros
- External dependencies do not need to be taken into account by using mock objects.
### Cons
- May not catch errors in the interaction between different units.
- Can be time-consuming to write and maintain.

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

## Integration test
Integration testing focuses on testing the interactions between different units of the software. It ensures that different parts of the system work together as intended.
### Pros
- Ensures that the different components of the system work together as intended.
### Cons
- Ensuring that the data from the external dependencies used across different components is consistent and in the right state for testing can be a complex task.

# Test Driven Development
Test Driven Development (TDD) is a software development practice that focuses on creating unit test cases before developing the actual code.
