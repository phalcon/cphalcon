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

use Phalcon\Image;
use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class FlipCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: flip()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdFlip(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - flip()');

        $params = [
            'jpg' => [
                [Image::HORIZONTAL, 'de60965c3f89164f3709c8826b2e62c5'],
                [Image::VERTICAL, '93b3e9033a359ab3594c06482ceabd5e'],
            ],
            'png' => [
                [Image::HORIZONTAL, '8f1d9613781b45bb0be1509613d45aef'],
                [Image::VERTICAL, '27f30b2172484a98d0beb14e08ce0880'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as list($direction, $md5)) {
                $resultImage = 'flip-' . $direction . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->flip($direction)->save($output);

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
