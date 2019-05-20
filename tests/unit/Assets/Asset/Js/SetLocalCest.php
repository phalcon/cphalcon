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

class SetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setLocal() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetLocalLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setLocal() - js local');

        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $asset->setLocal(true);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setLocal() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetLocalRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setLocal() - js remote');
        $I->skipTest('TODO - Need checking');
        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $asset->setLocal(false);

        $I->assertFalse(
            $asset->getLocal()
        );
    }
}
