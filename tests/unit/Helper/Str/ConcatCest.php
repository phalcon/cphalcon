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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class ConcatCest
 */
class ConcatCest
{
    /**
     * Tests Phalcon\Helper\Str :: concat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrConcat(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - concat()');
        // Test 1
        $actual   = Str::concat('/', '/tmp/', '/folder_1/', '/folder_2', 'folder_3/');
        $expected = '/tmp/folder_1/folder_2/folder_3/';
        $I->assertEquals($expected, $actual);

        // Test 2
        $actual   = Str::concat('.', '@test.', '.test2.', '.test', '.34');
        $expected = '@test.test2.test.34';
        $I->assertEquals($expected, $actual);
    }
}
