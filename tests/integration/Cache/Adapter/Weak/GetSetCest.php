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

namespace Phalcon\Tests\Integration\Cache\Adapter\Weak;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;

class GetSetCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Weak :: get()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @throws HelperException
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function cacheAdapterWeakGetSet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Cache\Adapter\Weak - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $key = uniqid();

        $result = $adapter->set($key, $example[1]);
        $I->assertTrue($result);

        $expected = $example[1];
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                'sdtClass',
                new \stdClass(),
            ],
            [
                'arrayobject',
                new \ArrayObject(),
            ],
            [
                'splObjectStorage',
                new \SplObjectStorage(),
            ],
            [
                'splQueue',
                new \SplQueue(),
            ],
        ];
    }
}
