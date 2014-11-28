
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_ASYNC_H
#define PHALCON_ASYNC_H

#include "php_phalcon.h"

#define PHALCON_ASYNC_NOWAIT		1
#define PHALCON_ASYNC_MSG_NOERROR	2
#define PHALCON_ASYNC_MSG_EXCEPT	4

extern zend_class_entry *phalcon_async_ce;

PHALCON_INIT_CLASS(Phalcon_Async);

#endif /* PHALCON_ASYNC_H */
