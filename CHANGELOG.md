# [3.4.5](https://github.com/phalcon/cphalcon/releases/tag/v3.4.5) (2019-10-30)
- Fixed segfault in `Phalcon\Mvc\Micro\LazyLoader::__call()` when the handler has a syntax error. [#12396](https://github.com/phalcon/cphalcon/issues/12396)
- Fixed RuntimeException in `Phalcon\Db\Adapter\Pdo` Trying to call method upper on a non-object. [#14330](https://github.com/phalcon/cphalcon/issues/14330)
- Fixed `Phalcon\Storage\Adapter\Redis::delete()` deprecated warning from php-redis [#14281](https://github.com/phalcon/cphalcon/issues/14281)

# [3.4.4](https://github.com/phalcon/cphalcon/releases/tag/v3.4.4) (2019-06-30)
- Generated Dialect Class referring to a PHP class can't be found [#13867](https://github.com/phalcon/cphalcon/pull/13867)
- Changed default gcc's CFLAGS so that, the extension should be properly generated for most hosts, including Docker [#13143](https://github.com/phalcon/cphalcon/issues/13143)
- `Phalcon\Forms\Form::clear()` now correctly clears single fields. [#14217](https://github.com/phalcon/cphalcon/issues/14217)
- Used latest stable Zephir from 0.10.x branch to prevent segfaults with PHP 7.3.6 [#14160](https://github.com/phalcon/cphalcon/issues/14160)

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

# [3.3.2](https://github.com/phalcon/cphalcon/releases/tag/v3.3.2) (2018-03-04)
- Fixed `Phalcon\Db\Dialect\Mysql::modifyColumn` to produce valid SQL for renaming the column [#13012](https://github.com/phalcon/cphalcon/issues/13012)
- Fixed `Phalcon\Forms\Form::getMessages` to return back previous behaviour: return array of messages with element name as key [#13294](https://github.com/phalcon/cphalcon/issues/13294)
- Fixed `Phalcon\Mvc\Model\Behavior\SoftDelete::notify` to solve the exception that soft deletion renamed model [#13302](https://github.com/phalcon/cphalcon/issues/13302), [#13306](https://github.com/phalcon/cphalcon/issues/13306)
- Fixed `E_DEPRECATED` error for `each()` in `Phalcon\Debug\Dump` [#13253](https://github.com/phalcon/cphalcon/issues/13253)

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
- Added `Phalcon\Mvc\Query::setTransaction` to enable an override transaction [#13226](https://github.com/phalcon/cphalcon/issues/13226)

# [3.2.4](https://github.com/phalcon/cphalcon/releases/tag/v3.2.4) (2017-10-21)
- Fixed regression of [#13046](https://github.com/phalcon/cphalcon/issues/13046) by removing injection of dispatcher's parameters (which were never available anyway) [#13121](https://github.com/phalcon/cphalcon/issues/13121)
- Fixed `Phalcon\Mvc\Model\Query::_getQualified` to correct replace field names in `WHERE` [#12971](https://github.com/phalcon/cphalcon/issues/12971)

# [3.2.3](https://github.com/phalcon/cphalcon/releases/tag/v3.2.3) (2017-10-12)
- Fixed `Phalcon\Mvc\Model\Query::_executeSelect` threw RuntimeException, if db:beforeQuery() returned false
- Internal cookies property is now always an array [#12978](https://github.com/phalcon/cphalcon/issues/12978)
- Fixed `Phalcon\Validation\Validator\File::validate` to work properly with parameter 'message' [#12947](https://github.com/phalcon/cphalcon/issues/12947)
- Fixed `Phalcon\Mvc\View::render` to render a view with params [#13046](https://github.com/phalcon/cphalcon/issues/13046)
- Fixed `Phalcon\Mvc\Model\Manager::getRelationRecords` to work properly with provided columns [#12972](https://github.com/phalcon/cphalcon/issues/12972)
- Mark as deprecated no longer used `Phalcon\Mvc\Model\Query\Builder::$_with` parameter [#13023](https://github.com/phalcon/cphalcon/issues/13023)
- Fixed `Phalcon\Dispatcher::dispatch` to ensure proper flow for all forward/exception/dispatch event hooks [#12931](https://github.com/phalcon/cphalcon/issues/12931)

# [3.2.2](https://github.com/phalcon/cphalcon/releases/tag/v3.2.2) (2017-08-14)
- Fixed `Phalcon\Db\Adapter\Pdo\Postgresql::describeColumns` to work properly with `DOUBLE PRECISION` and `REAL` data types [#12842](https://github.com/phalcon/cphalcon/issues/12842)
- Fixed `Phalcon\Paginator\Adapter\QueryBuilder::getPaginate` to use the db connection service of the model [#12957](https://github.com/phalcon/cphalcon/issues/12957)
- Fixed `Phalcon\Paginator\Adapter\QueryBuilder::getPaginate` to escape reserverd words [#12950](https://github.com/phalcon/cphalcon/issues/12950)
- Fixed `Phalcon\Dispatcher::dispatch` to correct forward with the modified action suffix [#12988](https://github.com/phalcon/cphalcon/pull/12988)
- Fixed `Phalcon\Forms\Element::_construct` to prevent create form element with empty name [#12954](https://github.com/phalcon/cphalcon/pull/12954)

# [3.2.1](https://github.com/phalcon/cphalcon/releases/tag/v3.2.1) (2017-07-10)
- Added `Phalcon\Db\Dialect\Mysql::getForeignKeyChecks` to generate a SQL to check the foreign key settings [#2604](https://github.com/phalcon/cphalcon/issues/2604), [phalcon/phalcon-devtools#556](https://github.com/phalcon/phalcon-devtools/issues/556)
- Fixed inconsistent behaviour of `Phalcon\Config::merge` across minor version of PHP7 [#12779](https://github.com/phalcon/cphalcon/issues/12779)
- Fixed visibility of `Phalcon\Mvc\Model\Query\Builder` methods: `_conditionNotIn`, `_conditionIn`, `_conditionNotBetween` and `_conditionBetween` to allow 3rd party libraries extend it
- Fixed `Phalcon\Assets\Manager::output`, implemented missing resource type filtering for mixed resource collections [#2408](https://github.com/phalcon/cphalcon/issues/2408)
- Fixed `Phalcon\Http\Response::getStatusCode` to return (int) HTTP code only, instead of full string [#12895](https://github.com/phalcon/cphalcon/issues/12895)
- Fixed `Phalcon\Db\Dialect\Postgresql::addForeignKey` for proper creating the foreign key without a name
- Fixed `Phalcon\Cache\Backend\Apcu::flush` to use APCu instead APC [#12934](https://github.com/phalcon/cphalcon/issues/12934)
- Fixed `Phalcon\Db\Adapter\Pdo\Mysql::addForeignKey` for proper creating the foreign key with a desired key name [#2604](https://github.com/phalcon/cphalcon/issues/2604), [phalcon/phalcon-devtools#556](https://github.com/phalcon/phalcon-devtools/issues/556)
- Fixed `Phalcon\Db\Dialect\Mysql::addForeignKey` to generate correct SQL [#2604](https://github.com/phalcon/cphalcon/issues/2604), [phalcon/phalcon-devtools#556](https://github.com/phalcon/phalcon-devtools/issues/556)

# [3.2.0](https://github.com/phalcon/cphalcon/releases/tag/v3.2.0) (2017-06-19)
- Phalcon will now trigger `E_DEPREACATED` by using `Phalcon\Mvc\Model\Criteria::addWhere`, `Phalcon\Debug::getMajorVersion`, `Phalcon\Dispatcher::setModelBinding`, `Phalcon\Tag::resetInput`, `Phalcon\Mvc\Model\Validator::__construct`
- Added Factory Adapter loaders [#11001](https://github.com/phalcon/cphalcon/issues/11001)
- Added ability to sanitize URL to `Phalcon\Filter`
- Added missed `$type` argument to interface `Phalcon\Mvc\Model\Query\BuilderInterface::join()` to specify type join
- Added `Phalcon\Mvc\Model::hasUpdated` and `Phalcon\Mvc\Model:getUpdatedFields`, way to check if fields were updated after create/save/update
- Added support for having option in `Phalcon\Paginator\Adapter\QueryBuilder` [#12111](https://github.com/phalcon/cphalcon/issues/12111)
- Added `Phalcon\Config::path` to get a value using a dot separated path [#12221](https://github.com/phalcon/cphalcon/issues/12221)
- Added service provider interface to configure services by context [#12783](https://github.com/phalcon/cphalcon/pull/12783)
- Added the ability to load services from yaml (`Phalcon\Di::loadFromYaml`) and php array (`Phalcon\Di::loadFromPhp`) files, so we can keep the references cleanly separated from code [#12784](https://github.com/phalcon/cphalcon/pull/12784)
- Added `Phalcon\Cache\Backend\Apcu` to introduce pure support of APCu [#12098](https://github.com/phalcon/cphalcon/issues/12098), [#11934](https://github.com/phalcon/cphalcon/issues/11934)
- Added `Phalcon\Annotations\Adapter\Apcu` to introduce pure support of APCu [#12098](https://github.com/phalcon/cphalcon/issues/12098)
- Added option to disable snapshot update on create/save using `Phalcon\Mvc\Model::setup(['updateSnapshotOnSave' => false])` or `phalcon.orm.update_snapshot_on_save = 0` in `php.ini`
- Added `Phalcon\Mvc\Model\Manager::setModelPrefix` and `Phalcon\Mvc\Model\Manager::getModelPrefix` to introduce tables prefixes [#10328](https://github.com/phalcon/cphalcon/issues/10328)
- Added methods `Phalcon\Mvc\Model\Query\Builder::andHaving`, `Phalcon\Mvc\Model\Query\Builder::orHaving`, `Phalcon\Mvc\Model\Query\Builder::betweenHaving`, `Phalcon\Mvc\Model\Query\Builder::notBetweenHaving`, `Phalcon\Mvc\Model\Query\Builder::inHaving`, `Phalcon\Mvc\Model\Query\Builder::notInHaving`
- Added parameters `skip_on_insert`, `skip_on_update` and `allow_empty_string` and fixed a bug for renamed integer columns in `Phalcon\Mvc\Model\MetaData\Strategy\Annotations::getMetaData`
- Added way to disable setters in `Phalcon\Mvc\Model::assign` by using `Phalcon\Mvc\Model::setup` or ini option
- Added ability to sanitize special characters to `Phalcon\Filter`
- Added a new `Phalcon\Mvc\Model\Binder::findBoundModel` method. Params fetched from cache are being added to `internalCache`  class property in `Phalcon\Mvc\Model\Binder::getParamsFromCache`
- Added `Phalcon\Mvc\Model\Criteria::createBuilder` to create a query builder from criteria
- Added `dispatcher::beforeForward` event to allow forwarding request to the separated module [#121](https://github.com/phalcon/cphalcon/issues/121), [#12417](https://github.com/phalcon/cphalcon/issues/12417)
- Added `Phalcon\Security\Random:base62` to provide the largest value that can safely be used in URLs without needing to take extra characters into consideration [#12105](https://github.com/phalcon/cphalcon/issues/12105)
- Added `Phalcon\Assets\ResourceInterface`. So now `Phalcon\Assets\Inline` and `Phalcon\Assets\Resource` implements `ResourceInterface`
- Added `Phalcon\Assets\Collection::has` to checks whether the resource is added to the collection or not
- Added `Phalcon\Cli\Dispatcher::getOption`, `Phalcon\Cli\Dispatcher::hasOption` and the options as parameter to cli handlers
- Added `Phalcon\Config\Adapter\Grouped` to allow usage of multiple configuration files/adapters in a simple format [#12884](https://github.com/phalcon/cphalcon/pull/12884)
- Added `DISTINCT` type for `Phalcon\Text::random`
- Added autopadding feature for `Phalcon\Crypt::encryptBase64` and `Phalcon\Crypt::decryptBase64` [#12490](https://github.com/phalcon/cphalcon/issues/12490)
- Fixed Dispatcher forwarding when handling exception [#11819](https://github.com/phalcon/cphalcon/issues/11819), [#12154](https://github.com/phalcon/cphalcon/issues/12154)
- Fixed params view scope for PHP 7 [#12648](https://github.com/phalcon/cphalcon/issues/12648)
- Fixed `Phalcon\Mvc\Micro::handle` to prevent attemps to send response twice [#12668](https://github.com/phalcon/cphalcon/pull/12668)
- Fixed `Di::set`, `Di::setShared` to allow pass more than 10 arguments [#12299](https://github.com/phalcon/cphalcon/issues/12299)
- Fixed `Phalcon\Mvc\Model\MetaData\Strategy\Annotations::getColumnMaps` where only renamed columns where returned if there was one
- Fixed `Phalcon\Mvc\Micro:handle` to correctly handle `before` handlers [#10931](https://github.com/phalcon/cphalcon/pull/10931)
- Fixed `Phalcon\Mvc\Micro:handle` to correctly handle `afterBinding` handlers
- Fixed `Phalcon\Mvc\Model::hasChanged` to correctly use it with arrays [#12669](https://github.com/phalcon/cphalcon/issues/12669)
- Fixed `Phalcon\Mvc\Model\Resultset::delete` to return result depending on success [#11133](https://github.com/phalcon/cphalcon/issues/11133)
- Fixed `Phalcon\Session\Adapter::destroy` to  correctly clear the `$_SESSION` superglobal [#12326](https://github.com/phalcon/cphalcon/pull/12326), [#12835](https://github.com/phalcon/cphalcon/pull/12835)
- Fixed `Phalcon\Assets\Collection:add` to avoid duplication of resources [#10938](https://github.com/phalcon/cphalcon/issues/10938), [#2008](https://github.com/phalcon/cphalcon/issues/2008)
- Fixed `Phalcon\Mvc\View\Engine\Volt::compile` to not throw exception in case of absence the file and `stat` option is true [#12849](https://github.com/phalcon/cphalcon/pull/12849)
- Fixed `Phalcon\Mvc\Collection::getReservedAttributes` to workaround for PHP 7/7.1 bug with static null when extending class [phalcon/incubator#762](https://github.com/phalcon/incubator/issues/762), [phalcon/incubator#760](https://github.com/phalcon/incubator/issues/760)
- Fixed `Phalcon\Cache\Backend\Redis::__construct` and `Phalcon\Cache\Backend\Redis::_connect` to correctly handle the Redis auth option [#12736](https://github.com/phalcon/cphalcon/issues/12736)
- Fixed `Phalcon\Mvc\Collection::getReservedAttributes`, added missing properties to reserved attributes [phalcon/incubator#762](https://github.com/phalcon/incubator/issues/762), [phalcon/incubator#760](https://github.com/phalcon/incubator/issues/760)
- Fixed `Phalcon\Mvc\Router\Annotation::processActionAnnotation` to support PATCH request

# [3.1.2](https://github.com/phalcon/cphalcon/releases/tag/v3.1.2) (2017-XX-XX)
- Fixed PHP 7.1 issues [#12055](https://github.com/phalcon/cphalcon/issues/12055)
- Fixed `Imagick::getVersion()` error in some system [#12729](https://github.com/phalcon/cphalcon/issues/12729)
- Fixed `Phalcon\Mvc\Model::_doLowInsert` to properly set snapshot when having default values and public properties [#12766](https://github.com/phalcon/cphalcon/issues/12766)

# [3.1.1](https://github.com/phalcon/cphalcon/releases/tag/v3.1.1) (2017-XX-XX)
- Fixed undefined index warning on existing cached resultsets
- Fixed `Phalcon\Mvc\Model::_dowLowUpdate` warning first argument is not an array [#12742](https://github.com/phalcon/cphalcon/issues/12742)

# [3.1.0](https://github.com/phalcon/cphalcon/releases/tag/v3.1.0) (2016-XX-XX)
- Added `Phalcon\Validation\Validator\Callback`, `Phalcon\Validation::getData`
- Added the ability to truncate database tables
- Added `Phalcon\Mvc\Model\Binder`, class used for binding models to parameters in dispatcher, micro, added `Phalcon\Dispatcher::getBoundModels` and `Phalcon\Mvc\Micro::getBoundModels` to getting bound models, added `Phalcon\Mvc\Micro\Collection\LazyLoader::callMethod`
- Added afterBinding event to `Phalcon\Dispatcher` and `Phalcon\Mvc\Micro`, added `Phalcon\Mvc\Micro::afterBinding`
- Added the ability to set custom Resultset class returned by find() [#12166](https://github.com/phalcon/cphalcon/issues/12166)
- Added the ability to clear appended and prepended title elements (Phalcon\Tag::appendTitle, Phalcon\Tag::prependTitle). Now you can use array to add multiple titles. For more details check [#12238](https://github.com/phalcon/cphalcon/issues/12238).
- Added the ability to specify what empty means in the 'allowEmpty' option of the validators. Now it accepts as well an array specifying what's empty, for example ['', false]
- Added the ability to use `Phalcon\Validation` with `Phalcon\Mvc\Collection`, deprecated `Phalcon\Mvc\Collection::validationHasFailed`
- Fixes internal cache saving in `Phalcon\Mvc\Model\Binder` when no cache backend is used
- Added `Phalcon\Acl\Adapter\Memory::getActiveKey`, `Phalcon\Acl\Adapter\Memory::activeFunctionCustomArgumentsCount` and `Phalcon\Acl\Adapter\Memory::getActiveFunction` to get latest key, number of custom arguments, and function used to acquire access
- Added `Phalcon\Firewall` component

# [3.0.4](https://github.com/phalcon/cphalcon/releases/tag/v3.0.4) (XXXX-XX-XX)
- Fixed Isnull check is not correct when the model field defaults to an empty string. [#12507](https://github.com/phalcon/cphalcon/issues/12507)

# [3.0.3](https://github.com/phalcon/cphalcon/releases/tag/v3.0.3) (2016-12-24)
- Fixed implementation of Iterator interface in a `Phalcon\Forms\Form` that could cause a run-time warning
- Fixed `Phalcon\Cache\Backend\Redis::get`, `Phalcon\Cache\Frontend\Data::afterRetrieve` to allow get empty strings from the Redis database [#12437](https://github.com/phalcon/cphalcon/issues/12437)
- Fixed `Phalcon\Cache\Backend\Redis::exists` to correct check if cache key exists for empty value in the Redis database [#12434](https://github.com/phalcon/cphalcon/pull/12434)
- Fixed `Phalcon\Security::checkToken` to prevent possible timing attack [#12418](https://github.com/phalcon/cphalcon/issues/12418)
- Fixed `Phalcon\Mvc\Model\Resultset\Simple` to save snapshot when caching
- Fixed `Phalcon\Http\Request::getHeaders` to handle auth headers correctly [#12480](https://github.com/phalcon/cphalcon/issues/12480)
- Fixed `Phalcon\Http\Request::getMethod` to handle `X-HTTP-Method-Override` header correctly [#12478](https://github.com/phalcon/cphalcon/issues/12478)
- Fixed `Phalcon\Mvc\Model\Criteria::limit` and `Phalcon\Mvc\Model\Query\Builder::limit` to work with `limit` and `offset` properly [#12419](https://github.com/phalcon/cphalcon/issues/12419)
- Fixed `Phalcon\Forms\Form` to correct form validation and set messages for elements [#12465](https://github.com/phalcon/cphalcon/issues/12465), [#11500](https://github.com/phalcon/cphalcon/issues/11500), [#11135](https://github.com/phalcon/cphalcon/issues/11135), [#3167](https://github.com/phalcon/cphalcon/issues/3167), [#12395](https://github.com/phalcon/cphalcon/issues/12395)
- Fixed `Phalcon\Cache\Backend\Libmemcached::queryKeys` to correct query the existing cached keys [#11024](https://github.com/phalcon/cphalcon/issues/11024)
- Fixed building extension for ImageMagick 7 [mkoppanen/imagick#180](https://github.com/mkoppanen/imagick/issues/180)
- Fixed `Phalcon\Cache\Backend\Redis::save` to allow save data termlessly [#12327](https://github.com/phalcon/cphalcon/issues/12327)

# [3.0.2](https://github.com/phalcon/cphalcon/releases/tag/v3.0.2) (2016-11-26)
- Fixed saving snapshot data while caching model [#12170](https://github.com/phalcon/cphalcon/issues/12170), [#12000](https://github.com/phalcon/cphalcon/issues/12000)
- Fixed `Phalcon\Http\Response\Headers::send` to send correct status header [#12179](https://github.com/phalcon/cphalcon/issues/12179)
- Fixed `Phalcon\Mvc\Model::setSnapshotData`, `Phalcon\Mvc\Model\Resultset\Simple::toArray` by fixing an issue like `fetch a, a[key]` using Zephir [#11205](https://github.com/phalcon/cphalcon/issues/11205), [#12147](https://github.com/phalcon/cphalcon/issues/12147)
- Fixed `Phalcon\Cache\Backend\Memcache::flush` to remove all query keys after flush memcached [#12182](https://github.com/phalcon/cphalcon/issues/12182)
- Fixed `Phalcon\Cache\Backend\Memory::delete` to correct remove items from  `Phalcon\Cache\Backend\Memory::$_data`
- Fixed `Phalcon\Cache\Frontend\Data::afterRetrieve`, `Phalcon\Cache\Frontend\Igbinary::afterRetrieve`, `Phalcon\Cache\Frontend\Msgpack::afterRetrieve` to unserialize only raw data [#12186](https://github.com/phalcon/cphalcon/issues/12186)
- Fixed `Phalcon\Mvc\Model::cloneResultMapHydrate` to correct create array/objects from data by column map with types [#12191](https://github.com/phalcon/cphalcon/issues/12191)
- Fixed `Phalcon\Validation\Validator\Confirmation::validate` to use `fieldWith` instead of `field` when looking up the value for labelWith.
- Fixed `Phalcon\Cache\Backend\Redis::_connect` to use `select` redis internal function only when the `index` is greater than zero.
- Fixed `Phalcon\Config\Adapter\Ini::_cast` to allow create extended config adapters [#12230](https://github.com/phalcon/cphalcon/issues/12230).
- Fixed `Phalcon\Tag::appendTitle`, `Phalcon\Tag::prependTitle` to stack title prepending and appending [#12233](https://github.com/phalcon/cphalcon/issues/12233).
- Fixed `Phalcon\Debug::getVersion` to provide valid link to the latest Phalcon major version [#12215](https://github.com/phalcon/cphalcon/issues/12215)
- Fixed `Phalcon\Session\Adapter\Libmemcached::read`, `Phalcon\Session\Adapter\Libmemcached::destroy`, `Phalcon\Session\Adapter\Memcache::read`, `Phalcon\Session\Adapter\Memcache::destroy`, `Phalcon\Session\Adapter\Redis::read` and `Phalcon\Session\Adapter\Redis::destroy` in accordance with the `session_set_save_handler` API [#12206](https://github.com/phalcon/cphalcon/pull/12206)
- Fixed `Phalcon\Validation::getValue()` to use filters when having entity
- Fixed `Phalcon\Db\Dialect\Mysql::describeReferences()` and `Phalcon\Db\Dialect\Postgresql::describeReferences()` to return proper sql
- Fixed `Phalcon\Db\Column::hasDefault` to return `false` for autoincrement columns [phalcon/phalcon-devtools#853](https://github.com/phalcon/phalcon-devtools/issues/853)
- Fixed `Phalcon\Db\Dialect\Postgresql::createTable`, `Phalcon\Db\Dialect\Postgresql::addColumn`, `Phalcon\Db\Dialect\Postgresql::modifyColumn` to correct escape default values [#12267](https://github.com/phalcon/cphalcon/issues/12267), [phalcon/phalcon-devtools#859](https://github.com/phalcon/phalcon-devtools/issues/859)
- Fixed `Phalcon\Forms\Form::bind` to clean form elements [#11978](https://github.com/phalcon/cphalcon/issues/11978), [#12165](https://github.com/phalcon/cphalcon/issues/12165), [#12099](https://github.com/phalcon/cphalcon/issues/12099), [#10044](https://github.com/phalcon/cphalcon/issues/10044)
- Fixed `Phalcon\Tag::resetInput` for proper use without attempts to clear `$_POST` [#12099](https://github.com/phalcon/cphalcon/issues/12099)
- Fixed `Phalcon\Db\Dialect\Mysql` and `Phalcon\Db\Dialect\Postresql` to correctly check schema in missing methods
- Fixed `Phalcon\Cache\Backend\Apc::flush` to remove only it's own keys by prefix [#12153](https://github.com/phalcon/cphalcon/issues/12153)
- Fixed `Phalcon\Acl\Adapter\Memory::isAllowed` to call closures when using wildcard [#12333](https://github.com/phalcon/cphalcon/issues/12333)
- Fixed `Phalcon\Validation\Validator\File` array to string conversion in `minResolution` and `maxResolution` [#12349](https://github.com/phalcon/cphalcon/issues/12349)
- Fixed `Phalcon\Cache\Backend\File::queryKeys()` to compare the filename against parsed prefix
- Database identifiers are now properly escaped [#12410](https://github.com/phalcon/cphalcon/issues/12410)

# [3.0.1](https://github.com/phalcon/cphalcon/releases/tag/v3.0.1) (2016-08-24)
- Fixed `Phalcon\Cache\Backend\Redis::flush` in order to flush cache correctly
- Fixed `Phalcon\Mvc\Model\Manager::getRelationRecords` to correct using multi relation column [#12035](https://github.com/phalcon/cphalcon/issues/12035)
- Fixed `Phalcon\Acl\Resource`. Now it implements `Phalcon\Acl\ResourceInterface` [#11959](https://github.com/phalcon/cphalcon/issues/11959)
- Fixed `save` method for all cache backends. Now it updates the `_lastKey` property correctly [#12050](https://github.com/phalcon/cphalcon/issues/12050)
- Fixed virtual foreign key check when having multiple keys [#12071](https://github.com/phalcon/cphalcon/issues/12071)
- `Phalcon\Config\Adapter\Ini` constructor can now specify `parse_ini_file()` scanner mode [#12079](https://github.com/phalcon/cphalcon/pull/12079)
- Fixed `Phalcon\Cache\Backend\Apc::save` due to which the `Apc::increment`/`Apc::decrement` could not be used properly [#12109](https://github.com/phalcon/cphalcon/issues/12109)
- Fixed `Phalcon\Mvc\Model\Criteria::inWhere` so that now the second parameter can be an empty array [#10676](https://github.com/phalcon/cphalcon/issues/10676)
- Fixed ORM related memory leak [#12115](https://github.com/phalcon/cphalcon/issues/12115), [#11995](https://github.com/phalcon/cphalcon/issues/11995), [#12116](https://github.com/phalcon/cphalcon/issues/12116)
- Fixed incorrect `Phalcon\Mvc\View::getActiveRenderPath` behavior [#12139](https://github.com/phalcon/cphalcon/issues/12139)
- Fixed `Phalcon\Security\Random::base64Safe` so that now the method returns correct safe string [#12141](https://github.com/phalcon/cphalcon/issues/12141)
- Fixed the `Phalcon\Translate\Adapter\Gettext::getOptionsDefault` visibility [#12157](https://github.com/phalcon/cphalcon/issues/12157)
- Enabled PHQL cache for PHP7 to improve performance and reuse plannings

# [3.0.0](https://github.com/phalcon/cphalcon/releases/tag/v3.0.0) (2016-07-29)
- PHP 5.3 and 5.4 are now fully deprecated
- `Phalcon\Mvc\Model\Validation` is now deprecated in favor of `Phalcon\Validation`
- Changed default hash algorithm in `Phalcon\Security` to `CRYPT_BLOWFISH_Y`
- Changed constructor of `Phalcon\Mvc\Model` to allow pass an array of initialization data
- Removed support for prefixes strategy in `Phalcon\Loader`
- Now `Phalcon\Mvc\View` supports many views directories at the same time
- An absolute path can now be used to `Mvc\View::setLayoutsDir`
- Fixed odd view behavior[#1933](https://github.com/phalcon/cphalcon/issues/1933) related to setLayout() and pick()
- `Phalcon\Di` is now bound to services closures allowing use `Phalcon\Di` as $this to access services within them
- If an object is returned after firing the event `beforeServiceResolve` in `Phalcon\Di` this overrides the
  default service localization process
- Placeholders `:controller` and `:action` in `Mvc\Router` now defaults to `/([\\w0-9\\_\\-]+)` instead of `/([\\a-zA-Z0-9\\_\\-]+)`
- Modifier `#u` (PCRE_UTF8) is now default in regex based routes in `Mvc\Router`
- Return 'false' from an action disables the view component (same as `$this->view->disable()`)
- Return a string from an action takes it as the body of the response (same as return `$this->response->setContent('Hello world')`)
- Return a string from an `Mvc\Micro` handler takes it as the body of the response
- `Mvc\Router\Route` now escapes characters such as . or + to avoid unexpected behaviors
- Closures used as handlers in` Mvc\Micro` are now bound to the $app instance
- Routes now can have an associated callback that can override the default dispatcher + view behavior
- `Phalcon\Mvc\Model` now implements `JsonSerializable` making easy serialize model instances
- When destructing a `Mvc\Model\Manager` PHQL cache is clean
- Method `isSetOption` in `Phalcon\Validation\ValidatorInterface` marked as deprecated, please use `hasOption`
- Added internal check "allowEmpty" before calling a validator. If it option is true and the value of empty, the validator is skipped
- Added default header: `Content-Type: "application/json; charset=UTF-8"` in method `Phalcon\Http\Response::setJsonContent`
- Now `Phalcon\Events\Event` implements `Phalcon\Events\EventInterface`
- `Phalcon\Events\Event::getCancelable` renamed to `Phalcon\Events\Event::isCancelable`
- Removed `Phalcon\Events\Manager::dettachAll` in favor of `Phalcon\Events\Manager::detachAll`
- `Phalcon\Mvc\Model\Criteria::getOrder` renamed to `Phalcon\Mvc\Model\Criteria::getOrderBy`
- Added method `getOption()` in `Phalcon\Mvc\Model\RelationInterface`
- Added ability to spoof HTTP request method
- Added FULLTEXT index type to `Phalcon\Db\Adapter\Pdo\Mysql`
- Fixed the use of the annotation router with namespaced controllers
- Added `Phalcon\Acl\RoleAware` and `Phalcon\Acl\ResourceAware` Interfaces, Now you can pass objects to `Phalcon\Acl\AdapterInterface::isAllowed` as `roleName` and `resourceName`, also they will be automatically passed to function defined in `Phalcon\Acl\AdapterInterface::allow` or `Phalcon\Acl\AdapterInterface::deny` by type
- `Phalcon\Acl\AdapterInterface::allow` and `Phalcon\Acl\AdapterInterface::deny` have 4th argument - function, which will be called when using `Phalcon\Acl\AdapterInterface::isAllowed`
- `Phalcon\Acl\AdapterInterface::isAllowed` have 4th argument - parameters, you can pass arguments for function defined in `Phalcon\Acl\AdapterInterface:allow` or `Phalcon\Acl\AdapterInterface::deny` as associative array where key is argument name
- Added method `getActionSuffix()` in `Phalcon\DispatcherInterface`
- CLI parameters are now handled consistently.
- Added `Phalcon\Mvc\Controller\BindModelInterface` and associated model type hint loading through dispatcher.
- Added `Phalcon\Dispatcher::hasParam()`.
- `Phalcon\Cli\Console` and `Phalcon\Mvc\Application` now inherit `Phalcon\Application`.
- Fixed `afterFetch` event not being sent to behaviors
- Fixed issue with radio not being checked when default value is 0 [#11358](https://github.com/phalcon/cphalcon/issues/11358)
- Fixed issue with `Model::__set` that was bypassing setters [#11286](https://github.com/phalcon/cphalcon/issues/11286)
- Fixed issue with `Model::__set` that was setting hidden attributes directly when setters are not declared [#11286](https://github.com/phalcon/cphalcon/issues/11286)
- Added `Phalcon\Cli\DispatcherInterface`, `Phalcon\Cli\TaskInterface`, `Phalcon\Cli\RouterInterface` and `Phalcon\Cli\Router\RouteInterface`.
- Added `Phalcon\Mvc\Collection::update`, `Phalcon\Mvc\Collection::create` and `Phalcon\Mvc\Collection::createIfNotExist`
- Removed `__construct` from all interfaces [#11410](https://github.com/phalcon/cphalcon/issues/11410)
- Fires the `dispatch:beforeException` event when there is any exception during dispatching [#11458](https://github.com/phalcon/cphalcon/issues/11458)
- Added `OR` operator for `Phalcon\Mvc\Model\Query\Builder` methods: `betweenWhere`, `notBetweenWhere`, `inWhere` and `notInWhere`
- Fixed bug of `destroy` method of `Phalcon\Session\Adapter\Libmemcached`
- Added `Phalcon\Cache\Backend\Memcache::addServers` to enable pool of servers for memcache
- Added `setLastModified` method to `Phalcon\Http\Response`
- Added `Phalcon\Validation\Validator\Date`
- Added `\Phalcon\Queue\Beanstalk::ignore()` It removes the named tube from the watch list for the current connection.
- Added `\Phalcon\Queue\Beanstalk::pauseTube()` Can delay any new job being reserved for a given time.
- Added `\Phalcon\Queue\Beanstalk::kick()` It moves jobs into the ready queue. If there are any buried jobs, it will only kick buried jobs. Otherwise it will kick delayed jobs.
- Added `\Phalcon\Queue\Beanstalk::listTubeUsed()` Returns the tube currently being used by the client.
- Added `\Phalcon\Queue\Beanstalk::listTubesWatched()` Returns a list tubes currently being watched by the client.
- Added `\Phalcon\Queue\Beanstalk::peekDelayed()` Return the delayed job with the shortest delay left.
- Added `\Phalcon\Queue\Beanstalk::jobPeek()` Return job.
- Mcrypt is replaced with openssl in `Phalcon\Crypt`
- Default encrypt algorithm in `Phalcon\Crypt` is now changed to `AES-256-CFB`
- Removed methods setMode(), getMode(), getAvailableModes() in `Phalcon\CryptInterface`
- Added `Phalcon\Assets\Manager::exists()` to check if collection exists
- `Phalcon\Mvc\Model\Manager::load()` now can load models from aliased namespaces
- `Phalcon\Mvc\Model\Transaction\Manager` now correctly keeps account of transactions [#11554](https://github.com/phalcon/cphalcon/issues/11554)
- `Phalcon\Db\Dialect\Sqlite` now maps additional column types to SQLite columns equivalents.
- `Phalcon\Security` is using now `Phalcon\Security\Random`
- Enforced that `Phalcon\Security::getToken()` and `Phalcon\Security::getTokenKey()` return a random value per request not per call
- `Phalcon\Security::getToken()` and `Phalcon\Security::getTokenKey()` are using now `Phalcon\Security::_numberBytes` instead of passed as a argument or hardcoded value
- `Phalcon\Security::hash()` corrected not working CRYPT_STD_DES, CRYPT_EXT_DES, MD5, CRYPT_SHA256
- `Phalcon\Security::hash()` CRYPT_SHA512 fixed wrong salt length
- Added missing unit-tests for `Phalcon\Security`
- Fixed `Filter::add` method handler [#11581](https://github.com/phalcon/cphalcon/issues/11581)
- Removed `Phalcon\Session` [#11340](https://github.com/phalcon/cphalcon/issues/11340)
- Phalcon\Tag::getTitle() shows a title depending on prependTitle and appendTitle
- Using a settable variable for the Mongo Connection Service name instead of a hard coded string [#11725](https://github.com/phalcon/cphalcon/issues/11725)
- Added new getter `Phalcon\Mvc\Model\Query\Builder::getJoins()` - to get join parts from query builder
- Fixed `Phalcon\Db\Dialect\Oracle::prepareTable()` to correctly generate SQL for table aliases [#11799](https://github.com/phalcon/cphalcon/issues/11799)
- Fixed `Phalcon\Mvc\Model\Resultset::update()` - removed endless loop queries
- The cache backend adapters now returns boolean on call `Phalcon\Cache\BackendInterface::save`
- Fixed the Session write callback [#11733](https://github.com/phalcon/cphalcon/issues/11733)
- Added '\Phalcon\Loader::registerFiles' & '\Phalcon\Loader::getFiles'. This allows you to add files to the autoloader
- Added `Phalcon\Security::hasLibreSsl` and `Phalcon\Security::getSslVersionNumber`
- Added new setter `Phalcon\Escaper::setDoubleEncode()` - to allow setting/disabling double encoding
- Added  `Phalcon\Cache\Frontend\Msgpack` - Added Msgpack Support for Frontend Cache
- `Phalcon\Debug\Dump` skip debugging di, fix detecting private/protected properties
- Added option to validate multiple fields with one validator(fix uniqueness validator as well), also removes unnecessary `model => $this` in `Phalcon\Validation\Validator\Uniqueness`.
- `Phalcon\Validation\Validator\Alpha` now correctly validates non-ASCII characters [#11386](https://github.com/phalcon/cphalcon/issues/11386)
- `Phalcon\Validation\Validator\Digit` now correctly validates digits [#11374](https://github.com/phalcon/cphalcon/issues/11374)
- Added `Phalcon\Validation\CombinedFieldsValidator`, validation will pass array of fields to this validator if needed
- Added ability to autoescape Flash messages [#11448](https://github.com/phalcon/cphalcon/issues/11448)
- Fixed `Phalcon\Config::merge` for working with php7
- Added ability to use custom delimiter for `Phalcon\Text::camelize` and `Phalcon\Text::uncamelize` [#10396](https://github.com/phalcon/cphalcon/issues/10396)
- Added support of `CONNECT`, `TRACE` and `PURGE`  HTTP methods
- Refactored `Phalcon\Http\Request::getHttpHost`. Now it always return host name or empty string. Optionally validates and clean host name [#2573](https://github.com/phalcon/cphalcon/issues/2573)
- Added `Phalcon\Http\Request::getPort`. To get information about the port on which the request is made.
- Added `Phalcon\Http\Request::setStrictHostCheck` and `Phalcon\Http\Request::isStrictHostCheck` to manage strict validation of host name.
- Fixed matching host name by `Phalcon\Mvc\Route::handle` when using port on current host name [#2573](https://github.com/phalcon/cphalcon/issues/2573)
- Fixed `Phalcon\Text:dynamic()` to allow custom separator [#11215](https://github.com/phalcon/cphalcon/issues/11215)
- Fixed `Phalcon\Validation::appendMessage` to allow append message to the empty stack [#10405](https://github.com/phalcon/cphalcon/issues/10405)
- Fixed `Phalcon\Session\Flash::getMessages`. Now it returns an empty array in case of non existent message type request [#11941](https://github.com/phalcon/cphalcon/issues/11941)
- Amended `Phalcon\Mvc\RouterInterface` and `Phalcon\Mvc\Router`. Added missed `addPurge`, `addTrace` and `addConnect` methods
- Fixed incorrect query when using NULL fields with `Phalcon\Validation\Validator\Uniqueness`
- Fixed `Phalcon\Forms\Form::getValue`. Now Elements can have names that match with the internal Form getters [#10398](https://github.com/phalcon/cphalcon/issues/10398)
- Add `setContentLength()` method to `Phalcon\Http\Response`
- Fixed `Phalcon\Mvc\Model\Manager::_mergeFindParameters` - Merging conditions [#11987](https://github.com/phalcon/cphalcon/issues/11987)
- Renamed `Phalcon\Http\Request::isSoapRequest` to `Phalcon\Http\Request::isSoap` and `Phalcon\Http\Request::isSecureRequest` to `Phalcon\Http\Request::isSecure`. Left the originals functions as aliases and marked them deprecated.
- Fixed wildcard inheritance in `Phalcon\Acl\Adapter\Memory` [#12004](https://github.com/phalcon/cphalcon/issues/12004)
- Dropped support of Oracle [#12008](https://github.com/phalcon/cphalcon/issues/12008)
- Improved `Phalcon\Mvc\Collection::findById`. Added check if a `id` in a valid format [#12010](https://github.com/phalcon/cphalcon/issues/12010)
- Added `convert` option to `Phalcon\Validation\Validator\Uniqueness` to convert values to do the database lookup [#12005](https://github.com/phalcon/cphalcon/issues/12005)

# [2.0.13](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.13) (2016-05-19)
- Restored `Phalcon\Text::camelize` behavior [#11767](https://github.com/phalcon/cphalcon/issues/11767)
- Used Zephir v0.9.2

# [2.0.12](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.12) (2016-05-16)
- Fixed regression changes for `Phalcon\Mvc\View\Engine\Volt::callMacro` [#11745](https://github.com/phalcon/cphalcon/issues/11745)
- Fixed the argument type of `Phalcon\Flash::success` [#11764](https://github.com/phalcon/cphalcon/pull/11764)
- Restored Phalcon\Text::camelize behavior [#11767](https://github.com/phalcon/cphalcon/issues/11767)

# [2.0.11](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.11) (2016-05-04)
- Fix Model magic set functionality to maintain variable visibility and utilize setter methods.[#11286](https://github.com/phalcon/cphalcon/issues/11286)
- Added a `prepareSave` event to model saving
- Added support for OnUpdate and OnDelete foreign key events to the MySQL adapter
- Added ability to setLogLevel on multiple logs [#10429](https://github.com/phalcon/cphalcon/pull/10429)
- Fixed regression changes for `Phalcon\Translate\Adapter\Gettext::prepareOptions` [#11429](https://github.com/phalcon/cphalcon/issues/11429)
- Fixed `Phalcon\Mvc\View\Engine\Volt::callMacro` bug. Now it's correctly calling `call_user_func_array` instead of `call_user_func`
- Fixed undefined method call `Phalcon\Mvc\Collection\Manager::getConnectionService`. Now `Phalcon\Mvc\Collection::getConnectionService` works correctly in according to documentation

# [2.0.10](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.10) (2016-02-04)
- ORM: Added support for DATE columns in Oracle
- Fixed wrong `total_items` and `total_pages` in `Paginator` when the query builder has set `groupBy()`
- Fixed `Phalcon\Acl\Memory::allow` bug[#11210](https://github.com/phalcon/cphalcon/issues/11210) related to the inconsistent behavior with access specified as string and array
- Added quoting column in `Phalcon\Db\Dialect\MySQL::addColumn` when define position of the column
- Added support to define position of the column in `Phalcon\Db\Dialect\MySQL::modifyColumn`
- Fixed `Phalcon\Mvc\Model\Query\Builder` bug[#11298](https://github.com/phalcon/cphalcon/issues/11298) related to resetting limit to null
- Fixed `Phalcon\Tag::getTitle` bug[#11185](https://github.com/phalcon/cphalcon/issues/11185). Now a title will be automatically escaped.
- Fixed `Phalcon\Translate\Adapter\Gettext::exists` bug[#11310](https://github.com/phalcon/cphalcon/issues/11310) related to the wrong returned value (always true)
- Fixed `Phalcon\Translate\Adapter\Gettext::setLocale` bug[#11311](https://github.com/phalcon/cphalcon/issues/11311) related to the incorrect setting locale
- Added ability to persistent connection in `Phalcon\Queue\Beanstalk::connect`
- Fixed `Phalcon\Http\Response::redirect` bug[#11324](https://github.com/phalcon/cphalcon/issues/11324). Incorrect initialization local array of status codes
- Fixed cache backends bug[#11322](https://github.com/phalcon/cphalcon/issues/11322) related to saving number 0
- Fixed `Phalcon\Db\Dialect::escape` bug[#11359](https://github.com/phalcon/cphalcon/issues/11359). Added ability to use the database name with dots.

# [2.0.9](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.9) (2015-11-24)
- Fixed bug that double serializes data using Redis adapter
- Added `console:boot` event to allow the developer to perform initialization actions
- Added implementation options `allowEmpty` for `Phalcon\Mvc\Model\Validator\Ip`
- Fixed SQLite bug[#10997](https://github.com/phalcon/cphalcon/issues/10997) related to setting of index type
- Added `Phalcon\Db\Dialect\Sqlite::listIndexesSql` - to generate the SQL to get query list of indexes
- Fixed MySQL bug[#11036](https://github.com/phalcon/cphalcon/issues/11036) related to setting of index type
- Added missed `RouteInterface::setHostname`, `RouteInterface::getHostname`
- Added `strict` option for ExclusionIn validator
- Added `Phalcon\Text::underscore` - to make a phrase underscored instead of spaced
- Added `Phalcon\Text::humanize` - to make an underscored or dashed phrase human-readable
- Added ability to change document class to be returned in ODM through `class` option

# [2.0.8](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.8) (2015-09-19)
- Added `Phalcon\Security\Random::base58` - to generate a random base58 string
- Added `Phalcon\Logger\Adapter::isTransaction()` to check whether the logger is currently in transaction
  mode or not (Phalcon 1.3 behavior)
- `Phalcon\Session\Adapter` now closes the session when the adapter is destroyed (Phalcon 1.3 behavior)
- Fixed fetching of data in modes FETCH_CLASS, FETCH_INTO and FETCH_FUNC in `Phalcon\Db`
- Added missing code property in `Phalcon\Validation\Message` available in Phalcon 1.3.x
- Added `Phalcon\Db\Column::TYPE_TIMESTAMP` to allow migrations on these kind of columns
- Added `Phalcon\Db\ColumnInterface::hasDefault` to check if a column has a default value declared in its database
  column definition
- Fixed determining of default value for column in `Phalcon\Db\Dialect\MySQL`, `Phalcon\Db\Dialect\Sqlite` and
  `Phalcon\Db\Dialect\Postgresql` classes
- Now `Phalcon\Mvc\Model::__call` invokes finders as in `__callStatic`
- Fixed `Phalcon\Db\Dialect\Postgresql::getColumnDefinition` for `BIGINT` and `BOOLEAN` data types
- Fixed `BOOLEAN` default value in `Phalcon\Db\Dialect\Postgresql`
- Added `Phalcon\Validation\Validator\CreditCard` - validation credit card number using luhn algorithm

# [2.0.7](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.7) (2015-08-17)
- `Image\Adapter\Gd::save()` no longer fails if the method or the instance is created with a filename without an extension
- Fixed segfault in `Image\Adapter\Imagick::text()`
- Exceptions thrown in Volt compiler are now `Phalcon\Mvc\View\Engine\Exception`
- Now you can import macros from other files using `{% include "file.volt" %}`
- Undefined function calls fall back to macro calls in Volt
- Automatic bound parameters in `Mvc\Model\Criteria` now uses a different prefix
than `Mvc\Model\Query\Builder` to avoid collisions
- Added `Cache\Multiple::flush()` to flush the cache backends added to the multiple system
- Fixed `Session\Bag::remove()`
- `Session\Bag::destroy()` eliminates any temporary data in the variables bag
- `afterCreate`/`afterUpdate` are only called if saving related records was successful
- Added an optional parameter removeData to `Session\Adapter::remove()` to remove any data in `$_SESSION` that
belongs to the uniqueId or the whole session data
- Now session variables making use of unique prefixes use `#` as internal separator
- Added parameter the changing operator for conditions in method `Mvc\Model\Criteria::fromImput()` [#10749](https://github.com/phalcon/cphalcon/issues/10749)
- Added `\Phalcon\Queue\Beanstalk::listTubes()` to get list of a tubes
- Added a fix to avoid that a table present in many sub-queries causes invalid SQL generation
- Add `CookieInterface`, update `Cookie` and `Cookies` to use this interface - Decoupling `Cookies` and `Cookie` - Check `Session` state before using it in `Cookie`. [#10789](https://github.com/phalcon/cphalcon/issues/10789)
- Fixed merge of `Phalcon\Config` instances containing objects different than `Phalcon\Config` compatible instances
- When creating tables in Postgres, inline PRIMARY keys are now escaped properly[#10797](https://github.com/phalcon/cphalcon/pull/10797)
- Fixed incorrect generation of `SELECT COUNT(\*)` causing unexpected exceptions when `phqlLiterals` is disabled
- Added `Phalcon\Security\Random` - secure random number generator class. Provides secure random number generator which is suitable for generating session key in HTTP cookies, etc

# [2.0.6](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.6) (2015-07-21)
- Builds in TravisCI now uses Docker to perform faster builds
- Added `Http\Response::setCache()` to easily set cache headers.
- When a beanstalkd connection is closed the adapter does not produce a notice anymore
- Default separator in `Text::increment` is now _ (underscore)
- Using `tel_field` in Volt now generates correct PHP code
- SQL generated by PostgreSQL dialect in dropTable and dropView is now correct
- Errors generated in `Cache\Backend\Memcached` now shows the result code to easily debug problems
- Fixed `LIMIT/OFFSET` SQL generation in `Mvc\Model\Query\Builder`
- Fixed `Logger\Formatter\Line` to match 1.3.x behavior
- Fixed warning when castOnHydrate' is true [#10648](https://github.com/phalcon/cphalcon/pull/10648)
- Added name before int/float/numeric/string/bool/null/other variables in Debug\Dump::output
- Now `Validation\Validator\Identical` allows both 'accepted' and 'value' as value to keep backwards compatibility
- Added `\Phalcon\Mvc\Model\MetaData\Redis` adapter.
- Added Redis Session adapter
- Fixed bug in `Mvc\Model\Criteria::fromInput` unallowing it to use renamed columns
- Fixed bug in `Http\Request` getRawBody()/getPut() clears input buffer [#10694](https://github.com/phalcon/cphalcon/issues/10694)

# [2.0.5](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.5) (2015-07-14)
- Fixed a bug that makes that attaching an events manager to an Mvc\Application causes view->render() not being called
- Fixed bug that makes generated SQL statements using FOR UPDATE not being parsed correctly
- The email filter now no longer removes the ' character [#10603](https://github.com/phalcon/cphalcon/pull/10603)
- When an array is bound the cached representation in PHQL makes the SQL being incorrectly
  generated the second time.
- Added `\Phalcon\Mvc\Model\MetaData\Memcache` and `\Phalcon\Mvc\Model\MetaData\Libmemcached` adapters

# [2.0.4](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.4) (2015-07-07)
- Fixed bug in `Phalcon\Mvc\Model::update()` that throws an exception when the record does exist
- Now links in `Phalcon\Debug` point to https://api.phalconphp.com instead of http://docs.phalconphp.com
- Implemented a more versatile way to assign variables in Volt allowing to assign properties and array indexes
- Improved generation of macros in Volt using anonymous functions instead of plain PHP functions
  This allow to bind the adapter object and inject services within them
- Fixed generation and validation of default parameters in Volt's macros
- Added `Phalcon\Assets\Manager::getCollections()` to return all collections registered [#2488](https://github.com/phalcon/cphalcon/pull/2488)
- Now `Phalcon\Mvc\Url::getStatic()` generates URLs from routes
- Introduced `Phalcon\Mvc\EntityInterface` to allow parameters receive both `Phalcon\Mvc\Model` and `Phalcon\Mvc\Collection` instances
- Added `Phalcon\Session\Adapter::setName()` to change the session name
- Added BIGINT support in `Phalcon\Db`
- Added new types `Phalcon\Db\Column::BLOB` and `Phalcon\Db\Column::DOUBLE` [#10506](https://github.com/phalcon/cphalcon/pull/10506)
- Automatic binding of Large Object data (LOB) in the ORM
- Support for BIT types in MySQL with binding as booleans
- Added `Phalcon\Flash\Direct::output()` allowing to place flash messages in a specific place of the view [#629](https://github.com/phalcon/cphalcon/pull/629)
- Added 'autoescape' option that allows to globally enable autoescape in any Volt template
- Added `readAttribute`/`writeAttribute` to `Phalcon\Mvc\Collection\Document`
- Added toArray to `Phalcon\Mvc\Collection\Document`
- Global setting `db.force_casting` now forces casting bound parameters to specified bind types
- Introduced new placeholders in PHQL enclosed in brackets that allow to set the type: {name:str} or {names:array}
- Now you can bind arrays in bound parameters in PHQL
- Global setting `orm.cast_on_hydrate` allow to cast hydrated attributes to the original types in the mapped tables instead of using strings
- Values in LIMIT/OFFSET clause are now passed using bound parameters in PHQL
- Allowing late state binding in both Simple/Complex results to allow override `Mvc\Model::cloneResultMap`
- Added method `distinct()` in `Phalcon\Mvc\Model\Criteria` [#10536](https://github.com/phalcon/cphalcon/issues/10536)
- Added global setting orm.ignore_unknown_columns to ignore unexpected columns when hydrating instances in the ORM
  This fixes extra auxiliar columns used in `Db\Adapter\Pdo\Oracle`
- Added support for afterFetch in `Mvc\Collection`
- Added `beforeMatch` parameter in `@Route` annotation of `Mvc\Router\Annotations`
- Added groupBy/getGroupBy/having/getHaving to `Mvc\Model\Criteria`
- `Phalcon\Mvc\Model::count()` now return values as integer
- Removed `__construct` from `Phalcon\Mvc\View\EngineInterface`
- Added `Phalcon\Debug\Dump::toJson()` to return an JSON string of information about a single variable
- Now instances in Phalcon\Di are built using internal optimizers instead of ReflectionClass (PHP 5.6)
- Added `Phalcon\Mvc\Model\Validator\Ip` from incubator
- Added parameter return `defaultValue` in `Phalcon\Mvc\Model\Validator::getOption()`
- Fixed in `Phalcon\Validation\Validator\Identical` the name of parameter `value` to `accepted` according docs
- Added method `Text:dynamic()` generate random text in accordance with the template, see [#10571](https://github.com/phalcon/cphalcon/pull/10571)
- Now Mvc\Router has default routes with unicode support [#10544](https://github.com/phalcon/cphalcon/pull/10544)

# [2.0.3](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.3) (2015-06-10)
- Added support for Behaviors in `Phalcon\Mvc\Collection`
- Added `SoftDelete` and `Timestampable` behaviors to Collections
- Implemented Namespace aliases in PHQL
- Now you can define if a virtual foreign key must ignore null values or not
- Fixed bug that added two ? in `Mvc\Url::get()` when using query parameters ([#10421](https://github.com/phalcon/cphalcon/issues/10421))
- Now string attributes in models can be marked to allow empty string values ([#440](https://github.com/phalcon/cphalcon/issues/440))
- Added an option to return the SQL to be generated from a `Mvc\Model\Query` instance ([#1908](https://github.com/phalcon/cphalcon/issues/1908))
- Fix doesn't correct column domain in `Phalcon\Db\Dialect::select()` see [#10439](https://github.com/phalcon/cphalcon/pull/10439)
- Added support for DOUBLE type in MySQL
- `Phalcon\Tag\Select` now handles array values as strings avoiding that zero will be handled as empty string ([#2921](https://github.com/phalcon/cphalcon/issues/2921)
- PHQL now supports CASE/WHEN/ELSE expressions ([#651](https://github.com/phalcon/cphalcon/issues/651))
- Fixed bug that passes non-string values to `Phalcon\Crypt::encrypt` from `Phalcon\Http\Cookies`
- Fixed bug that didn't pass the schema name in the sequence name (PostgreSQL)
- Attribute persistent is now removed from the DNS attributes in PDO connections to avoid errors in PostgreSQL ([#10484](https://github.com/phalcon/cphalcon/issues/10484))

# [2.0.2](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.2) (2015-05-26)
 - Added `stats()` methods to Beanstalk
 - Fixed segfault when a docblock does not have annotations [#10301](https://github.com/phalcon/cphalcon/issues/10301)
 - Fixed wrong number of parameters passed when triggering an event in Mvc\Collection
 - Now `Mvc\Model` checks if an attribute has a default value associated in the database and ignores it from the insert/update generated SQL
 - Readded `Http\Request::hasPut()` ([#10283](https://github.com/phalcon/cphalcon/issues/10283))
 - Phalcon\Text
   - Added method `reduceSlashes()` - Reduces multiple slashes in a string to single slashes
   - Added method `concat()` - Concatenates strings using the separator only once without duplication in places concatenation
 - Added conditional on Session adapter start() to check if the session has already been started
 - Added `status()` function in Session adapter to return the status of the session (disabled/none/started)

# [2.0.1](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.1) (2015-05-10)
 - Added missing `Phalcon\Debug::listenLowSeverity`
 - Added new theme in `Phalcon\Debug`
 - Allow to count and iterate `Phalcon\Session\Bag` as in 1.3.x
 - Renamed `getEventsManager()` to `getInternalEventsManager()` in `Phalcon\Di` to avoid collision with existing services
 - Added constants FILTER_* to `Phalcon\Filter` for filters names
 - Fixed multibyte characters in cssmin/jsmin
 - Added `Phalcon\Security::destroyToken()` to remove current token key and value from session
   removed first argument (password), since it's not used in the function
 - Restored alternative hash algorithms in `Phalcon\Security` that were available in 1.3.x
 - Fixed bug that makes instances returned in Model::findFirst to be not completely initialized
 - Added support for general SELECT ALL/SELECT DISTINCT in PHQL
 - Added support for "not in" test in Volt
 - Phalcon\Debug\Dump
   - Renamed method `var()` to `variable()`
   - Renamed method `vars()` to `variables()`
 - `Phalcon\Mvc\Model::findFirst()` now allows hydration ([#10259](https://github.com/phalcon/cphalcon/issues/10259))

# [2.0.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v2.0.0) (2015-04-17)
 - Full rewrite of most components in Zephir
 - `Added Phalcon\Mvc\Micro::error` for better handling of exceptions
 - `Phalcon\Forms\Form::label` does not share attributes with the ones that belong to the element
 - Added parameter 'params' to set default conditions when retrieving related records
 - Added filters "int!" and "float!" that cast values to the respective type
 - Filter "alphanum" now uses a regular expression instead of internal functions for better behaviour in 64bits
 - Added `allowEmpty` option in `Phalcon\Validation` validators to skip validation if the value is empty
 - Added `Phalcon\Validation::setDefaultMessages` to set default values in validators
 - Added `Phalcon\Validation\Validator\Numericality`
 - Added events in `Phalcon\Di`: beforeServiceResolve / afterServiceResolve
 - Mysql database introspector now uses DATABASE() as default schema
 - Added option to disable cache keys in `Cache\Backend\Memcache`
 - `Mvc\View component` is now disabled automatically when redirecting using Http\Response
 - `Mvc\Model::dynamicUpdate` now works better as it compares if every field has changed according to its data type
 - Added `Db\Adapter\Pdo::getErrorInfo()` to obtain the last error generated in a PDO connection

# [1.3.4](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.3.4) (2014-10-28)
 - Fix improper access to `\Phalcon\Debug::$_charset` ([#2840](https://github.com/phalcon/cphalcon/issues/2840))
 - Fix segfault in Phalcon\Mvc\Collection when an invalid parameter is passed as conditions
 - Fix segfault when MongoClient does not return a valid collection in Phalcon\Mvc\Collection
 - Fix possible memory corruption when phalcon_concat_self does not properly separate values

# [1.3.3](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.3.3) (2014-09-23)
 - Fix segmentation fault in zim_Phalcon_Http_Request_getBasicAuth ([#2819](https://github.com/phalcon/cphalcon/issues/2819))
 - Fix memory corruption on unclean shutdown ([#2829](https://github.com/phalcon/cphalcon/issues/2829))

# [1.3.2](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.3.2) (2015-05-05)
 - fix inverted test in Model/setSnapshotData() (issue [#2466](https://github.com/phalcon/cphalcon/issues/2466))
 - Updated Phalcon\Queue\Beanstalk\Job::touch comment
 - Fixed use columns as referenced columns in mysql createTable() reference...
 - [#2414](https://github.com/phalcon/cphalcon/issues/2414)  - Removed check for DBG in session/adapter
 - Updated Model::__set
 - [#1989](https://github.com/phalcon/cphalcon/issues/1989) Supported \Phalcon\Db\Index: TYPE
 - Updated Phalcon\Mvc\Model\Query\Builder::groupBy
 - Validation, setDefaultMessages fix
 - Fix pagination nativeArray test-unit failed
 - Add Phalcon\Translate\Adapter\Gettext
 - Add Phalcon\Config\Adapter\Yaml
 - [#1803](https://github.com/phalcon/cphalcon/issues/1803) Bug join alias
 - Fix valid function for the first call
 - Acl bug
 - [#2402](https://github.com/phalcon/cphalcon/issues/2402) issue
 - Ignore "value" attribute in TextArea.
 - [#2394](https://github.com/phalcon/cphalcon/issues/2394) Add Phalcon\Validation\MessageInterface
 - Relative namespace
 - [#2386](https://github.com/phalcon/cphalcon/issues/2386)
 - Fixing a typo
 - [#2375](https://github.com/phalcon/cphalcon/issues/2375) Add check messages is object in Phalcon\Validation::appendMess...
 - Update affected rows for selects.
 - [#2196](https://github.com/phalcon/cphalcon/issues/2196): Declare missing functions
 - Fix broken condition
 - Add Phalcon\Mvc\Model\MetaData\Strategy
 - Fix offsetUnset
 - Changing "file_exists" function for "is_file".
 - Fix bug about updated property for Phalcon\Session\*
 - [#2291](https://github.com/phalcon/cphalcon/issues/2291) Middlewares do not stop operation when before event triggered in Micro as documented http://docs.…
 - [#1608](https://github.com/phalcon/cphalcon/issues/1608) about Phalcon\Mvc\Router\Annotations
 - [#2019](https://github.com/phalcon/cphalcon/issues/2019) and added tests
 - model: added methods arg infos
 - [#2319](https://github.com/phalcon/cphalcon/issues/2319) In `Model::_postSaveRelatedRecords` add check whether value is object
 - [#2321](https://github.com/phalcon/cphalcon/issues/2321): Fixed the null value for position
 - [#2313](https://github.com/phalcon/cphalcon/issues/2313) about Phalcon\Annotations\Annotation
 - [#2229](https://github.com/phalcon/cphalcon/issues/2229) (cast and convert not working)
 - Add method Phalcon\Assets\Collection::addFilter
 - Add Phalcon\Session\Adapter\memcache and Phalcon\Session\Adapter\Libmemcached
 - Add class Phalcon\Session\Adapter\Libmemcached
 - Add class Phalcon\Session\Adapter\Memcache
 - \Phalcon\Tag::XHTML5 was returning empty string
 - [#2278](https://github.com/phalcon/cphalcon/issues/2278) add Phalcon\Logger\Multiple::CRITICAL
 - Tag, add title separator to append/prepend title
 - [#2250](https://github.com/phalcon/cphalcon/issues/2250) Updated Phalcon\Db\Dialect::select
 - [#2270](https://github.com/phalcon/cphalcon/issues/2270) updated phalcon_camelize
 - Add namespace support for view
 - [#2259](https://github.com/phalcon/cphalcon/issues/2259) Updated \Phalcon\Image\Adapter::crop
 - [#2262](https://github.com/phalcon/cphalcon/issues/2262) `\Phalcon\Logger\Formatter\Json` Wrong number of parameters
 - [#2244](https://github.com/phalcon/cphalcon/issues/2244) add judge conditions in `Phalcon\Mvc\Model\Manager::getRelationRecords`
 - Removed final keyword from Model constructor
 - [#2111](https://github.com/phalcon/cphalcon/issues/2111) – replacing bindParam to bindValue to avoid unexpected reference changes
 - [#2002](https://github.com/phalcon/cphalcon/issues/2002) Tag::linkTo() to allow the addition of query string parameters
 - Added `allowEmpty` option to \Phalcon\Mvc\Model\Validator\*
 - Use phalcon_camelize for namespace Add \Phalcon\Session\Adapter::setId Fixed [#1932](https://github.com/phalcon/cphalcon/issues/1932) Phalcon\Http\…
 - [#2111](https://github.com/phalcon/cphalcon/issues/2111) – replacing bindParam to bindValue to avoid unexpected reference changes
 - Fix wrong issent() call on non Response objects
 - [#2236](https://github.com/phalcon/cphalcon/issues/2236)  - in mysql tinyint(1) is not boolean it's an int between 0 and 127
 - Add \Phalcon\Session\Adapter::setId
 - Fix BUG \Phalcon\Model\Validate\*
 - Travis fast-finish builds
 - [#2157](https://github.com/phalcon/cphalcon/issues/2157) and added tests
 - [#2196](https://github.com/phalcon/cphalcon/issues/2196) Declared missing functions
 - Add `allowEmpty` option to \Phalcon\Mvc\Model\Validator\*
 - [#2002](https://github.com/phalcon/cphalcon/issues/2002) Tag::linkTo() to allow the addition of query string parameters
 - [#2018](https://github.com/phalcon/cphalcon/issues/2018) add method \Phalcon\Db\Result\Pdo::nextRowset
 - Use phalcon_camelize for namespace
 - [#1932](https://github.com/phalcon/cphalcon/issues/1932) Phalcon\Http\Request\File extend SplFileInfo

# [1.3.1](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.3.1) (2014-03-25)
 - Fixed segfault in Phalcon\Di\Service::resolve when string class does not exist ([#2205](https://github.com/phalcon/cphalcon/issues/2205))
 - Moved global zvals to RINIT/RSHUTDOWN to improve stability on Windows TS builds
 - Moved pre-allocated frames to RINIT/RSHUTDOWN to improve stability on Windows TS builds
 - Fixed segfault when replacing Phalcon\Session adapter by PHP userland adapter
 - Fixed zval invalid indirection in Phalcon\Security hash
 - Fixed segfault when passing an invalid number of arguments to Phalcon\Annotations\Reader::parseDocBlock
 - Private and Protected properties weren't unmangled in Phalcon\Annotations\Reader
 - First character of controller name was removed when isExactHandler flag is on

# [1.3.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.3.0) (2014-03-19)
 - Make the source code compatible with PHP 5.6-dev and PHP 5.7-dev ([#1762](https://github.com/phalcon/cphalcon/issues/1762))
 - Code cleanup: get rid of compiler warnings, dead code elimination, code deduplication, use static code analysers to eliminate possible bugs
   ([#801](https://github.com/phalcon/cphalcon/issues/801), [#802](https://github.com/phalcon/cphalcon/issues/802), [#810](https://github.com/phalcon/cphalcon/issues/810), [#825](https://github.com/phalcon/cphalcon/issues/825), [#827](https://github.com/phalcon/cphalcon/issues/827), [#838](https://github.com/phalcon/cphalcon/issues/838), [#849](https://github.com/phalcon/cphalcon/issues/849), [#942](https://github.com/phalcon/cphalcon/issues/942), [#968](https://github.com/phalcon/cphalcon/issues/968), [#1001](https://github.com/phalcon/cphalcon/issues/1001), [#1093](https://github.com/phalcon/cphalcon/issues/1093), [#1169](https://github.com/phalcon/cphalcon/issues/1169), [#1214](https://github.com/phalcon/cphalcon/issues/1214), [#1223](https://github.com/phalcon/cphalcon/issues/1223), [#1224](https://github.com/phalcon/cphalcon/issues/1224), [#1375](https://github.com/phalcon/cphalcon/issues/1375), [#1430](https://github.com/phalcon/cphalcon/issues/1430), [#1787](https://github.com/phalcon/cphalcon/issues/1787), [#1794](https://github.com/phalcon/cphalcon/issues/1794), [#1828](https://github.com/phalcon/cphalcon/issues/1828))
 - Fixed various memory leaks ([#469](https://github.com/phalcon/cphalcon/issues/469), [#860](https://github.com/phalcon/cphalcon/issues/860), [#910](https://github.com/phalcon/cphalcon/issues/910), [#914](https://github.com/phalcon/cphalcon/issues/914), [#916](https://github.com/phalcon/cphalcon/issues/916), [#1031](https://github.com/phalcon/cphalcon/issues/1031), [#1067](https://github.com/phalcon/cphalcon/issues/1067), [#1249](https://github.com/phalcon/cphalcon/issues/1249), [#1273](https://github.com/phalcon/cphalcon/issues/1273), [#1291](https://github.com/phalcon/cphalcon/issues/1291), [#1309](https://github.com/phalcon/cphalcon/issues/1309), [#1345](https://github.com/phalcon/cphalcon/issues/1345), [#1455](https://github.com/phalcon/cphalcon/issues/1455), [#1470](https://github.com/phalcon/cphalcon/issues/1470), [#1700](https://github.com/phalcon/cphalcon/issues/1700))
 - Fixed memory access violations / segmentation faults / etc ([#469](https://github.com/phalcon/cphalcon/issues/469), [#849](https://github.com/phalcon/cphalcon/issues/849), [#851](https://github.com/phalcon/cphalcon/issues/851), [#852](https://github.com/phalcon/cphalcon/issues/852), [#858](https://github.com/phalcon/cphalcon/issues/858), [#860](https://github.com/phalcon/cphalcon/issues/860), [#861](https://github.com/phalcon/cphalcon/issues/861), [#895](https://github.com/phalcon/cphalcon/issues/895), [#911](https://github.com/phalcon/cphalcon/issues/911), [#918](https://github.com/phalcon/cphalcon/issues/918), [#927](https://github.com/phalcon/cphalcon/issues/927), [#928](https://github.com/phalcon/cphalcon/issues/928), [#1000](https://github.com/phalcon/cphalcon/issues/1000), [#1077](https://github.com/phalcon/cphalcon/issues/1077), [#1112](https://github.com/phalcon/cphalcon/issues/1112), [#1113](https://github.com/phalcon/cphalcon/issues/1113), [#1131](https://github.com/phalcon/cphalcon/issues/1131), [#1149](https://github.com/phalcon/cphalcon/issues/1149), [#1173](https://github.com/phalcon/cphalcon/issues/1173),
   [#1272](https://github.com/phalcon/cphalcon/issues/1272), [#1284](https://github.com/phalcon/cphalcon/issues/1284), [#1302](https://github.com/phalcon/cphalcon/issues/1302), [#1340](https://github.com/phalcon/cphalcon/issues/1340), [#1343](https://github.com/phalcon/cphalcon/issues/1343), [#1368](https://github.com/phalcon/cphalcon/issues/1368), [#1369](https://github.com/phalcon/cphalcon/issues/1369), [#1371](https://github.com/phalcon/cphalcon/issues/1371), [#1376](https://github.com/phalcon/cphalcon/issues/1376), [#1379](https://github.com/phalcon/cphalcon/issues/1379), [#1392](https://github.com/phalcon/cphalcon/issues/1392), [#1451](https://github.com/phalcon/cphalcon/issues/1451), [#1466](https://github.com/phalcon/cphalcon/issues/1466), [#1485](https://github.com/phalcon/cphalcon/issues/1485), [#1494](https://github.com/phalcon/cphalcon/issues/1494), [#1501](https://github.com/phalcon/cphalcon/issues/1501), [#1504](https://github.com/phalcon/cphalcon/issues/1504), [#1509](https://github.com/phalcon/cphalcon/issues/1509), [#1567](https://github.com/phalcon/cphalcon/issues/1567), [#1607](https://github.com/phalcon/cphalcon/issues/1607), [#1983](https://github.com/phalcon/cphalcon/issues/1983), [#1006](https://github.com/phalcon/cphalcon/issues/1006))
 - Fixed PHP notices, warnings and other incompatibilities ([#894](https://github.com/phalcon/cphalcon/issues/894), [#1222](https://github.com/phalcon/cphalcon/issues/1222), [#1315](https://github.com/phalcon/cphalcon/issues/1315), [#1413](https://github.com/phalcon/cphalcon/issues/1413), [#1427](https://github.com/phalcon/cphalcon/issues/1427), [#1428](https://github.com/phalcon/cphalcon/issues/1428), [#1529](https://github.com/phalcon/cphalcon/issues/1529), [#1988](https://github.com/phalcon/cphalcon/issues/1988), [#1998](https://github.com/phalcon/cphalcon/issues/1998))
 - Fixed inheritance chain for Phalcon\Forms\Exception, Phalcon\Loader\Exception, Phalcon\Http\Request\Exception ([#1770](https://github.com/phalcon/cphalcon/issues/1770))
 - Major source code optimizations ([#1785](https://github.com/phalcon/cphalcon/issues/1785), [#1972](https://github.com/phalcon/cphalcon/issues/1972), [#2003](https://github.com/phalcon/cphalcon/issues/2003))
 - Control Phalcon behavior via INI settings ([#1796](https://github.com/phalcon/cphalcon/issues/1796))
 - Security fixes:
   - Hardening fixes ([#1044](https://github.com/phalcon/cphalcon/issues/1044))
   - Interface validation ([#1043](https://github.com/phalcon/cphalcon/issues/1043), [#1048](https://github.com/phalcon/cphalcon/issues/1048))
   - Thorough data validation in __wakeup() ([#1043](https://github.com/phalcon/cphalcon/issues/1043), [#1634](https://github.com/phalcon/cphalcon/issues/1634), [#1635](https://github.com/phalcon/cphalcon/issues/1635))
   - Fixed XSS vulnerabilities ([#1216](https://github.com/phalcon/cphalcon/issues/1216), [#1190](https://github.com/phalcon/cphalcon/issues/1190))
   - Phalcon\Security::checkHash() allows to restrict the length of the password to avoid attacks like https://www.djangoproject.com/weblog/2013/sep/15/security/ ([#1261](https://github.com/phalcon/cphalcon/issues/1261))
   - Fixed crash while rendering element's label ([#1210](https://github.com/phalcon/cphalcon/issues/1210))
   - Prevent MongoDB Request Injection Attacks ([#1265](https://github.com/phalcon/cphalcon/issues/1265))
   - Do not allow to override superglobals in views ([#1617](https://github.com/phalcon/cphalcon/issues/1617))
 - Phalcon Kernel:
   - 32 and 64 bit hashes can be computed on the same CPU architecture ([#817](https://github.com/phalcon/cphalcon/issues/817))
   - Reduced overall memory usage ([#834](https://github.com/phalcon/cphalcon/issues/834), [#891](https://github.com/phalcon/cphalcon/issues/891), [#893](https://github.com/phalcon/cphalcon/issues/893))
   - Memory allocation optimizations ([#912](https://github.com/phalcon/cphalcon/issues/912), [#1220](https://github.com/phalcon/cphalcon/issues/1220), [#1987](https://github.com/phalcon/cphalcon/issues/1987))
   - Faster internal array and string manipulation ([#822](https://github.com/phalcon/cphalcon/issues/822), [#823](https://github.com/phalcon/cphalcon/issues/823), [#830](https://github.com/phalcon/cphalcon/issues/830), [#833](https://github.com/phalcon/cphalcon/issues/833), [#837](https://github.com/phalcon/cphalcon/issues/837), [#890](https://github.com/phalcon/cphalcon/issues/890), [#1972](https://github.com/phalcon/cphalcon/issues/1972))
   - Camelize does not ignore the last character of a string anymore ([#1436](https://github.com/phalcon/cphalcon/issues/1436))
   - Fixed bug in phalcon_fix_path() ([#1601](https://github.com/phalcon/cphalcon/issues/1601))
   - Use native counterparts for memory_get_usage(), gettype(), json_encode(), json_decode(), session_XXX(), header(), headers_sent(), debug_backtrace(),
     lcfirst(), ob_XXX(), array_unshift(), array_values(), array_keys(), htmlentities() ([#836](https://github.com/phalcon/cphalcon/issues/836), [#847](https://github.com/phalcon/cphalcon/issues/847), [#936](https://github.com/phalcon/cphalcon/issues/936), [#945](https://github.com/phalcon/cphalcon/issues/945), [#1099](https://github.com/phalcon/cphalcon/issues/1099))
   - Hash functions tailored for object handlers ([#842](https://github.com/phalcon/cphalcon/issues/842))
   - Optimization of calls to userland functions and methods ([#843](https://github.com/phalcon/cphalcon/issues/843), [#954](https://github.com/phalcon/cphalcon/issues/954))
   - Read/modify/update optimization on properties ([#848](https://github.com/phalcon/cphalcon/issues/848))
   - Added support for self/parent/static scopes in static properties ([#943](https://github.com/phalcon/cphalcon/issues/943))
   - Scope lookup optimizations ([#948](https://github.com/phalcon/cphalcon/issues/948))
   - Do not restore memory frames from kernel functions ([#960](https://github.com/phalcon/cphalcon/issues/960), [#976](https://github.com/phalcon/cphalcon/issues/976))
   - Diagnostic messages when Phalcon is compiled in dev mode ([#1009](https://github.com/phalcon/cphalcon/issues/1009), [#1054](https://github.com/phalcon/cphalcon/issues/1054), [#1097](https://github.com/phalcon/cphalcon/issues/1097))
   - Return Value Optimization ([#1046](https://github.com/phalcon/cphalcon/issues/1046), [#1047](https://github.com/phalcon/cphalcon/issues/1047), [#1075](https://github.com/phalcon/cphalcon/issues/1075))
   - Fixed locale issue ([#1095](https://github.com/phalcon/cphalcon/issues/1095))
   - Added support for interned strings (PHP 5.4+)
   - Static property fetch/update optimization ([#1293](https://github.com/phalcon/cphalcon/issues/1293))
   - Fix misleading diagnostics on exception ([#1297](https://github.com/phalcon/cphalcon/issues/1297))
   - Use preallocated permanent zvals instead of null, true, false, 0 and 1 ([#1302](https://github.com/phalcon/cphalcon/issues/1302))
   - Bug fix in phalcon_fix_path() ([#1591](https://github.com/phalcon/cphalcon/issues/1591))
   - Persistent function cache for Phalcon methods ([#1825](https://github.com/phalcon/cphalcon/issues/1825))
   - Function call optimization ([#1846](https://github.com/phalcon/cphalcon/issues/1846))
   - Use Native Reflection API ([#1957](https://github.com/phalcon/cphalcon/issues/1957))
 - Phalcon\Acl:
   - Fixed broken ACL inheritance ([#905](https://github.com/phalcon/cphalcon/issues/905))
   - Bug fix when ACL allowed access to forbidden resources ([#1303](https://github.com/phalcon/cphalcon/issues/1303))
   - Fixed bug with ACL * wildcard ([#1409](https://github.com/phalcon/cphalcon/issues/1409))
   - Fixed bug with numeric resources ([#1513](https://github.com/phalcon/cphalcon/issues/1513))
   - Phalcon\Acl\Adapter now implements Phalcon\Acl\AdapterInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
 - Phalcon\Annotations:
   - Fixed getProperty() bug in AnnotationsAdapter ([#996](https://github.com/phalcon/cphalcon/issues/996))
   - Phalcon\Annotations optimizations ([#1141](https://github.com/phalcon/cphalcon/issues/1141))
   - Fixed parsing of annotations containing / ([#1480](https://github.com/phalcon/cphalcon/issues/1480))
   - Phalcon\Annotations\Adapter now implements Phalcon\Annotations\AdapterInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Annotation parser optimization ([#1957](https://github.com/phalcon/cphalcon/issues/1957))
 - Phalcon\Assets:
   - Fixed bugs when minifier produced no output at all ([#811](https://github.com/phalcon/cphalcon/issues/811), [#821](https://github.com/phalcon/cphalcon/issues/821))
   - Fixed joining issue ([#951](https://github.com/phalcon/cphalcon/issues/951))
   - Added support for UTF-8 characters in jsmin
   - Fixed chaining of CSS/JS filters ([#1198](https://github.com/phalcon/cphalcon/issues/1198))
   - Phalcon\Assets\Filters\CssMin and JsMin implement Phalcon\Assets\FilterInterface ([#1539](https://github.com/phalcon/cphalcon/issues/1539))
   - Added Phalcon\Assets\Collection::setTargetLocal() ([#1532](https://github.com/phalcon/cphalcon/issues/1532))
 - Phalcon\Cache:
   - Added Libmemcached cache backend ([#913](https://github.com/phalcon/cphalcon/issues/913))
   - Added support for APCu 4.0.2+ ([#1234](https://github.com/phalcon/cphalcon/issues/1234))
   - Implemented Phalcon\Cache\Backend\Memory::queryKeys() ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Bug fixes in Phalcon\Cache\Backend\Xcache ([#1406](https://github.com/phalcon/cphalcon/issues/1406))
   - Phalcon\Cache\Frontend\Data optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Frontend\None optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Frontend\Base64 optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Frontend\Igbinary optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Frontend\Output optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Frontend\Json optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\Memory optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\File optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\Apc optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\Xcache optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\Memcache optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\Mongo optimizations ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Phalcon\Cache\Backend\Libmemcached optimizations and bug fixes ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
   - Added increment() and decrement() methods ([#1374](https://github.com/phalcon/cphalcon/issues/1374))
   - Added flush() method ([#1352](https://github.com/phalcon/cphalcon/issues/1352))
   - Phalcon\Cache\Backend now implements Phalcon\Cache\BackendInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Ability to disable key tracking for Memcache/Libmemcached backends ([#1550](https://github.com/phalcon/cphalcon/issues/1550))
 - Phalcon\Config:
   - Faster Phalcon\Config implementation using object handlers ([#837](https://github.com/phalcon/cphalcon/issues/837), [#1277](https://github.com/phalcon/cphalcon/issues/1277))
   - Phalcon\Config now support numeric properties as well ([#837](https://github.com/phalcon/cphalcon/issues/837))
   - Implemented Phalcon\Config::offsetUnset() ([#732](https://github.com/phalcon/cphalcon/issues/732))
   - Phalcon\Config\Adapter\Ini correctly handles empty sections and INI files without any sections ([#829](https://github.com/phalcon/cphalcon/issues/829), [#837](https://github.com/phalcon/cphalcon/issues/837))
   - Added Phalcon\Adapter\Config\Json class to read JSON configs ([#844](https://github.com/phalcon/cphalcon/issues/844))
   - Phalcon\Config::merge now works with derived classes ([#1024](https://github.com/phalcon/cphalcon/issues/1024))
   - Dot-delimited directives in INI-files are now prsed correctly ([#872](https://github.com/phalcon/cphalcon/issues/872))
   - Support for PHP arrays as config files ([#1439](https://github.com/phalcon/cphalcon/issues/1439))
 - Phalcon\Crypt:
   - Added support for various padding schemes (PKCS7, ANSI X.923, ISO 10126, ISO/IEC 7816-4, zero padding, space padding) to Phalcon\Crypt ([#864](https://github.com/phalcon/cphalcon/issues/864), [#887](https://github.com/phalcon/cphalcon/issues/887))
   - Reduced peak memory usage ([#1237](https://github.com/phalcon/cphalcon/issues/1237))
   - encryptBase64() and decryptBase64() can optionally use RFC 4648 flavor of BASE64 ([#1353](https://github.com/phalcon/cphalcon/issues/1353), [#1919](https://github.com/phalcon/cphalcon/issues/1919))
 - Phalcon\Db:
   - Added support for DECIMAL scale ([#940](https://github.com/phalcon/cphalcon/issues/940))
   - Fixed invalid sequence names for PostgreSQL ([#1022](https://github.com/phalcon/cphalcon/issues/1022))
   - Added support for MySQL DOUBLE type ([#1128](https://github.com/phalcon/cphalcon/issues/1128))
   - Database dialects now support BOOLEAN data type ([#816](https://github.com/phalcon/cphalcon/issues/816))
   - Added support for POINT type in MySQL ([#1536](https://github.com/phalcon/cphalcon/issues/1536))
   - Fixed issue with RawValue('default') on composite primary key ([#1534](https://github.com/phalcon/cphalcon/issues/1534))
   - Added support for AUTO_INCREMENT columns to addColumn() (MySQL, SQLite) and modifyColumn() (MySQL) ([#1695](https://github.com/phalcon/cphalcon/issues/1695))
   - Phalcon\Db\Dialect\Mysql::getColumnDefinition() now returns INT instead of INT(0) ([#1695](https://github.com/phalcon/cphalcon/issues/1695))
   - Added support for the following fetch modes from PDO: FETCH_LAZY, FETCH_BOUND, FETCH_COLUMN, FETCH_CLASS, FETCH_INTO, FETCH_FUNC, FETCH_NAMED, FETCH_KEY_PAIR ([#1642](https://github.com/phalcon/cphalcon/issues/1642))
   - Added support for the following fetch mode modifiers from PDO: FETCH_GROUP, FETCH_UNIQUE, FETCH_CLASSTYPE, FETCH_SERIALIZE, FETCH_PROPS_LATE ([#1642](https://github.com/phalcon/cphalcon/issues/1642))
   - Phalcon\Db optimizations ([#1693](https://github.com/phalcon/cphalcon/issues/1693))
   - Phalcon\Db\Adapter optimizations ([#1693](https://github.com/phalcon/cphalcon/issues/1693))
   - Phalcon\Db\Index optimizations ([#1693](https://github.com/phalcon/cphalcon/issues/1693))
   - Phalcon\Db\Profiler optimizations ([#1693](https://github.com/phalcon/cphalcon/issues/1693))
   - Phalcon\Db\Reference optimizations ([#1693](https://github.com/phalcon/cphalcon/issues/1693))
   - Phalcon\Db\Result\Pdo optimizations ([#1693](https://github.com/phalcon/cphalcon/issues/1693))
   - Phalcon\Db\Adapter now implements Phalcon\Db\AdapterInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Db\Dialect now implements Phalcon\Db\DialectInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
 - Phalcon\Debug:
   - Added support for UTF-8 to \Phalcon\Debug ([#1099](https://github.com/phalcon/cphalcon/issues/1099))
   - Phalcon\Debug::uri now supports both http and https ([#987](https://github.com/phalcon/cphalcon/issues/987))
   - Fixed array to string conversion notice ([#1103](https://github.com/phalcon/cphalcon/issues/1103))
   - Add support for xdebug.file_link_format ([#1401](https://github.com/phalcon/cphalcon/issues/1401))
 - Phalcon\Di:
   - Phalcon\Di optimizations ([#1014](https://github.com/phalcon/cphalcon/issues/1014)) with workarounds for NuSphere DBG ([#1714](https://github.com/phalcon/cphalcon/issues/1714))
   - Added Phalcon\Di\Service::isResolved() method ([#1242](https://github.com/phalcon/cphalcon/issues/1242))
   - Make sure that 'persistent' is resolved only when accessed for the first time ([#1637](https://github.com/phalcon/cphalcon/issues/1637))
   - Faster DI implementation by using object handlers ([#1473](https://github.com/phalcon/cphalcon/issues/1473))
   - Changes to Phalcon\DiInterface ([#2034](https://github.com/phalcon/cphalcon/issues/2034))
     - removed setShared() method because it is a shorthand for set($name, $definition, true);
     - removed attempt() method because it is a shorthand for `has()` + `set()`
     - renamed setRaw() to setService() because getRaw() is actually getService() + $service->getDefinition()
     - setRaw() is now an alias for setService() but it will spit E_DEPRECATED
     - removed `getRaw()` because it is `getService()` + `$service->getDefinition()`
     - modified `setService($name, $raw_definition)` to `setService($raw_definition)` because service name can be retrieved from the definition
 - Phalcon\Dispatcher:
   - Dispatching parameters now can be modified in 'beforeExecuteRoute' events
   - 'beforeException' events can now handle exceptions occurred when executing actions ([#140](https://github.com/phalcon/cphalcon/issues/140))
   - Added Phalcon\Dispatcher::getHandlerClass and Phalcon\Dispatcher::getActionMethod
   - Implemented afterInitialize event ([#782](https://github.com/phalcon/cphalcon/issues/782))
   - Phalcon\Dispatcher optimizations ([#782](https://github.com/phalcon/cphalcon/issues/782))
   - Added getPreviousControllerName(), getPreviousActionName() ([#1462](https://github.com/phalcon/cphalcon/issues/1462))
   - If an event handler throws an exception, call dispatch:beforeException and break the dispatch loop ([#1763](https://github.com/phalcon/cphalcon/issues/1763))
   - Phalcon\Dispatcher::_handleException() is invoked regardless whether the event manager is present ([#1953](https://github.com/phalcon/cphalcon/issues/1953))
 - Phalcon\Element:
   - Phalcon\Element::addFilter() incorrectly prepends NULL as the first element ([#1019](https://github.com/phalcon/cphalcon/issues/1019))
 - Phalcon\Escaper:
   - Fixed bugs in Phalcon\Escaper ([#917](https://github.com/phalcon/cphalcon/issues/917))
   - Phalcon\Escaper optimizations ([#1015](https://github.com/phalcon/cphalcon/issues/1015))
   - Fix phalcon_escape_multi() to generate valid UTF-8 ([#1681](https://github.com/phalcon/cphalcon/issues/1681))
 - Phalcon\Events:
   - Added support for weak references ([#663](https://github.com/phalcon/cphalcon/issues/663))
   - Bug fix in Phalcon\Events\manager::attach() ([#1331](https://github.com/phalcon/cphalcon/issues/1331), [#1337](https://github.com/phalcon/cphalcon/issues/1337))
 - Phalcon\Flash:
   - Phalcon\Flash\Session::getMessage('key') returns now an empty array if the key is not found ([#908](https://github.com/phalcon/cphalcon/issues/908), [#920](https://github.com/phalcon/cphalcon/issues/920))
   - Phalcon\Flash\Session::getMessages() incorrectly removed all messages ([#1575](https://github.com/phalcon/cphalcon/issues/1575))
   - Implemented Phalcon\Flash\Session::isset() ([#1342](https://github.com/phalcon/cphalcon/issues/1342))
 - Phalcon\Forms:
   - Phalcon\Forms\Element\* classes now implement Phalcon\Form\ElementInterface
   - Added support for HTML attributes to Phalcon\Forms\Form::label() ([#1029](https://github.com/phalcon/cphalcon/issues/1029))
   - Phalcon\Forms\Form::getMessages() does not generate a fatal error if the form is valid ([#1349](https://github.com/phalcon/cphalcon/issues/1349))
   - Improvements to Phalcon\Forms\Form::add() ([#1386](https://github.com/phalcon/cphalcon/issues/1386))
   - Added Phalcon\Forms\Element\Radio class ([#1646](https://github.com/phalcon/cphalcon/issues/1646))
   - Phalcon\Forms\Form::hasMessagesFor() returns boolean ([#1764](https://github.com/phalcon/cphalcon/issues/1764))
   - Iterators for Phalcon\Forms\Form implemented via Zend API ([#1765](https://github.com/phalcon/cphalcon/issues/1765))
   - Phalcon\Forms\Form::count() implemented via Zend API ([#1765](https://github.com/phalcon/cphalcon/issues/1765))
   - Phalcon\Forms\Form optimizations ([#1765](https://github.com/phalcon/cphalcon/issues/1765))
   - Phalcon\Forms\Element now implements Phalcon\Forms\ElementInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Fixed Phalcon\Forms\Element\Select::addOption() ([#1955](https://github.com/phalcon/cphalcon/issues/1955))
 - Phalcon\Http:
   - Phalcon\Http\Cookie can be used without sessions ([#875](https://github.com/phalcon/cphalcon/issues/875))
   - Phalcon\Http\Cookie does not ignore expire time ([#897](https://github.com/phalcon/cphalcon/issues/897))
   - Phalcon\Http\Request fully supports file arrays ([#884](https://github.com/phalcon/cphalcon/issues/884), [#888](https://github.com/phalcon/cphalcon/issues/888))
   - Phalcon\Http\Request optimizations ([#889](https://github.com/phalcon/cphalcon/issues/889))
   - Added getKey(), getError(), isUploadedFile() methods to Phalcon\Http\Request\File ([#878](https://github.com/phalcon/cphalcon/issues/878), [#888](https://github.com/phalcon/cphalcon/issues/888))
   - Fixed regression in \Phalcon\Http\Request::getRawBody() ([#1091](https://github.com/phalcon/cphalcon/issues/1091))
   - Bug fix in Phalcon\Http\Request::getQuery() ([#1226](https://github.com/phalcon/cphalcon/issues/1226))
   - Fixed broken Phalcon\Http\Response::setFileToSend() method ([#831](https://github.com/phalcon/cphalcon/issues/831), [#832](https://github.com/phalcon/cphalcon/issues/832))
   - Redirects use status descriptions from RFC 2616 ([#1175](https://github.com/phalcon/cphalcon/issues/1175))
   - Phalcon\Http\Response::setFileToSend() can now show the file in the browser instead of offering to download it ([#853](https://github.com/phalcon/cphalcon/issues/853))
   - Added Phalcon\Http\Response\Headers::toArray() ([#1008](https://github.com/phalcon/cphalcon/issues/1008))
   - getJsonRawBody() may return an associative array ([#1241](https://github.com/phalcon/cphalcon/issues/1241))
   - Added getURI(), getBasicAuth(), getDigestAuth() methods to Phalcon\Http\Request ([#1250](https://github.com/phalcon/cphalcon/issues/1250))
   - Added getPut()/hasPut() methods to Phalcon\Http\Request ([#680](https://github.com/phalcon/cphalcon/issues/680), [#1403](https://github.com/phalcon/cphalcon/issues/1403))
   - Implemented Phalcon\Http\Request\File::getRealType ([#1442](https://github.com/phalcon/cphalcon/issues/1442), [#1444](https://github.com/phalcon/cphalcon/issues/1444))
   - External URLs are now automatically detected by Phalcon\Http\Response::redirect() ([#1182](https://github.com/phalcon/cphalcon/issues/1182))
   - Fixed error in Phalcon\Http\Response\Headers::send() when no headers were set ([#2047](https://github.com/phalcon/cphalcon/issues/2047))
 - Phalcon\Image:
   - Added Phalcon\Image\Adapter, Phalcon\Image\Adapter\Gd, Phalcon\Image\Adapter\Imagick ([#902](https://github.com/phalcon/cphalcon/issues/902), [#1025](https://github.com/phalcon/cphalcon/issues/1025), [#1030](https://github.com/phalcon/cphalcon/issues/1030), [#1041](https://github.com/phalcon/cphalcon/issues/1041), [#1050](https://github.com/phalcon/cphalcon/issues/1050), [#1063](https://github.com/phalcon/cphalcon/issues/1063), [#1076](https://github.com/phalcon/cphalcon/issues/1076), [#1081](https://github.com/phalcon/cphalcon/issues/1081), [#1114](https://github.com/phalcon/cphalcon/issues/1114), [#1120](https://github.com/phalcon/cphalcon/issues/1120), [#1158](https://github.com/phalcon/cphalcon/issues/1158), [#1195](https://github.com/phalcon/cphalcon/issues/1195), [#1206](https://github.com/phalcon/cphalcon/issues/1206), [#1214](https://github.com/phalcon/cphalcon/issues/1214), [#1370](https://github.com/phalcon/cphalcon/issues/1370))
 - Phalcon\Logger:
   - Added FirePHP Log Adapter and Formatter ([#845](https://github.com/phalcon/cphalcon/issues/845), [#1333](https://github.com/phalcon/cphalcon/issues/1333), [#1483](https://github.com/phalcon/cphalcon/issues/1483))
   - Implemented Phalcon\Logger\Adapter::isTransaction() ([#1238](https://github.com/phalcon/cphalcon/issues/1238))
   - Fixed a bug preventing the EMERGENCY log type from being displayed correctly ([#1498](https://github.com/phalcon/cphalcon/issues/1498))
   - Added Phalcon\Logger\Adapter\File::getPath() ([#1495](https://github.com/phalcon/cphalcon/issues/1495), [#1508](https://github.com/phalcon/cphalcon/issues/1508))
   - Phalcon\Logger optimizations ([#1716](https://github.com/phalcon/cphalcon/issues/1716))
   - Phalcon\Logger\Adapter::setLogLevel() is honored by transactions ([#1716](https://github.com/phalcon/cphalcon/issues/1716))
   - Phalcon\Logger\Adapter::commit() now clears the queue ([#1742](https://github.com/phalcon/cphalcon/issues/1742))
   - Phalcon\Logger\Adapter now implements Phalcon\Logger\AdapterInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Logger\Formatter now implements Phalcon\Logger\FormatterInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Logger\Adapter and Phalcon\Logger\AdapterInterface are now PSR-3 compliant ([#1873](https://github.com/phalcon/cphalcon/issues/1873), [#1888](https://github.com/phalcon/cphalcon/issues/1888))
   - Added Phalcon\Logger\Adapter::critical() method ([#1888](https://github.com/phalcon/cphalcon/issues/1888))
   - For PHP 5.3.9+ when phalcon.register_psr3_classes php.ini option is set, Phalcon\Logger\Adapter implements Psr\Log\LoggerInterface ([#1888](https://github.com/phalcon/cphalcon/issues/1888))
   - When phalcon.register_psr3_classes php.ini option is set, Phalcon\Logger\Adapter and derived classes throw Psr\Log\InvalidArgumentException
     instead of Phalcon\Logger\Exception when the arguments are not valid ([#1888](https://github.com/phalcon/cphalcon/issues/1888))
 - Phalcon\Mvc:
   - Added support for route names in Phalcon\Mvc\Micro\Collection ([#1868](https://github.com/phalcon/cphalcon/issues/1868))
   - Phalcon\Mvc\Application::handle() now checks whether the class exists before include()'ing its file ([#812](https://github.com/phalcon/cphalcon/issues/812), [#818](https://github.com/phalcon/cphalcon/issues/818))
   - Phalcon\Mvc\Model\Criteria::fromInput() now sets _modelName ([#866](https://github.com/phalcon/cphalcon/issues/866), [#873](https://github.com/phalcon/cphalcon/issues/873))
   - Phalcon\Mvc\Model\Query\Builder may now use both integer and string placeholders ([#701](https://github.com/phalcon/cphalcon/issues/701))
   - Mvc\Model\getMessages() is filterable now ([#885](https://github.com/phalcon/cphalcon/issues/885))
   - Fixed hasManyToMany relation implementation ([#938](https://github.com/phalcon/cphalcon/issues/938))
   - Fixed regular expression in \Phalcon\Mvc\Model\Validator\Email ([#1243](https://github.com/phalcon/cphalcon/issues/1243))
   - Phalcon\Mvc\Model::hasOne/hasMany/belongsTo/hasManyToMany/addBehavior() are now public methods ([#1166](https://github.com/phalcon/cphalcon/issues/1166))
   - Added Phalcon\Mvc\Model\Row::toArray() method ([#1506](https://github.com/phalcon/cphalcon/issues/1506))
   - Phalcon\Mvc\Model\Validator::getOption() returns NULL if the option does not exist ([#1530](https://github.com/phalcon/cphalcon/issues/1530))
   - Bug with a custom Events Manager in Phalcon\Mvc\Models ([#1314](https://github.com/phalcon/cphalcon/issues/1314))
   - Phalcon\Mvc\Model\Query\Builder::__construct() does not ignore joins anymore ([#1327](https://github.com/phalcon/cphalcon/issues/1327))
   - Fixed HAVING handling in Phalcon\Mvc\Model\Query\Builder ([#1396](https://github.com/phalcon/cphalcon/issues/1396))
   - Micro Collections return Phalcon\Mvc\Micro\CollectionInterface ([#1130](https://github.com/phalcon/cphalcon/issues/1130))
   - Phalcon\Mvc\Url::get() can append query params ([#723](https://github.com/phalcon/cphalcon/issues/723), [#877](https://github.com/phalcon/cphalcon/issues/877))
   - Regular Expression Optimization for Phalcon\Mvc\Router ([#977](https://github.com/phalcon/cphalcon/issues/977))
   - PHQL: added placeholders support to LIMIT ([#1023](https://github.com/phalcon/cphalcon/issues/1023))
   - Added Phalcon\Mvc\Router::getDefautXXX() methods ([#1087](https://github.com/phalcon/cphalcon/issues/1087))
   - Allow HAVING without GROUP BY in query builder ([#1115](https://github.com/phalcon/cphalcon/issues/1115))
   - mvc/model/query.c optimizations ([#1129](https://github.com/phalcon/cphalcon/issues/1129), [#1132](https://github.com/phalcon/cphalcon/issues/1132))
   - Added support for array(limit, offset) as a 'limit' constructor key in Query Builder ([#1208](https://github.com/phalcon/cphalcon/issues/1208))
   - Added support for 'conditions' in Phalcon\Mvc\Model\Query\Builder::__construct() ([#1236](https://github.com/phalcon/cphalcon/issues/1236))
   - Added Phalcon\Mvc\View::isDisabled(), Phalcon\Mvc\View::getRenderLevel(), Phalcon\Mvc\View::getDisabledLevels() ([#907](https://github.com/phalcon/cphalcon/issues/907), [#1320](https://github.com/phalcon/cphalcon/issues/1320))
   - Added Phalcon\Mvc\View::getCurrentRenderLevel() ([#907](https://github.com/phalcon/cphalcon/issues/907), [#1326](https://github.com/phalcon/cphalcon/issues/1326))
   - Bug fix in Phalcon\Mvc\Model\Resultset\Simple::toArray() ([#1377](https://github.com/phalcon/cphalcon/issues/1377))
   - Bug fixes in Volt compiler ([#1387](https://github.com/phalcon/cphalcon/issues/1387))
   - Volt compiler optimizations ([#1729](https://github.com/phalcon/cphalcon/issues/1729))
   - Phalcon\Mvc\Model\Query\Builder optimizations ([#1414](https://github.com/phalcon/cphalcon/issues/1414))
   - Allow to set dirs without trailing slashes in Phalcon\Mvc\View ([#406](https://github.com/phalcon/cphalcon/issues/406), [#1440](https://github.com/phalcon/cphalcon/issues/1440))
   - Phalcon\Mvc\Model\Validator::getOption() returns null if option does not exists ([#1531](https://github.com/phalcon/cphalcon/issues/1531))
   - Added Phalcon\Mvc\Model::selectWriteConnection() ([#1519](https://github.com/phalcon/cphalcon/issues/1519))
   - Added Phalcon\Mvc\Router\Group::convert()/getConverters() ([#1555](https://github.com/phalcon/cphalcon/issues/1555), [#1572](https://github.com/phalcon/cphalcon/issues/1572))
   - Added Phalcon\Mvc\Router\Route::getGroup() ([#1682](https://github.com/phalcon/cphalcon/issues/1682))
   - Added Phalcon\Mvc\Router\Group::getName() and setName() ([#1682](https://github.com/phalcon/cphalcon/issues/1682))
   - Faster Phalcon\Mvc\Model\Row ([#1606](https://github.com/phalcon/cphalcon/issues/1606))
   - Optimized Phalcon\Mvc\Router\Group ([#1682](https://github.com/phalcon/cphalcon/issues/1682))
   - Bug fix: no arguments were passed to beforeMatch handler in Phalcon\Mvc\Router ([#1556](https://github.com/phalcon/cphalcon/issues/1556))
   - Added diagnostics when a validator returns false but does not call appendMessage() ([#1664](https://github.com/phalcon/cphalcon/issues/1664))
   - Fixed handling of numeric namespaces/modules/controllers/actions ([#1688](https://github.com/phalcon/cphalcon/issues/1688))
   - Added Phalcon\Mvc\View::exists() and Phalcon\Mvc\View(\Simple)::getRegisteredEngines() ([#1707](https://github.com/phalcon/cphalcon/issues/1707))
   - Volt: fixed bug in email_filed() ([#1723](https://github.com/phalcon/cphalcon/issues/1723))
   - Fixed deprecation warnings in Phalcon\Mvc\Collection::save() and Phalcon\Mvc\Collection::delete() ([#1783](https://github.com/phalcon/cphalcon/issues/1783))
   - Phalcon\Mvc\Model\Behavior now implements Phalcon\Mvc\Model\BehaviorInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Mvc\Model\Metadata now implements Phalcon\Mvc\Model\MetadataInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Mvc\Model\Validator now implements Phalcon\Mvc\Model\ValidatorInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Mvc\View\Engine now implements Phalcon\Mvc\View\EngineInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Mvc\Model\Validator::getOption()/getOptions()/isSetOption() methods are now public ([#1904](https://github.com/phalcon/cphalcon/issues/1904))
   - Phalcon\Mvc\Model::findFirst() now works when phqlLiterals is false ([#886](https://github.com/phalcon/cphalcon/issues/886))
   - Fixed notices when phalcon.orm.column_renaming is 0 ([#1801](https://github.com/phalcon/cphalcon/issues/1801))
   - Implemented reset() for metadata adapters other than memory ([#1934](https://github.com/phalcon/cphalcon/issues/1934))
   - Relaxed the requirement for the route to start with a slash ([#1938](https://github.com/phalcon/cphalcon/issues/1938))
   - Phalcon\Mvc\Router\Group: merge slashes when the route prefix ends and the route pattern starts with a slash ([#1938](https://github.com/phalcon/cphalcon/issues/1938))
   - Phalcon\Mvc\Model\Criteria::fromInput() now works with column maps ([#1903](https://github.com/phalcon/cphalcon/issues/1903))
 - Phalcon\Paginator:
   - Phalcon\Paginator\Adapter\Model returns correct results even when page number is incorrect ([#1654](https://github.com/phalcon/cphalcon/issues/1654))
   - Optimized Phalcon\Paginator\Adapter\QueryBuilder ([#1632](https://github.com/phalcon/cphalcon/issues/1632))
   - setCurrentPage() returns $this for all adapters ([#1633](https://github.com/phalcon/cphalcon/issues/1633))
   - Optimized Phalcon\Paginator\Adapter\NativeArray ([#1653](https://github.com/phalcon/cphalcon/issues/1653))
 - Phalcon\Queue:
   - Fixed bug in Phalcon\Queue\Beanstalk::read() ([#1348](https://github.com/phalcon/cphalcon/issues/1348), [#1612](https://github.com/phalcon/cphalcon/issues/1612))
   - Bug fixes in beanstalkd protocol implementation ([#1650](https://github.com/phalcon/cphalcon/issues/1650))
   - Optimizations ([#1621](https://github.com/phalcon/cphalcon/issues/1621))
   - Added peekDelayed() and peekburied() to Phalcon\Queue\Beanstalk ([#1650](https://github.com/phalcon/cphalcon/issues/1650))
   - Added kick(), bury(), release(), touch() to Phalcon\Queue\Beanstalk\Job ([#1650](https://github.com/phalcon/cphalcon/issues/1650))
 - Phalcon\Registry ([#1209](https://github.com/phalcon/cphalcon/issues/1209), [#1935](https://github.com/phalcon/cphalcon/issues/1935))
 - Phalcon\Security:
   - Phalcon\Security\Exception inherits from Phalcon\Exception, not from \Phalcon\Di\Exception
   - Added Phalcon\Security::computeHmac() ([#1347](https://github.com/phalcon/cphalcon/issues/1347))
   - Bug fixes ([#1347](https://github.com/phalcon/cphalcon/issues/1347))
   - Constant-time string comparison in Phalcon\Security::checkHash() to prevent timing attacks ([#1755](https://github.com/phalcon/cphalcon/issues/1755))
   - Phalcon\Security::checkHash() now correctly handles non-bcrypt hashes ([#1912](https://github.com/phalcon/cphalcon/issues/1912))
   - Support all hashes supported by crypt() in Phalcon\Security::hash() ([#1971](https://github.com/phalcon/cphalcon/issues/1971))
   - Phalcon\Security::getSaltBytes() dies not require OpenSSL anymore ([#1971](https://github.com/phalcon/cphalcon/issues/1971))
 - Phalcon\Session:
   - Fix Phalcon\Session\Bag::remove() ([#1637](https://github.com/phalcon/cphalcon/issues/1637))
   - Add remove() to Phalcon\Session\BagInterface ([#1917](https://github.com/phalcon/cphalcon/issues/1917))
   - Phalcon\Session\Adapter::get() may optionally remove the data from session ([#1358](https://github.com/phalcon/cphalcon/issues/1358))
   - Phalcon\Session\Adapter optimizations ([#1624](https://github.com/phalcon/cphalcon/issues/1624))
   - Phalcon\Session\Adapter::__destruct() now calls session_write_close() ([#1624](https://github.com/phalcon/cphalcon/issues/1624))
   - Phalcon\Session\AdapterInterface is compatible with SessionHandlerInterface ([#1108](https://github.com/phalcon/cphalcon/issues/1108))
   - Phalcon\Session\Adapter now implements Phalcon\Session\AdapterInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
   - Phalcon\Session\Bag::__get() now returns by reference (unlike get()) ([#1895](https://github.com/phalcon/cphalcon/issues/1895))
   - Phalcon\Session\Bag implements ArrayAccess, Countable, IteratorAggregate interfaces ([#1917](https://github.com/phalcon/cphalcon/issues/1917))
   - Phalcon\Session\Adapter implements ArrayAccess, Countable, IteratorAggregate interfaces ([#1917](https://github.com/phalcon/cphalcon/issues/1917))
   - Optimized Phalcon\Session\Adapter using object handlers ([#1917](https://github.com/phalcon/cphalcon/issues/1917))
 - Phalcon\Tag:
   - Fixed bugs ([#903](https://github.com/phalcon/cphalcon/issues/903))
   - Fixed radio button generation ([#947](https://github.com/phalcon/cphalcon/issues/947))
   - Fixed inconsistent behavior of setAutoescape() ([#1263](https://github.com/phalcon/cphalcon/issues/1263))
   - Added missing HTML5 input types ([#824](https://github.com/phalcon/cphalcon/issues/824), [#1323](https://github.com/phalcon/cphalcon/issues/1323))
   - Added Phalcon\Tag::setTitleSeparator() ([#1365](https://github.com/phalcon/cphalcon/issues/1365))
   - Added support for <optgroup> ([#1422](https://github.com/phalcon/cphalcon/issues/1422))
   - Fixed inconsistency in Tag::stylesheetLink/javascriptInclude w.r.t. local URLs ([#1486](https://github.com/phalcon/cphalcon/issues/1486))
 - Phalcon\Translate:
   - Optimized Phalcon\Translate\Adapter, Phalcon\Translate\Adapter\NativeArray by using object handlers ([#1668](https://github.com/phalcon/cphalcon/issues/1668))
   - Phalcon\Translate\Adapter\NativeArray::query() now replaces placeholders even if the string is not found in the language content ([#2044](https://github.com/phalcon/cphalcon/issues/2044))
 - Phalcon\Validation:
   - Added support for error codes ([#1171](https://github.com/phalcon/cphalcon/issues/1171))
   - Bug fixes ([#1399](https://github.com/phalcon/cphalcon/issues/1399))
   - Optimized Phalcon\Validation\Message\Group by using native iterators ([#1657](https://github.com/phalcon/cphalcon/issues/1657))
   - Optimized Phalcon\Validation\Message\Group by using object handlers ([#1765](https://github.com/phalcon/cphalcon/issues/1765))
   - Phalcon\Validation\Validator now implements Phalcon\Validation\ValidatorInterface ([#1852](https://github.com/phalcon/cphalcon/issues/1852))
 - Psr\Log:
   - when phalcon.register_psr3_classes php.ini option is set, Psr\Log\LoggerAwareInterface, Psr\Log\LoggerInterface,
     Psr\Log\AbstractLogger, Psr\Log\InvalidArgumentException, Psr\Log\LogLevel, Psr\Log\NullLogger,
     Psr\Log\LoggerAwareTrait (PHP 5.4+), Psr\Log\LoggerTrait (PHP 5.4+) are registered as internal interfaces/classes/traits
     by Phalcon ([#1888](https://github.com/phalcon/cphalcon/issues/1888))
 - Unit tests:
   - Travis CI imporvements ([#819](https://github.com/phalcon/cphalcon/issues/819), [#846](https://github.com/phalcon/cphalcon/issues/846), [#949](https://github.com/phalcon/cphalcon/issues/949))
   - Use markTestSkipped() instead of echo ([#862](https://github.com/phalcon/cphalcon/issues/862))
   - Do not run APC tests under CLI when apc.enable_cli is 0 ([#1449](https://github.com/phalcon/cphalcon/issues/1449))
   - Added new tests ([#865](https://github.com/phalcon/cphalcon/issues/865), [#1256](https://github.com/phalcon/cphalcon/issues/1256), [#1260](https://github.com/phalcon/cphalcon/issues/1260), [#1339](https://github.com/phalcon/cphalcon/issues/1339), [#1560](https://github.com/phalcon/cphalcon/issues/1560), [#1563](https://github.com/phalcon/cphalcon/issues/1563))
   - Skip database tests when the DBMS is not available ([#970](https://github.com/phalcon/cphalcon/issues/970))
   - Support for optional RVO ([#1147](https://github.com/phalcon/cphalcon/issues/1147))
   - Added support for test coverage visualization ([#1307](https://github.com/phalcon/cphalcon/issues/1307), [#1361](https://github.com/phalcon/cphalcon/issues/1361))
   - Bug fixes in tests ([#1313](https://github.com/phalcon/cphalcon/issues/1313), [#1334](https://github.com/phalcon/cphalcon/issues/1334), [#1335](https://github.com/phalcon/cphalcon/issues/1335), [#1449](https://github.com/phalcon/cphalcon/issues/1449), [#1467](https://github.com/phalcon/cphalcon/issues/1467))
 - Documentation bug fixes ([#1069](https://github.com/phalcon/cphalcon/issues/1069), [#1070](https://github.com/phalcon/cphalcon/issues/1070), [#1072](https://github.com/phalcon/cphalcon/issues/1072), [#1145](https://github.com/phalcon/cphalcon/issues/1145), [#1146](https://github.com/phalcon/cphalcon/issues/1146), [#1205](https://github.com/phalcon/cphalcon/issues/1205), [#1372](https://github.com/phalcon/cphalcon/issues/1372), [#1397](https://github.com/phalcon/cphalcon/issues/1397), [#1521](https://github.com/phalcon/cphalcon/issues/1521), [#1523](https://github.com/phalcon/cphalcon/issues/1523), [#1586](https://github.com/phalcon/cphalcon/issues/1586), lots of them)
 - Refactored, improved and optimized build script ([#1218](https://github.com/phalcon/cphalcon/issues/1218))
 - Other bug fixes ([#1051](https://github.com/phalcon/cphalcon/issues/1051), [#1131](https://github.com/phalcon/cphalcon/issues/1131), [#1040](https://github.com/phalcon/cphalcon/issues/1040), [#1275](https://github.com/phalcon/cphalcon/issues/1275), [#1392](https://github.com/phalcon/cphalcon/issues/1392), [#1396](https://github.com/phalcon/cphalcon/issues/1396), [#1399](https://github.com/phalcon/cphalcon/issues/1399), [#1425](https://github.com/phalcon/cphalcon/issues/1425), [#1426](https://github.com/phalcon/cphalcon/issues/1426)...)

# [1.2.6](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.6) (2014-01-26)
 - Phalcon\Security::checkHash() now correctly handles non-bcrypt hashes ([#1912](https://github.com/phalcon/cphalcon/issues/1912))

# [1.2.5](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.5) (2014-01-13)
 - Http\Cookie::__toString() will not throw exceptions ([#1427](https://github.com/phalcon/cphalcon/issues/1427))
 - Phalcon\Http\Cookie::__toString() will return a string value ([#1428](https://github.com/phalcon/cphalcon/issues/1428))
 - Camelize does not ignore the last character of a string anymore ([#1436](https://github.com/phalcon/cphalcon/issues/1436))
 - APC tests do not run under CLI when apc.enable_cli is 0 ([#1449](https://github.com/phalcon/cphalcon/issues/1449))
 - Phalcon\Debug::uri now supports both http and https ([#987](https://github.com/phalcon/cphalcon/issues/987))
 - Fixed inconsistency in Tag::stylesheetLink/javascriptInclude w.r.t. local URLs ([#1486](https://github.com/phalcon/cphalcon/issues/1486))
 - Fixed bug in Phalcon\Queue\Beanstalk::read() ([#1348](https://github.com/phalcon/cphalcon/issues/1348), [#1612](https://github.com/phalcon/cphalcon/issues/1612))
 - Phalcon\Flash\Session::getMessages() incorrectly removed all messages ([#1575](https://github.com/phalcon/cphalcon/issues/1575))
 - Fixed bug in phalcon_fix_path() ([#1601](https://github.com/phalcon/cphalcon/issues/1601))
 - Added Phalcon\Mvc\Model\Row::toArray() method ([#1506](https://github.com/phalcon/cphalcon/issues/1506))
 - Added support for POINT type in MySQL ([#1536](https://github.com/phalcon/cphalcon/issues/1536))
 - Phalcon\Mvc\Model\Validator::getOption() returns NULL if the option does not exist ([#1530](https://github.com/phalcon/cphalcon/issues/1530))
 - Fixed parsing of annotations containing / ([#1480](https://github.com/phalcon/cphalcon/issues/1480))
 - Make sure that 'persistent' is resolved only when accessed for the first time ([#1637](https://github.com/phalcon/cphalcon/issues/1637))
 - Fix Phalcon\Session\Bag::remove() ([#1637](https://github.com/phalcon/cphalcon/issues/1637))
 - Bug fixes in beanstalkd protocol implementation
 - Phalcon\Paginator\Adapter\Model returns correct results even when page number is incorrect ([#1654](https://github.com/phalcon/cphalcon/issues/1654))
 - Bug fix: no arguments were passed to beforeMatch handler in Phalcon\Mvc\Router ([#1556](https://github.com/phalcon/cphalcon/issues/1556))
 - Phalcon\Logger\Adapter::setLogLevel() is honored by transactions ([#1716](https://github.com/phalcon/cphalcon/issues/1716))
 - Bug fixes in Phalcon\Db\Adapter\Pdo::describeColumns() ([#1562](https://github.com/phalcon/cphalcon/issues/1562))
 - Phalcon\Session\Adapter::__destruct() now calls session_write_close() ([#1624](https://github.com/phalcon/cphalcon/issues/1624))
 - Volt: fixed bug in email_filed() ([#1723](https://github.com/phalcon/cphalcon/issues/1723))
 - Fixed PHP Notices in Phalcon\Debug::onUncaughtException() ([#1683](https://github.com/phalcon/cphalcon/issues/1683))
 - Phalcon\Logger\Adapter::commit() clears the queue ([#1748](https://github.com/phalcon/cphalcon/issues/1748))
 - Constant-time string comparison in Phalcon\Security::checkHash() ([#1755](https://github.com/phalcon/cphalcon/issues/1755))
 - Fix phalcon_escape_multi() to generate valid UTF-8 ([#1681](https://github.com/phalcon/cphalcon/issues/1681))

# [1.2.4](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.4) (2013-10-23)
 - Fixed broken ACL inheritance ([#905](https://github.com/phalcon/cphalcon/issues/905))
 - Fixed crash while rendering element's label ([#1210](https://github.com/phalcon/cphalcon/issues/1210))
 - Fixed XSS vulnerabilities ([#1216](https://github.com/phalcon/cphalcon/issues/1216), [#1190](https://github.com/phalcon/cphalcon/issues/1190))
 - Added support for APCu 4.0.2+ ([#1234](https://github.com/phalcon/cphalcon/issues/1234))
 - Fixed chaining of CSS/JS filters ([#1198](https://github.com/phalcon/cphalcon/issues/1198))
 - Fixed notices and warnings with complex PHQL queries ([#1222](https://github.com/phalcon/cphalcon/issues/1222))
 - Memory allocation optimizations ([#1220](https://github.com/phalcon/cphalcon/issues/1220))
 - Fixed regular expression in \Phalcon\Mvc\Model\Validator\Email ([#1243](https://github.com/phalcon/cphalcon/issues/1243))
 - Documentation bug fixes
 - Phalcon\Mvc\Model::hasOne/hasMany/belongsTo/hasManyToMany/addBehavior() are now public methods ([#1166](https://github.com/phalcon/cphalcon/issues/1166))
 - Added support for MySQL DOUBLE type ([#1128](https://github.com/phalcon/cphalcon/issues/1128))
 - Added support for UTF-8 characters in jsmin
 - Added support for UTF-8 to \Phalcon\Debug ([#1099](https://github.com/phalcon/cphalcon/issues/1099))
 - Fixed regression in \Phalcon\Http\Request::getRawBody() ([#1091](https://github.com/phalcon/cphalcon/issues/1091))
 - Implemented \Phalcon\Cache\Backend\Memory::queryKeys() ([#1093](https://github.com/phalcon/cphalcon/issues/1093))
 - Redirects use status descriptions from RFC 2616 ([#1175](https://github.com/phalcon/cphalcon/issues/1175))
 - \Phalcon\Config::merge now works with derived classes ([#1024](https://github.com/phalcon/cphalcon/issues/1024))
 - \Phalcon\Security::checkHash() allows to restrict the length of the password to avoid attacks like https://www.djangoproject.com/weblog/2013/sep/15/security/
 - \Phalcon\Config can now be cloned ([#1277](https://github.com/phalcon/cphalcon/issues/1277))
 - \Phalcon\Mvc\Query\Builder::__construct() ignores joins ([#1327](https://github.com/phalcon/cphalcon/issues/1327))
 - Bug with a custom Events Manager in Phalcon\Mvc\Models ([#1314](https://github.com/phalcon/cphalcon/issues/1314))
 - Micro Collections return Phalcon\Mvc\Micro\CollectionInterface ([#1130](https://github.com/phalcon/cphalcon/issues/1130))
 - \Phalcon\Forms\Form::getMessages() does not generate a fatal error if the form is valid ([#1349](https://github.com/phalcon/cphalcon/issues/1349))
 - Fixed memory leaks ([#1345](https://github.com/phalcon/cphalcon/issues/1345))
 - Fixed invalid memory reads/writes across the code ([#1340](https://github.com/phalcon/cphalcon/issues/1340))
 - Fixed HAVING handling in Phalcon\Mvc\QueryBuilder ([#1396](https://github.com/phalcon/cphalcon/issues/1396))
 - Bug fixes in \Phalcon\Logger\{Adapter,Formatter}\FirePhp ([#1333](https://github.com/phalcon/cphalcon/issues/1333))
 - Bug fixes in Phalcon\Cache\Backend\Xcache ([#1406](https://github.com/phalcon/cphalcon/issues/1406))
 - Phalcon\Forms\Element::__toString() does not throw exceptions anymore ([#1413](https://github.com/phalcon/cphalcon/issues/1413))
 - Other bug fixes ([#947](https://github.com/phalcon/cphalcon/issues/947), [#1131](https://github.com/phalcon/cphalcon/issues/1131), [#1040](https://github.com/phalcon/cphalcon/issues/1040), [#1275](https://github.com/phalcon/cphalcon/issues/1275), [#1392](https://github.com/phalcon/cphalcon/issues/1392), [#1396](https://github.com/phalcon/cphalcon/issues/1396), [#1399](https://github.com/phalcon/cphalcon/issues/1399), backported patches from 1.3.0 etc)

# [1.2.3](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.3) (2013-08-16)
 - Security fixes ([#1144](https://github.com/phalcon/cphalcon/issues/1144))

# [1.2.2](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.2) (2013-08-06)
 - Phalcon\Mvc\Model\Query\Builder may now use both integer and string placeholders ([#701](https://github.com/phalcon/cphalcon/issues/701))
 - Fixed invalid memory reads when GC is on ([#469](https://github.com/phalcon/cphalcon/issues/469), [#927](https://github.com/phalcon/cphalcon/issues/927))
 - Phalcon\Flash\Session::getMessage('key') returns now an empty array if the key is not found ([#908](https://github.com/phalcon/cphalcon/issues/908), [#920](https://github.com/phalcon/cphalcon/issues/920))
 - Fixed bugs in Phalcon\Escaper ([#917](https://github.com/phalcon/cphalcon/issues/917))
 - Fixed memory leaks for PHP < 5.4 ([#910](https://github.com/phalcon/cphalcon/issues/910), [#914](https://github.com/phalcon/cphalcon/issues/914), [#916](https://github.com/phalcon/cphalcon/issues/916))
 - Fixed memory access violations ([#911](https://github.com/phalcon/cphalcon/issues/911), [#918](https://github.com/phalcon/cphalcon/issues/918), [#927](https://github.com/phalcon/cphalcon/issues/927), [#928](https://github.com/phalcon/cphalcon/issues/928))
 - Memory allocation optimizations ([#912](https://github.com/phalcon/cphalcon/issues/912))

# [1.2.1](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.1) (2013-07-25)
 - Reduced overall memory usage ([#834](https://github.com/phalcon/cphalcon/issues/834), [#891](https://github.com/phalcon/cphalcon/issues/891), [#893](https://github.com/phalcon/cphalcon/issues/893))
 - Faster internal array and string manipulation ([#830](https://github.com/phalcon/cphalcon/issues/830), [#833](https://github.com/phalcon/cphalcon/issues/833), [#837](https://github.com/phalcon/cphalcon/issues/837))
 - Fixed PHP 5.5 compilation on Windows
 - Dispatching parameters now can be modified in 'beforeExecuteRoute' events
 - 'beforeException' events can now handle exceptions occurred when executing actions ([#140](https://github.com/phalcon/cphalcon/issues/140))
 - Added Phalcon\Dispatcher::getHandlerClass and Phalcon\Dispatch::getActionMethod
 - Phalcon\Form\Element\* classes now implement Phalcon\Form\ElementInterface
 - Phalcon\Config\Adapter\Ini correctly handles empty sections and INI files without any sections ([#829](https://github.com/phalcon/cphalcon/issues/829), [#837](https://github.com/phalcon/cphalcon/issues/837))
 - Phalcon\Http\Request fully supports file arrays ([#884](https://github.com/phalcon/cphalcon/issues/884), [#888](https://github.com/phalcon/cphalcon/issues/888))
 - Added support for various padding schemes (PKCS7, ANSI X.923, ISO 10126, ISO/IEC 7816-4, zero padding, space padding) to Phalcon\Crypt ([#864](https://github.com/phalcon/cphalcon/issues/864), [#887](https://github.com/phalcon/cphalcon/issues/887))
 - Added getKey(), getError(), isUploadedFile() methods to Phalcon\Http\Request\File ([#878](https://github.com/phalcon/cphalcon/issues/878), [#888](https://github.com/phalcon/cphalcon/issues/888))
 - Dot-delimited directives in INI-files are now prsed correctly ([#872](https://github.com/phalcon/cphalcon/issues/872))
 - Fixed memory leaks in cache backends ([#860](https://github.com/phalcon/cphalcon/issues/860))
 - Fixed various memory corruption issues ([#849](https://github.com/phalcon/cphalcon/issues/849), [#852](https://github.com/phalcon/cphalcon/issues/852), [#858](https://github.com/phalcon/cphalcon/issues/858), [#860](https://github.com/phalcon/cphalcon/issues/860), [#861](https://github.com/phalcon/cphalcon/issues/861))
 - Fixed broken Phalcon\Http\Response::setFileToSend() method ([#831](https://github.com/phalcon/cphalcon/issues/831), [#832](https://github.com/phalcon/cphalcon/issues/832))
 - Phalcon\Http\Response::setFileToSend() can now show the file in the browser instead of offering to download it ([#853](https://github.com/phalcon/cphalcon/issues/853))
 - Added Phalcon\Adapter\Config\Json class to read JSON configs ([#844](https://github.com/phalcon/cphalcon/issues/844))
 - Added FirePHP Log Adapter and Formatter ([#845](https://github.com/phalcon/cphalcon/issues/845))
 - Faster Phalcon\Config implementation ([#837](https://github.com/phalcon/cphalcon/issues/837))
 - Phalcon\Config now support numeric properties as well ([#837](https://github.com/phalcon/cphalcon/issues/837))
 - Database dialects now support BOOLEAN data type ([#816](https://github.com/phalcon/cphalcon/issues/816))
 - Phalcon\Mvc\Application::handle() now checks whether the class exists before include()'ing its file ([#812](https://github.com/phalcon/cphalcon/issues/812), [#818](https://github.com/phalcon/cphalcon/issues/818))

# [1.2.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.2.0) (2013-07-10)
 - Now 'compiledPath' option accept a closure to dynamically create the compilation path in Volt
 - Volt now supports user extensions, these can be used to extend better Volt
 - Now Phalcon\Mvc\Url provides an internal separation for uris for static resources and uris to rewrite resources
 - Added Mvc\Model\Criteria::inWhere to append an IN expression to the criteria
 - Added Mvc\Model\Criteria::notInWhere to append a NOT IN expression to the criteria
 - Added Mvc\Model\Criteria::notBetweenWhere to append a NOT BETWEEN expression to the criteria
 - Added Mvc\Model\Criteria::betweenWhere to append a BETWEEN expression to the criteria
 - Phalcon\Tag::image accepts a second parameter to allow external URLs
 - Added Phalcon\Mvc\View\Simple as an alternative view component, this only have a single level of rendering and works better with Volt's inheritance
 - Better escaping of reserved words in internal PHQL generation
 - Added Phalcon\Http\Request::getJsonRawBody() to return the request body as a decoded JSON
 - Added Phalcon\Http\Request::getHeaders()
 - Support for many to many relations in the ORM
 - Added Phalcon\Assets\Filters\Jsmin to provide on-the-fly javascript minification
 - Added Phalcon\Assets\Filters\Cssmin to provide on-the-fly CSS minification
 - Support for real nested transactions in Phalcon\Db using database savepoints
 - Support for create/list/drop views in Phalcon\Db
 - Added event application:viewRender to Phalcon\Mvc\Application allowing the developer to call the $view->render method as he/she needs
 - Added option to disable literals in PHQL statements, this highly reduces the possibility
 to be attacked using SQL injections
 - Now you can pass an array of variables with virtual local scope in Phalcon\Mvc\View::partial()
 - Syntax CAST(expr AS datatype) is now supported by PHQL
 - Support for CONVERT(expr USING charset) in PHQL
 - Support for {% include "hello" with [var1, var2] %}
 - Phalcon\Mvc\Collection::find receives a parameter 'fields' to specify a list of fields
 - Added Phalcon\Forms\Element\Email and Phalcon\Tag::emailField
 - Support to define arrays using curly braces in Volt {'a': 'b', 'c': 'd'} in Volt
 - Support to make multiple assigments in a single set in Volt {% set a = b, c = d %} in Volt
 - Volt now support 'if'/'else' blocks with empty bodies
 - Support for 'cascade' action in addition to 'restrict' in Virtual Foreign Keys (ORM)
 - Added missing Phalcon\Http\Request\File::getType()
 - Phalcon\Tag is not abstract anymore allowing to create instances of it
 - Phalcon\Tag is now registered as 'tag' in Phalcon\Di\FactoryDefault
 - In a handler in Phalcon\Mvc\Micro returns an object that implements Phalcon\Http\ResponseInterface the response is automatically send()
 - Phalcon\Mvc\View now have a chaineable API
 - Phalcon\Mvc\Micro now can optionally receive the DI in its constructor
 - Now if a method receives an incorrect number of parameters an exception BadMethodCallException is thrown instead of a warning
 - Phalcon\Mvc\Model/Phalcon\Mvc\Collection now checks for a method 'onConstruct' allowing the developer to execute initialization stuff every time a model/collection instance is created
 - Phalcon\Mvc\Model/Phalcon\Mvc\Collection now checks for a method 'afterFetch' allowing the developer to execute initialization stuff every time a model/collection instance is created
 in a findFirst/find operation is created
 - Added Phalcon\Mvc\Collection::summatory easing the generation of this type of aggregation
 - Support for boolean literals in PHQL
 - Support for complex expressions in GROUP BY clauses in PHQL
 - Now PHQL exceptions include the PHQL statement itself
 - Aliases for namespaces are now supported in PHQL
 - Acl\Memory was rewritten to make it simpler and faster, you may regenerate your serialized ACLs
 - Support for assigment operators +=, -=, *=, /= in Volt
 - Support for Profile-Guided optimization installation scripts (See blog)
 - Added Phalcon\Annotations\Adapter\Xcache to store annotations in Xcache
 - Added Phalcon\Mvc\Model\Metadata\Xcache to store models meta-data in Xcache
 - Added
 - Now if a controller implements 'initialize' it only is called if 'beforeExecuteRoute' is not stopped
 - Listeners implementing 'beforeExecuteRoute'/'afterExecuteRoute' are executed first than the ones implemented as methods in the controller/task

# [1.1.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.1.0) (2013-05-08)
 - Improvements to the query builder allowing to define bound parameters in the "where" methods
 - Added Mvc\Model\Query\Builder::inWhere to append an IN expression to the query
 - Added Mvc\Model\Query\Builder::notInWhere to append a NOT IN expression to the query
 - Added Mvc\Model\Query\Builder::betweenWhere to append a BETWEEN expression to the query
 - Now Phalcon\Session\Bag injects automatically the default DI if one hasn't beed manually assigned
 - Added Phalcon\Forms\Manager to reference forms and retrieve them from any part of the application
 - If an element in Phalcon\Forms doesn't have a label defined now returns the element's name as label
 - Now if a validator in Phalcon\Validator has defined the option 'cancelOnFail' => true the validation
 will be aborted if the validator fails
 - Added Phalcon\Validation\Validator\Between to check a value between a range of two values
 - Added Phalcon\Validation\Validator\Confirmation to check that a value match its confirmation value (another attribute in the data to validate)
 - Phalcon\Forms\Form now extends from Phalcon\Di\Injectable allowing developers to use application services in the form initialization
 - Now calls to Phalcon\Mvc\Router can be chained
 - Phalcon\Mvc\Router::getRewriteUri is now public
 - Added Phalcon\Mvc\Router\Route::beforeMatch to implement arbitrary conditions to unmatch a matched route
 - Phalcon\Mvc\Model can be now set up to throw an exception when the saving process fails
 - Added Phalcon\Assets component to manage CSS/Javascripts resources in an application
 - Added Phalcon\Annotations\Collection::getAll to return all the annotations in a collection that matches a name
 - Added Phalcon\Crypt component to provide encryption facilities to phalcon applications
 - Now Phalcon\Http\Request: get, getQuery y getPost returns the respective superglobals in case of no parameters
 - Now Phalcon\Mvc\Router supports simple/regex hostname restrictions
 - Added support for filtering/sanitizing in Phalcon\Validation
 - Added events beforeValidation/afterValidation to Phalcon\Validation and Phalcon\Forms\Form
 - Added ability to register user-options in Phalcon\Forms\Form elements
 - Fixed Phalcon\Mvc\Micro\Collections to register a controllers in Phalcon\Mvc\Micro
 - Added Phalcon\Tag::dateField and Phalcon\Tag::numericField
 - Added Phalcon\Forms\Element\Date and Phalcon\Forms\Element\Numeric
 - Added Phalcon\Cache\Frontend\Json to cache data as JSON
 - Added Phalcon\Tag::tagHtml and Phalcon\Tag::tagHtmlClose to generate any kind of HTML tags
 - Phalcon\Http\Response\Cookies is now fixed
 - Added support for automatic crypting of cookies in Phalcon\Http\Response\Cookies
 - Phalcon\Di\FactoryDefault now provides the 'crypt' service
 - Volt's paths are now automatically normalized to realpaths
 - Fixed bug in convert_encoding in Volt
 - Added Phalcon\Filter\UserFilterInterface to be used in custom filters
 - Added support for filters in Phalcon\Forms\Form elements
 - Added maximum recursion depth exceeded control in Phalcon\Kernel
 - Performance: Now Phalcon makes use of interned strings if PHP 5.4 to reduce memory usage
 - Performance: Implemented cache of visibility for all intern properties in 5.3/5.4 increasing performance
 - Performance: All hash keys are now pre-calculated in compilation time to read/write internal properties faster
 - Performance: Now all functions are static allowing the compiler to inline functions or remove those that aren't used by the framework
 - Performance: Now Phalcon provides specific optimizations when the extension is compiled for NTS modules
 - Performance: Implemented function to fetch parameters from the VM stack with minimum overhead
 - Performance: Implemented a global PHQL parser cache to avoid that a same statement be parsed more than one time
 - Performance: Events by priority are now disabled by default. A user must explicitly define that Phalcon\Events\Manager must use a PriorityQueue instead of a FIFF (First In-First Fired)
 - !! Phalcon\CLI\Router API have been changed. Check the manual to update your bootstrap

# [1.0.1](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.0.1) (2013-04-08)
 - Paths aren't correctly normalized in Phalcon\Mvc\Model\MetaData\Files
 - Added extra class prefix to schema.table in Phalcon\Mvc\Model\MetaData to avoid multiple-database collisions
 - Now Phalcon\Mvc\Router ignores numeric paths in controller, namespace, module and action, avoiding that those will be passed to the dispatcher
 - Added Phalcon\Forms\Form::remove to remove an element from the form and Phalcon\Forms\Form::has to check if a form has an element

# [1.0.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v1.0.0) (2013-03-22)
 - Added Phalcon\Mvc\Router::setUriSource to set if the URI source must be $_GET['_url'] or $_SERVER['REQUEST_URI']
 - Added a white-list parameter to Phalcon\Mvc\Model::save(), Phalcon\Mvc\Model::create() and
 Phalcon\Mvc\Model::update() to avoid possible mass-assigment attacks
 - Added leftJoin/rightJoin to QueryBuilder

# 1.0.0b1
 - Fixed bug with missing blocks in multiple inheritance in Volt
 - Support for ternary operator in Volt
 - Support for 'forelse' in Volt
 - Added support for loop variable context in Volt
 - Added whitespace control delimiters {%- -%} and {{- -}} to Volt
 - Support for 'in' and 'not in' operators in Volt
 - Added Phalcon\Mvc\Model::assign to assign an array of values to a model instance
 - Added Phalcon\Mvc\Model::refresh to refresh the state of a model
 - Added Phalcon\Logger\Adapter::setLogLevel to filter messages with greater or less priority
 - Removed constructor from Phalcon\Cache\BackendInterface
 - Added Phalcon\Cache\Multiple, this backend writes to several backends, and reads data according to the order in which backends were registered.
 - Now a model can use a separate connection to read and another to write, this makes horizontal sharding easy
 - Now, a model could implement a method selectReadConnection to dynamically return the correct database according to the current query conditions
 - Added Phalcon\Cache\Backend\Memory to cache data in the current request
 - Added Phalcon\Validation, this component allows the validate a set of data based on pre-defined rules
 - Added Phalcon\Forms, this component acts as a forms builder binding request data to entities, aiding in the validation of data, helping in the errors/messages generated in the validation process
 - Phalcon\Db is now case-folding independent
 - Phalcon\Mvc\Model uses column names keeping the case-folding as they were defined
 - Added Phalcon\Mvc\Router::notFound to define the paths the router must use if any route is matched
 - Improved \Phalcon\Mvc\Router\Annotations to work better with controllers in namespaces and modules
 - A model can be marked to keep record snapshots allowing to check what fields have been changed
 - The _source and _schema properties have been moved from Phalcon\Mvc\Model to Phalcon\Mvc\Model\Manager. This allow set source/schema in the model initializer
 - Added Phalcon\Session\Bag::remove to remove an specific variable from a session bag
 - Added support for complex expressions in PHQL ORDER BY clause
 - Added support for complex expressions in PHQL GROUP BY clause
 - Added support for $_SERVER['REQUEST_URI'] if $_GET['_url'] is not available in Phalcon\Mvc\Router
 - Added an option to set up specific models with dynamic update instead of all-fields update, every field is checked if it was changed to dynamically create a UPDATE SQL column only with those fields that changed
 - Added a minimalist client for the Beanstalk queue server

# 0.9.0b2
 - Support for reusable records. A relation can be marked to cache queried records in memory to speedup getting related records
 - Added 'elseif' statement to Volt
 - Changed static key in Volt's 'cache' to any valid expression
 - Added Phalcon\Logger\Adapter\Syslog and Phalcon\Logger\Adapter\Stream to Phalcon\Logger
 - Added Phalcon\Logger\Multiple to send logs to multiples adapters
 - Added formatters abstraction to Phalcon\Logger, now including: Phalcon\Logger\Formatter\Line, Phalcon\Logger\Formatter\Json and Phalcon\Logger\Formatter\Syslog
 - Added Phalcon\Annotations\Adapter\Files to Phalcon\Annotations, this adapter stores annotations in PHP files

# 0.9.0b1
 - Added Phalcon\Annotations, a general purpose component to read annotations from docblocks
 - Phalcon\Mvc\Model now supports saving related records using magic methods with a unique call to 'save'
 - Adding autoescaping option to Phalcon\Tag
 - Added andWhere/orWhere to Phalcon\Mvc\Model\Criteria
 - Added passing an HTTP body to the Phalcon\Http\Response's constructor
 - Phalcon\Mvc\View is now able to pass variables to the views using magic methods
 - Support for slice with filter and built-in syntax in Volt
 - Added magic methods in the ORM to find/findFirst by a single field
 - Improved XSS protection in Phalcon\Tag
 - Implemented queuing events with priorities in Phalcon\Events
 - Implemented collecting of returned responses in Phalcon\Events
 - Added toArray method to Phalcon\Mvc\Model\Resultset classes
 - Added hydration modes to Phalcon\Mvc\Model\Resultset (HYDRATE_RECORDS, HYDRATE_ARRAYS, HYDRATE_OBJECTS)

# 0.8.0b1
 - Improved Phalcon\Escaper, this component provides contextual escaping of different kinds of texts (CSS, Javascript, URL, HTML Attributes etc)
 - Added serialization of Mvc\Collection instances
 - Added Phalcon\Mvc\View::setLayout to change the layout instead of looking for a controller with the same name as the latest controller dispatched
 - Now is possible to pass an option called 'options' to any of the Phalcon\Db\Adapter\Pdo adapters to set extra
 PDO options in the connection
 - Removed filtering of keys from Phalcon\Cache\Backend\File
 - Support for creating groups of routes using Phalcon\Router\Route\Group
 - Added Phalcon\Mvc\Micro middleware events
 - Implemented virtual scopes in Phalcon\Mvc\View

# 0.8.0a2
 - Added support for behaviors in the ORM including: Phalcon\Mvc\Model\Behavior\Timestampable and Phalcon\Mvc\Model\Behavior\SoftDelete
 - Improved serialization of Mvc\Model instances and complex resultsets
 - Added an option to change the layouts directory and partials directory in Phalcon\Mvc\View
 - Added an option to disable an specific level of rendering in Phalcon\Mvc\View
 - Added Phalcon\Mvc\Model::setup to globally enable/disable specific features in the ORM
 - Added Phalcon\Db::setup to globally enable/disable specific features in the database component
 - Added Phalcon\Mvc\Model\Resultset::delete to delete every complete object returned in a resultset using a transaction
 - Added Phalcon\Mvc\Model\Resultset::update to update every complete object returned in a resultset using a transaction
 - Added support for converters in Phalcon\Mvc\Router
 - Added Phalcon\Mvc\View::getRender to return contents of a template into a string
 - Added methods to support HTTP method PATCH
 - Now Phalcon\Mvc\Model uses the last part of a namespaced class name as source name
 - Phalcon\Di now implements ArrayAccess to get/set services
 - Phalcon\Mvc\Micro now implements ArrayAccess to get services from the related services container
 - Improved building of complex service definitions in the DI
 - Added toArray method to Phalcon\Mvc\Model instances
 - Added autoescape mode in Volt

# 0.8.0a1
 - Removed unnecessary intermediate zvals when retrieving array items reducing overall memory comsumption
 - Removed unnecessary intermediate zvals when retrieving object members reducing overall memory comsumption
 - Removed PH_CHECK constant making simpler calling functions and methods internally
 - Added Phalcon\Text::increment, Phalcon\Text::random, Phalcon\Text::lower, Phalcon\Text::upper, Phalcon\Text::startsWith, Phalcon\Text::endsWith
 - Added Phalcon\Config::merge to merge recursively a configuration with another one
 - Added Phalcon\Config::toArray method to recursively convert an object to an array
 - Improved Volt runtime error/syntax error messages including always line and file
 - Added Phalcon\Security providing a set of functions to improve the security in Phalcon applications like bcrypt password hashing and CSRF protection
 - Added Phalcon\Mvc\View\Engine\Volt\Compiler::addFunction to register user functions
 - Added Phalcon\Mvc\View\Engine\Volt\Compiler::addFilter to register user filters
 - Added Phalcon\Mvc\Model\Relation as class for model relationships
 - Added '[' and ']' as delimiters to escape PHQL reserverd words
 - Reduced memory usage in PHQL parser/tokenizer
 - Added support for aliasing of model relationships in Phalcon\Mvc\Model
 - Relationships in Models are now case insensitive to be compliant with the PHP standard
 - Looking for a relationship in the models manager now performs a search in O(1) order
 - Added "cache" statement in Volt to cache view fragments
 - Added "do" statement to Volt to execute an expression without printing its evaluated value
 - Added "include" statement to Volt to perform a statical include of other views in compiling time
 - Added an internal method cache to speed up overall execution
 - Reduced memory allocation when reading/writing properties from objects
 - Added missing Phalcon\Mvc\Collection::getMessages() and Phalcon\Mvc\Collection::appendMessage
 - Added Phalcon\Config::get method to obtain a value from the configuration object setting a default value
 - Added an optional default value to Phalcon\Session\Adapter::get if this method returns a null value
 - Added OO methods to Phalcon\Session\Bag::get
 - Added an optional default value to Phalcon\Session\Bag::get if this method returns a null value
 - Added multiple inheritance and two-way replacement of blocks in Volt
 - Added evaluation of "tests" to Volt
 - Added support to call methods and read properties in sub-objects in Volt
 - Volt now checks if a variable name is a registered service and injects it to the views
 - The "For" statement in Volt now supports get the current key and add an optional if evaluation
 - Added support to read PHP constants in Volt
 - Added "prefix" option to Volt, allowing prefixing the resulting compiled paths
 - Now registerAutoloader in module definitions receives the services container (DI) as first parameter
 - Fixed skipAttributes methods in Phalcon\Mvc\Model
 - Fixed use of muliples databases in the ORM
 - Fixed use of a common events manager databases in the ORM
 - Now Phalcon\Mvc\Router can be configured to remove extra slashes passed in the URI
 - In Phalcon\Mvc\Router the default route is '/' when none is giving


# [0.7.0](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v0.7.0) (2012-12-04)
 - Now the namespace can be set in a path of the route and it will passed automatically to the dispatcher
 - Implementing URL generation based on routes without regular expressions
 - Now is possible register a template engine in Phalcon\Mvc\View with an anonymous function
 - Passing 'compileAlways' => true as option for Volt makes that the templates will be always compiled instead of checking if they have changes
 - Now Phalcon\Cache\Backend adapters return false in the "exists" method if the cache has expired
 - Fixed bug in Phalcon\Db\Result\Pdo::seek when using bind parameters

# 0.7.0b1
 - Implemented a fast way to retrieve object's members without adding a memory frame
 - Now Phalcon\Mvc\Dispatcher checks for methods beforeExecuteRoute and afterExecuteRoute in the controller handler
 - Added phalcon_start_with to check if a zval string starts with other string avoiding substrs in PHP userland
 - Added interfaces to most classes helping the developer to easily create component replacements and add new adapters/classes
 - Implemented interfaces on their own components
 - Implemented event propagation, event cancelation and ability to stop events in EventsManager
 - Added Phalcon\Dispatcher::getDefaultNamespace
 - Added a $merge parameter to every Phalcon\Loader strategy to merge current values with a new array
 - Implemented registering services as "always shared"
 - Now Phalcon\Mvc\Model::save, Phalcon\Mvc\Model::create, Phalcon\Mvc\Model::update receives an array to assign the model's attributes from it
 - Support for UTF-8/UTF-16 characters on 32 bit platforms for PHQL/Volt parsers
 - Support for custom schemas in PHQL
 - Now is possible pass bound parameters to Phalcon\DB::fetchOne and Phalcon\Db::fetchAll
 - Implemented independent column map for models and a full escaping system for columns/tables/schemas according to the database system conventions
 - Added a $merge parameter to Phalcon\Mvc\Application::registerModules to merge new modules with current ones
 - Phalcon\Mvc\Application now allows registering a module using an anonymous function
 - Added Phalcon\Mvc\Model\Query\Builder aiding in the creation of PHQL queries using an OO interface
 - Support for COUNT(DISTINCT x) syntax in PHQL
 - Allowing user-defined messages in most Phalcon\Mvc\Model\Validators
 - Now Phalcon\Mvc\Model\Validator\StringLength uses mb_strlen when it is available
 - Allowed pass a URI manually to Phalcon\Mvc\Micro::handle()
 - Fixed missing json_encode filter in Volt
 - Moving cache implementation from Phalcon\Mvc\Model to Phalcon\Mvc\Model\Query, this allows caching both simple and complex resultsets
 - Added Phalcon\Paginator\Adapter\QueryBuilder to use a PHQL Query Builder as source of data
 - Added adapter for Oracle databases in Phalcon\Db

# [0.6.1](https://github.com/phalcon/cphalcon/releases/tag/phalcon-v0.6.1) (2012-11-15)
 - Fixed bug in Phalcon\Mvc\Micro's not-found handler
 - Fixed bug reading named-parameters with quantifiers in Phalcon\Mvc\Router
 - Now named-routes are processed without use regular expressions
 - Now $this->view->disable() disables the auto-rendering mode completely
 - Added Phalcon\Mvc\View::enable that re-enables the auto-rendering mode
 - Added Phalcon\Cache\Backend::stop() to stop the cache without store anything into the backend
 - Fixed bug in Phalcon\Mvc\View that saves an empty cached content when using a cache
 - Implemented Phalcon\Db::FETCH_OBJ to return objects instead of arrays

# 0.6.0
 - Added functions version, version_id, date and time to Volt
 - PHQL OFFSET complete implementation
 - Fixed bug in Phalcon\Mvc\Collection::find and Phalcon\Mvc\Collection::findFirst

# 0.6.0b1
 - Removing unnecessary duplications in zval PHALCON_GET_FOREACH_VALUE
 - Merging PHALCON_INIT_NVAR into PHALCON_GET_FOREACH_KEY
 - Added HTML/XHTML document type support in Phalcon\Tag
 - Added "exists" method to every backend in Phalcon\Cache\Backend
 - Now is required pass true as parameter to Phalcon\Http\Request::getClientAddress if the user want to check the client address in the $_SERVER['HTTP_X_FORWARDED_FOR'] header
 - Removed unnecessary duplication of function names when calling function and methods
 - Now Phalcon can call functions from the PHP userspace without use call_user_func_array/call_user_func increasing performance
 - Added beforeException event triggered from Phalcon\Dispatcher before launch an exception allowing injecting code before launch a real exception modifing the behavior of the component
 - Now is possible attach listeners directly to specific events in Phalcon\Event\Managers
 - Added Phalcon\Http\Request::get and Phalcon\Http\Request::has to read/check values from $_REQUEST
 - Added Phalcon\Cache\Backend\Mongo that uses a MongoDB collection as backend
 - Added options (compiled path, compiled separator, stat) for Volt

# 0.6.0a1
 - Concatenation on the same variable is now faster by using realloc instead of zval duplication
 - Some internal macros like PHALCON_INIT_VAR now produce fewer C-code making the extension lighter
 - Removed initialization of the memory stack frame when isn't needed
 - Inlining of scope locating functions to make read/write on objects faster
 - Array joins are now faster because a zval needle isn't needed anymore
 - Implemented fast copy/ctor to return_value reducing the overall memory usage
 - Added Phalcon\Tag::friendlyTitle to create friendly titles
 - Added a new C-based template engine highly coupled with Phalcon called Volt
 - Registered Phalcon\Mvc\Model\Transaction\Manager in Phalcon\Di\FactoryDefault as 'transactionManager'
 - Added Phalcon\Escaper to add contextual escaping of different kinds of texts
 - Registered Phalcon\Escaper in Phalcon\Di\FactoryDefault as 'escaper'
 - Phalcon\Tag now caches resolved services such as 'url' and 'dispatcher' making the view generation faster
 - Added support to the OFFSET clause in PHQL
 - Optimized Phalcon\Mvc\Model\Metadata to use fewer memory when using a high number of tables
 - Changed the use of strpos by phalcon_memnstr to search for strings into other strings reducing unnecessary zval allocations
 - Added faster camelize/uncamelize functions
 - Now a model can implement the method metaData to return the model meta-data insteaf of leave Phalcon do it automatically
 - Phalcon\Mvc\Model::skipAttributes allows setting a group of attributes that must be skipped from the INSERT/UPDATE SQL generation
 - Added Phalcon\Mvc\Collection to manage non-structured data models, for example: MongoDB

# 0.5.2
 - Fixed bug in Phalcon\Mvc\Model::_exists making PHQL inserts fail
 - Fixed bug passing extra parameters to Phalcon\Mvc\Model magic methods

# 0.5.1
 - Fixed bug in Phalcon\Loader producing that pathFound event wasn't triggered
 - Added throwing exception in Phalcon\Loader when trying to write in a read only file
 - Now Phalcon\Loader replaces _ by DIRECTORY_SEPARATOR in most strategies
 - Fixed bug in Phalcon\Mvc\Model\Resultset::seek that doesn't allow to paginate results in Phalcon\Paginator
 - Fixed bug in Phalcon\Mvc\Dispatcher that doesn't throws an exception when an infinite forward is produced
 - PDO error mode was changed to PDO::ERRMODE_EXCEPTION producing exceptions instead of silent error messages
 - Fixed wrong precedence in PHQL operators
 - Fixed bug that makes that the correct value for SERIAL columns wasn't filled for PostgreSQL
 - Added an extra parameter "data" to an event triggering in Phalcon\Events allowing getting more information about certain event
 - Added an extra parameter to Phalcon\Db::query and Phalcon\Db::execute to bind parameters by their data type
 - Added recognition of the related sequence for PostgreSQL when inserting data into tables with SERIAL columns Phalcon\Mvc\Model
 - Phalcon\Db\Adapter\*::describeColumns try to find the best bind param type for every column
 - Added bindType to Phalcon\Db\Column to know what its best bind param to cast according to its data type
 - Added getDefaultValue() to Phalcon\Db\Adapter\* in order the best value to insert in an auto-increment or serial column
 - Added bindTypes param to Phalcon\Mvc\Model::find and Phalcon\Mvc\Model::findFirst
 - Due to the new agressive type-casting when binding parameters, Phalcon\Mvc\Model isn't capable anymore of generate reliable automatic keys for the cache
 - Fixed bug that makes actions and events implemented in a parent class innaccessibles for Phalcon
 - Now Phalcon\Text::camelize checks for underscores and dashes
 - Added Phalcon\Mvc\Model::getRelated to return related relation models on namespaced models

# 0.5.0
- Added Phalcon\CLI components to create CLI applications
- Added SQLite support

# 0.5.0a4
- Removed support for Twig and Mustache
- Added PhalconQL (PHQL), a high level query language directly engaged with the Phalcon\Mvc\Model component
- Multiples refactorings removing unused code
- Added support to match routes on a determined individual or a set of HTTP methods
- Added support for named parameters without requiring a regular expression in Phalcon\Mvc\Router
- Added Phalcon\Mvc\Router\Route to encapsulate the information of a route
- Added Phalcon\Mvc\Micro to create applications in a micro-framework style
- Added Phalcon\Di\FactoryDefault that has the Phalcon Components registered as Default

# 0.5.0a3
 - Added Phalcon\Di as dependency injector container
 - Added Phalcon\Events as events management component
 - Removed Phalcon\Router\Rewrite
 - Phalcon\Router\Regex moved to Phalcon\Mvc\Router
 - Phalcon\Dispatcher moved to Phalcon\Mvc\Dispatcher
 - Phalcon\Mvc\Dispatcher::forward now only accepts an array parameter
 - Dispatcher events has been removed (beforeDispatch and afterDispatch) in favor of the new EventsManager component
 - Controller look up based on controllersDir has been removed in favor of autoloaders
 - Phalcon\Controller moved to Phalcon\Mvc\Controller
 - Phalcon\Model moved to Phalcon\Mvc\Model
 - Phalcon\Transaction moved to Phalcon\Mvc\Model\Transaction
 - Removed Phalcon\Db\Pool
 - ModelsManager look up based on modelsDir has been removed in favor of autoloaders
 - Phalcon\Db\Pdo::describeColumns return an array of Phalcon\Db\Columns
 - Removed Phalcon\Controller\Front
 - Most "Factories" and "Singletons" implementations were removed
 - Phalcon\Mvc\Model\Metadata adapters must be instantiated directly

# 0.5.0a2
 - Removed memory leaks when reading class constants
 - Replaced the database native adapters by PDO

# 0.5.0a1
 - Classes are now registered as PHP namespaces.
 - Improved stability running Phalcon with PHP versions lower or equal than 5.3.3
 - Thousand of unnecessary intermediate variables were removed improving stability
 - Phalcon now performs a reduced number of copy-on-write checks
 - Added class modifiers like Abstract or Final to Phalcon classes
 - Fixed memory leaks generated when throwing internal exceptions
 - Removed deprecated experimental function and method calls

# 0.4.4
 - Fixed problem with Phalcon_Session functions not registered

# 0.4.3
 - Fixed problem with partials, that removed any output previously generated
 - Added Phalcon_Session::destroy
 - Fixed memory leaks generated when throwing internal exceptions

# 0.4.2
 - Added support for PostgreSQL database
 - Phalcon_View is now fully integrated with Phalcon_Cache
 - Dropped unnecessary registration of arguments for exception classes
 - Dropped unnecessary zval copy-on-write checks
 - Fixed double registration of Phalcon_Config in MODULE_MINIT
 - Fixed method definition of __destruct adding ZEND_ACC_DTOR
 - Fixed bug in Phalcon_Model_Query making that the component does not apply quoting properly
 - Fixed segmentation fault in Phalcon_Loader
 - Fixed memory leaks generated when retreiving some static properties
 - Replaced PHP's str_replace for a slightly faster once
 - Improved stability working with static properties in multi-threaded web servers
 - Fixed bug in integration between Phalcon_Db and Phalcon_Logger

# 0.4.1
- Complex concatenations are now made without a lot of intermediate zvals improving the overall memory usage
- Improved throwing of simple exceptions with a unique string parameter
- Added Phalcon_Dispatcher::setParam to change a routing parameter
- Added Phalcon_Request::redirect to make HTTP redirections from controllers
- Phalcon_Model_* is now completely decoupled from Phalcon_Controller_Front
- Phalcon_Model_Base::_createSQLSelectMulti and Phalcon_Model_Base::_createSQLSelectOne has been joined into a single method
- Added Phalcon_Db::bindParams in order to avoid SQL injections
- Added "bind" parameter to Phalcon_Model_Base::find, Phalcon_Model_Base::findFirst, Phalcon_Model_Base::count,
Phalcon_Model_Base::sum, etc. to avoid SQL injections
- The database adapter Phalcon_Db_Adapter_Mysql was moved from mysql extension to mysqli
- Added Phalcon_Db_Result_Mysql to encapsulate the resultset functionality. Those methods were before in Phalcon_Db.
- Fixed bug rebuilding symbol table in Phalcon_View_Engine_Php::render
- Added Phalcon_View::pick to choose a view to show different than last-controller/last-action
- Now is possible to define routes with a shortened syntax in Regex
- Phalcon is now using Compare-and-Swap to reduce the number of writes to cache adapters like files or APC, also avoiding the unnecesary register of shutdown functions

# 0.4.0
- Fixed possible segmentation fault when releasing memory of zval strings that has constant values
- Fixed bug avoiding that auto-globals will jit-initialized inside Phalcon on some old versions of PHP
- Moved zval separation to phalcon_array_update_*
- Moved zval separation to phalcon_array_append_*
- Moved zval constructor to phalcon_array_update_*
- Implemented functions to avoid use arrays of zvals parameters for static and method calls
- Removed error reporting silence from the extension
- Removed thousands of unnecessary referencing/deferencing vars when calling functions/methods
- Moved multi-dimensional array updates to fewer complex functions
- Moved access to static properties to a function that controls possible invalid access to non existent properties
- Fixed memory leaks in Phalcon_Cache and Phalcon_Transaction_Manager
- Added virtual foreign keys to Phalcon_Model (ORM)
- Implemented the possibility to serialize Phalcon_Model_Resultset objects
- Implemented the possibility to access Phalcon_Model_Resultset as an array of objects
- Added Phalcon_Cache_Backend_Apc, Phalcon_Cache_Backend_Memcache, Phalcon_Cache_Frontend_None and Phalcon_Cache_Frontend_Data
- Added Phalcon_Request::hasPost and Phalcon_Request::hasQuery
- Added parameter "persistent" to Phalcon_Db allowing creating persistent connections
- Added alphanum to Phalcon_Filter to filter strings allowing filtering only alpha-numeric characters
- Refactored Phalcon_Tag::select and Phalcon_Tag::selectStatic, now uses the same code in Phalcon_Tag_Select
- Added Phalcon_Tag::checkField helper to create input[type="checkbox"] tags
- Added Phalcon_View::getParams to recover extra params sent to the request
- Sometimes when Phalcon throws an internal exception or E_ERROR the memory stack is not properly cleaned
  producing an unstable state, this situation was fixed
- Phalcon_View was refactored to allow other templating engines like Mustache or Twig
- Added Phalcon_Translate for multi-lingual translation messages based on adapters
- Added calculation functions to Phalcon_Model: count, sum, average, minimum and maximum
- Dispatcher exceptions now throws a HTTP 404 Not found status
- Added Phalcon_Router_Regex to define routes based on regular expressions
- Renamed Phalcon_Request::getBestQualityCharset() to Phalcon_Request::getBestCharset()
- Added Phalcon_Request::getBestLanguage()

# 0.3.5
 - Most of throw exception process has been rewrriten to use fewer instructions
 - Super global initialization is now slightly fast
 - Fixed bug in Phalcon_Db::close
 - Added logging capabilities to Phalcon_Db
 - Added Phalcon_Model_Metadata::getIdentityField allowing to know the identity (auto_increment) field
 - Added DDL and DML methods to Phalcon_Db
 - Added Phalcon_Db_Column to describe table columns
 - Added Phalcon_Db_Index to describe table indexes
 - Added Phalcon_Db_Reference to describe table references (foreign keys)

# 0.3.4
 - Fixed wrong implementation in Phalcon_Tag::javascriptInclude
 - Added Phalcon_Cache_Frontend_Output
 - Renamed Phalcon_Db_Mysql to Phalcon_Db_Adapter_Mysql
 - Renamed Phalcon_Cache_Adapter_File to Phalcon_Cache_Frontend_File
 - Added Phalcon_Request::setRawHeader
 - Added Phalcon_Paginator_Adapter_Array
 - Fixed bugs in model paginator
 - Added Phalcon_Tag::hiddenField
 - Added Phalcon_Tag::fileField
 - Added Phalcon_Loader to autoload classes based on some conventions
 - Added Phalcon_Db_Profiler to profile database operations and determine posible bottlenecks
 - Added methods to query table metadata: Phalcon_Db::describeTable, Phalcon_Db::describeIndexes and Phalcon_Db::describeReferences
 - Fixed segmentation fault in Phalcon_Db::tableExists
 - Fixed memory leak in Phalcon_Paginator
 - Adding Zend Thread Safety (ZTS) support to Phalcon Memory Manager

# 0.3.3
 - Added Phalcon_Tag::setDefault as an alias for Phalcon_Tag::displayTo
 - Added Phalcon_View::setVar as an alias for Phalcon_View::setParamToView
 - Added ACL managment with in-memory lists
 - Fixed segfaults on methods with array optional parameters
 - Fixed segfaults on some isset
 - Added built-in model attributes validators
 - Added Phalcon_ACL to manage access lists
 - Added missing Phalcon_Tag::passwordField

# 0.3.2
 - Fixed separation of super globals by mistake causing segmentation faults
 - Support for compilation on Visual C++ 6.0
 - Fixed segmentation faults when required parameters are not given for most methods

# 0.3.1
 - Phalcon garbage collector incrementally releases memory allocated after the end of a particular execution trace reducing memory fragmentation.

# 0.3.0
 - Refactored many code patterns as C macros, the total base code was reduced by about 8000 lines of code less.
 - Most function calls was rewriten to avoid any string length counting by avoiding potential use of strlen. Functions and methods names have fixed string lengths improving general performance. This improvement was also implemented for static string concatenation.
 - We have implemented some kind of Register Allocation to take advantage of processor registers. However, compiler will choose best register allocations when it compiles the extension.
 - Support for PHP 5.4. A number of issues when running Phalcon under PHP 5.4 were identified and corrected.
 - In some cases memory was copied without need when updating internal arrays, them were fixed.
 - A function cache was included to avoid potential function lookups on internal HashTables. This cache stores internal pointers to functions low level code improving performance.

# 0.2.6
 - Fixed segfault when reading _SESSION superglobal when no session_start has been made
 - Added Phalcon_Cache with adapter File
 - Added method Phalcon_Model_Manager::getHasOneRecords
