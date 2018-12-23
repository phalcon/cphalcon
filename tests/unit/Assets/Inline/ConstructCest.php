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

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content);

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter set');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructCssAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes set');
        $content = 'p {color: #000099}';
        $asset   = new Inline('css', $content, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content);

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter set');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructJsAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes set');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Inline('js', $content, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }
}
