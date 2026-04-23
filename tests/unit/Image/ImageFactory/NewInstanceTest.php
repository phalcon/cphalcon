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

namespace Phalcon\Tests\Unit\Image\ImageFactory;

use Phalcon\Image\Adapter\Imagick;
use Phalcon\Image\Exception;
use Phalcon\Image\ImageFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function supportDir;
use function uniqid;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function testImageImageFactoryNewInstance(): void
    {
        $this->checkExtensionIsLoaded('imagick');

        $factory = new ImageFactory();
        $file    = supportDir('assets/images/example-jpg.jpg');
        $file    = str_replace("/", DIRECTORY_SEPARATOR, $file);
        $name    = 'imagick';

        $image = $factory->newInstance($name, $file);

        $class = Imagick::class;
        $this->assertInstanceOf($class, $image);

        $expected = $file;
        $actual   = $image->getRealPath();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-08-02
     */
    public function testImageImageFactoryNewInstanceException(): void
    {
        $this->checkExtensionIsLoaded('imagick');

        $name = uniqid('service-');
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Service ' . $name . ' is not registered');

        $factory = new ImageFactory();
        $factory->newInstance($name, uniqid('file-'));
    }
}
