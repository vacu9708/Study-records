An aspect is a module consisting of cross-cutting functionalities that can be applied to multiple methods scattered throughout the application.<br>
In AOP, **cross-cutting functinalities** are defined in a central location called Aspect.<br>
Cross-cutting concerns refers to concerns that are scattered across multiple parts of a program and are not localized to a specific module.<br>
The IoC container takes control of object management and weaves aspects into the appropriate components.<br>

![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/6f020c38-a8fd-472a-bc3b-70fc1b1dd951)

Suppose we want to add logging functionality to methods in the "UserService" class to track the execution time of each method.<br>
In the traditional OOP, the logging functionality had to be included in every method that needs it.<br>
With AOP, there is no need to include it in every method that needs the functionality because The modularized LoggingAspect goes to where it is needed on its own.<br>

Here's an example of how to define a "logging" aspect in Spring AOP:<br>
~~~java
@Aspect
@Component
public class LoggingAspect {

    private static final Logger logger = LoggerFactory.getLogger(LoggingAspect.class);

    @Around("execution(* com.example.UserService.*(..))")
    public Object logExecutionTime(ProceedingJoinPoint joinPoint) throws Throwable {
        long startTime = System.currentTimeMillis();
        // Continue the intercepted method
        Object proceed = joinPoint.proceed();
        long endTime = System.currentTimeMillis();
        logger.info("Execution time of " + joinPoint.getSignature().getName() + " : " + (endTime - startTime) + " ms");
        // Finish the aspect method
        return proceed;
    }
}
~~~
>**@Around** makes the aspect be executed before and after the target method.<br>

The logging functionality can be separated from the code of the "UserService" class and be applied to multiple places in the application without duplicating code.<br>
