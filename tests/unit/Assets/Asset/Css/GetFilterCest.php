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

class GetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getFilter() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetFilterCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getFilter() - css local');

        $asset = new Css('css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getFilter() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetFilterRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getFilter() - css remote');

        $asset = new Css('https://phalcon.ld/css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );
    }
}
