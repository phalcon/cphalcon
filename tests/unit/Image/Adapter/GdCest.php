<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Image\Adapter;

use Phalcon\Image;
use Phalcon\Image\Adapter\Gd;
use UnitTester;

class GdTest
{
    /**
     * executed before each test
     */
    protected function _before(UnitTester $I, $scenario)
    {
        if (!function_exists('gd_info')) {
            $scenario->skip('Warning: gd extension is not loaded');
        }
    }

    /**
     * Tests create a new image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdSave(UnitTester $I)
    {
        $image = new Gd(PATH_OUTPUT . 'tests/image/gd/new.jpg', 100, 100);
        $image->save();

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('new.jpg');
        $I->deleteFile('new.jpg');
    }

    /**
     * Tests resize image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdResize(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Resize to 200 pixels on the shortest side
        $image->resize(200, 200)->save(PATH_OUTPUT . 'tests/image/gd/resize.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('resize.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/resize.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width <= 200;
        $I->assertTrue($actual);
        $actual = $height <= 200;
        $I->assertTrue($actual);
        $I->deleteFile('resize.jpg');
    }

    /**
     * Tests crop image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdCrop(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Crop the image to 200x200 pixels, from the center
        $image->crop(200, 200)->save(PATH_OUTPUT . 'tests/image/gd/crop.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('crop.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/crop.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $expected = 200;
        $actual   = $width;
        $I->assertEquals($expected, $actual);
        $expected = 200;
        $actual   = $height;
        $I->assertEquals($expected, $actual);

        $actual = $image->getWidth() == 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() == 200;
        $I->assertTrue($actual);
        $I->deleteFile('crop.jpg');
    }

    /**
     * Tests rotate image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdRotate(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Rotate 45 degrees clockwise
        $image->rotate(45)->save(PATH_OUTPUT . 'tests/image/gd/rotate.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('rotate.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/rotate.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('rotate.jpg');
    }

    /**
     * Tests flip image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdFlip(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Flip the image from top to bottom
        $image->flip(Image::HORIZONTAL)->save(PATH_OUTPUT . 'tests/image/gd/flip.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('flip.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/flip.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('flip.jpg');
    }

    /**
     * Tests sharpen image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdSharpen(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Sharpen the image by 20%
        $image->sharpen(20)->save(PATH_OUTPUT . 'tests/image/gd/sharpen.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('sharpen.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/sharpen.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('sharpen.jpg');
    }

    /**
     * Tests reflection image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdReflection(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Create a 50 pixel reflection that fades from 0-100% opacity
        $image->reflection(50)->save(PATH_OUTPUT . 'tests/image/gd/reflection.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('reflection.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/reflection.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('reflection.jpg');
    }

    /**
     * Tests watermark
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdWatermark(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');
        $mark = new Gd(PATH_DATA . 'assets/logo.png');

        // Add a watermark to the bottom right of the image
        $image->watermark($mark, true, true)->save(PATH_OUTPUT . 'tests/image/gd/watermark.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('watermark.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/watermark.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('watermark.jpg');
    }

    /**
     * Tests mask
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdMask(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');
        $mask = new Gd(PATH_DATA . 'assets/logo.png');

        // Add a watermark to the bottom right of the image
        $image->mask($mask)->save(PATH_OUTPUT . 'tests/image/gd/mask.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('mask.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/mask.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('mask.jpg');
    }

    /**
     * Tests background
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdBackground(UnitTester $I)
    {
        $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

        // Add a watermark to the bottom right of the image
        $image->background('#000')->save(PATH_OUTPUT . 'tests/image/gd/background.jpg');

        $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
        $I->seeFileFound('background.jpg');

        $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/background.jpg');
        $width = imagesx($tmp);
        $height = imagesy($tmp);

        $actual = $width > 200;
        $I->assertTrue($actual);
        $actual = $height > 200;
        $I->assertTrue($actual);

        $actual = $image->getWidth() > 200;
        $I->assertTrue($actual);
        $actual = $image->getHeight() > 200;
        $I->assertTrue($actual);

        $I->deleteFile('background.jpg');
    }
}
