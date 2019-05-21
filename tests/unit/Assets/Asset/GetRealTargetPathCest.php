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

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css local');

        $realTargetPath = 'css/docs.css';

        $asset = new Asset('css', $realTargetPath);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - css remote');

        $realTargetPath = 'https://phalcon.ld/css/docs.css';

        $asset = new Asset('css', $realTargetPath, false);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - js local');

        $realTargetPath = 'js/jquery.js';

        $asset = new Asset('js', $realTargetPath);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetPath() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetPath() - js remote');

        $realTargetPath = 'https://phalcon.ld/js/jquery.js';

        $asset = new Asset('js', $realTargetPath, false);

        $I->assertEquals(
            $realTargetPath,
            $asset->getRealTargetPath()
        );
    }
}
