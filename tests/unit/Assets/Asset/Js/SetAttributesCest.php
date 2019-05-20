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

class SetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setAttributes() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetAttributesLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js local');

        $asset = new Js('js/jquery.js');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset->setAttributes($attributes);

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setAttributes() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetAttributesRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js remote');

        $asset = new Js('https://phalcon.ld/js/jquery.js', false);

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset->setAttributes($attributes);

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
