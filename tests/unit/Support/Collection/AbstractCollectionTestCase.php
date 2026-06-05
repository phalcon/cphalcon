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

namespace Phalcon\Tests\Unit\Support\Collection;

use Phalcon\Support\Collection;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use function array_keys;
use function array_values;

abstract class AbstractCollectionTestCase extends AbstractUnitTestCase
{
    public static function getClasses()
    {
        return [
            [Collection::class],
            [Collection\ReadOnlyCollection::class],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $sample = new stdClass();
        $sample->one = 'two';

        return [
            [
                Collection::class,
                'boolean',
                1,
                true,
            ],
            [
                Collection::class,
                'bool',
                1,
                true,
            ],
            [
                Collection::class,
                'integer',
                "123",
                123,
            ],
            [
                Collection::class,
                'int',
                "123",
                123,
            ],
            [
                Collection::class,
                'float',
                "123.45",
                123.45,
            ],
            [
                Collection::class,
                'double',
                "123.45",
                123.45,
            ],
            [
                Collection::class,
                'string',
                123,
                "123",
            ],
            [
                Collection::class,
                'array',
                $sample,
                ['one' => 'two'],
            ],
            [
                Collection::class,
                'object',
                ['one' => 'two'],
                $sample,
            ],
            [
                Collection::class,
                'null',
                1234,
                null,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'boolean',
                1,
                true,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'bool',
                1,
                true,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'integer',
                "123",
                123,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'int',
                "123",
                123,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'float',
                "123.45",
                123.45,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'double',
                "123.45",
                123.45,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'string',
                123,
                "123",
            ],
            [
                Collection\ReadOnlyCollection::class,
                'array',
                $sample,
                ['one' => 'two'],
            ],
            [
                Collection\ReadOnlyCollection::class,
                'object',
                ['one' => 'two'],
                $sample,
            ],
            [
                Collection\ReadOnlyCollection::class,
                'null',
                1234,
                null,
            ],
        ];
    }

    /**
     * @return string[]
     */
    protected function getDataForGet(): array
    {
        return [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
            'seven' => '',
            'eight' => null,
        ];
    }

    /**
     * @return array
     */
    protected function getDataKeys(): array
    {
        return array_keys($this->getData());
    }

    /**
     * @return string[]
     */
    protected function getData(): array
    {
        return [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
    }

    /**
     * @return string[]
     */
    protected function getDataNoCase(): array
    {
        return [
            'one'   => 'two',
            'THREE' => 'four',
            'five'  => 'six',
        ];
    }

    /**
     * @return array
     */
    protected function getDataValues(): array
    {
        return array_values($this->getData());
    }
}
