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
 * Class SetPathCest
 */
class SetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = '/new/path';
        $asset->setPath($expected);
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $expected = '/new/path';
        $asset->setPath($expected);
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = '/new/path';
        $asset->setPath($expected);
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = '/new/path';
        $asset->setPath($expected);
        $this->assetGetPath($I, $asset, $expected);
    }
}
