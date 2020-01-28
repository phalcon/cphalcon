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

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct()');

        $asset = new Js('<script>alert("Hello");</script>');

        $I->assertEquals(
            'js',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - filter');

        $asset = new Js('<script>alert("Hello");</script>');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - filter set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - filter set');

        $asset = new Js(
            '<script>alert("Hello");</script>',
            false
        );

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - attributes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - attributes');

        $asset = new Js('<script>alert("Hello");</script>');

        $expected = [
            'type' => 'text/javascript',
        ];

        $I->assertEquals(
            $expected,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - attributes set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineJsConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
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
