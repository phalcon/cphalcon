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

namespace Phalcon\Tests\Unit\Assets\Filters\CssMin;

use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Filters\CssMin;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Filters\CssMin
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Filters\CssMin :: __construct() - no string
     * exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsFiltersCssMinConstructNonString(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\CssMin - filter() - no string exception');

        $cssMin = new Cssmin();
        $I->assertInstanceOf(Cssmin::class, $cssMin);
        $I->assertInstanceOf(FilterInterface::class, $cssMin);
    }
}
