<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Image;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/850
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getOffsets(): array
    {
        return [
            'null'   => [null],
            'string' => ['10'],
            'float'  => [1.5],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getOffsets')]
    public function testImageAdapterCropOffsets(mixed $offset): void
    {
        $image = new Gd(
            Talon::settings()->supportPath('assets/images/example-jpg.jpg')
        );

        $image->crop(100, 100, $offset, $offset);

        $this->assertSame(100, $image->getWidth());
        $this->assertSame(100, $image->getHeight());
    }
}
