<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Interpolator;

use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Interpolator\IndexedArray;
use UnitTester;

class IndexedArrayCest
{
    private $config = null;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->config = [
            'ru' => [
                'Hello!'          => 'Привет!',
                'Hello %s %s %s!' => 'Привет, %s %s %s!',
            ],
        ];
    }

    public function testIndexedArrayInterpolator(UnitTester $I)
    {
        $language   = $this->config['ru'];
        $params     = ['content' => $language, 'interpolator' => new IndexedArray()];
        $translator = new NativeArray($params);

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->_(
            'Hello %s %s %s!',
            [
                'John',
                'D.',
                'Doe',
            ]
        );

        $I->assertEquals($expected, $actual);
    }

    public function testReplacePlaceholders(UnitTester $I)
    {
        $interpolator = new IndexedArray();

        $expected = 'Hello, John D. Doe!';

        $stringFrom = 'Hello, %s %s %s!';
        $actual     = $interpolator->replacePlaceholders($stringFrom, ['John', 'D.', 'Doe']);


        $I->assertEquals($expected, $actual);
    }
}
