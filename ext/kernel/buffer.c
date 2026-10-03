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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_ext.h"
#include "kernel/buffer.h"

#ifndef ZEPHIR_BUFFER_ENABLED

/* The project did not opt in: the class is compiled out and MINIT
 * registration is a no-op. */
void zephir_buffer_module_init(void) {}

#else

#ifndef ZEPHIR_BUFFER_NAMESPACE
#error "ZEPHIR_BUFFER_NAMESPACE must be defined together with ZEPHIR_BUFFER_ENABLED"
#endif

#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_array.h>
#include <ext/spl/spl_exceptions.h>

/* Unconditional on purpose. ext/json cannot be disabled in PHP 8, and gating
 * JsonSerializable on a build-time probe would mean json_encode() silently
 * emitting `{}` and dropping every element wherever the probe happened to
 * fail. kernel/string.c's ZEPHIR_USE_PHP_JSON gate is about an optional
 * *optimisation*; this is about not losing data. */
#include <ext/json/php_json.h>

/* zend_object_count_elements_t returned `int` up to PHP 8.1 and `zend_result`
 * from 8.2. The two are different types, so the handler has to be declared
 * with whichever one this build expects. */
#if PHP_VERSION_ID >= 80200
# define ZEPHIR_BUFFER_COUNT_RESULT zend_result
#else
# define ZEPHIR_BUFFER_COUNT_RESULT int
#endif

zend_class_entry *zephir_buffer_ce;

static zend_object_handlers zephir_buffer_object_handlers;

/* ---------------------------------------------------------------- storage */

static zend_always_inline size_t zephir_buffer_elem_size(uint8_t kind)
{
	return kind == ZEPHIR_BUFFER_LONG ? sizeof(zend_long) : sizeof(double);
}

static zend_always_inline int zephir_buffer_kind_is_valid(uint8_t kind)
{
	return kind == ZEPHIR_BUFFER_DOUBLE || kind == ZEPHIR_BUFFER_LONG;
}

/**
 * (Re)allocates the element array, zero-filled.
 *
 * All-bits-zero is 0.0 for an IEEE 754 double and 0 for a zend_long, so one
 * ecalloc covers both kinds.
 */
static int zephir_buffer_alloc(zephir_buffer_object *b, zend_long len, uint8_t kind)
{
	if (b->data.raw) {
		efree(b->data.raw);
		b->data.raw = NULL;
	}

	b->kind = kind;
	b->len  = len;

	if (len > 0) {
		b->data.raw = ecalloc((size_t) len, zephir_buffer_elem_size(kind));
	}

	return SUCCESS;
}

static zend_always_inline void zephir_buffer_get(const zephir_buffer_object *b, zend_long index, zval *rv)
{
	if (b->kind == ZEPHIR_BUFFER_LONG) {
		ZVAL_LONG(rv, b->data.l[index]);
	} else {
		ZVAL_DOUBLE(rv, b->data.d[index]);
	}
}

/**
 * Stores `value` at `index`, converted with the engine's own cast, so an
 * element ends up holding exactly what `(float)` / `(int)` would have produced.
 */
static zend_always_inline void zephir_buffer_put(zephir_buffer_object *b, zend_long index, zval *value)
{
	if (b->kind == ZEPHIR_BUFFER_LONG) {
		b->data.l[index] = zval_get_long(value);
	} else {
		b->data.d[index] = zval_get_double(value);
	}
}

static zend_always_inline int zephir_buffer_in_range(const zephir_buffer_object *b, zend_long index)
{
	/* One compare: a negative index wraps to a huge unsigned value. */
	return (zend_ulong) index < (zend_ulong) b->len;
}

/* ------------------------------------------------------------- diagnostics */

/**
 * php-src moved this from RuntimeException to OutOfBoundsException in 8.4
 * (OutOfBoundsException extends RuntimeException, so catching the older one
 * still works). Follow it, so a Buffer raises on each version whatever
 * SplFixedArray raises there.
 */
static ZEND_COLD void zephir_buffer_throw_out_of_range(void)
{
#if PHP_VERSION_ID >= 80400
	zend_throw_exception(spl_ce_OutOfBoundsException, "Index invalid or out of range", 0);
#else
	zend_throw_exception(spl_ce_RuntimeException, "Index invalid or out of range", 0);
#endif
}

