
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

extern zend_class_entry *phalcon_arr_ce;

PHALCON_INIT_CLASS(Phalcon_Arr);

PHP_METHOD(Phalcon_Arr, is_assoc);
PHP_METHOD(Phalcon_Arr, is_array);
PHP_METHOD(Phalcon_Arr, path);
PHP_METHOD(Phalcon_Arr, set_path);
PHP_METHOD(Phalcon_Arr, range);
PHP_METHOD(Phalcon_Arr, get);
PHP_METHOD(Phalcon_Arr, extract);
PHP_METHOD(Phalcon_Arr, pluck);
PHP_METHOD(Phalcon_Arr, unshift);
PHP_METHOD(Phalcon_Arr, map);
PHP_METHOD(Phalcon_Arr, merge);
PHP_METHOD(Phalcon_Arr, overwrite);
PHP_METHOD(Phalcon_Arr, callback);
PHP_METHOD(Phalcon_Arr, flatten);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_is_assoc, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_is_array, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_path, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, default_value)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_set_path, 0, 0, 3)
	ZEND_ARG_INFO(1, array)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_range, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, max)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_get, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, default_value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_extract, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, default_value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_pluck, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_unshift, 0, 0, 3)
	ZEND_ARG_INFO(1, array)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_map, 0, 0, 2)
	ZEND_ARG_INFO(0, callbacks)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, array1)
	ZEND_ARG_INFO(0, array2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_overwrite, 0, 0, 2)
	ZEND_ARG_INFO(0, array1)
	ZEND_ARG_INFO(0, array2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_callback, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_flatten, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()
PHP_METHOD(Phalcon_Arr, is_assoc);
PHP_METHOD(Phalcon_Arr, is_array);
PHP_METHOD(Phalcon_Arr, path);
PHP_METHOD(Phalcon_Arr, set_path);
PHP_METHOD(Phalcon_Arr, range);
PHP_METHOD(Phalcon_Arr, get);
PHP_METHOD(Phalcon_Arr, extract);
PHP_METHOD(Phalcon_Arr, pluck);
PHP_METHOD(Phalcon_Arr, unshift);
PHP_METHOD(Phalcon_Arr, map);
PHP_METHOD(Phalcon_Arr, merge);
PHP_METHOD(Phalcon_Arr, overwrite);
PHP_METHOD(Phalcon_Arr, callback);
PHP_METHOD(Phalcon_Arr, flatten);

PHALCON_INIT_FUNCS(phalcon_arr_method_entry){
	PHP_ME(Phalcon_Arr, is_assoc, arginfo_phalcon_arr_is_assoc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, is_array, arginfo_phalcon_arr_is_array, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, path, arginfo_phalcon_arr_path, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, set_path, arginfo_phalcon_arr_set_path, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, range, arginfo_phalcon_arr_range, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, get, arginfo_phalcon_arr_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, extract, arginfo_phalcon_arr_extract, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, pluck, arginfo_phalcon_arr_pluck, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, unshift, arginfo_phalcon_arr_unshift, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, map, arginfo_phalcon_arr_map, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, merge, arginfo_phalcon_arr_merge, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, overwrite, arginfo_phalcon_arr_overwrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, callback, arginfo_phalcon_arr_callback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Arr, flatten, arginfo_phalcon_arr_flatten, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};

