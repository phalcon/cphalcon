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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class GetTargetPathCest
 */
class GetTargetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getTargetPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetTargetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - js local');
        $asset = new Js('js/jquery.js');

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
    public function assetsAssetJsGetTargetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetPath() - js remote');
        $asset = new Js('https://phalcon.ld/js/jquery.js', false);

        $expected = '/phalcon/path';
        $asset->setTargetPath($expected);
        $this->assetGetTargetPath($I, $asset, $expected);
    }
}
