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

namespace Phalcon\Tests\Unit\Image\Adapter\Imagick;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

final class SaveTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickSave(): void
    {
        $image = new Imagick(Talon::settings()->outputPath('tests/image/imagick/new.jpg'), 100, 100);
        $image->setResourceLimit(6, 1);
        $image->save();

        $this->assertFileExists(
            Talon::settings()->outputPath('tests/image/imagick/new.jpg')
        );
        $this->safeDeleteFile('new.jpg');
    }
}
