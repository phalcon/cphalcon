# [4.0.0](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0) (2018-XX-XX)

## Added
- Added `Phalcon\Db\Adapter\Pdo\Postgresql::describeReferences` to implement custom Postgresql rules
- Added `Phalcon\Mvc\Router\RouteInterface::convert` so that calling `Phalcon\Mvc\Router\Group::add` will return an instance that has `convert` method [#13380](https://github.com/phalcon/cphalcon/issues/13380)
- Added `Phalcon\Mvc\ModelInterface::getModelsMetaData` [#13070](https://github.com/phalcon/cphalcon/issues/13402)
- Added `paginate()` method as a proxy of `getPaginate`. Added `previous` in the paginator object same as `before`. After 4.0 is released we will deprecate `getPaginate()`, `before` and `total_items` [#13492](https://github.com/phalcon/cphalcon/issues/13492)
- Added `Phalcon\Messages\MessageInterface`, `Phalcon\Messages\Message`, `Phalcon\Messages\Exception` and `Phalcon\Messages\Messages` to handle all messages for the application (model/validation) [#13114](https://github.com/phalcon/cphalcon/issues/13114)
- Added `getHandlerSuffix()`, `setHandlerSuffix()` in Dispatcher, `getTaskSuffix()`, `setTaskSuffix()` in the CLI Dispatcher [#13468](https://github.com/phalcon/cphalcon/issues/13468)
- Added ability to set a custom template for the Flash Messenger. [#13445](https://github.com/phalcon/cphalcon/issues/13445)
- Added `forUpdate` in the Sqlite dialect to override the method from the base dialect. [#13539](https://github.com/phalcon/cphalcon/issues/13539)
- Added `TYPE_ENUM` in the Mysql adapter. [#11368](https://github.com/phalcon/cphalcon/issues/11368)
- Added `Phalcon\Acl\Adapter\Memory::addRole` support multiple inherited
- Added `Phalcon\Tag::renderTitle()` that renders the title enclosed in `<title>` tags. [#13547](https://github.com/phalcon/cphalcon/issues/13547)
- Added `hasHeader()` method to `Phalcon\Http\Response` to provide the ability to check if a header exists. [PR-12189](https://github.com/phalcon/cphalcon/pull/12189)
- Added global setting `orm.case_insensitive_column_map` to attempt to find value in the column map case-insensitively. Can be also enabled by setting `caseInsensitiveColumnMap` key in `\Phalcon\Mvc\Model::setup()`. [#11802](https://github.com/phalcon/cphalcon/pull/11802)
- Added `Phalcon\Mvc\Model\Query\BuilderInterface::offset` [#13599](https://github.com/phalcon/cphalcon/pull/13599)
- Added `Phalcon\Http\Response\Cookies::getCookies` [#13591](https://github.com/phalcon/cphalcon/pull/13591)
- Added `Phalcon\Mvc\Model::isRelationshipLoaded` to check if relationship is loaded

## Changed
- By configuring `prefix` and `statsKey` the `Phalcon\Cache\Backend\Redis::queryKeys` no longer returns prefixed keys, now it returns original keys without prefix. [PR-13456](https://github.com/phalcon/cphalcon/pull/13456)
- Now Phalcon requires the [PSR PHP extension](https://github.com/jbboehr/php-psr) to be installed and enabled
- The `Phalcon\Mvc\Application`, `Phalcon\Mvc\Micro` and `Phalcon\Mvc\Router` now must have a URI to process [PR-12380](https://github.com/phalcon/cphalcon/pull/12380)
- Response headers and cookies are no longer prematurely sent [PR-12378](https://github.com/phalcon/cphalcon/pull/12378)
- You can no longer assign data to models whilst saving them [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- The `Phalcon\Mvc\Model\Manager::load` no longer reuses already initialized models [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Changed `Phalcon\Db\Dialect\Postgresql::describeReferences` to generate correct SQL, added "on update" and "on delete" constraints
- Changed catch `Exception` to `Throwable` [#12288](https://github.com/phalcon/cphalcon/issues/12288)
- Changed `Phalcon\Mvc\Model\Query\Builder::addFrom` to remove third parameter `$with` [PR-13109](https://github.com/phalcon/cphalcon/pull/13109)
- `Phalcon\Forms\Form::clear` will no longer call `Phalcon\Forms\Element::clear`, instead it will clear/set default value itself, and `Phalcon\Forms\Element::clear` will now call `Phalcon\Forms\Form::clear` if it's assigned to the form, otherwise it will just clear itself. [PR-13500](https://github.com/phalcon/cphalcon/pull/13500)
- `Phalcon\Forms\Form::getValue` will now also try to get the value by calling `Tag::getValue` or element's `getDefault` method before returning `null`, and `Phalcon\Forms\Element::getValue` calls `Tag::getDefault` only if it's not added to the form. [PR-13500](https://github.com/phalcon/cphalcon/pull/13500)
- Changed `Phalcon\Mvc\Model` to use the `Phalcon\Messages\Message` object for its messages [#13114](https://github.com/phalcon/cphalcon/issues/13114)
- Changed `Phalcon\Validation\*` to use the `Phalcon\Messages\Message` object for its messages [#13114](https://github.com/phalcon/cphalcon/issues/13114)
- Collections now use the Validation component [PR-12376](https://github.com/phalcon/cphalcon/pull/12376)
- Made the `specialKey` (`_PHCR`) optional for the `Phalcon\Cache\Backend\Redis` adapter [#10905](https://github.com/phalcon/cphalcon/issues/10905), [#11608](https://github.com/phalcon/cphalcon/pull/11608)
- Refactored `Phalcon\Db\Adapter\Pdo::query` to use PDO's prepare and execute. `Phalcon\Db\Adapter::fetchAll` to use PDO's fetchAll
- Fixed  `\Phalcon\Http\Response::setFileToSend` filename last much _ 
- Changed `Phalcon\Tag::getTitle()`. It returns only the text. It accepts `prepend`, `append` booleans to prepend or append the relevant text to the title. [#13547](https://github.com/phalcon/cphalcon/issues/13547) 
- Changed `Phalcon\Di\Service` constructor to no longer takes the name of the service.

## Removed
- PHP < 7.0 no longer supported
- Removed `Phalcon\Model::reset` [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Removed deprecated `Phalcon\Cli\Console::addModules`
- Removed deprecated `Phalcon\Debug::getMajorVersion`
- Removed deprecated `Phalcon\Mvc\Model\Criteria::addWhere`
- Removed deprecated `Phalcon\Mvc\Model\Criteria::order`
- Removed deprecated `Phalcon\Validation\Validator::isSetOption`
- Removed deprecated `Phalcon\Security::hasLibreSsl`
- Removed deprecated `Phalcon\Security::getSslVersionNumber`
- Removed `Phalcon\Http\RequestInterface::isSoapRequested` in favor of `Phalcon\Http\Request::isSoap`
- Removed `Phalcon\Http\RequestInterface::isSecureRequest` in favor of `Phalcon\Http\RequestInterface::isSecure`
- Removed `Phalcon\Validation\MessageInterface` and `Phalcon\Mvc\Model\MessageInterface` in favor of `Phalcon\Messages\MessageInterface`
- Removed `Phalcon\Validation\Message` and `Phalcon\Mvc\Model\Message` in favor of `Phalcon\Messages\Message`
- Removed `Phalcon\Validation\Message\Group` in favor of `Phalcon\Messages\Messages`

