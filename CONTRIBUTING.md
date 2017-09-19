# Contributing to Phalcon

Phalcon is an open source project and a volunteer effort. Phalcon welcomes contribution from everyone. Please take a moment to review this document in order to make the contribution process easy and effective for everyone involved.

Following these guidelines helps to communicate that you respect the time of the developers managing and developing this open source project. In return, they should reciprocate that respect in addressing your issue or assessing patches and features.

## Contributions

Contributions to Phalcon should be made in the form of GitHub pull requests.
Each pull request will be reviewed by a core contributor (someone with permission to land patches) and either landed in
the main tree or given feedback for changes that would be required before it can be merged. All contributions should
follow this format, even those from core contributors.

## Questions & Support

*We only accept bug reports, new feature requests and pull requests in GitHub*.
For questions regarding the usage of the framework or support requests please visit the [official forums][forum].

## Bug Report Checklist

- Make sure you are using the latest released version of Phalcon before submitting a bug report.
  Bugs in versions older than the latest released one will not be addressed by the core team

- If you have found a bug it is important to add relevant reproducibility information to your issue to allow us 
  to reproduce the bug and fix it quicker. Add a script, small program or repository providing the necessary code to 
  make everyone reproduce the issue reported easily. If a bug cannot be reproduced by the development it would be
  difficult provide corrections and solutions. [Submit Reproducible Test][srt] for more information.

- Be sure that information such as OS, Phalcon version and PHP version are part of the bug report

- If you're submitting a Segmentation Fault error, we would require a backtrace, please see [Generating a Backtrace][gb]

## Pull Request Checklist

- Don't submit your pull requests to the `master` branch. Branch from the required branch and,
  if needed, rebase to the proper branch before submitting your pull request.
  If it doesn't merge cleanly with master you may be asked to rebase your changes

- Don't put submodule updates in your pull request unless they are to landed commits

- Add tests relevant to the fixed bug or new feature. See our [testing guide][testing] for more information.

- Phalcon is written in [Zephir][zephir], please do not submit commits that modify C generated files directly or
  those whose functionality/fixes are implemented in the C programming language

- Remove any change to `ext/kernel`, `*.zep.c` and `*.zep.h` files before submitting the pull request

## Getting Support

If you have a question about how to use Phalcon, please see the [support page][support].

## Requesting Features

If you have a change or new feature in mind, please fill an [NFR][nfr].

Thanks! <br />
Phalcon Team

[forum]: https://forum.phalconphp.com/
[srt]: https://github.com/phalcon/cphalcon/wiki/Submit-Reproducible-Test
[gb]: https://github.com/phalcon/cphalcon/wiki/Generating-a-backtrace
[testing]: https://github.com/phalcon/cphalcon/blob/master/tests/README.md
[zephir]: https://zephir-lang.com/
[support]: https://phalconphp.com/support
[nfr]: https://github.com/phalcon/cphalcon/wiki/New-Feature-Request---NFR
