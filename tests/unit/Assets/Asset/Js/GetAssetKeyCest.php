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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getAssetKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getAssetKey()');

        $path = 'js/jquery.js';

        $asset = new Js(
            $path
        );

        $assetKey = md5(
            'js:' . $path
        );

        $I->assertEquals(
            $assetKey,
            $asset->getAssetKey()
        );
    }
}
