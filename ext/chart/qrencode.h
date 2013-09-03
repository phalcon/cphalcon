
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/
#ifndef PHALCON_CHART_QRENCODE_H
#define PHALCON_CHART_QRENCODE_H

extern zend_class_entry *phalcon_chart_qrencode_ce;

PHALCON_INIT_CLASS(Phalcon_Chart_QRencode);

PHP_METHOD(Phalcon_Chart_QRencode, __construct);
PHP_METHOD(Phalcon_Chart_QRencode, generate);
PHP_METHOD(Phalcon_Chart_QRencode, render);
PHP_METHOD(Phalcon_Chart_QRencode, save);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrencode___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, version)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, casesensitive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrencode_render, 0, 0, 0)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrencode_save, 0, 0, 0)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_chart_qrencode_method_entry){
	PHP_ME(Phalcon_Chart_QRencode, __construct, arginfo_phalcon_chart_qrencode___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Chart_QRencode, generate, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Chart_QRencode, render, arginfo_phalcon_chart_qrencode_render, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Chart_QRencode, save, arginfo_phalcon_chart_qrencode_save, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

#endif	/* PHALCON_CHART_QRENCODE_H */

