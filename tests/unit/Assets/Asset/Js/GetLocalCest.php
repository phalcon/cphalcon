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

class GetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getLocal() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetLocalLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js local');

        $file = 'js/jquery.js';

        $asset = new Js($file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getLocal() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetLocalRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js remote');

        $file = 'https://phalcon.ld/js/jquery.js';

        $asset = new Js($file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }
}
