/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_FILE_H
#define ZEPHIR_KERNEL_FILE_H

#include <php.h>

int zephir_file_exists(zval *filename);

void zephir_fwrite(zval *return_value, zval *stream_zval, zval *data);
int zephir_feof(zval *stream_zval);
int zephir_fclose(zval *stream_zval);
void zephir_file_get_contents(zval *return_value, zval *filename);
void zephir_file_put_contents(zval *return_value, zval *filename, zval *data);

void zephir_basename(zval *return_value, zval *path);
void zephir_filemtime(zval *return_value, zval *path);
int zephir_compare_mtime(zval *filename1, zval *filename2);
void zephir_prepare_virtual_path(zval *return_value, zval *path, zval *virtual_separator);
void zephir_unique_path_key(zval *return_value, zval *path);

#ifdef TSRM_WIN32
#define ZEPHIR_DIRECTORY_SEPARATOR "\\"
#else
#define ZEPHIR_DIRECTORY_SEPARATOR "/"
#endif

#endif /* ZEPHIR_KERNEL_FILE_H */
