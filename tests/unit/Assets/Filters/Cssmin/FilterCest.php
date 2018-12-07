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

namespace Phalcon\Test\Unit\Assets\Filters\Cssmin;

use UnitTester;

/**
 * Class FilterCest
 *
 * @package Phalcon\Test\Unit\Assets\Filters\Cssmin
 */
class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsFiltersCssminFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter()');
        $I->skipTest('Need implementation');
    }
}
