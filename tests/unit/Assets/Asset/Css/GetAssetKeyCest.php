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

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getAssetKey() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKeyLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css local');

        $file = 'css/docs.css';

        $asset = new Css($file);

        $assetKey = md5(
            'css:' . $file
        );

        $I->assertEquals(
            $assetKey,
            $asset->getAssetKey()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getAssetKey() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKeyRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css remote');

        $file = 'https://phalcon.ld/css/docs.css';

        $asset = new Css($file);

        $assetKey = md5(
            'css:' . $file
        );

        $I->assertEquals(
            $assetKey,
            $asset->getAssetKey()
        );
    }
}
