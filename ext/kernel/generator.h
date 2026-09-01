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

#ifndef ZEPHIR_KERNEL_GENERATOR_H
#define ZEPHIR_KERNEL_GENERATOR_H

#include <php.h>
#include <Zend/zend.h>

/**
 * Runtime for Zephir generator methods (`yield`), issue #1849.
 *
 * PHP's zend_generator can only suspend op_array (userland) functions, and
 * \Generator is final, so Zephir compiles each generator method into:
 *   - a creator (the visible method) that returns a <Namespace>\Generator
 *     object seeded with the call arguments, and
 *   - an internal-visibility step function holding the original body as a
 *     resumable state machine.
 *
 * This kernel class implements \Iterator plus send()/getReturn() with
 * PHP-identical laziness, auto-key, rewind and exhaustion semantics.
 *
 * The whole runtime is compiled out unless the project actually uses
 * `yield` (ZEPHIR_GENERATOR_ENABLED is defined in php_<project>.h by the
 * compiler when at least one generator method exists).
 */

/* Signature matches Zephir's internal-visibility call convention: the one
 * extra parameter is the generator object (zval of <Ns>\Generator). */
typedef void (*zephir_generator_step_fn)(int ht, zend_execute_data *execute_data,
	zval *return_value, zval *this_ptr, int return_value_used, zval *gen_ext);

typedef struct _zephir_generator_object {
	/* 0 = created (body not entered), N > 0 = suspended at yield point N,
	 * -1 = finished (clean return, or closed by an uncaught exception). */
	zend_long state;
	int started;   /* body entered at least once */
	int advanced;  /* resumed past the first suspension */
	int running;   /* re-entrancy guard while the step function executes */

	zephir_generator_step_fn step;
	zend_class_entry *scope;   /* class owning the step (EG(fake_scope) while running) */
	zval bound_this;           /* IS_UNDEF for static generator methods */

	zval current;              /* last yielded value (IS_UNDEF before start/after close) */
	zval key;                  /* last yielded key */
	zval retval;               /* getReturn() payload; IS_UNDEF unless finished cleanly */
	zend_long next_auto_key;   /* PHP array-append key counter semantics */

	/* Suspended C locals of the step function, boxed as zvals.
	 * Slots [0 .. n_params-1] are the creator's arguments. */
	uint32_t n_slots;
	zval *slots;

	zend_object std;
} zephir_generator_object;

#ifdef ZEPHIR_GENERATOR_ENABLED
extern zend_class_entry *zephir_generator_ce;
#endif

/* Registered in every extension's MINIT (no-op when the runtime is compiled out). */
void zephir_generator_module_init(void);

#ifdef ZEPHIR_GENERATOR_ENABLED

static inline zephir_generator_object *zephir_generator_fetch(zend_object *obj)
{
	return (zephir_generator_object *) ((char *) obj - XtOffsetOf(zephir_generator_object, std));
}

#define ZEPHIR_GENERATOR_P(zv) zephir_generator_fetch(Z_OBJ_P(zv))

/* Creator side */
void zephir_generator_create(zval *return_value, zval *bound_this, zend_class_entry *scope,
	zephir_generator_step_fn step, uint32_t n_params);

/* Step side: suspension protocol */
zend_long zephir_generator_get_state(zval *gen);
void zephir_generator_slots_ensure(zval *gen, uint32_t n);
void zephir_generator_slot_set(zval *gen, uint32_t i, zval *value);
void zephir_generator_slot_set_long(zval *gen, uint32_t i, zend_long value);
void zephir_generator_slot_set_double(zval *gen, uint32_t i, double value);
void zephir_generator_slot_set_bool(zval *gen, uint32_t i, int value);
void zephir_generator_slot_set_str(zval *gen, uint32_t i, zend_string *value);
zval *zephir_generator_slot(zval *gen, uint32_t i);
void zephir_generator_yield(zval *gen, zval *key_or_null, zval *value_or_null, zend_long state);
void zephir_generator_finish(zval *gen, zval *retval_or_null);

/* Restore a suspended slot back into a C-stack zval local, transferring the
 * slot's reference and re-observing the local in the current memory frame.
 * UNDEF slots leave the local untouched (it stays UNDEF and a later
 * ZEPHIR_INIT_* observes it normally). */
#define ZEPHIR_GEN_RESTORE_ZVAL(gen, idx, local) \
	do { \
		zval *_zg_slot = zephir_generator_slot(gen, idx); \
		if (Z_TYPE_P(_zg_slot) != IS_UNDEF) { \
			zephir_memory_observe(local); \
			ZVAL_COPY_VALUE(local, _zg_slot); \
			ZVAL_UNDEF(_zg_slot); \
		} \
	} while (0)

#endif /* ZEPHIR_GENERATOR_ENABLED */

#endif /* ZEPHIR_KERNEL_GENERATOR_H */
