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

#include "php.h"
#include "php_ext.h"

#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/generator.h"

#ifndef ZEPHIR_GENERATOR_ENABLED

/* The project contains no generator methods: the runtime is compiled out and
 * MINIT registration is a no-op. */
void zephir_generator_module_init(void) {}

#else

#ifndef ZEPHIR_GENERATOR_NAMESPACE
#error "ZEPHIR_GENERATOR_NAMESPACE must be defined together with ZEPHIR_GENERATOR_ENABLED"
#endif

zend_class_entry *zephir_generator_ce;

static zend_object_handlers zephir_generator_object_handlers;

/* ---------------------------------------------------------------- object */

static zend_object *zephir_generator_create_object(zend_class_entry *ce)
{
	zephir_generator_object *g = zend_object_alloc(sizeof(zephir_generator_object), ce);

	g->state         = 0;
	g->started       = 0;
	g->advanced      = 0;
	g->running       = 0;
	g->step          = NULL;
	g->scope         = NULL;
	g->next_auto_key = 0;
	g->n_slots       = 0;
	g->slots         = NULL;
	ZVAL_UNDEF(&g->bound_this);
	ZVAL_UNDEF(&g->current);
	ZVAL_UNDEF(&g->key);
	ZVAL_UNDEF(&g->retval);

	zend_object_std_init(&g->std, ce);
	object_properties_init(&g->std, ce);
	g->std.handlers = &zephir_generator_object_handlers;

	return &g->std;
}

static void zephir_generator_free_object(zend_object *object)
{
	zephir_generator_object *g = zephir_generator_fetch(object);
	uint32_t i;

	zval_ptr_dtor(&g->bound_this);
	zval_ptr_dtor(&g->current);
	zval_ptr_dtor(&g->key);
	zval_ptr_dtor(&g->retval);

	for (i = 0; i < g->n_slots; ++i) {
		zval_ptr_dtor(&g->slots[i]);
	}
	if (g->slots) {
		efree(g->slots);
	}

	zend_object_std_dtor(&g->std);
}

static HashTable *zephir_generator_get_gc(zend_object *object, zval **table, int *n)
{
	zephir_generator_object *g = zephir_generator_fetch(object);
	zend_get_gc_buffer *gc_buffer = zend_get_gc_buffer_create();
	uint32_t i;

	zend_get_gc_buffer_add_zval(gc_buffer, &g->bound_this);
	zend_get_gc_buffer_add_zval(gc_buffer, &g->current);
	zend_get_gc_buffer_add_zval(gc_buffer, &g->key);
	zend_get_gc_buffer_add_zval(gc_buffer, &g->retval);
	for (i = 0; i < g->n_slots; ++i) {
		zend_get_gc_buffer_add_zval(gc_buffer, &g->slots[i]);
	}
	zend_get_gc_buffer_use(gc_buffer, table, n);

	return NULL;
}

/* ------------------------------------------------------------- execution */

static void zephir_generator_close(zephir_generator_object *g)
{
	g->state = -1;
	zval_ptr_dtor(&g->current);
	zval_ptr_dtor(&g->key);
	ZVAL_UNDEF(&g->current);
	ZVAL_UNDEF(&g->key);
}

/* Enter (or resume) the step function once. On return the generator is
 * either suspended at the next yield, finished cleanly, or closed by an
 * exception now propagating in EG(exception). */
static void zephir_generator_run(zephir_generator_object *g)
{
	zval rv, genzv;
	const zend_class_entry *old_fake_scope;

	if (g->state < 0 || g->step == NULL) {
		return;
	}
	if (g->running) {
		zend_throw_error(NULL, "Cannot resume an already running generator");
		return;
	}

	g->started = 1;
	g->running = 1;

	ZVAL_UNDEF(&rv);
	ZVAL_OBJ(&genzv, &g->std); /* borrowed reference */

	old_fake_scope = EG(fake_scope);
	EG(fake_scope) = g->scope;

	g->step(0, EG(current_execute_data), &rv,
		Z_TYPE(g->bound_this) == IS_OBJECT ? &g->bound_this : NULL, 0, &genzv);

	EG(fake_scope) = (zend_class_entry *) old_fake_scope;
	g->running = 0;

	zval_ptr_dtor(&rv);

	if (EG(exception)) {
		/* PHP closes a generator whose body throws. */
		zephir_generator_close(g);
	}
}

