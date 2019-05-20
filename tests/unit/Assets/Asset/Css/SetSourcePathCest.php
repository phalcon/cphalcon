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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

class SetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setSourcePath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetSourcePathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - css local');

        $asset = new Css('css/docs.css');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: setSourcePath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetSourcePathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - css remote');

        $asset = new Css('https://phalcon.ld/css/docs.css');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }
}
