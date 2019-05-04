<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Adapter\Memory;

use Codeception\Example;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use stdClass;
use UnitTester;

/**
 * Class GetSetCest
 */
class GetSetCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: get()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-03-31
     */
    public function storageAdapterMemoryGetSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Adapter\Memory - get()/set() - ' . $example[0]);
        $factory = new SerializerFactory();
        $adapter = new Memory($factory);

        $key = uniqid();

        $result = $adapter->set($key, $example[1]);
        $I->assertTrue($result);

        $expected = $example[1];
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'string',
                'random string',
            ],
            [
                'integer',
                123456,
            ],
            [
                'float',
                123.456,
            ],
            [
                'boolean',
                true,
            ],
            [
                'object',
                new stdClass(),
            ],
        ];
    }
}
