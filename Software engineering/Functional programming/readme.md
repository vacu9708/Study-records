![image](https://user-images.githubusercontent.com/67142421/178240477-49b802bc-deb5-427b-a414-712d4b49349a.png)

## Imperative programming
>Traditional programming languages before functional programming.<br>
Step-by-step instructions to complete a goal are specified.<br>
It is about ***how to do something*** like driving a manual car.

## Declarative programming
Includes functional programming.
>SQL, HTML <br>
It is a much higher level of abstraction that specifies only the goal without step-by-step instrunctions.<br>
It is about ***What to do*** like driving an automatic car.<br>
Imperative instructions should be abstracted well in advance so that declarative programming works well.

# Example of Imperative programming and declarative programming
Both make the same output. [2,4,6,8]
## Imperative programming
~~~javascript
function double_all_elements (arr) {
  let results = []
  for (let i = 0; i < arr.length; i++)
    results.push(arr[i] * 2)
  return results
}
console.log(double_all_elements([1,2,3,4]))
~~~

## Functional programming
~~~javascript
function double_all_elements (arr) {
  return arr.map((item) => item * 2)
}
console.log(double_all_elements([1,2,3,4]))
~~~
