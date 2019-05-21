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

class GetRealTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $expected = 'css/docs.css';

        $I->assertEquals(
            $expected,
            $asset->getRealTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $expected = 'https://phalcon.ld/css/docs.css';

        $I->assertEquals(
            $expected,
            $asset->getRealTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $expected = 'js/jquery.js';

        $I->assertEquals(
            $expected,
            $asset->getRealTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

        $expected = 'https://phalcon.ld/js/jquery.js';

        $I->assertEquals(
            $expected,
            $asset->getRealTargetPath()
        );
    }
}
