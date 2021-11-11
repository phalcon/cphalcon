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

namespace Phalcon\Tests\Unit\Html\Escaper;

use Codeception\Example;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class DetectEncodingCest
 *
 * @package Phalcon\Tests\Unit\Html\Escaper
 */
class DetectEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: detectEncoding()
     *
     * @dataProvider escaperDetectEncodingProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function escaperDetectEncoding(UnitTester $I, Example $example)
    {
        $I->wantToTest('Escaper - detectEncoding()');

        $escaper = new Escaper();

        $source   = $example['source'];
        $expected = $example['expected'];
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    private function escaperDetectEncodingProvider(): array
    {
        return [
            [
                'source'   => 'ḂḃĊċḊḋḞḟĠġṀṁ',
                'expected' => 'UTF-8',
            ],

            [
                'source'   => chr(172) . chr(128) . chr(159) . 'ḂḃĊċḊḋḞḟĠġṀṁ',
                'expected' => 'ISO-8859-1',
            ],

            [
                'source'   => '\0\0\0H\0\0\0i',
                'expected' => 'UTF-8',
            ],
        ];
    }
}