/**
 * Converts an arbitrary offset zval to an index, following php-src's own
 * spl_offset_convert_to_long() -- including the three regimes its failure
 * branch went through:
 *
 *   8.0        no type check at all; an unusable offset became -1 and was
 *              reported by the range check
 *   8.1, 8.2   TypeError, "Illegal offset type"
 *   8.3+       TypeError naming the container and the offset type
 *
 * On failure from 8.1 up an exception is pending, so callers must check
 * EG(exception) before using the result. php-src reports BP_VAR_R here even
 * from isset(), so do the same rather than varying the message by context.
 */
static zend_long zephir_buffer_offset_to_long(zval *offset)
{
	zend_ulong idx;

try_again:
	switch (Z_TYPE_P(offset)) {
		case IS_STRING:
			if (ZEND_HANDLE_NUMERIC(Z_STR_P(offset), idx)) {
				return (zend_long) idx;
			}
			break;

		case IS_DOUBLE:
#if PHP_VERSION_ID >= 80100
			return zend_dval_to_lval_safe(Z_DVAL_P(offset));
#else
			return zend_dval_to_lval(Z_DVAL_P(offset));
#endif

		case IS_LONG:
			return Z_LVAL_P(offset);

		case IS_FALSE:
			return 0;

		case IS_TRUE:
			return 1;

		case IS_REFERENCE:
			offset = Z_REFVAL_P(offset);
			goto try_again;

		case IS_RESOURCE:
#if PHP_VERSION_ID >= 80100
			zend_use_resource_as_offset(offset);
#endif
			return Z_RES_HANDLE_P(offset);
	}

#if PHP_VERSION_ID >= 80300
	zend_illegal_container_offset(zephir_buffer_ce->name, offset, BP_VAR_R);
	return 0;
#elif PHP_VERSION_ID >= 80100
	zend_type_error("Illegal offset type");
	return 0;
#else
	return -1;
#endif
}

/**
 * Resolves an offset to an in-range index, or returns FAILURE with an
 * exception pending.
 */
static int zephir_buffer_resolve(const zephir_buffer_object *b, zval *offset, zend_long *index)
{
	zend_long resolved = zephir_buffer_offset_to_long(offset);

	if (EG(exception)) {
		return FAILURE;
	}

	if (!zephir_buffer_in_range(b, resolved)) {
		zephir_buffer_throw_out_of_range();
		return FAILURE;
	}

	*index = resolved;

	return SUCCESS;
}

/* ----------------------------------------------------------------- object */

static zend_object *zephir_buffer_create_object(zend_class_entry *ce)
{
	zephir_buffer_object *b = zend_object_alloc(sizeof(zephir_buffer_object), ce);

	b->data.raw = NULL;
	b->len      = 0;
	b->kind     = ZEPHIR_BUFFER_DOUBLE;

	zend_object_std_init(&b->std, ce);
	object_properties_init(&b->std, ce);
	b->std.handlers = &zephir_buffer_object_handlers;

	return &b->std;
}

static void zephir_buffer_free_object(zend_object *object)
{
	zephir_buffer_object *b = zephir_buffer_fetch(object);

	if (b->data.raw) {
		efree(b->data.raw);
		b->data.raw = NULL;
	}

	zend_object_std_dtor(&b->std);
}

static zend_object *zephir_buffer_clone_object(zend_object *object)
{
	zephir_buffer_object *source = zephir_buffer_fetch(object);
	zend_object          *cloned = zephir_buffer_create_object(object->ce);
	zephir_buffer_object *copy   = zephir_buffer_fetch(cloned);

	copy->kind = source->kind;
	copy->len  = source->len;

	if (source->len > 0) {
		size_t bytes = (size_t) source->len * zephir_buffer_elem_size(source->kind);

		copy->data.raw = emalloc(bytes);
		memcpy(copy->data.raw, source->data.raw, bytes);
	}

	zend_objects_clone_members(cloned, object);

	return cloned;
}

/* Without this var_dump()/print_r() would show an object with no state at all,
 * because the elements are not properties. */
static HashTable *zephir_buffer_get_debug_info(zend_object *object, int *is_temp)
{
	zephir_buffer_object *b = zephir_buffer_fetch(object);
	HashTable            *info;
	zend_long             i;

	ALLOC_HASHTABLE(info);
	zend_hash_init(info, (uint32_t) (b->len > 0 ? b->len : 0), NULL, ZVAL_PTR_DTOR, 0);

	for (i = 0; i < b->len; ++i) {
		zval element;

		zephir_buffer_get(b, i, &element);
		zend_hash_index_update(info, (zend_ulong) i, &element);
	}

	*is_temp = 1;

	return info;
}

