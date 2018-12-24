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
 * Class SetSourcePathCest
 */
class SetSourcePathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = '/new/path';
        $asset->setSourcePath($expected);
        $this->assetGetSourcePath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $expected = '/new/path';
        $asset->setSourcePath($expected);
        $this->assetGetSourcePath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = '/new/path';
        $asset->setSourcePath($expected);
        $this->assetGetSourcePath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetSourcePathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $expected = '/new/path';
        $asset->setSourcePath($expected);
        $this->assetGetSourcePath($I, $asset, $expected);
    }
}
