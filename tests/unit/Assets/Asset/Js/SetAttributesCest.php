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
 * Class SetAttributesCest
 */
class SetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setAttributes() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetAttributesLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js local');
        $asset = new Js('js/jquery.js');

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setAttributes() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetAttributesRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js remote');
        $asset = new Js('https://phalcon.ld/js/jquery.js', false);

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }
}
