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

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class FirstBetweenCest
{
    /**
     * Tests Phalcon\Helper\Str :: firstBetween()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrFirstBetween(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - firstBetween()');

        $source   = 'This is a [custom] string';
        $expected = 'custom';
        $actual   = Str::firstBetween($source, '[', ']');
        $I->assertEquals($expected, $actual);
    }
}
