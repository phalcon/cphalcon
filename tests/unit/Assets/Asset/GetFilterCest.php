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

namespace Phalcon\Test\Unit\Assets\Asset;

use UnitTester;

/**
 * Class GetFilterCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset
 */
class GetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getFilter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetFilter(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getFilter()");
        $I->skipTest("Need implementation");
    }
}
