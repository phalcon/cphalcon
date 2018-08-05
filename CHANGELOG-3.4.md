# [3.4.1](https://github.com/phalcon/cphalcon/releases/tag/v3.4.1) (2018-08-04)
- Changed `Phalcon\Cache\Backend\Redis` to support connection timeout parameter
- Fixed `Phalcon\Validaiton\Validator\Uniqueness::isUniquenessModel` to properly get value of primary key when it has different name in column map [#13398](https://github.com/phalcon/cphalcon/issues/13398)
- Fixed bad performance for repeated `Phalcon\Mvc\Router::getRouteByName` and `Phalcon\Mvc\Router::getRouteById` calls for applications with many routes
- Fixed incorrect tinyblob bind type in `Phalcon\Db\Adapter\Pdo\Mysql::describeColumns` [#13423](https://github.com/phalcon/cphalcon/issues/13423)
- Fixed `Phalcon\Http\Request::getPut` to provide json content-type support [#12892](https://github.com/phalcon/cphalcon/issues/12892), [#13418](https://github.com/phalcon/cphalcon/issues/13418)

# [3.4.0](https://github.com/phalcon/cphalcon/releases/tag/v3.4.0) (2018-05-28)
- Added `Phalcon\Mvc\Router::attach` to add `Route` object directly into `Router` [#13326](https://github.com/phalcon/cphalcon/issues/13326)
- Added the ability to listen `request:beforeAuthorizationResolve` and `request:afterAuthorizationResolve` events. This ability enables using custom authorization resolvers [#13327](https://github.com/phalcon/cphalcon/pull/13327)
- Added call event `afterFetch` in `Phalcon\Mvc\Model:refresh` [#12220](https://github.com/phalcon/cphalcon/issues/12220)
- Added `Phalcon\Http\Response::getReasonPhrase` to retrieve the reason phrase from the `Status` header [#13314](https://github.com/phalcon/cphalcon/pull/13314)
- Added `Phalcon\Loader::setFileCheckingCallback` to set internal file existence resolver [#13360](https://github.com/phalcon/cphalcon/issues/13360)
- Added ability to pass aggregation options for `Phalcon\Mvc\Collection::aggregate` [#12302](https://github.com/phalcon/cphalcon/pull/12302)
- Added `Phalcon\Crypt::setHashAlgo` to set the name of hashing algorithm used to the calculating message digest [#13379](https://github.com/phalcon/cphalcon/issues/13379)
- Added `Phalcon\Crypt::getHashAlgo` to get the name of hashing algorithm used to the calculating message digest [#13379](https://github.com/phalcon/cphalcon/issues/13379)
- Added `Phalcon\Crypt::useSigning` to set if the calculating message digest must used (NOTE: This feature will be enabled by default in Phalcon 4.0.0) [#13379](https://github.com/phalcon/cphalcon/issues/13379)
- Added `Phalcon\Crypt::getAvailableHashAlgos` to get a list of registered hashing algorithms suitable for calculating message digest [#13379](https://github.com/phalcon/cphalcon/issues/13379)
- Added `Phalcon\Crypt::__construct` so now the cipher can be set at object construction and the calculating message digest can be enabled without the need to call `setCipher` or `useSigning` explicitly [#13379](https://github.com/phalcon/cphalcon/issues/13379)
- Added `Phalcon\Crypt\Mismatch`. Exceptions thrown in `Phalcon\Crypt` will use this class [#13379](https://github.com/phalcon/cphalcon/issues/13379)
- Added `Phalcon\Http\Cookie::setSignKey` to set sign key used to generate a message authentication code (eg. message digest)
- Added `Phalcon\Http\Response\Cookies::setSignKey` to set sign key used to generate a message authentication code (eg. message digest)
- Changed `Phalcon\Crypt::setCipher` so that IV length will be reconfigured during setting the cipher algorithm
- Changed `Phalcon\Crypt::setCipher` so that method will throw `Phalcon\Crypt\Exception` if a cipher is unavailable
- Fixed regression ([#13308](https://github.com/phalcon/cphalcon/pull/13308)) for `Phalcon\Debug\Dump::output` to correctly work with detailed mode [#13315](https://github.com/phalcon/cphalcon/issues/13315)
- Fixed `Phalcon\Mvc\Model\Query\Builder::having` and `Phalcon\Mvc\Model\Query\Builder::where` to correctly merge the bind types [#11487](https://github.com/phalcon/cphalcon/issues/11487)
- Fixed `Phalcon\Mvc\Model::setSnapshotData` to properly sets the old snapshot
- Do not throw Exception when superglobal does not exist [#13252](https://github.com/phalcon/cphalcon/issues/13252), [#13254](https://github.com/phalcon/cphalcon/issues/13254), [#12918](https://github.com/phalcon/cphalcon/issues/12918)
