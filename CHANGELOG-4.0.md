# [4.0.0](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0) (2018-XX-XX)

## Added
- Added `Phalcon\Db\Adapter\Pdo\Postgresql::describeReferences` to implement custom Postgresql rules

## Changed
- The `Phalcon\Mvc\Application`, `Phalcon\Mvc\Micro` and `Phalcon\Mvc\Router` now must have a URI to process [#12380](https://github.com/phalcon/cphalcon/pull/12380)
- Response headers and cookies are no longer prematurely sent [#12378](https://github.com/phalcon/cphalcon/pull/12378)
- You can no longer assign data to models whilst saving them [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- The `Phalcon\Mvc\Model\Manager::load` no longer reuses already initialized models [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Changed `Phalcon\Db\Dialect\Postgresql::describeReferences` to generate correct SQL, added "on update" and "on delete" constraints
- Change catch `Exception` to `Throwable` [#12288](https://github.com/phalcon/cphalcon/issues/12288)
- Changed `Phalcon\Mvc\Model\Query\Builder::addFrom` to remove third parameter `$with` [#13109](https://github.com/phalcon/cphalcon/pull/13109)

## Removed
- Removed `Phalcon\Model::reset` [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Removed deprecated `Phalcon\Cli\Console::addModules`
- Removed deprecated `Phalcon\Debug::getMajorVersion`
- Removed deprecated `Phalcon\Http\Request::isSoapRequested`
- Removed deprecated `Phalcon\Http\Request::isSecureRequest`
- Removed deprecated `Phalcon\Mvc\Model\Criteria::addWhere`
- Removed deprecated `Phalcon\Mvc\Model\Criteria::order`
- Removed deprecated `Phalcon\Validation\Validator::isSetOption`
- Removed deprecated `Phalcon\Security::hasLibreSsl`
- Removed deprecated `Phalcon\Security::getSslVersionNumber`
- Removed `Phalcon\Http\RequestInterface::isSoapRequested` in favor of `Phalcon\Http\Request::isSoap`
- Removed `Phalcon\Http\RequestInterface::isSecureRequest` in favor of `Phalcon\Http\RequestInterface::isSecure`
