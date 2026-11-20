
Contributing
============

If you would like to contribute code to this project you can do so through GitHub by forking the repository and sending a pull request. Before RDK accepts your code into the project you must sign the RDK Contributor License Agreement (CLA).

Pull requests
-------------

* Base your changes on the `develop` branch.
* Keep each pull request focused on a single change and describe what it does and why.
* Update the README if you add features, change behavior or introduce breaking changes.

Testing
-------

Build and run the unit tests before submitting a pull request:

```
mkdir build
cd build
cmake ..
make
make test
```

Add or update unit tests in `tests/` for any new or changed behavior.
