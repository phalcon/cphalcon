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

class SetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }
}
