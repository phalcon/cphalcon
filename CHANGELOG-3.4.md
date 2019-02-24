# [3.4.3](https://github.com/phalcon/cphalcon/releases/tag/v3.4.3) (2018-02-24)
- Provided PHP 7.3 support [#13847](https://github.com/phalcon/cphalcon/issues/13847)

# [3.4.2](https://github.com/phalcon/cphalcon/releases/tag/v3.4.2) (2018-12-02)
- Added missing Volt tags to array helper in `Phalcon\Mvc\View\Engine\Volt\Compiler::functionCall` [#13447](https://github.com/phalcon/cphalcon/issues/13447)
- Added the ability to explicitly define nullable columns (especially timestamp ones) [#13099](https://github.com/phalcon/cphalcon/issues/13099)
- Refactored `Phalcon\Db\Adapter\Pdo::query` to use PDO's `prepare` and `execute` and `Phalcon\Db\Adapter::fetchAll` to use PDO's `fetchAll`
- Fixed `Phalcon\Validation\Validator\Numericality` to accept float numbers on locales with comma decimal point [#13450](https://github.com/phalcon/cphalcon/issues/13450)
- Fixed `Phalcon\Tag` so it unsets `parameters` before passing options array to `self::renderAttributes`
- Fixed `Phalcon\Http\Response::setFileToSend` filename; when file downloaded it had an extra `_`
- Fixed `Phalcon\Mvc\Model\Query::execute` to properly bind parameters to sub queries [#11605](https://github.com/phalcon/cphalcon/issues/11605)
- Fixed `Phalcon\Http\Request::getJsonRawBody` [#13501](https://github.com/phalcon/cphalcon/issues/13501). It will now return false when the body content is empty, as well as when it encounters an error whilst decoding the JSON content
- Fixed `Phalcon\Validation::preChecking` to allow use `Phalcon\Db\RawValue` as an empty container for `isAllowEmpty` option [#13549](https://github.com/phalcon/cphalcon/pull/13549), [#13573](https://github.com/phalcon/cphalcon/issues/13573), [#12519](https://github.com/phalcon/cphalcon/pull/12519)
- Fixed object binding and placeholder creation in `Phalcon\Db\Adapter::insert` and `Phalcon\Db\Adapter::update` [#13058](https://github.com/phalcon/cphalcon/issues/13058)
- Fixed `Phalcon\Config\Adapter\Ini` not building config objects properly for numerical keys [#12725](https://github.com/phalcon/cphalcon/issues/12725), [#13604](https://github.com/phalcon/cphalcon/issues/13604)
- Fixed incorrect scope of view variables
  [#12176](https://github.com/phalcon/cphalcon/issues/12176),
  [#12385](https://github.com/phalcon/cphalcon/issues/12385),
  [#12648](https://github.com/phalcon/cphalcon/issues/12648),
  [#12705](https://github.com/phalcon/cphalcon/issues/12705),
  [#13288](https://github.com/phalcon/cphalcon/pull/13288)
- Fixed `Phalcon\Config::_merge` not merging config with numeric properties properly [#13351](https://github.com/phalcon/cphalcon/issues/13351).

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
