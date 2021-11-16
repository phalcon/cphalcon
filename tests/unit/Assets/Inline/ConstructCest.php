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

namespace Phalcon\Tests\Unit\Assets\Inline;

use Phalcon\Assets\Inline;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = 'css';
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);
        $actual  = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructCssFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter set');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content, false);
        $actual  = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructCssAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructCssAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes set');

        $content    = 'p {color: #000099}';
        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Inline(
            'css',
            $content,
            true,
            $attributes
        );

        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = 'js';
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);
        $actual  = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructJsFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter set');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content, false);
        $actual  = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructJsAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineConstructJsAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes set');

        $content    = '<script>alert("Hello");</script>';
        $attributes = [
            'data' => 'phalcon',
        ];
        $asset      = new Inline('js', $content, true, $attributes);

        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }
}
