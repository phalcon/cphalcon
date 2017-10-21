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
- Added `dispatcher::beforeForward` event to allow forwarding request to the separated module [#121](https://github.com/phalcon/cphalcon/issues/121), [#12417](https://github.com/phalcon/cphalcon/issues/12417), [#2496](https://github.com/phalcon/cphalcon/issues/2496), [#1658](https://github.com/phalcon/cphalcon/issues/1658)
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

