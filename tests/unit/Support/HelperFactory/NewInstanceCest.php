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

namespace Phalcon\Test\Unit\Support\HelperFactory;

use Codeception\Example;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Helper\Str\Interpolate;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Support :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\HelperFactory - newInstance() - ' . $example[0]);

        $factory = new HelperFactory();

        $expected = $example[1];
        $actual   = $factory->newInstance($example[0]);
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * @return \string[][]
     */
    private function getExamples(): array
    {
        return [
            [
                'interpolate',
                Interpolate::class,
            ],
        ];
    }
}
