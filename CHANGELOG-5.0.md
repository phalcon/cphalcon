# [5.0.0alpha7](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha6) (xxxx-xx-xx)

## Changed
- Changes to the `Phalcon\Acl`:
  - Renamed `Phalcon\Acl\ComponentAware` to `Phalcon\Acl\ComponentAwareInterface`
  - Renamed `Phalcon\Acl\RoleAware` to `Phalcon\Acl\RoleAwareInterface` [#15691](https://github.com/phalcon/cphalcon/issues/15691)
- Changed `require` to `require_once` in `Phalcon\Loader` to avoid conflicts with other loaders [#15489](https://github.com/phalcon/cphalcon/issues/15489)
- Changed `require` to `require_once` in `Phalcon\Cli\Console` and `Phalcon\Mvc\Application` for a bit of extra performance [#15489](https://github.com/phalcon/cphalcon/issues/15489)
- `Phalcon\Collection` has been moved under the `Support` namespace:
  - Renamed  `Phalcon\Collection` to `Phalcon\Support\Collection`
  - Renamed  `Phalcon\Collection\Exception` to `Phalcon\Support\Collection\Exception`
  - Renamed  `Phalcon\Collection\ReadOnly` to `Phalcon\Support\Collection\ReadOnly`
  - Renamed  `Phalcon\Collection` to `Phalcon\Support\Collection` [#15700](https://github.com/phalcon/cphalcon/issues/15700)

## Added
- Added more tests in the suite for additional code coverage [#15691](https://github.com/phalcon/cphalcon/issues/15691)
- Added `Phalcon\Events\AbstractEventsAware` class to handle the Events Manager when necessary [#15691](https://github.com/phalcon/cphalcon/issues/15691)

## Fixed
- Fixed `Query::getExpression()` return type [#15553](https://github.com/phalcon/cphalcon/issues/15553)
- Fixed `Phalcon\Mvc\Model::getRelated()` to correctly return relationships (cached or not) when the foreign key has changed [#15649](https://github.com/phalcon/cphalcon/issues/15649)

# [5.0.0alpha6](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha6) (2021-09-16)

## Changed
- Adjusted the constructor for `Phalcon\Storage\Adapter\*` and `Phalcon\Cache\Adapter\*` to allow an empty key prefix to be set if needed. [#15480](https://github.com/phalcon/cphalcon/issues/15480)
- Changed:
    - `Phalcon\Db\Adapter\AdapterInterface:lastInsertId()` to be identical as `Pdo:lastInsertId()`
    - `Phalcon\Db\Adapter\AdapterInterface:close()` now returns `void` instead of `bool`
    - `Phalcon\Db\Adapter\AdapterInterface:connect()` now returns `void` instead of `bool` and 1st argument default value is empty `array` instead of `null` [#15659](https://github.com/phalcon/cphalcon/issues/15659)

## Added
- Added `Phalcon\Security\JWT\Builder::addClaim` for custom JWT claims. [#15656](https://github.com/phalcon/cphalcon/issues/15656)

# [5.0.0alpha5](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha5) (2021-09-09)

## Changed
- Merged all architectures (`build/phalcon/32bits`, `build/phalcon/64bits` and `build/phalcon/safe`) into single universal inside `build/phalcon` [#15647](https://github.com/phalcon/cphalcon/issues/15647)

## Fixed
- Fixed C code in `build/` directory [#15647](https://github.com/phalcon/cphalcon/issues/15647)

# [5.0.0alpha4](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha4) (2021-09-05)

## Changed
- Changed `composer.json` to use PSR 1.1.x [#15504](https://github.com/phalcon/cphalcon/issues/15504)
- Changed `Phalcon\Di\Injectable:getDI()` to set default DI when no DI is set [#15629](https://github.com/phalcon/cphalcon/pull/15629)

## Added
- Added `Phalcon\Flash\Direct::setCssIconClasses` and `Phalcon\Flash\Session::setCssIconClasses` to allow setting icons in the flash messages (bootstrap related) [#15292](https://github.com/phalcon/cphalcon/issues/15292)
- Added `Phalcon\Http\Message\RequestMethodInterface` and `Phalcon\Http\Message\ResponseStatusCodeInterface` that contain constants to be used for any HTTP implementations (see PHP-FIG) [#15615](https://github.com/phalcon/cphalcon/issues/15615)

## Fixed
- Fixed `Phalcon\Container` interface to abide with `Psr\Container\ContainerInterface` after the upgrade to PSR 1.1.x [#15504](https://github.com/phalcon/cphalcon/issues/15504)
- Fixed `Phalcon\Forms\Form` when no entity is passed with isValid(), it uses the entity set in the form [#15567](https://github.com/phalcon/cphalcon/issues/15567)
- Fixed `Phalcon\Logger\Adapter\*` to not allow serialization of the object. Added an exception when destroying the object while in transaction mode [#15638](https://github.com/phalcon/cphalcon/issues/15638)

# [5.0.0alpha3](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha3) (2021-06-30)

## Changed
- Changed version format to allow alpha/beta/RC releases on PECL. 
- Changed:
    - `Phalcon\Mvc\Model\Resultset\Complex::__construct` now accepts `Psr\SimpleCache\CacheInterface` for the cache
    - `Phalcon\Mvc\Model\Resultset\Simple::__construct` now accepts `Psr\SimpleCache\CacheInterface` for the cache
    - `Phalcon\Mvc\Model\Resultset::__construct` now accepts `Psr\SimpleCache\CacheInterface` for the cache
    - `Phalcon\Mvc\Model\Resultset::getCache` now returns `Psr\SimpleCache\CacheInterface` [#15471](https://github.com/phalcon/cphalcon/issues/15471)
- Changed `Phalcon\Db\Adapter\AbstractAdapter:delete()` signature of optional parameters. [#15363](https://github.com/phalcon/cphalcon/issues/15363)
- Changed `bindCounts` argument to array type in:
    - `Phalcon\Db\Dialect:getColumnList()`
    - `Phalcon\Db\Dialect:getSqlColumn()`
    - `Phalcon\Db\Dialect:getSqlExpression()`
    - `Phalcon\Db\Dialect:getSqlExpressionBinaryOperations()`
    - `Phalcon\Db\Dialect:getSqlExpressionCase()`
    - `Phalcon\Db\Dialect:getSqlExpressionCastValue()`
    - `Phalcon\Db\Dialect:getSqlExpressionConvertValue()`
    - `Phalcon\Db\Dialect:getSqlExpressionFunctionCall()`
    - `Phalcon\Db\Dialect:getSqlExpressionGroupBy()`
    - `Phalcon\Db\Dialect:getSqlExpressionHaving()`
    - `Phalcon\Db\Dialect:getSqlExpressionJoins()`
    - `Phalcon\Db\Dialect:getSqlExpressionLimit()`
    - `Phalcon\Db\Dialect:getSqlExpressionList()`
    - `Phalcon\Db\Dialect:getSqlExpressionObject()`
    - `Phalcon\Db\Dialect:getSqlExpressionOrderBy()`
    - `Phalcon\Db\Dialect:getSqlExpressionScalar()`
    - `Phalcon\Db\Dialect:getSqlExpressionUnaryOperations()`
    - `Phalcon\Db\Dialect:getSqlExpressionWhere()`
    - `Phalcon\Db\DialectInterface:getSqlExpression()`

## Fixed
- Fixed `Phalcon\Db\Adapter\AbstractAdapter:delete()` when `bindTypes` argument is passed. [#15363](https://github.com/phalcon/cphalcon/issues/15363)
- Fixed `Phalcon\Storage\Adapter\Redis::getAdapter` to use passed `connectionTimeout`, `retryInterval` and `readTimeout` options for the connection [#15484](https://github.com/phalcon/cphalcon/issues/15484)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler` for a use case when a block will return null vs an array for `statementList` in PHP 8 [#15556](https://github.com/phalcon/cphalcon/issues/15556)

# [5.0.0-alpha.2](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0-alpha.2) (2021-05-05)

## Changed
- Changed `Phalcon\Translate\Adapter\Gettext::setLocale` signature to allow the category and an array of locales [#14764](https://github.com/phalcon/cphalcon/issues/14764)
- `Phalcon\Version` is now moved to `Phalcon\Support\Version`
    - `_getSpecialVersion` and `_getVersion` have been removed (marked deprecated in v4)
    - The class is no longer static; it has to be instantiated first
    - References to `Phalcon\Debug` and the Volt compiler have been adjusted [#15422](https://github.com/phalcon/cphalcon/issues/15422)
- `Phalcon\Debug` is now moved to `Phalcon\Support\Debug`; CSS/JS references updated [#14817](https://github.com/phalcon/cphalcon/issues/14817)
- Changed the logging names types to uppercase [#15375](https://github.com/phalcon/cphalcon/issues/15375)
- Changes to the `Phalcon\Logger`:
    - Renamed `Phalcon\Logger\Item::getName` to `Phalcon\Logger\Item::getLevelName`
    - Renamed `Phalcon\Logger\Item::getType` to `Phalcon\Logger\Item::getLevel`
    - Changed the logger timestamp to be `DateTimeImmutable` on a per item basis - more accurate timing
    - Changed `Phalcon\Logger` to accept a `DateTimeZone` in the constructor
    - Changed placeholder `%type%` to `%level%` to align with the variables [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Changed `Phalcon\Mvc\Model::getSchema()`, `Phalcon\Mvc\ModelInterface::getSchema()`, `Phalcon\Mvc\Model\Manager::getModelSchema()` `Phalcon\Mvc\Model\ManagerInterface::getModelSchema()` to return `string | null` so as to abide with the latest Zephir [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Changed the interpolation for the formatters to use the `Phalcon\Support\Helper\Str\Interpolate` [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Changed the exceptions thrown from factories to be more specific to their namespaces vs. the Factory generic one [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Changed `Phalcon\Mvc\Model\ManagerInterface:getRelationByAlias()` return type from `Relation|bool` to `RelationInterface|bool` [#15343](https://github.com/phalcon/cphalcon/issues/15343)
- Changed `Phalcon\Paginator\Repository:getItems()` return type from `array` to `ResultsetInterface` [#15074](https://github.com/phalcon/cphalcon/issues/15074)

## Added
- Added `BINARY` and `VARBINARY` support for Phalcon\Db\Adapter\Mysql [#14927](https://github.com/phalcon/cphalcon/issues/14927)
- Added `Phalcon\Db\Profiler\Item::getTotalElapsedNanoseconds()` and `Phalcon\Db\Profiler\Item::getTotalElapsedMilliseconds()` for more precision [#15249](https://github.com/phalcon/cphalcon/issues/15249)
- Added `Phalcon\Http\Response\Cookies::isSent()` and `Phalcon\Http\Response\Headers::isSent()`; Added logic to not send the headers or cookies twice. [#15334](https://github.com/phalcon/cphalcon/issues/15334)
- Added `Phalcon\Validation\Validator\File\AbstractFile::checkIsUploadedFile()` method to allow overriding when adding files to the `$_FILES` array directly (not uploading). [#15051](https://github.com/phalcon/cphalcon/issues/15051)
- Added `Phalcon\Support\Helper\Str\Interpolate` to be used throughout the code for interpolation (Logger/Translator) `%type%` to `%level%` to align with the variables [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Added `Phalcon\Support\HelperFactory` for an easier creation/access of helpers [#15411](https://github.com/phalcon/cphalcon/issues/15411)

## Fixed
- Corrected the `Phalcon\Db\Profiler\Item` calculation for seconds [#15249](https://github.com/phalcon/cphalcon/issues/15249) 
- Corrected `Phalcon\Http\Message\ServerRequestFactory` to populate with superglobals [#15286](https://github.com/phalcon/cphalcon/issues/15286)
- Corrected `Phalcon\Mvc\Model\Query\BuilderInterface::orderBy` to use `var` instead of `string` [#15415](https://github.com/phalcon/cphalcon/issues/15415)
- Corrected `Phalcon\Db\Adapter\Pdo\AbstractPdo::connect` to take into account the `persistent` option for relevant connections [#15241](https://github.com/phalcon/cphalcon/issues/15241)
- Corrected `Phalcon\Image\Adapter\Gd::processText` to correctly call `imagettfbbox` when a font is specified [#15188](https://github.com/phalcon/cphalcon/issues/15188)
- Corrected `Phalcon\Cache` to cast keys as strings before sending them to adapters [#15249](https://github.com/phalcon/cphalcon/issues/15249)
- Binding form values with specified whitelist [#15070](https://github.com/phalcon/cphalcon/issues/15070)

# [5.0.0-alpha.1](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0-alpha.1) (2021-03-31)

## Fixed
- Support for PHP 7.4 and PHP 8.0
- Fixed `Logger\Log::log()` `log` to recognize all log levels [#15214](https://github.com/phalcon/cphalcon/issues/15214)
- Changed `setClaims` to be protected so that the `Phalcon\Security\JWT\Builder` class can be properly extended. [#15322](https://github.com/phalcon/cphalcon/issues/15322)
- Fixed `Phalcon\Mvc\Model::average()` to return `float` value when is `string` [#15287](https://github.com/phalcon/cphalcon/pull/15287)
- Fixed `Phalcon\Storage\Serializer\Igbinary` to store `is_numeric` and `bool` values properly [#15240](https://github.com/phalcon/cphalcon/pull/15240)
- Fixed `Phalcon\Validation\Validator\Confirmation` was failing to compare cases such as 000123 = 123 [#15347](https://github.com/phalcon/cphalcon/pull/15347)
- Fixed `Phalcon\Storage\Adapter` failing to retrieve empty like stored data (such as [], 0, false) [15125](https://github.com/phalcon/cphalcon/issues/15125) 
- Fixed declarations for `function getEventsManager()` to allow null return [15010](https://github.com/phalcon/cphalcon/issues/15010)
- Removed underscore from method names (starting) to abide with PSR-12 [15345](https://github.com/phalcon/cphalcon/issues/15345)
- Fixed `Phalcon\Flash\Session::has()` to properly check if any messages are existing [15204](https://github.com/phalcon/cphalcon/issues/15204)
- Fixed signature of `Phalcon\Forms\Element\Select::__construct()`
- Fixed signature of `Phalcon\Assets\Manager::addCss()`
- Fixed signature of `Phalcon\Assets\Manager::addJs()`
- Fixed signature of `Phalcon\Db\Adapter\AdapterInterface::execute()`, `Phalcon\Db\Adapter\AdapterInterface::fetchOne()` and `Phalcon\Db\Adapter\AdapterInterface::query()`
