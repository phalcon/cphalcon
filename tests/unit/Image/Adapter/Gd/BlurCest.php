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

class BlurCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: blur()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdBlur(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - blur()');

        $params = [
            'jpg' => [
                [1, '424556b7c8c854850e4adc6b28a5ce1b'],
                [2, '96cae9c251abbc20f232936d4c1dfb0d'],
                [5, 'aada4fe1b7d69a8b24f6784d1033e501'],
            ],
            'png' => [
                [1, '73d7bc80509b72672091c08c6ae5ef17'],
                [2, '82a57800ff1ca4f09a9214830d59b46e'],
                [5, 'c28c252bde26e3d506f29cad746ad191'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as list($level, $md5)) {
                $resultImage = 'blur-' . $level . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->blur($level)->save($output);

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
