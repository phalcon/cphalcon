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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getAssetKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getAssetKey()');

        $path = 'css/docs.css';

        $asset = new Css(
            $path
        );

        $assetKey = md5(
            'css:' . $path
        );

        $I->assertEquals(
            $assetKey,
            $asset->getAssetKey()
        );
    }
}
