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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Codeception\Example;
use Phalcon\Assets\Asset\Css;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetCssConstructLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - local');

        $asset = new Css(
            $example['path'],
            $example['local']
        );

        $I->assertEquals(
            $example['local'],
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');

        $asset = new Css('css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - filter set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - filter set');

        $asset = new Css('css/docs.css', true, false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - attributes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - attributes');

        $asset = new Css('css/docs.css');

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - attributes set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Css(
            'css/docs.css',
            true,
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'path'  => 'css/docs.css',
                'local' => true,
            ],
            [
                'path'  => 'https://phalcon.ld/css/docs.css',
                'local' => false,
            ],
        ];
    }
}
