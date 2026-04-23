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

namespace Phalcon\Tests\Unit\Mvc;

use Phalcon\Tests\AbstractUnitTestCase;

use function ini_get;

final class GlobalsTest extends AbstractUnitTestCase
{
    /**
     * @dataProvider getExamples
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15269
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-10-24
     */
    public function testMvcModelGlobals(string $setting, string $value): void
    {
        $actual = ini_get($setting);
        $this->assertNotFalse($actual);

        $expected = $value;
        $this->assertSame($expected, $actual);
    }

    /**
     * @return array<array-key, array<string, string>>
     */
    public static function getExamples(): array
    {
        return [
            ['phalcon.db.escape_identifiers', '1'],
            ['phalcon.db.force_casting', '0'],
            ['phalcon.form.strict_entity_property_check', '0'],
            ['phalcon.orm.cast_last_insert_id_to_int', '0'],
            ['phalcon.orm.cast_on_hydrate', '0'],
            ['phalcon.orm.column_renaming', '1'],
            ['phalcon.orm.disable_assign_setters', '0'],
            ['phalcon.orm.enable_implicit_joins', '1'],
            ['phalcon.orm.enable_literals', '1'],
            ['phalcon.orm.events', '1'],
            ['phalcon.orm.exception_on_failed_metadata_save', '1'],
            ['phalcon.orm.exception_on_failed_save', '0'],
            ['phalcon.orm.ignore_unknown_columns', '0'],
            ['phalcon.orm.late_state_binding', '0'],
            ['phalcon.orm.not_null_validations', '1'],
            ['phalcon.orm.resultset_prefetch_records', '0'],
            ['phalcon.orm.update_snapshot_on_save', '1'],
            ['phalcon.orm.virtual_foreign_keys', '1'],
            ['phalcon.orm.dynamic_update', '1'],
        ];
    }
}
