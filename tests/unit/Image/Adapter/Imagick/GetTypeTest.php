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
use PHPUnit\Framework\Attributes\DataProvider;

final class GetTypeTest extends AbstractUnitTestCase
{
    use ImagickTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                Talon::settings()->supportPath('assets/images/example-gif.gif'),
            ],
            [
                Talon::settings()->supportPath('assets/images/example-jpg.jpg'),
            ],
            [
                Talon::settings()->supportPath('assets/images/example-png.png'),
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-02-19
     */
    #[DataProvider('getExamples')]
    #[DataProvider('getExamples')]
    public function testImageAdapterImagickGetType(string $source): void
    {
        $image = new Imagick($source);

        $actual = $image->getType();
        $this->assertIsInt($actual);
        $this->assertGreaterThan(0, $actual);
    }
}
