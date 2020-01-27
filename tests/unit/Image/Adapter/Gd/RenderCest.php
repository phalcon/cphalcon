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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class RenderCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: render()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdRender(UnitTester $I)
    {
        $I->skipTest("Test need to be refactored to handle GD 2.2 hashes");
        $I->wantToTest('Image\Adapter\Gd - render()');

        $params = [
            'jpg' => [130699, 'fbf9f3e3c3c18183'],
            'png' => [8802, '30787c3c1e181818'],
        ];

        foreach ($this->getImages() as $type => $imagePath) {
            $image = new Gd(
                $imagePath
            );

            [$lenght, $hash] = $params[$type];

            $I->assertSame($lenght, mb_strlen($image->render()));

            $I->assertTrue(
                $this->checkImageHash($imagePath, $hash)
            );
        }
    }
}
