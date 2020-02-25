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

namespace Phalcon\Test\Unit\Assets\Filters\Jsmin;

use Phalcon\Assets\Filters\Jsmin;
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter()');

        $jsmin = new Jsmin();

        $expected = '{}}';
        $actual   = $jsmin->filter('{}}');
        $I->assertEquals($expected, $actual);
    }
}
