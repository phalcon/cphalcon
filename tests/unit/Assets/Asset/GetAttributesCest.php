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
 * Class GetAttributesCest
 */
class GetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: getAttributes() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAttributesCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - css local');
        $asset = new Asset('css', 'css/docs.css', true, false, ['data-key' => 'phalcon']);

        $expected = ['data-key' => 'phalcon'];
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAttributes() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAttributesCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - css remote');
        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false, false, ['data-key' => 'phalcon']);

        $expected = ['data-key' => 'phalcon'];
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAttributes() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAttributesJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - js local');
        $asset = new Asset('js', 'js/jquery.js', true, false, ['data-key' => 'phalcon']);

        $expected = ['data-key' => 'phalcon'];
        $this->assetGetAttributes($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getAttributes() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetAttributesJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - js remote');
        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false, false, ['data-key' => 'phalcon']);

        $expected = ['data-key' => 'phalcon'];
        $this->assetGetAttributes($I, $asset, $expected);
    }
}
