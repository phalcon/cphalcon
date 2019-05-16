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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class GetAttributesCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset\Css :: getAttributes() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAttributesLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - css local');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Css(
            'css/docs.css',
            true,
            false,
            $attributes
        );

        $this->assetGetAttributes($I, $asset, $attributes);
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getAttributes() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetAttributesRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - css remote');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Css(
            'https://phalcon.ld/css/docs.css',
            false,
            false,
            $attributes
        );

        $this->assetGetAttributes($I, $asset, $attributes);
    }
}
