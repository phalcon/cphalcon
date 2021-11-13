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

use function str_replace;

use const PHP_EOL;

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
        /**
         * This is to ensure that Windows builds do not throw an error
         */
        $expected = str_replace("\n", PHP_EOL, $expected);
        $actual = $dump->variable($test, 'super');
        $I->assertEquals($expected, $actual);
    }
}
