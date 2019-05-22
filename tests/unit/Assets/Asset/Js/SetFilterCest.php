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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

class SetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setFilter() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetFilterJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - js local');

        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setFilter() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetFilterRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - js remote');

        $I->skipTest('TODO - Need checking');

        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }
}
