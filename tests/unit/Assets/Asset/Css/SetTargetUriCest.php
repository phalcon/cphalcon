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

class SetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setTargetUri()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetCssSetTargetUri(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Css - setTargetUri()');

        $asset = new Css(
            $example['path'],
            $example['local']
        );

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
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
