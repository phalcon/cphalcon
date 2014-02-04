
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

#ifndef PHALCON_KERNEL_FILE_H
#define PHALCON_KERNEL_FILE_H

#include "php_phalcon.h"

int phalcon_file_exists(zval *filename TSRMLS_DC);
int phalcon_compare_mtime(zval *filename1, zval *filename2 TSRMLS_DC);
void phalcon_fix_path(zval **return_value, zval *path, zval *directory_separator TSRMLS_DC);
void phalcon_prepare_virtual_path(zval *return_value, zval *path, zval *virtual_separator TSRMLS_DC);
void phalcon_unique_path_key(zval *return_value, zval *path TSRMLS_DC);
void phalcon_realpath(zval *return_value, zval *filename TSRMLS_DC);
void phalcon_file_get_contents(zval *return_value, zval *filename TSRMLS_DC);
void phalcon_file_put_contents(zval *return_value, zval *filename, zval *data TSRMLS_DC);
void phalcon_possible_autoload_filepath(zval *return_value, zval *prefix, zval *class_name, zval *virtual_separator, zval *separator TSRMLS_DC);

void phalcon_is_dir(zval *return_value, zval *path TSRMLS_DC);
void phalcon_unlink(zval *return_value, zval *path TSRMLS_DC);
void phalcon_filemtime(zval *return_value, zval *path TSRMLS_DC);
void phalcon_basename(zval *return_value, zval *path TSRMLS_DC);

void phalcon_prepare_virtual_path_ex(zval *return_value, const char *path, size_t path_len, char virtual_separator TSRMLS_DC);

#endif /* PHALCON_KERNEL_FILE_H */
