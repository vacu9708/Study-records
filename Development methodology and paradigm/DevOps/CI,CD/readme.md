# CI/CD
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/731151d8-f1ed-4653-a286-5f82a5de39fb)

CI/CD aims to automate the building, testing, and deployment of software.

## Continuous Integration (CI):
Continuous Integration automates the integration of code from multiple contributors into a shared repository.
### How CI works:
1. `Complete changes and push:` Developers work on their code in separate branches. And then a developer completes their code changes and pushes it to github
2. `CI process triggered:` The CI system is triggered and pulls the code changes from github to a dedicated (cluster of) server(s).
3. `Automated build and test:` The CI system then proceeds with building the app and running the tests such as unit tests, integration tests, and stress tests.
4. `Reports generated:` Reports are generated based on the test results. If any issues arise during the CI process, developers are notified, and they can quickly fix the problems.
5. `Manual testing:` Automated tests may not catch everything. Manual testing can be valuable for assessing usability, visual design, and other aspects that might be difficult to capture in automated tests.
6. `Merge:` If the process was successful, the developer then manually merges the code into the parent branch.

## Continuous Deployment (CD):
Continuous Deployment (CD) automates the process of releasing software to production.
### How CD works:
1. The 1,2,3,4,5 step of the CI are performed in a deployment branch and a (cluster of) server(s).
2. Successful builds are automatically deployed to the production environment.

## [How to use Jenkins](https://github.com/vacu9708/Tools-etc/tree/main/jenkins)
