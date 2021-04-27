# [5.0.0-alpha.2](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0-alpha.2) (xxxx-xx-xx)

## Changed
- Changed the logging names types to uppercase [#15375](https://github.com/phalcon/cphalcon/issues/15375)
- Changes to the `Phalcon\Logger`:
    - Renamed `Phalcon\Logger\Item::getName` to `Phalcon\Logger\Item::getLevelName`
    - Renamed `Phalcon\Logger\Item::getType` to `Phalcon\Logger\Item::getLevel`
    - Changed the logger timestamp to be `DateTimeImmutable` on a per item basis - more accurate timing
    - Changed `Phalcon\Logger` to accept a `DateTimeZone` in the constructor
    - Changed placeholder `%type%` to `%level%` to align with the variables [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Changed `Phalcon\Mvc\Model::getSchema()`, `Phalcon\Mvc\ModelInterface::getSchema()`, `Phalcon\Mvc\Model\Manager::getModelSchema()` `Phalcon\Mvc\Model\ManagerInterface::getModelSchema()` to return `string | null` so as to abide with the latest Zephir [#15411](https://github.com/phalcon/cphalcon/issues/15411)

## Added
- Added BINARY and VARBINARY support for Phalcon\Db\Adapter\Mysql [#14927](https://github.com/phalcon/cphalcon/issues/14927)
- Added `Phalcon\Db\Profiler\Item::getTotalElapsedNanoseconds()` and `Phalcon\Db\Profiler\Item::getTotalElapsedMilliseconds()` for more precision [#15249](https://github.com/phalcon/cphalcon/issues/15249)
- Added `Phalcon\Http\Response\Cookies::isSent()` and `Phalcon\Http\Response\Headers::isSent()`; Added logic to not send the headers or cookies twice. [#15334](https://github.com/phalcon/cphalcon/issues/15334)
- Added `Phalcon\Validation\Validator\File\AbstractFile::checkIsUploadedFile()` method to allow overriding when adding files to the `$_FILES` array directly (not uploading). [#15051](https://github.com/phalcon/cphalcon/issues/15051)

## Changed
- `Phalcon\Version` is now moved to `Phalcon\Support\Version`
    - `_getSpecialVersion` and `_getVersion` have been removed (marked deprecated in v4)
    - The class is no longer static; it has to be instantiated first
    - References to `Phalcon\Debug` and the Volt compiler have been adjusted [#15422](https://github.com/phalcon/cphalcon/issues/15422)
- `Phalcon\Debug` is now moved to `Phalcon\Support\Debug`; CSS/JS references updated [#14817](https://github.com/phalcon/cphalcon/issues/14817)

## Fixed
- Corrected the `Phalcon\Db\Profiler\Item` calculation for seconds [#15249](https://github.com/phalcon/cphalcon/issues/15249) 
- Corrected `Phalcon\Http\Message\ServerRequestFactory` to populate with superglobals [#15286](https://github.com/phalcon/cphalcon/issues/15286)
- Corrected `Phalcon\Mvc\Model\Query\BuilderInterface::orderBy` to use `var` instead of `string` [#15415](https://github.com/phalcon/cphalcon/issues/15415)
- Corrected `Phalcon\Db\Adapter\Pdo\AbstractPdo::connect` to take into account the `persistent` option for relevant connections [#15241](https://github.com/phalcon/cphalcon/issues/15241)
- Corrected `Phalcon\Image\Adapter\Gd::processText` to correctly call `imagettfbbox` when a font is specified [#15188](https://github.com/phalcon/cphalcon/issues/15188)
- Corrected `Phalcon\Cache` to cast keys as strings before sending them to adapters [#15249](https://github.com/phalcon/cphalcon/issues/15249)

# [5.0.0-alpha.1](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0-alpha.1) (2020-03-31)

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
