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

class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetRealSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - js local');

        $asset = new Js('js/jquery.js');

        $I->assertFalse(
            $asset->getRealSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealSourcePath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetRealSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealSourcePath() - js remote');

        $asset = new Js('https://phalcon.ld/js/jquery.js', false);

        $I->assertEquals(
            'https://phalcon.ld/js/jquery.js',
            $asset->getRealSourcePath()
        );
    }
}
