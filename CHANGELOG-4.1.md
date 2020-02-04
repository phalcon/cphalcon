# [4.1.0](https://github.com/phalcon/cphalcon/releases/tag/v4.1.0) (xxx-xx-xx)
## Added
- Added JWT (JSON Web Tokens) support under `Phalcon\Http\JWT`. Offers support for:
  - Token
  - Parser
  - Builder
  - Validator
  - Signers (None, HMAC)
  - Base64 encode/decodeUrl helper class
[#13856](https://github.com/phalcon/cphalcon/issues/13856)
- Added additional HTML helpers under `Phalcon\Html\Helper`: `Anchor`, `Base`, `Body`, `Button`, `Close`, `Element`, `Form`, `Img`, `Input\Color`, `Input\Date`, `Input\DateTime`, `Input\DateTimeLocal`, `Input\Email`, `Input\File`, `Input\Hidden`, `Input\Image`, `Input\Input`, `Input\Month`, `Input\Numeric`, `Input\Password`, `Input\Range`, `Input\Select`, `Input\Search`, `Input\Submit`, `Input\Tel`, `Input\Text`, `Input\Textarea`, `Input\Time`, `Input\Url`, `Input\Week`, `Label`, `Link`, `Meta`, `Ol`, `Script`, `Style`, `Title`, `Ul` 
[#14696](https://github.com/phalcon/cphalcon/issues/14696)
- Added `Phalcon\Http\Request::getPreferredIsoLocaleVariant()` to return the base language if this is a specific one (`en` vs `en-US`) [#3135](https://github.com/phalcon/cphalcon/issues/3135)
- Added `preload` for Volt, which will send a HTTP/2 preload header [#13128](https://github.com/phalcon/cphalcon/issues/13128)
- Added `Phalcon\Helper\Arr::blackList()` to exclude elements of an array by the keys obtained from the elements of a blacklist [#14801](https://github.com/phalcon/cphalcon/issues/14801) [@TimurFlush](https://github.com/TimurFlush)

## Changed
- Added service checks for the session. Now cookies will be saved in the session only when the `session` service is defined [#11770](https://github.com/phalcon/cphalcon/issues/11770), [#14649](https://github.com/phalcon/cphalcon/pull/14649)
- Changed `Phalcon\Db\Adapter\*::getRawSQLStatement()` to return the full SQL query with parameters [#12196](https://github.com/phalcon/cphalcon/issues/12196)

## Fixed
- Fixed `Phalcon\Db\Dialect\Mysql::getColumnDefinition` to recognize `size` for `DATETIME`, `TIME` and `TIMESTAMP` columns [#13297](https://github.com/phalcon/cphalcon/issues/13297)

## Removed
- Removed `Phalcon\Http\Cookie` binding to session [#11770](https://github.com/phalcon/cphalcon/issues/11770)
  - `Phalcon\Http\Cookie` no longer depends on the session service and data will not be duplicated in the session. This made it difficult to use cookies in stateless applications (SPA).

`