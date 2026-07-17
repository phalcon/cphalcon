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

use ArrayAccess;
use IteratorAggregate;
use Phalcon\Contracts\Support\Collection as CollectionContract;
use Phalcon\Support\Collection;
use Phalcon\Support\Collection\CollectionInterface;
use Phalcon\Support\Collection\ReadOnlyCollection;

use function is_subclass_of;

final class ContractsTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionImplementsContract(): void
    {
        $this->assertInstanceOf(CollectionContract::class, new Collection());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionStillImplementsLegacyInterface(): void
    {
        $this->assertInstanceOf(CollectionInterface::class, new Collection());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportContractExtendsArrayAccess(): void
    {
        $this->assertTrue(
            is_subclass_of(CollectionContract::class, ArrayAccess::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportContractExtendsIteratorAggregate(): void
    {
        $this->assertTrue(
            is_subclass_of(CollectionContract::class, IteratorAggregate::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportLegacyInterfaceExtendsContract(): void
    {
        $this->assertTrue(
            is_subclass_of(CollectionInterface::class, CollectionContract::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportReadOnlyCollectionImplementsContract(): void
    {
        $this->assertInstanceOf(CollectionContract::class, new ReadOnlyCollection());
    }
}
