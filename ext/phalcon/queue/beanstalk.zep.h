
<<<<<<< HEAD:ext/phalcon/queue/beanstalk.zep.h
extern zend_class_entry *phalcon_queue_beanstalk_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk);

PHP_METHOD(Phalcon_Queue_Beanstalk, __construct);
PHP_METHOD(Phalcon_Queue_Beanstalk, connect);
PHP_METHOD(Phalcon_Queue_Beanstalk, put);
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve);
PHP_METHOD(Phalcon_Queue_Beanstalk, choose);
PHP_METHOD(Phalcon_Queue_Beanstalk, watch);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried);
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus);
PHP_METHOD(Phalcon_Queue_Beanstalk, read);
PHP_METHOD(Phalcon_Queue_Beanstalk, write);
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
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

#ifndef PHALCON_QUEUE_BEANSTALK_H
#define PHALCON_QUEUE_BEANSTALK_H
>>>>>>> master:ext/queue/beanstalk.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_queue_beanstalk_ce;

<<<<<<< HEAD:ext/phalcon/queue/beanstalk.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_beanstalk_method_entry) {
	PHP_ME(Phalcon_Queue_Beanstalk, __construct, arginfo_phalcon_queue_beanstalk___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Beanstalk, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, put, arginfo_phalcon_queue_beanstalk_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, reserve, arginfo_phalcon_queue_beanstalk_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, choose, arginfo_phalcon_queue_beanstalk_choose, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, watch, arginfo_phalcon_queue_beanstalk_watch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekReady, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekBuried, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, readStatus, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, read, arginfo_phalcon_queue_beanstalk_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, write, arginfo_phalcon_queue_beanstalk_write, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Queue_Beanstalk, disconnect, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Queue_Beanstalk);

#endif /* PHALCON_QUEUE_BEANSTALK_H */
>>>>>>> master:ext/queue/beanstalk.h
