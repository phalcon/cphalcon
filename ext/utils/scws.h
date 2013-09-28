
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
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_utils_scws_ce;

PHALCON_INIT_CLASS(Phalcon_Utils_Scws);

PHP_METHOD(Phalcon_Utils_Scws, __construct);
PHP_METHOD(Phalcon_Utils_Scws, close);
PHP_METHOD(Phalcon_Utils_Scws, set_charset);
PHP_METHOD(Phalcon_Utils_Scws, add_dict);
PHP_METHOD(Phalcon_Utils_Scws, set_dict);
PHP_METHOD(Phalcon_Utils_Scws, set_rule);
PHP_METHOD(Phalcon_Utils_Scws, set_ignore);
PHP_METHOD(Phalcon_Utils_Scws, set_multi);
PHP_METHOD(Phalcon_Utils_Scws, set_duality);
PHP_METHOD(Phalcon_Utils_Scws, send_text);
PHP_METHOD(Phalcon_Utils_Scws, get_result);
PHP_METHOD(Phalcon_Utils_Scws, get_tops);
PHP_METHOD(Phalcon_Utils_Scws, has_word);
PHP_METHOD(Phalcon_Utils_Scws, get_words);
PHP_METHOD(Phalcon_Utils_Scws, version);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_set_charset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_add_dict, 0, 0, 1)
	ZEND_ARG_INFO(0, dictPath)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_set_dict, 0, 0, 1)
	ZEND_ARG_INFO(0, dictPath)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_set_rule, 0, 0, 1)
	ZEND_ARG_INFO(0, rulePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_set_ignore, 0, 0, 1)
	ZEND_ARG_INFO(0, ignore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_set_multi, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_set_duality, 0, 0, 1)
	ZEND_ARG_INFO(0, duality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_send_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_get_tops, 0, 0, 0)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_has_words, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_scws_get_words, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_utils_scws_method_entry){
	PHP_ME(Phalcon_Utils_Scws, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Utils_Scws, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Utils_Scws, set_charset, arginfo_phalcon_utils_scws_set_charset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, add_dict, arginfo_phalcon_utils_scws_add_dict, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, set_path, arginfo_phalcon_utils_scws_set_path, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, set_dict, arginfo_phalcon_utils_scws_set_dict, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, set_rule, arginfo_phalcon_utils_scws_set_rule, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, set_ignore, arginfo_phalcon_utils_scws_set_ignore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, set_multi, arginfo_phalcon_utils_scws_set_multi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, set_duality, arginfo_phalcon_utils_scws_set_duality, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, send_text, arginfo_phalcon_utils_scws_send_text, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, get_result, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, get_tops, arginfo_phalcon_utils_scws_get_tops, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, has_word, arginfo_phalcon_utils_scws_has_word, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, get_words, arginfo_phalcon_utils_scws_get_words, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils_Scws, version, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

struct php_scws
{
	scws_t s;
	zval *zt;
	char charset[8];
	int rsrc_id;
};
