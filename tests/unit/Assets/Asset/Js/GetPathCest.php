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

class GetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js local');

        $path = 'js/jquery.js';

        $asset = new Js($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getPath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js remote');

        $path = 'https://phalcon.ld/js/jquery.js';

        $asset = new Js($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }
}
