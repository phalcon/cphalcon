<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetRealSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - local');

        $asset = new Js('js/jquery.js');

        $I->assertEquals('', $asset->getRealSourcePath());
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetRealSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - remote');

        $path = 'https://phalcon.ld/js/jquery.js';

        $asset = new Js($path, false);

        $I->assertEquals(
            $path,
            $asset->getRealSourcePath()
        );
    }
}
