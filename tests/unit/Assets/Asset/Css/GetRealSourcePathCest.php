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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

/**
 * Class GetRealSourcePathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Css
 */
class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealSourcePath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssGetRealSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - css local');

        $asset  = new Css('css/docs.css');
        $actual = $asset->getRealSourcePath();
        $I->assertEmpty($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealSourcePath() - remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssGetRealSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - css remote');

        $path  = 'https://phalcon.ld/css/docs.css';
        $asset = new Css($path, false);

        $actual = $asset->getRealSourcePath();
        $I->assertEquals($path, $actual);
    }
}
