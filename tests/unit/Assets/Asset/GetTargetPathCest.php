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
 * Class GetTargetPathCest
 */
class GetTargetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = '/phalcon/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $expected = '/phalcon/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = '/phalcon/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

        $expected = '/phalcon/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }
}
