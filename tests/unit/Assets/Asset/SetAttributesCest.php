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
 * Class SetAttributesCest
 */
class SetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setAttributes() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setAttributes() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setAttributes() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js local');
        $asset = new Asset('js', 'js/jquery.js');

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
    public function assetsAssetSetAttributesJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

        $expected = ['data-key' => 'phalcon'];
        $asset->setAttributes($expected);
        $this->assetGetAttributes($I, $asset, $expected);
    }
}
