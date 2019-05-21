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

class GetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - css local');

        $file = 'css/docs.css';

        $asset = new Asset('css', $file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - css remote');

        $file = 'https://phalcon.ld/css/docs.css';

        $asset = new Asset('css', $file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js local');

        $file = 'js/jquery.js';

        $asset = new Asset('js', $file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetLocalJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - js remote');

        $file = 'https://phalcon.ld/js/jquery.js';

        $asset = new Asset('js', $file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }
}
