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

use function uniqid;

/**
 * Class GetSetPathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetSetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getPath()/setPath()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetSetPath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getPath()/setPath()');

        $path  = uniqid('/');
        $asset = new Asset($example['type'], $path);

        $expected = $path;
        $actual   = $asset->getPath();
        $I->assertEquals($expected, $actual);

        $expected = $example['path'];
        $asset->setPath($example['path']);
        $actual = $asset->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
     */
    protected function provider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'css/docs.css',
            ],
            [
                'type' => 'css',
                'path' => 'https://phalcon.ld/css/docs.css',
            ],
            [
                'type' => 'js',
                'path' => 'js/jquery.js',
            ],
            [
                'type' => 'js',
                'path' => 'https://phalcon.ld/js/jquery.js',
            ],
        ];
    }
}
