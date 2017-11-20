# [3.3.0](https://github.com/phalcon/cphalcon/releases/tag/v3.3.0) (2017-XX-XX)
- Added support for `switch/case` syntax to the Volt Engine [#13107](https://github.com/phalcon/cphalcon/issues/13107)
- Added `Phalcon\Logger\Adapter\Blackhole` [#13074](https://github.com/phalcon/cphalcon/issues/13074)
- Added `Phalcon\Http\Request::hasHeader` to check if certain header exists
- Fixed `Phalcon\Mvc\Model\Query\Builder::getPhql` to correct generate PHQL in argument's array when using order DESC or ASC [#11827](https://github.com/phalcon/cphalcon/issues/11827)
- Fixed `Phalcon\Db\Dialect\Postgresql::createTable()` to correct inserting default value to SQL for `boolean` type [#13132](https://github.com/phalcon/cphalcon/issues/13132)
- Fixed `Phalcon\Db\Dialect\Postgresql::_castDefault()` to correct returning value for `boolean` type
- Fixed ` Phalcon\Mvc\Model::_doLowInsert()` to correct save snapshot on creation/save identityless models [#13166](https://github.com/phalcon/cphalcon/issues/13166)
