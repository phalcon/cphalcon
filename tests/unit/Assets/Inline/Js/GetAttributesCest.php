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

namespace Phalcon\Tests\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsGetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getAttributes()');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Js(
            '<script>alert("Hello");</script>',
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