static void zephir_generator_ensure_started(zephir_generator_object *g)
{
	if (!g->started && g->state == 0) {
		zephir_generator_run(g);
	}
}

static void zephir_generator_resume(zephir_generator_object *g)
{
	if (!g->started) {
		/* next()/send() on a fresh generator primes it first, then resumes. */
		zephir_generator_run(g);
		if (EG(exception) || g->state <= 0) {
			return;
		}
	}
	if (g->state > 0) {
		g->advanced = 1;
		zephir_generator_run(g);
	}
}

/* -------------------------------------------------------------- creator */

void zephir_generator_create(zval *return_value, zval *bound_this, zend_class_entry *scope,
	zephir_generator_step_fn step, uint32_t n_params)
{
	zephir_generator_object *g;

	object_init_ex(return_value, zephir_generator_ce);
	g = ZEPHIR_GENERATOR_P(return_value);

	g->step  = step;
	g->scope = scope;
	if (bound_this != NULL && Z_TYPE_P(bound_this) == IS_OBJECT) {
		ZVAL_COPY(&g->bound_this, bound_this);
	}
	if (n_params > 0) {
		zephir_generator_slots_ensure(return_value, n_params);
	}
}

/* ------------------------------------------------------ suspension slots */

zend_long zephir_generator_get_state(zval *gen)
{
	return ZEPHIR_GENERATOR_P(gen)->state;
}

void zephir_generator_slots_ensure(zval *gen, uint32_t n)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(gen);
	uint32_t i;

	if (n <= g->n_slots) {
		return;
	}
	g->slots = g->slots
		? safe_erealloc(g->slots, n, sizeof(zval), 0)
		: safe_emalloc(n, sizeof(zval), 0);
	for (i = g->n_slots; i < n; ++i) {
		ZVAL_UNDEF(&g->slots[i]);
	}
	g->n_slots = n;
}

void zephir_generator_slot_set(zval *gen, uint32_t i, zval *value)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(gen);

	ZEND_ASSERT(i < g->n_slots);
	zval_ptr_dtor(&g->slots[i]);
	if (value != NULL && Z_TYPE_P(value) != IS_UNDEF) {
		ZVAL_COPY(&g->slots[i], value);
	} else {
		ZVAL_UNDEF(&g->slots[i]);
	}
}

void zephir_generator_slot_set_long(zval *gen, uint32_t i, zend_long value)
{
	zval tmp;
	ZVAL_LONG(&tmp, value);
	zephir_generator_slot_set(gen, i, &tmp);
}

void zephir_generator_slot_set_double(zval *gen, uint32_t i, double value)
{
	zval tmp;
	ZVAL_DOUBLE(&tmp, value);
	zephir_generator_slot_set(gen, i, &tmp);
}

void zephir_generator_slot_set_bool(zval *gen, uint32_t i, int value)
{
	zval tmp;
	ZVAL_BOOL(&tmp, value);
	zephir_generator_slot_set(gen, i, &tmp);
}

void zephir_generator_slot_set_str(zval *gen, uint32_t i, zend_string *value)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(gen);

	ZEND_ASSERT(i < g->n_slots);
	zval_ptr_dtor(&g->slots[i]);
	if (value != NULL) {
		ZVAL_STR_COPY(&g->slots[i], value);
	} else {
		ZVAL_NULL(&g->slots[i]);
	}
}

zval *zephir_generator_slot(zval *gen, uint32_t i)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(gen);

	ZEND_ASSERT(i < g->n_slots);
	return &g->slots[i];
}

/* ------------------------------------------------------- yield / finish */

