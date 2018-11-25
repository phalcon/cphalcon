<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Resource\Js;

use UnitTester;

class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Resource\Js :: getRealSourcePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceJsGetRealSourcePath(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource\Js - getRealSourcePath()");
        $I->skipTest("Need implementation");
    }
}
