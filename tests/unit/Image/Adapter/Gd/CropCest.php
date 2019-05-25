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

class CropCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop()');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir = 'tests/image/gd';
        $width     = 200;
        $height    = 200;
        $cropImage = 'crop.jpg';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $md5       = '58de018ca54ed429032544c5c9f6e309';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height)->save(outputDir($outputDir . '/' . $cropImage));

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth()
        );

        $I->assertSame(
            $height,
            $image->getHeight()
        );

        $I->assertSame(
            $md5,
            md5_file($output),
            'MD5 checksum'
        );

        $I->safeDeleteFile($cropImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropJpgWithOffset(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop()');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir = 'tests/image/gd';
        $width     = 200;
        $height    = 200;
        $offsetX   = 200;
        $offsetY   = 200;
        $cropImage = 'crop.jpg';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $md5       = '9d16cdd5878348812e5e602b6e21b603';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height, $offsetX, $offsetY)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth(),
            'Check width'
        );

        $I->assertSame(
            $height,
            $image->getHeight(),
            'Check height'
        );

        $I->assertSame(
            $md5,
            md5_file($output),
            'MD5 checksum'
        );

        $I->safeDeleteFile($cropImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropPng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop() - png image');

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $outputDir = 'tests/image/gd';
        $width     = 40;
        $height    = 40;
        $cropImage = 'crop.png';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $md5       = '7c16dbb681d89358c8522384c5829155';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height)->save(outputDir($outputDir . '/' . $cropImage));

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth()
        );

        $I->assertSame(
            $height,
            $image->getHeight()
        );

        $I->assertSame(
            $md5,
            md5_file($output),
            'MD5 checksum'
        );

        $I->safeDeleteFile($cropImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: crop()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdCropPngWithOffset(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - crop()');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir = 'tests/image/gd';
        $width     = 42;
        $height    = 42;
        $offsetX   = 25;
        $offsetY   = 25;
        $cropImage = 'crop.png';
        $output    = outputDir($outputDir . '/' . $cropImage);
        $md5       = '7207a8d735abdfb3fcaf744cd71e15d3';

        // Resize to 200 pixels on the shortest side
        $image->crop($width, $height, $offsetX, $offsetY)->save($output);

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound($cropImage);

        $I->assertSame(
            $width,
            $image->getWidth(),
            'Check width'
        );

        $I->assertSame(
            $height,
            $image->getHeight(),
            'Check height'
        );

        $I->assertSame(
            $md5,
            md5_file($output),
            'MD5 checksum'
        );

        $I->safeDeleteFile($cropImage);
    }
}
