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

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $I->assertEquals(
            'css',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter set');

        $content = 'p {color: #000099}';

        $asset = new Inline('css', $content, false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes');

        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes set');

        $content = 'p {color: #000099}';

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Inline(
            'css',
            $content,
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $I->assertEquals(
            'js',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter set');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content, false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes');

        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes set');

        $content = '<script>alert("Hello");</script>';

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Inline('js', $content, true, $attributes);

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
