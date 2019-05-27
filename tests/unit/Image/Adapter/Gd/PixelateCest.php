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
use UnitTester;

class PixelateCest
{
    /**
     * Tests Phalcon\Image\Adapter\Gd :: pixelate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdPixelate(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - pixelate()');

        $params = [
            [7, 'da12b2b4a80803ab3c2d8306b7df4157'],
            [21, '12acefc11dc6cbb93186402612f17566'],
            [35, '94dcaa6b3d3117aad79b9f4b90886682'],
            [60, '3832ac0fd32441252b8ddde56980f36d'],
        ];
        foreach ($params as list($amount, $md5)) {
            $image = new Gd(
                dataDir('assets/images/phalconphp.jpg')
            );

            $outputDir   = 'tests/image/gd';
            $outputImage = $amount . '-pixelate.jpg';
            $output      = outputDir($outputDir . '/' . $outputImage);

            $image->pixelate($amount)->save($output);

            $I->amInPath(
                outputDir($outputDir)
            );

            $I->seeFileFound($outputImage);

            $I->assertSame(
                $md5,
                md5_file($output),
                'Checking MD5'
            );

            $I->safeDeleteFile($outputImage);
        }
    }
}
