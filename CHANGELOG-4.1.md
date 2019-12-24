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

## Changed

## Fixed

## Removed
- Removed `Phalcon\Http\Cookie` binding to session [#11770](https://github.com/phalcon/cphalcon/issues/11770)
  - `Phalcon\Http\Cookie` no longer depends on the session service and data will not be duplicated in the session. This made it difficult to use cookies in stateless applications (SPA).



