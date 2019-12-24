# [4.1.0](https://github.com/phalcon/cphalcon/releases/tag/v4.1.0) (xxx-xx-xx)
## Added

## Changed

## Fixed
- Fixed `Phalcon\Db\Dialect\Mysql::getColumnDefinition` to recognize `size` for `DATETIME`, `TIME` and `TIMESTAMP` columns [#13297](https://github.com/phalcon/cphalcon/issues/13297)

## Removed
- Removed `Phalcon\Http\Cookie` binding to session [#11770](https://github.com/phalcon/cphalcon/issues/11770)
  - `Phalcon\Http\Cookie` no longer depends on the session service and data will not be duplicated in the session. This made it difficult to use cookies in stateless applications (SPA).

`