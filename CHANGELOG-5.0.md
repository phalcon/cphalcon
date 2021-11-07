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
- Changes to `Phalcon\Session\Bag`:
  - Changed `Phalcon\Session\Bag::construct` to accept a container instead of internally calling the default
  - Changed `Phalcon\Session\Bag::construct` to throw an exception if the container is not specified
  - Changed `Phalcon\Session\Bag::init` to store the data in the session [#15494](https://github.com/phalcon/cphalcon/issues/15494)
- Changed `Phalcon\Events\Event::construct()` to allow `source` to be nullable [#15133](https://github.com/phalcon/cphalcon/issues/15133)
- Changes to `Phalcon\Crypt`
  - Moved `Phalcon\Crypt\Exception` to `Phalcon\Crypt\Exception\Exception`
  - Moved `Phalcon\Crypt\Mismatch` to `Phalcon\Crypt\Exception\Mismatch`
  - Changed the ccm/gcm modes to store the `authTag` with the encryption string and process it with the decryption string [#15717](https://github.com/phalcon/cphalcon/issues/15717)
- Created new namespace `Phalcon\Encryption`
  - Moved `Phalcon\Crypt` to `Phalcon\Encryption\Crypt`
  - Moved `Phalcon\Security` to `Phalcon\Encryption\Security`
  - Moved the whole `Security` namespace under `Encryption`
    - `Security\JWT\Exceptions\UnsupportedAlgorithmException` to `Encryption\Security\JWT\Exceptions\UnsupportedAlgorithmException`
    - `Security\JWT\Exceptions\ValidatorException` to `Encryption\Security\JWT\Exceptions\ValidatorException`
    - `Security\JWT\Signer\AbstractSigner` to `Encryption\Security\JWT\Signer\AbstractSigner`
    - `Security\JWT\Signer\Hmac` to `Encryption\Security\JWT\Signer\Hmac`
    - `Security\JWT\Signer\None` to `Encryption\Security\JWT\Signer\None`
    - `Security\JWT\Signer\SignerInterface` to `Encryption\Security\JWT\Signer\SignerInterface`
    - `Security\JWT\Token\AbstractItem` to `Encryption\Security\JWT\Token\AbstractItem`
    - `Security\JWT\Token\Enum` to `Encryption\Security\JWT\Token\Enum`
    - `Security\JWT\Token\Item` to `Encryption\Security\JWT\Token\Item`
    - `Security\JWT\Token\Parser` to `Encryption\Security\JWT\Token\Parser`
    - `Security\JWT\Token\Signature` to `Encryption\Security\JWT\Token\Signature`
    - `Security\JWT\Token\Token` to `Encryption\Security\JWT\Token\Token`
    - `Security\JWT\Builder` to `Encryption\Security\JWT\Builder`
    - `Security\JWT\Validator` to `Encryption\Security\JWT\Validator`
    - `Security\JWT\Validator` to `Encryption\Security\JWT\Validator`
    - `Security\Exception` to `Encryption\Security\Exception`
    - `Security\Random` to `Encryption\Security\Random` [#15729](https://github.com/phalcon/cphalcon/issues/15729)
- Renamed 
    - `Phalcon\Crypt\Crypt::getHashAlgo()` to `Phalcon\Crypt\Crypt::getHashAlgorithm()` 
    - `Phalcon\Crypt\Crypt::getAvailableHashAlgos()` to `Phalcon\Crypt\Crypt::getAvailableHashAlgorithms()` 
    - `Phalcon\Crypt\Crypt::setHashAlgo()` to `Phalcon\Crypt\Crypt::setHashAlgorithm()` [#15717](https://github.com/phalcon/cphalcon/issues/15717)
- Renamed `Phalcon\Factory\AdapterFactory::getAdapters()` to `Phalcon\Factory\AdapterFactory::getServices()` [#15717](https://github.com/phalcon/cphalcon/issues/15717)
- Changed `Phalcon\Crypt\Crypt::__construct()` to have `useSigning` set to `true` by default [#15717](https://github.com/phalcon/cphalcon/issues/15717)
- Changes to `Phalcon\Config`
    - Moved `Phalcon\Config` to `Phalcon\Config\Config`
    - Changed `Phalcon\Config\Config::path` by making the `delimiter` parameter a `string` 
    - Changed `Phalcon\Config\Adapter\Ini::__construct` to not accept `null` as the mode. The default is now `INI_SCANNER_NORMAL` (2)
    - Refactored the code for more efficiency and speed [#15720](https://github.com/phalcon/cphalcon/issues/15720)
- Changed `Phalcon\Db\Adapter\AdapterInterface::getInternalHandler()` and `Phalcon\Db\Adapter\Pdo\AbstractPdo::getInternalHandler()` to return `var` instead of `\PDO` for custom adapters with different engines [#15119](https://github.com/phalcon/cphalcon/issues/15119) 
- Moved `Phalcon\Filter` to `Phalcon\Filter\Filter`; added more tests [#15726](https://github.com/phalcon/cphalcon/issues/15726)
- Changed `Phalcon\Mvc\ModelgetPreparedQuery()` to return `QueryInterface` instead of `Query` [#15562](https://github.com/phalcon/cphalcon/issues/15562)
- Moved `Phalcon\Cache` to `Phalcon\Cache\Cache` [#15728](https://github.com/phalcon/cphalcon/issues/15728)
- Changed `Phalcon\Factory\AdapterFactory` to define the factory exception in `getExceptionClass()` instead of a property. [#15728](https://github.com/phalcon/cphalcon/issues/15728)
- Renamed `Phalcon\Db\Adapter\AbstractAdapter::getSqlVariables()` to `Phalcon\Db\Adapter\AbstractAdapter::getSQLVariables()` to align with the rest of the `getSQL*` methods [#15637](https://github.com/phalcon/cphalcon/issues/15637)
- Moved `Phalcon\Logger` to `Phalcon\Logger\Logger` [#15727](https://github.com/phalcon/cphalcon/issues/15727)
- Changes to `Phalcon\Escaper`
  - Moved `Phalcon\Escaper` to `Phalcon\Html\Escaper`
  - Moved `Phalcon\Escaper\EscaperInterface` to `Phalcon\Html\Escaper\EscaperInterface`
  - Moved `Phalcon\Escaper\Exception` to `Phalcon\Html\Escaper\Exception`
  - Deprecated methods (to be removed at a future version)
    - `escapeCss()` becomes `css()`
    - `escapeJs()`, becomes `js()`
    - `escapeHtml()` becomes `html()`
    - `escapeHtmlAttr()` becomes `attributes()`
    - `escapeUrl()` becomes `url()`
    - `setHtmlQuoteType()` becomes `setFlags()` [#15757](https://github.com/phalcon/cphalcon/issues/15757)
- Changed `Phalcon\Encryption\Security::hash()` to also use `password_hash()` and accept `ARGON2*` algorithms [#15731](https://github.com/phalcon/cphalcon/issues/15731) 
- Removed uncamelize of `realClassName` in `Phalcon\Mvc\Router\Route::getRoutePaths()` if definition is string to make processing same as if array definition [#15067](https://github.com/phalcon/cphalcon/issues/15067) 
- Changed `Phalcon\Validation::getValue()` behavior to get value from `data` if not found in `entity`. [#14203](https://github.com/phalcon/cphalcon/issues/14203)
- Changed `Phalcon\Forms\Form::isValid()` signature: added `whitelist` argument. [#14203](https://github.com/phalcon/cphalcon/issues/14203)
- Changed `Phalcon\Mvc\Model::save()` to allow saving master relations [#15572](https://github.com/phalcon/cphalcon/issues/15572) 

## Added
- Added more tests in the suite for additional code coverage [#15691](https://github.com/phalcon/cphalcon/issues/15691)
- Added `Phalcon\Events\AbstractEventsAware` class to handle the Events Manager when necessary [#15691](https://github.com/phalcon/cphalcon/issues/15691)
- Added `Phalcon\Acl\Adapter\AdapterInterface::getInheritedRoles()` and `Phalcon\Acl\Adapter\Memory::getInheritedRoles()` that returns the inherited roles based on a passed role name (or all if no parameter supplied) [#15154](https://github.com/phalcon/cphalcon/issues/15154)
- Changes to `Phalcon\Crypt`
    - Added `Phalcon\Crypt\Padding\PadInteface` and padding adapters
        - `Phalcon\Crypt\Padding\Ansi`
        - `Phalcon\Crypt\Padding\Iso10126`
        - `Phalcon\Crypt\Padding\IsoIek`
        - `Phalcon\Crypt\Padding\Noop`
        - `Phalcon\Crypt\Padding\PadInterface`
        - `Phalcon\Crypt\Padding\Pkcs7`
        - `Phalcon\Crypt\Padding\Space`
        - `Phalcon\Crypt\Padding\Zero`
    - Added `Phalcon\Crypt\PadFactory` to easily create padding adapters
    - Added more tests increasing coverage [#15717](https://github.com/phalcon/cphalcon/issues/15717)
- Added `Phalcon\Cache\Adapter\*::setForever()` and `Phalcon\Storage\Adapter\*::setForever()` to allow storing a key forever [#15485](https://github.com/phalcon/cphalcon/issues/15485)
- Added `Phalcon\Encryption\Security::getHashInformation()` to return information for a hash [#15731](https://github.com/phalcon/cphalcon/issues/15731)
- Added constants `Phalcon\Encryption\Security::CRYPT_ARGON2I` and `Phalcon\Encryption\Security::CRYPT_ARGON2ID` [#15731](https://github.com/phalcon/cphalcon/issues/15731)
- Added `allowEmpty` checks to common validators [#15515](https://github.com/phalcon/cphalcon/issues/15515)
- Added `Phalcon\Forms\Form::getFilteredValue()` to get filtered value without providing entity [#15438](https://github.com/phalcon/cphalcon/issues/15438)
- Added `Phalcon\Forms\Form::setWhitelist()` and `Phalcon\Forms\Form::getWhitelist()` [#14203](https://github.com/phalcon/cphalcon/issues/14203)

## Fixed
- Fixed `Query::getExpression()` return type [#15553](https://github.com/phalcon/cphalcon/issues/15553)
- Fixed `Phalcon\Mvc\Model::getRelated()` to correctly return relationships (cached or not) when the foreign key has changed [#15649](https://github.com/phalcon/cphalcon/issues/15649)
- Fixed `Phalcon\Db\Adapter\Pdo\*`, `Phalcon\Mvc\Model` and `Phalcon\Mvc\Model\MetaData\Strategy\Annotations` to treat `BIGINT` numbers as string [#15632](https://github.com/phalcon/cphalcon/issues/15632)
- Fixed `Phalcon\Crypt\Crypt::decrypt()` to correctly calculate the hash when using signed mode [#15717](https://github.com/phalcon/cphalcon/issues/15717)
- Fixed `Phalcon\Mvc\Model\Manager::isVisibleModelProperty()` to correctly check if setting property is visible [#15276](https://github.com/phalcon/cphalcon/issues/15276)
- Fixed `Phalcon\Config\Config::merge` to retain numeric indexes in deep merges [#14705](https://github.com/phalcon/cphalcon/issues/14705)
- Fixed globals (Zephir change) to correctly display string values for global settings in `phpinfo()` [#15269](https://github.com/phalcon/cphalcon/issues/15269)
- Fixed `Phalcon\Storage\Adapter\Redis::getAdapter()` and `Phalcon\Cache\Adapter\Redis::getAdapter()` to accept the connection timeout in the constructor `options` [#15744](https://github.com/phalcon/cphalcon/issues/15744) 
- Fixed `Phalcon\Db\Adapter\AbstractAdapter::getSQLVariables()` to return an empty array when initialized [#15637](https://github.com/phalcon/cphalcon/issues/15637)
- Fixed `Phalcon\Cache\Adapter\*` and `Phalcon\Storage\Adapter\*` to delete a key when `set()` is called with a zero or negative TTL [#15485](https://github.com/phalcon/cphalcon/issues/15485)
- Fixed `Phalcon\Db\Adapter\Pdo\Mysql` to not use `PDO::ATTR_EMULATE_PREPARES` and `PDO::ATTR_STRINGIFY_FETCHES` by default. This allows numbers to be returned with resultsets instead of strings for numeric fields [#15361](https://github.com/phalcon/cphalcon/issues/15361) 
- Fixed `Phalcon\Validation\Validator\File` to use `messageFileEmpty` [#14928](https://github.com/phalcon/cphalcon/issues/14928) 

# [5.0.0alpha6](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha6) (2021-09-16)

## Changed
- Adjusted the constructor for `Phalcon\Storage\Adapter\*` and `Phalcon\Cache\Adapter\*` to allow an empty key prefix to be set if needed. [#15480](https://github.com/phalcon/cphalcon/issues/15480)
- Changed:
    - `Phalcon\Db\Adapter\AdapterInterface:lastInsertId()` to be identical as `Pdo:lastInsertId()`
    - `Phalcon\Db\Adapter\AdapterInterface:close()` now returns `void` instead of `bool`
    - `Phalcon\Db\Adapter\AdapterInterface:connect()` now returns `void` instead of `bool` and 1st argument default value is empty `array` instead of `null` [#15659](https://github.com/phalcon/cphalcon/issues/15659)

## Added
- Added `Phalcon\Security\JWT\Builder::addClaim` for custom JWT claims. [#15656](https://github.com/phalcon/cphalcon/issues/15656)
- Added `Phalcon\Support\Helper` namespace:
  - Added `Phalcon\Support\HelperFactory`, a handy factory to help with string, array and other manipulations
  - Added `helper` service in `Phalon\Di\FactoryDefault` and `Phalcon\Di\FactoryDefault\Cli` to point to the `Phalcon\Support\HelperFactory`
  - Added array manipulation classes:
    - `Phalcon\Support\Helper\Arr\Blacklist`
    - `Phalcon\Support\Helper\Arr\Chunk`
    - `Phalcon\Support\Helper\Arr\First`
    - `Phalcon\Support\Helper\Arr\FirstKey`
    - `Phalcon\Support\Helper\Arr\Flatten`
    - `Phalcon\Support\Helper\Arr\Get`
    - `Phalcon\Support\Helper\Arr\Group`
    - `Phalcon\Support\Helper\Arr\Has`
    - `Phalcon\Support\Helper\Arr\IsUnique`
    - `Phalcon\Support\Helper\Arr\Last`
    - `Phalcon\Support\Helper\Arr\LastKey`
    - `Phalcon\Support\Helper\Arr\Order`
    - `Phalcon\Support\Helper\Arr\Pluck`
    - `Phalcon\Support\Helper\Arr\Set`
    - `Phalcon\Support\Helper\Arr\SliceLeft`
    - `Phalcon\Support\Helper\Arr\SliceRight`
    - `Phalcon\Support\Helper\Arr\Split`
    - `Phalcon\Support\Helper\Arr\ToObject`
    - `Phalcon\Support\Helper\Arr\ValidateAll`
    - `Phalcon\Support\Helper\Arr\ValidateAny`
    - `Phalcon\Support\Helper\Arr\Whitelist`
  - Added file manipulation classes:
    - `Phalcon\Support\Helper\File\Basename`
  - Added JSON manipulation classes:
    - `Phalcon\Support\Helper\Json\Encode`
    - `Phalcon\Support\Helper\Json\Decode`
  - Added number manipulation classes:
    - `Phalcon\Support\Helper\Number\IsBetween`
  - Added array manipulation classes:
    - `Phalcon\Support\Helper\Str\Camelize`
    - `Phalcon\Support\Helper\Str\Concat`
    - `Phalcon\Support\Helper\Str\CountVowels`
    - `Phalcon\Support\Helper\Str\Decapitalize`
    - `Phalcon\Support\Helper\Str\Decrement`
    - `Phalcon\Support\Helper\Str\DirFromFile`
    - `Phalcon\Support\Helper\Str\DirSeparator`
    - `Phalcon\Support\Helper\Str\Dynamic`
    - `Phalcon\Support\Helper\Str\EndsWith`
    - `Phalcon\Support\Helper\Str\FirstBetween`
    - `Phalcon\Support\Helper\Str\Friendly`
    - `Phalcon\Support\Helper\Str\Humanize`
    - `Phalcon\Support\Helper\Str\Includes`
    - `Phalcon\Support\Helper\Str\Increment`
    - `Phalcon\Support\Helper\Str\Interpolate`
    - `Phalcon\Support\Helper\Str\IsAnagram`
    - `Phalcon\Support\Helper\Str\IsLower`
    - `Phalcon\Support\Helper\Str\IsPalindrome`
    - `Phalcon\Support\Helper\Str\IsUpper`
    - `Phalcon\Support\Helper\Str\Len`
    - `Phalcon\Support\Helper\Str\Lower`
    - `Phalcon\Support\Helper\Str\Prefix`
    - `Phalcon\Support\Helper\Str\Random`
    - `Phalcon\Support\Helper\Str\ReduceSlashes`
    - `Phalcon\Support\Helper\Str\StartsWith`
    - `Phalcon\Support\Helper\Str\Suffix`
    - `Phalcon\Support\Helper\Str\Ucwords`
    - `Phalcon\Support\Helper\Str\Uncamelize`
    - `Phalcon\Support\Helper\Str\Underscore`
    - `Phalcon\Support\Helper\Str\Upper`[#15738](https://github.com/phalcon/cphalcon/issues/15738)

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
