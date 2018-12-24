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

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

/**
 * Class ConcatCest
 */
class ConcatCest
{
    /**
     * Tests Phalcon\Text :: concat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textConcat(UnitTester $I)
    {
        $I->wantToTest('Text - concat()');
        // Test 1
        $actual   = Text::concat('/', '/tmp/', '/folder_1/', '/folder_2', 'folder_3/');
        $expected = '/tmp/folder_1/folder_2/folder_3/';
        $I->assertEquals($expected, $actual);

        // Test 2
        $actual   = Text::concat('.', '@test.', '.test2.', '.test', '.34');
        $expected = '@test.test2.test.34';
        $I->assertEquals($expected, $actual);
    }
}
