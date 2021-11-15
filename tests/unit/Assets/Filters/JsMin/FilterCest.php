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

use Phalcon\Assets\Filters\JsMin;
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\JsMin :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsFiltersJsMinFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\JsMin - filter()');

        $jsmin = new JsMin();

        $expected = '{}}';
        $actual   = $jsmin->filter('{}}');
        $I->assertEquals($expected, $actual);
    }
}
