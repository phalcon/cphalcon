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

namespace Phalcon\Tests\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Css
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct()');

        $asset = new Css('p {color: #000099}');

        $expected = 'css';
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - filter');

        $asset  = new Css('p {color: #000099}');
        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - filter set');

        $asset  = new Css('p {color: #000099}', false);
        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - attributes');

        $asset = new Css('p {color: #000099}');

        $expected = [
            'type' => 'text/css',
        ];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset  = new Css(
            'p {color: #000099}',
            true,
            $attributes
        );
        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }
}
