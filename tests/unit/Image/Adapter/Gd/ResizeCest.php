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

class ResizeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: resize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdResizeJpg(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - resize() - jpg image');

        $image = new Gd(
            dataDir('assets/images/phalconphp.jpg')
        );

        $outputDir = 'tests/image/gd';
        $width     = 200;
        $height    = 200;

        // Resize to 200 pixels on the shortest side
        $image->resize($width, $height)->save(outputDir($outputDir . '/resize.jpg'));

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound('resize.jpg');

        $I->assertLessThanOrEqual(
            $width,
            $image->getWidth()
        );

        $I->assertLessThanOrEqual(
            $height,
            $image->getHeight()
        );

        $I->safeDeleteFile('resize.jpg');
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: resize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdResizePng(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - resize() - png image');

        $image = new Gd(
            dataDir('assets/images/logo.png')
        );

        $outputDir = 'tests/image/gd';
        $width     = 50;
        $height    = 50;

        // Resize to 50 pixels on the shortest side
        $image->resize($width, $height)->save(outputDir($outputDir . '/resize.jpg'));

        $I->amInPath(
            outputDir($outputDir)
        );

        $I->seeFileFound('resize.jpg');

        $I->assertLessThanOrEqual(
            $width,
            $image->getWidth()
        );

        $I->assertLessThanOrEqual(
            $height,
            $image->getHeight()
        );

        $I->safeDeleteFile('resize.jpg');
    }
}