static ZEPHIR_BUFFER_COUNT_RESULT zephir_buffer_count_elements(zend_object *object, zend_long *count)
{
	*count = zephir_buffer_fetch(object)->len;

	return SUCCESS;
}

/* ------------------------------------------------------------- dimensions */

static int zephir_buffer_has_dimension(zend_object *object, zval *offset, int check_empty);

/**
 * `$buffer[$i]`.
 *
 * The value is returned in `rv`, never as a pointer into the buffer -- the
 * elements are raw C scalars, not zvals, so there is nothing to point at.
 *
 * That does not stop compound assignment. The engine implements `$buffer[0]
 * += 1` on an object as a read followed by a write, so it arrives here and
 * then at zephir_buffer_write_dimension() and behaves normally. What cannot
 * work is anything needing a reference to the element -- `$buffer[0]++`,
 * `$r =& $buffer[0]`, passing it to a by-reference parameter. The engine
 * raises its standard "Indirect modification of overloaded element" notice for
 * those and the write has no effect, exactly as it does for any ArrayAccess
 * object that does not hand back a reference.
 */
static zval *zephir_buffer_read_dimension(zend_object *object, zval *offset, int type, zval *rv)
{
	zephir_buffer_object *b = zephir_buffer_fetch(object);
	zend_long             index;

	/* `$buffer[$i] ?? $default` must not raise for a merely absent index --
	 * but an offset of an unusable *type* still does, as it does for
	 * SplFixedArray. */
	if (type == BP_VAR_IS && !zephir_buffer_has_dimension(object, offset, 0)) {
		return &EG(uninitialized_zval);
	}

	if (!offset) {
		zend_throw_error(NULL, "Cannot use [] for reading");
		return NULL;
	}

	if (zephir_buffer_resolve(b, offset, &index) == FAILURE) {
		return NULL;
	}

	zephir_buffer_get(b, index, rv);

	return rv;
}

static void zephir_buffer_write_dimension(zend_object *object, zval *offset, zval *value)
{
	zephir_buffer_object *b = zephir_buffer_fetch(object);
	zend_long             index;

	if (!offset) {
		/* `$buffer[] = v`. A Buffer is fixed-size, so there is nothing to
		 * append to. php-src changed SplFixedArray's report here in 8.1. */
#if PHP_VERSION_ID >= 80100
		zend_throw_error(NULL, "[] operator not supported for %s", ZSTR_VAL(object->ce->name));
#else
		zephir_buffer_throw_out_of_range();
#endif
		return;
	}

	if (zephir_buffer_resolve(b, offset, &index) == FAILURE) {
		return;
	}

	zephir_buffer_put(b, index, value);
}

static int zephir_buffer_has_dimension(zend_object *object, zval *offset, int check_empty)
{
	zephir_buffer_object *b = zephir_buffer_fetch(object);
	zend_long             index;
	zval                  element;

	index = zephir_buffer_offset_to_long(offset);

	if (EG(exception)) {
		return 0;
	}

	if (!zephir_buffer_in_range(b, index)) {
		return 0;
	}

	/* Every in-range element is set. A Buffer holds numbers, so unlike
	 * SplFixedArray -- whose slots start out null, and where isset() is
	 * therefore false on a freshly constructed one -- there is no element
	 * value that isset() reports as absent. */
	if (!check_empty) {
		return 1;
	}

	zephir_buffer_get(b, index, &element);

	return zend_is_true(&element);
}

/* A numeric buffer cannot hold null, so unset() writes the zero element. */
static void zephir_buffer_unset_dimension(zend_object *object, zval *offset)
{
	zephir_buffer_object *b = zephir_buffer_fetch(object);
	zend_long             index;

	if (zephir_buffer_resolve(b, offset, &index) == FAILURE) {
		return;
	}

	if (b->kind == ZEPHIR_BUFFER_LONG) {
		b->data.l[index] = 0;
	} else {
		b->data.d[index] = 0.0;
	}
}

/* -------------------------------------------------------------- C-side API */

int zephir_buffer_create(zval *ret, zend_long len, uint8_t kind)
{
	zephir_buffer_object *b;

	if (!zephir_buffer_kind_is_valid(kind) || len < 0) {
		ZVAL_NULL(ret);

		return FAILURE;
	}

	object_init_ex(ret, zephir_buffer_ce);
	b = ZEPHIR_BUFFER_P(ret);

	return zephir_buffer_alloc(b, len, kind);
}

