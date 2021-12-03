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

namespace Phalcon\Tests\Unit\Di;

use Codeception\Example;
use Phalcon\Di;
use Phalcon\Di\Exception;
use Phalcon\Html\Escaper;
use Phalcon\Support\Collection;
use UnitTester;

/**
 * Class SetCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class SetCest
{
    /**
     * Unit Tests Phalcon\Di :: set()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-09-09
     */
    public function diSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Di - set() - ' . $example[0]);

        $container = new Di();

        // set non shared service
        $container->set($example[1], $example[2]);

        $class  = $example[3];
        $actual = $container->get($example[1]);
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Unit Tests Phalcon\Di :: set() - shared
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diSetShared(UnitTester $I)
    {
        $I->wantToTest('Di - set() - shared');

        $container = new Di();

        // set non shared service
        $container->set('escaper', Escaper::class);

        $class  = Escaper::class;
        $actual = $container->get('escaper');
        $I->assertInstanceOf($class, $actual);

        $escaper = $container->getService('escaper');
        $actual  = $escaper->isShared();
        $I->assertFalse($actual);

        // set shared service
        $container->set('collection', Collection::class, true);

        $class  = Collection::class;
        $actual = $container->get('collection');
        $I->assertInstanceOf($class, $actual);

        $collection = $container->getService('collection');
        $actual     = $collection->isShared();
        $I->assertTrue($actual);
    }


    /**
     * Unit Tests Phalcon\Di :: set() - alias
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diSetAlias(UnitTester $I)
    {
        $I->wantToTest('Di - set() - alias');

        $container = new Di();
        $escaper   = new Escaper();

        $container->set('alias', Escaper::class);
        $container->set(Escaper::class, $escaper);

        $class  = Escaper::class;
        $actual = $container->get('alias');
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'string',
                'escaper',
                Escaper::class,
                Escaper::class
            ],
            [
                'anonymous',
                'escaper',
                function () {
                    return new Escaper();
                },
                Escaper::class
            ],
            [
                'array',
                'escaper',
                [
                    'className' => Escaper::class,
                ],
                Escaper::class
            ],
        ];
    }
}
