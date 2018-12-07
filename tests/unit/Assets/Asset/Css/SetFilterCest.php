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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use UnitTester;

/**
 * Class SetFilterCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset\Css
 */
class SetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setFilter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetFilter(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Css - setFilter()");
        $I->skipTest("Need implementation");
    }
}
