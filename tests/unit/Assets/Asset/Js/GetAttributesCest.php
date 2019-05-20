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
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getAttributes() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAttributesLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - js local');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Js(
            'js/jquery.js',
            true,
            false,
            $attributes
        );

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getAttributes() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAttributesRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAttributes() - js remote');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Js(
            'https://phalcon.ld/js/jquery.js',
            false,
            false,
            $attributes
        );

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
