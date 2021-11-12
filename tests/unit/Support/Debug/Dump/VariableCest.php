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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use UnitTester;

/**
 * Class VariableCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug\Dump
 */
class VariableCest
{
    /**
     * Tests Phalcon\Support\Debug\Dump :: variable()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpVariable(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variable()');

        $test = 'value';
        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Support/Dump/variable_output.txt')
            )
        );
        $actual   = $dump->variable($test);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Debug\Dump :: variable() - name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function debugDumpVariableName(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variable() - name');

        $test = 'value';
        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Support/Dump/variable_name_output.txt')
            )
        );

        $actual = $dump->variable($test, 'super');
        $I->assertEquals($expected, $actual);
    }
}
