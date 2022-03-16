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

namespace Phalcon\Tests\Integration\Storage\Serializer;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Igbinary;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\Serializer\Php;

class GetSetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\ :: getData()/setData()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-02-24
     */
    public function storageSerializerGetSetData(
        IntegrationTester $I,
        Example $example
    ) {
        $I->wantToTest('Storage\Serializer\\' . $example[0] . ' - getData()/setData()');

        $data       = ['Phalcon Framework'];
        $class      = $example[1];
        $serializer = new $class();

        $actual = $serializer->getData();
        $I->assertNull($actual);

        $serializer->setData($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'Base64',
                Base64::class,
            ],
            [
                'Igbinary',
                Igbinary::class,
            ],
            [
                'Json',
                Json::class,
            ],
            [
                'Msgpack',
                Msgpack::class,
            ],
            [
                'None',
                None::class,
            ],
            [
                'Php',
                Php::class,
            ],
        ];
    }
}
