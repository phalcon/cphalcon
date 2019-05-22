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

class GetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getTargetUri() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetTargetUriLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - js local');

        $asset = new Js('js/jquery.js');

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getTargetUri() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetTargetUriRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - js remote');

        $asset = new Js('https://phalcon.ld/js/jquery.js', false);

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }
}
