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

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Css
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - local
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetCssConstructLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - local');

        $asset = new Css($example['path'], $example['local']);

        $expected = $example['local'];
        $actual   = $asset->isLocal();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');

        $asset  = new Css('css/docs.css');
        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - filter set');

        $asset  = new Css('css/docs.css', true, false);
        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetCssConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - __construct() - attributes');

        $asset = new Css('css/docs.css');

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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

        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }

    /**
     * @return array[]
     */
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
