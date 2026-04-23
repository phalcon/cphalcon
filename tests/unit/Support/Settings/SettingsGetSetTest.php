<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Settings;

use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractUnitTestCase;

final class SettingsGetSetTest extends AbstractUnitTestCase
{
    /**
     * Restore all overrides after each test so state does not leak.
     */
    protected function tearDown(): void
    {
        Settings::reset();
        parent::tearDown();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportSettingsDefaults(): void
    {
        $expected = true;
        $actual = Settings::get('db.escape_identifiers');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('db.force_casting');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('form.strict_entity_property_check');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.case_insensitive_column_map');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.cast_last_insert_id_to_int');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.cast_on_hydrate');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.column_renaming');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.disable_assign_setters');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.enable_implicit_joins');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.enable_literals');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.events');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.exception_on_failed_save');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.exception_on_failed_metadata_save');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.ignore_unknown_columns');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('orm.late_state_binding');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.not_null_validations');
        $this->assertSame($expected, $actual);

        $expected = 0;
        $actual = Settings::get('orm.resultset_prefetch_records');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.update_snapshot_on_save');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.virtual_foreign_keys');
        $this->assertSame($expected, $actual);

        $expected = true;
        $actual = Settings::get('orm.dynamic_update');
        $this->assertSame($expected, $actual);

        $actual = Settings::get('unknown');
        $this->assertNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportSettingsGetSet(): void
    {
        $expected = true;
        $actual = Settings::get('db.escape_identifiers');
        $this->assertSame($expected, $actual);

        $expected = false;
        $actual = Settings::get('db.force_casting');
        $this->assertSame($expected, $actual);

        Settings::set('db.escape_identifiers', false);
        $expected = false;
        $actual = Settings::get('db.escape_identifiers');
        $this->assertSame($expected, $actual);

        Settings::set('db.force_casting', true);
        $expected = true;
        $actual = Settings::get('db.force_casting');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportSettingsSetAllKnownKeys(): void
    {
        $keys = [
            'form.strict_entity_property_check',
            'orm.case_insensitive_column_map',
            'orm.cast_last_insert_id_to_int',
            'orm.cast_on_hydrate',
            'orm.column_renaming',
            'orm.disable_assign_setters',
            'orm.enable_implicit_joins',
            'orm.enable_literals',
            'orm.exception_on_failed_save',
            'orm.exception_on_failed_metadata_save',
            'orm.ignore_unknown_columns',
            'orm.late_state_binding',
            'orm.not_null_validations',
            'orm.resultset_prefetch_records',
            'orm.update_snapshot_on_save',
            'orm.virtual_foreign_keys',
            'orm.dynamic_update',
        ];

        foreach ($keys as $key) {
            $original = Settings::get($key);
            Settings::set($key, true);
            $actual = Settings::get($key);
            $this->assertTrue($actual);
            Settings::reset();
            $this->assertSame($original, Settings::get($key));
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportSettingsSetUnknownKeyIgnored(): void
    {
        Settings::set('unknown.key', true);
        $actual = Settings::get('unknown.key');
        $this->assertNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-04
     */
    public function testSupportSettingsReset(): void
    {
        Settings::set('db.escape_identifiers', false);
        Settings::set('db.force_casting', true);
        Settings::set('orm.events', false);

        $this->assertSame(false, Settings::get('db.escape_identifiers'));
        $this->assertSame(true, Settings::get('db.force_casting'));
        $this->assertSame(false, Settings::get('orm.events'));

        Settings::reset();

        $this->assertSame(true, Settings::get('db.escape_identifiers'));
        $this->assertSame(false, Settings::get('db.force_casting'));
        $this->assertSame(true, Settings::get('orm.events'));
    }
}
