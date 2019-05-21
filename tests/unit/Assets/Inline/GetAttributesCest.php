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

class GetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getAttributes() - css
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetAttributesCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getAttributes() - css');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Inline(
            'css',
            'p {color: #000099}',
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline :: getAttributes() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetAttributesJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getAttributes() - js');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Inline(
            'js',
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
