# [3.3.2](https://github.com/phalcon/cphalcon/releases/tag/v3.3.2) (2018-03-04)
- Fixed `Phalcon\Db\Dialect\Mysql::modifyColumn` to produce valid SQL for renaming the column [#13012](https://github.com/phalcon/cphalcon/issues/13012)
- Fixed `Phalcon\Forms\Form::getMessages` to return back previous behaviour: return array of messages with element name as key [#13294](https://github.com/phalcon/cphalcon/issues/13294)
- Fixed `Phalcon\Mvc\Model\Behavior\SoftDelete::notify` to solve the exception that soft deletion renamed model [#13302](https://github.com/phalcon/cphalcon/issues/13302), [#13306](https://github.com/phalcon/cphalcon/issues/13306)
- Fixed `E_DEPRECATED` error for `each()` in `Phalcon\Debug\Dump` [#13253](https://github.com/phalcon/cphalcon/issues/13253)
- Fixed `Phalcon\Cache\Backend\Redis::exists` to always return boolean [#13066](https://github.com/phalcon/cphalcon/issues/13066)

# [3.3.1](https://github.com/phalcon/cphalcon/releases/tag/v3.3.1) (2018-01-08)
- Fixed a boolean logic error in the CSS minifier and a corresponding unit test so that whitespace is stripped [#13200](https://github.com/phalcon/cphalcon/pull/13200)
- Fixed `default` Volt filter [#13242](https://github.com/phalcon/cphalcon/issues/13242), [#13244](https://github.com/phalcon/cphalcon/issues/13244)
- Fixed `Phalcon\Validation\Validator\Date` to return code in validation message

# [3.3.0](https://github.com/phalcon/cphalcon/releases/tag/v3.3.0) (2017-12-23)
- Added support of PHP 7.2 and initial support of PHP 7.3
- Added support for `switch/case` syntax to the Volt Engine [#13107](https://github.com/phalcon/cphalcon/issues/13107)
- Added `Phalcon\Logger\Adapter\Blackhole` [#13074](https://github.com/phalcon/cphalcon/issues/13074)
- Added `Phalcon\Http\Request::hasHeader` to check if certain header exists
- Added support of [`103 (Early Hint)`](https://datatracker.ietf.org/doc/draft-ietf-httpbis-early-hints) HTTP status code
- Added `router:beforeMount` event to `Router::mount` [#13158](https://github.com/phalcon/cphalcon/issues/13158)
- Added `Phalcon\Mvc\Application::sendHeadersOnHandleRequest` to enable or disable sending headers by each request handling [#13101](https://github.com/phalcon/cphalcon/issues/13101)
- Added `Phalcon\Mvc\Application::sendCookiesOnHandleRequest` to enable or disable sending cookies by each request handling [#13101](https://github.com/phalcon/cphalcon/issues/13101)
- Added ability to use PDO option aliases on database connect [#13010](https://github.com/phalcon/cphalcon/issues/13010)
- Added `Phalcon\Mvc\Model\MetaData\Apcu` [#13078](https://github.com/phalcon/cphalcon/issues/13078)
- Added ability to use string(file path) as a argument in `Phalcon\Config\Factory::load()`
- Added `Phalcon\Mvc\Mico\Collection::mapVia` to map routes via methods
- Added `Phalcon\Mvc\Model::setOldSnapshotData` to set old snapshot data separately to current snapshot data
- Added `Phalcon\Http\Response::removeHeader` to remove specific header from response
- Added `Phalcon\Mvc\Query::setTransaction` to enable an override transaction [#13226](https://github.com/phalcon/cphalcon/issues/13226)
- Fixed `Phalcon\Mvc\Model\Query\Builder::getPhql` to correct generate PHQL in argument's array when using order DESC or ASC [#11827](https://github.com/phalcon/cphalcon/issues/11827)
- Fixed `Phalcon\Db\Dialect\Postgresql::createTable` to produce valid SQL for table definition with `BOOLEAN` types [#13132](https://github.com/phalcon/cphalcon/issues/13132)
- Fixed `Phalcon\Db\Dialect\Postgresql::_castDefault` to return correct value for `BOOLEAN` type [#13132](https://github.com/phalcon/cphalcon/issues/13132), [phalcon/phalcon-devtools#1118](https://github.com/phalcon/phalcon-devtools/issues/1118)
- Fixed `Phalcon\Mvc\Model::_doLowInsert` to correct save snapshot on creation/save identityless models [#13166](https://github.com/phalcon/cphalcon/issues/13166)
- Fixed `Phalcon\Mvc\Model::_doLowUpdate` to correctly work with `Phalcon\Db\RawValue` [#13170](https://github.com/phalcon/cphalcon/issues/13170)
- Fixed `Phalcon\Mvc\Model::allowEmptyStringValues` to correct works with saving empty string values when DEFAULT not set in SQL
- Fixed `Phalcon\Mvc\Model\Behavior\SoftDelete` to correctly update snapshots after deleting item
- Fixed `Phalcon\Mvc\Model` to set old snapshot when no fields are changed when dynamic update is enabled
- Fixed `Phalcon\Acl\Adapter\Memory::isAllowed` to properly pass role and resource objects to custom function if they are objects of the same class
- Changed `Phalcon\Mvc\Model` to allow to pass a transaction within the query context [#13226](https://github.com/phalcon/cphalcon/issues/13226)
