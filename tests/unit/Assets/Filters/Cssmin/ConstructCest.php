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

namespace Phalcon\Test\Unit\Assets\Filters\Cssmin;

use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Filters\Cssmin;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: __construct() - no string
     * exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersCssminConstructNonString(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - no string exception');

        $cssMin = new Cssmin();
        $I->assertInstanceOf(Cssmin::class, $cssMin);
        $I->assertInstanceOf(FilterInterface::class, $cssMin);
    }
}
