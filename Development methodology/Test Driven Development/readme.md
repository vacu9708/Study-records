# Test Driven Development
Test Driven Development (TDD) is a software development practice that focuses on creating unit test cases before developing the actual code.

## Why TDD is important?
- **Easier bug catching**: TDD helps catch bugs early on when a test fails
- **Confidence after code changes**: TDD ensures that new code changes do not introduce bugs or break existing functionality.
- **Easier understanding of the code**: Tests written as part of TDD act as documentation for the code. They provide clear examples of how what behavior is expected. This helps other developers understand the codebase more easily and facilitates collaboration within the team.

## Pattern
1. **Given** this state(pre-conditions)
2. **When** this action is performed
3. **Then** this outcome is expected

## Unit test
In unit tests, external dependencies are replaced with mock objects.

~~~java
class Calculator{
  public int plus(int a, int b){
    return a+b;
  }
}

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
~~~
