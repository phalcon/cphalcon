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
 * Class GetRealTargetUriCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetRealTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - local
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetRealTargetUri(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri()');

        $type      = $example['type'];
        $path      = $example['path'];
        $local     = $example['local'];
        $expected  = $example['expected'];
        $targetUri = $example['targetUri'];

        $asset = new Asset($type, $path, $local);
        $asset->setTargetUri($targetUri);

        $actual = $asset->getRealTargetUri();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    protected function provider(): array
    {
        return [
            [
                'type'      => 'css',
                'path'      => 'css/docs.css',
                'local'     => true,
                'targetUri' => '',
                'expected'  => 'css/docs.css',
            ],
            [
                'type'      => 'js',
                'path'      => 'js/jquery.js',
                'local'     => true,
                'targetUri' => '',
                'expected'  => 'js/jquery.js',
            ],
            [
                'type'      => 'css',
                'path'      => 'https://phalcon.ld/css/docs.css',
                'local'     => false,
                'targetUri' => '',
                'expected'  => 'https://phalcon.ld/css/docs.css',
            ],
            [
                'type'      => 'js',
                'path'      => 'https://phalcon.ld/js/jquery.js',
                'local'     => false,
                'targetUri' => '',
                'expected'  => 'https://phalcon.ld/js/jquery.js',
            ],
            [
                'type'      => 'css',
                'path'      => 'css/assets.css',
                'local'     => true,
                'targetUri' => 'css/docs.css',
                'expected'  => 'css/docs.css',
            ],
        ];
    }
}
