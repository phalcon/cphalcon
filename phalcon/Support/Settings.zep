
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

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
class Settings
{
    /**
     * PHP-level overrides. Keys stored here take priority over globals_get().
     *
     * @var array
     */
    protected static overrides;

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
    public static function get(string key) -> mixed
    {
        var localOverrides;

        let localOverrides = self::overrides;

        if empty localOverrides {
            let localOverrides = [];
        }

        // PHP-level override takes priority
        if isset localOverrides[key] {
            return localOverrides[key];
        }

        // Fall back to the C-level global (null for unknown keys)
        return self::readGlobal(key);
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
    public static function set(string key, var value) -> void
    {
        var localOverrides;

        /**
         * Silently ignore unknown keys. A known key always resolves to a
         * bool/int through readGlobal(), so a null result means the key is
         * not part of the whitelist.
         */
        if null === self::readGlobal(key) {
            return;
        }

        let localOverrides = self::overrides;

        if empty localOverrides {
            let localOverrides = [];
        }

        let localOverrides[key] = value;
        let self::overrides     = localOverrides;
    }

    /**
     * Clears all PHP-level overrides, restoring get() to return globals_get()
     * fallback values (as configured in php.ini or .htaccess).
     */
    public static function reset() -> void
    {
        let self::overrides = [];
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
    private static function readGlobal(string key) -> mixed
    {
        switch key {
            case "db.escape_identifiers":
                return (bool) globals_get("db.escape_identifiers");

            case "db.force_casting":
                return (bool) globals_get("db.force_casting");

            case "form.strict_entity_property_check":
                return (bool) globals_get("form.strict_entity_property_check");

            case "orm.case_insensitive_column_map":
                return (bool) globals_get("orm.case_insensitive_column_map");

            case "orm.cast_last_insert_id_to_int":
                return (bool) globals_get("orm.cast_last_insert_id_to_int");

            case "orm.cast_on_hydrate":
                return (bool) globals_get("orm.cast_on_hydrate");

            case "orm.column_renaming":
                return (bool) globals_get("orm.column_renaming");

            case "orm.disable_assign_setters":
                return (bool) globals_get("orm.disable_assign_setters");

            case "orm.dynamic_update":
                return (bool) globals_get("orm.dynamic_update");

            case "orm.enable_implicit_joins":
                return (bool) globals_get("orm.enable_implicit_joins");

            case "orm.enable_literals":
                return (bool) globals_get("orm.enable_literals");

            case "orm.events":
                return (bool) globals_get("orm.events");

            case "orm.exception_on_failed_metadata_save":
                return (bool) globals_get("orm.exception_on_failed_metadata_save");

            case "orm.exception_on_failed_save":
                return (bool) globals_get("orm.exception_on_failed_save");

            case "orm.ignore_unknown_columns":
                return (bool) globals_get("orm.ignore_unknown_columns");

            case "orm.late_state_binding":
                return (bool) globals_get("orm.late_state_binding");

            case "orm.not_null_validations":
                return (bool) globals_get("orm.not_null_validations");

            case "orm.resultset_empty_left_join_model":
                return (bool) globals_get("orm.resultset_empty_left_join_model");

            case "orm.resultset_prefetch_records":
                return (int) globals_get("orm.resultset_prefetch_records");

            case "orm.update_snapshot_on_save":
                return (bool) globals_get("orm.update_snapshot_on_save");

            case "orm.virtual_foreign_keys":
                return (bool) globals_get("orm.virtual_foreign_keys");
        }

        return null;
    }
}

