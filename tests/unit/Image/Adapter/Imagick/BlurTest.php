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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\ImagickTrait;

use function outputDir;
use function supportDir;

final class BlurTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickBlur(): void
    {
        $source = supportDir('assets/images/example-jpg.jpg');
        $output = outputDir('tests/image/imagick/blur.jpg');

        $image = new Imagick($source);
        $image->setResourceLimit(6, 1);

        $image->blur(2)
              ->save($output)
        ;

        $this->assertFileExists($output);

        $this->safeDeleteFile($output);
    }
}
