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
use Phalcon\Support\Collection\Exception;
use Phalcon\Support\Collection\ReadOnlyCollection;

final class SetTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionOffsetSetException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection = new ReadOnlyCollection();
        $collection->offsetSet('three', 123);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionSet(): void
    {
        $collection = new Collection();

        $collection->set('three', 'two');

        $expected = 'two';
        $actual = $collection->get('three');
        $this->assertSame($expected, $actual);

        $collection->three = 'Phalcon';

        $expected = 'Phalcon';
        $actual = $collection->get('three');
        $this->assertSame($expected, $actual);

        $collection->offsetSet('three', 123);

        $expected = 123;
        $actual = $collection->get('three');
        $this->assertSame($expected, $actual);

        $collection['three'] = true;

        $actual = $collection->get('three');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionSetArrayException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection = new ReadOnlyCollection();
        $collection['three'] = true;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionSetException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection = new ReadOnlyCollection();
        $collection->set('three', 123);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionSetPropertyException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection = new ReadOnlyCollection();
        $collection->three = 'Phalcon';
    }
}
