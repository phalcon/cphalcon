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

namespace Phalcon\Tests\Unit\Support\Registry;

use Phalcon\Support\Registry;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

final class GetSetHasTest extends AbstractRegistryTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $sample = new stdClass();
        $sample->one = 'two';

        return [
            [
                'boolean',
                1,
                true,
            ],
            [
                'bool',
                1,
                true,
            ],
            [
                'integer',
                "123",
                123,
            ],
            [
                'int',
                "123",
                123,
            ],
            [
                'float',
                "123.45",
                123.45,
            ],
            [
                'double',
                "123.45",
                123.45,
            ],
            [
                'string',
                123,
                "123",
            ],
            [
                'array',
                $sample,
                ['one' => 'two'],
            ],
            [
                'object',
                ['one' => 'two'],
                $sample,
            ],
            [
                'null',
                1234,
                null,
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testSupportRegistryGet(): void
    {
        $registry = new Registry();

        /**
         * Has
         */
        $actual = $registry->has('three');
        $this->assertFalse($actual);

        /**
         * Set
         */
        $registry->set('three', 'two');

        $actual = $registry->has('three');
        $this->assertTrue($actual);

        $expected = 'two';
        $actual = $registry->get('three');
        $this->assertSame($expected, $actual);

        /**
         * Remove
         */
        $registry->remove('three');

        $actual = $registry->has('three');
        $this->assertFalse($actual);


        /**
         * Has property
         */
        $actual = isset($registry->six);
        $this->assertFalse($actual);

        /**
         * Set
         */
        $registry->six = 789;

        $actual = isset($registry->six);
        $this->assertTrue($actual);

        $expected = 789;
        $actual = $registry->six;
        $this->assertSame($expected, $actual);

        /**
         * Unset
         */
        unset($registry->six);

        $actual = isset($registry->six);
        $this->assertFalse($actual);

        /**
         * offsetExists
         */
        $actual = $registry->offsetExists('four');
        $this->assertFalse($actual);

        /**
         * offsetSet
         */
        $registry->offsetSet('four', 123);

        /**
         * offsetExists
         */
        $actual = $registry->offsetExists('four');
        $this->assertTrue($actual);

        /**
         * offsetGet
         */
        $expected = 123;
        $actual = $registry->offsetGet('four');
        $this->assertSame($expected, $actual);

        /**
         * offsetUnset
         */
        $registry->offsetUnset('four');

        $actual = $registry->offsetExists('four');
        $this->assertFalse($actual);

        /**
         * isset
         */
        $actual = isset($registry['five']);
        $this->assertFalse($actual);

        /**
         * set
         */
        $registry['five'] = 456;

        $actual = isset($registry['five']);
        $this->assertTrue($actual);

        /**
         * Get
         */
        $expected = 456;
        $actual = $registry['five'];
        $this->assertSame($expected, $actual);

        /**
         * Unset
         */
        unset($registry['five']);

        $actual = isset($registry['five']);
        $this->assertFalse($actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @since        2019-10-12
     */
    #[DataProvider('getExamples')]
    public function testSupportRegistryGetCast(
        string $cast,
        mixed $value,
        mixed $expected,
    ): void {
        $registry = new Registry(
            [
                'value' => $value,
            ],
        );

        /**
         * Get
         */
        $actual = $registry->get('value', null, $cast);
        $this->assertEquals($expected, $actual);
    }
}
