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
 * Class FirstStringBetweenCest
 */
class FirstStringBetweenCest
{
    /**
     * Tests Phalcon\Helper\Str :: firstStringBetween()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrFirstStringBetween(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - firstStringBetween()');

        $source   = 'This is a [custom] string';
        $expected = 'custom';
        $actual   = Str::firstStringBetween($source, '[', ']');
        $I->assertEquals($expected, $actual);
    }
}
