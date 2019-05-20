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

class SetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setSourcePath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - js local');

        $asset = new Js('js/jquery.js');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setSourcePath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - js remote');

        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }
}
