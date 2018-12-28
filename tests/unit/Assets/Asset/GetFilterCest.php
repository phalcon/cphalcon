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
 * Class GetFilterCest
 */
class GetFilterCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getFilter() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetFilterCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getFilter() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getFilter() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetFilterCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getFilter() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getFilter() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetFilterJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getFilter() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getFilter() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetFilterJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getFilter() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }
}
