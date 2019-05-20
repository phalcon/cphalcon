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

namespace Phalcon\Test\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use UnitTester;

class GetTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $targetPath = '/phalcon/path';

        $asset->setTargetPath($targetPath);

        $I->assertEquals(
            $targetPath,
            $asset->getTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $targetPath = '/phalcon/path';

        $asset->setTargetPath($targetPath);

        $I->assertEquals(
            $targetPath,
            $asset->getTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $targetPath = '/phalcon/path';

        $asset->setTargetPath($targetPath);

        $I->assertEquals(
            $targetPath,
            $asset->getTargetPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

        $targetPath = '/phalcon/path';

        $asset->setTargetPath($targetPath);

        $I->assertEquals(
            $targetPath,
            $asset->getTargetPath()
        );
    }
}
