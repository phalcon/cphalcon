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

class SetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setFilter() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetFilterCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css local');

        $asset = new Css('https://phalcon.ld/css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: setFilter() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetFilterRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css remote');

        $I->skipTest('TODO - Need checking');

        $asset = new Css('https://phalcon.ld/css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }
}
