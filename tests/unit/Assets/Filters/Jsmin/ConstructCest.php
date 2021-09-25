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

namespace Phalcon\Tests\Unit\Assets\Filters\Jsmin;

use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Filters\Jsmin;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: __construct() - no string exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - no string exception');

        $jsMin = new Jsmin();
        $I->assertInstanceOf(Jsmin::class, $jsMin);
        $I->assertInstanceOf(FilterInterface::class, $jsMin);
    }
}
