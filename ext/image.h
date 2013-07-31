
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
  | Authors: Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_image_ce;

PHALCON_INIT_CLASS(Phalcon_Image);

PHP_METHOD(Phalcon_Image, resize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, master)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_image_method_entry) {
	PHP_ME(Phalcon_Image, resize, arginfo_phalcon_image_resize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

