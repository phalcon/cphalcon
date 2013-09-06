
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
#ifndef PHALCON_CHART_QRCODE_H
#define PHALCON_CHART_QRCODE_H

extern zend_class_entry *phalcon_chart_qrcode_ce;

PHALCON_INIT_CLASS(Phalcon_Chart_QRcode);

PHP_METHOD(Phalcon_Chart_QRcode, __construct);
PHP_METHOD(Phalcon_Chart_QRcode, generate);
PHP_METHOD(Phalcon_Chart_QRcode, render);
PHP_METHOD(Phalcon_Chart_QRcode, save);
#ifdef PHALCON_USE_ZBAR
PHP_METHOD(Phalcon_Chart_QRcode, scan);
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrcode_generate, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, version)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, casesensitive)
ZEND_END_ARG_INFO()
#ifdef PHALCON_USE_ZBAR
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrcode_scan, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()
#endif
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrcode_render, 0, 0, 0)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_chart_qrcode_save, 0, 0, 0)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, margin)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_chart_qrcode_method_entry){
	PHP_ME(Phalcon_Chart_QRcode, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Chart_QRcode, generate, arginfo_phalcon_chart_qrcode_generate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Chart_QRcode, render, arginfo_phalcon_chart_qrcode_render, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Chart_QRcode, save, arginfo_phalcon_chart_qrcode_save, ZEND_ACC_PUBLIC) 
#ifdef PHALCON_USE_ZBAR
	PHP_ME(Phalcon_Chart_QRcode, scan, arginfo_phalcon_chart_qrcode_scan, ZEND_ACC_PUBLIC) 
#endif
	PHP_FE_END
};

#ifdef PHALCON_USE_ZBAR
#include <wand/MagickWand.h>
#include <zbar.h>
#endif

#endif	/* PHALCON_CHART_QRCODE_H */

