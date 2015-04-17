
<<<<<<< HEAD:ext/phalcon/text.zep.h
extern zend_class_entry *phalcon_text_ce;

ZEPHIR_INIT_CLASS(Phalcon_Text);

PHP_METHOD(Phalcon_Text, camelize);
PHP_METHOD(Phalcon_Text, uncamelize);
PHP_METHOD(Phalcon_Text, increment);
PHP_METHOD(Phalcon_Text, random);
PHP_METHOD(Phalcon_Text, startsWith);
PHP_METHOD(Phalcon_Text, endsWith);
PHP_METHOD(Phalcon_Text, lower);
PHP_METHOD(Phalcon_Text, upper);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
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

#ifndef PHALCON_TEXT_H
#define PHALCON_TEXT_H
>>>>>>> master:ext/text.h

#include "php_phalcon.h"

<<<<<<< HEAD:ext/phalcon/text.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_random, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()
=======
#define PHALCON_TEXT_RANDOM_ALNUM    0
#define PHALCON_TEXT_RANDOM_ALPHA    1
#define PHALCON_TEXT_RANDOM_HEXDEC   2
#define PHALCON_TEXT_RANDOM_NUMERIC  3
#define PHALCON_TEXT_RANDOM_NOZERO   4
>>>>>>> master:ext/text.h

extern zend_class_entry *phalcon_text_ce;

<<<<<<< HEAD:ext/phalcon/text.zep.h
ZEPHIR_INIT_FUNCS(phalcon_text_method_entry) {
	PHP_ME(Phalcon_Text, camelize, arginfo_phalcon_text_camelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, uncamelize, arginfo_phalcon_text_uncamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, increment, arginfo_phalcon_text_increment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, random, arginfo_phalcon_text_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, startsWith, arginfo_phalcon_text_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, endsWith, arginfo_phalcon_text_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, lower, arginfo_phalcon_text_lower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, upper, arginfo_phalcon_text_upper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Text);

#endif /* PHALCON_TEXT_H */
>>>>>>> master:ext/text.h
