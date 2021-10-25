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

use Phalcon\Support\Helper\Str\FirstBetween;
use UnitTester;

/**
 * Class FirstBetweenCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class FirstBetweenCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: firstBetween()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrFirstBetween(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - firstBetween()');

        $object   = new FirstBetween();
        $source   = 'This is a [custom] string';
        $expected = 'custom';
        $actual   = $object($source, '[', ']');
        $I->assertEquals($expected, $actual);
    }
}