void zephir_generator_yield(zval *gen, zval *key_or_null, zval *value_or_null, zend_long state)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(gen);

	zval_ptr_dtor(&g->current);
	zval_ptr_dtor(&g->key);

	if (value_or_null != NULL) {
		ZVAL_COPY(&g->current, value_or_null);
	} else {
		ZVAL_NULL(&g->current);
	}

	if (key_or_null != NULL) {
		ZVAL_COPY(&g->key, key_or_null);
		/* PHP array-append semantics: an explicit int key bumps the counter. */
		if (Z_TYPE_P(key_or_null) == IS_LONG && Z_LVAL_P(key_or_null) >= g->next_auto_key) {
			g->next_auto_key = Z_LVAL_P(key_or_null) + 1;
		}
	} else {
		ZVAL_LONG(&g->key, g->next_auto_key);
		g->next_auto_key++;
	}

	g->state = state;
}

void zephir_generator_finish(zval *gen, zval *retval_or_null)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(gen);

	zval_ptr_dtor(&g->retval);
	if (retval_or_null != NULL) {
		ZVAL_COPY(&g->retval, retval_or_null);
	} else {
		ZVAL_NULL(&g->retval);
	}
	zephir_generator_close(g);
}

/* --------------------------------------------------------- PHP methods */

PHP_METHOD(ZephirGenerator, rewind)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());

	ZEND_PARSE_PARAMETERS_NONE();

	if (!g->started) {
		zephir_generator_ensure_started(g);
		return;
	}
	if (g->advanced || g->state < 0) {
		zend_throw_exception(NULL, "Cannot rewind a generator that was already run", 0);
	}
}

PHP_METHOD(ZephirGenerator, valid)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());

	ZEND_PARSE_PARAMETERS_NONE();

	zephir_generator_ensure_started(g);
	RETURN_BOOL(g->state > 0);
}

PHP_METHOD(ZephirGenerator, current)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());

	ZEND_PARSE_PARAMETERS_NONE();

	zephir_generator_ensure_started(g);
	if (g->state > 0 && Z_TYPE(g->current) != IS_UNDEF) {
		RETURN_COPY(&g->current);
	}
	RETURN_NULL();
}

PHP_METHOD(ZephirGenerator, key)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());

	ZEND_PARSE_PARAMETERS_NONE();

	zephir_generator_ensure_started(g);
	if (g->state > 0 && Z_TYPE(g->key) != IS_UNDEF) {
		RETURN_COPY(&g->key);
	}
	RETURN_NULL();
}

PHP_METHOD(ZephirGenerator, next)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());

	ZEND_PARSE_PARAMETERS_NONE();

	zephir_generator_resume(g);
}

PHP_METHOD(ZephirGenerator, send)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());
	zval *value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

	/* Zephir's grammar has no yield-expressions, so a sent value can never
	 * be observed by the generator body; send() is resume-and-fetch. */
	(void) value;

	zephir_generator_resume(g);
	if (EG(exception)) {
		return;
	}
	if (g->state > 0 && Z_TYPE(g->current) != IS_UNDEF) {
		RETURN_COPY(&g->current);
	}
	RETURN_NULL();
}

PHP_METHOD(ZephirGenerator, getReturn)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(getThis());

	ZEND_PARSE_PARAMETERS_NONE();

	if (g->state != -1 || Z_TYPE(g->retval) == IS_UNDEF) {
		zend_throw_exception(NULL, "Cannot get return value of a generator that hasn't returned", 0);
		return;
	}
	RETURN_COPY(&g->retval);
}

/* ------------------------------------------------- native get_iterator */

typedef struct _zephir_generator_iterator {
	zend_object_iterator intern;
} zephir_generator_iterator;

static void zephir_generator_it_dtor(zend_object_iterator *iter)
{
	zval_ptr_dtor(&iter->data);
}

static int zephir_generator_it_valid(zend_object_iterator *iter)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(&iter->data);

	zephir_generator_ensure_started(g);
	return g->state > 0 ? SUCCESS : FAILURE;
}

static zval *zephir_generator_it_current(zend_object_iterator *iter)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(&iter->data);

	zephir_generator_ensure_started(g);
	return (g->state > 0 && Z_TYPE(g->current) != IS_UNDEF) ? &g->current : NULL;
}

static void zephir_generator_it_key(zend_object_iterator *iter, zval *key)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(&iter->data);

	zephir_generator_ensure_started(g);
	if (g->state > 0 && Z_TYPE(g->key) != IS_UNDEF) {
		ZVAL_COPY(key, &g->key);
	} else {
		ZVAL_NULL(key);
	}
}

