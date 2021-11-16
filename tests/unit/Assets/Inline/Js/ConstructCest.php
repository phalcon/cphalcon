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

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Js
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct()');

        $asset = new Js('<script>alert("Hello");</script>');

        $expected = 'js';
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - filter');

        $asset  = new Js('<script>alert("Hello");</script>');
        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - filter set');

        $asset  = new Js('<script>alert("Hello");</script>', false);
        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - attributes');

        $asset = new Js('<script>alert("Hello");</script>');

        $expected = [
            'type' => 'application/javascript',
        ];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Js :: __construct() - attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset  = new Js(
            '<script>alert("Hello");</script>',
            true,
            $attributes
        );
        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }
}
