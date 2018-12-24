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
 * Class SetTargetPathCest
 */
class SetTargetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setTargetPath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetPathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetPath() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = '/new/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setTargetPath() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetPathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetPath() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $expected = '/new/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setTargetPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetPathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetPath() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = '/new/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setTargetPath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetPathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetPath() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = '/new/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }
}
