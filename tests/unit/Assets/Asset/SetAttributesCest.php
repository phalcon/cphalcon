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
use UnitTester;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setAttributes() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - css local');

        $asset = new Asset('css', 'css/docs.css');

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
     * Tests Phalcon\Assets\Asset :: setAttributes() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

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
     * Tests Phalcon\Assets\Asset :: setAttributes() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js local');

        $asset = new Asset('js', 'js/jquery.js');

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
     * Tests Phalcon\Assets\Asset :: setAttributes() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetAttributesJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setAttributes() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

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
