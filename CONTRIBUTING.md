# Contributing to Phalcon

Phalcon is an open source project and a volunteer effort. Phalcon welcomes contribution from everyone.
Please take a moment to review this document in order to make the contribution process easy and effective for everyone
involved.

Following these guidelines helps to communicate that you respect the time of the developers managing and developing this
open source project. In return, they should reciprocate that respect in addressing your issue or assessing patches and
features.

## Contributions

Contributions to Phalcon should be made in the form of GitHub pull requests.
Each pull request will be reviewed by a core contributor (someone with permission to land patches) and either landed in
the main tree or given feedback for changes that would be required before it can be merged. All contributions should
follow this format, even those from core contributors.

## Questions & Support

We use the GitHub issues for tracking bugs and feature requests and have limited bandwidth to address all of them. Thus
we only accept bug reports, new feature requests and pull requests in GitHub. Our great community and contributors are
happy to help you though! Please use these community resources for obtaining help.

_Please use the [Documentation](https://docs.phalconphp.com) before anything else. You can also use the search feature
in our documents to find what you are looking for. If your question is still not answered, there are more options below._

* Questions should go to [Official Forums](https://forum.phalconphp.com)
* Another way is to ask a question on [Stack Overflow](https://stackoverflow.com/) and tag it with
  [`phalcon`](https://stackoverflow.com/questions/tagged/phalcon)
* Come join the Phalcon [Discord](https://phalcon.link/discord)
* There is a less active but still functioning community on [Slack](https://phalcon.link/slack)
* Our social network accounts are: [Gab.ai](https://phalcon.link/gab), [Twitter](https://phalcon.link/t),
  [Facebook](https://phalcon.link/fb) and [Google+](https://phalcon.link/gplus)
* If you still believe that what you found is a bug, please
  [open an issue](https://github.com/phalcon/cphalcon/issues/new)

Please report bugs when you've exhausted all of the above options.

## Bug Report Checklist

* Make sure you are using the latest released version of Phalcon before submitting a bug report.
  Bugs in versions older than the latest released one will not be addressed by the core team
* If you have found a bug it is important to add relevant reproducibility information to your issue to allow us 
  to reproduce the bug and fix it quicker. Add a script, small program or repository providing the necessary code to 
  make everyone reproduce the issue reported easily. If a bug cannot be reproduced by the development it would be
  difficult provide corrections and solutions.
  [Submit Reproducible Test](https://docs.phalconphp.com/en/latest/reproducible-tests) for more information
* Be sure that information such as OS, Phalcon version and PHP version are part of the bug report
* If you're submitting a [Segmentation Fault](https://en.wikipedia.org/wiki/Segmentation_fault) error, we would require
  a backtrace, please see [Generating a Backtrace](https://docs.phalconphp.com/en/latest/generating-backtrace)

## Pull Request Checklist

* Don't submit your pull requests to the `master` branch. Branch from the required branch and,
  if needed, rebase to the proper branch before submitting your pull request.
  If it doesn't merge cleanly with master you may be asked to rebase your changes
* Don't put submodule updates in your pull request unless they are to landed commits
* Add tests relevant to the fixed bug or new feature. Test classes should follow the
  [PSR-2 coding style guide](https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-2-coding-style-guide.md).
  See our [testing guide](https://github.com/phalcon/cphalcon/blob/master/tests/README.md) for more information
* Phalcon is written in [Zephir](https://zephir-lang.com/), please do not submit commits that modify C generated files
  directly or those whose functionality/fixes are implemented in the C programming language
* Remove any change to `ext/kernel`, `*.zep.c` and `*.zep.h` files before submitting the pull request

## Requesting Features

If you have a change or new feature in mind, please fill an
[NFR](https://docs.phalconphp.com/en/latest/new-feature-request) on the GitHub. Alternatively you may also request features via [the FeatHub page](https://feathub.com/phalcon/cphalcon).


Thanks! <br />
Phalcon Team
