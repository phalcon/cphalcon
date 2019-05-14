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

class RotateCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: rotate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-02-19
     */
    public function imageAdapterImagickRotate(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - rotate()');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Rotate 45 degrees clockwise
        $image->rotate(45)->save(outputDir('tests/image/imagick/rotate.jpg'));

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('rotate.jpg');

        $I->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $I->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('rotate.jpg');
    }
}
