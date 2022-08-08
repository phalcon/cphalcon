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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
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
            'gif'  => [8087, 'fffffffffbffffff'],
            'jpg'  => [130699, 'fbf9f3e3c3c18183'],
            'png'  => [8802, '30787c3c1e181818'],
            'wbmp' => [31761, '00c78ffe78030200'],
            'webp' => [483066, '270640183c3c7c7c'],
            'xyz'  => [8802, '30787c3c1e181818'] // unknown defaults to png,
        ];

        foreach ($this->getImages() as $type => $imagePath) {
            $image = new Gd($imagePath);

            [$length, $hash] = $params[$type];

            $I->assertSame($length, mb_strlen($image->render()));

            $actual = $this->checkImageHash($imagePath, $hash);
            $I->assertTrue($actual);
        }
    }
}
