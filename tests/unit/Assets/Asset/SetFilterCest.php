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
    public function assetsAssetSetFilterCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css local');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

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
    public function assetsAssetSetFilterCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - css remote');
        $I->skipTest('TODO - Need checking');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetFilterJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - js local');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setFilter() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetFilterJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setFilter() - js remote');
        $I->skipTest('TODO - Need checking');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);

        $expected = false;
        $asset->setFilter($expected);
        $this->assetGetFilter($I, $asset, $expected);
    }
}