int zephir_buffer_create_from_array(zval *ret, zval *arr, uint8_t kind)
{
	zephir_buffer_object *b;
	zval                 *value;
	zend_long             i = 0;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		ZVAL_NULL(ret);

		return FAILURE;
	}

	if (zephir_buffer_create(ret, (zend_long) zend_hash_num_elements(Z_ARRVAL_P(arr)), kind) == FAILURE) {
		return FAILURE;
	}

	b = ZEPHIR_BUFFER_P(ret);

	/* Positional: the keys of the source array are discarded, the values are
	 * taken in iteration order. */
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(arr), value) {
		zephir_buffer_put(b, i++, value);
	} ZEND_HASH_FOREACH_END();

	return SUCCESS;
}

int zephir_buffer_to_array(zval *ret, const zval *obj)
{
	zephir_buffer_object *b;
	zend_long             i;

	if (!zephir_is_buffer(obj)) {
		ZVAL_NULL(ret);

		return FAILURE;
	}

	b = ZEPHIR_BUFFER_P((zval *) obj);

	array_init_size(ret, (uint32_t) (b->len > 0 ? b->len : 0));

	for (i = 0; i < b->len; ++i) {
		if (b->kind == ZEPHIR_BUFFER_LONG) {
			add_next_index_long(ret, b->data.l[i]);
		} else {
			add_next_index_double(ret, b->data.d[i]);
		}
	}

	return SUCCESS;
}

uint8_t zephir_buffer_kind(const zval *obj)
{
	return zephir_is_buffer(obj) ? ZEPHIR_BUFFER_P((zval *) obj)->kind : 0;
}

zend_long zephir_buffer_len(const zval *obj)
{
	return zephir_is_buffer(obj) ? ZEPHIR_BUFFER_P((zval *) obj)->len : 0;
}

double *zephir_buffer_doubles(const zval *obj)
{
	zephir_buffer_object *b;

	if (!zephir_is_buffer(obj)) {
		return NULL;
	}

	b = ZEPHIR_BUFFER_P((zval *) obj);

	return b->kind == ZEPHIR_BUFFER_DOUBLE ? b->data.d : NULL;
}

zend_long *zephir_buffer_longs(const zval *obj)
{
	zephir_buffer_object *b;

	if (!zephir_is_buffer(obj)) {
		return NULL;
	}

	b = ZEPHIR_BUFFER_P((zval *) obj);

	return b->kind == ZEPHIR_BUFFER_LONG ? b->data.l : NULL;
}

/* ------------------------------------------------ kernel/array.c fast paths */

int zephir_buffer_dim_read_long(zval *return_value, zval *obj, zend_long index)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(obj);

	if (UNEXPECTED(!zephir_buffer_in_range(b, index))) {
		zephir_buffer_throw_out_of_range();
		ZVAL_NULL(return_value);

		return FAILURE;
	}

	zephir_buffer_get(b, index, return_value);

	return SUCCESS;
}

int zephir_buffer_dim_read(zval *return_value, zval *obj, zval *offset)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(obj);
	zend_long             index;

	if (UNEXPECTED(zephir_buffer_resolve(b, offset, &index) == FAILURE)) {
		ZVAL_NULL(return_value);

		return FAILURE;
	}

	zephir_buffer_get(b, index, return_value);

	return SUCCESS;
}

int zephir_buffer_dim_write_long(zval *obj, zend_long index, zval *value)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(obj);

	if (UNEXPECTED(!zephir_buffer_in_range(b, index))) {
		zephir_buffer_throw_out_of_range();

		return FAILURE;
	}

	zephir_buffer_put(b, index, value);

	return SUCCESS;
}

int zephir_buffer_dim_write(zval *obj, zval *offset, zval *value)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(obj);
	zend_long             index;

	if (UNEXPECTED(zephir_buffer_resolve(b, offset, &index) == FAILURE)) {
		return FAILURE;
	}

	zephir_buffer_put(b, index, value);

	return SUCCESS;
}

int zephir_buffer_dim_isset_long(const zval *obj, zend_long index)
{
	return zephir_buffer_in_range(ZEPHIR_BUFFER_P((zval *) obj), index);
}

int zephir_buffer_dim_isset(const zval *obj, zval *offset)
{
	return zephir_buffer_has_dimension(Z_OBJ_P((zval *) obj), offset, 0);
}

/* ---------------------------------------------------------------- methods */

