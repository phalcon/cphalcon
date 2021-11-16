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

namespace Phalcon\Tests\Integration\Storage\SerializerFactory;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Igbinary;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Storage\SerializerFactory;

use function uniqid;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageSerializerFactoryNewInstance(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - ' . $example[0]);

        $factory = new SerializerFactory();
        $service = $factory->newInstance($example[0]);

        $I->assertInstanceOf(
            $example[1],
            $service
        );
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerFactoryNewInstanceException(IntegrationTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - exception');

        $name = uniqid();
        $I->expectThrowable(
            new Exception('Service ' . $name . ' is not registered'),
            function () use ($name) {
                $factory = new SerializerFactory();
                $service = $factory->newInstance($name);
            }
        );
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            ['base64', Base64::class],
            ['igbinary', Igbinary::class],
            ['json', Json::class],
            ['msgpack', Msgpack::class],
            ['none', None::class],
            ['php', Php::class],
        ];
    }
}
