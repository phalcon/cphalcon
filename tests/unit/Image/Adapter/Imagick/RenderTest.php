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

use function supportDir;

final class RenderTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickRender(): void
    {
        $source = supportDir('assets/images/example-jpg.jpg');
        $image  = new Imagick($source);
        $image->setResourceLimit(6, 1);

        $result = $image->render('jpg', 75);

        $this->assertNotEmpty($result);
        $this->assertIsString($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageAdapterImagickRenderDefaultExtension(): void
    {
        $source = supportDir('assets/images/example-jpg.jpg');
        $image  = new Imagick($source);
        $image->setResourceLimit(6, 1);

        $result = $image->render();

        $this->assertNotEmpty($result);
        $this->assertIsString($result);
    }
}
