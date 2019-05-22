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

namespace Phalcon\Test\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use UnitTester;

class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetRealSourcePathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - css local');

        $realSourcePath = 'css/docs.css';

        $asset = new Asset('css', $realSourcePath);

        $I->assertFalse(
            $asset->getRealSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetRealSourcePathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - css remote');

        $realSourcePath = 'https://phalcon.ld/css/docs.css';

        $asset = new Asset('css', $realSourcePath, false);

        $I->assertEquals(
            $realSourcePath,
            $asset->getRealSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetRealSourcePathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - js local');

        $realSourcePath = 'js/jquery.js';

        $asset = new Asset('js', $realSourcePath);

        $I->assertFalse(
            $asset->getRealSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetRealSourcePathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - js remote');

        $realSourcePath = 'https://phalcon.ld/js/jquery.js';

        $asset = new Asset('js', $realSourcePath, false);

        $I->assertEquals(
            $realSourcePath,
            $asset->getRealSourcePath()
        );
    }
}
