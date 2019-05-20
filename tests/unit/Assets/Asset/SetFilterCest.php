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

class SetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetFilterCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css local');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetFilterCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetFilterJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - js local');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetFilterJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - js remote');
        $I->skipTest('TODO - Need checking');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $assert->getFilter()
        );
    }
}
