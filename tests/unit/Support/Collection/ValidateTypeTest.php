<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Collection;

use InvalidArgumentException;
use Phalcon\Support\Collection;
use stdClass;

final class ValidateTypeTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionAcceptsValidObjectType(): void
    {
        $collection = new Collection([], true, false, stdClass::class);
        $collection->set('a', new stdClass());

        $this->assertInstanceOf(stdClass::class, $collection->get('a'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionAcceptsValidScalarType(): void
    {
        $collection = new Collection([], true, false, 'int');
        $collection->set('a', 1);

        $this->assertSame(1, $collection->get('a'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionFilterPreservesTypeConfiguration(): void
    {
        $collection = new Collection(['a' => 1, 'b' => 2], true, false, 'int');

        $filtered = $collection->filter(static fn ($v) => $v > 1);

        $this->assertSame('int', $filtered->getType());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionRejectsInvalidScalarType(): void
    {
        $this->expectException(InvalidArgumentException::class);

        $collection = new Collection([], true, false, 'int');
        $collection->set('a', 'not an int');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionRejectsWrongObjectType(): void
    {
        $this->expectException(InvalidArgumentException::class);

        $collection = new Collection([], true, false, stdClass::class);
        $collection->set('a', $this);
    }

    /**
     * With a type, setData() calls validateType() for each constructor item
     * and for each set().
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     */
    public function testSupportCollectionSetDataCallsValidateTypeWithType(): void
    {
        $collection = new class (['a' => 1, 'b' => 2], true, false, 'int') extends Collection {
            public int $validateTypeCalls = 0;

            protected function validateType(mixed $value): void
            {
                $this->validateTypeCalls++;

                parent::validateType($value);
            }
        };

        $collection->set('c', 3);

        $this->assertSame(3, $collection->validateTypeCalls);
    }

    /**
     * With no type, setData() does not call validateType().
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     */
    public function testSupportCollectionSetDataSkipsValidateTypeWithoutType(): void
    {
        $collection = new class (['a' => 1, 'b' => 2]) extends Collection {
            public int $validateTypeCalls = 0;

            protected function validateType(mixed $value): void
            {
                $this->validateTypeCalls++;

                parent::validateType($value);
            }
        };

        $collection->set('c', 3);

        $this->assertSame(0, $collection->validateTypeCalls);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionValidatesConstructorData(): void
    {
        $this->expectException(InvalidArgumentException::class);

        new Collection(['a' => 'string-value'], true, false, 'int');
    }
}
