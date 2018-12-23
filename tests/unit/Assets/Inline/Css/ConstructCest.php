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

namespace Phalcon\Test\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
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
        $content = 'p {color: #000099}';
        $asset   = new Css($content);

        $expected = 'css';
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');
        $content = 'p {color: #000099}';
        $asset   = new Css($content);

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter set');
        $content = 'p {color: #000099}';
        $asset   = new Css($content, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes');
        $content = 'p {color: #000099}';
        $asset   = new Css($content);

        $expected = ['type' => 'text/css'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes set');
        $content = 'p {color: #000099}';
        $asset   = new Css($content, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }
}
