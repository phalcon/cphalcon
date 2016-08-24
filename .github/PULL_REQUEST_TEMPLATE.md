Thank you for wanting to contribute to Phalcon.

Before you submit a Pull Request, please bear in mind that PRs must be made on a
version branch (eg. `3.0.x`). `master` marks the latest stable release so PRs
targeting `master` will be **rejected**.

Please also check the following points are being met:

- [ ] Make sure that the PR passes in Travis CI to make the process more efficient.
- [ ] Only use tabs for indentation.
- [ ] if needed, rebase to the proper branch before submitting your pull request.
      If it doesn't merge cleanly with master you may be asked to rebase your changes.
- [ ] Don't put submodule updates in your pull request unless they are to landed commits.
- [ ] Add tests relevant to the fixed bug or new feature. See our testing guide for
      more information.
- [ ] Phalcon 2 is written in Zephir, please do not submit commits that modify C generated
      files directly or those whose functionality/fixes are implemented in the C
      programming language
- [ ] Remove any change to ext/kernel / *.zep.c / *.zep.h files before submitting the PR

