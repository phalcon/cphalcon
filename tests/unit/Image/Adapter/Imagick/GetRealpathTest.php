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

final class GetRealpathTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-02-19
     */
    public function testImageAdapterImagickGetRealpath(): void
    {
        $source = supportDir('assets/images/example-jpg.jpg');
        $source = str_replace('/', DIRECTORY_SEPARATOR, $source);
        $image  = new Imagick($source);

        $actual = $image->getRealpath();
        $this->assertSame($source, $actual);
    }
}
