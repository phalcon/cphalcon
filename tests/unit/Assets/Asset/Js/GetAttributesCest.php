<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getAttributes()');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Js(
            'js/jquery.js',
            true,
            false,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
