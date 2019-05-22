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

class GetTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getTargetPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetTargetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - css local');

        $asset = new Css('css/docs.css');

        $targetPath = '/phalcon/path';

        $asset->setTargetPath($targetPath);

        $I->assertEquals(
            $targetPath,
            $asset->getTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getTargetPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetTargetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - css remote');

        $asset = new Css('https://phalcon.ld/css/docs.css', false);

        $targetPath = '/phalcon/path';

        $asset->setTargetPath($targetPath);

        $I->assertEquals(
            $targetPath,
            $asset->getTargetPath()
        );
    }
}
