<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Filters\None;

use UnitTester;

/**
 * Class FilterCest
 */
class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\None :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsFiltersNoneFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\None - filter()');
        $I->skipTest('Need implementation');
    }
}
