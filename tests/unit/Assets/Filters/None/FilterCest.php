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

namespace Phalcon\Tests\Unit\Assets\Filters\None;

use Phalcon\Assets\Filters\None;
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\None :: filter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsFiltersNoneFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\None - filter()');

        $filter = new None();

        $I->assertEquals(
            ' ',
            $filter->filter(' ')
        );
    }
}
