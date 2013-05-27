
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

extern int phalcon_di_use_cache(TSRMLS_DC);

extern int phalcon_di_get_default(zval *return_value TSRMLS_DC);

extern int phalcon_di_get_shared_str(zval *return_value, char *name, int name_length, zval *arguments TSRMLS_DC);
extern int phalcon_di_get_shared(zval *return_value, zval *name, zval *arguments TSRMLS_DC);

extern int phalcon_di_has_str(char *name, int name_length TSRMLS_DC);
extern int phalcon_di_has(zval *name TSRMLS_DC);

extern void phalcon_di_set_shared(zval *service_name, zval *service TSRMLS_DC);