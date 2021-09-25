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

namespace Phalcon\Tests\Unit\Escaper;

use Codeception\Example;
use Phalcon\Escaper;
use UnitTester;

class DetectEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: detectEncoding()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-16
     *
     * @dataProvider escaperDetectEncodingProvider
     */
    public function escaperDetectEncoding(UnitTester $I, Example $example)
    {
        $I->wantToTest('Escaper - detectEncoding()');

        $escaper = new Escaper();

        $I->assertEquals(
            $example['expected'],
            $escaper->detectEncoding(
                $example['source']
            )
        );
    }

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
