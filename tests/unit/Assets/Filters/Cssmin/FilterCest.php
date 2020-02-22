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

use Phalcon\Assets\Filters\Cssmin;
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter()');

        $cssmin = new Cssmin();

        $expected = '{}}';
        $actual   = $cssmin->filter('{}}');
        $I->assertEquals($expected, $actual);
    }
}
