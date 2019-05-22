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

use Phalcon\Assets\Asset\Js;
use UnitTester;

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealTargetPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAssetKeyLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - js local');

        $realTargetPath = 'js/jquery.js';

        $asset = new Js($realTargetPath);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealTargetPath() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAssetKeyRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - js remote');

        $realTargetPath =  'https://phalcon.ld/js/jquery.js';

        $asset = new Js($realTargetPath, false);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }
}
