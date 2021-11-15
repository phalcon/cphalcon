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

namespace Phalcon\Tests\Unit\Assets\Filters\JsMin;

use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Filters\JsMin;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Filters\JsMin
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Filters\JsMin :: __construct() - no string exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsFiltersJsminConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\JsMin - filter() - no string exception');

        $jsMin = new Jsmin();
        $I->assertInstanceOf(Jsmin::class, $jsMin);
        $I->assertInstanceOf(FilterInterface::class, $jsMin);
    }
}
