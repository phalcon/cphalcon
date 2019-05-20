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

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getAssetKey() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAssetKeyLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - js local');

        $file = 'js/jquery.js';

        $asset = new Js($file);

        $expected = md5(
            'js:' . $file
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getAssetKey() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAssetKeyRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - js remote');

        $file = 'https://phalcon.ld/js/jquery.js';

        $asset = new Js($file, false);

        $expected = md5(
            'js:' . $file
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }
}
