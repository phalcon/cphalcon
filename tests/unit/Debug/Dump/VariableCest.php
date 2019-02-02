<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug\Dump;

use Phalcon\Debug\Dump;
use UnitTester;

/**
 * Class VariableCest
 */
class VariableCest
{
    /**
     * Tests Phalcon\Debug\Dump :: variable()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpVariable(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variable()');
        $test = 'value';
        $dump = new Dump();

        $expected = trim(file_get_contents(dataFolder('fixtures/Dump/variable_output.txt')));
        $actual   = $dump->variable($test);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Debug\Dump :: variable() - name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpVariableName(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variable() - name');
        $test = 'value';
        $dump = new Dump();

        $expected = trim(file_get_contents(dataFolder('fixtures/Dump/variable_name_output.txt')));
        $actual   = $dump->variable($test, 'super');
        $I->assertEquals($expected, $actual);
    }
}
