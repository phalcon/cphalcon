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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use UnitTester;

/**
 * Class SetTargetPathCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset\Js
 */
class SetTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetTargetPath(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Js - setTargetPath()");
        $I->skipTest("Need implementation");
    }
}
