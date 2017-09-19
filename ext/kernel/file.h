
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_FILE_H
#define ZEPHIR_KERNEL_FILE_H

#include <php.h>

int zephir_file_exists(zval *filename TSRMLS_DC);
int zephir_compare_mtime(zval *filename1, zval *filename2 TSRMLS_DC);
void zephir_fix_path(zval **return_value, zval *path, zval *directory_separator TSRMLS_DC);
void zephir_prepare_virtual_path(zval *return_value, zval *path, zval *virtual_separator TSRMLS_DC);
void zephir_unique_path_key(zval *return_value, zval *path TSRMLS_DC);
void zephir_realpath(zval *return_value, zval *filename TSRMLS_DC);
void zephir_file_get_contents(zval *return_value, zval *filename TSRMLS_DC);
void zephir_file_put_contents(zval *return_value, zval *filename, zval *data TSRMLS_DC);
void zephir_possible_autoload_filepath(zval *return_value, zval *prefix, zval *class_name, zval *virtual_separator, zval *separator TSRMLS_DC);

void zephir_is_dir(zval *return_value, zval *path TSRMLS_DC);
void zephir_unlink(zval *return_value, zval *path TSRMLS_DC);
void zephir_filemtime(zval *return_value, zval *path TSRMLS_DC);
void zephir_basename(zval *return_value, zval *path TSRMLS_DC);

void zephir_fwrite(zval *return_value, zval *stream_zval, zval *data TSRMLS_DC);
int zephir_feof(zval *stream_zval TSRMLS_DC);
int zephir_fclose(zval *stream_zval TSRMLS_DC);

#ifdef TSRM_WIN32
#define ZEPHIR_DIRECTORY_SEPARATOR "\\"
#else
#define ZEPHIR_DIRECTORY_SEPARATOR "/"
#endif

#endif /* ZEPHIR_KERNEL_FILE_H */
