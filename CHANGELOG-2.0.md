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
- Fixed a bug that makes that attaching an events manager to an `Mvc\Application` causes `view->render` not being called
- Fixed bug that makes generated SQL statements using `FOR UPDATE` not being parsed correctly
- The email filter now no longer removes the `'` character [#10603](https://github.com/phalcon/cphalcon/pull/10603)
- When an array is bound the cached representation in PHQL makes the SQL being incorrectly
  generated the second time.
- Added `Phalcon\Mvc\Model\MetaData\Memcache` and `Phalcon\Mvc\Model\MetaData\Libmemcached` adapters

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
