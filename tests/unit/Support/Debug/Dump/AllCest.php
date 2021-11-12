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
use stdClass;
use UnitTester;

/**
 * Class AllCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug\Dump
 */
class AllCest
{
    /**
     * Tests Phalcon\Support\Debug\Dump :: all()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpAll(UnitTester $I)
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $I->wantToTest('Debug\Dump - all()');

        $test1 = 'string';
        $test2 = ['key' => 'value'];
        $test3 = new stdClass();

        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Support/Dump/variables_output.txt')
            )
        );

        $I->assertEquals(
            $expected,
            $dump->all($test1, $test2, $test3)
        );
    }
}
