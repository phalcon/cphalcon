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
use stdClass;
use UnitTester;

class AllCest
{
    /**
     * Tests Phalcon\Debug\Dump :: all()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugDumpAll(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - all()');

        $test1 = 'string';
        $test2 = ['key' => 'value'];
        $test3 = new stdClass();

        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Dump/variables_output.txt')
            )
        );

        $I->assertEquals(
            $expected,
            $dump->all($test1, $test2, $test3)
        );
    }
}
