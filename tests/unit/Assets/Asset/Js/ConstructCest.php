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

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Codeception\Example;
use Phalcon\Assets\Asset\Js;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - local
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetJsConstructLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Js - __construct() - local');

        $asset = new Js($example['path'], $example['local']);

        $expected = $example['local'];
        $actual   = $asset->isLocal();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');

        $asset = new Js('js/jquery.js');

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - __construct() - filter set');

        $asset = new Js('js/jquery.js', true, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - __construct() - attributes');

        $asset = new Js('js/jquery.js');

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Js(
            'js/jquery.js',
            true,
            true,
            $attributes
        );

        $expected = $attributes;
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
     */
    protected function provider(): array
    {
        return [
            [
                'path'  => 'js/jquery.js',
                'local' => true,
            ],
            [
                'path'  => 'https://phalcon.ld/js/jquery.js',
                'local' => false,
            ],
        ];
    }
}
