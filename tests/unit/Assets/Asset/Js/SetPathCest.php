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

class SetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js local');

        $asset = new Js('js/jquery.js');

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setPath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js remote');

        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }
}
