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

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct()');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content);

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
    public function assetsInlineConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content);

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
    public function assetsInlineConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter set');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content, false);

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
    public function assetsInlineConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content);

        $expected = ['type' => 'text/javascript'];
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
    public function assetsInlineConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes set');
        $content = '<script>alert("Hello");</script>';
        $asset   = new Js($content, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }
}
