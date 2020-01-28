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

namespace Phalcon\Test\Unit\Annotations\AnnotationsFactory;

use Codeception\Example;
use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\AnnotationsFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Annotations\AdapterFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-19
     */
    public function annotationsAdapterFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Annotations\AdapterFactory - newInstance() - ' . $example[0]);

        $factory = new AnnotationsFactory();
        $name    = 'apcu';

        $image = $factory->newInstance($example[0]);

        $I->assertInstanceOf(
            $example[1],
            $image
        );
    }

    private function getExamples(): array
    {
        return [
            [
                'apcu',
                Apcu::class,
            ],
            [
                'memory',
                Memory::class,
            ],
            [
                'stream',
                Stream::class,
            ],
        ];
    }
}
