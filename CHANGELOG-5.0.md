# Changelog

## [5.16.0](https://github.com/phalcon/cphalcon/releases/tag/v5.15.1) (2026-06-22)

### Tools

- Zephir Parser v2.0.4
- Zephir 0.23.0 (development - f87b27ba9)

### Changed

- Changed `Phalcon\Support\Debug::getVersion()` to return a compact version badge anchor (`v<version>`) instead of the previous "Phalcon Framework" version block. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Changed `Phalcon\Support\Debug` and `Phalcon\Support\Debug\Dump` to render from named, overridable template strings (the new `Phalcon\Contracts\Support\Debug\TemplateAware` contract with `getTemplate()`/`setTemplate()`) filled by `strtr`, instead of inline string concatenation. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Changed `Phalcon\Support\Debug` into a thin coordinator that delegates exception-data collection to the new `Phalcon\Support\Debug\ReportBuilder` and HTML rendering to a `Phalcon\Contracts\Support\Debug\Renderer` (default `Phalcon\Support\Debug\Renderer\HtmlRenderer`), and exposes `getRenderer()`/`setRenderer()` to swap the renderer. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Changed the `Phalcon\Support\Debug` Memory panel to report both real and peak memory usage. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Changed the `Phalcon\Support\Debug` exception page to a redesigned, asset-driven layout (masthead with the Phalcon logo, error card, tabbed Request/Server/Included Files/Memory/Variables context, and collapsible backtrace frames); `getCssSources()` and `getJsSources()` now reference a single `debug.css` and `debug.js` instead of the bundled jQuery, jQuery-UI and prettify assets. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)

### Added

