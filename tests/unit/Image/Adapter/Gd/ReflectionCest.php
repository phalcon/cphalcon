<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class ReflectionCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: reflection()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdReflection(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - reflection()');

        $params = [
            'jpg' => [
                [100, 75, false, 'ee03ed1356319622eb4afdbc3df97763'],
                [100, 75, true, 'ee03ed1356319622eb4afdbc3df97763'],
                [60, 40, false, '721bd5766f4c63378532dc8aa2f19cea'],
                [60, 40, true, '721bd5766f4c63378532dc8aa2f19cea'],
            ],
            'png' => [
                [10, 75, false, 'cae4fe2091be1f202d4f129323d28552'],
                [10, 75, true, '6f310fbd54b8cf2d58096db28e7197ba'],
                [30, 40, false, '1161b35d84280641b5125544b63965e8'],
                [30, 40, true, '0c515780919d5e5f7bfee81cd1a33199'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as list($height, $opacity, $fade, $md5)) {
                $resultImage = 'reflection-' . $height . '-' . $opacity . '-' . ((int)$fade) . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->reflection($height, $opacity, $fade)->save($output);

                $I->amInPath(
                    outputDir($outputDir)
                );

                $I->seeFileFound($resultImage);

                $I->assertSame(
                    $md5,
                    md5_file($output)
                );

                $I->safeDeleteFile($output);
            }
        }
    }
}
