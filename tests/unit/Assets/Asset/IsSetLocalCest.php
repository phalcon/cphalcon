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

namespace Phalcon\Tests\Unit\Assets\Asset;

use Codeception\Example;
use Phalcon\Assets\Asset;
use UnitTester;

/**
 * Class SetLocalCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class IsSetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset :: isLocal()/setLocal()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetSetLocalCssLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - isLocal()/setLocal()');

        $asset = new Asset($example['type'], $example['path']);

        $actual = $asset->isLocal();
        $I->assertTrue($actual);

        $asset->setLocal($example['local']);

        $actual = $asset->isLocal();
        $I->assertEquals($example['local'], $actual);
    }

    /**
     * @return array[]
     */
    protected function provider(): array
    {
        return [
            [
                'type'  => 'css',
                'path'  => 'css/docs.css',
                'local' => true,
            ],
            [
                'type'  => 'js',
                'path'  => 'js/jquery.js',
                'local' => true,
            ],
            [
                'type'  => 'css',
                'path'  => 'https://phalcon.ld/css/docs.css',
                'local' => false,
            ],
            [
                'type'  => 'js',
                'path'  => 'https://phalcon.ld/js/jquery.js',
                'local' => false,
            ],
        ];
    }
}
