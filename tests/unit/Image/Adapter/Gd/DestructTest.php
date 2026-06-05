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
use ReflectionProperty;

final class DestructTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testImageAdapterGdDestruct(): void
    {
        foreach ($this->getImages() as $image) {
            $gd = new Gd($image);

            $property = new ReflectionProperty($gd, 'image');
            $property->setAccessible(true);
            $this->assertNotNull($property->getValue($gd));

            $gd->__destruct();

            $this->assertNull($property->getValue($gd));
        }
    }
}
