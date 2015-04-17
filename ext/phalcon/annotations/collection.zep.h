
<<<<<<< HEAD:ext/phalcon/annotations/collection.zep.h
extern zend_class_entry *phalcon_annotations_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Collection);

PHP_METHOD(Phalcon_Annotations_Collection, __construct);
PHP_METHOD(Phalcon_Annotations_Collection, count);
PHP_METHOD(Phalcon_Annotations_Collection, rewind);
PHP_METHOD(Phalcon_Annotations_Collection, current);
PHP_METHOD(Phalcon_Annotations_Collection, key);
PHP_METHOD(Phalcon_Annotations_Collection, next);
PHP_METHOD(Phalcon_Annotations_Collection, valid);
PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations);
PHP_METHOD(Phalcon_Annotations_Collection, get);
PHP_METHOD(Phalcon_Annotations_Collection, getAll);
PHP_METHOD(Phalcon_Annotations_Collection, has);
=======
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_ANNOTATIONS_COLLECTION_H
#define PHALCON_ANNOTATIONS_COLLECTION_H
>>>>>>> master:ext/annotations/collection.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_annotations_collection_ce;

<<<<<<< HEAD:ext/phalcon/annotations/collection.zep.h
ZEPHIR_INIT_FUNCS(phalcon_annotations_collection_method_entry) {
	PHP_ME(Phalcon_Annotations_Collection, __construct, arginfo_phalcon_annotations_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, getAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, get, arginfo_phalcon_annotations_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, getAll, arginfo_phalcon_annotations_collection_getall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, has, arginfo_phalcon_annotations_collection_has, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Annotations_Collection);

#endif /* PHALCON_ANNOTATIONS_COLLECTION_H */
>>>>>>> master:ext/annotations/collection.h
