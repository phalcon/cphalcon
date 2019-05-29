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

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: setAttributes()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineJsSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - setAttributes()');

        $asset = new Js(
            '<script>alert("Hello");</script>'
        );

        $expected = [
            'data-key' => 'phalcon',
        ];

        $asset->setAttributes($expected);

        $I->assertEquals(
            $expected,
            $asset->getAttributes()
        );
    }
}
