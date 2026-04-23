# Changelog
## 7.0.0-alpha-1 (2026-XX-XX)

### Changed

### Added

### Fixed

- [BC] Fixed `Phalcon\Mvc\Model` NOT NULL validation to accept empty strings `""` for string columns (`VARCHAR`, `CHAR`, `TEXT`); previously `""` was incorrectly treated as `null` and triggered a `PresenceOf` validation error. Applications relying on this implicit rejection of empty strings must add an explicit `PresenceOf` or `StringLength(min=1)` validator [#16426](https://github.com/phalcon/cphalcon/issues/16426)

### Removed

