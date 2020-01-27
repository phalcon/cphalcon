
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team  (http://www.zephir-lang.com)      |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_TIME_H
#define ZEPHIR_KERNEL_TIME_H

#include <php.h>
#include <Zend/zend.h>

#define MICRO_IN_SEC 1000000.00

void zephir_time(zval *return_value);
#ifdef HAVE_GETTIMEOFDAY
void zephir_microtime(zval *return_value, zval *get_as_float);
#endif

#endif /* ZEPHIR_KERNEL_TIME_H */
