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

class SharpenCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: sharpen()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdSharpen(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - sharpen()');

        $outputDir = 'tests/image/gd';
        $params = [
            [10, '9b94b582851e0df3d06960abae30ce7a'],
            [50, '2f39d4ccd43c058ca243f784f61b8487'],
            [100, '71fe7f3643aee3af73f30b7b53795e82'],
        ];
        $i = 0;

        foreach ($params as list($amount, $md5)) {
            $image = new Gd(
                dataDir('assets/images/phalconphp.jpg')
            );

            $outputImage = $i++ . 'sharpen.jpg';
            $output = outputDir($outputDir . '/' . $outputImage);

            $image->sharpen($amount)
                ->save($output);

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
