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
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

use function dataDir;
use function outputDir;

class TextCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: text()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdText(UnitTester $I, Example $example)
    {
        $I->wantToTest('Image\Adapter\Gd - text()');

        $this->checkJpegSupport($I);

        $outputDir   = 'tests/image/gd';
        $image       = new Gd(dataDir('assets/images/phalconphp.jpg'));
        $index       = $example['index'];
        $outputImage = $index . 'text.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);

        $image
            ->text(
                $example['text'],
                $example['offsetX'],
                $example['offsetY'],
                $example['opacity'],
                $example['color'],
                $example['size'],
                $example['font']
            )
              ->save($output)
        ;

        $I->amInPath(outputDir($outputDir));
        $I->seeFileFound($outputImage);

        $I->assertTrue($this->checkImageHash($output, $example['hash']));
        $I->safeDeleteFile($outputImage);
    }

    /**
     * Tests Phalcon\Image\Adapter\Gd :: text()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     * @issue  15188
     */
    public function imageAdapterGdTextWithFont(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - text() - with font');

        $this->checkJpegSupport($I);

        $outputDir = 'tests/image/gd';


        $image       = dataDir('assets/images/phalconphp.jpg');
        $outputImage = '15188-text.jpg';
        $output      = outputDir($outputDir . '/' . $outputImage);
        $text        = 'Hello Phalcon!';
        $offsetX     = 50;
        $offsetY     = 75;
        $opacity     = 60;
        $color       = '0000FF';
        $size        = 24;
        $font        = dataDir('assets/fonts/Roboto-Light.ttf');
        $hash        = 'fbf9f3e3c3c18183';

        $object = new Gd($image);
        $object
            ->text($text, $offsetX, $offsetY, $opacity, $color, $size, $font)
            ->save($output)
        ;

        $I->amInPath(outputDir($outputDir));
        $I->seeFileFound($outputImage);

        $I->assertTrue($this->checkImageHash($output, $hash));
        $I->safeDeleteFile($outputImage);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'index'   => 1,
                'text'    => 'Hello Phalcon!',
                'offsetX' => false,
                'offsetY' => false,
                'opacity' => 100,
                'color'   => '000000',
                'size'    => 12,
                'font'    => null,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
            [
                'index'   => 2,
                'text'    => 'Hello Phalcon!',
                'offsetX' => 50,
                'offsetY' => false,
                'opacity' => 100,
                'color'   => '000000',
                'size'    => 12,
                'font'    => null,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
            [
                'index'   => 3,
                'text'    => 'Hello Phalcon!',
                'offsetX' => 50,
                'offsetY' => 75,
                'opacity' => 100,
                'color'   => '000000',
                'size'    => 12,
                'font'    => null,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
            [
                'index'   => 4,
                'text'    => 'Hello Phalcon!',
                'offsetX' => 50,
                'offsetY' => 75,
                'opacity' => 60,
                'color'   => '000000',
                'size'    => 12,
                'font'    => null,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
            [
                'index'   => 5,
                'text'    => 'Hello Phalcon!',
                'offsetX' => 50,
                'offsetY' => 75,
                'opacity' => 60,
                'color'   => '00FF00',
                'size'    => 12,
                'font'    => null,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
            [
                'index'   => 6,
                'text'    => 'Hello Phalcon!',
                'offsetX' => 50,
                'offsetY' => 75,
                'opacity' => 60,
                'color'   => '0000FF',
                'size'    => 24,
                'font'    => null,
                'hash'    => 'fbf9f3e3c3c18183',
            ],
        ];
    }
}
