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

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct()');

        $asset = new Css('p {color: #000099}');

        $I->assertEquals(
            'css',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - filter');

        $asset = new Css('p {color: #000099}');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - filter set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - filter set');

        $asset = new Css('p {color: #000099}', false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - attributes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - attributes');

        $asset = new Css('p {color: #000099}');

        $expected = [
            'type' => 'text/css',
        ];

        $I->assertEquals(
            $expected,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline\Css :: __construct() - attributes set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Css(
            'p {color: #000099}',
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
