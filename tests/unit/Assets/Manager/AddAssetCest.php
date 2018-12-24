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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class AddAssetCest
 */
class AddAssetCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addAsset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsManagerAddAsset(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAsset()');
        $assets = new Manager();
        $assets->addAsset(new Css('/css/style1.css'));

        $expected = 1;
        $actual   = count($assets->get('css'));
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: addAsset() - addCss()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsManagerAddAssetAddCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAsset() - addCss()');
        $assets = new Manager();
        $assets->addCss('/css/style2.css');
        $assets->addAsset(new Css('/css/style1.css'));

        $expected = 2;
        $actual   = count($assets->get('css'));
        $I->assertEquals($expected, $actual);
    }
}
