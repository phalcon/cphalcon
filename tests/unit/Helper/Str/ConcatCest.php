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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Exception;
use Phalcon\Helper\Str;
use UnitTester;

class ConcatCest
{
    /**
     * Tests Phalcon\Helper\Str :: concat()
     *
     * @author Phalcon Team <team@phalcon.io>
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

    /**
     * Tests Phalcon\Helper\Str :: concat() - exception
     */
    public function helperStrConcatException(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - concat() - exception');
        $I->expectThrowable(
            new Exception('concat needs at least three parameters'),
            function () {
                Str::concat('/', '/tmp/');
            }
        );
    }
}
