<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

class GetFilterCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getFilter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getFilter()');

        $asset = new Css('css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );
    }
}
