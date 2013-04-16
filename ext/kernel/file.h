
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

extern int phalcon_file_exists(zval *filename TSRMLS_DC);
extern int phalcon_compare_mtime(zval *filename1, zval *filename2 TSRMLS_DC);
extern void phalcon_fix_path(zval **return_value, zval *path, zval *directory_separator TSRMLS_DC);
extern void phalcon_prepare_virtual_path(zval *return_value, zval *path, zval *virtual_separator TSRMLS_DC);
extern void phalcon_unique_path_key(zval *return_value, zval *path TSRMLS_DC);
extern void phalcon_realpath(zval *return_value, zval *filename TSRMLS_DC);