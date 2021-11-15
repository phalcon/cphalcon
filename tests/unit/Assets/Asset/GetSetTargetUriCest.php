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
 * Class GetSetTargetUriCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetSetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setTargetUri() - local
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetSetTargetUriJsLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setTargetUri()');

        $asset     = new Asset($example['type'], $example['path'], $example['local']);
        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);
        $actual = $asset->getTargetUri();
        $I->assertEquals($targetUri, $actual);
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
