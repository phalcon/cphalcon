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

class RotateCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: rotate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdRotate(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - rotate()');

        $params = [
            'jpg' => [
                [0, '3df18f591c4c8d166f3d9e08dec118cb'],
                [45, '9adc6f82d097800e5a13f59e873eb905'],
                [90, 'de4ba68f1ebae8b4ed158be67d5d504a'],
                [180, '26f83d7a5157a469e6d07b71cb296cae'],
                [270, 'e41b1e28fa8df37223818c4eb3ff17eb'],
            ],
            'png' => [
                [0, '17909972f73be3698ad96bcd18e043f0'],
                [45, '32bc2f284c213d5d0e674e46a4af3672'],
                [90, '6aeb9ab424a852701a2449f7d8db71f1'],
                [180, '4508bdd74d338a685a5268cc1caee604'],
                [270, 'f90e485c532fdbec85ad22bfaf87b7cd'],
            ],
        ];

        $outputDir = 'tests/image/gd';

        foreach ($this->getImages() as $type => $imagePath) {
            foreach ($params[$type] as list($degrees, $md5)) {
                $resultImage = 'rotate-' . $degrees . '.' . $type;
                $output      = outputDir($outputDir . '/' . $resultImage);

                $image = new Gd($imagePath);

                $image->rotate($degrees)->save($output);

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
