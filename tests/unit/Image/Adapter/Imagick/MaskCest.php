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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use function dataDir;
use function outputDir;
use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Fixtures\Traits\ImagickTrait;
use UnitTester;

class MaskCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: mask()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function imageAdapterImagickMask(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - mask()');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        $mask = new Imagick(
            dataDir('assets/images/logo.png')
        );

        // Add a watermark to the bottom right of the image
        $image->mask($mask)->save(outputDir('tests/image/imagick/mask.jpg'));

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('mask.jpg');

        $I->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $I->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('mask.jpg');
    }
}
