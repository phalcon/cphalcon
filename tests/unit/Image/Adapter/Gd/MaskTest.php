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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

final class MaskTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdMask(): void
    {
        $this->checkJpegSupport();

        $image = new Gd(supportDir('assets/images/example-png.png'));
        $mask  = new Gd(supportDir('assets/images/example-jpg.jpg'));

        $outputDir   = 'tests/image/gd/';
        $outputImage = 'mask.png';
        $output      = outputDir($outputDir . '/' . $outputImage);

        $hash = '30787c3c3f191810';

        // Resize to 200 pixels on the shortest side
        $mask->mask($image)
             ->save($output)
        ;

        $this->assertFileExists(outputDir($outputDir) . $outputImage);

        $actual = $this->checkImageHash($output, $hash);
        $this->assertTrue($actual);

        $this->safeDeleteFile($output);
    }
}
