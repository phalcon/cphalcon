# [3.1.2](https://github.com/phalcon/cphalcon/releases/tag/v3.1.2) (2017-04-05)
- Fixed PHP 7.1 issues [#12055](https://github.com/phalcon/cphalcon/issues/12055)
- Fixed `Imagick::getVersion()` error in some system [#12729](https://github.com/phalcon/cphalcon/pull/12729)
- Fixed `Phalcon\Mvc\Model::_doLowInsert` to properly set snapshot when having default values and public properties [#12766](https://github.com/phalcon/cphalcon/issues/12766)

# [3.1.1](https://github.com/phalcon/cphalcon/releases/tag/v3.1.1) (2017-03-25)
- Fixed undefined index warning on existing cached resultsets
- Fixed `Phalcon\Mvc\Model::_dowLowUpdate` warning first argument is not an array [#12742](https://github.com/phalcon/cphalcon/issues/12742)

# [3.1.0](https://github.com/phalcon/cphalcon/releases/tag/v3.1.0) (2017-03-22)
- Added `Phalcon\Validation\Validator\Callback`, `Phalcon\Validation::getData`
- Added the ability to truncate database tables
- Added `Phalcon\Mvc\Model\Binder`, class used for binding models to parameters in dispatcher, micro, added `Phalcon\Dispatcher::getBoundModels` and `Phalcon\Mvc\Micro::getBoundModels` to getting bound models, added `Phalcon\Mvc\Micro\Collection\LazyLoader::callMethod`
- Added afterBinding event to `Phalcon\Dispatcher` and `Phalcon\Mvc\Micro`, added `Phalcon\Mvc\Micro::afterBinding`
- Added the ability to set custom Resultset class returned by find() [#12166](https://github.com/phalcon/cphalcon/issues/12166)
- Added the ability to clear appended and prepended title elements (Phalcon\Tag::appendTitle, Phalcon\Tag::prependTitle). Now you can use array to add multiple titles. For more details check [#12238](https://github.com/phalcon/cphalcon/issues/12238).
- Added the ability to specify what empty means in the 'allowEmpty' option of the validators. Now it accepts as well an array specifying what's empty, for example ['', false]
- Added the ability to use `Phalcon\Validation` with `Phalcon\Mvc\Collection`, deprecated `Phalcon\Mvc\Model\Validator` classes
- Added the value of the object intanceof Interface to `Phalcon\Acl\Adapter\Memory`
- Added the ability to get original values from `Phalcon\Mvc\Model\Binder`, added `Phalcon\Mvc\Micro::getModelBinder`, `Phalcon\Dispatcher::getModelBinder`
- Added `prepend` parameter to `Phalcon\Loader::register` to specify autoloader's loading order to top most
- Fixes internal cache saving in `Phalcon\Mvc\Model\Binder` when no cache backend is used
- Fixed `Phalcon\Session\Bag::remove` to initialize the bag before removing a value [#12647](https://github.com/phalcon/cphalcon/pull/12647)
- Fixed `Phalcon\Mvc\Model::getChangedFields` to correct detect changes from NULL to Zero [#12628](https://github.com/phalcon/cphalcon/issues/12628)
- Fixed `Phalcon\Mvc\Model` to create/refresh snapshot after create/update/refresh operation [#11007](https://github.com/phalcon/cphalcon/issues/11007), [#11818](https://github.com/phalcon/cphalcon/issues/11818), [#11424](https://github.com/phalcon/cphalcon/issues/11424)
- Fixed `Phalcon\Mvc\Model::validate` to correctly set code message [#12645](https://github.com/phalcon/cphalcon/issues/12645)
- Fixed `Phalcon\Mvc\Model` to correctly add error when try to save empty string value to not null and not default column [#12688](https://github.com/phalcon/cphalcon/issues/12688)
- Fixed `Phalcon\Validation\Validator\Uniqueness` collection persistent condition
- Fixed `Phalcon\Loader::autoLoad` to prevent PHP warning [#12684](https://github.com/phalcon/cphalcon/pull/12684)
- Fixed `Phalcon\Mvc\Model\Query::_executeSelect` to correctly get the column map [#12715](https://github.com/phalcon/cphalcon/issues/12715)
- Fixed params view scope for PHP 5 [#12648](https://github.com/phalcon/cphalcon/issues/12648)