static void zephir_generator_it_next(zend_object_iterator *iter)
{
	zephir_generator_resume(ZEPHIR_GENERATOR_P(&iter->data));
}

static void zephir_generator_it_rewind(zend_object_iterator *iter)
{
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(&iter->data);

	if (!g->started) {
		zephir_generator_ensure_started(g);
		return;
	}
	if (g->advanced || g->state < 0) {
		zend_throw_exception(NULL, "Cannot rewind a generator that was already run", 0);
	}
}

static const zend_object_iterator_funcs zephir_generator_iterator_funcs = {
	zephir_generator_it_dtor,
	zephir_generator_it_valid,
	zephir_generator_it_current,
	zephir_generator_it_key,
	zephir_generator_it_next,
	zephir_generator_it_rewind,
	NULL, /* invalidate_current */
#if PHP_VERSION_ID >= 80100
	NULL, /* get_gc */
#endif
};

static zend_object_iterator *zephir_generator_get_iterator(zend_class_entry *ce, zval *object, int by_ref)
{
	zephir_generator_iterator *iterator;
	zephir_generator_object *g = ZEPHIR_GENERATOR_P(object);

	if (by_ref) {
		zend_throw_error(NULL, "An iterator cannot be used with foreach by reference");
		return NULL;
	}
	if (g->state < 0) {
		zend_throw_exception(NULL, "Cannot traverse an already closed generator", 0);
		return NULL;
	}

	iterator = emalloc(sizeof(zephir_generator_iterator));
	zend_iterator_init(&iterator->intern);
	ZVAL_COPY(&iterator->intern.data, object);
	iterator->intern.funcs = &zephir_generator_iterator_funcs;

	return &iterator->intern;
}

/* ---------------------------------------------------------- class init */

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephir_generator_none, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_generator_rewind, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_generator_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_generator_current, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_generator_key, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zephir_generator_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephir_generator_send, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static const zend_function_entry zephir_generator_methods[] = {
	PHP_ME(ZephirGenerator, rewind,    arginfo_zephir_generator_rewind,  ZEND_ACC_PUBLIC)
	PHP_ME(ZephirGenerator, valid,     arginfo_zephir_generator_valid,   ZEND_ACC_PUBLIC)
	PHP_ME(ZephirGenerator, current,   arginfo_zephir_generator_current, ZEND_ACC_PUBLIC)
	PHP_ME(ZephirGenerator, key,       arginfo_zephir_generator_key,     ZEND_ACC_PUBLIC)
	PHP_ME(ZephirGenerator, next,      arginfo_zephir_generator_next,    ZEND_ACC_PUBLIC)
	PHP_ME(ZephirGenerator, send,      arginfo_zephir_generator_send,    ZEND_ACC_PUBLIC)
	PHP_ME(ZephirGenerator, getReturn, arginfo_zephir_generator_none,    ZEND_ACC_PUBLIC)
	PHP_FE_END
};

void zephir_generator_module_init(void)
{
	zend_class_entry ce;

	INIT_NS_CLASS_ENTRY(ce, ZEPHIR_GENERATOR_NAMESPACE, "Generator", zephir_generator_methods);
	zephir_generator_ce = zend_register_internal_class(&ce);
	zephir_generator_ce->ce_flags |= ZEND_ACC_FINAL | ZEND_ACC_NO_DYNAMIC_PROPERTIES;
	zephir_generator_ce->create_object = zephir_generator_create_object;
	zephir_generator_ce->get_iterator  = zephir_generator_get_iterator;

	memcpy(&zephir_generator_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	zephir_generator_object_handlers.offset    = XtOffsetOf(zephir_generator_object, std);
	zephir_generator_object_handlers.free_obj  = zephir_generator_free_object;
	zephir_generator_object_handlers.get_gc    = zephir_generator_get_gc;
	zephir_generator_object_handlers.clone_obj = NULL;

	zend_class_implements(zephir_generator_ce, 1, zend_ce_iterator);
}

#endif /* ZEPHIR_GENERATOR_ENABLED */
