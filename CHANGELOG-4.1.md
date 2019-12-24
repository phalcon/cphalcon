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

Thanks
## Changed

## Fixed
- Fixed `Phalcon\Db\Dialect\Mysql::getColumnDefinition` to recognize `size` for `DATETIME`, `TIME` and `TIMESTAMP` columns [#13297](https://github.com/phalcon/cphalcon/issues/13297)

