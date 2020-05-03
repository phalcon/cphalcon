<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Translate\InterpolatorFactory;

use Codeception\Example;
use Phalcon\Factory\Exception;
use Phalcon\Translate\Interpolator\AssociativeArray;
use Phalcon\Translate\Interpolator\IndexedArray;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Translate\InterpolatorFactory :: newInstance()
     *
     * @param        UnitTester $I
     * @param        Example $example
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-18
     */
    public function translateInterpolatorFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Translate\InterpolatorFactory - newInstance() - ' . $example[0]);

        $adapter = new InterpolatorFactory();
        $service = $adapter->newInstance($example[0]);

        $class = $example[1];
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Translate\InterpolatorFactory :: newInstance() - exception
     *
     * @param        UnitTester $I
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-18
     */
    public function translateInterpolatorFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Translate\InterpolatorFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('Service unknown is not registered'),
            function () {
                $adapter = new InterpolatorFactory();
                $adapter->newInstance('unknown');
            }
        );
    }

    private function getExamples(): array
    {
        return [
            ['associativeArray', AssociativeArray::class],
            ['indexedArray', IndexedArray::class],
        ];
    }
}
