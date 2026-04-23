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
use PHPUnit\Framework\Attributes\DataProvider;

use function supportDir;

final class GetMimeTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                supportDir('assets/images/example-gif.gif'),
                'image/GIF',
            ],
            [
                supportDir('assets/images/example-jpg.jpg'),
                'image/JPEG',
            ],
            [
                supportDir('assets/images/example-png.png'),
                'image/PNG',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-02-19
     */
    #[DataProvider('getExamples')]
    public function testImageAdapterImagickGetMime(
        string $source,
        string $expected
    ): void {
        $image = new Imagick($source);

        $actual = $image->getMime();
        $this->assertSame($expected, $actual);
    }
}
