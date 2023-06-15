# CI/CD
CI/CD aims to automate the building, testing, and deployment of software.

# Continuous Integration (CI):
Continuous Integration automates the integration of code from multiple contributors into a shared repository.<br>

### How CI works:
1. Developers work on their code in separate branches.
2. A developer completes their code changes and pushes it to github, which triggers the CI process.
3. The CI system pulls the code changes from github.
4. The CI system then proceeds with building the code and running the tests such as unit tests, e2e tests, and stress tests.
5. It generates reports based on the test results. If any issues arise during the CI process, developers are notified, and they can quickly fix the problems.
6. If the build and tests are successful, The developer then manually merges their code changes into the parent branch.

# Continuous Deployment (CD):
Continuous Deployment (CD) automates the process of releasing software to production.<br>

### How CD works:
1. A new commit to a deployment branch triggers the CD process.
2. The 3,4,5 step of the CI is performed in the CD system.
3. Successful builds are automatically deployed to the production environment.
