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

#ifndef ZEPHIR_KERNEL_BUFFER_H
#define ZEPHIR_KERNEL_BUFFER_H

#include <php.h>
#include <Zend/zend.h>

/**
 * <Namespace>\Buffer -- a fixed-size, contiguous, C-typed numeric buffer,
 * issue #2721.
 *
 * A PHP array of floats costs a zval plus a hash slot per element and can only
 * be handed to a C numeric library by walking it into a scratch buffer and
 * walking the result back out again. Where that pack/unpack happens once per
 * operation it dominates the operation. This class is the place to keep the
 * data between operations instead: the elements live in one `emalloc`'d C
 * array, hand-written C reads and writes them through a raw pointer, and the
 * PHP array is materialised only at the boundary, by toArray().
 *
 * It is an ordinary refcounted zend_object, so it can be held in a Zephir
 * property, passed between methods and garbage collected like anything else.
 *
 * The whole class is compiled out unless the project opts in
 * (ZEPHIR_BUFFER_ENABLED is defined in php_<project>.h by the compiler when
 * `kernel-classes.buffer` is true in config.json).
 */

/* Element kinds. Fixed at construction; a buffer never changes kind. */
#define ZEPHIR_BUFFER_DOUBLE 1
#define ZEPHIR_BUFFER_LONG   2

typedef struct _zephir_buffer_object {
	/* `len` contiguous elements of the kind named by `kind`, or NULL when
	 * len == 0. Never a zval: this is the whole point of the class. */
	union {
		double    *d;
		zend_long *l;
		void      *raw;
	} data;

	zend_long len;
	uint8_t   kind;

	/* MUST stay last: handlers.offset is XtOffsetOf(..., std). */
	zend_object std;
} zephir_buffer_object;

#ifdef ZEPHIR_BUFFER_ENABLED
extern zend_class_entry *zephir_buffer_ce;
#endif

/* Registered in every extension's MINIT (no-op when compiled out). */
void zephir_buffer_module_init(void);

#ifdef ZEPHIR_BUFFER_ENABLED

static inline zephir_buffer_object *zephir_buffer_fetch(zend_object *obj)
{
	return (zephir_buffer_object *) ((char *) obj - XtOffsetOf(zephir_buffer_object, std));
}

#define ZEPHIR_BUFFER_P(zv) zephir_buffer_fetch(Z_OBJ_P(zv))

/* True when `zv` is a Buffer object. The check is a class-entry pointer
 * compare, so it is cheap enough for the kernel array fast paths. */
static inline int zephir_is_buffer(const zval *zv)
{
	return Z_TYPE_P(zv) == IS_OBJECT && Z_OBJCE_P((zval *) zv) == zephir_buffer_ce;
}

/**
 * Creates a zero-filled buffer of `len` elements into `ret`.
 * Returns FAILURE (and throws) for a negative length or an unknown kind.
 */
int zephir_buffer_create(zval *ret, zend_long len, uint8_t kind);

/**
 * Creates a buffer holding the values of `arr` in iteration order. Keys are
 * discarded -- a Buffer is positional. Each value is converted with PHP's own
 * cast, so the result matches `(float)` / `(int)` element for element.
 */
int zephir_buffer_create_from_array(zval *ret, zval *arr, uint8_t kind);

/** Materialises the elements as a packed PHP list into `ret`. */
int zephir_buffer_to_array(zval *ret, const zval *obj);

/** The element kind, or 0 when `obj` is not a Buffer. */
uint8_t zephir_buffer_kind(const zval *obj);

/** The element count, or 0 when `obj` is not a Buffer. */
zend_long zephir_buffer_len(const zval *obj);

/**
 * The raw element pointers. Each returns NULL unless `obj` is a Buffer of
 * that kind -- asking for the wrong one is a NULL, never a silently
 * reinterpreted buffer. NULL is also returned for an empty buffer.
 *
 * This is the extension author's entry point: pass the result straight to
 * cblas_daxpy(), a hand-written loop, or anything else expecting a contiguous
 * array. The pointer stays valid until the buffer is destroyed; buffers are
 * fixed-size, so it is never reallocated.
 */
double    *zephir_buffer_doubles(const zval *obj);
zend_long *zephir_buffer_longs(const zval *obj);

/**
 * Fast paths for kernel/array.c.
 *
 * `buf[i]` in Zephir source compiles to a zephir_array_* call, which would
 * otherwise see an ordinary ArrayAccess object and dispatch a full
 * offsetGet()/offsetSet() method call per element. These do the same work
 * without leaving C, and raise the same diagnostics when the offset is
 * unusable.
 */
int zephir_buffer_dim_read_long(zval *return_value, zval *obj, zend_long index);
int zephir_buffer_dim_read(zval *return_value, zval *obj, zval *offset);
int zephir_buffer_dim_write_long(zval *obj, zend_long index, zval *value);
int zephir_buffer_dim_write(zval *obj, zval *offset, zval *value);
int zephir_buffer_dim_isset_long(const zval *obj, zend_long index);
int zephir_buffer_dim_isset(const zval *obj, zval *offset);

#endif /* ZEPHIR_BUFFER_ENABLED */

#endif /* ZEPHIR_KERNEL_BUFFER_H */
