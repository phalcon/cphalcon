
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Song Yeung <netyum@163.com>                                   |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_EXIT_H
#define ZEPHIR_KERNEL_EXIT_H

#include <Zend/zend.h>

void zephir_exit_empty();
void zephir_exit(zval *ptr);

#endif
