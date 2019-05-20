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

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css local');

        $file = 'css/docs.css';

        $asset = new Asset('css', $file);

        $expected = md5(
            'css:' . $file
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - css remote');

        $file = 'https://phalcon.ld/css/docs.css';

        $asset = new Asset('css', $file);

        $expected = md5(
            'css:' . $file
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - js local');

        $file = 'js/jquery.js';

        $asset = new Asset('js', $file);

        $expected = md5(
            'js:' . $file
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAssetKeyJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey() - js remote');

        $file = 'https://phalcon.ld/js/jquery.js';

        $asset = new Asset('js', $file);

        $expected = md5(
            'js:' . $file
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }
}
