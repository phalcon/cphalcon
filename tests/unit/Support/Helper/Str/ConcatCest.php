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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\Concat;
use UnitTester;

/**
 * Class ConcatCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class ConcatCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: concat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrConcat(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - concat()');

        $object = new Concat();

        // Test 1
        $actual   = $object(
            '/',
            '/tmp/',
            '/folder_1/',
            '/folder_2',
            'folder_3/'
        );
        $expected = '/tmp/folder_1/folder_2/folder_3/';
        $I->assertEquals($expected, $actual);

        // Test 2
        $actual   = $object(
            '.',
            '@test.',
            '.test2.',
            '.test',
            '.34'
        );
        $expected = '@test.test2.test.34';
        $I->assertEquals($expected, $actual);
    }
}
