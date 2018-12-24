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
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class SetFilterCest
 */
class SetFilterCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetFilterCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css local');
        $asset = new Css('https://phalcon.ld/css/docs.css');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetFilterRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css remote');
        $I->skipTest('TODO - Need checking');
        $asset = new Css('https://phalcon.ld/css/docs.css');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }
}
