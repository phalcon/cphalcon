
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_queue_beanstalk_job_ce;

PHALCON_INIT_CLASS(Phalcon_Queue_Beanstalk_Job);

PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __construct);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getId);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getBody);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, delete);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, queue)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_queue_beanstalk_job_method_entry){
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __construct, arginfo_phalcon_queue_beanstalk_job___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getBody, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Queue_Beanstalk_Job, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
