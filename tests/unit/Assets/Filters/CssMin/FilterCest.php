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

use Phalcon\Assets\Filters\CssMin;
use UnitTester;

/**
 * Class FilterCest
 *
 * @package Phalcon\Tests\Unit\Assets\Filters\CssMin
 */
class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\CssMin :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsFiltersCssMinFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\CssMin - filter()');

        $cssmin = new Cssmin();

        $expected = '{}}';
        $actual   = $cssmin->filter('{}}');
        $I->assertEquals($expected, $actual);
    }
}
