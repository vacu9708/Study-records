# What testing contibutes to?
- **Easier bug catching**: Test cases induce developers to think about bugs and helps catch bugs early on on test fails
- **Confidence after code changes**: Test code ensures that new code changes do not introduce bugs or break existing functionality.
- **Encouraged good architecture**: Unit tests induce developers to write "testable code". Writing unit tests often requires breaking down complex systems into smaller, independent units. This encourages modular code with clear responsibilities, as units are easier to test in isolation.
- **Easier understanding of the code**: Unit tests act as documentation for the units. They provide clear examples of what behavior is expected, which helps understand the code more easily and facilitates collaboration within the team.

Complex components must have test code in case they are modified to be sure that there are no bugs after modifying them!!

### Test pattern
1. **Given** this state(pre-conditions)
2. **When** this action is performed
3. **Then** this outcome is expected
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

# Unit test
Unit testing focuses on testing individual components or functions of the software in isolation.<br>
In pure unit tests, all external dependencies are replaced with mock dependencies for the unit to be isolated.
### Pros
- External dependencies do not need to be taken into account by using mock objects.
### Cons
- May not catch errors in the interaction between different units.
- Can be time-consuming to set up mock dependencies
### Example
~~~java
@Test
void login_successful(){
    // Given
    UserCredentialsDto userCredentialsDto = new UserCredentialsDto("username", "password");
    // Mock authRepository.findByUsername() to return a user entity
    String hashedPassword = new BCryptPasswordEncoder().encode("password");
    UserEntity userEntity = new UserEntity(UUID.randomUUID(), "username", hashedPassword, "email");
    when(authRepository.findByUsername(any())).thenReturn(userEntity);
    // Mock redis template
    when(redisTemplate.opsForValue()).thenReturn(valueOperations);
    when(valueOperations.get(any())).thenReturn(null);
    // When
    ResponseEntity<?> response = authService.login(userCredentialsDto);
    // Then
    assertEquals(200, response.getStatusCode().value());
}
~~~

# Integration test
Integration testing focuses on testing the interactions between different units of the software without mocking. It ensures that different parts of the system work together as intended.<br>
### Example
Clean up the data tha was used after testing!
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/0df85c6c-2ec2-4144-b8d9-0bc88fed5d56)

### Pros
- Ensures that the different components of the system work together as intended.
### Cons
- It can be challenging to set up external dependencies.
- Ensuring that the data from the external dependencies used across different components is consistent can be a complex task.

# Testing strategy
While pure unit testing ideally mocks every external dependency for isolation, practical considerations may lead to unit tests that do interact with some external dependencies that are easy to set up.
While pure integration testing ideally involves real components, practical considerations may lead to some level of mocking, especially for components that are difficult to set up and costly.
### Then? hybrid approach
It's common to see a mix of mocked and real dependencies in a test suite.<br>
This hybrid approach can be a good trade-off between unit testing and integration testing.
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/8f665b2e-4f91-4fbd-9ce8-ba241ab90bb1)

---

# Test Driven Development
Test Driven Development (TDD) is a software development practice that focuses on creating unit test cases before developing the actual code.
