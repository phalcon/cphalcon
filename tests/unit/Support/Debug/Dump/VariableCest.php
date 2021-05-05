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

namespace Phalcon\Test\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use UnitTester;

class VariableCest
{
    /**
     * Tests Phalcon\Debug\Dump :: variable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugDumpVariable(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variable()');

        $test = 'value';

        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Dump/variable_output.txt')
            )
        );

        $I->assertEquals(
            $expected,
            $dump->variable($test)
        );
    }

    /**
     * Tests Phalcon\Debug\Dump :: variable() - name
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugDumpVariableName(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variable() - name');

        $test = 'value';

        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Dump/variable_name_output.txt')
            )
        );

        $I->assertEquals(
            $expected,
            $dump->variable($test, 'super')
        );
    }
}
