
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Support\Settings
 *
 * Provides a PHP-userland layer for reading and overriding the Phalcon
 * extension's ini settings (orm.*, db.*, form.*).
 *
 * get() checks PHP-level overrides first, then falls back to globals_get()
 * which reads the value configured in php.ini / .htaccess / per-virtualhost.
 *
 * set() stores the value in the PHP-level overrides array only. It does NOT
 * call globals_set(), so the change is confined to this static state and never
 * modifies the underlying C struct. This prevents settings changed by one
 * project from leaking into another project sharing the same PHP worker process.
 *
 * NOTE: In non-ZTS (non-thread-safe) PHP builds, globals_get() reads from a
 * process-level C struct. Because set() does not write to that struct, any
 * value set via ini_set("phalcon.orm.*", ...) or globals_set() by other code
 * remains visible through get() as the fallback for keys that have no
 * PHP-level override. In ZTS builds each thread has its own copy of the struct.
 *
 * reset() clears only the keys that were previously set via set(), restoring
 * those keys to their globals_get() fallback values.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Settings)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support, Settings, phalcon, support_settings, phalcon_support_settings_method_entry, 0);

	/**
	 * PHP-level overrides. Keys stored here take priority over globals_get().
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_settings_ce, SL("overrides"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	return SUCCESS;
}

/**
 * Returns the value of a known setting.
 *
 * Resolution order:
 *   1. PHP-level override (set via Settings::set())
 *   2. globals_get() - the C-level value, honoring php.ini / .htaccess
 *   3. null - for unknown keys
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Settings, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval key_zv, localOverrides, _0$$4;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&localOverrides);
	ZVAL_UNDEF(&_0$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&localOverrides);
	zephir_read_static_property_ce(&localOverrides, phalcon_support_settings_ce, SL("overrides"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&localOverrides)) {
		ZEPHIR_INIT_NVAR(&localOverrides);
		array_init(&localOverrides);
	}
	if (zephir_array_isset_value(&localOverrides, &key_zv)) {
		zephir_array_fetch(&_0$$4, &localOverrides, &key_zv, PH_NOISY | PH_READONLY, "phalcon/Support/Settings.zep", 68);
		RETURN_CTOR(&_0$$4);
	}
	ZEPHIR_RETURN_CALL_SELF("readglobal", &_1, 0, &key_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Overrides a setting at the PHP level.
 *
 * Does NOT call globals_set(), so the C-level struct is not modified and
 * no other project sharing this PHP process is affected.
 *
 * Unknown keys are silently ignored.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Phalcon_Support_Settings, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval key_zv, *value, value_sub, localOverrides, _0;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&localOverrides);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_SELF(&_0, "readglobal", &_1, 0, &key_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&localOverrides);
	zephir_read_static_property_ce(&localOverrides, phalcon_support_settings_ce, SL("overrides"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&localOverrides)) {
		ZEPHIR_INIT_NVAR(&localOverrides);
		array_init(&localOverrides);
	}
	zephir_array_update_zval(&localOverrides, &key_zv, value, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(phalcon_support_settings_ce, ZEND_STRL("overrides"), &localOverrides);
	ZEPHIR_MM_RESTORE();
}

/**
 * Clears all PHP-level overrides, restoring get() to return globals_get()
 * fallback values (as configured in php.ini or .htaccess).
 */
PHP_METHOD(Phalcon_Support_Settings, reset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalcon_support_settings_ce, ZEND_STRL("overrides"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * The single authoritative whitelist. Reads a known setting from its
 * C-level global, applying the per-key cast, and returns null for any
 * unknown key. Both get() and set() consult this method so the list of
 * valid settings lives in one place.
 *
 * globals_get() requires a string literal, so each key is read
 * explicitly rather than by a variable lookup.
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Settings, readGlobal)
{
	zval _0$$22;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0$$22);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	do {
		if (ZEPHIR_IS_STRING(&key_zv, "db.escape_identifiers")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(db).escape_identifiers);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "db.force_casting")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(db).force_casting);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "form.strict_entity_property_check")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(form).strict_entity_property_check);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.call_setters_on_hydration")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).call_setters_on_hydration);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.case_insensitive_column_map")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).case_insensitive_column_map);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.cast_last_insert_id_to_int")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.cast_on_hydrate")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).cast_on_hydrate);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.column_renaming")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).column_renaming);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.disable_assign_setters")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).disable_assign_setters);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.dynamic_update")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).dynamic_update);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.enable_implicit_joins")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).enable_implicit_joins);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.enable_literals")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).enable_literals);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.events")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).events);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.exception_on_failed_metadata_save")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.exception_on_failed_save")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).exception_on_failed_save);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.ignore_unknown_columns")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).ignore_unknown_columns);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.late_state_binding")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).late_state_binding);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.not_null_validations")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).not_null_validations);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.resultset_empty_left_join_model")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).resultset_empty_left_join_model);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.resultset_prefetch_records")) {
			ZEPHIR_INIT_VAR(&_0$$22);
			ZEPHIR_INIT_NVAR(&_0$$22);
			ZVAL_STRING(&_0$$22, "ZEPHIR_GLOBAL(orm).resultset_prefetch_records");
			RETURN_MM_LONG(zephir_get_intval_ex(&_0$$22));
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.update_snapshot_on_save")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).update_snapshot_on_save);
		}
		if (ZEPHIR_IS_STRING(&key_zv, "orm.virtual_foreign_keys")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).virtual_foreign_keys);
		}
	} while(0);

	RETURN_MM_NULL();
}