- Added `Phalcon\Support\Debug::getRenderer()` and `Phalcon\Support\Debug::setRenderer()`. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Added connection-liveness and opt-in auto-reconnect support to `Phalcon\Db\Adapter\Pdo\AbstractPdo`: `ping()` (a `SELECT 1` probe), `ensureConnection()` (reconnect in place when the probe fails), and `setAutoReconnect()`/`getAutoReconnect()` (also settable via the `autoReconnect` descriptor key). When auto-reconnect is enabled and a query fails on a lost ("gone away") connection outside a transaction, `execute()` and `query()` fire the new `db:connectionLost` event, reconnect, and retry the statement once; a loss inside a transaction is re-thrown without retry. "Gone away" detection is provided per driver by `Phalcon\Db\Adapter\Pdo\Mysql` (error codes 2006/2013) and `Phalcon\Db\Adapter\Pdo\Postgresql` (SQLSTATE 08003/08006/57P01-03), with a message fallback. [#17204](https://github.com/phalcon/cphalcon/issues/17204) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Added the Beanstalk queue adapter (`Phalcon\Queue\Adapter\Beanstalk\*`) over a dependency-free socket client, with native delivery delay and priority and a `VisibilityAware` consumer (`touch()`). [#17051](https://github.com/phalcon/cphalcon/issues/17051) [[doc]](https://docs.phalcon.io/5.15/queue/)
- Added the Memory and Stream queue adapters (`Phalcon\Queue\Adapter\Memory\*`, in-process FIFO; `Phalcon\Queue\Adapter\Stream\*`, file-per-queue with `flock`). [#17051](https://github.com/phalcon/cphalcon/issues/17051) [[doc]](https://docs.phalcon.io/5.15/queue/)
- Added the Redis queue adapter (`Phalcon\Queue\Adapter\Redis\*`) with list-backed FIFO delivery (`LPUSH`/`BRPOP`), sorted-set delivery delay and native blocking receive. [#17051](https://github.com/phalcon/cphalcon/issues/17051) [[doc]](https://docs.phalcon.io/5.15/queue/)
- Added the `Phalcon\Contracts\Support\Debug\TemplateAware` and `Phalcon\Contracts\Support\Debug\Renderer` contracts, the `Phalcon\Support\Debug\ReportBuilder` and `Phalcon\Support\Debug\Renderer\HtmlRenderer` classes, and the value objects `Phalcon\Support\Debug\Report\ExceptionReport` and `Phalcon\Support\Debug\Report\BacktraceItem`. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Added the `Phalcon\Queue\AdapterFactory` and `Phalcon\Queue\QueueFactory` factories, and registered the `queueFactory` service in `Phalcon\Di\FactoryDefault` and `Phalcon\Di\FactoryDefault\Cli`. [#17051](https://github.com/phalcon/cphalcon/issues/17051) [[doc]](https://docs.phalcon.io/5.15/queue/)
- Added the `Phalcon\Queue` component, a first-class queue/messaging layer modeled on the queue-interop contracts, with the `Phalcon\Contracts\Queue\*` interfaces (`ConnectionFactory`, `Context`, `Destination`, `Queue`, `Topic`, `Producer`, `Consumer`, `SubscriptionConsumer`, `Message`, `Processor`, `VisibilityAware`) and the `Phalcon\Queue\Exceptions\*` hierarchy (`QueueThrowable`, `Exception` and the typed `Invalid*` / `*NotSupportedException` exceptions). [#17051](https://github.com/phalcon/cphalcon/issues/17051) [[doc]](https://docs.phalcon.io/5.15/queue/)
- Added the queue consumer runner (`Phalcon\Queue\Consumer\QueueConsumer`, `Worker`, `WorkerOptions`, `BoundProcessor`, `Events`) and the CLI consumer task `Phalcon\Queue\Cli\ConsumerTask`. [#17051](https://github.com/phalcon/cphalcon/issues/17051) [[doc]](https://docs.phalcon.io/5.15/queue/)
- Added the same liveness and opt-in auto-reconnect support to `Phalcon\DataMapper\Pdo\Connection` (`ping()`, `ensureConnection()`, `setAutoReconnect()`/`getAutoReconnect()`), wrapping `exec()`, `perform()`, `prepare()`, and `query()` with the single-retry behavior. This connection has no events manager, so no `db:connectionLost` event is fired; "gone away" detection is driver-agnostic and the in-transaction guard uses a locally tracked transaction level. [#17204](https://github.com/phalcon/cphalcon/issues/17204) [[doc]](https://docs.phalcon.io/5.15/db-layer/)

### Fixed

- Fixed `Phalcon\Mvc\Model::cloneResultMap()` calling model setters during ORM hydration unconditionally (introduced in 5.12.0 via [#14810](https://github.com/phalcon/cphalcon/issues/14810)), which ran user setters on every record hydrated by `find()`/`findFirst()`; a setter that issued an ORM query (e.g. `self::findFirstByEmail()`) recursed infinitely, as `findFirst()` re-entered `cloneResultMap()`, which re-invoked the setter, which called `findFirst()` again. Hydration setters are now gated by a dedicated `orm.call_setters_on_hydration` setting (default `false`), decoupled from `orm.disable_assign_setters` (which still governs `assign()`); this restores the pre-5.12.0 hydration behaviour by default and makes setter execution during hydration opt-in. [#17214](https://github.com/phalcon/cphalcon/issues/17214) [[doc]](https://docs.phalcon.io/5.15/db-models/)
- Fixed `Phalcon\Mvc\Router\Route::compilePattern()` and `Phalcon\Cli\Router\Route::compilePattern()` expanding the `:params` placeholder - and the built-in `/:controller/:action/:params` and `/:task/:action/:params` default routes - to the nested quantifier `(/.*)*`. The group body overlaps itself, so an unmatchable trailing byte made the compiled pattern backtrack catastrophically: a short crafted URI (a run of `/` followed by a byte `.` cannot match) drove the `preg_match()` in `Phalcon\Mvc\Router::handle()` / `Phalcon\Cli\Router::handle()` into exponential time on every request. The trailing group is now compiled to the equivalent `(/.*)?`, which captures the same `params` value in linear time. [[doc]](https://docs.phalcon.io/5.15/routing/)
- Fixed `Phalcon\Support\Debug` ignoring the `request` entry of `setBlacklist()`: `$_REQUEST` is now filtered against the `request` blacklist, where previously both superglobals were filtered against the `server` blacklist only. [#17202](https://github.com/phalcon/cphalcon/issues/17202) [[doc]](https://docs.phalcon.io/5.15/support-debug/)
- Fixed `Phalcon\Tag\Select::selectField()` to invoke the resultset `using` render callback only when it is a `Closure` (previously any object), keeping the dynamically invoked callable out of reach of user-controlled data. [#17210](https://github.com/phalcon/cphalcon/issues/17210)

### Removed

## [5.15.0](https://github.com/phalcon/cphalcon/releases/tag/v5.15.0) (2026-06-18)

### Tools

- Zephir Parser v2.0.4
- Zephir 0.23.0 (development - 27535f802)

### Changed

- Changed `Phalcon\Acl\Adapter\Memory` to fire the `acl:beforeCheckAccess` and `acl:afterCheckAccess` events with an immutable array payload (`role`, `component`, `access`, plus `granted` on the `after` event) as the event data, instead of passing the adapter instance. [#17143](https://github.com/phalcon/cphalcon/issues/17143) [[doc]](https://docs.phalcon.io/5.15/acl/)
- Changed `Phalcon\Assets\AssetInterface` and `Phalcon\Assets\FilterInterface` to extend the new `Phalcon\Contracts\Assets\Asset` and `Phalcon\Contracts\Assets\Filter` contracts. [#17147](https://github.com/phalcon/cphalcon/issues/17147) [[doc]](https://docs.phalcon.io/5.15/assets/)
- Changed `Phalcon\Assets\Collection::has()` to an O(1) keyed lookup (`isset`) over the asset store instead of a linear scan. [#17147](https://github.com/phalcon/cphalcon/issues/17147) [[doc]](https://docs.phalcon.io/5.15/assets/)
- Changed `Phalcon\Assets\Manager` to reject any collection filter that is not a `Phalcon\Assets\FilterInterface` instance with `Phalcon\Assets\Exceptions\InvalidFilter`, instead of a fatal error when a non-conforming object reached `filter()`. [#17147](https://github.com/phalcon/cphalcon/issues/17147) [[doc]](https://docs.phalcon.io/5.15/assets/)
- Changed `Phalcon\Auth\Guard\Session` to accept an optional `Phalcon\Time\Clock\ClockInterface`; the remember-me cookie expiry now reads "now" through the clock, defaulting to `Phalcon\Time\Clock\SystemClock::fromUTC()`. [#17151](https://github.com/phalcon/cphalcon/issues/17151) [[doc]](https://docs.phalcon.io/5.15/auth/) [[doc]](https://docs.phalcon.io/5.15/time-clock/)
- Changed `Phalcon\Auth\Manager::attempt()` and `Phalcon\Auth\Manager::logout()` to throw `Phalcon\Auth\Exceptions\DoesNotImplement` (a subclass of `Phalcon\Auth\Exception`) when the default guard does not implement `GuardStateful`. [#17148](https://github.com/phalcon/cphalcon/issues/17148) [[doc]](https://docs.phalcon.io/5.15/auth/)
- Changed `Phalcon\Auth\ManagerFactory` to validate the required guard configuration keys (`type`, `adapter`, and the adapter `name`) up front, throwing a diagnostic `Phalcon\Auth\Exception` instead of a notice and `TypeError`. [#17148](https://github.com/phalcon/cphalcon/issues/17148) [[doc]](https://docs.phalcon.io/5.15/auth/)
- Changed `Phalcon\Autoload\Exceptions\LoaderDirectoriesNotArray` to accept an optional namespace name; when supplied, the message names the namespace whose directory registration failed. [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)
- Changed `Phalcon\Autoload\Loader::getFoundPath()` to return the resolved path for every lookup strategy (class map, namespace, directory), not only for file loading. [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)
- Changed `Phalcon\Autoload\Loader` to drop the redundant directory and namespace-prefix re-normalization on the namespace resolution path (no behavior change). [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)
- Changed `Phalcon\Cache\AbstractCache::checkKey()` and `Phalcon\Cache\AbstractCache::checkKeys()` to throw the exception class returned by `getExceptionClass()` (defaulting to `Phalcon\Cache\Exception\InvalidArgumentException`) instead of the dedicated `InvalidCacheKey` / `CacheKeysNotIterable` subclasses, so the thrown type can be overridden (for example to restore the PSR-16 marker). The exception messages are unchanged. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Changed `Phalcon\Cache\AbstractCache::checkKey()` to reject an empty-string key, so every cache operation now throws for `""`, matching the PSR-16 requirement that keys be non-empty and closing the bare-prefix collision channel. [#17164](https://github.com/phalcon/cphalcon/issues/17164) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Changed `Phalcon\Cache\AbstractCache::doDelete()` to validate the key before firing the `cache:beforeDelete` event, matching `doGet()`/`doSet()`/`doHas()`; the event no longer fires for a delete that throws on an invalid key. [#17164](https://github.com/phalcon/cphalcon/issues/17164) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Changed `Phalcon\Cache\AbstractCache::doSetMultiple()` to validate every key before writing any item, so an invalid key fails the operation up front instead of leaving the already-written pairs persisted behind the thrown exception. [#17164](https://github.com/phalcon/cphalcon/issues/17164) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Changed `Phalcon\Cache\CacheInterface` to extend the new `Phalcon\Contracts\Cache\Cache` contract. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Changed `Phalcon\Cli\Router::handle()` to return the router instance on every path; the matched branch previously returned `null`. [#17165](https://github.com/phalcon/cphalcon/issues/17165) [[doc]](https://docs.phalcon.io/5.15/application-cli/)
- Changed `Phalcon\Cli\Router\Exceptions\BeforeMatchNotCallable`, `Phalcon\Cli\Router\Exceptions\InvalidRoutePaths`, and `Phalcon\Cli\Router\Exceptions\RouterArgumentsInvalidType` to accept optional context (the route pattern, the route pattern, and the received type respectively) and include it in the exception message. [#17165](https://github.com/phalcon/cphalcon/issues/17165) [[doc]](https://docs.phalcon.io/5.15/application-cli/)
- Changed `Phalcon\Cli\Router\Route::beforeMatch()` to reject a non-callable callback at registration with `Phalcon\Cli\Router\Exceptions\BeforeMatchNotCallable`, instead of deferring the failure to match time, matching the `Phalcon\Mvc\Router\Route` behavior. [#17165](https://github.com/phalcon/cphalcon/issues/17165) [[doc]](https://docs.phalcon.io/5.15/application-cli/)
- Changed `Phalcon\Contracts\Paginator\Adapter::setCurrentPage()` and `Phalcon\Contracts\Paginator\Adapter::setLimit()` to return the `Phalcon\Contracts\Paginator\Adapter` contract instead of the implementation-side `Phalcon\Paginator\Adapter\AdapterInterface`, removing the contract layer's dependency on the implementation namespace. Implementations returning the narrower interface remain covariant-compatible. [#17153](https://github.com/phalcon/cphalcon/issues/17153) [[doc]](https://docs.phalcon.io/5.15/db-pagination/)
- Changed `Phalcon\Contracts\Paginator\Repository` to document the offset and cursor adapter dialects on its getters: cursor adapters (`Phalcon\Paginator\Adapter\QueryBuilderCursor`) store cursor values in `getCurrent()`/`getNext()` and do not compute `getTotalItems()`, `getLast()` or `getPrevious()` (returning `0`). [#17153](https://github.com/phalcon/cphalcon/issues/17153) [[doc]](https://docs.phalcon.io/5.15/db-pagination/)
- Changed `Phalcon\Db\Adapter\AbstractAdapter::__construct()` to reject a `dialectClass` descriptor object that does not implement `Phalcon\Db\DialectInterface` with the new `Phalcon\Db\Exceptions\InvalidDialectClass` at construction time, instead of deferring the failure to first use. [#17163](https://github.com/phalcon/cphalcon/issues/17163) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Changed `Phalcon\Db\Adapter\AbstractAdapter::tableExists()` and `Phalcon\Db\Adapter\AbstractAdapter::tableOptions()` to return `false` and `[]` respectively when the metadata query returns no rows, instead of emitting a notice on a missing array offset. [#17163](https://github.com/phalcon/cphalcon/issues/17163) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Changed `Phalcon\Db\Geometry\GeometryInterface` to extend the new `Phalcon\Contracts\Db\Geometry\Geometry` contract. [#17163](https://github.com/phalcon/cphalcon/issues/17163) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Changed `Phalcon\Dispatcher\AbstractDispatcher::callActionMethod()` to build the `dispatch:beforeCallAction`/`afterCallAction` observer `Phalcon\Support\Collection` directly instead of resolving it from the DI container by class name, removing a per-action container lookup on the hot path. (Release note: an application that registered a `Phalcon\Support\Collection` service to override that lookup is no longer consulted here.) [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Changed `Phalcon\Dispatcher\AbstractDispatcher::callActionMethod()` to re-validate the handler/action pair with `is_callable()` after the `dispatch:beforeCallAction` observer runs, so a listener that substitutes a non-existent action now fails through the `EXCEPTION_ACTION_NOT_FOUND` channel instead of a raw `call_user_func_array()` fatal. [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Changed `Phalcon\Dispatcher\AbstractDispatcher` to declare its `throwDispatchException()` and `handleException()` error hooks as `abstract protected` methods and call them directly instead of through dynamic string dispatch. A custom dispatcher that omits either now fails when the class is loaded rather than with an undefined-method fatal on the first error path. [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Changed `Phalcon\Dispatcher\AbstractDispatcher` to document its three lifecycle hook channels (events-manager listener, duck-typed handler method, and the `dispatch:beforeCallAction` observer), record the `afterBinding` blocks' intentional bypass of `handleException()`, and correct the stale initialize-ordering note that referenced Phalcon 4.0 (no behavior change). [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Changed `Phalcon\Dispatcher\DispatcherInterface`, `Phalcon\Mvc\DispatcherInterface`, and `Phalcon\Cli\DispatcherInterface` to extend the new `Phalcon\Contracts\Dispatcher\Dispatcher`, `Phalcon\Contracts\Mvc\Dispatcher`, and `Phalcon\Contracts\Cli\Dispatcher` contracts. [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Changed `Phalcon\Domain\Payload\PayloadInterface`, `Phalcon\Domain\Payload\ReadableInterface`, and `Phalcon\Domain\Payload\WriteableInterface` to extend the new `Phalcon\Contracts\Domain\Payload\Payload`, `Phalcon\Contracts\Domain\Payload\Readable`, and `Phalcon\Contracts\Domain\Payload\Writeable` contracts. [#17162](https://github.com/phalcon/cphalcon/issues/17162) [[doc]](https://docs.phalcon.io/5.15/domain/)
- Changed `Phalcon\Encryption\Crypt::decrypt()` to reject input shorter than the selected cipher requires up front with the new `Phalcon\Encryption\Crypt\Exception\InvalidDecryptLength`, instead of failing later as the less specific `Phalcon\Encryption\Crypt\Exception\DecryptionFailed`. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Changed `Phalcon\Encryption\Crypt::setAuthTagLength()` to validate that the length is between 4 and 16 bytes, throwing the new `Phalcon\Encryption\Crypt\Exception\InvalidAuthTagLength` instead of accepting any integer. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Changed `Phalcon\Encryption\Crypt\CryptInterface` and `Phalcon\Encryption\Crypt\Padding\PadInterface` to extend the new `Phalcon\Contracts\Encryption\Crypt\Crypt` and `Phalcon\Contracts\Encryption\Crypt\Padding\Pad` contracts. [#17162](https://github.com/phalcon/cphalcon/issues/17162) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Changed `Phalcon\Encryption\Crypt\PadFactory::padNumberToService()` to throw on an unknown padding constant instead of silently mapping it to the no-op padding (fail closed). [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Changed `Phalcon\Encryption\Crypt` and `Phalcon\Encryption\Crypt\CryptInterface` to drop the unreachable ECB padding branches (ECB ciphers are filtered out at construction) and to document the encrypted payload wire format (`iv ‖ hmac ‖ ciphertext ‖ tag`) and the AEAD parameter statefulness. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Changed `Phalcon\Encryption\Security\JWT\Signer\SignerInterface` to extend the new `Phalcon\Contracts\Encryption\Security\JWT\Signer\Signer` contract. [#17162](https://github.com/phalcon/cphalcon/issues/17162) [[doc]](https://docs.phalcon.io/5.15/encryption-security-jwt/)
- Changed `Phalcon\Encryption\Security\JWT\Validator` to accept an optional `Phalcon\Time\Clock\ClockInterface` constructor parameter for reading the current time; `timeShift` is retained as the legacy clock-skew mechanism. [#17151](https://github.com/phalcon/cphalcon/issues/17151) [[doc]](https://docs.phalcon.io/5.15/encryption-security/) [[doc]](https://docs.phalcon.io/5.15/time-clock/)
- Changed `Phalcon\Encryption\Security\Uuid\UuidInterface`, `Phalcon\Encryption\Security\Uuid\TimeBasedUuidInterface`, and `Phalcon\Encryption\Security\Uuid\NodeProviderInterface` to extend the new `Phalcon\Contracts\Encryption\Security\Uuid\Uuid`, `Phalcon\Contracts\Encryption\Security\Uuid\TimeBasedUuid`, and `Phalcon\Contracts\Encryption\Security\Uuid\NodeProvider` contracts. [#17162](https://github.com/phalcon/cphalcon/issues/17162) [[doc]](https://docs.phalcon.io/5.15/encryption-security/)
- Changed `Phalcon\Flash\AbstractFlash` to declare `message()` as an `abstract public` method and call it directly from `error()`, `notice()`, `success()`, and `warning()` instead of through dynamic string dispatch. [#17158](https://github.com/phalcon/cphalcon/issues/17158) [[doc]](https://docs.phalcon.io/5.15/flash/)
- Changed `Phalcon\Flash\FlashInterface` to extend the new `Phalcon\Contracts\Flash\Flash` contract. [#17158](https://github.com/phalcon/cphalcon/issues/17158) [[doc]](https://docs.phalcon.io/5.15/flash/)
- Changed `Phalcon\Flash\Session::output()` to no longer discard the accumulated messages when implicit flush is disabled; it now clears the buffer only in the implicit-flush (echo) mode, so with implicit flush off the rendered messages remain reachable instead of being silently destroyed. [#17158](https://github.com/phalcon/cphalcon/issues/17158) [[doc]](https://docs.phalcon.io/5.15/flash/)
- Changed `Phalcon\Html\Attributes::renderAttributes()` to escape attribute values through `Phalcon\Html\Escaper\AttributeEscaper` instead of a hardcoded `htmlspecialchars()` call, consolidating attribute escaping in one place. Output is byte-identical for the default configuration (`ENT_QUOTES`, UTF-8, double-encode on). [#17157](https://github.com/phalcon/cphalcon/issues/17157) [[doc]](https://docs.phalcon.io/5.15/html-attributes/)
- Changed `Phalcon\Html\Breadcrumbs::render()` to return an empty string when no crumbs have been added, instead of indexing `end([])` and emitting a PHP warning followed by a malformed single-crumb `<dl>`. [#17157](https://github.com/phalcon/cphalcon/issues/17157) [[doc]](https://docs.phalcon.io/5.15/html-breadcrumbs/)
- Changed `Phalcon\Html\Link\Serializer\Header::serialize()` to escape embedded backslashes and double quotes in attribute values per the RFC 8288 quoted-string rules, so an attribute value containing a double quote no longer produces a malformed `Link` header. [#17157](https://github.com/phalcon/cphalcon/issues/17157) [[doc]](https://docs.phalcon.io/5.15/html-link/)
- Changed `Phalcon\Image\Adapter\AbstractAdapter::background()` and `Phalcon\Image\Adapter\AbstractAdapter::text()` to validate the supplied hex color through a single shared parser, throwing the new `Phalcon\Image\Exceptions\InvalidColor` for a malformed color instead of silently producing incorrect channel values. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/image/)
- Changed `Phalcon\Image\Adapter\AbstractAdapter` to declare its fourteen `process*` operations as `abstract protected` methods and call them directly instead of through dynamic string dispatch. A custom adapter that omits one now fails when the class is loaded rather than with an undefined-method fatal on the first operation. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/image/)
- Changed `Phalcon\Image\Adapter\Gd::__construct()` to throw `Phalcon\Image\Exceptions\ImageLoadFailed` when an existing file cannot be read (for example a corrupt or unreadable image), instead of falling through to `Phalcon\Image\Exceptions\UnsupportedImageType` with no context. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/image/)
- Changed `Phalcon\Logger\AbstractLogger::addMessage()` to route each adapter through a direct `add()`/`process()` conditional instead of a dynamic method-name dispatch, and normalized the `defaultFormatter` class-string escaping in `Phalcon\Logger\Adapter\AbstractAdapter` (no behavior change). [#17155](https://github.com/phalcon/cphalcon/issues/17155) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Changed `Phalcon\Logger\AbstractLogger` to accept an optional `Phalcon\Time\Clock\ClockInterface` constructor parameter; log item timestamps now come from the clock, defaulting to a `Phalcon\Time\Clock\SystemClock` on the logger timezone (current behavior preserved). [#17151](https://github.com/phalcon/cphalcon/issues/17151) [[doc]](https://docs.phalcon.io/5.15/logger/) [[doc]](https://docs.phalcon.io/5.15/time-clock/)
- Changed `Phalcon\Logger\Adapter\AbstractAdapter::__destruct()` to auto-commit an open transaction, flushing the queued items, instead of throwing `Phalcon\Logger\Exceptions\TransactionAlreadyActive`. Throwing from a destructor is fatal during script shutdown, so an exception unwinding past a `commit()` no longer escalates a lost log buffer into a process fatal. [#17155](https://github.com/phalcon/cphalcon/issues/17155) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Changed `Phalcon\Logger\Adapter\AbstractAdapter::begin()` to throw `Phalcon\Logger\Exceptions\TransactionAlreadyActive` when a transaction is already active, instead of silently re-arming the flag. [#17155](https://github.com/phalcon/cphalcon/issues/17155) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Changed `Phalcon\Logger\LoggerInterface`, `Phalcon\Logger\Adapter\AdapterInterface`, and `Phalcon\Logger\Formatter\FormatterInterface` to extend the new `Phalcon\Contracts\Logger\Logger`, `Phalcon\Contracts\Logger\Adapter\Adapter`, and `Phalcon\Contracts\Logger\Formatter\Formatter` contracts. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Changed `Phalcon\Messages\Messages::appendMessages()` to reject a non-`Traversable` object with `Phalcon\Messages\Exceptions\MessagesNotIterable`, instead of a fatal error on `rewind()`. [#17154](https://github.com/phalcon/cphalcon/issues/17154) [[doc]](https://docs.phalcon.io/5.15/filter-validation/)
- Changed `Phalcon\Messages\Messages::offsetSet()` to require a `Phalcon\Messages\MessageInterface` instance, throwing `Phalcon\Messages\Exceptions\MessageNotObject` for any other value instead of accepting any object; the exception message now states the required type. [#17154](https://github.com/phalcon/cphalcon/issues/17154) [[doc]](https://docs.phalcon.io/5.15/filter-validation/)
- Changed `Phalcon\Messages\Messages` to implement the new `Phalcon\Contracts\Messages\Messages` contract; the concrete type is unchanged. [#17154](https://github.com/phalcon/cphalcon/issues/17154) [[doc]](https://docs.phalcon.io/5.15/filter-validation/)
- Changed `Phalcon\Mvc\Application\Exceptions\InvalidModuleDefinition` and `Phalcon\Cli\Console\Exceptions\InvalidModuleDefinition` to accept an optional module name and reason in the constructor. The exception message now identifies the offending module and why its definition is invalid. [#17146](https://github.com/phalcon/cphalcon/issues/17146) [[doc]](https://docs.phalcon.io/5.15/application/) [[doc]](https://docs.phalcon.io/5.15/application-cli/)
- Changed `Phalcon\Mvc\ModelInterface::find()` to document the four query dialects and their intended lanes (find-parameter arrays, `Phalcon\Mvc\Model\Query\Builder`, `Phalcon\Mvc\Model\Criteria`, and raw PHQL) (no behavior change). [#17166](https://github.com/phalcon/cphalcon/issues/17166) [[doc]](https://docs.phalcon.io/5.15/db-models/)
- Changed `Phalcon\Mvc\Model\MetaData` to document its two positional metadata array layouts on the class docblock - the 14-slot attribute array and the 2-slot column map - noting that the two constant families share numeric values and that the metadata cache adapters persist the layout (no behavior change). [#17166](https://github.com/phalcon/cphalcon/issues/17166) [[doc]](https://docs.phalcon.io/5.15/db-models-metadata/)
- Changed `Phalcon\Mvc\Model` to document the `__get`/`__call`/`__callStatic` magic-resolution order and finder grammar on its class docblock, and that `Phalcon\Mvc\Model::setup()` writes process-global `orm.*` settings that affect every model in the process (no behavior change). [#17166](https://github.com/phalcon/cphalcon/issues/17166) [[doc]](https://docs.phalcon.io/5.15/db-models/)
- Changed `Phalcon\Paginator\Adapter\AbstractAdapter` to require the `limit` option and `Phalcon\Paginator\Adapter\Model` to require the `model` option in their constructors, both throwing `Phalcon\Paginator\Exceptions\MissingRequiredParameter`, matching the `Phalcon\Paginator\Adapter\QueryBuilder` and `Phalcon\Paginator\Adapter\QueryBuilderCursor` adapters. Previously a missing `limit` reached a division-by-zero in `Model`/`NativeArray` and a missing `model` produced a notice followed by a fatal. [#17153](https://github.com/phalcon/cphalcon/issues/17153) [[doc]](https://docs.phalcon.io/5.15/db-pagination/)
- Changed `Phalcon\Paginator\Adapter\QueryBuilderCursor` to throw `Phalcon\Paginator\Exceptions\InvalidCursorColumn` when the cursor column value of the last row is non-numeric, instead of casting it to `0` and silently terminating pagination (e.g. over UUID or ULID keys). [#17153](https://github.com/phalcon/cphalcon/issues/17153) [[doc]](https://docs.phalcon.io/5.15/db-pagination/)
- Changed `Phalcon\Paginator\Adapter\QueryBuilder` to explicitly initialize its internal `hasMultipleGroups` flag and documented that the `columns` constructor option is consumed only by the total-count rewrite for `HAVING`/`GROUP BY` queries. [#17153](https://github.com/phalcon/cphalcon/issues/17153) [[doc]](https://docs.phalcon.io/5.15/db-pagination/)
- Changed `Phalcon\Session\Adapter\Redis::read()` to short-circuit a re-entrant read when this instance already holds the lock for the same session id, returning the held lock instead of spinning against its own lock for the full retry budget before throwing `Phalcon\Session\Adapter\Exceptions\AdapterRuntimeError` (the `session_reset()` re-read path). Only the self-deadlock scenario changes. [#17167](https://github.com/phalcon/cphalcon/issues/17167) [[doc]](https://docs.phalcon.io/5.15/session/)
- Changed `Phalcon\Session\Manager::setId()` to validate the supplied id against the PHP session-id alphabet (`[a-zA-Z0-9,-]`), throwing the new `Phalcon\Session\Exceptions\InvalidSessionId`, matching the cookie validation already performed in `start()` instead of passing an invalid id straight to `session_id()`. [#17167](https://github.com/phalcon/cphalcon/issues/17167) [[doc]](https://docs.phalcon.io/5.15/session/)
- Changed `Phalcon\Session\Manager::setName()` to reject a digits-only name with `Phalcon\Session\Exceptions\InvalidSessionName`, instead of letting PHP emit a `session_name()` warning and silently leave the name unchanged. [#17167](https://github.com/phalcon/cphalcon/issues/17167) [[doc]](https://docs.phalcon.io/5.15/session/)
- Changed `Phalcon\Storage\Adapter\AbstractAdapter::doGet()` and the `Phalcon\Storage\Adapter\Stream` counter and delete internals to route through the protected `do*` primitives instead of re-entering the public `get()`/`set()`/`has()`/`delete()` surface. A networked read on `Redis`/`Libmemcached` no longer issues a separate `EXISTS` before `GET` (roughly halving the round trips), and no fabricated nested `before*`/`after*` events are fired - event listeners now observe the real operation sequence (a behavior note for listeners, not a break). [#17168](https://github.com/phalcon/cphalcon/issues/17168) [[doc]](https://docs.phalcon.io/5.15/storage/)
- Changed `Phalcon\Storage\Adapter\AbstractAdapter::getArrVal()` to delegate to the canonical `Phalcon\Support\Helper\Arr\Get` helper instead of carrying its own diverged copy (no behavior change). [#17168](https://github.com/phalcon/cphalcon/issues/17168) [[doc]](https://docs.phalcon.io/5.15/storage/)
- Changed `Phalcon\Storage\Adapter\AbstractAdapter::getUnserializedData()` to guard the `isSuccess()` call with `method_exists()`, defaulting to success. A custom serializer implementing only `Phalcon\Storage\Serializer\SerializerInterface` (which does not declare `isSuccess()`) no longer fatals on the first cache miss or corrupt entry. [#17168](https://github.com/phalcon/cphalcon/issues/17168) [[doc]](https://docs.phalcon.io/5.15/storage/)
- Changed `Phalcon\Storage\Adapter\Redis::getKeys()` to enumerate keys with a non-blocking `SCAN` iteration instead of the blocking `KEYS *` command, removing the production hazard on large keyspaces while returning the same keys. `Phalcon\Storage\Adapter\RedisCluster::getKeys()` retains `KEYS` because cluster `SCAN` iterates one node at a time. [#17168](https://github.com/phalcon/cphalcon/issues/17168) [[doc]](https://docs.phalcon.io/5.15/storage/)
- Changed `Phalcon\Support\Collection::sort()` to throw `InvalidArgumentException` when given a non-callable callback, instead of fataling inside `uasort()`, and to compare against the `SORT_ASC`/`SORT_DESC` constants rather than the literals `4`/`3`. [#17152](https://github.com/phalcon/cphalcon/issues/17152) [[doc]](https://docs.phalcon.io/5.15/support-collection/)
- Changed `Phalcon\Support\Helper\Str\AbstractStr` and `Phalcon\Support\Helper\Arr\AbstractArr` to be marked `@internal`, documenting that they exist only for their respective helper hierarchies; new code should compose the invokable helpers (`Phalcon\Support\Helper\Str\Interpolate`, `Phalcon\Support\Helper\Arr\Get`) rather than extending these bases. [#17152](https://github.com/phalcon/cphalcon/issues/17152) [[doc]](https://docs.phalcon.io/5.15/support-helper/)
- Changed `Phalcon\Support\Settings::get()` and `Phalcon\Support\Settings::set()` to share a single internal reader for the setting whitelist instead of duplicating the list across the read and write paths, removing the drift risk between them. [#17152](https://github.com/phalcon/cphalcon/issues/17152) [[doc]](https://docs.phalcon.io/5.15/support-settings/)
- Changed `Phalcon\Translate\Adapter\AbstractAdapter` and `Phalcon\Translate\Interpolator\AssociativeArray` to memoize the interpolator instance and the `Phalcon\Support\Helper\Str\Interpolate` helper respectively, removing two object allocations per translation call on the hot path. [#17150](https://github.com/phalcon/cphalcon/issues/17150) [[doc]](https://docs.phalcon.io/5.15/translate/)
- Changed `Phalcon\Translate\Adapter\AbstractAdapter` to host the `triggerError` strict-mode option and the `notFound()` hook (lifted from `Phalcon\Translate\Adapter\NativeArray`), so `Phalcon\Translate\Adapter\Csv` and `Phalcon\Translate\Adapter\Gettext` now also support strict mode - a missing key throws `Phalcon\Translate\Exceptions\KeyNotFound` when `triggerError` is enabled. Defaults preserve current behavior. [#17150](https://github.com/phalcon/cphalcon/issues/17150) [[doc]](https://docs.phalcon.io/5.15/translate/)
- Changed several `Phalcon\Assets` exceptions to provide better descriptions. [#17147](https://github.com/phalcon/cphalcon/issues/17147) [[doc]](https://docs.phalcon.io/5.15/assets/)
- Changed the Redis fast path in `Phalcon\Cache\AbstractCache::doGetMultiple()` to validate each key, accept `Traversable` inputs (previously a `TypeError` on the Redis adapter only), and apply the serializer's full unserialize protocol (returning the default value for a corrupt entry), aligning it with the per-key loop path used by the other adapters. [#17164](https://github.com/phalcon/cphalcon/issues/17164) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Changed the `Phalcon\Application\Exceptions\ModuleNotRegistered` message to be more descriptive. [#17146](https://github.com/phalcon/cphalcon/issues/17146) [[doc]](https://docs.phalcon.io/5.15/application/) [[doc]](https://docs.phalcon.io/5.15/application-cli/)
- Changed the `Phalcon\Auth\Guard\Session` `auth:*` events to fire as non-cancellable, matching that their return value was already ignored. [#17148](https://github.com/phalcon/cphalcon/issues/17148) [[doc]](https://docs.phalcon.io/5.15/auth/)
- Changed the `Phalcon\Auth\Guard\Session` remember-me cookie lifetime to a configurable `Phalcon\Auth\Guard\Config\SessionGuardConfig` value (`rememberTtl`, default `DEFAULT_REMEMBER_TTL`); the default is now 365 days (previously a hardcoded 360). [#17148](https://github.com/phalcon/cphalcon/issues/17148) [[doc]](https://docs.phalcon.io/5.15/auth/)
- Changed the `Phalcon\Auth` adapters (`Memory`, `Stream`, `Model`) to verify the configured user model implements `Phalcon\Contracts\Auth\AuthUser` during hydration, throwing `Phalcon\Auth\Exceptions\DoesNotImplement` instead of failing later. [#17148](https://github.com/phalcon/cphalcon/issues/17148) [[doc]](https://docs.phalcon.io/5.15/auth/)
- Changed the `Phalcon\Autoload\Loader` class-map strategy to fire the `loader:beforeCheckPath` event before probing, matching the namespace and directory strategies. [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)
- Changed the `Phalcon\Flash\Exceptions\EscaperServiceUnavailable` and `Phalcon\Flash\Exceptions\SessionServiceUnavailable` messages to "The '<service>' service is not available (no container, or service not registered)", describing both trigger conditions (no container at all, or a container that lacks the service). [#17158](https://github.com/phalcon/cphalcon/issues/17158) [[doc]](https://docs.phalcon.io/5.15/flash/)
- Deprecated `Phalcon\Assets\Filters\Cssmin` and `Phalcon\Assets\Filters\Jsmin`; both return the content unchanged (the minification has never been implemented). [#17147](https://github.com/phalcon/cphalcon/issues/17147) [[doc]](https://docs.phalcon.io/5.15/assets/)
- Deprecated `Phalcon\Cli\Router::getParams()` and `Phalcon\Cli\RouterInterface::getParams()` in favor of `getParameters()`. [#17165](https://github.com/phalcon/cphalcon/issues/17165) [[doc]](https://docs.phalcon.io/5.15/application-cli/)
- Deprecated the `Phalcon\Dispatcher\AbstractDispatcher` and `Phalcon\Dispatcher\DispatcherInterface` parameter accessors `getParam()`, `getParams()`, `hasParam()`, `setParam()`, and `setParams()` in favor of their `getParameter()`, `getParameters()`, `hasParameter()`, `setParameter()`, and `setParameters()` counterparts; the deprecated spellings will be removed in the next major version. [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Deprecated the `Phalcon\Encryption\Security` constants `CRYPT_STD_DES`, `CRYPT_EXT_DES`, `CRYPT_BLOWFISH`, and `CRYPT_BLOWFISH_Y` (never implemented; they resolve to bcrypt) and `CRYPT_MD5` (weak legacy algorithm); any unhandled `defaultHash` value resolves to bcrypt. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-security/)

### Added

- Added `Phalcon\Contracts\Assets\Asset` and `Phalcon\Contracts\Assets\Filter`, the canonical contracts for `Phalcon\Assets\Asset` and the Assets filters. They are the long-term replacements for the deprecated `Phalcon\Assets\AssetInterface` and `Phalcon\Assets\FilterInterface`. [#17147](https://github.com/phalcon/cphalcon/issues/17147) [[doc]](https://docs.phalcon.io/5.15/assets/)
- Added `Phalcon\Contracts\Cache\Cache`, the canonical contract for `Phalcon\Cache\Cache` (the PSR-16-shaped cache surface). It is the long-term replacement for the deprecated `Phalcon\Cache\CacheInterface`. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/cache/)
- Added `Phalcon\Contracts\Db\Geometry\Geometry`, the canonical contract for the `Phalcon\Db\Geometry` value objects (`getSrid()`, `getType()`, `toWkt()`). It is the long-term replacement for the deprecated `Phalcon\Db\Geometry\GeometryInterface`. [#17163](https://github.com/phalcon/cphalcon/issues/17163) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Added `Phalcon\Contracts\Dispatcher\Dispatcher`, `Phalcon\Contracts\Mvc\Dispatcher`, and `Phalcon\Contracts\Cli\Dispatcher`, the canonical contracts for `Phalcon\Dispatcher\AbstractDispatcher`, `Phalcon\Mvc\Dispatcher`, and `Phalcon\Cli\Dispatcher`. They are the long-term replacements for the deprecated `Phalcon\Dispatcher\DispatcherInterface`, `Phalcon\Mvc\DispatcherInterface`, and `Phalcon\Cli\DispatcherInterface`. [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Added `Phalcon\Contracts\Flash\Flash`, the canonical contract for the `Phalcon\Flash` messengers (`Phalcon\Flash\Direct`, `Phalcon\Flash\Session`). It is the long-term replacement for the deprecated `Phalcon\Flash\FlashInterface`. [#17158](https://github.com/phalcon/cphalcon/issues/17158) [[doc]](https://docs.phalcon.io/5.15/flash/)
- Added `Phalcon\Contracts\Logger\Logger`, `Phalcon\Contracts\Logger\Adapter\Adapter`, and `Phalcon\Contracts\Logger\Formatter\Formatter`, the canonical contracts for `Phalcon\Logger\Logger`, its adapters, and its formatters. They are the long-term replacements for the deprecated `Phalcon\Logger\LoggerInterface`, `Phalcon\Logger\Adapter\AdapterInterface`, and `Phalcon\Logger\Formatter\FormatterInterface`. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Added `Phalcon\Contracts\Messages\Messages`, the canonical contract for the `Phalcon\Messages\Messages` collection (append, count, filter, and iteration); the collection previously had no interface of its own. [#17154](https://github.com/phalcon/cphalcon/issues/17154) [[doc]](https://docs.phalcon.io/5.15/filter-validation/)
- Added `Phalcon\Db\Exceptions\InvalidDialectClass`, thrown by `Phalcon\Db\Adapter\AbstractAdapter::__construct()` when the `dialectClass` descriptor object does not implement `Phalcon\Db\DialectInterface`. [#17163](https://github.com/phalcon/cphalcon/issues/17163) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Added `Phalcon\Dispatcher\AbstractDispatcher::getPreviousActionName()`, `Phalcon\Dispatcher\AbstractDispatcher::getPreviousHandlerName()`, and `Phalcon\Dispatcher\AbstractDispatcher::getPreviousNamespaceName()`, lifting the previously MVC-only previous-dispatch getters to the base so `Phalcon\Cli\Dispatcher` gains them too. `Phalcon\Mvc\Dispatcher::getPreviousControllerName()` remains as a controller-named alias. [#17159](https://github.com/phalcon/cphalcon/issues/17159) [[doc]](https://docs.phalcon.io/5.15/dispatcher/)
- Added `Phalcon\Encryption\Crypt\Exception\InvalidAuthTagLength` and `Phalcon\Encryption\Crypt\Exception\InvalidDecryptLength`. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Added `Phalcon\Image\Adapter\Gd::create()` and `Phalcon\Image\Adapter\Imagick::create()`, static named constructors for the blank-canvas case that avoid the constructor's load-or-create ambiguity. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/image/)
- Added `Phalcon\Image\Exceptions\InvalidColor`, thrown when a malformed hex color is passed to `Phalcon\Image\Adapter\AbstractAdapter::background()` or `Phalcon\Image\Adapter\AbstractAdapter::text()`. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/image/)
- Added `Phalcon\Logger\AbstractLogger::begin()`, `Phalcon\Logger\AbstractLogger::commit()`, and `Phalcon\Logger\AbstractLogger::rollback()`, which fan the transaction out across every non-excluded adapter, so transactions can be controlled at the logger level instead of one adapter at a time. [#17155](https://github.com/phalcon/cphalcon/issues/17155) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Added a correctly-spelled `"pkcs7"` service alias to `Phalcon\Encryption\Crypt\PadFactory` alongside the existing (misspelled) `"pjcs7"`, so `newInstance("pkcs7")` resolves the PKCS7 padding. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Added an optional `sessionKey` constructor parameter to `Phalcon\Flash\Session` (defaulting to the existing `_flashMessages` key), letting multi-instance applications namespace their flash messages instead of sharing one session slot. [#17158](https://github.com/phalcon/cphalcon/issues/17158) [[doc]](https://docs.phalcon.io/5.15/flash/)
- Added the `Phalcon\Db\Dialect::supportsReturning()`, `Phalcon\Db\Dialect::supportsOnConflictUpdate()`, `Phalcon\Db\Dialect::supportsMaterializedViews()`, and `Phalcon\Db\Dialect::supportsAlterTable()` capability predicates (overridden per dialect to match each backend) so callers can detect an optional feature instead of catching its dedicated exception. [#17163](https://github.com/phalcon/cphalcon/issues/17163) [[doc]](https://docs.phalcon.io/5.15/db-layer/)

### Fixed

- Fixed `Phalcon\Autoload\Loader` reporting a successful autoload for a class-map entry whose mapped file does not exist; the class-map strategy now honors the `require` result and falls through to the namespace and directory strategies instead of short-circuiting them. [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)
- Fixed `Phalcon\Db\Adapter\Pdo\Mysql::describeColumns()` treating a column declared `DEFAULT NULL` as having the string `"NULL"` as its default (MySQL's `INFORMATION_SCHEMA.COLUMNS.COLUMN_DEFAULT` reports it that way since the 5.13.0 switch away from `SHOW FULL COLUMNS`); the sentinel is now read as no default. This stops a nullable column whose value is `null` from being turned into the string `"NULL"` on the model attribute after `save()`. [#17176](https://github.com/phalcon/cphalcon/issues/17176) [[doc]](https://docs.phalcon.io/5.15/db-layer/)
- Fixed `Phalcon\Encryption\Crypt::decrypt()` extracting the GCM/CCM authentication tag with `str_replace()`, which stripped every occurrence of the tag's byte sequence from the ciphertext rather than only the trailing tag. With short auth tags an interior collision corrupted the ciphertext and made a valid AEAD payload fail authentication; the tag is now split off by length. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Fixed `Phalcon\Encryption\Crypt\Padding\Pkcs7` and `Phalcon\Encryption\Crypt\Padding\Zero` measuring binary padded data with the encoding-sensitive `mb_strlen()`; on a multibyte-capable internal encoding this computed the padding size from the wrong byte and silently mis-unpadded. Both now use byte-true `strlen()`. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-crypt/)
- Fixed `Phalcon\Encryption\Security::hash()` discarding caller-supplied Argon2 tuning options (`memory_cost`, `time_cost`, `threads`); it rebuilt the options array with only `cost`, so a hardened configuration silently ran with defaults. The caller's options are now preserved. [#17160](https://github.com/phalcon/cphalcon/issues/17160) [[doc]](https://docs.phalcon.io/5.15/encryption-security/)
- Fixed `Phalcon\Filter\Validation::bind()` emitting an `Invalid arguments supplied for camelize()` warning when the data being validated against an entity contained a numeric (integer) key, as happened with `Phalcon\Forms\Form::isValid($data, $entity)`; integer keys are now skipped during entity binding. [#17173](https://github.com/phalcon/cphalcon/issues/17173) [[doc]](https://docs.phalcon.io/5.15/filter-validation/)
- Fixed `Phalcon\Logger\AbstractLogger::excludeAdapters()` leaving the exclusion list armed across calls when the level filter discarded the message; the list is now cleared on every `Phalcon\Logger\AbstractLogger::addMessage()` call, so an exclusion is consumed by the call that set it instead of skipping adapters on the next, unrelated log call. [#17155](https://github.com/phalcon/cphalcon/issues/17155) [[doc]](https://docs.phalcon.io/5.15/logger/)
- Fixed `Phalcon\Mvc\Model::sum()` and `Phalcon\Mvc\Model::average()` returning `null` on an empty result set, which violated their declared `float | ResultsetInterface` return type and raised a `TypeError` in any subclass that overrode them with the same type and delegated through `parent`. Both now coerce the empty aggregate to `0.0`. [#17184](https://github.com/phalcon/cphalcon/issues/17184) [[doc]](https://docs.phalcon.io/5.15/db-models/)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler::resolveFilter()` building the `join` filter by splicing the raw separator and array argument token values into the generated PHP - the separator dropped between two literal single quotes and the array emitted unquoted - instead of compiling them through `expression()` as every other Volt literal is. A `join` separator literal containing a single quote closed the generated `join('...')` call and injected arbitrary statements into the compiled template, which the Volt engine then ran when the view was rendered. Both arguments are now emitted through `expression()`, which quotes and escapes the separator. [[doc]](https://docs.phalcon.io/5.15/volt/)
- Fixed `Phalcon\Support\Collection` (and every descendant, including `Phalcon\Config\Config` and `Phalcon\Html\Attributes`) orphaning the previously stored entry when a key was overwritten with a different letter casing on a case-insensitive collection. `set("Key", 1)` followed by `set("KEY", 2)` left both entries in the backing store, so `count()`, `toArray()`, and iteration disagreed with `get()`, `has()`, and `remove()`. The stale entry is now evicted before the new value is written. [#17152](https://github.com/phalcon/cphalcon/issues/17152) [[doc]](https://docs.phalcon.io/5.15/support-collection/)
- Fixed `Phalcon\Time\Clock\FrozenClock::adjust()` leaving the process-global `warning.enable` flag clobbered on the pre-PHP-8.3 fallback path; the prior value is now restored on both exits. [#17151](https://github.com/phalcon/cphalcon/issues/17151) [[doc]](https://docs.phalcon.io/5.15/time-clock/)
- Fixed the `Phalcon\Acl\Adapter\Memory` documentation and metadata. [#17143](https://github.com/phalcon/cphalcon/issues/17143) [[doc]](https://docs.phalcon.io/5.15/acl/)
- Fixed the `Phalcon\Autoload\Loader` debug trail (`getDebug()`) being wiped by nested autoloads (a class requiring a not-yet-loaded parent); the trail is now reset only on the outermost call. [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)
- Fixed the `loader:pathFound` event in `Phalcon\Autoload\Loader` firing more than once per load (and, for the class-map strategy, before the file was confirmed); it now fires once, from the point that loads the file. [#17149](https://github.com/phalcon/cphalcon/issues/17149) [[doc]](https://docs.phalcon.io/5.15/autoload/)

### Removed

- Removed `Phalcon\Cache\Exception\InvalidCacheKey` and `Phalcon\Cache\Exception\CacheKeysNotIterable`. `Phalcon\Cache\AbstractCache::checkKey()` and `checkKeys()` now throw `Phalcon\Cache\Exception\InvalidArgumentException` with the same messages. [#17156](https://github.com/phalcon/cphalcon/issues/17156) [[doc]](https://docs.phalcon.io/5.15/cache/)


## [5.14.2](https://github.com/phalcon/cphalcon/releases/tag/v5.14.2) (2026-06-12)

### Tools

- Zephir Parser v2.0.4
- Zephir 0.23.0 (development - 27535f802)

### Changed

- Changed `Phalcon\Cli\Console::handle()` to process module definitions the same way as `Phalcon\Mvc\Application::handle()`. The module is now resolved through the inherited `getModule()`, so an unregistered module throws `Phalcon\Application\Exceptions\ModuleNotRegistered` (as `Console::getModule()` already did) instead of `Phalcon\Cli\Console\Exceptions\ConsoleModuleNotRegistered`. `Closure` module definitions are now supported and are invoked with the container, matching MVC. A definition that is neither an array nor a `Closure` throws the new `Phalcon\Cli\Console\Exceptions\InvalidModuleDefinition` instead of `InvalidModuleDefinitionPath`. [#17107](https://github.com/phalcon/cphalcon/issues/17107)
- Changed `Phalcon\Config\Adapter\Ini::parseIniString()` to use `Phalcon\Config\Config::DEFAULT_PATH_DELIMITER` for the key nesting separator instead of a hardcoded `.` (no behavior change). [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Changed `Phalcon\Config\Adapter\Json` and `Phalcon\Config\Adapter\Php` to throw `Phalcon\Config\Exceptions\CannotLoadConfigFile` when the configuration file cannot be read, instead of failing inside the JSON decoder (`Json`) or with a fatal `require` error (`Php`). All file based Config adapters now share the same failure contract. [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Changed `Phalcon\Config\ConfigFactory` to resolve adapter-specific constructor arguments (`mode` for `ini`, `callbacks` for `yaml`) through a single internal parameter map consulted by both `load()` and `newInstance()`, instead of two hardcoded switches. `load()` now also resolves the `yml` adapter name / file extension to the `yaml` adapter. [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Consolidated the `allowEmpty` handling of `Phalcon\Filter\Validation` into the validator (`Phalcon\Filter\Validation\AbstractValidator::isAllowEmpty()`). The per-field `allowEmpty` map is also honored. [#17124](https://github.com/phalcon/cphalcon/issues/17124)
- Moved the resolution of an array `attribute` option from `Phalcon\Filter\Validation\AbstractValidator::getOption()` into `Phalcon\Filter\Validation\Validator\Uniqueness::getOption()`. [#17124](https://github.com/phalcon/cphalcon/issues/17124)

### Added

- Added `Phalcon\Filter\Filter::getDefaultMapper()`, for mapper services used also by `Phalcon\Filter\FilterFactory::getServices()`. [#17124](https://github.com/phalcon/cphalcon/issues/17124)
- Added `Phalcon\Filter\Validation\Validator\File\Resolution\AspectRatio`, validating that an uploaded image has an exact aspect ratio. The `ratio` option uses the `16x9` format (per-field array form supported) and is compared with integer cross-multiplication, so the dimensions must match exactly: 1920x1080 matches `16x9`, 1366x768 does not. Also available through the composite `Phalcon\Filter\Validation\Validator\File` via the `aspectRatio` and `messageAspectRatio` options. [#17104](https://github.com/phalcon/cphalcon/issues/17104)
- Added `SessionUpdateTimestampHandlerInterface` support to the `Phalcon\Session` adapters (`Noop`, `Stream`, `Redis`, `Libmemcached`), enabling PHP's `session.lazy_write` (on by default): when the session data is unchanged at close, PHP now calls `updateTimestamp()` instead of `write()`. `Stream` touches the session file without rewriting its data; `Redis` and `Libmemcached` delegate to `write()` to refresh the TTL. With `session.use_strict_mode` enabled, the new `validateId()` rejects uninitialized session ids. [#17129](https://github.com/phalcon/cphalcon/issues/17129)
- Added a `stripPrefix` option (default `true`) to the `Phalcon\Storage` / `Phalcon\Cache` adapters, controlling whether a leading prefix is stripped from incoming keys (the behavior introduced for [#17089](https://github.com/phalcon/cphalcon/issues/17089)). `Phalcon\Session\Adapter\Redis` and `Phalcon\Session\Adapter\Libmemcached` disable it by default: session ids are externally generated, so an id that happens to start with the prefix text must not collide with another session. [#17127](https://github.com/phalcon/cphalcon/issues/17127)
- Added an optional `Phalcon\Config\ConfigFactory` constructor parameter to `Phalcon\Config\Adapter\Grouped`. The factory is created once and reused for every configuration fragment, so custom adapters registered on a supplied factory are now visible when loading grouped configurations. [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Added dialect-specific operators to PHQL: `@@`, `@>`, `<@`, `&&`, `||`, `->`, `->>`, `#>`, `#>>`. Each is parsed into a binary expression and emitted only by the dialects that support it (PostgreSQL: all nine; MySQL: `->`, `->>`; SQLite: `||`, `->`, `->>`); using an operator on a dialect that does not support it throws `Phalcon\Db\Exceptions\UnsupportedOperator`. The jsonb existence operators (`?`, `?|`, `?&`, `@?`) and the `~` regex family are intentionally unsupported - use their function equivalents (e.g. `jsonb_exists()`, `regexp_like()`). [#14954](https://github.com/phalcon/cphalcon/issues/14954) [#14579](https://github.com/phalcon/cphalcon/issues/14579)
- Added geometry value objects under `Phalcon\Db\Geometry` (`Point`, `LineString`, `Polygon`, `MultiPoint`, `MultiLineString`, `MultiPolygon`, `GeometryCollection`) and read-side hydration of spatial columns. When `orm.cast_on_hydrate` is enabled, spatial column values (MySQL WKB / PostGIS EWKB) are decoded into these objects on model read; otherwise the raw value is returned unchanged. [#17110](https://github.com/phalcon/cphalcon/issues/17110) [#14769](https://github.com/phalcon/cphalcon/issues/14769) [#13670](https://github.com/phalcon/cphalcon/issues/13670)
- Added opt-in session locking to `Phalcon\Session\Adapter\Redis`, preventing concurrent requests from racing on the same session (stale reads / lost writes). When enabled with the new `lockingEnabled` constructor option, `read()` acquires a per-session lock (`SET NX EX`, retried with pauses) and `close()` / `destroy()` release it with a token-guarded delete, so an adapter can only remove a lock it still owns. A read that cannot acquire the lock throws `Phalcon\Session\Adapter\Exceptions\AdapterRuntimeError`. Tunable via the `lockExpiry` (lock TTL in seconds, default `30`), `lockRetries` (maximum attempts, default `100`) and `lockWaitTime` (microseconds between attempts, default `50000`) options. Locking is off by default. [#17126](https://github.com/phalcon/cphalcon/issues/17126)
- Added table comment support to the MySQL and PostgreSQL dialects. Comment values are single-quote escaped (the existing PostgreSQL column-comment emission is now escaped as well). SQLite has no native table comment and ignores the option. [#15258](https://github.com/phalcon/cphalcon/issues/15258)
- Added the `Phalcon\Contracts\Filter\Sanitizer` interface and moving array recursion in `Phalcon\Filter\Filter::sanitize()`. [#17124](https://github.com/phalcon/cphalcon/issues/17124)

### Fixed

- Fixed `Phalcon\Config\Config::cloneEmpty()` so that `filter()`, `map()`, `sort()` and `where()` no longer fail on adapter instances (`Ini`, `Json`, `Php`, `Yaml`, `Grouped`). The override clones the current instance and replaces its data instead of invoking the adapter constructor with the parent `(array $data, ...)` signature. [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Fixed `Phalcon\Config\Config::merge()` emptying the configuration before validating its argument. Invalid merge data still throws `Phalcon\Config\Exceptions\InvalidMergeData`, but the current configuration now survives intact. [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Fixed `Phalcon\Config\Config::setData()` bypassing the `Phalcon\Support\Collection` runtime type guard: a `type` passed to the constructor is now enforced on leaf values at every nesting depth (arrays become nested Config objects, which validate their own leaves). Nested Config objects also inherit the `strictNull` and `type` flags in addition to `insensitive`. [#17134](https://github.com/phalcon/cphalcon/issues/17134)
- Fixed `Phalcon\Http\Cookie::send()` fataling when the cookie has a non-empty definition and no DI container is set. The session integration (service lookup, started check, and the `_PHCOOKIE_` key convention) is now consolidated in private `getStartedSession()`/`getSessionKey()` helpers shared by `delete()`, `restore()` and `send()`. [#17127](https://github.com/phalcon/cphalcon/issues/17127)
- Fixed `Phalcon\Mvc\Model::groupResult()` declaring a `Phalcon\Mvc\Model\ResultsetInterface` return type while returning a scalar (`int`, `float`, `string`, or `null`) for non-grouped aggregate queries (`count()`, `sum()`, `average()`, `maximum()`, `minimum()`). The return type declaration has been removed (`@return int|float|string|null|ResultsetInterface`), so model subclasses can override `groupResult()` without risking a `TypeError`. [#17114](https://github.com/phalcon/cphalcon/issues/17114)
- Fixed `Phalcon\Mvc\Model::save()` and `Phalcon\Mvc\Model::update()` to run the record-existence check on the write connection instead of the read connection. On master-replica setups, replication lag could make the check miss a row already written to the master, causing `save()` to attempt an `INSERT` instead of an `UPDATE`, or `update()` to fail with `Record cannot be updated because it does not exist`. `create()` has used the write connection since [#14256](https://github.com/phalcon/cphalcon/issues/14256). [#17105](https://github.com/phalcon/cphalcon/issues/17105)
- Fixed `Phalcon\Session\Bag` calling `getDI()` on its `Phalcon\Session\ManagerInterface` constructor parameter - a method the interface does not declare - which fataled for any manager implementing only the interface. The container is now captured only when the manager provides one. [#17127](https://github.com/phalcon/cphalcon/issues/17127)
- Fixed `Phalcon\Session\Manager::start()` deleting valid session cookies when `session.sid_bits_per_character` is `6`: the cookie sanity check now accepts the full PHP session ID alphabet (`[a-zA-Z0-9,-]`) instead of alphanumerics only. [#17127](https://github.com/phalcon/cphalcon/issues/17127)
- Fixed the Volt parser raising `Syntax error, unexpected token DEFAULT` when the `default` filter (e.g. `{{ value|default('text') }}`) is used inside a `{% switch %}` block. The word `default` is now treated as the `{% default %}` clause only when it directly follows the opening `{%` delimiter inside a switch; everywhere else it is parsed as a plain identifier, so the filter, `{{ default }}` and `{% set default = ... %}` all work inside switch-case blocks. [#16003](https://github.com/phalcon/cphalcon/issues/16003)
- Fixed the `Phalcon\Storage` / `Phalcon\Cache` adapters to accept keys already carrying the adapter prefix, so keys returned by `getKeys()` can be passed straight back to `get()`, `has()`, `delete()`, `deleteMultiple()`, `set()`, `setForever()`, `increment()` and `decrement()`. `Phalcon\Storage\Adapter\AbstractAdapter` now strips a leading prefix from incoming keys. [#17089](https://github.com/phalcon/cphalcon/issues/17089)
- Fixed the alternative installation script (`build/install`) to set the installed `phalcon.so` to mode `0644` after `make install`. The PHP build system installs shared extensions with the `install` default mode `0755`; shared objects only need read permission. [#17113](https://github.com/phalcon/cphalcon/issues/17113)

### Removed

- Removed `Phalcon\Cli\Console\Exceptions\ConsoleModuleNotRegistered` and `Phalcon\Cli\Console\Exceptions\InvalidModuleDefinitionPath`, superseded by `Phalcon\Application\Exceptions\ModuleNotRegistered` and `Phalcon\Cli\Console\Exceptions\InvalidModuleDefinition`. [#17107](https://github.com/phalcon/cphalcon/issues/17107)

## [5.14.1](https://github.com/phalcon/cphalcon/releases/tag/v5.14.1) (2026-06-08)

### Tools

- Zephir Parser v2.0.4
- Zephir 0.23.0 (development - bae82f7bd)

### Changed

- Consolidated the `Phalcon\Auth` dual-container handling (new `Phalcon\Container\Container` vs legacy `Phalcon\Di\Di`) behind a single internal `Phalcon\Auth\Internal\ContainerResolver`. [#17088](https://github.com/phalcon/cphalcon/issues/17088) [[doc]](https://docs.phalcon.io/5.14/auth/)
- Renamed the private `Phalcon\Events\Manager` dispatch hot-loop helper to `runQueue()`. [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.14/events/)
- Reworked the `Phalcon\Auth` access gates into Specification-style policies. `Phalcon\Contracts\Auth\Access\Access::isAllowed()` now receives the current identity and the request context: `isAllowed(Guard $guard, string $actionName, array $context = [])`, where context carries `handler` (controller / task / Micro component name), `module` (MVC module, when present), and `params` (dispatcher or route parameters). [#17088](https://github.com/phalcon/cphalcon/issues/17088) [[doc]](https://docs.phalcon.io/5.14/auth/)
- `Phalcon\Auth\Manager::access()` now resolves gates through `Phalcon\Auth\Access\AccessLocator` from the container instead of constructing them directly. [#17088](https://github.com/phalcon/cphalcon/issues/17088) [[doc]](https://docs.phalcon.io/5.14/auth/)

### Added

- Added `Phalcon\Auth\Access\Acl` - an ACL-backed access gate that incorporates the role-based authorization of the old Firewall component ([#14630](https://github.com/phalcon/cphalcon/issues/14630)) into the Auth layer. The gate checks the authenticated user's role against a `Phalcon\Acl\Adapter\AdapterInterface`: the ACL component is the `handler` context key (prefixed with `module` and a configurable separator when present), the ACL access is the action name, and `params` are passed through to callable ACL rules. Unauthenticated requests resolve to a configurable guest role (default `guest`); authenticated users supply their role via `Phalcon\Acl\RoleAwareInterface`. [#17088](https://github.com/phalcon/cphalcon/issues/17088) [[doc]](https://docs.phalcon.io/5.14/auth/)
- Added `Phalcon\Auth\Micro\AuthMicroListener` to enforce the active Auth access gate on `Phalcon\Mvc\Micro` route execution (attach to the `micro` event space).[#17088](https://github.com/phalcon/cphalcon/issues/17088) [[doc]](https://docs.phalcon.io/5.14/auth/)
- Added `Phalcon\Events\Manager::dispatch(object $event, string|array|null $name = null, ?object $source = null)` for object/class-based event dispatch built on Phalcon's own `Phalcon\Contracts\Events\Stoppable`. Listeners are routed by an explicit name (a string, or a `[class, method]` array) or by the event's class name and receive the event object. [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.14/events/)
- Added `beforeBind` and `afterBind` hook methods to `Phalcon\Forms\Form`. When defined on a form subclass, `beforeBind(array $data, ?object $entity)` runs at the start of `bind()` (returning `false` cancels the bind) and `afterBind(?object $entity)` runs after the data has been assigned. Both also fire when `bind()` is reached through `isValid()`. [#14598](https://github.com/phalcon/cphalcon/issues/14598) [[doc]](https://docs.phalcon.io/5.14/forms/)
- Added a `sync` option to many-to-many (`hasManyToMany`) relations and a chainable `Phalcon\Mvc\Model::setSync()` method to synchronize related records on save. When enabled, saving deletes the intermediate rows for records no longer present in the assigned array (add/update/delete), instead of only appending. [#17071](https://github.com/phalcon/cphalcon/issues/17071) [[doc]](https://docs.phalcon.io/5.14/db-models-relationships/)
- Added a `trace()` method to `Phalcon\Logger\Logger` together with a new `TRACE` log level (value `9`, label `trace`). [#17047](https://github.com/phalcon/cphalcon/issues/17047) [[doc]](https://docs.phalcon.io/5.14/logger/)
- Added a `{% verbatim %}`/`{% endverbatim %}` tag to Volt. Its body is emitted exactly as written, without being parsed by Volt, so `{{ ... }}`, `{% ... %}`, `{# ... #}` and constructs such as `<?xml ... ?>` or client-side templates (Handlebars, Mustache, Angular) pass through untouched. [#17085](https://github.com/phalcon/cphalcon/issues/17085) [[doc]](https://docs.phalcon.io/5.14/volt/)
- Added support for `JOIN` clauses in PHQL `UPDATE` statements (e.g. `UPDATE Invoices INNER JOIN Customers ON ... SET ... WHERE Customers.cst_id = :id:`). The join is used to filter the records to update; the statement still targets a single model. [#16984](https://github.com/phalcon/cphalcon/issues/16984) [[doc]](https://docs.phalcon.io/5.14/db-phql/)

### Fixed

- Fixed PHQL parser cache to use string-keyed lookups (`zend_hash_str_find`/`zend_hash_str_update`) instead of integer keys derived from `zend_inline_hash_func`, eliminating hash collisions that caused different PHQL queries to return identical cached ASTs [#14791](https://github.com/phalcon/cphalcon/issues/14791)
- Fixed `Phalcon\Annotations\Reader` failing to parse a docblock when an annotation argument is a string literal containing a parenthesis (e.g. `@SomeAnnotation(key='value(')`). The docblock pre-scan that locates each `@Annotation(...)` span counted every `(`/`)`, including those inside quoted values, so an unbalanced parenthesis in a string consumed the rest of the comment and produced a "Scanning error". [#16084](https://github.com/phalcon/cphalcon/issues/16084)
- Fixed `Phalcon\Di\Injectable::__get()` to no longer cache resolved services as dynamic object properties. Services accessed via magic properties (e.g. `$this->request`) are now re-resolved through the container on each access, so replacing or updating a service in the container is reflected in controllers, views, and other injectable classes. Properties already declared on the class continue to be populated. [#17052](https://github.com/phalcon/cphalcon/issues/17052)
- Fixed `Phalcon\Encryption\Crypt::decrypt()` to verify the HMAC tag with the constant-time `hash_equals()` instead of the identity operator, removing an observable timing discrepancy in the tag comparison (CWE-208, CWE-347) . The tag is now also verified before the decrypted text is unpadded, and truncated tags are rejected by the unequal-length path of `hash_equals()`. [#17090](https://github.com/phalcon/cphalcon/issues/17090) [[doc]](https://docs.phalcon.io/5.14/encryption-crypt/)
- Fixed `Phalcon\Mvc\Model\Query\Builder::orderBy()` when the array syntax is used with complex PHQL expressions. Previously any array item containing a space was split as a simple `column direction` pair, corrupting expressions such as `CASE WHEN inv_status_flag = 1 THEN 0 ELSE 1 END ASC`. The builder now only treats a trailing `ASC`/`DESC` as the direction (autoescaping a simple column) and preserves complex expressions verbatim. [#17077](https://github.com/phalcon/cphalcon/issues/17077)
- Fixed `Phalcon\Mvc\Model\Query` (PHQL) parsing of identifiers whose name begins with the `NOT` keyword. Columns, tables, and aliases such as `notice_id` were truncated to `ice_id` (the leading `not` was dropped), causing the database to report the column as unknown - most visibly in `Phalcon\Mvc\Model\Query\Builder` join conditions built via `createBuilder()`. The scanner's re2c backtracking marker shared the token-start pointer, so the `NOT BETWEEN` rule advanced it past `not`; escaped identifiers containing internal escapes (e.g. `[col\[0\]]`) were corrupted by the same root cause. [#16831](https://github.com/phalcon/cphalcon/issues/16831) [#17087](https://github.com/phalcon/cphalcon/issues/17087)
- Fixed the compilation failure (`'name_zv' undeclared`) in `Phalcon\Container\Container::callableGet()` and `callableNew()`. Both closures captured the typed `string name` parameter directly via `use (name)`. [#17078](https://github.com/phalcon/cphalcon/issues/17078)
- Fixed the build from emitting a warning for `RedisCluster` not being present at compile time. [#2589](https://github.com/zephir-lang/zephir/pull/2589) [#16977](https://github.com/phalcon/cphalcon/issues/16977)

### Removed

- Removed the unfinished `{% raw %}`/`{% endraw %}` Volt tag. It never produced output (compilation threw `UnknownVoltStatement`) and its body was parsed rather than emitted literally. Use `{% verbatim %}` instead. [#17085](https://github.com/phalcon/cphalcon/issues/17085)

## [5.14.0](https://github.com/phalcon/cphalcon/releases/tag/v5.14.0) (2026-06-04)

### Tools

- Zephir Parser v2.0.3
- Zephir 0.22.0 (development - 9d2def774)

### Changed

- Alignment with v6; docblocks; sorting; return types; minor fixes (image watermark opacity calc, serializer/helpers, readonly-becoming-mutable, ACL local access). [#17055](https://github.com/phalcon/cphalcon/issues/17055)
- Changed return types to `-> <static>` or `-> <self>` in various components. The change is a covariant narrowing on implementation methods and does not touch any interface contracts, so userland classes that implement Phalcon interfaces and return the interface type continue to work unchanged. [#17035](https://github.com/phalcon/cphalcon/issues/17035)
- Internal performance work across `Autoload`, `Dispatcher`, `Annotations`, `Db`, `Mvc\Model`, `Mvc\Model\Query`, `Tag`, `Assets`, `Acl\Adapter\Memory`, `Http\Request`, `Encryption\Crypt`. Behavior preserved. [#17049](https://github.com/phalcon/cphalcon/issues/17049)
- Moved CI tools/scripts in `resources/` removed unused ones [#17066](https://github.com/phalcon/cphalcon/pull/17066)
- Moved docker in `resources/` [#17066](https://github.com/phalcon/cphalcon/pull/17066)
- Refactored docker images (more flexible less cruft) [#17066](https://github.com/phalcon/cphalcon/pull/17066)
- Reorganization of quality tool config files (in `resources/`) [#17066](https://github.com/phalcon/cphalcon/pull/17066)
- `Phalcon\Autoload\Loader` getters (`getDirectories`, `getExtensions`, `getFiles`) return arrays keyed by the value string instead of by a SHA256 hash of it; iteration order and contents are unchanged. [#17049](https://github.com/phalcon/cphalcon/issues/17049) [[doc]](https://docs.phalcon.io/5.14/autoload/)
- `Phalcon\Mvc\Router::handle()` internal optimizations: O(1) hash lookup for literal-URI routes; per-HTTP-method buckets; hot-loop reads; PCRE patterns chunked; per-route metadata cache deduplicated by route id. [#17012](https://github.com/phalcon/cphalcon/issues/17012) [[doc]](https://docs.phalcon.io/5.14/routing/)
- `Phalcon\Mvc\Router\Route::getCompiledHostName()` now uses cache for hostname/converters. [#17012](https://github.com/phalcon/cphalcon/issues/17012) [[doc]](https://docs.phalcon.io/5.14/routing/)

### Added

- Added a new dependency-injection container under `Phalcon\Container`, with its contracts under `Phalcon\Contracts\Container`. It adds:
    - `Phalcon\Container\Container` / `Phalcon\Container\ContainerFactory` - the container and its factory, configured through `Phalcon\Contracts\Container\Service\Provider` providers (`Phalcon\Container\Provider\Web`, `Phalcon\Container\Provider\Cli`).
    - `Phalcon\Container\Definition\ServiceDefinition` - fluent service definitions with autowiring, factories, extenders, tags, aliases, and configurable service lifetimes (`Phalcon\Container\Definition\ServiceLifetime`).
    - `Phalcon\Container\Resolver\Resolver` - reflection-based constructor / method / parameter autowiring, plus the `Phalcon\Container\Resolver\Lazy\*` family for lazy resolution (`Get`, `GetCall`, `NewInstance`, `Call`, `Env`, `CsEnv`, `ArrayValues`, etc.).
    - `Phalcon\Container\Exceptions\*` - granular, per-cause exceptions (`ServiceNotFound`, `CircularAliasFound`, `FrozenDefinition`, `CannotResolveParameter`, `NoProcessorFound`, etc.). [#16897](https://github.com/phalcon/cphalcon/issues/16897) [[doc]](https://docs.phalcon.io/5.14/container/)
- Added a new authentication and authorization layer under `Phalcon\Auth`, with its contracts under `Phalcon\Contracts\Auth`. Built on top of `Phalcon\Container`, it adds:
    - `Phalcon\Auth\Manager` / `Phalcon\Auth\ManagerFactory` - the central manager that wires guards and access gates together, and its factory.
    - `Phalcon\Auth\AuthUser` - a lightweight user value object returned by array-backed adapters when no application model class is configured.
    - Guards under `Phalcon\Auth\Guard` - `Session` and `Token` (with `AbstractGuard` and `UserRemember`), resolved via `Phalcon\Auth\Guard\GuardLocator` and configured through `Phalcon\Auth\Guard\Config\*` (`AbstractGuardConfig`, `SessionGuardConfig`, `TokenGuardConfig`).
    - Adapters under `Phalcon\Auth\Adapter` - `Memory`, `Model`, and `Stream` user providers (with `AbstractAdapter` and `AbstractArrayAdapter`), resolved via `Phalcon\Auth\Adapter\AdapterLocator` and configured through `Phalcon\Auth\Adapter\Config\*` (`AbstractAdapterConfig`, `MemoryAdapterConfig`, `ModelAdapterConfig`, `StreamAdapterConfig`).
    - Access gates under `Phalcon\Auth\Access` - `Auth` and `Guest` (with `AbstractAccess`), resolved via `Phalcon\Auth\Access\AccessLocator`.
    - Dispatcher listeners `Phalcon\Auth\Mvc\AuthDispatcherListener` and `Phalcon\Auth\Cli\AuthDispatcherListener` (with `Phalcon\Auth\AbstractAuthDispatcherListener`) to guard MVC and CLI dispatch.
    - `Phalcon\Auth\Exception` plus granular `Phalcon\Auth\Exceptions\*` (`AccessDenied`, `ConfigRequiresNonEmptyValue`, `DataMustContainIdKey`, `DoesNotImplement`, `FileCannotRead`, `FileDoesNotContainJson`, `FileDoesNotExist`, `FileNotValidJson`).
    - Contracts under `Phalcon\Contracts\Auth` - `Manager`, `AuthUser`, `AuthRemember`, `RememberToken`, `Access\Access`, `Adapter\Adapter`, `Adapter\AdapterConfig`, `Adapter\RememberAdapter`, `Guard\Guard`, `Guard\GuardConfig`, `Guard\GuardStateful`, `Guard\BasicAuth`.
    - `Phalcon\Support\AbstractLocator` - the shared service-locator base extended by the guard, adapter, and access locators. [#16273](https://github.com/phalcon/cphalcon/issues/16273) [[doc]](https://docs.phalcon.io/5.14/auth/)
- Added granular exception classes across the framework. Every namespace that previously surfaced failures through a single umbrella `Phalcon\<Namespace>\Exception` (or its sub-namespace counterpart) now ships per-cause classes under a sibling `Exceptions/` folder. Each new class extends the existing per-namespace parent so `catch (Phalcon\<Namespace>\Exception $e)` continues to work unchanged. New classes:
    - `Phalcon\Acl\Exceptions`
        - `AccessRuleNotFound`
        - `CircularInheritanceError`
        - `ElementNotFound`
        - `ForbiddenWildcard`
        - `InvalidAccessList`
        - `InvalidComponentImplementation`
        - `InvalidRoleImplementation`
        - `InvalidRoleType`
        - `MissingFunctionParameters`
        - `ParameterTypeMismatch`
        - `RoleNotFoundException`
    - `Phalcon\Annotations\Exceptions`
        - `AnnotationNotFound`
        - `AnnotationsDirectoryNotWritable`
        - `CannotReadAnnotationData`
        - `UnknownAnnotationExpression`
    - `Phalcon\Application\Exceptions`
        - `ModuleNotRegistered`
    - `Phalcon\Assets\Exceptions`
        - `AssetSourceTargetCollision`
        - `CannotReadAsset`
        - `CollectionNotFound`
        - `InvalidAssetSourcePath`
        - `InvalidAssetTargetPath`
        - `InvalidFilter`
        - `InvalidTargetPath`
        - `TargetPathIsDirectory`
    - `Phalcon\Autoload\Exceptions`
        - `LoaderDirectoriesNotArray`
        - `LoaderMethodNotCallable`
    - `Phalcon\Cache\Exception`
        - `CacheKeysNotIterable`
        - `InvalidCacheKey`
    - `Phalcon\Cli\Console\Exceptions`
        - `ConsoleModuleNotRegistered`
        - `ContainerRequired`
        - `InvalidModuleDefinitionPath`
        - `ModuleDefinitionPathNotFound`
    - `Phalcon\Cli\Router\Exceptions`
        - `BeforeMatchNotCallable`
        - `InvalidRoutePaths`
        - `RouterArgumentsInvalidType`
    - `Phalcon\Config\Exceptions`
        - `CannotLoadConfigFile`
        - `ConfigNotArrayOrObject`
        - `GroupedAdapterRequiresArray`
        - `InvalidMergeData`
        - `MissingConfigOption`
        - `MissingFileExtension`
        - `MissingYamlExtension`
    - `Phalcon\DataMapper\Pdo\Exception`
        - `DriverNotSupported`
        - `UnknownDriverMethod`
        - `UnknownQueryMethod`
    - `Phalcon\Db\Exceptions`
        - `CannotInsertWithoutData`
        - `CannotPrepareStatement`
        - `CheckExpressionRequired`
        - `ColumnTypeRejectsAutoIncrement`
        - `ColumnTypeRejectsScale`
        - `ColumnTypeRequired`
        - `ConflictTargetColumnRequired`
        - `ConflictUpdateColumnRequired`
        - `ForeignKeyColumnsRequired`
        - `GeneratedAutoIncrementConflict`
        - `GeneratedDefaultConflict`
        - `IncompleteBindTypes`
        - `InvalidBindParameter`
        - `InvalidCheckExpression`
        - `InvalidGenerationExpression`
        - `InvalidGroupByExpression`
        - `InvalidIndexColumns`
        - `InvalidIndexDirections`
        - `InvalidIndexWhere`
        - `InvalidListExpression`
        - `InvalidOrderByExpression`
        - `InvalidSqlExpression`
        - `InvalidSqlExpressionType`
        - `InvalidUnaryExpression`
        - `InvalidWhereConditions`
        - `MatchedParameterNotFound`
        - `MaterializedViewsNotSupported`
        - `MissingDefinitionKey`
        - `MissingForeignKeyChecks`
        - `MissingSqliteDatabase`
        - `MysqlOnConflictNotSupported`
        - `NestedTransactionChangeBlocked`
        - `NoActiveTransaction`
        - `ReferencedColumnCountMismatch`
        - `ReferencedColumnsRequired`
        - `ReferencedTableRequired`
        - `ReturningNotSupported`
        - `ReturningRequiresColumn`
        - `SavepointsNotSupported`
        - `SqliteAlterCheckNotSupported`
        - `SqliteAlterColumnNotSupported`
        - `SqliteAlterForeignKeyNotSupported`
        - `SqliteAlterPrimaryKeyNotSupported`
        - `SqliteDropCheckNotSupported`
        - `SqliteDropForeignKeyNotSupported`
        - `SqliteDropPrimaryKeyNotSupported`
        - `TableMustHaveColumn`
        - `UnrecognizedDataType`
        - `UpdateFieldCountMismatch`
    - `Phalcon\Di\Exceptions`
        - `AliasAlreadyInUse`
        - `AliasNameMustBeString`
        - `ArgumentTypeRequired`
        - `CallArgumentsMustBeArray`
        - `CircularAliasReference`
        - `ContainerRequired`
        - `DefinitionMustBeArrayForRead`
        - `DefinitionMustBeArrayForUpdate`
        - `MethodCallMustBeArray`
        - `MethodNameRequired`
        - `MissingClassNameParameter`
        - `MissingParameterKey`
        - `PropertyInjectionRequiresInstance`
        - `PropertyMustBeArray`
        - `PropertyNameRequired`
        - `PropertyValueRequired`
        - `ServiceCannotBeResolved`
        - `SetterInjectionRequiresInstance`
        - `SetterParametersMustBeArray`
        - `UnknownServiceType`
    - `Phalcon\Dispatcher\Exceptions`
        - `ForwardInInitializeForbidden`
    - `Phalcon\Encryption\Crypt\Exception`
        - `DecryptionFailed`
        - `EmptyDecryptionKey`
        - `EmptyEncryptionKey`
        - `EncryptionFailed`
        - `InvalidPaddingSize`
        - `IvLengthCalculationFailed`
        - `MissingAuthData`
        - `MissingOpensslExtension`
        - `RandomBytesGenerationFailed`
        - `UnsupportedAlgorithm`
    - `Phalcon\Encryption\Security\Exceptions`
        - `InvalidRandomInput`
        - `UnknownHashAlgorithm`
    - `Phalcon\Encryption\Security\JWT\Exceptions`
        - `EmptyPassphrase`
        - `InvalidAudience`
        - `InvalidAudienceType`
        - `InvalidClaims`
        - `InvalidExpirationTime`
        - `InvalidHeader`
        - `InvalidNotBefore`
        - `MalformedJwtString`
        - `MissingJwtTypHeader`
        - `UnsupportedHmacAlgorithm`
        - `WeakPassphrase`
    - `Phalcon\Events\Exceptions`
        - `EventNotCancelable`
        - `InvalidEventHandler`
        - `InvalidEventSource`
        - `InvalidEventType`
        - `InvalidSubscriberConfiguration`
        - `NoListenersForEvent`
    - `Phalcon\Filter\Exceptions`
        - `FilterNotRegistered`
    - `Phalcon\Filter\Validation\Exceptions`
        - `FieldNotPrintable`
        - `FilterServiceUnavailable`
        - `InvalidAllowedTypes`
        - `InvalidCallbackReturn`
        - `InvalidDomainOption`
        - `InvalidFieldType`
        - `InvalidFilterService`
        - `InvalidStrictOption`
        - `InvalidValidationData`
        - `InvalidValidator`
        - `InvalidValidatorScope`
        - `MissingMbstring`
        - `NoDataToValidate`
        - `NoValidators`
        - `NoValidatorsInComposite`
        - `UniquenessConversionMustBeArray`
        - `UniquenessModelRequired`
        - `UniquenessOnlyForPhalconModel`
        - `ValidationEntityNotObject`
    - `Phalcon\Flash\Exceptions`
        - `EscaperServiceUnavailable`
        - `FlashMessageNotStringOrArray`
        - `SessionServiceUnavailable`
    - `Phalcon\Forms\Exceptions`
        - `ElementNotInForm`
        - `FormElementNameRequired`
        - `FormNotInLocator`
        - `FormNotRegistered`
        - `InvalidEntity`
        - `InvalidFilterType`
        - `InvalidJsonSchema`
        - `JsonSchemaNotArray`
        - `NoFormElements`
        - `SchemaEntryMissingKey`
        - `SchemaEntryNotArray`
        - `UnknownFormElementType`
        - `YamlExtensionRequired`
        - `YamlSchemaNotArray`
    - `Phalcon\Html\Exceptions`
        - `AttributeNotRenderable`
        - `FriendlyTitleConversionFailed`
        - `InvalidResultsetValue`
        - `ServiceNotRegistered`
        - `UsingRequiresTwoValues`
    - `Phalcon\Http\Cookie\Exceptions`
        - `CookieKeyTooShort`
        - `CryptInterfaceRequired`
        - `CryptServiceUnavailable`
        - `FilterServiceUnavailable`
    - `Phalcon\Http\Request\Exceptions`
        - `FilterServiceUnavailable`
        - `InvalidHost`
        - `InvalidHttpMethod`
        - `MissingFilters`
        - `SanitizerNotFound`
    - `Phalcon\Http\Response\Exceptions`
        - `NonStandardStatusCodeRequiresMessage`
        - `ResponseAlreadySent`
        - `ResponseServiceUnavailable`
        - `UrlServiceUnavailable`
    - `Phalcon\Image\Exceptions`
        - `CompositeFailed`
        - `ExtensionNotLoaded`
        - `ImageLoadFailed`
        - `MissingDimensions`
        - `MissingHeight`
        - `MissingWidth`
        - `ResizeFailed`
        - `ResourceTypeError`
        - `TextRenderingFailed`
        - `UnsupportedImageType`
        - `VersionMismatch`
    - `Phalcon\Logger\Adapter\Exceptions`
        - `FileOpenFailed`
        - `InvalidStreamMode`
        - `SyslogOpenFailed`
    - `Phalcon\Logger\Exceptions`
        - `AdapterNotFound`
        - `DeserializationFailed`
        - `NoAdaptersConfigured`
        - `SerializationFailed`
        - `TransactionAlreadyActive`
        - `TransactionNotActive`
    - `Phalcon\Messages\Exceptions`
        - `MessageNotObject`
        - `MessagesNotIterable`
    - `Phalcon\Mvc\Application\Exceptions`
        - `ContainerRequired`
        - `InvalidModuleDefinition`
        - `ModuleDefinitionPathNotFound`
    - `Phalcon\Mvc\Dispatcher\Exceptions`
        - `ResponseServiceUnavailable`
    - `Phalcon\Mvc\Micro\Exceptions`
        - `ContainerRequired`
        - `ErrorHandlerNotCallable`
        - `HandlerNotCallable`
        - `InvalidRegisteredHandler`
        - `LazyHandlerNotFound`
        - `MissingCollectionMainHandler`
        - `NoHandlersToMount`
        - `NoMatchedRouteHandler`
        - `NotFoundHandlerNotCallable`
        - `ResponseHandlerNotCallable`
    - `Phalcon\Mvc\Model\Behavior\Exceptions`
        - `MissingRequiredOption`
    - `Phalcon\Mvc\Model\Exceptions`
        - `BelongsToRequiresObject`
        - `BindTypeNotDefined`
        - `CannotResolveAttribute`
        - `ColumnNotInMap`
        - `ColumnNotInTableColumns`
        - `ColumnNotInTableMap`
        - `CorruptColumnType`
        - `CursorIsImmutable`
        - `DataTypeNotDefined`
        - `HandlerMustImplementBindable`
        - `IdentityNotInColumnMap`
        - `IdentityNotInTableColumns`
        - `IndexNotInCursor`
        - `IndexNotInRow`
        - `InvalidConnectionService`
        - `InvalidContainer`
        - `InvalidDumpResultKey`
        - `InvalidFindParameters`
        - `InvalidGetModelNameReturn`
        - `InvalidModelName`
        - `InvalidModelsManagerService`
        - `InvalidModelsMetadataService`
        - `InvalidResultsetCacheService`
        - `InvalidReturnedRecord`
        - `InvalidSerializationData`
        - `ManagerOrmServicesUnavailable`
        - `MethodNotFound`
        - `MissingMethodName`
        - `MissingModelClassName`
        - `ModelCouldNotLoad`
        - `ModelOrmServicesUnavailable`
        - `PrimaryKeyAttributeNotSet`
        - `PrimaryKeyRequired`
        - `PropertyNotAccessible`
        - `RecordCannotRefresh`
        - `RecordNotPersisted`
        - `ReferencedFieldsMismatch`
        - `RelationAliasMustBeString`
        - `RelationNotDefined`
        - `RelationRequiresObjectOrArray`
        - `ResultsetColumnNotInMap`
        - `RowIsImmutable`
        - `SnapshotsDisabled`
        - `StaticMethodRequiresOneArgument`
        - `UnknownRelationType`
        - `UpdateSnapshotDisabled`
    - `Phalcon\Mvc\Model\MetaData\Exceptions`
        - `CannotObtainTableColumns`
        - `ColumnMapNotArray`
        - `ContainerRequired`
        - `CorruptedMetaData`
        - `InvalidContainer`
        - `InvalidMetaDataForModel`
        - `MetaDataDirectoryNotWritable`
        - `MetaDataStrategyFailed`
        - `NoAnnotationsForClass`
        - `NoPropertyAnnotationsForClass`
        - `TableNotInDatabase`
    - `Phalcon\Mvc\Model\Query\Exceptions`
        - `AmbiguousColumn`
        - `AmbiguousJoinRelation`
        - `BindParameterNotInPlaceholders`
        - `BindTypeRequiresArray`
        - `BindValueRequired`
        - `ColumnNotInDomain`
        - `ColumnNotInSelectedModels`
        - `CorruptedAst`
        - `CorruptedDeleteAst`
        - `CorruptedInsertAst`
        - `CorruptedSelectAst`
        - `CorruptedUpdateAst`
        - `DeleteMultipleNotSupported`
        - `DuplicateAlias`
        - `EmptyArrayPlaceholderValue`
        - `InsertColumnCountMismatch`
        - `InvalidCachedResultset`
        - `InvalidCachingOptions`
        - `InvalidColumnDefinition`
        - `InvalidInjectedManager`
        - `InvalidInjectedMetadata`
        - `InvalidQueryCacheService`
        - `InvalidResultsetClass`
        - `JoinAliasAlreadyUsed`
        - `JoinFieldCountMismatch`
        - `MissingCacheKey`
        - `MissingMetaData`
        - `MissingModelAttribute`
        - `MissingModelsManager`
        - `MixedDatabaseSystems`
        - `ModelSourceNotFound`
        - `ModelsListNotLoaded`
        - `MultipleSqlStatementsNotSupported`
        - `NoModelForAlias`
        - `PhqlColumnNotInMap`
        - `ReadConnectionMissing`
        - `RelationshipNotFound`
        - `ResultsetClassNotFound`
        - `ResultsetNonCacheable`
        - `UnknownBindType`
        - `UnknownColumnType`
        - `UnknownJoinType`
        - `UnknownModelOrAlias`
        - `UnknownPhqlExpression`
        - `UnknownPhqlExpressionType`
        - `UnknownPhqlStatement`
        - `UpdateMultipleNotSupported`
        - `WriteConnectionMissing`
    - `Phalcon\Mvc\Model\Query\Exceptions\Builder`
        - `BuilderColumnNotInMap`
        - `BuilderConditionInvalid`
        - `ModelRequired`
        - `NoPrimaryKey`
        - `OperatorNotAvailable`
    - `Phalcon\Mvc\Router\Exceptions`
        - `AnnotationsServiceUnavailable`
        - `BeforeMatchNotCallable`
        - `ConfigKeyMustBeArray`
        - `EmptyGroupOfRoutes`
        - `GroupRoutesMustBeArray`
        - `InvalidCallbackParameter`
        - `InvalidConfigSource`
        - `InvalidNotFoundPaths`
        - `InvalidRoutePaths`
        - `InvalidRoutePosition`
        - `InvalidRouterFactoryConfig`
        - `MissingGroupRouteKey`
        - `MissingRouteConfigKey`
        - `RequestServiceUnavailable`
        - `UnknownHttpMethod`
        - `WrongPathsKey`
    - `Phalcon\Mvc\Url\Exceptions`
        - `MissingRouteName`
        - `RouteNotFound`
        - `RouterServiceUnavailable`
    - `Phalcon\Mvc\View\Engine\Volt\Exceptions`
        - `CannotOpenCompiledFile`
        - `CorruptedStatement`
        - `CorruptedStatementWithData`
        - `InvalidCompilationPrefix`
        - `InvalidExtension`
        - `InvalidHaystack`
        - `InvalidIntermediateRepresentation`
        - `InvalidOptionType`
        - `InvalidPathClosureReturn`
        - `InvalidPathType`
        - `InvalidStatement`
        - `InvalidUserFilterDefinition`
        - `InvalidUserFunctionDefinition`
        - `MacroAlreadyDefined`
        - `MacroNotFound`
        - `MbstringRequired`
        - `TemplateFileNotFound`
        - `TemplateFileNotOpenable`
        - `TemplatePathCollision`
        - `UnknownVoltExpression`
        - `UnknownVoltFilter`
        - `UnknownVoltFilterType`
        - `UnknownVoltStatement`
        - `VoltDirectoryNotWritable`
    - `Phalcon\Mvc\View\Exceptions`
        - `InvalidEngineRegistration`
        - `InvalidViewsDirType`
        - `SimpleViewNotFound`
        - `SimpleViewServicesUnavailable`
        - `ViewNotFound`
        - `ViewServicesUnavailable`
        - `ViewsDirItemMustBeString`
    - `Phalcon\Paginator\Exceptions`
        - `BuilderModelNotDefined`
        - `InvalidBuilderInstance`
        - `InvalidCursorColumn`
        - `InvalidLimit`
        - `MissingColumnsForHaving`
        - `MissingRequiredParameter`
        - `PaginatorDataNotArray`
    - `Phalcon\Session\Adapter\Exceptions`
        - `AdapterRuntimeError`
        - `InvalidSavePath`
        - `SavePathUnavailable`
    - `Phalcon\Session\Exceptions`
        - `InvalidSessionAdapter`
        - `InvalidSessionName`
        - `SessionAlreadyStarted`
        - `SessionModificationDenied`
    - `Phalcon\Storage\Exceptions`
        - `AuthenticationFailed`
        - `ClusterConnectionFailed`
        - `ConnectionFailed`
        - `DatabaseSelectionFailed`
        - `InvalidConfiguration`
        - `StorageError`
    - `Phalcon\Storage\Serializer\Exceptions`
        - `InvalidSerializationInput`
        - `InvalidUnserializationInput`
    - `Phalcon\Support\Collection\Exceptions`
        - `InvalidValueType`
        - `ReadOnlyViolation`
    - `Phalcon\Support\Debug\Exceptions`
        - `RequestHalted`
        - `RuntimeWarning`
    - `Phalcon\Support\Helper\Json\Exceptions`
        - `JsonDecodeError`
        - `JsonEncodeError`
    - `Phalcon\Support\Helper\Str\Exceptions`
        - `InsufficientArguments`
        - `InvalidReplaceFormat`
        - `SyntaxError`
    - `Phalcon\Time\Clock\Exceptions`
        - `InvalidModifier`
    - `Phalcon\Translate\Exceptions`
        - `FileOpenError`
        - `ImmutableObject`
        - `InterpolatorNotRegistered`
        - `InvalidDataType`
        - `KeyNotFound`
        - `MissingContent`
        - `MissingGettextExtension`
        - `MissingRequiredParameter`
        - `TranslatorNotRegistered` [#17019](https://github.com/phalcon/cphalcon/issues/17019)
- Added `Phalcon\Events\Manager::fire()` `beforeFire()` / `afterFire()` extension seams to `Manager::fire()`. [#17065](https://github.com/phalcon/cphalcon/issues/17065) [[doc]](https://docs.phalcon.io/5.14/events/)
- Added opt-in memory caps for long-running workers (Swoole / RoadRunner / queue consumers). Default `0` preserves the original unbounded behavior: [#17049](https://github.com/phalcon/cphalcon/issues/17049)
    - `Phalcon\Db\Profiler::setMaxProfiles(int)` / `getMaxProfiles()` [[doc]](https://docs.phalcon.io/5.14/db-layer/)
    - `Phalcon\Logger\Adapter\AbstractAdapter::setQueueLimit(int)` / `getQueueLimit()` [[doc]](https://docs.phalcon.io/5.14/logger/)
    - `Phalcon\Events\Manager::setMethodExistsCacheLimit(int)` / `getMethodExistsCacheLimit()` [[doc]](https://docs.phalcon.io/5.14/events/)
    - `Phalcon\Annotations\Adapter\AbstractAdapter::setAnnotationsLimit(int)` / `getAnnotationsLimit()` [[doc]](https://docs.phalcon.io/5.14/annotations/)
    - `Phalcon\Storage\Adapter\Memory::setMaxItems(int)` / `getMaxItems()` [[doc]](https://docs.phalcon.io/5.14/storage/)
- Added `Phalcon\Mvc\Router\Route::setRouteId(string $routeId)` - setter intended for restoring cached routes [#17012](https://github.com/phalcon/cphalcon/issues/17012) [[doc]](https://docs.phalcon.io/5.14/routing/)
- Added `Phalcon\Mvc\Router::buildDispatcherDump()` / `Phalcon\Mvc\Router::loadDispatcherFromArray(array $dump)` - used to build/load the routes [#17012](https://github.com/phalcon/cphalcon/issues/17012) [[doc]](https://docs.phalcon.io/5.14/routing/)
- Added `Phalcon\Mvc\Router::dumpDispatcher(string $path)` / `Phalcon\Mvc\Router::loadDispatcher(string $path)` - file-shaped helpers that write/read routes [#17012](https://github.com/phalcon/cphalcon/issues/17012) [[doc]](https://docs.phalcon.io/5.14/routing/)
- Added `Phalcon\Mvc\Router::useCache()` - to use a `Phalcon\Cache` adapter to store routes [#17012](https://github.com/phalcon/cphalcon/issues/17012) [[doc]](https://docs.phalcon.io/5.14/routing/)

### Fixed

- Fixed `$this->eventsManager` resolving to `null` inside `Phalcon\Mvc\Controller` methods [#17060](https://github.com/phalcon/cphalcon/issues/17060) [[doc]](https://docs.phalcon.io/5.14/controllers/)
- Fixed `Phalcon\Events\Event` and `Phalcon\Events\Manager::fire()` being declared `final` in 5.13.0 ([#17006](https://github.com/phalcon/cphalcon/issues/17006)), which prevented subclassing the events manager. [#17065](https://github.com/phalcon/cphalcon/issues/17065) [[doc]](https://docs.phalcon.io/5.14/events/)
- Fixed `Phalcon\Forms\Form::clear()` leaving a previously-bound `null` field value in the data array instead of unsetting it before reassigning the element default [#17042](https://github.com/phalcon/cphalcon/issues/17042) [[doc]](https://docs.phalcon.io/5.14/forms/)
- Fixed `Phalcon\Mvc\Model::getChangedFields()` / `hasChanged()` flagging every null-valued column of a freshly-loaded row as changed [#17042](https://github.com/phalcon/cphalcon/issues/17042) [[doc]](https://docs.phalcon.io/5.14/db-models/)
- Fixed `Phalcon\Mvc\Model::getUpdatedFields()` flagging unchanged null-valued columns as updated [#17042](https://github.com/phalcon/cphalcon/issues/17042) [[doc]](https://docs.phalcon.io/5.14/db-models/)
- Fixed `Phalcon\Mvc\Model\Row::offsetGet()` / `offsetExists()` throwing `The index does not exist in the row` when accessing a column whose value is `null` [#17041](https://github.com/phalcon/cphalcon/issues/17041) [[doc]](https://docs.phalcon.io/5.14/db-models/)
- Fixed `Phalcon\Mvc\Router::handle()` falling back to a default catch-all route instead of matching an HTTP-method-constrained route attached afterward. [#17062](https://github.com/phalcon/cphalcon/issues/17062) [[doc]](https://docs.phalcon.io/5.14/routing/)
- Fixed `Phalcon\Mvc\View::getContent()` throwing `TypeError` after `View::start()`. `start()` was assigning `$this->content = null` [#17041](https://github.com/phalcon/cphalcon/issues/17041) [[doc]](https://docs.phalcon.io/5.14/views/)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler` emitting invalid PHP when a double-quoted Volt string contained literal single quotes (e.g. `"send_ga('Link', ...)"`). Only un-escaped single quotes are now escaped, so the `'Let\'s Encrypt'` case from [#17002](https://github.com/phalcon/cphalcon/issues/17002) is preserved [#17046](https://github.com/phalcon/cphalcon/issues/17046) [[doc]](https://docs.phalcon.io/5.14/volt/)
- Fixed warning in `Phalcon\Auth\ManagerFactory` emitted in tests (random commit but had to be fixed) [#17066](https://github.com/phalcon/cphalcon/pull/17066)

### Removed

- Removed unused `Phalcon\Contracts\Container\Service\Lifetime` [#17066](https://github.com/phalcon/cphalcon/pull/17066)
- Reverted the `Phalcon\Mvc\Model\Query::executeUpdate()` named-placeholder substitution introduced for [#16976](https://github.com/phalcon/cphalcon/issues/16976). The substitution path was triggering a use-after-free in the model update flow under PostgreSQL ([#17042](https://github.com/phalcon/cphalcon/issues/17042)). Issue [#16976](https://github.com/phalcon/cphalcon/issues/16976) is reopened and will be addressed with a different approach. [[doc]](https://docs.phalcon.io/5.14/db-phql/)

## [5.13.0](https://github.com/phalcon/cphalcon/releases/tag/v5.13.0) (2026-05-18)

### Changed

- Changed `Phalcon\Contracts\Support\Collection` to declare the expanded method surface (`column`, `each`, `filter`, `first`, `getType`, `isEmpty`, `keys`, `last`, `map`, `reduce`, `replace`, `sort`, `values`, `where`) so the contract matches the implementation [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Changed `Phalcon\Events\Event` to be declared `final`. The class is a value object holding `type`, `source`, `data`, `cancelable`, and `stopped`; no subclasses exist in the cphalcon tree and any future typed-event work would add new sibling classes implementing `EventInterface` rather than extending `Event`. Marking it `final` lets the C extension fold the per-fire getters (`getType`, `getSource`, `getData`, `isCancelable`, `isStopped`, `isPropagationStopped`) into direct dispatch. BC note: any userland `class MyEvent extends Event` now fails [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::attach()` to classify the handler kind once at attach time so the dispatch loop can route via a single branch instead of running `instanceof Closure` / `is_callable` / `typeof` per fire per listener. Four kinds are recognized: `0` = Closure (direct invocation via Zephir's `{handler}(args)` syntax, no arg-array allocation), `1` = `[obj, method]` array callable (direct dynamic dispatch `handler[0]->{handler[1]}(args)`, no `call_user_func_array` overhead), `2` = plain object with method named after the event - the classic Phalcon listener pattern (class name is captured at attach time and stored on the tuple to skip `get_class()` per fire), `3` = generic callable (string function name, invokable object, `[class, staticMethod]`) routed through `call_user_func_array`. The subscriber array-form attach paths (`[methodName, priority]` and `[[methodA, priorityA], [methodB, priorityB]]`) now route through `insertHandlerEntry` directly with `kind=1`, bypassing the classification cascade since the resulting handler shape is already known. `methodExistsCache` access in the dispatch loop is tightened to a single `isset` fast path [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::detach()` to drop the `eventType` key entirely when its queue empties (removing the last listener), so `hasListeners()` and `fire()`'s short-circuit tell the truth. Previously an emptied queue left the key in place with an empty array value, causing `isset($this->events[$eventType])` to return `true` with no actual listeners to dispatch to. The matching `DetachTest` expectations are updated to reflect the new contract [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::detachAll(null)` to reset `events` to `[]` instead of `null`. The previous `null` reset broke `isset($this->events[$key])` semantics inside `attach()` and `fire()` until the next assignment refilled the property; the empty-array form keeps all access paths consistent [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::fire()` and `Phalcon\Events\Manager::fireAll()` to wrap dispatch in `try { ... } catch \Throwable, ex { cleanup; throw ex; }`. A throwing listener restores stashed responses (if nested) and decrements `fireDepth` back to its pre-call value before the exception propagates, so manager state stays clean for the next fire - important for long-lived managers (workers, daemons) where a single dirty teardown would poison every subsequent fire [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::fire()` to parse the `eventType` only once per unique string and cache the result (`[typePrefix, eventName]`) in an internal `eventNameCache` keyed by the original string. Repeated fires of the same event name (`db:beforeQuery × N` per request, model lifecycle events on hot save paths) collapse to a single hash lookup after warm-up. The cache never needs invalidation because the parse is deterministic for a given input string. `fire()` also short-circuits before allocating the `Event` instance when no listeners match either the type queue or the fully-qualified queue - in production most fires have zero matching listeners (model lifecycle events with no user-attached behavior, DB events without a tracer), so the avoided allocation is significant in hot paths [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::fire()`, `Phalcon\Events\Manager::attach()`, and `Phalcon\Events\Manager::fireQueue()` to be declared `final`. The class itself stays open so genuine subclasses that only add new methods continue to work, but the dispatch hot path is locked to enable C-level direct dispatch on the three methods that run per-event. The remaining public surface (`addSubscriber`, `removeSubscriber`, `detach`, `detachAll`, `getListeners`, `getResponses`, `getSubscribers`, `hasListeners`, `isCollecting`, `isValidHandler`, `collectResponses`, `enablePriorities`, `arePrioritiesEnabled`, `isStrict`, `setStrict`, `fireAll`, `clearSubscribers`) is left non-`final` so decorator-style subclasses that wrap these less-hot methods can still override them. BC note: subclasses that override `fire`, `attach`, or `fireQueue` now fail [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager::fireQueue()` to be a thin BC-preserving wrapper around a new private `Phalcon\Events\Manager::dispatch()` helper. The public signature `fireQueue(array $queue, EventInterface $event)` is unchanged; the framework's own `fire()` path bypasses `fireQueue` and calls `dispatch()` directly with hoisted arguments (`eventName`, `source`, `data`, `cancelable`, `collect`) so the second dispatch leg of a two-queue `fire()` (type queue + fully-qualified queue) does not re-extract identical values from the event. The dispatch path also applies a single-handler fast path: when the queue has exactly one listener (very common in unit tests and lightly-instrumented production), the foreach plus per-iteration cancelable/isStopped check is skipped and dispatch goes straight through the type-branch [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager` dispatch return-value contract to **last non-null wins**. Previously every listener return overwrote the running `status`, so a chain of (`"value"`, `null`) ended with `fire()` returning `null` and silently losing the earlier real value. The new contract only updates `status` when the listener return is non-null - the last meaningful return survives. The `stop()` determinism rule overrides last-non-null: when a listener calls `$event->stop()` (and `cancelable=true`), that listener's return value is what `fire()` returns - even if `null` - because the caller asked for the stopping listener's verdict explicitly. Returning `false` from a listener does **not** short-circuit the queue; callers wanting to stop downstream listeners must call `$event->stop()`. Consumers like `Phalcon\Mvc\Dispatcher` that interpret a `false` return from `fire()` as a cancel signal are unaffected because that check happens in their own dispatch logic, not in the events manager [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Events\Manager` listener storage from `SplPriorityQueue` to a sorted array of `[handler, type, priority]` tuples (with an additional `className` element on `type=2` tuples). The `SplPriorityQueue::EXTR_BOTH` clone-per-fire and O(n) `setExtractFlags()` rebuild on detach are eliminated; the "empty heap" warnings produced by `SplPriorityQueue` on never-fired event types disappear as a side effect. Insert order under the same priority is preserved (FIFO). When `enablePriorities` is off (the default), `insertHandlerEntry` short-circuits to a plain append - the sorted-insert loop only runs when priorities are explicitly enabled. When it does run, the insert uses `array_splice` instead of a per-element rebuild [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Changed `Phalcon\Html\Escaper` into a façade over five per-context escapers (`Phalcon\Html\Escaper\HtmlEscaper`, `AttributeEscaper`, `CssEscaper`, `JsEscaper`, `UrlEscaper`); each is reachable via `getXxxEscaper()`/`setXxxEscaper()` so individual contexts can be swapped without subclassing the façade. The legacy `setEncoding()`, `setFlags()`, and `setDoubleEncode()` setters fan out to all sub-escapers so existing code keeps working [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-escaper/)
- Changed `Phalcon\Html\Helper\AbstractSeries::__toString()` to `ksort()` its `store` before rendering so entries are emitted in position order rather than registration order. [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Changed `Phalcon\Html\Helper\Input\Checkbox` and `Phalcon\Html\Helper\Input\Radio` to extend a new shared `Phalcon\Html\Helper\Input\AbstractChecked`; `Radio` no longer extends `Checkbox`. Two paths now render `checked="checked"`: the unconditional opt-ins `["checked" => "checked"]` (case-insensitive) and `["checked" => true]`, and a value-match path comparing the supplied `checked` attribute against the input's `value` (`==` by default for mixed int/string round-tripping, `===` under `strict(true)`) [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Changed `Phalcon\Html\Helper\Style::add()` and `Phalcon\Html\Helper\Script::add()` now accept an optional `int $position = -1` argument that is routed through the new protected `pushOrPlace()` helper (negative pushes onto the next auto-increment slot, non-negative places at that key, advancing past occupied slots) [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Changed `Phalcon\Html\TagFactory` to no longer extend `Phalcon\Factory\AbstractFactory`; the registration pipeline now accepts class-strings, closures/callables, or `[className, [depKey, ...]]` / `[className, [depKey, ...], [extraArg, ...]]` tuples, and helpers are lazily cached per name in a separate `instances` map so `set()` overrides correctly invalidate the previous instance. `has()` now reports against the recipe map instead of the resolved-instance map [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Changed `Phalcon\Mvc\Model\Resultset\Complex::current()` LEFT-JOIN hydration to be controlled by the new `orm.resultset_empty_left_join_model` ini setting (default `true`). When the flag is `true` (default) a LEFT JOIN that matches no row hydrates an empty Model instance whose every column is `null` - preserving the pre-5.13 behavior so applications upgrading from 5.9.x do not need code changes. Setting the flag to `false` (via `php.ini`, `.htaccess`, or `Phalcon\Support\Settings::set('orm.resultset_empty_left_join_model', false)`) restores the 5.13.0 contract introduced by [#16239](https://github.com/phalcon/cphalcon/issues/16239), where the unmatched slot is plainly `null`. The new key is wired into `Phalcon\Support\Settings::get()` / `set()` alongside the other `orm.*` toggles [#16960](https://github.com/phalcon/cphalcon/issues/16960) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Changed `Phalcon\Mvc\Url\UrlInterface::get()` signature to match the implementation: the previously undeclared `var baseUri = null` fourth parameter (added to `Phalcon\Mvc\Url::get()` in 2015 but never propagated to the interface) and the new `bool replaceArgs = false` fifth parameter are now part of the contract [#16986](https://github.com/phalcon/cphalcon/issues/16986) [[doc]](https://docs.phalcon.io/5.13/mvc-url/)
- Changed `Phalcon\Support\Collection::__construct()` to accept two additional opt-in parameters - `bool $strictNull = false` and `?string $type = null`. When `strictNull` is `true`, `get()` returns stored `null` values verbatim instead of substituting the default (previous behavior was unconditional default-substitution); when `type` is set, every `set()`/`init()` runs through the new `validateType()` guard, which maps the scalar tokens `int`/`string`/`bool`/`float`/`array`/`object` to their `is_*` checks and treats anything else as a class/interface name compared with `instanceof`, throwing `InvalidArgumentException` on mismatch [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Changed `Phalcon\Support\Collection::__serialize()` to return a structured array `["data", "insensitive", "strictNull", "type"]` so a serialize/unserialize round-trip restores the full configuration (previously only `data` survived). `__unserialize()` accepts both the new structured format and the legacy flat-array format, so existing serialized blobs keep deserializing without intervention [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Changed `Phalcon\Support\Collection::getKeys()` and `Phalcon\Support\Collection::getValues()` to delegate to the new `keys()` / `values()` methods and marked the `get*`-prefixed pair `@deprecated`; behavior is unchanged but new code should call `keys()` / `values()` instead [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)

### Added

- Added CHECK-constraint support via new `Phalcon\Db\Check` value object and `Phalcon\Db\CheckInterface`. `Check` takes a constraint name (string; empty string means an unnamed constraint, in which case the dialect omits the `CONSTRAINT <name>` prefix) and a definition array containing the required `expression` key (the boolean SQL predicate). `Phalcon\Db\Dialect\Mysql`, `Phalcon\Db\Dialect\Postgresql`, and `Phalcon\Db\Dialect\Sqlite` all recognize `definition["checks"]` (array of `CheckInterface`) inside `createTable()` and emit an inline `[CONSTRAINT "<name>"] CHECK (<expr>)` line alongside the column/index/reference lines. New dialect methods `addCheck()` and `dropCheck()` emit the equivalent `ALTER TABLE ... ADD CONSTRAINT ... CHECK (...)` and `ALTER TABLE ... DROP CHECK|CONSTRAINT ...` SQL for MySQL 8.0.16+ and PostgreSQL; SQLite throws (CHECK constraints can only be declared at CREATE TABLE time in SQLite, the same limitation that already applies to FK constraints). New adapter methods `Phalcon\Db\Adapter\AbstractAdapter::addCheck()` and `Phalcon\Db\Adapter\AbstractAdapter::dropCheck()` provide the symmetric one-call ergonomics already available for `addForeignKey()` / `dropForeignKey()`. The new dialect and adapter methods are declared as commented-out `@todo v7` stubs on `Phalcon\Db\DialectInterface` and `Phalcon\Db\Adapter\AdapterInterface` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added MySQL 8.0+ `INVISIBLE` index support to `Phalcon\Db\Index`. The constructor's second parameter is now backward-compatibly overloaded: passing a plain list of column names continues to work (legacy positional form), while passing an associative array containing a `columns` key activates the new definition-array form (`["columns" => [...], "type" => "...", "invisible" => true]`). The third positional `type` argument is honored only when the second argument is the legacy list form; in definition-array mode `type` comes from the array. `Index` gains a matching `isInvisible(): bool` accessor and throws a `Phalcon\Db\Exception` if the definition-array path is taken but `columns` is not itself an array. `Phalcon\Db\Dialect\Mysql::addIndex` and `Phalcon\Db\Dialect\Mysql::createTable` emit a trailing ` INVISIBLE` keyword for invisible indexes. `Phalcon\Db\Adapter\Pdo\Mysql::describeIndexes` reverse-engineers the flag from the MySQL 8.0+ `Visible` column of `SHOW INDEXES` (absent on 5.7, which defaults to visible). PostgreSQL and SQLite have no equivalent and their dialects ignore the flag. The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Index` to avoid breaking third-party implementors during the v5 line. This definition-array hook is the path that will be reused by upcoming items #8 (descending indexes), #9 (partial indexes), and #10 (functional indexes) so the constructor stays tidy [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added MySQL 8.0.23+ `INVISIBLE` column support to `Phalcon\Db\Column`. A new boolean definition-array key `invisible` (default `false`) is parsed by the constructor; a matching `isInvisible(): bool` accessor reports the state at runtime. `Phalcon\Db\Dialect\Mysql::addColumn`, `Phalcon\Db\Dialect\Mysql::createTable`, and `Phalcon\Db\Dialect\Mysql::modifyColumn` emit ` INVISIBLE` after the NOT NULL/NULL clause when the flag is set. PostgreSQL and SQLite have no equivalent and their dialects ignore the flag. `Phalcon\Db\Adapter\Pdo\Mysql::describeColumns` reverse-engineers the flag from the `EXTRA` column of `information_schema.COLUMNS` (already in the result set since item #1's switch from `SHOW FULL COLUMNS`) - substring-matched so the flag is still detected when MySQL concatenates it with other extras like `INVISIBLE STORED GENERATED`. The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Column` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added PostgreSQL `CREATE INDEX CONCURRENTLY` support via a new `concurrently` definition-array key on `Phalcon\Db\Index` (default `false`). `Phalcon\Db\Index::isConcurrent(): bool` exposes the flag at runtime. `Phalcon\Db\Dialect\Postgresql::addIndex` now emits `CONCURRENTLY` between the `INDEX` keyword and the index name when the flag is set (`CREATE INDEX CONCURRENTLY "idx_email" ON "schema"."table" (...)`), so the index can be built without taking the strong lock that normally blocks writers. MySQL and SQLite have no equivalent concept and their dialects ignore the flag. No reverse engineering is meaningful (the option is creation-time only - once built, the index is indistinguishable from one built non-concurrently). The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Index` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added PostgreSQL materialized-view support to the Db dialect and adapter layers. Three new methods land on `Phalcon\Db\Dialect`: `createMaterializedView(string $viewName, array $definition, string $schemaName = null): string` (definition takes a required `sql` key, same shape as `createView`), `dropMaterializedView(string $viewName, string $schemaName = null, bool $ifExists = true): string`, and `refreshMaterializedView(string $viewName, string $schemaName = null, bool $concurrent = false): string` (passing `$concurrent = true` emits `REFRESH MATERIALIZED VIEW CONCURRENTLY ...` for non-blocking refresh - requires a unique index on the view). `Phalcon\Db\Dialect\Postgresql` overrides all three to emit the correct SQL; the base implementations throw `Phalcon\Db\Exception`, which is inherited unchanged by `Phalcon\Db\Dialect\Mysql` and `Phalcon\Db\Dialect\Sqlite` (neither engine has a materialized-view concept). `Phalcon\Db\Adapter\AbstractAdapter` gains three matching `createMaterializedView()` / `dropMaterializedView()` / `refreshMaterializedView()` wrappers that execute the dialect-built SQL and return bool.  [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added PostgreSQL-specific column types and array-column support to `Phalcon\Db\Column` and `Phalcon\Db\Dialect\Postgresql`. Ten new `Column::TYPE_*` constants are introduced: `TYPE_BYTEA` (30), `TYPE_INET` (31), `TYPE_CIDR` (32), `TYPE_MACADDR` (33), `TYPE_INT4RANGE` (34), `TYPE_INT8RANGE` (35), `TYPE_NUMRANGE` (36), `TYPE_TSRANGE` (37), `TYPE_TSTZRANGE` (38), `TYPE_DATERANGE` (39). `Phalcon\Db\Dialect\Postgresql::getColumnDefinition` recognizes the new types and emits the matching keywords (`BYTEA`, `INET`, `CIDR`, `MACADDR`, `INT4RANGE`, `INT8RANGE`, `NUMRANGE`, `TSRANGE`, `TSTZRANGE`, `DATERANGE`). MySQL and SQLite dialects fall through their existing `default` branches for these constants - users targeting those engines should pick a portable base type instead. Additionally, a new boolean definition-array key `array` and a `Phalcon\Db\Column::isArray(): bool` accessor expose array-column intent; when `isArray()` is `true`, the PostgreSQL dialect appends `[]` to the type (`INTEGER[]`, `TEXT[]`, `INET[]`, etc.). MySQL and SQLite ignore the flag. `Phalcon\Db\Adapter\Pdo\Postgresql::describeColumns` reverse-engineers the new types by matching the `data_type` column from `information_schema.columns` and sets `array` when `data_type` reports `ARRAY` or contains `[]`. The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Column` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added `FOR SHARE` shared-lock emission to `Phalcon\Db\Dialect\Postgresql::sharedLock()`; it previously returned the original query unchanged (silent no-op), so callers had no way to express PostgreSQL's row-level shared lock through the cphalcon dialect API. The method now appends `" FOR SHARE"` and also accepts the optional `string $modifier = ""` second argument introduced by item #3, so callers can request `FOR SHARE NOWAIT` / `FOR SHARE SKIP LOCKED` via the `Phalcon\Contracts\Db\Dialect::LOCK_NOWAIT` / `LOCK_SKIP_LOCKED` constants. The signature change is propagated to `Phalcon\Contracts\Db\Dialect::sharedLock`, `Phalcon\Contracts\Db\Adapter\Adapter::sharedLock`, and the SQLite and MySQL impls - SQLite remains a no-op regardless of the modifier (no row-level locking), and MySQL still emits its legacy `LOCK IN SHARE MODE` and silently ignores any modifier (the legacy syntax does not support `NOWAIT` / `SKIP LOCKED`; users on MySQL 8.0+ who need those modifiers can use `forUpdate()` instead). `Phalcon\Db\Adapter\AbstractAdapter::sharedLock` passes the modifier through to the dialect [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added `NOWAIT` / `SKIP LOCKED` row-lock modifiers to `forUpdate()`. The dialect and adapter `forUpdate()` methods now accept an optional second `string $modifier = ""` argument; pass one of the new contract constants `Phalcon\Contracts\Db\Dialect::LOCK_NONE` (default), `Phalcon\Contracts\Db\Dialect::LOCK_NOWAIT`, or `Phalcon\Contracts\Db\Dialect::LOCK_SKIP_LOCKED` to emit `SELECT … FOR UPDATE`, `SELECT … FOR UPDATE NOWAIT`, or `SELECT … FOR UPDATE SKIP LOCKED` respectively. Recognized by MySQL 8.0+ and PostgreSQL 9.5+; SQLite has no row-level locking and silently ignores the modifier. Signature change is propagated to `Phalcon\Contracts\Db\Dialect::forUpdate`, `Phalcon\Contracts\Db\Adapter\Adapter::forUpdate`, `Phalcon\Db\Dialect::forUpdate` (base), `Phalcon\Db\Dialect\Sqlite::forUpdate` (override remains a no-op), and `Phalcon\Db\Adapter\AbstractAdapter::forUpdate` (pass-through). Existing single-argument call sites are unaffected - the second parameter defaults to `""` [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added `ON CONFLICT (...) DO UPDATE SET ...` upsert support to the Db dialect and adapter layers. New SQL-transformer method `Phalcon\Db\Dialect::onConflictUpdate(string $sqlQuery, array $conflictColumns, array $updateColumns): string` appends an upsert clause to the supplied INSERT statement using the SQL-standard form recognized by PostgreSQL 9.5+ and SQLite 3.24+: `INSERT INTO ... ON CONFLICT ("col") DO UPDATE SET "other" = excluded."other"`. The base implementation in `Phalcon\Db\Dialect::onConflictUpdate` provides the standard emission (inherited by `Phalcon\Db\Dialect\Postgresql` and `Phalcon\Db\Dialect\Sqlite`); `Phalcon\Db\Dialect\Mysql::onConflictUpdate` overrides to throw because MySQL's `INSERT ... ON DUPLICATE KEY UPDATE` shape is incompatible (deferred to parser item #23). Throws `Phalcon\Db\Exception` when either the `conflictColumns` or `updateColumns` array is empty. `Phalcon\Db\Adapter\AbstractAdapter::onConflictUpdate` provides the symmetric one-call passthrough. The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Dialect` and `Phalcon\Contracts\Db\Adapter\Adapter` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added `Phalcon\Contracts\Db` namespace housing the canonical contracts for the Db layer: `Phalcon\Contracts\Db\Check`, `Phalcon\Contracts\Db\Column`, `Phalcon\Contracts\Db\Dialect`, `Phalcon\Contracts\Db\Index`, `Phalcon\Contracts\Db\Reference`, `Phalcon\Contracts\Db\Result`, and `Phalcon\Contracts\Db\Adapter\Adapter`. The legacy interfaces (`Phalcon\Db\CheckInterface`, `Phalcon\Db\ColumnInterface`, `Phalcon\Db\DialectInterface`, `Phalcon\Db\IndexInterface`, `Phalcon\Db\ReferenceInterface`, `Phalcon\Db\ResultInterface`, `Phalcon\Db\Adapter\AdapterInterface`) are kept as thin extensions of their contract counterparts, marked `@deprecated` (matching the `Phalcon\Support\Collection\CollectionInterface` migration pattern), so existing implementors and typehints continue to work in the v5 line. The `@todo v7` commented-out stubs for the generated-column API (item #1) and CHECK-constraint API (item #2) live in the canonical contract files, which is where they will be uncommented when v7 ships [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added `Phalcon\Contracts\Events\Stoppable` - a Phalcon-owned mirror of PSR-14's `StoppableEventInterface` with the single `isPropagationStopped(): bool` method. `Phalcon\Events\Event` implements it and routes the call through the same internal `stopped` flag as `isStopped()`, so existing `$event->stop()` callers automatically expose the PSR-14-shaped accessor without changing their code. Keeps PSR types out of the extension while letting a future `phalcon/events-psr14-bridge` package map Phalcon ↔ PSR-14 in PHP land [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Contracts\Events\Subscriber` - a subscriber contract requiring a single static `getSubscribedEvents(): array` method. Supported shapes per entry: `['event:name' => 'methodName']` (plain string), `['event:name' => ['methodName', priority]]` (method with priority), or `['event:name' => [['methodA', priorityA], ['methodB', priorityB]]]` (multiple listeners per event). Replaces the magic-method-only routing as the primary discoverability mechanism while keeping that path intact for BC [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Contracts\Forms\Schema` interface defining a single `load(): array` method for objects that supply a normalized list of form-element definitions [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Added `Phalcon\Contracts\Mvc\Model\Relation\CacheKeyProvider` with a single `getUniqueKey(): string` method; when a model implements this interface and a relation is marked `reusable => true`, the Model Manager uses the return value of `getUniqueKey()` as the cache key instead of the object-identity-based `unique_key()` builtin, allowing different PHP object instances that represent the same database row to share the same reusable record cache entry [#16993](https://github.com/phalcon/cphalcon/issues/16993) [[doc]](https://docs.phalcon.io/5.13/db-models-relationships/)
- Added `Phalcon\Di\Di::hasShared(string $name): bool` and `Phalcon\Di\Di::removeShared(string $name): void` (also declared on `Phalcon\Di\DiInterface`) to operate on the shared-instance cache independently of the service-definition registry. `hasShared()` reports whether `getShared()` has already materialized an instance for the given name (in contrast to `has()`, which reports on the definition registry). `removeShared()` drops the cached instance - both from `Di::$sharedInstances` and from the `Service` object's internal `sharedInstance` field - without removing the service definition, so the next `getShared()` call rebuilds a fresh instance. Use case: fork-based multi-process workers that need to discard the parent's inherited resource handle (DB connection, etc.) without re-registering the service. Both methods are alias-aware [#13440](https://github.com/phalcon/cphalcon/issues/13440) [[doc]](https://docs.phalcon.io/5.13/di/)
- Added `Phalcon\Encryption\Security::setAutoRefresh(bool)` and `Phalcon\Encryption\Security::refreshToken()` to make CSRF-token rotation opt-out. When `setAutoRefresh(false)` is called, `getToken()` and `getTokenKey()` reuse the existing session values instead of generating a new pair on every call, eliminating the per-request session write that backend session stores billed per-write (DynamoDB, Redis-with-billing, etc.) would otherwise incur on read-only requests. `refreshToken()` provides an explicit, atomic rotation of both the token and the token key (used after login or any other state change where rotation is appropriate). The default `autoRefresh = true` preserves the existing one-time-use behavior; opt-in only [#14413](https://github.com/phalcon/cphalcon/issues/14413) [[doc]](https://docs.phalcon.io/5.13/encryption-security/)
- Added `Phalcon\Events\Manager::addSubscriber()`, `Phalcon\Events\Manager::removeSubscriber()`, `Phalcon\Events\Manager::getSubscribers()`, and `Phalcon\Events\Manager::clearSubscribers()` to register and unregister `Subscriber` instances. The subscriber's `getSubscribedEvents()` map is parsed once at attach time and each entry is routed through the regular listener pipeline; the result is cached per class name in a new internal `subscriberEventsCache` so repeated add/remove of the same subscriber class doesn't re-invoke the static method. `removeSubscriber()` is idempotent; `clearSubscribers()` iterates a snapshot of registered subscribers so the underlying property can be mutated safely during the walk. Subscribers are keyed by `spl_object_id()` so the same instance cannot be double-registered [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Events\Manager::fireAll(string $eventType, object $source, mixed $data = null, bool $cancelable = true): array` returning every listener's return value as an indexed array. Independent of `collectResponses()`; the caller's collected state on `$this->responses` is stashed on entry and restored on exit so a `fireAll()` call from inside a `collect`-mode `fire()` does not pollute the outer accumulator [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Events\Manager::halt()`, `Phalcon\Events\Manager::resume()`, and `Phalcon\Events\Manager::isHalted(): bool` - a manager-level kill switch separate from `$event->stop()`. `stop()` only stops the current dispatch chain; `halt()` survives across `fire()` calls and makes every subsequent `fire()` / `fireAll()` / `fireQueue()` call return immediately (`null` or `[]`) without dispatching, until `resume()` clears the flag. Use case: a security check or initialization-failure path that needs to abort all downstream event activity for the rest of the request [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Events\Manager::setStopOnFalse(bool)` / `Phalcon\Events\Manager::isStopOnFalse(): bool` - an opt-in per-event short-circuit. When `setStopOnFalse(true)` has been called and the fire's `cancelable` flag is on, a listener returning literal `false` stops the dispatch loop for that event and pins the `fire()` return as `false`; later listeners cannot overwrite the cancel. Default off, preserving the pre-5.13 last-wins return-value semantics so existing codebases are unaffected. Independent of `halt()` and `$event->stop()` - only governs how the dispatch loop reacts to a literal `false` listener return [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Events\Manager::setStrict(bool)` / `Phalcon\Events\Manager::isStrict(): bool` to enable strict mode. When strict mode is on, `fire()` and `fireAll()` throw `Phalcon\Events\Exception` on dispatch of an event with zero matching listeners - useful in development for catching typos in event names. Default off; opt-in only [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Added `Phalcon\Forms\Element\CheckGroup` and `Phalcon\Forms\Element\RadioGroup` form elements that render multiple `<input type="checkbox">` / `<input type="radio">` inputs from a single registered form-element entry. `CheckGroup` auto-suffixes the name with `[]` when not already present so PHP collects checked values into an array on submission; both elements bind cleanly because they live under a single key [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Added `Phalcon\Forms\Form::load(Schema $schema, FormsLocator $locator)` that consumes element definitions from any `Schema` source and resolves their `type` strings through the supplied locator, allowing custom element types via `FormsLocator::setElement()` [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Added `Phalcon\Forms\FormsLocator`, a closure-based registry for named forms (`get`/`has`/`set`) and element-type factories (`getElement`/`hasElement`/`setElement`); entity-less form lookups are lazily cached, while entity-aware lookups always rebuild. The default element registry seeds factories for `check`, `checkgroup`, `date`, `email`, `file`, `hidden`, `numeric`, `password`, `radio`, `radiogroup`, `select`, `submit`, `text`, and `textarea` [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Added `Phalcon\Forms\Loader\ArrayLoader`, `Phalcon\Forms\Loader\JsonLoader`, and `Phalcon\Forms\Loader\YamlLoader` - three `Schema` implementations that feed `Form::load()` from a PHP array, a JSON string/file, or a YAML string/file (pecl/yaml) respectively [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Added `Phalcon\Forms\Manager::loadForm(string $name, Schema $schema, ?object $entity = null)` and `Phalcon\Forms\Manager::getLocator()`; `loadForm()` builds a form from a `Schema`, registers it in the manager, and also registers a factory in the locator so subsequent entity-aware retrievals via `FormsLocator::get($name, $entity)` rebuild fresh instances. `Manager::__construct(FormsLocator $locator = null)` accepts a nullable locator and instantiates a default `FormsLocator` when omitted (BC: pre-existing `new Manager()` calls continue to work) [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Added `Phalcon\Html\Escaper\AbstractEscaper`, `Phalcon\Html\Escaper\AttributeEscaper`, `Phalcon\Html\Escaper\CssEscaper`, `Phalcon\Html\Escaper\HtmlEscaper`, `Phalcon\Html\Escaper\JsEscaper`, and `Phalcon\Html\Escaper\UrlEscaper` as the per-context building blocks behind `Phalcon\Html\Escaper` [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-escaper/)
- Added `Phalcon\Html\Helper\Input\AbstractGroup`, `Phalcon\Html\Helper\Input\CheckboxGroup`, and `Phalcon\Html\Helper\Input\RadioGroup`; the base resolves option entries (scalar label or `[label, ...attrs]` map) into `<input>` + `<label>` pairs sharing a single HTML `name`, with auto-generated `id` per value (`{name}_{value}`) and per-item attribute pass-through. `CheckboxGroup` matches against an array (or scalar coerced into one) for `checked`; `RadioGroup` matches against a single scalar. Registered in `Phalcon\Html\TagFactory` as `inputCheckboxGroup` and `inputRadioGroup` [#16996](https://github.com/phalcon/cphalcon/issues/16996) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added `Phalcon\Html\Helper\Input\Generic` and `Phalcon\Html\Helper\Input\AbstractChecked`; `Generic` accepts the HTML5 `type` via the constructor (with `setType()` to change it after construction), letting `TagFactory` register a single class for all type-string-only inputs and differentiate them through the recipe map [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added `Phalcon\Html\Helper\Input\Select::placeholder(string $text)` to inject a `<option value="" disabled selected>$text</option>` first entry, and `Phalcon\Html\Helper\Input\Select::strict(bool $flag = true)` to opt the option/`selected` comparison from the new loose default into strict (`===`) matching [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added `Phalcon\Html\Helper\Script::beginInternal()` and `endInternal(array $attributes = [], int $pos = -1)` to capture inline JavaScript via output buffering and append it to the asset stack as a `<script>...</script>` block [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added `Phalcon\Html\Helper\Tag` (open tag) and `Phalcon\Html\Helper\VoidTag` (self-closing tag) as escape hatches for arbitrary tag names without a dedicated helper; available via `TagFactory` as `tag` and `voidTag` [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added `Phalcon\Mvc\Router::getMethodRoutes(): array` - returns the internal HTTP-method index (routes bucketed by method string, unconstrained routes under `"*"`). `handle()` now builds a candidate list from only the matching-method bucket plus the unconstrained bucket and iterates that subset in reverse, eliminating the O(n) per-route HTTP-method check that previously ran against every registered route on each request [#17015](https://github.com/phalcon/cphalcon/issues/17015) [[doc]](https://docs.phalcon.io/5.13/routing/)
- Added `Phalcon\Mvc\Router::loadFromConfig(array|ConfigInterface $config): RouterInterface` - initializes the router from a data structure, accepting the top-level keys `defaultRoutes`, `removeExtraSlashes`, `defaults`, `notFound`, `routes`, and `groups`. Each `routes` entry supports `method` (one of `connect`, `delete`, `get`, `head`, `options`, `patch`, `post`, `purge`, `put`, `trace`; omitted = any method), `pattern`, `paths`, `name`, and `hostname`. Each `groups` entry supports `prefix`, `hostname`, `paths`, and a nested `routes` array, then is mounted via `mount()` [#15050](https://github.com/phalcon/cphalcon/issues/15050) [[doc]](https://docs.phalcon.io/5.13/routing/)
- Added `Phalcon\Mvc\Router\RouterFactory` with `load(array|ConfigInterface $config): RouterInterface` and `newInstance(bool $defaultRoutes = true): RouterInterface`, mirroring the idiomatic `ConfigFactory`/`LoggerFactory` pattern; `load()` honors the optional top-level `defaultRoutes` key (defaulting to `true`) and delegates route assembly to `Router::loadFromConfig()` [#15050](https://github.com/phalcon/cphalcon/issues/15050) [[doc]](https://docs.phalcon.io/5.13/routing/)
- Added `Phalcon\Paginator\Adapter\QueryBuilderCursor` - a keyset (cursor-based) pagination adapter that accepts a `QueryBuilder`, a `limit`, and a `cursorColumn` (the column used as the cursor key, typically a primary key). Each `paginate()` call fetches `limit + 1` rows using `cursorColumn > :cursor:` to skip already-seen rows; the extra row is used only to detect whether a next page exists and is never returned. `getNext()` returns the last visible row's cursor value, or `0` when no further page exists. `setCursor(int|null $cursor)` advances or resets the position. `getTotalItems()` and `getLast()` return `0` by design - no COUNT query is issued. Registered in `PaginatorFactory` as `"queryBuilderCursor"` [#14754](https://github.com/phalcon/cphalcon/issues/14754) [[doc]](https://docs.phalcon.io/5.13/db-pagination/)
- Added `Phalcon\Support\Collection:column(string $propertyOrMethod): array` (lift a single property/method off every item, keyed by the original collection key) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:each(callable $callback)` (run the callback for side effects and return `$this` for chaining) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:filter(callable $callback)` (new collection of items where the callback returns truthy) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:first()` / `last()` (head/tail value or `null` on empty) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:isEmpty(): bool`, `getType(): string|null` (the type guard configured at construction) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:keys(bool $insensitive = true)` and `values()` (the non-`get`-prefixed names, with `getKeys`/`getValues` retained as deprecated wrappers) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:map(callable $callback)` (new collection of transformed values, keys preserved) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:reduce(callable $callback, mixed $initial = null): mixed` (callback signature `($accumulator, $value, $key)`) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:replace(array $data): void` (clear then `init` in one call) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:sort(?callable $callback = null, int $order = SORT_ASC)` (`uasort` when a callback is supplied, otherwise `asort`/`arsort` keyed by `$order`) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Support\Collection:where(string $propertyOrMethod, mixed $value)` (strict-equality filter via `extractValue`) [#17000](https://github.com/phalcon/cphalcon/issues/17000) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Added `Phalcon\Time\Clock\Exception` with the `invalidModifier()` named constructor; `FrozenClock::adjust()` throws this exception uniformly across PHP versions when the modifier string cannot be parsed (catching `DateMalformedStringException` on PHP 8.3+ and trapping the `E_WARNING` plus `false` return on earlier versions, leaving the clock state untouched on failure) [#16965](https://github.com/phalcon/cphalcon/issues/16965) [[doc]](https://docs.phalcon.io/5.13/time-clock/)
- Added `Phalcon\Time\Clock` namespace with `ClockInterface`, `SystemClock`, and `FrozenClock` to wrap clock functionality for the application; `SystemClock` returns the current time as a `DateTimeImmutable` in a configurable timezone (with `fromUTC()` and `fromSystemTimezone()` named constructors), while `FrozenClock` returns a fixed instant for deterministic testing and exposes `set()` and `adjust()` to move the clock in place (returning `$this` for fluent chaining) [#16965](https://github.com/phalcon/cphalcon/issues/16965) [[doc]](https://docs.phalcon.io/5.13/time-clock/)
- Added `RETURNING` clause support to the Db dialect and adapter layers. New SQL-transformer method `Phalcon\Db\Dialect::returning(string $sqlQuery, array $columns): string` appends a `RETURNING` clause to an `INSERT` / `UPDATE` / `DELETE` statement; pass `["*"]` for `RETURNING *` or a list of column identifiers for `RETURNING "col1", "col2"`. `Phalcon\Db\Dialect\Postgresql::returning` and `Phalcon\Db\Dialect\Sqlite::returning` provide the emission (SQLite requires 3.35+). The base implementation in `Phalcon\Db\Dialect::returning` throws `Phalcon\Db\Exception`, which is inherited unchanged by `Phalcon\Db\Dialect\Mysql` since MySQL has no RETURNING construct. An empty `columns` array throws on PgSQL and SQLite. `Phalcon\Db\Adapter\AbstractAdapter::returning` provides the symmetric one-call passthrough so users can do `$connection->query($connection->returning($sql, ["id"]))`. The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Dialect` and `Phalcon\Contracts\Db\Adapter\Adapter` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added `Raw` factory variants `aRaw`, `buttonRaw`, `elementRaw`, `labelRaw`, `olRaw`, and `ulRaw` to `Phalcon\Html\TagFactory`, each backed by a tuple recipe that pins `raw = true` on the constructor of the underlying helper [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added an opt-in `bool $replaceArgs = false` fifth parameter to `Phalcon\Mvc\Url::get()`; when `true` and the supplied `$uri` already contains a query string, the existing query is parsed via `parse_str()` and merged under `array_merge($existing, (array) $args)` so user-supplied keys override colliding ones (e.g. `$url->get('http://example.com?page=1', ['page' => 5], null, null, true)` now returns `http://example.com?page=5` instead of `http://example.com?page=1&page=5`). The default (flag omitted) preserves the legacy append-with-`&` behavior to keep existing callers working [#16986](https://github.com/phalcon/cphalcon/issues/16986) [[doc]](https://docs.phalcon.io/5.13/mvc-url/)
- Added back the `generate_pecl` workflow job and `package.xml`, restoring publication of a `phalcon-pecl.tgz` artifact (also attached to GitHub releases) for a few more versions to give downstream users time to migrate to PIE
- Added functional/expression index support to `Phalcon\Db\Index`. Entries inside the `columns` array can now be `Phalcon\Db\RawValue` instances; string entries continue to be treated as column identifiers and escaped. The base `Phalcon\Db\Dialect::getIndexColumnList()` helper detects `RawValue` entries and per-dialect renders them - MySQL and PostgreSQL wrap each expression in its own parentheses (`KEY idx ((LOWER(col)))` and `CREATE INDEX ON t ((lower(col)))` respectively), while SQLite emits the expression verbatim (its grammar accepts `expr` directly as an `indexed-column`). The helper gains an optional `bool $wrapExpressions = true` flag - defaults are tuned per dialect at the call site so users do not need to think about it. Expressions compose with the descending direction (#8) and partial-index predicate (#9) without any additional API surface. Reverse-engineering of expressions is deferred (PostgreSQL via `pg_get_expr(pg_index.indexprs, ...)`, SQLite via `sqlite_master.sql` parsing - same conservative cutoff used in item #1). No new accessor method is needed - `Index::getColumns()` continues to return the entries (now of mixed string / `RawValue` type) [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added generated/computed column support to `Phalcon\Db\Column` via two new definition-array keys: `generated` (the SQL expression as a string; `null` keeps the column non-generated) and `generationStored` (`bool`, `false` → `VIRTUAL`, `true` → `STORED`; PostgreSQL ignores the flag and always emits `STORED`). Three new public methods report the state at runtime - `getGenerationExpression(): string | null`, `isGenerated(): bool`, `isGenerationStored(): bool`. The class enforces that a generated column cannot also declare `default` or `autoIncrement`. All three dialects (`Mysql`, `Postgresql`, `Sqlite`) emit `GENERATED ALWAYS AS (<expr>) VIRTUAL\|STORED` from `addColumn()`, `createTable()`, and (where supported) `modifyColumn()`, and skip the `DEFAULT` / `AUTO_INCREMENT` / `AUTOINCREMENT` clauses for generated columns. Reverse-engineering through `describeColumns()` is also wired up: MySQL switches from `SHOW FULL COLUMNS` to an equivalent `information_schema.COLUMNS` query that additionally returns `GENERATION_EXPRESSION`; PostgreSQL extends its `information_schema.columns` query with `is_generated` and `generation_expression`; SQLite switches from `PRAGMA table_info` to `PRAGMA table_xinfo` so the `hidden` flag (`2` → VIRTUAL, `3` → STORED) can populate `isGenerated()` / `isGenerationStored()`. SQLite cannot expose the generation expression through any pragma, so `getGenerationExpression()` round-trips as an empty string for SQLite-introspected generated columns (documented limitation). The new methods are declared as commented `@todo v7` stubs on `Phalcon\Db\ColumnInterface` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added hostname-aware URL generation to `Phalcon\Mvc\Url::get()`: when a named route carries a `setHostname()` restriction the returned URL is now protocol-relative (`//hostname/path`) so it works transparently under both HTTP and HTTPS [#17007](https://github.com/phalcon/cphalcon/issues/17007) [[doc]](https://docs.phalcon.io/5.13/mvc-url/)
- Added new Contracts (aka Interfaces) for `Phalcon\Encryption\Security` namely `Phalcon\Contracts\Encryption\Security\Security`, `CryptoUtils`, `CsrfProtection`, and `PasswordSecurity` and tied them to the component [#16991](https://github.com/phalcon/cphalcon/issues/16991) [[doc]](https://docs.phalcon.io/5.13/encryption-security/)
- Added partial-index support on `Phalcon\Db\Index` via a new `where` definition-array key (string). `Phalcon\Db\Index::getWhere(): string` exposes the configured predicate (empty string when none). `Phalcon\Db\Dialect\Postgresql::addIndex` and `Phalcon\Db\Dialect\Sqlite::addIndex` append `` WHERE <expr>`` to the emitted `CREATE INDEX` statement. MySQL has no partial-index feature and its dialect ignores the value. Reverse-engineering of the predicate is deferred for both PostgreSQL (requires `pg_get_expr(pg_index.indpred, pg_index.indrelid)`) and SQLite (requires `sqlite_master.sql` parsing) - same conservative cutoff used for SQLite generation expressions in item #1. Throws `Phalcon\Db\Exception` if the definition-array `where` key is supplied with a non-string value. The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Index` [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added per-column sort direction (`ASC` / `DESC`) support on `Phalcon\Db\Index` via a new `directions` definition-array key. The array is parallel to `columns`; trailing positions absent from `directions` default to `ASC` at emission time. `Phalcon\Db\Index::getDirections(): array` exposes the configured list (empty array means "no per-column direction declared" - preserves the legacy plain `(col1, col2)` rendering exactly). A new protected `Phalcon\Db\Dialect::getIndexColumnList(IndexInterface)` helper centralizes the direction-aware emission and is now used by `Phalcon\Db\Dialect\Mysql::addIndex` / `createTable`, `Phalcon\Db\Dialect\Postgresql::addIndex` / `createTable`, and `Phalcon\Db\Dialect\Sqlite::addIndex` / `createTable`. `Phalcon\Db\Adapter\Pdo\Mysql::describeIndexes` reverse-engineers directions from the `Collation` column of `SHOW INDEXES` (`A` = ASC, `D` = DESC, NULL = ASC); the resulting `Index` only carries a non-empty `directions` array when at least one column is DESC, so existing introspection workflows that don't expect direction metadata see no diff. PostgreSQL and SQLite reverse-engineering of directions is deferred (`pg_index.indoption` and `sqlite_master.sql` parsing respectively - same conservative cutoff used for SQLite generation expressions in item #1). The new method is declared as a commented `@todo v7` stub on `Phalcon\Contracts\Db\Index` to avoid breaking third-party implementors during the v5 line [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added per-option HTML attribute support to the `Phalcon\Html\Helper\Input\Select` data-provider path: `Phalcon\Html\Helper\Input\Select\SelectDataInterface` now also exposes `getAttributes()` returning `[optionValue => [attrName => stringValue, ...]]`; `ArrayData` accepts a second constructor argument with the resolved per-value attribute map, and `ResultsetData` accepts a third `attributesMap` argument (`htmlAttr => string|callable`) whose closures receive the current row. Resolution happens once in the providers (with `false`/`null` results dropped); rendering continues to flow through the existing `AbstractHelper` attribute pipeline [#16983](https://github.com/phalcon/cphalcon/issues/16983) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Added precompiled ARM64 binaries for Linux (`ubuntu-22.04-arm` runner) and macOS (`macos-14`, Apple Silicon) to the release artifacts. The `build_extension` CI matrix now produces `phalcon-php<ver>-<ts>-ubuntu-gcc-arm64.zip` and `phalcon-php<ver>-<ts>-macos-clang-arm64.zip` alongside the existing x64 builds, and the macOS composite action installs `pcre2`/`re2c` via Homebrew, points `CPPFLAGS`/`LDFLAGS` at the keg-only `pcre2` headers, and enables the extension in PHP's `PHP_CONFIG_FILE_SCAN_DIR` so `php --ri phalcon` succeeds [#16553](https://github.com/phalcon/cphalcon/issues/16553)
- Added spatial / geometry column-type support to `Phalcon\Db\Column` and the MySQL and PostgreSQL dialects. Eight new `Column::TYPE_*` constants land: `TYPE_GEOMETRY` (40), `TYPE_POINT` (41), `TYPE_LINESTRING` (42), `TYPE_POLYGON` (43), `TYPE_MULTIPOINT` (44), `TYPE_MULTILINESTRING` (45), `TYPE_MULTIPOLYGON` (46), `TYPE_GEOMETRYCOLLECTION` (47). `Phalcon\Db\Dialect\Mysql::getColumnDefinition` and `Phalcon\Db\Dialect\Postgresql::getColumnDefinition` emit the matching keywords (MySQL recognizes them natively from 5.7; PostgreSQL needs PostGIS installed, which interprets the keywords). SQLite has no native spatial type and its dialect leaves these constants in the `default` branch. `Phalcon\Db\Adapter\Pdo\Mysql::describeColumns` reverse-engineers the new types by `starts_with`-matching the column type - order in the switch was chosen so the longer multi-* / geometrycollection variants are matched before their shorter prefixes (`linestring` before `polygon`, etc.). PostgreSQL reverse-engineering for spatial types is deferred because `information_schema.data_type` does not consistently expose PostGIS type names without joining `pg_type` - users introspecting PostGIS schemas should query metadata directly until then. **Caveat - read-side WKB hydration is not part of this change.** A `POINT` selected directly with `SELECT location FROM items` still returns raw WKB bytes (cphalcon issues [#14769](https://github.com/phalcon/cphalcon/issues/14769) and [#13670](https://github.com/phalcon/cphalcon/issues/13670)); the workaround is to project `ST_AsText(location)` / `ST_AsBinary(location)` / `ST_AsGeoJSON(location)` server-side. The DDL/describe support shipped here is the schema-level prerequisite for any future result-set hydration helper [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added support for arbitrary SQL expressions in DDL `DEFAULT` clauses by recognizing `Phalcon\Db\RawValue` instances passed as `definition["default"]`. Previously each dialect quoted any non-numeric, non-`CURRENT_TIMESTAMP`, non-`NULL` default as a string literal - preventing legitimate expression defaults like MySQL 8.0.13+ `DEFAULT (UUID())`, PostgreSQL `DEFAULT gen_random_uuid()` / `DEFAULT nextval('seq')`, or SQLite 3.31+ `DEFAULT strftime('%s','now')`. `Phalcon\Db\Dialect\Mysql::addColumn` / `createTable` / `modifyColumn`, `Phalcon\Db\Dialect\Postgresql::castDefault` (used by all three of its DDL paths), and `Phalcon\Db\Dialect\Sqlite::addColumn` / `createTable` now detect `RawValue` defaults and emit `DEFAULT <raw>` verbatim. Plain-scalar and `CURRENT_TIMESTAMP` / `NULL` keyword defaults continue to take the existing whitelist path unchanged. `Column::hasDefault()` already treats a `RawValue` as a non-null default, so `isAutoIncrement()` semantics and the generated-column "no default allowed" guard from item #1 remain correct [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)
- Added the canonical Events contracts under the `Phalcon\Contracts\Events` namespace: `Phalcon\Contracts\Events\Event` (replaces `Phalcon\Events\EventInterface`), `Phalcon\Contracts\Events\EventsAware` (replaces `Phalcon\Events\EventsAwareInterface`), and `Phalcon\Contracts\Events\Manager` (replaces `Phalcon\Events\ManagerInterface`). The legacy `Phalcon\Events\*Interface` types are kept as thin extensions of their canonical counterparts, marked `@deprecated`, matching the migration pattern used for `Phalcon\Support\Collection\CollectionInterface`. Existing implementors and typehints continue to work in the v5 line [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Enabled `dropColumn()` on the SQLite dialect to emit `ALTER TABLE ... DROP COLUMN ...` instead of throwing unconditionally - SQLite 3.35+ natively supports `ALTER TABLE DROP COLUMN`, and pre-empting it at the cphalcon dialect level prevented modern users from using the feature. On engines older than 3.35 the server itself rejects the statement at execution time, with a clearer "near 'DROP': syntax error" message than the previous cphalcon-side throw. `Phalcon\Db\Adapter\Pdo\Sqlite::dropColumn` already passes through the dialect output via `AbstractAdapter`, so users now get a one-call `$connection->dropColumn(...)` on SQLite [#14719](https://github.com/phalcon/cphalcon/issues/14719) [[doc]](https://docs.phalcon.io/5.13/db-layer/)

### Fixed

- Fixed `.ci/release-notes.sh` failing intermittently with `grep: write error: Broken pipe` once `CHANGELOG-5.0.md` grew past the pipe-buffer threshold; the `grep ... | head -n N` pipelines (with `set -o pipefail` active) gave `grep` `SIGPIPE` when `head` closed the FD before `grep` finished writing, aborting the step. Replaced both pipelines with single-pass `awk` programs that exit on the matching line, eliminating the broken-pipe race entirely while keeping the original "extract from the latest `## ` heading down to one line above the next `# ` heading" behavior
- Fixed `Phalcon\Annotations\AnnotationsFactory::newInstance("memory")` segfaulting the PHP process [#16962](https://github.com/phalcon/cphalcon/issues/16962) [[doc]](https://docs.phalcon.io/5.13/annotations/)
- Fixed `Phalcon\Cli\Console::handle()` and `Phalcon\Mvc\Application::handle()` not propagating the configured `defaultModule` to the dispatcher when the router returned no module name; both methods resolved a local `moduleName` (router value, falling back to `$this->defaultModule`) for the module-loading path but then called `$dispatcher->setModuleName($router->getModuleName())`, discarding the fallback. As a result, dispatcher events such as `dispatch:beforeDispatchLoop` saw an empty module name even when `setDefaultModule()` had been called. Both call sites now pass the resolved `moduleName` to the dispatcher [#17013](https://github.com/phalcon/cphalcon/issues/17013) [[doc]](https://docs.phalcon.io/5.13/application-cli/)
- Fixed `Phalcon\Db\Dialect::getSqlExpression()` not propagating the outer `bindCounts` map into the recursive `select()` call rendered for nested sub-SELECTs, so an array placeholder (`{name:array}`) inside a sub-SELECT kept the parse-time `times` count baked into the cached PHQL intermediate; a second execution of the same outer PHQL with the same bind name but a different bind-array size fell back to the stale count and PDO raised "Invalid parameter number: number of bound variables does not match number of tokens" (workaround was `Phalcon\Mvc\Model\Query::clean()` between calls). The `select` branch now seeds the nested definition's `bindCounts` from the outer `bindCounts` on a local copy of the nested intermediate so the runtime placeholder-count override fires at every nesting level without mutating the cached intermediate [#17004](https://github.com/phalcon/cphalcon/issues/17004) [[doc]](https://docs.phalcon.io/5.13/db-phql/)
- Fixed `Phalcon\Events\Manager::fireQueue()` segfaulting when invoking a `Closure` listener whose declared parameter count is less than the three arguments the manager passes (`$event, $source, $data`). The previous `handler->__invoke(...)` form routed through PHP's strict C-level method-call path which sets up a 3-slot frame that the closure's own 2-slot (or fewer) frame cannot accept, producing undefined behavior and a process crash. The dispatch path now uses Zephir's `{handler}(args)` callable-invocation syntax, which routes through `zend_call_function` and handles closure arity mismatch correctly [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)
- Fixed `Phalcon\Forms\Form::bind()` leaving the entity property untouched when a `Check` element's key was absent from submitted data (the browser behavior for an unchecked checkbox), so a previously-`true` field could never be reset by re-submitting the form. `Phalcon\Forms\Element\Check` gains opt-in `setUncheckedValue()` / `getUncheckedValue()` / `hasUncheckedValue()`; when an unchecked value has been registered and the element's data key is missing from the bind payload, `bind()` injects the registered value into `$data` before the main loop so it flows through whitelist, filters, and entity setters identically to a submitted value. Checks without an explicit `setUncheckedValue()` preserve the previous behavior (entity untouched) [#16982](https://github.com/phalcon/cphalcon/issues/16982) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Fixed `Phalcon\Forms\Form::bind()` silently dropping data for `Radio` elements registered under distinct form-element identifiers but sharing the same HTML `name` attribute (e.g. `new Radio('r0', ['name' => 'banned'])`, `new Radio('r1', ['name' => 'banned'])` bound from `['banned' => 'yes']`); the bind loop only looked up `$this->elements[$key]` and skipped the value when no element matched, so the entity property was never set. The lookup now falls back to scanning registered elements for one whose HTML `name` attribute matches the data key [#15957](https://github.com/phalcon/cphalcon/issues/15957) [[doc]](https://docs.phalcon.io/5.13/forms/)
- Fixed `Phalcon\Html\Helper\Input\AbstractInput::__invoke()` always assigning an `id` attribute equal to the element name, producing invalid markup like `id="tags[]"` when the name contained brackets (array names or indexed names like `roles[0]`). The auto-`id` is now skipped when the name contains `[`, matching the behavior of the corresponding helper in the PHP-side `phalcon/phalcon` library
- Fixed `Phalcon\Mvc\Model::__set()` not clearing the cached related record when a `belongsTo` relation alias is assigned `null`; calling a getter before setting the relation to null caused `preSaveRelatedRecords()` to overwrite the FK back to its previous value on save [#16611](https://github.com/phalcon/cphalcon/issues/16611) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model::assign()` and `Phalcon\Mvc\Model::writeAttribute()` silently dropping values for columns whose name maps to a reserved internal setter (`source`, `schema`, `dirtyState`, `connectionService`, `readConnectionService`, `writeConnectionService`, `eventsManager`, `transaction`, `snapshotData`, `oldSnapshotData`); `Phalcon\Mvc\Model::possibleSetter()` returned `true` for these reserved names while skipping both the setter call and the property assignment, so the value never landed on the model. It now returns `false` for reserved setters, letting the caller fall through to direct property assignment while still preventing the reserved internal setter from being hijacked by the column [#16617](https://github.com/phalcon/cphalcon/issues/16617) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model::cloneResultMap()` and `Phalcon\Mvc\Model::possibleSetter()` throwing `TypeError` during hydration when a model setter has a strict type hint (e.g. `?array`) and the raw database value is incompatible; the ORM now catches `TypeError` and falls back to direct property assignment [#16956](https://github.com/phalcon/cphalcon/issues/16956) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model::doLowInsert()` throwing `Unable to insert into <table> without data` when saving a model whose only column is an auto-increment primary key; on dialects where `useExplicitIdValue()` is `false` (MySQL, SQLite) the identity branch produced an empty `values` array. The identity column is now added with the connection's default identity value when the resulting `values` array would otherwise be empty [#156](https://github.com/phalcon/phalcon/issues/156) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model::find()` return type regression introduced in 5.7.0 (PR [#16578](https://github.com/phalcon/cphalcon/pull/16578)) that removed the `: ResultsetInterface` runtime declaration while adding `@template T` generic docblocks for IDE autocompletion. Subclass overrides that narrowed the return type to `: ResultsetInterface` and call sites that assigned the result to a typed property (`private ResultsetInterface $robots = Robots::find(...)`) broke on upgrade from 5.6.x. The runtime return type is restored, and the docblock claim was tightened from `T[]|\Phalcon\Mvc\Model\Resultset<int, T>` to `\Phalcon\Mvc\Model\Resultset<int, T>` so it is a strict subtype of the runtime declaration - Psalm previously raised `MismatchingDocblockReturnType` on the generated ide-stubs because `T[]` resolves to `array<int, T>`, which is not a `ResultsetInterface` (the `T[]` half of the union was always false; `find()` never returns a plain PHP array, even under `HYDRATE_ARRAYS`). Modern IDEs and static analyzers continue to resolve element-type `T` through the surviving generic annotation. `findFirst()` is unchanged - it has always returned `var | null` because it can legitimately return a `ModelInterface`, a `Row`, or `null` depending on the projection [#16633](https://github.com/phalcon/cphalcon/issues/16633) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model::findFirst()` docblock claim that diluted the generic return type. The annotation was `@return T|\Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row|null` (introduced by PR [#16578](https://github.com/phalcon/cphalcon/pull/16578)), but since `@template T of static` and every `Model` subclass implements `ModelInterface`, the `ModelInterface` union member is a supertype of `T` and Psalm/PHPStan collapsed the union to its widest member - losing `T` and forcing user code that called child-class-specific methods on `findFirst()`'s result to assert `instanceof self` first. The redundant `ModelInterface` member is removed; the annotation is now `@return T|\Phalcon\Mvc\Model\Row|null`, preserving `T` for static analyzers while keeping `Row` (returned when the query projects scalar columns) and `null` (no match) honest [#16661](https://github.com/phalcon/cphalcon/issues/16661) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model::preSaveRelatedRecords()` skipping `doSave()` for `belongsTo` parents whose `dirtyState` was `DIRTY_STATE_PERSISTENT`; modifications made to an existing parent (loaded via `findFirst()`) and then attached to a new child were silently dropped on save, while only the FK was written. The dirtyState short-circuit (originally added to break circular hasMany ⇄ belongsTo recursion) is removed and recursion is now prevented by the `visited` collection already enforced inside `doSave()` [#16222](https://github.com/phalcon/cphalcon/issues/16222) [[doc]](https://docs.phalcon.io/5.13/db-models/)
- Fixed `Phalcon\Mvc\Model\Query::executeUpdate()` and `Phalcon\Mvc\Model::doLowUpdate()` for PHQL `UPDATE ... SET <expr>` expressions with placeholders (e.g. `col = col + :inc:`): named placeholders embedded in expression SQL are now resolved before creating `RawValue` to avoid PDO "mixed named and positional parameters", and dynamic-update comparisons now always treat `RawValue` assignments as changed so updates are not skipped when the current numeric value is `0` [#16976](https://github.com/phalcon/cphalcon/issues/16976) [[doc]](https://docs.phalcon.io/5.13/db-phql/)
- Fixed `Phalcon\Mvc\Model\Query::parse()` returning a cached intermediate representation with the model's original schema/source baked into the `tables` slot, so subsequent `find()`/`findFirst()`/`findBy*()` calls for the same PHQL string kept emitting SQL pointing at the original schema after the model changed its schema at runtime (e.g. via a wrapper calling `setSchema()`); the cache-hit branch now refreshes the `tables` entries from the live `model->getSchema()`/`getSource()` before returning, preserving the parse-cache benefit while keeping the rendered FROM clause in sync with current model state [#17020](https://github.com/phalcon/cphalcon/issues/17020) [[doc]](https://docs.phalcon.io/5.13/db-phql/)
- Fixed `Phalcon\Mvc\Router::handle()` leaving unmatched optional named parameters (e.g. `{id:(/[0-9]+)?}{slug:(/.+)?}`) in the resulting params with their raw regex group positions (`id => 1, slug => 2`) instead of unsetting them; the unset branch was nested under `else` of `typeof converters === "array"`, but `Route::$converters` defaults to `[]` so the branch was unreachable. The check is now flattened so an unmatched positional parameter is removed when no per-part converter exists [#16559](https://github.com/phalcon/cphalcon/issues/16559) [[doc]](https://docs.phalcon.io/5.13/routing/)
- Fixed `Phalcon\Mvc\View::getActiveRenderPath()` returning only the first candidate path as a string when a single `viewsDir` was configured with multiple registered render engines and the view was not found; the method now collapses the internal `activeRenderPaths` array to a string only when it contains exactly one element, returning the full array of candidate paths in all other cases [#16614](https://github.com/phalcon/cphalcon/issues/16614) [[doc]](https://docs.phalcon.io/5.13/views/)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler` rejecting single-quoted Volt string literals containing an escaped single quote (e.g. `{{ 'Let\'s Encrypt' }}`) with a downstream PHP `T_STRING` parse error; the Volt scanner already preserves the user-written `\'` verbatim in `expr["value"]`, so the compiler's `str_replace("'", "\\'", expr["value"])` step double-escaped it into `Let\\'s Encrypt`, producing PHP source `'Let\\'s Encrypt'` that PHP read as `Let\` followed by an unexpected identifier. Dropped the redundant `str_replace`; the scanner's regex (`(['] ([\\][']|[\\].|...) ['])`) guarantees `expr["value"]` is already valid PHP single-quoted string content [#17002](https://github.com/phalcon/cphalcon/issues/17002) [[doc]](https://docs.phalcon.io/5.13/volt/)
- Fixed `Phalcon\Support\Collection::get()` returning the wrapping object's mangled property table when called with `$cast = 'array'` on a stored object (e.g. a nested `Phalcon\Config\Config`, which `Config::setData()` wraps around every array value). The previous implementation called `settype($value, 'array')` unconditionally, which on an object exposes PHP's null-prefixed internal protected-property names (`"\0*\0data"`, `"\0*\0lowerKeys"`, etc.) instead of the intended array form, so `$config->get('outKey', [], 'array')['inKey']` raised `Notice: Undefined index`. The cast branch now special-cases `'array'` for objects exposing a `toArray()` method and delegates to that method; scalar casts (`int`, `bool`, `float`, `string`, `null`, `object`) and `'array'` on a plain `stdClass` (no `toArray()`) are unchanged [#17005](https://github.com/phalcon/cphalcon/issues/17005) [[doc]](https://docs.phalcon.io/5.13/support-collection/)
- Fixed `Phalcon\Tag\Select::optionsFromArray()` not escaping option label text, allowing XSS injection via malicious values; labels are now escaped with `escapeHtml()` and option values with `escapeHtmlAttr()` via the escaper service, consistent with `optionsFromResultset()` [#16660](https://github.com/phalcon/cphalcon/issues/16660) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)
- Fixed nested `Phalcon\Events\Manager::fire()` calls clobbering the outer caller's collected `$this->responses` state. Previously the inner fire would reset `$this->responses = []` and append its own listener returns there, so after the nested fire returned the outer caller's `getResponses()` saw the inner fire's results instead of its own. `fire()` now tracks re-entrancy depth via a new internal `fireDepth` counter and, on a nested call with `collect=true`, stashes the outer's responses on entry and restores them on exit so the outer accumulator is preserved across the inner dispatch. `fireAll()` applies the same stash-and-restore pattern unconditionally so it never pollutes outer collected state regardless of the manager's `collectResponses()` setting [#17006](https://github.com/phalcon/cphalcon/issues/17006) [[doc]](https://docs.phalcon.io/5.13/events/)

### Removed

- Removed calls to `version_compare` that led to pre PHP 8.0 code [#16966](https://github.com/phalcon/cphalcon/issues/16966)
- Removed the per-type input helpers `Phalcon\Html\Helper\Input\Color`, `Date`, `DateTime`, `DateTimeLocal`, `Email`, `File`, `Hidden`, `Image`, `Input`, `Month`, `Numeric`, `Password`, `Range`, `Search`, `Submit`, `Tel`, `Text`, `Time`, `Url`, and `Week`; their `TagFactory` service names (`inputColor`, `inputDate`, ...) now resolve to `Phalcon\Html\Helper\Input\Generic` with the appropriate `type` baked into the recipe, so callers using the factory keep working unchanged [#16971](https://github.com/phalcon/cphalcon/issues/16971) [[doc]](https://docs.phalcon.io/5.13/html-tagfactory/)

## [5.12.1](https://github.com/phalcon/cphalcon/releases/tag/v5.12.1) (2026-04-30)

### Changed

### Added

- Added `Phalcon\Db\Column::TYPE_UUID` constant (value `29`) and added support for PostgreSQL native `uuid` column type in `Phalcon\Db\Adapter\Pdo\Postgresql` and `Phalcon\Db\Dialect\Postgresql` [#16840](https://github.com/phalcon/cphalcon/issues/16840) [[doc]](https://docs.phalcon.io/5.12/db-layer/)
- Added support for `Phalcon\Mvc\Url` static base URI in `Phalcon\Assets\Manager`; when a DI container is set and a `url` service is available, local asset paths are now resolved via `getStatic()` instead of a bare `/` prefix [#16570](https://github.com/phalcon/cphalcon/issues/16570) [[doc]](https://docs.phalcon.io/5.12/assets/)

### Fixed

- Fixed `Phalcon\Mvc\Model\MetaDataInterface::readMetaDataIndex()` and `Phalcon\Mvc\Model\MetaData::readMetaDataIndex()` declaring return type as `array|null` when the method can also return a `string` (e.g. for `MODELS_IDENTITY_COLUMN`), causing a PHP fatal error on PHP 8+ [#16613](https://github.com/phalcon/cphalcon/issues/16613) [[doc]](https://docs.phalcon.io/5.12/db-models-metadata/)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler::statementList()` returning `null` instead of `string` when processing templates that consist entirely of block-mode statements, causing a PHP fatal error on PHP 8+ [#16613](https://github.com/phalcon/cphalcon/issues/16613) [[doc]](https://docs.phalcon.io/5.12/volt/)
- Fixed `Phalcon\Forms\Element\Select::render()` multiselect regression introduced in v5.12.0 (#16894) by reverting to `Phalcon\Tag\Select::selectField()`; the new `Html\Helper\Input\Select` only supports a single selected value and does not handle array values required for multiselect [#16946](https://github.com/phalcon/cphalcon/issues/16946) [[doc]](https://docs.phalcon.io/5.12/forms/)
- Fixed `Phalcon\Html\Helper\Input\AbstractInput::setValue()` ignoring empty string `""` as a valid value, causing `Checkbox` and `Radio` inputs with `value=""` to never render `checked="checked"` even when the `checked` attribute matched [#16648](https://github.com/phalcon/cphalcon/issues/16648) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Fixed `Phalcon\Http\Response\Cookies::get()` throwing an opaque fatal error when no DI container has been set; it now throws `Phalcon\Http\Cookie\Exception` with a descriptive message before accessing the container [#16650](https://github.com/phalcon/cphalcon/issues/16650) [[doc]](https://docs.phalcon.io/5.12/http-response/)
- Fixed `Phalcon\Mvc\Model\MetaData::writeMetaDataIndex()` prematurely initializing a child model's metadata with the parent's source table when `skipAttributes()` (or `skipAttributesOnCreate()`/`skipAttributesOnUpdate()`) is called inside a parent model's `initialize()` and the child calls `parent::initialize()` before setting its own source, corrupting the child's attribute list and breaking relationship resolution [#16544](https://github.com/phalcon/cphalcon/issues/16544) [[doc]](https://docs.phalcon.io/5.12/db-models-metadata/)
- Fixed `Phalcon\Storage\Serializer\Json::serialize()` rejecting plain objects (e.g. `stdClass`) that do not implement `JsonSerializable`; `json_encode()` handles such objects natively and the guard was unnecessary [#16630](https://github.com/phalcon/cphalcon/issues/16630) [[doc]](https://docs.phalcon.io/5.12/storage/)
- Fixed `Phalcon\Mvc\Model\Manager` retaining a model instance in `lastInitialized` after initialization and `Phalcon\Mvc\Model` not clearing the reusable-records cache after `save()`, causing memory to grow unboundedly in long-running processes [#16566](https://github.com/phalcon/cphalcon/issues/16566) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Paginator\Adapter\QueryBuilder::paginate()` returning wrong total item count when the query uses `DISTINCT` columns; the count now uses `COUNT(DISTINCT ...)` for a single column and a subquery for multiple columns [#16581](https://github.com/phalcon/cphalcon/issues/16581) [[doc]](https://docs.phalcon.io/5.12/db-pagination/)
- Fixed `Phalcon\Mvc\Model\Query\Builder::autoescape()` incorrectly wrapping function expressions (e.g. `DATE_PART(...)`) in brackets when used in `groupBy()`, causing a `"Column does not belong to any of the selected models"` exception [#16599](https://github.com/phalcon/cphalcon/issues/16599) [[doc]](https://docs.phalcon.io/5.12/db-phql/)
- Fixed `Phalcon\Mvc\Model` - saving a model with multiple fields relations threw `"Not implemented"` [#16029](https://github.com/phalcon/cphalcon/issues/16029) [[doc]](https://docs.phalcon.io/5.12/db-models/)

## [5.12.0](https://github.com/phalcon/cphalcon/releases/tag/v5.12.0) (2026-04-29)

### Changed

- Changed `Phalcon\Assets\Manager` filter type check from `is_object()` to `typeof` and updated the error message to `"The filter is not valid"` [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/assets/)
- Changed `Phalcon\Cache\AbstractCache::doDeleteMultiple()` to delegate to the storage adapter's `deleteMultiple()` instead of looping over individual `delete()` calls [#16859](https://github.com/phalcon/cphalcon/issues/16859) [[doc]](https://docs.phalcon.io/5.12/cache/)
- Changed `Phalcon\Di\Exception` message for missing services from `"was not found in the dependency injection container"` to `"is not registered in the container"` [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/di/)
- Changed `Phalcon\Di\Service\Builder` error messages for service parameters to use double quotes instead of single quotes [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/di/)
- Changed `Phalcon\Forms\Element\AbstractElement::getLocalTagFactory()` to throw `Phalcon\Forms\Exception` instead of silently creating a new `TagFactory` when neither `setTagFactory()` nor a parent `Form` provides one [#16894](https://github.com/phalcon/cphalcon/issues/16894) [[doc]](https://docs.phalcon.io/5.12/forms/)
- Changed `Phalcon\Forms\Element\Select::render()` to use `TagFactory`-based `Html\Helper\Input\Select` instead of the deprecated `Phalcon\Tag\Select` [#16894](https://github.com/phalcon/cphalcon/issues/16894) [[doc]](https://docs.phalcon.io/5.12/forms/)
- Changed `Phalcon\Html\TagFactory` to accept an optional `ResponseInterface` in the constructor (useful for `preload`) [#16892](https://github.com/phalcon/cphalcon/issues/16892) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Changed `Phalcon\Mvc\Controller` and `Phalcon\Mvc\View\Engine\AbstractEngine` to be events aware [#16890](https://github.com/phalcon/cphalcon/pull/16890) [[doc]](https://docs.phalcon.io/5.12/controllers/)
- Changed `Phalcon\Mvc\View\Engine\Volt\Compiler::setOptions` to return `$this` now [#16891](https://github.com/phalcon/cphalcon/pull/16891) [[doc]](https://docs.phalcon.io/5.12/volt/)
- Changed calls to `globals_get` and `globals_set` in the code with `Phalcon\Support\Settings::get()/set()` [#16884](https://github.com/phalcon/cphalcon/issues/16884) [[doc]](https://docs.phalcon.io/5.12/support-settings/)
- Changed exception messages across multiple components to use `"does not"` instead of `"doesn't"` for consistency [#16889](https://github.com/phalcon/cphalcon/issues/16889)

### Added

- Added `Phalcon\Encryption\Security\Uuid` factory and versioned adapters (`Version1`–`Version7`) with a `UuidInterface` carrying standard RFC 4122 namespace constants; each version is a singleton cached by the factory, invoked via `v1()`–`v7()` [#16326](https://github.com/phalcon/cphalcon/issues/16326) [[doc]](https://docs.phalcon.io/5.12/encryption-security/)
- Added `Phalcon\Html\Helper\FriendlyTitle` - available via `TagFactory` as `friendlyTitle` [#16892(https://github.com/phalcon/cphalcon/issues/16892) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Added `Phalcon\Html\Helper\Input\Select::fromData()` to populate select options from a `SelectDataInterface` provider, with optgroup support [#16894](https://github.com/phalcon/cphalcon/issues/16894) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Added `Phalcon\Html\Helper\Input\Select\SelectDataInterface`, `Phalcon\Html\Helper\Input\Select\ArrayData`, and `Phalcon\Html\Helper\Input\Select\ResultsetData` as data providers for the `Select` helper [#16894](https://github.com/phalcon/cphalcon/issues/16894) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Added `Phalcon\Html\Helper\Preload` - available via `TagFactory` as `preload`; `TagFactory` now accepts an optional `ResponseInterface` as its third constructor parameter [#16892(https://github.com/phalcon/cphalcon/issues/16892) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Added `Phalcon\Mvc\Model\Resultset::refresh()` to re-execute the underlying query and update the resultset with fresh data from the database [#16409](https://github.com/phalcon/cphalcon/issues/16409) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Added `deleteMultiple()` to `Phalcon\Storage\Adapter\*` to delete multiple keys in a single operation using native batch capabilities per adapter [#16859](https://github.com/phalcon/cphalcon/issues/16859) [[doc]](https://docs.phalcon.io/5.12/storage/)
- Added key validation per entry in `Phalcon\Cache\AbstractCache::doDeleteMultiple()` throwing `InvalidArgumentException` for keys containing invalid characters [#16859](https://github.com/phalcon/cphalcon/issues/16859) [[doc]](https://docs.phalcon.io/5.12/cache/)
- Added named static factory methods `Phalcon\Forms\Exception::tagFactoryNotFound()` and `Phalcon\Forms\Exception::usingParameterRequired()` [#16894](https://github.com/phalcon/cphalcon/issues/16894) [[doc]](https://docs.phalcon.io/5.12/forms/)

### Fixed

- Fixed `Phalcon\Db\Dialect\Postgresql::modifyColumn()` to generate correct SQL when changing a boolean column's default value: replaced `empty` check with `hasDefault()` to avoid treating `false` as "no default", removed the boolean-only branch that omitted the `ALTER TABLE` prefix, and fixed `castDefault()` to return PostgreSQL literals `true`/`false` instead of raw PHP booleans [#15829](https://github.com/phalcon/cphalcon/issues/15829) [[doc]](https://docs.phalcon.io/5.12/db-layer/)
- Fixed `Phalcon\Db\Result\PdoResult::$rowCount` to use `null` as the uninitialised sentinel instead of `false`, preventing a count of `0` rows being confused with "not yet counted" [#16409](https://github.com/phalcon/cphalcon/issues/16409) [[doc]](https://docs.phalcon.io/5.12/db-layer/)
- Fixed `Phalcon\Dispatcher\AbstractDispatcher::dispatch()` to refresh the local `eventsManager` and `hasEventsManager` variables after `initialize()` returns, so that an events manager attached to the dispatcher inside `initialize()` is honored for all subsequent dispatch events (`afterInitialize`, `afterExecuteRoute`, `afterDispatch`, `afterDispatchLoop`, etc.) [#16440](https://github.com/phalcon/cphalcon/issues/16440) [[doc]](https://docs.phalcon.io/5.12/dispatcher/)
- Fixed `Phalcon\Filter\Validation::bind()` to skip the dependency injection container lookup when `data` is empty, preventing unnecessary `Di\Exception` errors [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/filter-validation/)
- Fixed `Phalcon\Filter\Validation\AbstractValidator::allowEmpty()` to support a value-list array (e.g. `[null, '']`) in addition to the per-field map syntax, using strict `===` comparison so that `'0'` is never silently treated as empty [#15491](https://github.com/phalcon/cphalcon/issues/15491) [[doc]](https://docs.phalcon.io/5.12/filter-validation/)
- Fixed `Phalcon\Filter\Validation\AbstractValidator::messageFactory()` to pass the joined field string to `Phalcon\Messages\Message` instead of the raw array when multiple fields are provided [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/filter-validation/)
- Fixed `Phalcon\Filter\Validation\Validator\Alpha::validate()` to return `false` when `allowEmpty` is explicitly set to `false` and the submitted value is `null` or an empty string [#16200](https://github.com/phalcon/cphalcon/issues/16200) [[doc]](https://docs.phalcon.io/5.12/filter-validation/)
- Fixed `Phalcon\Forms\Form::isValid()` to apply field filters even when no validators are specified (again) [#16830](https://github.com/phalcon/cphalcon/issues/16830) [[doc]](https://docs.phalcon.io/5.12/forms/)
- Fixed `Phalcon\Html\Escaper::css()` and `Phalcon\Html\Escaper::js()` to return an empty string instead of `false` when the input is empty or contains only a null codepoint [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/html-escaper/)
- Fixed `Phalcon\Html\Helper\AbstractHelper::renderAttributes()` to emit boolean HTML5 attributes (e.g. `async`, `defer`) as standalone attribute names instead of `async="1"` when the attribute value is `true` [#16304](https://github.com/phalcon/cphalcon/issues/16304) [[doc]](https://docs.phalcon.io/5.12/html-tagfactory/)
- Fixed `Phalcon\Html\Helper\Breadcrumbs` to support subdirectory installs: added `getPrefix()`/`setPrefix()` for a manual string prefix, and an optional `UrlInterface` constructor parameter that resolves links through `url->get()` (including base URI prepending and double-slash normalisation); `TagFactory` accepts an optional fourth `UrlInterface` argument and passes it to `Breadcrumbs` automatically [#14957](https://github.com/phalcon/cphalcon/issues/14957) [[doc]](https://docs.phalcon.io/5.12/html-breadcrumbs/)
- Fixed `Phalcon\Http\Response::setStatusCode()` exception message from `"Non-standard statuscode given without a message"` to `"Non-standard status-code given without a message"` [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/http-response/)
- Fixed `Phalcon\Image\Adapter\AbstractAdapter::crop()` to correctly handle `offsetX = 0` and `offsetY = 0` by changing the parameter types from `int` to `var`; the previous `int` typing caused Zephir to compile the `null` check as `0 == offset` in C, making explicit zero offsets indistinguishable from omitted (center) offsets [#16156](https://github.com/phalcon/cphalcon/issues/16156) [[doc]](https://docs.phalcon.io/5.12/image/)
- Fixed `Phalcon\Image\Adapter\Gd::processResize()` to preserve PNG alpha channel transparency by replacing `imagescale()` with `imagecreatetruecolor()` + `imagealphablending(false)` + `imagesavealpha(true)` + `imagecopyresampled()` [#16316](https://github.com/phalcon/cphalcon/issues/16316) [[doc]](https://docs.phalcon.io/5.12/image/)
- Fixed `Phalcon\Image\Adapter\Imagick::processPixelate()` to explicitly cast division result to `int` to prevent implicit float-to-int deprecation [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/image/)
- Fixed `Phalcon\Mvc\Model::__get()` to return the already-loaded related record instead of re-fetching from the database, preventing modifications to relation properties from being discarded [#15554](https://github.com/phalcon/cphalcon/issues/15554) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::__unserialize()` and `Phalcon\Mvc\Model::unserialize()` to call `onConstruct()` after deserialization, so typed properties initialized in `onConstruct` are correctly set when a model is restored from cache [#15906](https://github.com/phalcon/cphalcon/issues/15906) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::__unserialize()` and `Phalcon\Mvc\Model::unserialize()` to restore snapshot as the current attributes (instead of null) when a model is deserialized with no pending changes, preventing `getChangedFields()` from throwing after cache retrieval [#15837](https://github.com/phalcon/cphalcon/issues/15837) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::cloneResultMap()` to call model setter methods (e.g. `setName()`) during ORM hydration when `orm.disable_assign_setters` is `false`, making hydration behaviour consistent with `assign()`; setters in `localMethods` (Phalcon internals) are excluded [#14810](https://github.com/phalcon/cphalcon/issues/14810) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::collectRelatedToSave()` to skip unmodified `hasOne`/`hasMany` related records that have snapshot data, preventing spurious `INSERT`/`UPDATE` statements when a relation is read but not changed [#16000](https://github.com/phalcon/cphalcon/issues/16000) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::doLowInsert()` to also reset `uniqueKey` (in addition to `uniqueParams`) after an auto-increment INSERT so that a subsequent `has()` call on the same record rebuilds the primary-key condition from current attribute values; previously, `uniqueParams` was cleared but `uniqueKey` was kept, causing `has()` to query with a `null` parameter and return `false`, which made `SoftDelete` attempt to INSERT an already-existing `belongsTo` related record instead of updating it [#16453](https://github.com/phalcon/cphalcon/issues/16453) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::doLowUpdate()` to skip columns whose string value matches the column's function-call DB default (e.g. `gen_random_uuid()`) in the non-dynamic update path, preventing the function name from being passed as a bound string parameter and causing a DB type error [#15828](https://github.com/phalcon/cphalcon/issues/15828) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::doSave()` to capture the model snapshot before the INSERT/UPDATE and restore it when `postSaveRelatedRecords` fails and rolls back the transaction; previously, with `orm.update_snapshot_on_save` enabled, the snapshot was permanently updated inside `doLowInsert`/`doLowUpdate` even when the transaction was rolled back, causing Dynamic Update to silently skip the write on the next save attempt [#16410](https://github.com/phalcon/cphalcon/issues/16410) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::getRelated()` to return already-fetched relations from the internal cache (`dirtyRelated` first, then `related`) instead of always querying the database; cache is cleared after `save()` and `delete()` to prevent stale results [#16409](https://github.com/phalcon/cphalcon/issues/16409) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::toArray()` to catch `Error` thrown by a getter that accesses an uninitialized typed PHP property (can occur when `cloneResultMap()` skips a null value for a `NOT NULL` column, e.g. via a `LEFT JOIN`), returning `null` instead of propagating the error [#15711](https://github.com/phalcon/cphalcon/issues/15711) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model::unserialize()` to catch `TypeError` when assigning a serialised `null` back to a typed non-nullable PHP property, preventing a crash on the second request when the model is loaded from a cache like APCu [#15711](https://github.com/phalcon/cphalcon/issues/15711) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model\Manager::getRelationRecords()` to apply reusable caching for `hasManyToMany` and `hasOneThrough` relations; `reusable: true` was previously ignored for through-relations [#15934](https://github.com/phalcon/cphalcon/issues/15934) [[doc]](https://docs.phalcon.io/5.12/db-models-relationships/)
- Fixed `Phalcon\Mvc\Model\Query::executeSelect()` to embed `Phalcon\Db\RawValue` bind parameters directly in the SQL string instead of passing them to PDO [#16350](https://github.com/phalcon/cphalcon/issues/16350) [[doc]](https://docs.phalcon.io/5.12/db-phql/)
- Fixed `Phalcon\Mvc\Model\Query::executeSelect()` to use the write connection when the query contains a `FOR UPDATE` clause, instead of always using the read connection [#16032](https://github.com/phalcon/cphalcon/issues/16032) [[doc]](https://docs.phalcon.io/5.12/db-phql/)
- Fixed `Phalcon\Mvc\Model\Query::getExpression()` to emit `NOT BETWEEN` instead of `BETWEEN NOT` for the `PHQL_T_BETWEEN_NOT` token, producing valid SQL [#16812](https://github.com/phalcon/cphalcon/issues/16812) [[doc]](https://docs.phalcon.io/5.12/db-phql/)
- Fixed `Phalcon\Mvc\Model\Query::getSelectColumn()` to use the full model class name as the `balias` key in a complex resultset when the model is namespaced (e.g. `App\Models\Users`), instead of incorrectly applying `lcfirst()` to the fully-qualified name; non-namespaced models (e.g. `Robots`) retain the existing `lcfirst()` behaviour (`robots`) [#16052](https://github.com/phalcon/cphalcon/issues/16052) [[doc]](https://docs.phalcon.io/5.12/db-phql/)
- Fixed `Phalcon\Mvc\Model\Query\Builder::getPhql()` to use a named bind parameter (`:APK0:`) instead of embedding the raw primary-key value in the PHQL string when `findFirst()` is called with a numeric or numeric-string argument; this prevents unbounded growth of the internal PHQL AST cache (`Query::$internalPhqlCache`) in long-running CLI processes [#14656](https://github.com/phalcon/cphalcon/issues/14656) [[doc]](https://docs.phalcon.io/5.12/db-phql/)
- Fixed `Phalcon\Mvc\Model\Resultset\Complex::current()` to return `null` instead of an empty model instance when a `LEFT JOIN` produces no matching row (all column values are `null`) [#16239](https://github.com/phalcon/cphalcon/issues/16239) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Model\Transaction\Manager::collectTransaction()` to keep the correct transactions when rebuilding the list after removal [#16522](https://github.com/phalcon/cphalcon/issues/16522) [[doc]](https://docs.phalcon.io/5.12/db-models-transactions/)
- Fixed `Phalcon\Mvc\Model\Transaction\Manager::commit()` to remove each transaction from the pool after committing so that subsequent `get()` calls return a fresh transaction [#16522](https://github.com/phalcon/cphalcon/issues/16522) [[doc]](https://docs.phalcon.io/5.12/db-models-transactions/)
- Fixed `Phalcon\Mvc\Model` to handle the `lastInsertId correctly under Postgres [#16920](https://github.com/phalcon/cphalcon/pull/16920) [#16436](https://github.com/phalcon/cphalcon/pull/16436) [#15775](https://github.com/phalcon/cphalcon/pull/15775) [[doc]](https://docs.phalcon.io/5.12/db-models/)
- Fixed `Phalcon\Mvc\Router\Annotations::handle()` to strip the `controllerSuffix` from the class name when a fully-qualified class name already includes it (e.g. `App\Controllers\InvoicesController`), preventing the doubled suffix `InvoicesControllerController` [#16238](https://github.com/phalcon/cphalcon/issues/16238) [[doc]](https://docs.phalcon.io/5.12/routing/)
- Fixed `Phalcon\Paginator\Adapter\QueryBuilder::paginate()` to correctly count groups when `groupBy()` receives a multi-column array, using a `SELECT DISTINCT` subquery instead of the PostgreSQL-incompatible `COUNT(DISTINCT col1, col2)` form [#15912](https://github.com/phalcon/cphalcon/issues/15912) [[doc]](https://docs.phalcon.io/5.12/db-pagination/)
- Fixed `Phalcon\Paginator\Adapter\QueryBuilder::paginate()` to use the `columns` option as the `COUNT(DISTINCT ...)` argument when a `GROUP BY` is present, allowing NULL-safe expressions to be supplied [#15266](https://github.com/phalcon/cphalcon/issues/15266) [[doc]](https://docs.phalcon.io/5.12/db-pagination/)
- Fixed `Phalcon\Storage\Adapter\Libmemcached`, `Phalcon\Storage\Adapter\Redis` and `Phalcon\Storage\Adapter\Weak` to call `initSerializer()` during construction [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/storage/)
- Fixed `Phalcon\Storage\Adapter\Redis` to initialize `lifetime` from options during construction [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/storage/)
- Fixed `Phalcon\Support\Helper\Json\Encode` to prefix the `InvalidArgumentException` message with `"json_encode error: "` for consistency [#16889](https://github.com/phalcon/cphalcon/issues/16889) [[doc]](https://docs.phalcon.io/5.12/support-helper/)
- Fixed the CI run to correctly use updated changes, and reuse artifacts [#16920](https://github.com/phalcon/cphalcon/pull/16920)
- Fixed the CI run to now run Postgresql tests [#16920](https://github.com/phalcon/cphalcon/pull/16920)
- Fixed the CI run to now run Sqlite tests [#16920](https://github.com/phalcon/cphalcon/pull/16920)

### Removed

## [5.11.1](https://github.com/phalcon/cphalcon/releases/tag/v5.11.1) (2026-04-04)

### Changed

### Added

- Added `Phalcon\Storage\Adapter\RedisCluster` adapter to support Redis Cluster connections [#16867](https://github.com/phalcon/cphalcon/issues/16867)
- Added `Phalcon\Support\Settings` to be used for ini settings throughout the framework [#16873](https://github.com/phalcon/cphalcon/issues/16873)

### Fixed

- Fixed `Phalcon\Encryption\Security::computeHmac()` to catch `\ValueError` thrown by PHP 8.1+ when an unknown hashing algorithm is passed [#16893](https://github.com/phalcon/cphalcon/issues/16893)
- Fixed `Phalcon\Translate\Adapter\Gettext::setLocale()` to call `setlocale` when it is available, removing warnings in PHP 8.5 [#16886](https://github.com/phalcon/cphalcon/issues/16886)

### Removed

## [5.11.0](https://github.com/phalcon/cphalcon/releases/tag/v5.11.0) (2026-04-03)

### Changed

- Changed `Phalcon\Filter\Sanitize\IP` to optimize the sanatization of IP address [#16838](https://github.com/phalcon/cphalcon/issues/16838)
- Changed `Phalcon\Encryption\Security\JWT\Builder::setPassphrase()` to require digits and special characters [#16847](https://github.com/phalcon/cphalcon/issues/16847)
- Changed `Phalcon\Encryption\Security\JWT\Builder::getAudience()` to return an empty array if not set [#16846](https://github.com/phalcon/cphalcon/issues/16846)
- Changed `Phalcon\Encryption\Security\Random::base()` to use 16 bits by default [#16845](https://github.com/phalcon/cphalcon/issues/16845)
- Changed `Phalcon\Logger\Logger` to use lowercase when reporting log levels (previously uppercase) [#16852](https://github.com/phalcon/cphalcon/issues/16852)
- Changed `Phalcon\Logger\Adapter\Stream` to use a more efficient way to write messages in the logger instead of opening and closing the stream per message [#16852](https://github.com/phalcon/cphalcon/issues/16852)
- Changed `Phalcon\Logger\Adapter\Syslog` to use the `Enum` instead of `Logger` constants [#16852](https://github.com/phalcon/cphalcon/issues/16852)
- Changed the whole testing suite to run on phpunit only [#16860](https://github.com/phalcon/cphalcon/issues/16860) [#16861](https://github.com/phalcon/cphalcon/issues/16861) [#16862](https://github.com/phalcon/cphalcon/issues/16862)

### Added

- Added PIE (PHP Installer for Extensions) support [#16832](https://github.com/phalcon/cphalcon/issues/16832)
- Added the ability to specify aliases for `Phalcon\Di\Di` services.[#13042](https://github.com/phalcon/cphalcon/issues/13042)
- Added `Phalcon\Encryption\Security\JWT\Validator::validateClaim()` to validate custom claims [#16843](https://github.com/phalcon/cphalcon/issues/16843)

### Fixed

- Fixed `Phalcon\Forms\Form::isValid()` to apply field filters even when no validators are specified [#16830](https://github.com/phalcon/cphalcon/issues/16830) [[doc]](https://docs.phalcon.io/5.12/forms/)
- Fixed `Phalcon\Http\Request` method `getClientAddress()` when using `trustForwardedHeader` [#16836](https://github.com/phalcon/cphalcon/issues/16836)
- Fixed `Phalcon\Acl\Adapter\Memory::isAllowed()` and `Phalcon\Mvc\Model\Binder` to handle PHP 8.1+ union and intersection types by checking for `ReflectionNamedType` before calling `getName()` [#16261](https://github.com/phalcon/cphalcon/issues/16261)
- Fixed memory leak in PHQL parser (phql_internal_parse_phql()) during repeated query execution. [#16854](https://github.com/phalcon/cphalcon/issues/16854)
- Fixed a deadlock issue when running the db suite [#16862](https://github.com/phalcon/cphalcon/issues/16862)
- Fixed `Phalcon\Storage\Adapter\Redis::clear()` and `Phalcon\Storage\Adapter\Stream::clear()` to only delete keys belonging to the current prefix instead of flushing the entire storage [#16806](https://github.com/phalcon/cphalcon/issues/16806)

### Removed

## [5.10.0](https://github.com/phalcon/cphalcon/releases/tag/v5.10.0) (2025-12-25)

### Changed

- Changed `bind()` and `validate()` method in `Phalcon\Filter\Validation` and `Phalcon\Filter\Validation\ValidationInterface` to accept `$whitelist` array of only allowed fields to be mutated when using entity [#16800](https://github.com/phalcon/cphalcon/issues/16800)
- Changed `Phalcon\Storage\Adapters\Libmemcached::getAdapter()` to use 50ms for `\Memcached::OPT_CONNECT_TIMEOUT` [#16818](https://github.com/phalcon/cphalcon/issues/16818)
- Changed `Phalcon\Html\Helper\Input\*` to honor `Docbloc` directives [#16778](https://github.com/phalcon/cphalcon/issues/16778)

### Added

- Added `fails()` method helper to `Phalcon\Filter\Validation` useful for standalone validation [#16798](https://github.com/phalcon/cphalcon/issues/16798)

### Fixed

- Fixed `Phalcon\Config\Adapter\Yaml` constructor to handle `null` return values from `yaml_parse_file()`, ensuring empty configuration files are treated as empty arrays instead of throwing errors.
- Fixed `Phalcon\Http\Request` method `getClientAddress(true)` to return correct IP address from trusted forwarded proxy. [#16777](https://github.com/phalcon/cphalcon/issues/16777)
- Fixed `Phalcon\Http\Request` method `getPost()` to correctly return json data as well and unified both `getPut()` and `getPatch()` to go through the same parsing method. [#16792](https://github.com/phalcon/cphalcon/issues/16792)
- Fixed `Phalcon\Filter\Validation` method `bind()` and `validate()` to correctly bind data when using entity as well as skip binding of fields not included in `$whitelist` [#16800](https://github.com/phalcon/cphalcon/issues/16800)
- Fixed `Phalcon\Http\Request` method `getPostData()` when `Content-Type` header is not set [#16804](https://github.com/phalcon/cphalcon/issues/16804)
- Fixed `Phalcon\Events\ManagerInterface` adding priority property [#16817](https://github.com/phalcon/cphalcon/issues/16817)
- Fixed `Phalcon\Storage\Adapters\Libmemcached::getAdapter()` to correctly merge adapter options [#16818](https://github.com/phalcon/cphalcon/issues/16818)
- Fixed `Phalcon\Encryption\Crypt` method `checkCipherHashIsAvailable(string $cipher, string $type)` to correctly check the `cipher` or `hash` type [#16822](https://github.com/phalcon/cphalcon/issues/16822)
- Fixed `Phalcon\Mvc\Model` docblocks [#16825](https://github.com/phalcon/cphalcon/issues/16825)

### Removed

## [5.9.3](https://github.com/phalcon/cphalcon/releases/tag/v5.9.3) (2025-04-19)

### Changed
- Added Multi-Stage Dockerfile and Github action for release Docker images to ghcr.io and Docker Hub. [#16752](https://github.com/phalcon/cphalcon/issues/16752)

### Added

- Added `Phalcon\Mvc\Router::setUriSource()` to allow URI processing from `$_GET['url']` or `$_SERVER['REQUEST_URI']` as it was in v3 [#16741](https://github.com/phalcon/cphalcon/issues/16741)

### Fixed

- Fixed `Phalcon\Mvc\Router` to correctly handle numeric URI parts as it was in v3 [#16741](https://github.com/phalcon/cphalcon/issues/16741)
- Fixed `Phalcon\Mvc\Model\Binder` to use ReflectionParameter::getType() instead of deprecated method, PHP 8.0 or higher issue. [#16742](https://github.com/phalcon/cphalcon/issues/16742)
- Fixed `Phalcon\Mvc\Model\Query` to check if cache entry exists. [#16747](https://github.com/phalcon/cphalcon/issues/16747)
- Fixed `Phalcon\Mvc\Router` to correctly match route when using query string URIs. [#16749](https://github.com/phalcon/cphalcon/issues/16749)
- Fixed `Phalcon\Mvc\Model::cloneResultset` to properly parse fields that do not accept `null` values [#16736](https://github.com/phalcon/cphalcon/issues/16736)

### Removed

## [5.9.2](https://github.com/phalcon/cphalcon/releases/tag/v5.9.2) (2025-04-03)

### Changed

### Added

### Fixed

- Fixed `Phalcon\Translate\Adapter\Csv` the `escape` argument is explicitly required in PHP 8.4  [#16733](https://github.com/phalcon/cphalcon/issues/16733)
- Fixed `Phalcon\Mvc\Model\Query` to use the cacheOptions lifetime over the "cache" service lifetime

### Removed

## [5.9.1](https://github.com/phalcon/cphalcon/releases/tag/v5.9.1) (2025-03-31)

### Changed

- Changed `Phalcon\Storage\Adapter\AbstractAdapter` and dropped `has()` check before receiving the value. [#16705](https://github.com/phalcon/cphalcon/issues/16705)

### Added

- Added `Phalcon\Html\Helper\Breadcrumbs` component to replace the old `Phalcon\Html\Breadcrumbs` component. [#16727](https://github.com/phalcon/cphalcon/issues/16727) [[doc]](https://docs.phalcon.io/5.12/html-breadcrumbs/)

### Fixed

- Fixed `Phalcon\Mvc\Micro\LazyLoader::callMethod` to prevent `Unknown named parameter` error [#16724](https://github.com/phalcon/cphalcon/issues/16724)

### Removed

## [5.9.0](https://github.com/phalcon/cphalcon/releases/tag/v5.9.0) (2025-03-08)

### Changed

- Changed `Phalcon\Filter\Validation\Validator\Email` to allow UTF8 in local part. [#16637](https://github.com/phalcon/cphalcon/issues/16637)
- Changed `Phalcon\Cache\Cache::getMultiple()` to use `mget()` when the `Phalcon\Cache\Adapter\Redis` is used. [#16689](https://github.com/phalcon/cphalcon/issues/16689)
- Changed `Storage\Adapter\Redis` to accept `ssl` in the options for secure connections. [#16711](https://github.com/phalcon/cphalcon/issues/16711)

### Added
- Added `dispatch:beforeCallAction` and `dispatch:afterCallAction` to last-minute modifications to handler and method (mostly for debugging).

### Fixed

- Fixed `Phalcon\Forms\Form` and `Phalcon\Filter\Validation` to correctly handle the `validate()` response when using validation class `beforeValidate()` [#16702](https://github.com/phalcon/cphalcon/issues/16702)
- Fixed `Phalcon\Support\Debug` to use correct passed arguments in `set_error_handler` callback. PHP v7.2.0 deprecated `errcontext` and has been removed since php v8.0.0 [#16649](https://github.com/phalcon/cphalcon/issues/16686)
- Fixed `Phalcon\Http\Response\Cookies`, `Phalcon\Http\Response\CookiesInterface` and `Phalcon\Http\Cookie` to use correct cookie default arguments, avoid deprecated null assign warning when trying to assign the same cookie twice [#16649](https://github.com/phalcon/cphalcon/issues/16649)
- Fixed `Phalcon\Encryption\Crypt` to use `strlen` instead of `mb_strlen` for padding calculations [#16642](https://github.com/phalcon/cphalcon/issues/16642)
- Fixed `Phalcon\Filter\Validation\Validator\File\MimeType::validate` to close the handle when using `finfo` [#16647](https://github.com/phalcon/cphalcon/issues/16647)
- Fixed `Phalcon\Mvc\Model\Manager::getRelationRecords` to explicitly set the `referencedModel` in the conditions along with the `referencedFields` [#16655](https://github.com/phalcon/cphalcon/pull/16655)
- Fixed `Phalcon\Image\Adapters\AbstractAdapter::watermark` to correctly calculate the Y offset [#16658](https://github.com/phalcon/cphalcon/issues/16658)
- Fixed `Phalcon\Dispatcher\AbstractDispatcher` when calling action methods that do not define parameters to prevent `Unknown named parameter` error.
- Fixed `Phalcon\Di\Injectable` to reference the correct instance of `Phalcon\Di\Di` in the docblock property [#16634](https://github.com/phalcon/cphalcon/issues/16634)
- Fixed `Phalcon\Filter\Filter` to have the correct docblock for IDE completion
- Fixed `Phalcon\Mvc\Model\Query` to use the lifetime in the "cache" service if none has been supplied by the options [#16696](https://github.com/phalcon/cphalcon/issues/16696)
- Fixed `Phalcon\Session\Adapter\Stream::gc()` to throw an exception if something is wrong with `glob()` [#16713](https://github.com/phalcon/cphalcon/issues/16713)
- Fixed `Phalcon\Http\Request::getBasicAuth()` to return a `null` password if not defined on the server [#16668](https://github.com/phalcon/cphalcon/issues/16668)

### Removed

## [5.8.0](https://github.com/phalcon/cphalcon/releases/tag/v5.8.0) (2024-07-09)

### Changed

### Added

### Fixed

- Fixed `Phalcon\Di\Injectable` to reference the correct instance of `Phalcon\Di\Di` in the docblock property [#16634](https://github.com/phalcon/cphalcon/issues/16634)

### Removed

## [5.8.0](https://github.com/phalcon/cphalcon/releases/tag/v5.8.0) (2024-07-09)

### Changed

- Changed `Phalcon\Mvc\Model`, `Phalcon\Support\Collection` and `Phalcon\Support\Registry` to correctly implement   `\Serializable` interface. [#16591](https://github.com/phalcon/cphalcon/issues/16591)
- Changed the `Phalcon\Mvc\Router\Group::getHostname()` to return `null` also. [#16601](https://github.com/phalcon/cphalcon/issues/16601)
- Changed `Phalcon\Mvc\View\Engine\Volt\Compiler::compileSource` to also return `array` [#16608](https://github.com/phalcon/cphalcon/issues/16608)

### Added

- Added events and `Phalcon\Events\Manager` for `Phalcon\Storage\Adapter\Apcu`,
  `Phalcon\Storage\Adapter\Redis`,
  `Phalcon\Storage\Adapter\Memory`,
  `Phalcon\Storage\Adapter\Libmemcached`, [[doc]](https://docs.phalcon.io/5.12/storage/)
  `Phalcon\Storage\Adapter\Stream`,
  `Phalcon\Storage\Adapter\Weak`,
  `Phalcon\Cache\Adapter\Apcu`,
  `Phalcon\Cache\Adapter\Redis`,
  `Phalcon\Cache\Adapter\Memory`,
  `Phalcon\Cache\Adapter\Libmemcached`,
  `Phalcon\Cache\Adapter\Stream`,
  `Phalcon\Cache\Adapter\Weak`
  `Phalcon\Cache\AbstractCache`. [#16606](https://github.com/phalcon/cphalcon/issues/16606)

### Fixed

- Fixed `Phalcon\Support\Helper\PascalCase` causing memory leak by anonymous function [#16593](https://github.com/phalcon/cphalcon/issues/16593)
- Fixed `Phalcon\Mvc\Model\Query` to rollback failed transactions and re-throw exception for data consistency [#16604](https://github.com/phalcon/cphalcon/issues/16604)

### Removed

## [5.7.0](https://github.com/phalcon/cphalcon/releases/tag/v5.7.0) (2024-05-17)

### Changed

- Changed `Phalcon\Support\HelperFactory` to use the internal mapper for better memory management [#16571](https://github.com/phalcon/cphalcon/issues/16571)

### Added

- New ini setting `phalcon.form.strict_entity_property_check` for `Phalcon\Forms\Form` to enable strict entity property checking. [#16567](https://github.com/phalcon/cphalcon/issues/16567)

### Fixed

- Fixed `Phalcon\Mvc\Cli\Router` to extend the `Phalcon\Mvc\Cli\RouterInterface` [#16551](https://github.com/phalcon/cphalcon/issues/16551)
- Fixed `Phalcon\Filter\Validation\Validator\StringLength::validate()` to correctly use the `include` parameter [#16560](https://github.com/phalcon/cphalcon/issues/16560)
- Fixed `Phalcon\Db\Column::TYPE_BINARY` and `Phalcon\Db\Column::TYPE_TINYINTEGER` to have unique values [#16532](https://github.com/phalcon/cphalcon/issues/16532)
- Fixed `Phalcon\Forms\Form` to bind only existing properties on entities, based on `phalcon.form.strict_entity_property_check` setting. [#16567](https://github.com/phalcon/cphalcon/issues/16567)
- Fixed `Phalcon\Filter\Sanitize\BoolVal` to correctly handle integers. [#16582](https://github.com/phalcon/cphalcon/issues/16582)

### Removed

## [5.6.2](https://github.com/phalcon/cphalcon/releases/tag/v5.6.1) (2024-03-14)

### Changed

- Changed `Phalcon\Mvc\View\Engine\Volt\Compiler::filter` to use the helper with `upper` and `lower` for UTF-8 characters [#16543](https://github.com/phalcon/cphalcon/issues/16543)
- Changed `Phalcon\Di\AbstractInjectionAware` to extend `stdClass` for PHP 8.2 deprecation warnings [#16543](https://github.com/phalcon/cphalcon/issues/16543)

### Added

### Fixed

### Removed

## [5.6.1](https://github.com/phalcon/cphalcon/releases/tag/v5.6.1) (2024-02-08)

### Changed

- Changed `Phalcon\Cli\Router::setDefaultAction` and `Phalcon\Cli\Router::setDefaultModule` to return the object back for a fluent interface [#16328](https://github.com/phalcon/cphalcon/issues/16328)

### Added

### Fixed

- Fixed `Phalcon\Db\Adapter\Pdo\Postgresql::describeColumns()` to return the correct string back [#16371](https://github.com/phalcon/cphalcon/issues/16371)
- Fixed `Phalcon/Filter/Validation::validate()` and `Phalcon/Filter/Validation/ValidationInterface::validate()` to return also `bool` [#16337](https://github.com/phalcon/cphalcon/issues/16337)
- Fixed `Phalcon\Mvc\Model::toArray` to ignore getters when the field name is `source`. [#16514](https://github.com/phalcon/cphalcon/issues/16514)
- Fixed `Phalcon\Http\Request::getPut` to correctly get form encoded data [#16519](https://github.com/phalcon/cphalcon/issues/16519)
- Fixed deprecation warning in callables `Use of "static" in callables is deprecated` for PHP 8.2+ [#16263](https://github.com/phalcon/cphalcon/issues/16263)

### Removed

## [5.6.0](https://github.com/phalcon/cphalcon/releases/tag/v5.6.0) (2024-01-09)

### Changed

- Changed `Phalcon\Db\Adapter\Pdo\Mysql` to not use specific flags for `PDO` (`PDO::ATTR_EMULATE_PREPARES` or `PDO::ATTR_STRINGIFY_FETCHES`) for performance reasons [#16474](https://github.com/phalcon/cphalcon/issues/16474)
- Merged `Phalcon\Db\AbstractDb` with `Phalcon\Db\Adapter\AbstractAdapter` since the former was not used [#16474](https://github.com/phalcon/cphalcon/issues/16474)

### Added

- Added `resetColumns()`, `resetFrom()`, `resetWhere()`, `resetGroupBy()`, `resetHaving()`, `resetOrderBy()`, `resetLimit()`, `resetFlags()` to the `Phalcon\Datamapper\Query\AbstractQuery` to allow resetting query filters.

### Fixed

- Fixed `Phalcon\Mvc\Model::count` to ignore the `order` parameter (needed for Posgresql) [#16471](https://github.com/phalcon/cphalcon/issues/16471)
- Fixed `Phalcon\Mvc\Model::toArray` added parameter to ignore getters in order not to break serialize. [#16490](https://github.com/phalcon/cphalcon/issues/16490)
- Fixed `Phalcon\Mvc\Model::toArray` changing the conditionals for population to remove segfault. [#16498](https://github.com/phalcon/cphalcon/issues/16498)

### Removed

## [5.5.0](https://github.com/phalcon/cphalcon/releases/tag/v5.5.0) (2023-12-25)

### Changed

- Shifted minimal support from PHP 7.4 to PHP 8.0 [#16477](https://github.com/phalcon/cphalcon/issues/16477)
- Changed `Phalcon\Mvc\Model::toArray` to use getters if present [#16320](https://github.com/phalcon/cphalcon/issues/16320)
- Adjusted return types identical to original interface `int|false` in `Phalcon\Session\Adapter\*::gc()` [#16477](https://github.com/phalcon/cphalcon/issues/16477)
- Changed return type of `Phalcon\Config\Adapter\Ini::cast()` to `mixed` [#16477](https://github.com/phalcon/cphalcon/issues/16477)

### Added

- Added support for PHP 8.3 [#16477](https://github.com/phalcon/cphalcon/issues/16477)

### Fixed

- Fixed `Phalcon\Filter\Validation\Validator\Numericality` to return false when input has spaces [#16461](https://github.com/phalcon/cphalcon/issues/16461)
- Fixed `Phalcon\Mvc\Model\ResultsetSimple::toArray` to ignore numeric indexes in case results come as not `fetch_assoc` [#16467](https://github.com/phalcon/cphalcon/issues/16467)

### Removed

## [5.4.0](https://github.com/phalcon/cphalcon/releases/tag/v5.4.0) (2023-10-25)

### Changed

- Changed `Phalcon\Mvc\Model::getMessages()` to also filter with an array of fields [#16265](https://github.com/phalcon/cphalcon/issues/16265)
- Changed `Phalcon\DataMapper\Query\Select::columns()` to accept an array of columns (keys as aliases) instead of `func_get_args` [#16451](https://github.com/phalcon/cphalcon/issues/16451)
- Changed `Phalcon\Html\Helper\AbstractSeries::__invoke()` to no longer clear the internal store when called [#16441](https://github.com/phalcon/cphalcon/issues/16441)

### Added

- Added the ability to define interpolator characters for the `Phalcon\Logger\Formatter\Line` [#16430](https://github.com/phalcon/cphalcon/issues/16430)
- Added `Phalcon\Html\Helper\AbstractSeries::reset()` to clear the internal store when needed [#16441](https://github.com/phalcon/cphalcon/issues/16441)

### Fixed

- Model Annotation strategy did not work with empty_string [#16426](https://github.com/phalcon/cphalcon/issues/16426)
- View::reset() sets content to null instead of default empty string [#16437](https://github.com/phalcon/cphalcon/issues/16437)
- Fixed `Phalcon\Filter\Validation\Validator\Size\*` validators to correctly detect the size of uploaded files [#16390](https://github.com/phalcon/cphalcon/issues/16390)

### Removed

## [5.3.1](https://github.com/phalcon/cphalcon/releases/tag/v5.3.1) (2023-09-12)

### Fixed

- Fixed infinite save loop in `Phalcon\Mvc\Model::save()` [#16395](https://github.com/phalcon/cphalcon/issues/16395)
- Fixed undefined column with columnMap and model caching [#16420](https://github.com/phalcon/cphalcon/issues/16420)
- Fixed memory leak in `Phalcon\Mvc\Router::handle()` [#16431](https://github.com/phalcon/cphalcon/pull/16431)

## [5.3.0](https://github.com/phalcon/cphalcon/releases/tag/v5.3.0) (2023-08-15)

### Changed

- Refactored `Phalcon\Mvc\Model::doLowUpdate` and `Phalcon\Mvc\Model::postSaveRelatedRecords` for better code logic and a clearer separation of behavior, although it lead to partially repeated code. [#16391](https://github.com/phalcon/cphalcon/issues/16391)
- Cleaned `Phalcon\Mvc\Model\Metadata::initialize` [#16393](https://github.com/phalcon/cphalcon/issues/16393)

### Added

- Added `Phalcon\Mvc\Model::appendMessagedFrom` for code consistency and to add messages from another model [#16391](https://github.com/phalcon/cphalcon/issues/16391)
- Added `Phalcon\Autoload\Loader::isRegistered` for debugging purposes [#16391](https://github.com/phalcon/cphalcon/issues/16391)
- Added `Phalcon\Mvc\Model\Metadata::initializeMetadata` [#16393](https://github.com/phalcon/cphalcon/issues/16393)
- Added `Phalcon\Mvc\Model\Metadata::getMetaDataUniqueKey` [#16393](https://github.com/phalcon/cphalcon/issues/16393)
- Added `Phalcon\Mvc\Model\Metadata::getColumnMapUniqueKey` [#16393](https://github.com/phalcon/cphalcon/issues/16393)
- Added `Phalcon\Encryption\Security\JWT\Builder::addHeader()` to allow adding custom headers [#16396](https://github.com/phalcon/cphalcon/issues/16396)

### Fixed

- Parse multipart/form-data from PUT request [#16271](https://github.com/phalcon/cphalcon/issues/16271)
- Set Dynamic Update by default system-wide [#16343](https://github.com/phalcon/cphalcon/issues/16343)
- Fixed memory leak in Micro application [#16404](https://github.com/phalcon/cphalcon/pull/16404)


## [5.3.1](https://github.com/phalcon/cphalcon/releases/tag/v5.3.1) (xxxx-xx-xx)

### Fixed

- Forced `routeId` in `Phalcon\Mvc\Router\Route` to always return a string [#16414](https://github.com/phalcon/cphalcon/pull/16414)


## [5.2.3](https://github.com/phalcon/cphalcon/releases/tag/v5.2.3) (2023-07-26)

### Added

- Added `getAdapter()` in `Phalcon\Mvc\Model\Metadata` to retrieve the internal cache adapter if necessary. [#16244](https://github.com/phalcon/cphalcon/issues/16244)
- Added `Phalcon\Storage\Adapter\Weak` implemented with WeakReference has a cache/retrieval solution for objects not yet collected by the Garbage Collection. [#16372](https://github.com/phalcon/cphalcon/issues/16372)

### Fixed

- Tried to reproduce the behavior described in #16244 but had no success. [#16244](https://github.com/phalcon/cphalcon/issues/16244)
- Extended `Phalcon\Di\Injectable` from `stdClass` to remove the deprecation warning (dynamic properties) for PHP 8.2 [#16308](https://github.com/phalcon/cphalcon/issues/16308)
- Corrected the return type of `Phalcon\Mvc\View::getVar()` so that stubs can be accurate. [#16276](https://github.com/phalcon/cphalcon/issues/16276)
- Changed all the `encode`/`decode` methods for JSON to use the `Phalcon\Support\Helper\Json\*` classes. [#15608](https://github.com/phalcon/cphalcon/issues/15608)
- Changed the `Phalcon\Support\Helper\Json\*` classes to clear up `json_last_error()` before doing any conversions. [#15608](https://github.com/phalcon/cphalcon/issues/15608)
- Fixed `Phalcon\Http\Request::getJsonRawBody` to protect from empty body [#16373](https://github.com/phalcon/cphalcon/issues/16373)

## [5.2.2](https://github.com/phalcon/cphalcon/releases/tag/v5.2.2) (2023-06-18)

### Fixed

- Fixed `Encryption\Crypt::checkCipherHashIsAvailable` to allow proper setting of the hash [#16314](https://github.com/phalcon/cphalcon/issues/16314)
- Removed `unlikely` from `if` statements from the Stream storage adapter and Json serializer [#16339](https://github.com/phalcon/cphalcon/issues/16339)
- Fixed `Storage\Adapter\Stream::get()/set()` to correctly calculate the path if the prefix is present in the key [#16348](https://github.com/phalcon/cphalcon/issues/16348)
- Fixed `Html\Helper\Input\Checkbox` to correctly process empty values [#15959](https://github.com/phalcon/cphalcon/issues/15959)

## [5.2.1](https://github.com/phalcon/cphalcon/releases/tag/v5.2.1) (2023-02-28)

### Fixed

- Fixed compilation under PHP 8.2 [#16293](https://github.com/phalcon/cphalcon/issues/16293), [#16295](https://github.com/phalcon/cphalcon/issues/16295)

## [5.2.0](https://github.com/phalcon/cphalcon/releases/tag/v5.2.0) (2023-02-26)

### Added

- Added support for PHP 8.2 [#15973](https://github.com/phalcon/cphalcon/issues/15973)

### Fixed

- Fixed `Phalcon\Html\Helper\Title::prepend` to correctly prepend text in subsequent calls [#16283](https://github.com/phalcon/cphalcon/issues/16283)

## [5.1.4](https://github.com/phalcon/cphalcon/releases/tag/v5.1.4) (2023-01-10)

### Fixed

- Fixed `Phalcon\Acl\Adapter\Memory::isAllowed` to not use the deprecated `ReflectionType::getClass` [#16255](https://github.com/phalcon/cphalcon/issues/16255)

## [5.1.3](https://github.com/phalcon/cphalcon/releases/tag/v5.1.3) (2022-12-25)

### Fixed

- Fixed `Phalcon\Mvc\Micro::handle` to type check an object for the `finish` [#16240](https://github.com/phalcon/cphalcon/issues/16240)
- Fixed `Phalcon\DI\Service::resolve` to not call the `get()` from the container and cause an infinite loop [#15032](https://github.com/phalcon/cphalcon/issues/15032)

## [5.1.2](https://github.com/phalcon/cphalcon/releases/tag/v5.1.2) (2022-10-30)

### Fixed

- Fixed `Phalcon\Support\Debug` to correctly calculate the documents URL for the hyperlinks [#16223](https://github.com/phalcon/cphalcon/issues/16223)
- Fixed `Phalcon\Html\TagFactory` docblock for autocompletion (https://github.com/phalcon/cphalcon/commit/0129658f3ac468dcc5294d401403e166302a8069)
- Fixed `Phalcon\Db\Profiler` by correctly calculating the seconds (reapplied changes) [#15822](https://github.com/phalcon/cphalcon/issues/15822)
- Added `Phalcon\Html\TagFactory` to the `Phalcon\Di\FactoryDefault\Cli` [#16233](https://github.com/phalcon/cphalcon/issues/16233)

## [5.1.1](https://github.com/phalcon/cphalcon/releases/tag/v5.1.1) (2022-11-12)

### Fixed

- Fixed `Phalcon\Filter::sanitize` to return correct data when `noRecursive` is `true` [#16199](https://github.com/phalcon/cphalcon/issues/16199)
- Fixed `Phalcon\Html\Escaper::html` to not return `null` when a zero string is passed [#16202](https://github.com/phalcon/cphalcon/issues/16202)

## [5.1.0](https://github.com/phalcon/cphalcon/releases/tag/v5.1.0) (2022-11-01)

### Added

- Added `Phalcon\Http\Request::getPatch()` to get a value from a PATCH request [#16188](https://github.com/phalcon/cphalcon/issues/16188)
- Added `Phalcon\Http\Request::getFilteredPatch()` to get a value filtered from a PATCH request [#16188](https://github.com/phalcon/cphalcon/issues/16188)
- Added `Phalcon\Http\Request::hasPatch()` to check if a value exist in a PATCH request [#16188](https://github.com/phalcon/cphalcon/issues/16188)

### Fixed

- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler::isTagFactory` to correctly detect a `TagFactory` object without throwing an error [#16097](https://github.com/phalcon/cphalcon/issues/16097)
- Fixed default values for `Phalcon\Cli`, `Phalcon\Dispatcher` and `Phalcon\Application` components to ensure not `null` values are passed to methods [#16186](https://github.com/phalcon/cphalcon/issues/16186)
- Fixed `Phalcon\Form::clear` to correctly clear the elements and not recurse [#15956](https://github.com/phalcon/cphalcon/issues/15956)

## [5.0.5](https://github.com/phalcon/cphalcon/releases/tag/v5.0.5) (2022-10-24)

### Fixed

- Fixed `Phalcon\Config\Config::setData` to pass the `insensitive` flag to child objects [#16171](https://github.com/phalcon/cphalcon/issues/16171)
- Fixed `Phalcon\Config\Adapter\Groupped::__construct` to pass the `insensitive` flag to child objects [#16171](https://github.com/phalcon/cphalcon/issues/16171)
- Fixed `Phalcon\Session\Manager::setName`, removing the regex check for the name for custom adapters to work with `create_sid()` [#16170](https://github.com/phalcon/cphalcon/issues/16170)
- Fixed `PdoResult::fetchAll` when passed class name in 2nd argument [#16177](https://github.com/phalcon/cphalcon/issues/16177)
- Fixed `Forms\Form::label` to accept an array as a default variable [#16180](https://github.com/phalcon/cphalcon/issues/16180)

## [5.0.4](https://github.com/phalcon/cphalcon/releases/tag/v5.0.4) (2022-10-17)

### Fixed

- Fixed `Phalcon\Encryption\Security` to take into account the `workFactor` in the cost calculation [#16153](https://github.com/phalcon/cphalcon/issues/16153)
- Removed double unserializing during Model caching [#16035](https://github.com/phalcon/cphalcon/issues/16035), [#16131](https://github.com/phalcon/cphalcon/issues/16131)
- Fixed `Phalcon\Db\Adapter\Pdo\Mysql::describeIndexes` to assign an empty string in the index type of `null` and remove warnings [#16157](https://github.com/phalcon/cphalcon/issues/16157)
- Fixed `Phalcon\Db\Adapter\Pdo\Sqlite::describeIndexes` to assign an empty string in the index type of `null` and remove warnings [#16157](https://github.com/phalcon/cphalcon/issues/16157)
- Fixed `Phalcon\Mvc\Model\Manager::notifyEvent` to return `true` instead of `null` on success [#16161](https://github.com/phalcon/cphalcon/issues/16161)
- Fixed `Phalcon\Encryption\Security\JWT\Validator::validateExpiration` to correctly validate the `exp` claim [#16166](https://github.com/phalcon/cphalcon/issues/16166)

## [5.0.3](https://github.com/phalcon/cphalcon/releases/tag/v5.0.3) (2022-10-06)

### Changed

- Fixed `Phalcon\Filter\Sanitize\StringVal` to accept flags for `htmlspecialchars()` [#16135](https://github.com/phalcon/cphalcon/issues/16135)

### Fixed

- Fixed `Phalcon\Html\Escaper::attributes()` to honor the `$flags` set for `htmlspecialchars()` [#16134](https://github.com/phalcon/cphalcon/issues/16134)

## [5.0.2](https://github.com/phalcon/cphalcon/releases/tag/v5.0.2) (2022-09-27)

### Fixed

- Fixed `Phalcon\Html\Escaper::attributes()` to accept any value and transform it to string [#16123](https://github.com/phalcon/cphalcon/issues/16123)
- Fixed `Phalcon\Logger\AbstractLogger::getLevelNumber()` to better check for string levels [#16123](https://github.com/phalcon/cphalcon/issues/16123)

# [5.0.1](https://github.com/phalcon/cphalcon/releases/tag/v5.0.1) (2022-09-23)

### Added

- Added `Phalcon\Encryption\Security\JWT\Validator::get()` and `Phalcon\Encryption\Security\JWT\Validator::set()` for validation data [#16115](https://github.com/phalcon/cphalcon/issues/16115)

### Fixed

- Fixed `Phalcon\Encryption\Security\JWT\Token\Token::validate()` to correctly call validator methods [#16115](https://github.com/phalcon/cphalcon/issues/16115)

## [5.0.0](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0) (2022-09-22)

### Changed

- Changed `Phalcon\Logger\Adapter\Stream::process` to open the log file, check for locks, write contents and close the stream [#16072](https://github.com/phalcon/cphalcon/issues/16072)
- Changed getters and setters from shorthand format to full methods [#16102](https://github.com/phalcon/cphalcon/issues/16102)
- Changed return types to `array` in `Phalcon\Annotations\Reflection` class methods [#16106](https://github.com/phalcon/cphalcon/issues/16106)
- Changed `Phalcon\Html\Escaper::attributes()` to also accept an array of attributes [#16108](https://github.com/phalcon/cphalcon/issues/16108)

### Added

- Added `Phalcon\Encryption\Security\JWT\Token::validate()` to validate a token's claims [#16094](https://github.com/phalcon/cphalcon/issues/16094)
- Added `Phalcon\Encryption\Security\JWT\Token::verify()` to verify a token's signature [#16094](https://github.com/phalcon/cphalcon/issues/16094)
- Added `Phalcon\Encryption\Security\JWT\Validator::getErrors()` to return any errors with the validation as an array [#16094](https://github.com/phalcon/cphalcon/issues/16094)

### Fixed

- Fixed and improved return type of `object` & `?object` [#16023](https://github.com/phalcon/cphalcon/issues/16023)
- Fixed `Phalcon\Filter\Validation\Validator\Digit` to use only strings for `ctype_*` calls [#16064](https://github.com/phalcon/cphalcon/issues/16064)
- Fixed `Phalcon\Flash\AbstractFlash::outputMessage` to return the message (implicitFlush) [#16063](https://github.com/phalcon/cphalcon/issues/16063)
- Fixed `Phalcon\Filter\Validation\Validator\Numericality` to correctly detect illegal characters within string numbers [#16070](https://github.com/phalcon/cphalcon/issues/16070)
- Fixed segmentation fault on Reflection of `Phalcon\Mvc\Model` class [#16080](https://github.com/phalcon/cphalcon/issues/16080)
- Fixed segmentation fault on Reflection [#16096](https://github.com/phalcon/cphalcon/issues/16096)

## [5.0.0rc4](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0RC4) (2022-08-08)

### Fixed

- Reverted to single quotes when volt code generates PHP code.
- Any `tag` helpers only accept parameters with double quotes
- Renamed `Phalcon\Tag::form()` to `Phalcon\Tag::formLegacy` (helper `form_legacy`) [#16019](https://github.com/phalcon/cphalcon/issues/16019)
- Fixed
    - `Phalcon\Cli\Router::getMatchedRoute()`
    - `Phalcon\Cli\RouterInterface::getMatchedRoute()`
    - `Phalcon\Mvc\Router::getMatchedRoute()`
    - `Phalcon\Mvc\RouterInterface::getMatchedRoute()` to return `RouterInterface` or `null` [#16030](https://github.com/phalcon/cphalcon/issues/16030)
- Fixed
    - `Phalcon/Storage/Serializer/Base64::unserialize()`
    - `Phalcon/Storage/Serializer/Igbinary::unserialize()`
    - `Phalcon/Storage/Serializer/Igbinary::serialize()`
    - `Phalcon/Storage/Serializer/Php::unserialize()` to reset isSuccess value [#16040](https://github.com/phalcon/cphalcon/issues/16040)
- Fixed `Phalcon\Paginator\Adapter\Model::paginate()` fix group parameter breaking total items [#16042](https://github.com/phalcon/cphalcon/issues/16042)
- Fixed `Phalcon\Mvc\Model::doLowUpdate()` prevent RawValue getting overwritten [#16037](https://github.com/phalcon/cphalcon/issues/16037)
- Refactored `Phalcon\Image\*`
    - Reorganized code in the image adapters
    - Simplified various areas, speeding up processing
    - Removed `getInternalImImage()` (same as `getImage()`) for `Phalcon\Image\Adapter\Imagick`
    - Added better support for webm images [#15977](https://github.com/phalcon/cphalcon/issues/15977)

## [5.0.0rc3](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0RC3) (2022-07-12)

### Added

- Added support for `webp` images for `Phalcon\Image\Adapter\Gd` [#15977](https://github.com/phalcon/cphalcon/issues/15977)
- Added `Phalcon\Mvc\Model\ManagerInterface::getBuilder()` to return the existing builder (created by `createBuilder()`) [#15966](https://github.com/phalcon/cphalcon/issues/15966)
- Added `Phalcon\Mvc\Model\Manager::getBuilder()` to return the existing builder (created by `createBuilder()`) [#15966](https://github.com/phalcon/cphalcon/issues/15966)

### Fixed

- Fixed `Phalcon\Tag::textArea()` to check if the value is `null` before calling `htmlspecialchars` [#15992](https://github.com/phalcon/cphalcon/issues/15992)
- Fixed
    - `Phalcon/Filter/Validation/Validator/Alnum`
    - `Phalcon/Filter/Validation/Validator/Alpha`
    - `Phalcon/Filter/Validation/Validator/Confirmation`
    - `Phalcon/Filter/Validation/Validator/CreditCard`
    - `Phalcon/Filter/Validation/Validator/StringLength/Max`
    - `Phalcon/Filter/Validation/Validator/StringLength/Min` to check if the value is `null` before calling internal PHP methods [#15992](https://github.com/phalcon/cphalcon/issues/15992)
- Fixed `Phalcon\Html\Helper\Title` to properly use indent and delimiter [#15984](https://github.com/phalcon/cphalcon/issues/15984)
- Fixed `Phalcon\Html\Helper\Doctype` to properly use indent and delimiter [#15984](https://github.com/phalcon/cphalcon/issues/15984)
- Fixed `Phalcon\Mvc\View\Engine\Volt::isIncluded()` and `Phalcon\Mvc\View\Engine\Volt::length()` to check for null values before calls to php methods [#15984](https://github.com/phalcon/cphalcon/issues/15984)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler::expression()` to use double quotes instead of single ones [#15984](https://github.com/phalcon/cphalcon/issues/15984)
- Fixed `Phalcon\Support\Version::getPart()` to always return string values [#15984](https://github.com/phalcon/cphalcon/issues/15984)
- Fixed `Phalcon\Dispatcher\DispatcherInterface::setModuleName()` to accept `null` [#15997](https://github.com/phalcon/cphalcon/issues/15997)
- Fixed `Phalcon\Dispatcher\AbstractDispatcher::setModuleName()` to accept `null` [#15997](https://github.com/phalcon/cphalcon/issues/15997)
- Fixed `Phalcon\Dispatcher\AbstractDispatcher::getModuleName()` to also return `null` [#15997](https://github.com/phalcon/cphalcon/issues/15997)

## [5.0.0rc2](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0RC2) (2022-06-09)

### Changed

- Changed the `StringVal` filter to now use `htmlspecialchars()` [#15978](https://github.com/phalcon/cphalcon/issues/15978)

### Added

- Added `StringValLegacy` filter using `filter_var()` for PHP < 8.1 [#15978](https://github.com/phalcon/cphalcon/issues/15978)

### Fixed

- Fixed `Phalcon\Http\Response::getQualityHeader()` to check if the server variable is `null` before performing `preg_split` [#15984](https://github.com/phalcon/cphalcon/issues/15984)

## [5.0.0rc1](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0RC1) (2022-05-31)

### Changed

- Changed `Phalcon\Session\Bag::__construct()` to accept a `Phalcon\Session\Manager` as the first parameter and `name` as the second one [#15904](https://github.com/phalcon/cphalcon/issues/15904)
- Changed `Phalcon\Logger\Logger` to no longer depend on PSR interfaces [#15925](https://github.com/phalcon/cphalcon/issues/15925)
- Changed `Phalcon\Cache\Cache` to no longer depend on PSR interfaces [#15927](https://github.com/phalcon/cphalcon/issues/15927)
- Changed `Phalcon\Html\Link` to no longer depend on PSR interfaces [#15930](https://github.com/phalcon/cphalcon/issues/15930)

### Added

- Added `Phalcon\Encryption\Crypt::isValidDecryptLength($input)` to allow checking for the length of the decryption string [#15879](https://github.com/phalcon/cphalcon/issues/15879)
- Added `Phalcon\Di\InitializationAwareInterface` to allow auto calling the `initialize` method when accessing service through DIC [#15916](https://github.com/phalcon/cphalcon/pull/15916)
- Added
    - `Phalcon\Storage\Serializer\MemcachedIgbinary`
    - `Phalcon\Storage\Serializer\MemcachedJson`
    - `Phalcon\Storage\Serializer\MemcachedPhp`
    - `Phalcon\Storage\Serializer\RedisIgbinary`
    - `Phalcon\Storage\Serializer\RedisJson`
    - `Phalcon\Storage\Serializer\RedisMsgpack`
    - `Phalcon\Storage\Serializer\RedisNone`
    - `Phalcon\Storage\Serializer\RedisPhp` to be used if adapter serialization is required [#15904](https://github.com/phalcon/cphalcon/issues/15904)
- Added
    - `Phalcon\Logger\LoggerInterface`
    - `Phalcon\Logger\AbstractLogger` to be used in the logger class but also the proxy-psr3 repo [#15925](https://github.com/phalcon/cphalcon/issues/15925)
- Added
    - `Phalcon\Cache\CacheInterface`
    - `Phalcon\Cache\AbstractCache` to be used in the cache class but also the proxy-psr16 repo [#15927](https://github.com/phalcon/cphalcon/issues/15927)
- Added
    - `Phalcon\Html\Link\Interfaces\EvolvableLinkInterface`
    - `Phalcon\Html\Link\Interfaces\EvolvableLinkProviderInterface`
    - `Phalcon\Html\Link\Interfaces\LinkInterface`
    - `Phalcon\Html\Link\Interfaces\LinkProviderInterface`
    - `Phalcon\Html\Link\AbstractLink`
    - `Phalcon\Html\Link\AbstractLinkProvider` to be used in the link class but also the proxy-psr13 repo [#15930](https://github.com/phalcon/cphalcon/issues/15930)
- Added `Phalcon\Translate\Adapter\Csv::toArray()` and `Phalcon\Translate\Adapter\NativeArray::toArray()` to return the translation array back  [#15902](https://github.com/phalcon/cphalcon/issues/15902)

### Fixed

- Fixed `Phalcon\Html\Helper\Input\Numeric` to produce correct elements [#15896](https://github.com/phalcon/cphalcon/issues/15896)
- Fixed `Phalcon\Storage\Adapter\*` to correctly store `null` values [#15904](https://github.com/phalcon/cphalcon/issues/15904)

### Removed

- Removed `Phalcon\Container\Container` and moved its contents to the `proxy-psr11` repo [#15928](https://github.com/phalcon/cphalcon/issues/15928)
- Removed `Phalcon\Http\Message\*` and `Phalcon\Http\Server\*` classes. This removes PSR from Phalcon. PSR-7 available in v6 [#15929](https://github.com/phalcon/cphalcon/issues/15929)

## [5.0.0beta3](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0beta3) (2022-02-06)

### Changed

- Renamed `Phalcon\Db\Result\Pdo` to `Phalcon\Db\Result\PdoResult` to avoid collisions with `\PDO` [#15874](https://github.com/phalcon/cphalcon/issues/15854) [[doc]](https://docs.phalcon.io/5.12/db-layer/)
- Moved `Phalcon\Validation` to `Phalcon\Filter\Validation`

### Added

- Added `Phalcon\Html\Helper\Title:setSeparator` to allow setting the separator independently [#15866](https://github.com/phalcon/cphalcon/issues/15866)

### Fixed

- Fixed `Phalcon\Logger\AbstractAdapter::getFormattedItem()` to not add `PHP_EOL` at the end of the message and added it to the `Phalcon\Logger\Adapter\Stream` [#14547](https://github.com/phalcon/cphalcon/issues/14547)
- Fixed `Phalcon\Html\Helper\Title:__invoke()` to not use the `$separator` as parameter - no need to redefine it in a view [#15866](https://github.com/phalcon/cphalcon/issues/15866)
- Fixed the delimiters for `Phalcon\Support\Helper\SnakeCase` and `Phalcon\Support\Helper\KamelCase` [#15850](https://github.com/phalcon/cphalcon/issues/15850)
- Fixed `Phalcon\Mvc\Router\Route::getName()` and `Phalcon\Mvc\Router\Route::getHostname()` to also return `null` [#15880](https://github.com/phalcon/cphalcon/issues/15880)
- Fixed `Phalcon\Mvc\Router\RouteInterface::getName()` and `Phalcon\Mvc\Router\RouteInterface::getHostname()` to also return `null` [#15880](https://github.com/phalcon/cphalcon/issues/15880)
- Fixed `Phalcon\Mvc\Model::findFirst()` to return `mixed` or `null` [#15883](https://github.com/phalcon/cphalcon/issues/15883)
- Fixed `Phalcon\Mvc\Model::belongsTo()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model::hasMany()`   parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model::hasOne()`    parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model::hasOneThrough()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model\Manager::addHasMany()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model\Manager::addHasManyToMany()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model\Manager::addHasOne()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model\Manager::addHasOneThrough()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)
- Fixed `Phalcon\Mvc\Model\Manager::addBelongsTo()` parameter `options` array by default [#15971](https://github.com/phalcon/cphalcon/issues/15971)

## [5.0.0beta2](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0beta2) (2022-01-06)

### Added

- Added `Phalcon\Support\Helper\Str\KebabCase`, `Phalcon\Support\Helper\Str\PascalCase` and `Phalcon\Support\Helper\Str\SnakeCase` helpers [#15850](https://github.com/phalcon/cphalcon/issues/15850)

### Fixed

- `Phalcon\Mvc\View\Engine\Volt\Compiler::functionCall()` to check for container presence before checking the `tag` service [#15842](https://github.com/phalcon/cphalcon/issues/15842)
- `Phalcon\Di\FactoryDefault()` to set `assets` and `tag` as shared services [#15847](https://github.com/phalcon/cphalcon/issues/15847)
- `Phalcon\Forms\Element\AbstractElement::getLocalTagFactory()` to return the tagFactory from itself, the form, the DI or a new instance [#15847](https://github.com/phalcon/cphalcon/issues/15847) [[doc]](https://docs.phalcon.io/5.12/forms/)
- Changed references to `sha1` with `hash("sha256", $data)` to ensure that there are no collisions from the hashing algorithm  [#15844](https://github.com/phalcon/cphalcon/issues/15844)
- Changed `Phalcon\Support\Helper\Str\Camelize` to accept a third boolean parameter indicating whether the result will have the first letter capitalized or not [#15850](https://github.com/phalcon/cphalcon/issues/15850)

## [5.0.0beta1](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0beta1) (2021-12-24)

### Changed

- Marked as deprecated:
    - `Phalcon\Mvc\Model::existsBelongsTo()`
    - `Phalcon\Mvc\Model::existsHasMany()`
    - `Phalcon\Mvc\Model::existsHasOne()`
    - `Phalcon\Mvc\Model::existsHasOneThrough()`
    - `Phalcon\Mvc\Model::existsHasManyToMany()`
    - `Phalcon\Translate\Adapter\Csv::exists()`
    - `Phalcon\Translate\Adapter\Gettext::exists()`
    - `Phalcon\Translate\Adapter\NativeArray::exists()` [#15785](https://github.com/phalcon/cphalcon/issues/15785)
- Moved `Phalcon\Container` to `Phalcon\Container\Container` [#15796](https://github.com/phalcon/cphalcon/issues/15796)
- Changed the `Phalcon\Support\Collection::get()` to return the default value if the key does not exist or the value is `null` to mirror the behavior of v3. [#15370](https://github.com/phalcon/cphalcon/issues/15370)
- Moved `Phalcon\Registry` to `Phalcon\Support\Registry` [#15802](https://github.com/phalcon/cphalcon/issues/15802)
- Moved `Phalcon\Url` to `Phalcon\Mvc\Url` [#15798](https://github.com/phalcon/cphalcon/issues/15798)
- Moved `Phalcon\Loader` to `Phalcon\Autoload\Loader` [#15797](https://github.com/phalcon/cphalcon/issues/15797)
- Changes to `Phalcon\Autoload\Loader`:
    - Renamed `registerClasses()` to `setClasses()`
    - Renamed `registerDirectories()` to `setDirectories()`
    - Renamed `registerExtensions()` to `setExtensions()`
    - Renamed `registerFiles()` to `setFiles()`
    - Renamed `registerNamespaces()` to `setNamespaces()` [#15797](https://github.com/phalcon/cphalcon/issues/15797)
- Moved `Phalcon\Di` to `Phalcon\Di\Di` [#15799](https://github.com/phalcon/cphalcon/issues/15799)
- Removed references to `Phalcon\Tag` from the framework in favor of `Phalcon\Html\TagFactory` [#15801](https://github.com/phalcon/cphalcon/issues/15801)
- `Phalcon\Forms\Form` requires a `Phalcon\Html\TagFactory` to be set before it can render elements [#15801](https://github.com/phalcon/cphalcon/issues/15801)
- `Phalcon\Di\FactoryDefault` will now return a `Phalcon\Html\TagFactory` for the `tag` service [#15801](https://github.com/phalcon/cphalcon/issues/15801)

### Added

- Added:
    - `Phalcon\Mvc\Model::hasBelongsTo()`
    - `Phalcon\Mvc\Model::hasHasMany()`
    - `Phalcon\Mvc\Model::hasHasOne()`
    - `Phalcon\Mvc\Model::hasHasOneThrough()`
    - `Phalcon\Mvc\Model::hasHasManyToMany()`
    - `Phalcon\Translate\Adapter\Csv::has()`
    - `Phalcon\Translate\Adapter\Gettext::has()`
    - `Phalcon\Translate\Adapter\NativeArray::has()` [#15785](https://github.com/phalcon/cphalcon/issues/15785)
- Added `filter`, `camelize`, `dynamic` and `uncamelize` in `Phalcon\Support\HelperFactory` [#15805](https://github.com/phalcon/cphalcon/issues/15805)
- Added `Phalcon\Autoload\Loader::getDebug()` to collect debugging information from the loader (enabled from the constructor) [#15797](https://github.com/phalcon/cphalcon/issues/15797)

### Fixed

- `Phalcon\Logger\LoggerFactory::load()` to correctly use the key of the adapters array as the name of the adapter [#15831](https://github.com/phalcon/cphalcon/issues/15831)
- Fixed `Phalcon\Dispatcher\Dispatcher::setParams()` not updating local params during `dispatch()` loop [#15603](https://github.com/phalcon/cphalcon/issues/15603)
- Fixed related records auto-save with `belongsTo()` relation [#15148](https://github.com/phalcon/cphalcon/issues/15148)

### Removed

- Removed `Phalcon\Exception`; replaced by `\Exception` [#15800](https://github.com/phalcon/cphalcon/issues/15800)

## [5.0.0alpha7](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha7) (2021-11-16)

### Changed

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
- Changed `Phalcon\Mvc\Model::getPreparedQuery()` to return `QueryInterface` instead of `Query` [#15562](https://github.com/phalcon/cphalcon/issues/15562)
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
- Changed `Phalcon\Support\Collection\ReadOnly` to `Phalcon\Support\Collection\ReadOnlyCollection` to avoid conflicts with the read-only feature in PHP 8.1 [#15767](https://github.com/phalcon/cphalcon/issues/15767)
- Removed `Phalcon\Text` - replaced by `Phalcon\Support\Helper\Str\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Removed `Phalcon\Helper\Arr` - replaced by `Phalcon\Support\Helper\Arr\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Removed `Phalcon\Helper\File` - replaced by `Phalcon\Support\Helper\File\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Removed `Phalcon\Helper\Json` - replaced by `Phalcon\Support\Helper\Json\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Removed `Phalcon\Helper\Number` - replaced by `Phalcon\Support\Helper\Number\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Removed `Phalcon\Helper\Str` - replaced by `Phalcon\Support\Helper\Str\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Removed references to `Phalcon\Text`, `Phacon\Helper\*` from the code replacing it with `Phalcon\Support\Helper\*` [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Synchronized tests with `phalcon/phalcon` thus increasing coverage [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Changed `Phalcon\Assets\Manager` to require a `Phalcon\Html\TagFactory` in its constructor [#15776](https://github.com/phalcon/cphalcon/issues/15776)

### Added

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
- Added `dirtyState` serialization in `Phalcon\Mvc\Model` [#15571](https://github.com/phalcon/cphalcon/issues/15571)
- Added short versions of helpers for `Phalcon\Html\TagFactory` (call service as a method) [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Added short versions of helpers for `Phalcon\Support\HelperFactory` (call service as a method) [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Added `Phalcon\Html\Helper\Doctype` helper for `doctype` generation [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Added `style` or `link` tag option for `Phalcon\Html\Helper\Style` [#15776](https://github.com/phalcon/cphalcon/issues/15776)

### Fixed

- Fixed `Query::getExpression()` return type [#15553](https://github.com/phalcon/cphalcon/issues/15553)
- Fixed `Phalcon\Mvc\Model::getRelated()` to correctly return relationships (cached or not) when the foreign key has changed [#15649](https://github.com/phalcon/cphalcon/issues/15649) [[doc]](https://docs.phalcon.io/5.12/db-models/)
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
- Fixed `Phalcon\Db\RawValue` usage bugs in `Phalcon\Mvc\Model::doLowUpdate()` [#15413](https://github.com/phalcon/cphalcon/issues/15413)
- Fixed `type` attribute for stylesheet links [#15776](https://github.com/phalcon/cphalcon/issues/15776)
- Fixed `Phalcon\Debug` to not throw an exception if a URL service is not present [#15381](https://github.com/phalcon/cphalcon/issues/15381)

### Removed

- Removed `Phalcon\Kernel` - obsolete [#15776](https://github.com/phalcon/cphalcon/issues/15776)

## [5.0.0alpha6](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha6) (2021-09-16)

### Changed

- Adjusted the constructor for `Phalcon\Storage\Adapter\*` and `Phalcon\Cache\Adapter\*` to allow an empty key prefix to be set if needed. [#15480](https://github.com/phalcon/cphalcon/issues/15480)
- Changed:
    - `Phalcon\Db\Adapter\AdapterInterface:lastInsertId()` to be identical as `Pdo:lastInsertId()`
    - `Phalcon\Db\Adapter\AdapterInterface:close()` now returns `void` instead of `bool`
    - `Phalcon\Db\Adapter\AdapterInterface:connect()` now returns `void` instead of `bool` and 1st argument default value is empty `array` instead of `null` [#15659](https://github.com/phalcon/cphalcon/issues/15659)

### Added

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
        - `Phalcon\Support\Helper\Json\Encode` [[doc]](https://docs.phalcon.io/5.12/support-helper/)
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

## [5.0.0alpha5](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha5) (2021-09-09)

### Changed

- Merged all architectures (`build/phalcon/32bits`, `build/phalcon/64bits` and `build/phalcon/safe`) into single universal inside `build/phalcon` [#15647](https://github.com/phalcon/cphalcon/issues/15647)

### Fixed

- Fixed C code in `build/` directory [#15647](https://github.com/phalcon/cphalcon/issues/15647)

## [5.0.0alpha4](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha4) (2021-09-05)

### Changed

- Changed `composer.json` to use PSR 1.1.x [#15504](https://github.com/phalcon/cphalcon/issues/15504)
- Changed `Phalcon\Di\Injectable:getDI()` to set default DI when no DI is set [#15629](https://github.com/phalcon/cphalcon/pull/15629)

### Added

- Added `Phalcon\Flash\Direct::setCssIconClasses` and `Phalcon\Flash\Session::setCssIconClasses` to allow setting icons in the flash messages (bootstrap related) [#15292](https://github.com/phalcon/cphalcon/issues/15292)
- Added `Phalcon\Http\Message\RequestMethodInterface` and `Phalcon\Http\Message\ResponseStatusCodeInterface` that contain constants to be used for any HTTP implementations (see PHP-FIG) [#15615](https://github.com/phalcon/cphalcon/issues/15615)

### Fixed

- Fixed `Phalcon\Container` interface to abide with `Psr\Container\ContainerInterface` after the upgrade to PSR 1.1.x [#15504](https://github.com/phalcon/cphalcon/issues/15504)
- Fixed `Phalcon\Forms\Form` when no entity is passed with isValid(), it uses the entity set in the form [#15567](https://github.com/phalcon/cphalcon/issues/15567)
- Fixed `Phalcon\Logger\Adapter\*` to not allow serialization of the object. Added an exception when destroying the object while in transaction mode [#15638](https://github.com/phalcon/cphalcon/issues/15638)

## [5.0.0alpha3](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0alpha3) (2021-06-30)

### Changed

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

### Fixed

- Fixed `Phalcon\Db\Adapter\AbstractAdapter:delete()` when `bindTypes` argument is passed. [#15363](https://github.com/phalcon/cphalcon/issues/15363)
- Fixed `Phalcon\Storage\Adapter\Redis::getAdapter` to use passed `connectionTimeout`, `retryInterval` and `readTimeout` options for the connection [#15484](https://github.com/phalcon/cphalcon/issues/15484)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler` for a use case when a block will return null vs an array for `statementList` in PHP 8 [#15556](https://github.com/phalcon/cphalcon/issues/15556)

## [5.0.0-alpha.2](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0-alpha.2) (2021-05-05)

### Changed

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

### Added

- Added `BINARY` and `VARBINARY` support for Phalcon\Db\Adapter\Mysql [#14927](https://github.com/phalcon/cphalcon/issues/14927)
- Added `Phalcon\Db\Profiler\Item::getTotalElapsedNanoseconds()` and `Phalcon\Db\Profiler\Item::getTotalElapsedMilliseconds()` for more precision [#15249](https://github.com/phalcon/cphalcon/issues/15249)
- Added `Phalcon\Http\Response\Cookies::isSent()` and `Phalcon\Http\Response\Headers::isSent()`; Added logic to not send the headers or cookies twice. [#15334](https://github.com/phalcon/cphalcon/issues/15334)
- Added `Phalcon\Validation\Validator\File\AbstractFile::checkIsUploadedFile()` method to allow overriding when adding files to the `$_FILES` array directly (not uploading). [#15051](https://github.com/phalcon/cphalcon/issues/15051)
- Added `Phalcon\Support\Helper\Str\Interpolate` to be used throughout the code for interpolation (Logger/Translator) `%type%` to `%level%` to align with the variables [#15411](https://github.com/phalcon/cphalcon/issues/15411)
- Added `Phalcon\Support\HelperFactory` for an easier creation/access of helpers [#15411](https://github.com/phalcon/cphalcon/issues/15411)

### Fixed

- Corrected the `Phalcon\Db\Profiler\Item` calculation for seconds [#15249](https://github.com/phalcon/cphalcon/issues/15249)
- Corrected `Phalcon\Http\Message\ServerRequestFactory` to populate with superglobals [#15286](https://github.com/phalcon/cphalcon/issues/15286)
- Corrected `Phalcon\Mvc\Model\Query\BuilderInterface::orderBy` to use `var` instead of `string` [#15415](https://github.com/phalcon/cphalcon/issues/15415)
- Corrected `Phalcon\Db\Adapter\Pdo\AbstractPdo::connect` to take into account the `persistent` option for relevant connections [#15241](https://github.com/phalcon/cphalcon/issues/15241)
- Corrected `Phalcon\Image\Adapter\Gd::processText` to correctly call `imagettfbbox` when a font is specified [#15188](https://github.com/phalcon/cphalcon/issues/15188)
- Corrected `Phalcon\Cache` to cast keys as strings before sending them to adapters [#15249](https://github.com/phalcon/cphalcon/issues/15249)
- Binding form values with specified whitelist [#15070](https://github.com/phalcon/cphalcon/issues/15070)

## [5.0.0-alpha.1](https://github.com/phalcon/cphalcon/releases/tag/v5.0.0-alpha.1) (2021-03-31)

### Fixed

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
- Fixed `Phalcon\Annotations\Reader::parse()` to return constants annotations [#15919](https://github.com/phalcon/cphalcon/issues/15919)
- Added `Phalcon\Annotations\Reflection::getConstantsAnnotations()` method that returns constants annotations [#15919](https://github.com/phalcon/cphalcon/issues/15919)
- Changes to the `Phalcon\Annotations\Adapter\AdapterInterface`:
    - Added `getConstant()` method that returns class constant annotations collection
    - Added `getConstants()` method that returns class constants annotations array list
