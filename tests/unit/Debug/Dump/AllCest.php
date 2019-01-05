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
use stdClass;
use UnitTester;

/**
 * Class AllCest
 */
class AllCest
{
    /**
     * Tests Phalcon\Debug\Dump :: all()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpAll(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - all()');
        $test1 = 'string';
        $test2 = ['key' => 'value'];
        $test3 = new stdClass();
        $dump  = new Dump();

        $expected = trim(file_get_contents(dataFolder('fixtures/Dump/variables_output.txt')));
        $actual   = $dump->all($test1, $test2, $test3);
        $I->assertEquals($expected, $actual);
    }
}
