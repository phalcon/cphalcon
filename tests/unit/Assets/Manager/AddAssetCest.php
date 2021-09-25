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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use UnitTester;

class AddAssetCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addAsset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsManagerAddAsset(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAsset()');

        $assets = new Manager();

        $assets->addAsset(
            new Css('/css/style1.css')
        );

        $I->assertCount(
            1,
            $assets->get('css')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: addAsset() - addCss()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsManagerAddAssetAddCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAsset() - addCss()');

        $assets = new Manager();

        $assets->addCss('/css/style2.css');

        $assets->addAsset(
            new Css('/css/style1.css')
        );

        $I->assertCount(
            2,
            $assets->get('css')
        );
    }
}
