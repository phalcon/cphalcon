# [4.0.0](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0) (2017-XX-XX)
- MVC Application and Router now must have a URI to process [#12380](https://github.com/phalcon/cphalcon/pull/12380)
- Response headers and cookies are no longer prematurely sent [#12378](https://github.com/phalcon/cphalcon/pull/12378)
- You can no longer assign data to models whilst saving them [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- `ModelManager::load()` no longer reuses already initialized models [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Removed `Model::reset()` [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Changed `Phalcon\Db\Dialect\Postgresql::describeReferences` to generate correct SQL for postgresql adapter, added constraints on update and on delete
- Added `Phalcon\Db\Adapter\Pdo\Postgresql::describeReferences` method for postgresql adapter
- Change catch Exception to Throwable [#12288](https://github.com/phalcon/cphalcon/issues/12288)
