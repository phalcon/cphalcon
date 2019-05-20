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

class SetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }
}
