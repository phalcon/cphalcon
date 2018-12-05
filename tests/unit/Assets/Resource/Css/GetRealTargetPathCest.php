<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Resource\Css;

use UnitTester;

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Resource\Css :: getRealTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceCssGetRealTargetPath(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource\Css - getRealTargetPath()");
        $I->skipTest("Need implementation");
    }
}