PHP_METHOD(ZephirBuffer, __construct)
{
	zephir_buffer_object *b    = ZEPHIR_BUFFER_P(getThis());
	zend_long             size;
	zend_long             type = ZEPHIR_BUFFER_DOUBLE;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(size)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();

	if (size < 0) {
		zend_argument_value_error(1, "must be greater than or equal to 0");
		RETURN_THROWS();
	}

	if (!zephir_buffer_kind_is_valid((uint8_t) type)) {
		zend_argument_value_error(2, "must be Buffer::TYPE_DOUBLE or Buffer::TYPE_LONG");
		RETURN_THROWS();
	}

	zephir_buffer_alloc(b, size, (uint8_t) type);
}

PHP_METHOD(ZephirBuffer, fromArray)
{
	zval      *values;
	zend_long  type = ZEPHIR_BUFFER_DOUBLE;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();

	if (!zephir_buffer_kind_is_valid((uint8_t) type)) {
		zend_argument_value_error(2, "must be Buffer::TYPE_DOUBLE or Buffer::TYPE_LONG");
		RETURN_THROWS();
	}

	zephir_buffer_create_from_array(return_value, values, (uint8_t) type);
}

PHP_METHOD(ZephirBuffer, toArray)
{
	ZEND_PARSE_PARAMETERS_NONE();

	zephir_buffer_to_array(return_value, getThis());
}

PHP_METHOD(ZephirBuffer, type)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(ZEPHIR_BUFFER_P(getThis())->kind);
}

PHP_METHOD(ZephirBuffer, count)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(ZEPHIR_BUFFER_P(getThis())->len);
}

PHP_METHOD(ZephirBuffer, fill)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(getThis());
	zval                 *value;
	zend_long             i;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

	if (b->kind == ZEPHIR_BUFFER_LONG) {
		zend_long converted = zval_get_long(value);

		for (i = 0; i < b->len; ++i) {
			b->data.l[i] = converted;
		}
	} else {
		double converted = zval_get_double(value);

		for (i = 0; i < b->len; ++i) {
			b->data.d[i] = converted;
		}
	}
}

PHP_METHOD(ZephirBuffer, offsetExists)
{
	zval *offset;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(zephir_buffer_has_dimension(Z_OBJ_P(getThis()), offset, 0));
}

PHP_METHOD(ZephirBuffer, offsetGet)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(getThis());
	zval                 *offset;
	zend_long             index;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();

	if (zephir_buffer_resolve(b, offset, &index) == FAILURE) {
		RETURN_THROWS();
	}

	zephir_buffer_get(b, index, return_value);
}

PHP_METHOD(ZephirBuffer, offsetSet)
{
	zval *offset;
	zval *value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

	zephir_buffer_write_dimension(Z_OBJ_P(getThis()), offset, value);
}

PHP_METHOD(ZephirBuffer, offsetUnset)
{
	zval *offset;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();

	zephir_buffer_unset_dimension(Z_OBJ_P(getThis()), offset);
}

/**
 * foreach materialises the elements. A Buffer exists so that hot loops happen
 * in C over the raw pointer; iterating one element at a time through the VM is
 * the slow path by definition, so it is not worth a lazy iterator.
 */
PHP_METHOD(ZephirBuffer, getIterator)
{
	zval elements;

	ZEND_PARSE_PARAMETERS_NONE();

	zephir_buffer_to_array(&elements, getThis());

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zend_call_method_with_1_params(
		Z_OBJ_P(return_value), spl_ce_ArrayIterator, NULL, "__construct", NULL, &elements);

	zval_ptr_dtor(&elements);
}

/* Without this json_encode() would serialise an object with no properties as
 * `{}` and drop every element. */
PHP_METHOD(ZephirBuffer, jsonSerialize)
{
	ZEND_PARSE_PARAMETERS_NONE();

	zephir_buffer_to_array(return_value, getThis());
}

PHP_METHOD(ZephirBuffer, __serialize)
{
	zval elements;

	ZEND_PARSE_PARAMETERS_NONE();

	zephir_buffer_to_array(&elements, getThis());

	array_init_size(return_value, 2);
	add_next_index_long(return_value, ZEPHIR_BUFFER_P(getThis())->kind);
	add_next_index_zval(return_value, &elements);
}

