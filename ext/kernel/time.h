
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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


#ifndef PHALCON_KERNEL_TIME_H
#define PHALCON_KERNEL_TIME_H

#include <php.h>
#include <Zend/zend.h>

#define MICRO_IN_SEC 1000000.00

void phalcon_time(zval *return_value);
#ifdef HAVE_GETTIMEOFDAY
void phalcon_microtime(zval *return_value, zval *get_as_float TSRMLS_DC);
#endif

#endif /* PHALCON_KERNEL_TIME_H */
