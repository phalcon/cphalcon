<?php

namespace Phalcon\Test\Unit\Image\Adapter;

use Phalcon\Image;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Image\Adapter\Gd;

/**
 * \Phalcon\Test\Unit\Image\Adapter\GdTest
 * Tests the \Phalcon\Image\Adapter\Gd component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Image\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class GdTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        if (!function_exists('gd_info')) {
            $this->markTestSkipped('Warning: gd extension is not loaded');
        }
    }

    /**
     * Tests create a new image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdSave()
    {
        $this->specify(
            "Gd::save does not create a new image",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_OUTPUT . 'tests/image/gd/new.jpg', 100, 100);
                $image->save();

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('new.jpg');
                $I->deleteFile('new.jpg');
            }
        );
    }

    /**
     * Tests resize image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdResize()
    {
        $this->specify(
            "Gd::resize does not resize image correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Resize to 200 pixels on the shortest side
                $image->resize(200, 200)->save(PATH_OUTPUT . 'tests/image/gd/resize.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('resize.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/resize.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width <= 200)->true();
                expect($height <= 200)->true();

                expect($image->getWidth() <= 200)->true();
                expect($image->getHeight() <= 200)->true();

                $I->deleteFile('resize.jpg');
            }
        );
    }

    /**
     * Tests crop image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdCrop()
    {
        $this->specify(
            "Gd::crop does not crop image correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Crop the image to 200x200 pixels, from the center
                $image->crop(200, 200)->save(PATH_OUTPUT . 'tests/image/gd/crop.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('crop.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/crop.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width)->equals(200);
                expect($height)->equals(200);

                expect($image->getWidth() == 200)->true();
                expect($image->getHeight() == 200)->true();

                $I->deleteFile('crop.jpg');
            }
        );
    }

    /**
     * Tests rotate image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdRotate()
    {
        $this->specify(
            "Gd::rotate does not rotate image correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Rotate 45 degrees clockwise
                $image->rotate(45)->save(PATH_OUTPUT . 'tests/image/gd/rotate.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('rotate.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/rotate.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('rotate.jpg');
            }
        );
    }

    /**
     * Tests flip image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdFlip()
    {
        $this->specify(
            "Gd::flip does not flip image correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Flip the image from top to bottom
                $image->flip(Image::HORIZONTAL)->save(PATH_OUTPUT . 'tests/image/gd/flip.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('flip.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/flip.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('flip.jpg');
            }
        );
    }

    /**
     * Tests sharpen image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdSharpen()
    {
        $this->specify(
            "Gd::sharpen does not sharpe image correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Sharpen the image by 20%
                $image->sharpen(20)->save(PATH_OUTPUT . 'tests/image/gd/sharpen.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('sharpen.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/sharpen.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('sharpen.jpg');
            }
        );
    }

    /**
     * Tests reflection image
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdReflection()
    {
        $this->specify(
            "Gd::reflection does not reflect image correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Create a 50 pixel reflection that fades from 0-100% opacity
                $image->reflection(50)->save(PATH_OUTPUT . 'tests/image/gd/reflection.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('reflection.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/reflection.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('reflection.jpg');
            }
        );
    }

    /**
     * Tests watermark
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdWatermark()
    {
        $this->specify(
            "Gd::watermark does not create watermark correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');
                $mark = new Gd(PATH_DATA . 'assets/logo.png');

                // Add a watermark to the bottom right of the image
                $image->watermark($mark, true, true)->save(PATH_OUTPUT . 'tests/image/gd/watermark.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('watermark.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/watermark.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('watermark.jpg');
            }
        );
    }

    /**
     * Tests mask
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdMask()
    {
        $this->specify(
            "Gd::mask does not create mask correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');
                $mask = new Gd(PATH_DATA . 'assets/logo.png');

                // Add a watermark to the bottom right of the image
                $image->mask($mask)->save(PATH_OUTPUT . 'tests/image/gd/mask.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('mask.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/mask.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('mask.jpg');
            }
        );
    }

    /**
     * Tests background
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-19
     */
    public function testGdBackground()
    {
        $this->specify(
            "Gd::background does not create background correctly",
            function () {
                $I = $this->tester;

                $image = new Gd(PATH_DATA . 'assets/phalconphp.jpg');

                // Add a watermark to the bottom right of the image
                $image->background('#000')->save(PATH_OUTPUT . 'tests/image/gd/background.jpg');

                $I->amInPath(PATH_OUTPUT . 'tests/image/gd/');
                $I->seeFileFound('background.jpg');

                $tmp = imagecreatefromjpeg(PATH_OUTPUT . 'tests/image/gd/background.jpg');
                $width = imagesx($tmp);
                $height = imagesy($tmp);

                expect($width > 200)->true();
                expect($height > 200)->true();

                expect($image->getWidth() > 200)->true();
                expect($image->getHeight() > 200)->true();

                $I->deleteFile('background.jpg');
            }
        );
    }
}
