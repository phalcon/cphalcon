<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug\Dump;

use Phalcon\Debug\Dump;
use UnitTester;

class ToJsonCest
{
    /**
     * Tests Phalcon\Debug\Dump :: toJson()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function debugDumpToJson(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - toJson()');
        $test = [
            'key' => 'value',
        ];
        $dump = new Dump();

        $expected = "{\n    \"key\": \"value\"\n}";
        $actual   = $dump->toJson($test);
        $I->assertEquals($expected, $actual);
    }
}
