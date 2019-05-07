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

class SetTypeCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset\Js :: setType() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetTypeLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - js local');
        $asset = new Js('js/jquery.js');

        $expected = 'css';
        $asset->setType($expected);
        $this->assetGetType($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setType() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetTypeRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - js remote');
        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $expected = 'css';
        $asset->setType($expected);
        $this->assetGetType($I, $asset, $expected);
    }
}
