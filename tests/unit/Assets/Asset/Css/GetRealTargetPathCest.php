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

use Phalcon\Assets\Asset\Css;
use UnitTester;

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealTargetPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKeyLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css local');

        $realTargetPath = 'css/docs.css';

        $asset = new Css($realTargetPath);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealTargetPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKeyRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css remote');

        $realTargetPath = 'https://phalcon.ld/css/docs.css';

        $asset = new Css($realTargetPath, false);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }
}
