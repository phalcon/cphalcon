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

class GetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - css local');

        $path = 'css/docs.css';

        $asset = new Asset('css', $path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - css remote');

        $path = 'https://phalcon.ld/css/docs.css';

        $asset = new Asset('css', $path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js local');

        $path = 'js/jquery.js';

        $asset = new Asset('js', $path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js remote');

        $path = 'https://phalcon.ld/js/jquery.js';

        $asset = new Asset('js', $path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }
}
