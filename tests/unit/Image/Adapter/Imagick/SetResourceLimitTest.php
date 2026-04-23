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
use Phalcon\Image\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

use function supportDir;

final class SetResourceLimitTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageAdapterImagickSetResourceLimitException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Cannot set the Resource Type for this image'
        );

        $source = supportDir('assets/images/example-jpg.jpg');
        $image  = new Imagick($source);

        $image->setResourceLimit(100, 1);
    }
}
