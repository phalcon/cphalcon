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
use Phalcon\Support\Collection\ReadOnlyCollection;
use PHPUnit\Framework\Attributes\DataProvider;

final class HasTest extends AbstractCollectionTestCase
{
    /**
     * @dataProvider getClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionHas(
        string $class,
    ): void {
        $data = $this->getData();
        $collection = new $class($data);

        $actual = $collection->has('three');
        $this->assertTrue($actual);

        $actual = $collection->has('THREE');
        $this->assertTrue($actual);

        $actual = $collection->has(uniqid());
        $this->assertFalse($actual);

        $actual = $collection->__isset('three');
        $this->assertTrue($actual);

        $actual = isset($collection['three']);
        $this->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $this->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $this->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionHasSensitive(): void
    {
        $data = $this->getData();
        $collection = new Collection($data, false);

        $actual = $collection->has('three');
        $this->assertTrue($actual);

        $actual = $collection->has('THREE');
        $this->assertFalse($actual);

        $actual = $collection->has(uniqid());
        $this->assertFalse($actual);

        $actual = $collection->__isset('three');
        $this->assertTrue($actual);

        $actual = isset($collection['three']);
        $this->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $this->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $this->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportCollectionReadOnlyHasSensitive(): void
    {
        $data = $this->getData();
        $collection = new ReadOnlyCollection($data, false);

        $actual = $collection->has('three');
        $this->assertTrue($actual);

        $actual = $collection->has('THREE');
        $this->assertFalse($actual);

        $actual = $collection->has(uniqid());
        $this->assertFalse($actual);

        $actual = $collection->__isset('three');
        $this->assertTrue($actual);

        $actual = isset($collection['three']);
        $this->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $this->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $this->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $this->assertFalse($actual);
    }
}
