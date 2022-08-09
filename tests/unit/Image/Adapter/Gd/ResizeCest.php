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

use Codeception\Example;
use Phalcon\Image\Adapter\Gd;
use Phalcon\Image\Enum;
use Phalcon\Image\Exception;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

use function dataDir;

class ResizeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: resize()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @return void
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function imageAdapterGdResize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Image\Adapter\Gd - resize() - ' . $example['label']);

        $this->checkJpegSupport($I);

        $file   = $example['file'];
        $source = $example['source'];
        $width  = $example['width'];
        $height = $example['height'];
        $hash   = $example['hash'];

        $outputDir = 'tests/image/gd';
        $output    = outputDir($outputDir . '/' . $file);

        $image = new Gd($source);

        $image->resize($width, $height)
              ->save($output)
        ;

        $I->amInPath(outputDir($outputDir));
        $I->seeFileFound($file);

        $actual = $image->getWidth();
        $I->assertSame($width, $actual);

        $actual = $image->getHeight();
        $I->assertSame($height, $actual);

        $actual = $this->checkImageHash($output, $hash);
        $I->assertTrue($actual);

        $I->safeDeleteFile($file);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: resize()
     *
     * @dataProvider getExamplesExceptions
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @return void
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function imageAdapterGdResizeExceptions(UnitTester $I, Example $example)
    {
        $I->wantToTest('Image\Adapter\Gd - resize() - exceptions - ' . $example['label']);

        $this->checkJpegSupport($I);

        $master  = $example['master'];
        $width   = $example['width'];
        $height  = $example['height'];
        $message = $example['message'];

        $source = dataDir('assets/images/example-jpg.jpg');
        $image  = new Gd($source);

        $I->expectThrowable(
            new Exception($message),
            function () use ($image, $width, $height, $master) {
                $image->resize($width, $height, $master);
            }
        );
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'label'  => 'jpg',
                'source' => dataDir('assets/images/example-jpg.jpg'),
                'file'   => 'resize.jpg',
                'height' => 75,
                'width'  => 199,
                'hash'   => 'fbf9f3e3c3c1c183',
            ],
            [
                'label'  => 'png',
                'source' => dataDir('assets/images/example-png.png'),
                'file'   => 'resize.jpg',
                'height' => 50,
                'width'  => 50,
                'hash'   => 'bf9f8fc5bf9bc0d0',
            ],
        ];
    }

    /**
     * @return array[]
     */
    private function getExamplesExceptions(): array
    {
        return [
            [
                'label'   => 'TENSILE',
                'master'  => Enum::TENSILE,
                'height'  => null,
                'width'   => 199,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'TENSILE',
                'master'  => Enum::TENSILE,
                'height'  => 199,
                'width'   => null,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'AUTO',
                'master'  => Enum::AUTO,
                'height'  => null,
                'width'   => 199,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'AUTO',
                'master'  => Enum::AUTO,
                'height'  => 199,
                'width'   => null,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'INVERSE',
                'master'  => Enum::INVERSE,
                'height'  => null,
                'width'   => 199,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'INVERSE',
                'master'  => Enum::INVERSE,
                'height'  => 199,
                'width'   => null,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'PRECISE',
                'master'  => Enum::PRECISE,
                'height'  => null,
                'width'   => 199,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'PRECISE',
                'master'  => Enum::PRECISE,
                'height'  => 199,
                'width'   => null,
                'message' => 'width and height must be specified',
            ],
            [
                'label'   => 'WIDTH',
                'master'  => Enum::WIDTH,
                'height'  => 199,
                'width'   => null,
                'message' => 'width must be specified',
            ],
            [
                'label'   => 'HEIGHT',
                'master'  => Enum::HEIGHT,
                'height'  => null,
                'width'   => 199,
                'message' => 'height must be specified',
            ],
        ];
    }
}