PHP_METHOD(ZephirBuffer, __unserialize)
{
	zephir_buffer_object *b = ZEPHIR_BUFFER_P(getThis());
	zval                 *payload;
	zval                 *kind;
	zval                 *elements;
	zval                 *value;
	zend_long             i = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(payload)
	ZEND_PARSE_PARAMETERS_END();

	kind     = zend_hash_index_find(Z_ARRVAL_P(payload), 0);
	elements = zend_hash_index_find(Z_ARRVAL_P(payload), 1);

	if (!kind || Z_TYPE_P(kind) != IS_LONG || !elements || Z_TYPE_P(elements) != IS_ARRAY
		|| !zephir_buffer_kind_is_valid((uint8_t) Z_LVAL_P(kind))) {
		zend_throw_exception_ex(NULL, 0, "Invalid serialization data for %s object",
			ZSTR_VAL(zephir_buffer_ce->name));
		RETURN_THROWS();
	}

	zephir_buffer_alloc(b, (zend_long) zend_hash_num_elements(Z_ARRVAL_P(elements)),
		(uint8_t) Z_LVAL_P(kind));

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(elements), value) {
		zephir_buffer_put(b, i++, value);
	} ZEND_HASH_FOREACH_END();
}

/* ------------------------------------------------------------- class init */

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephir_buffer_construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephir_buffer_from_array, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, values, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_to_array, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_long, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_fill, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_offset_exists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_offset_get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_offset_set, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_offset_unset, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zephir_buffer_get_iterator, 0, 0, Traversable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_json_serialize, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_serialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_buffer_unserialize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry zephir_buffer_methods[] = {
	PHP_ME(ZephirBuffer, __construct,   arginfo_zephir_buffer_construct,      ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(ZephirBuffer, fromArray,     arginfo_zephir_buffer_from_array,     ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(ZephirBuffer, toArray,       arginfo_zephir_buffer_to_array,       ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, type,          arginfo_zephir_buffer_long,           ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, count,         arginfo_zephir_buffer_long,           ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, fill,          arginfo_zephir_buffer_fill,           ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, offsetExists,  arginfo_zephir_buffer_offset_exists,  ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, offsetGet,     arginfo_zephir_buffer_offset_get,     ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, offsetSet,     arginfo_zephir_buffer_offset_set,     ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, offsetUnset,   arginfo_zephir_buffer_offset_unset,   ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, getIterator,   arginfo_zephir_buffer_get_iterator,   ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, jsonSerialize, arginfo_zephir_buffer_json_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, __serialize,   arginfo_zephir_buffer_serialize,      ZEND_ACC_PUBLIC)
	PHP_ME(ZephirBuffer, __unserialize, arginfo_zephir_buffer_unserialize,    ZEND_ACC_PUBLIC)
	PHP_FE_END
};

void zephir_buffer_module_init(void)
{
	zend_class_entry ce;

	INIT_NS_CLASS_ENTRY(ce, ZEPHIR_BUFFER_NAMESPACE, "Buffer", zephir_buffer_methods);
	zephir_buffer_ce = zend_register_internal_class(&ce);
	zephir_buffer_ce->ce_flags |= ZEND_ACC_FINAL | ZEND_ACC_NO_DYNAMIC_PROPERTIES;
	zephir_buffer_ce->create_object = zephir_buffer_create_object;

	zend_declare_class_constant_long(zephir_buffer_ce, ZEND_STRL("TYPE_DOUBLE"), ZEPHIR_BUFFER_DOUBLE);
	zend_declare_class_constant_long(zephir_buffer_ce, ZEND_STRL("TYPE_LONG"), ZEPHIR_BUFFER_LONG);

	memcpy(&zephir_buffer_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	zephir_buffer_object_handlers.offset           = XtOffsetOf(zephir_buffer_object, std);
	zephir_buffer_object_handlers.free_obj         = zephir_buffer_free_object;
	zephir_buffer_object_handlers.clone_obj        = zephir_buffer_clone_object;
	zephir_buffer_object_handlers.get_debug_info   = zephir_buffer_get_debug_info;
	zephir_buffer_object_handlers.count_elements   = zephir_buffer_count_elements;
	zephir_buffer_object_handlers.read_dimension   = zephir_buffer_read_dimension;
	zephir_buffer_object_handlers.write_dimension  = zephir_buffer_write_dimension;
	zephir_buffer_object_handlers.has_dimension    = zephir_buffer_has_dimension;
	zephir_buffer_object_handlers.unset_dimension  = zephir_buffer_unset_dimension;

	zend_class_implements(zephir_buffer_ce, 4,
		zend_ce_arrayaccess, zend_ce_countable, zend_ce_aggregate, php_json_serializable_ce);
}

#endif /* ZEPHIR_BUFFER_ENABLED */
