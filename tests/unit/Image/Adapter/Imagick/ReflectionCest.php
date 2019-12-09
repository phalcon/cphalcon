<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Test\Fixtures\Traits\ImagickTrait;
use UnitTester;

use function dataDir;
use function outputDir;

class ReflectionCest
{
    use ImagickTrait;

    /**
     * Tests Phalcon\Image\Adapter\Imagick :: reflection()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function imageAdapterImagickReflection(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - reflection()');

        $image = new Imagick(
            dataDir('assets/images/phalconphp.jpg')
        );

        $image->setResourceLimit(6, 1);

        // Create a 50 pixel reflection that fades from 0-100% opacity
        $image->reflection(50)->save(outputDir('tests/image/imagick/reflection.jpg'));

        $I->amInPath(
            outputDir('tests/image/imagick/')
        );

        $I->seeFileFound('reflection.jpg');

        $I->assertGreaterThan(
            200,
            $image->getWidth()
        );

        $I->assertGreaterThan(
            200,
            $image->getHeight()
        );

        $I->safeDeleteFile('reflection.jpg');
    }
}
