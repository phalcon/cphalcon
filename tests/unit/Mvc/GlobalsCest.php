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

namespace Phalcon\Test\Unit\Mvc;

use Codeception\Example;
use UnitTester;

use function ini_get;

class GlobalsCest
{
    /**
     * Tests Phalcon\Mvc :: globals
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-10-24
     * @issue  https://github.com/phalcon/cphalcon/issues/15269
     */
    public function mvcModelGlobals(UnitTester $I, Example $example)
    {
        $I->wantToTest('Phalcon\Mvc\Model\Query - globals ' . $example['setting']);

        $actual = ini_get($example['setting']);
        $I->assertNotFalse($actual);

        $expected = $example['value'];
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array<array-key, array<string, mixed>>
     */
    private function getExamples(): array
    {
        return [
            [
                'setting' => 'phalcon.db.escape_identifiers',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.db.force_casting',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.form.strict_entity_property_check',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.cast_last_insert_id_to_int',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.cast_on_hydrate',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.column_renaming',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.disable_assign_setters',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.enable_implicit_joins',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.enable_literals',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.events',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.exception_on_failed_metadata_save',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.exception_on_failed_save',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.ignore_unknown_columns',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.late_state_binding',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.not_null_validations',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.resultset_prefetch_records',
                'value'   => '0',
            ],
            [
                'setting' => 'phalcon.orm.update_snapshot_on_save',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.virtual_foreign_keys',
                'value'   => '1',
            ],
            [
                'setting' => 'phalcon.orm.dynamic_update',
                'value'   => '1',
            ],
        ];
    }
}
