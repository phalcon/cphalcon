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
 * Class GetPathCest
 */
class GetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = 'css/docs.css';
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $expected = 'https://phalcon.ld/css/docs.css';
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = 'js/jquery.js';
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getPath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = 'https://phalcon.ld/js/jquery.js';
        $this->assetGetPath($I, $asset, $expected);
    }
}
