
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_cache_frontend_igbinary_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Igbinary);

PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_igbinary_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, beforeStore, arginfo_phalcon_cache_frontend_igbinary_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, afterRetrieve, arginfo_phalcon_cache_frontend_igbinary_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

