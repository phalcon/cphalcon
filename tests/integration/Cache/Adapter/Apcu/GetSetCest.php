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

namespace Phalcon\Test\Integration\Cache\Adapter\Apcu;

use Codeception\Example;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Cache\CacheFixtureData;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use IntegrationTester;

class GetSetCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: get()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-31
     */
    public function cacheAdapterApcuGetSet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Cache\Adapter\Apcu - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key = uniqid();

        $I->assertTrue(
            $adapter->set($key, $example[1])
        );

        $I->assertEquals(
            $example[1],
            $adapter->get($key)
        );
    }

    private function getExamples(): array
    {
        return CacheFixtureData::getExamples();
    }
}
