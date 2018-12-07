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
 * Class SetPathCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset\Css
 */
class SetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetPath(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Css - setPath()");
        $I->skipTest("Need implementation");
    }
}
