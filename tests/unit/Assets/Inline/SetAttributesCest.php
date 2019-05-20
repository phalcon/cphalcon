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

namespace Phalcon\Test\Unit\Assets\Inline;

use Phalcon\Assets\Inline;
use UnitTester;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Inline :: setAttributes() - css
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetAttributesCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setAttributes() - css');

        $asset = new Inline(
            'css',
            'p {color: #000099}'
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

    /**
     * Tests Phalcon\Assets\Inline :: setAttributes() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetAttributesJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setAttributes() - js');

        $asset = new Inline(
            'js',
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
