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

use Phalcon\Support\Collection;
use Phalcon\Support\Collection\Exception;
use Phalcon\Support\Collection\ReadOnlyCollection;

final class RemoveTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionRemove(): void
    {
        $data       = $this->getData();
        $collection = new Collection($data);

        $expected = $data;
        $actual   = $collection->toArray();
        $this->assertSame($expected, $actual);

        $collection->remove('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);

        $collection->remove('FIVE');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);

        $collection->init($data);
        unset($collection['five']);
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);

        $collection->init($data);
        $collection->__unset('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);

        $collection->init($data);
        $collection->offsetUnset('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual = $collection->toArray();
        $this->assertSame($expected, $actual);
    }

    /**
     * remove() calls processKey() one time.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-18
     */
    public function testSupportCollectionRemoveCallsProcessKeyOneTime(): void
    {
        $collection = new class ($this->getData()) extends Collection {
            public int $processKeyCalls = 0;

            protected function processKey(string $element): string
            {
                $this->processKeyCalls++;

                return parent::processKey($element);
            }
        };

        $collection->processKeyCalls = 0;
        $collection->remove('FIVE');

        $this->assertSame(1, $collection->processKeyCalls);
        $this->assertSame(['one' => 'two', 'three' => 'four'], $collection->toArray());
    }

    /**
     * remove() does not call has().
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-18
     */
    public function testSupportCollectionRemoveDoesNotCallHas(): void
    {
        $collection = new class ($this->getData()) extends Collection {
            public int $hasCalls = 0;

            public function has(string $element): bool
            {
                $this->hasCalls++;

                return parent::has($element);
            }
        };

        $collection->remove('five');
        $collection->remove('seven');

        $this->assertSame(0, $collection->hasCalls);
        $this->assertSame(['one' => 'two', 'three' => 'four'], $collection->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionRemoveException(): void
    {
        $data       = $this->getData();
        $collection = new ReadOnlyCollection($data);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection->remove('five');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionRemoveInsensitiveException(): void
    {
        $data       = $this->getData();
        $collection = new ReadOnlyCollection($data);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection->remove('FIVE');
    }

    /**
     * remove() of a key with a different case. With insensitive keys, the
     * entry is removed and the key can be set again. With sensitive keys,
     * only the same case removes the entry.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-18
     */
    public function testSupportCollectionRemoveKeyWithOtherCase(): void
    {
        $collection = new Collection(['Five' => 6, 'one' => 1]);

        $collection->remove('FIVE');
        $this->assertSame(['one' => 1], $collection->toArray());
        $this->assertFalse($collection->has('five'));

        $collection->set('five', 7);
        $this->assertSame(['one' => 1, 'five' => 7], $collection->toArray());

        $collection->remove('seven');
        $this->assertSame(['one' => 1, 'five' => 7], $collection->toArray());

        $collection = new Collection(['Five' => 6], false);

        $collection->remove('five');
        $this->assertSame(['Five' => 6], $collection->toArray());

        $collection->remove('Five');
        $this->assertSame([], $collection->toArray());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionRemoveOffsetUnsetException(): void
    {
        $data       = $this->getData();
        $collection = new ReadOnlyCollection($data);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection->offsetUnset('five');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionRemoveUnderscoreUnsetException(): void
    {
        $data       = $this->getData();
        $collection = new ReadOnlyCollection($data);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        $collection->__unset('five');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionRemoveUnsetException(): void
    {
        $data       = $this->getData();
        $collection = new ReadOnlyCollection($data);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The object is read only');
        unset($collection['five']);
    }
}
