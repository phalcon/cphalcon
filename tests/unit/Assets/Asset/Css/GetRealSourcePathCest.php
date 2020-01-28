<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealSourcePath() - local
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetRealSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - local');

        $asset = new Css('css/docs.css');

        $I->assertFalse(
            $asset->getRealSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealSourcePath() - remote
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetRealSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - remote');

        $path = 'https://phalcon.ld/css/docs.css';

        $asset = new Css($path, false);

        $I->assertEquals(
            $path,
            $asset->getRealSourcePath()
        );
    }
}
