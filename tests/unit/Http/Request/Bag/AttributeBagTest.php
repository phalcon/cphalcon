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

namespace Phalcon\Tests\Unit\Http\Request\Bag;

use Phalcon\Http\Request\Bag\AbstractBag;
use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Http\Request\Exceptions\NullKeyException;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class AttributeBagTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagArrayAccess(): void
    {
        $bag = new AttributeBag();

        $bag['user'] = 'nikos';

        $this->assertTrue(isset($bag['user']));
        $this->assertSame('nikos', $bag['user']);

        unset($bag['user']);

        $this->assertFalse(isset($bag['user']));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagExtendsAbstractBag(): void
    {
        $bag = new AttributeBag();

        $this->assertInstanceOf(AbstractBag::class, $bag);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagGetReturnsDefaultWhenMissing(): void
    {
        $bag = new AttributeBag();

        $this->assertSame('fallback', $bag->get('nope', 'fallback'));
        $this->assertNull($bag->get('nope'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagGetReturnsDefaultWhenValueIsNull(): void
    {
        $bag = new AttributeBag(['key' => null]);

        $this->assertSame('fallback', $bag->get('key', 'fallback'));
        $this->assertTrue($bag->has('key'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagGetReturnsRawValue(): void
    {
        $bag = new AttributeBag(['user' => 'nikos']);

        $this->assertSame('nikos', $bag->get('user'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagIsIterableAndCountable(): void
    {
        $bag = new AttributeBag(
            [
                'one' => '1',
                'two' => '2',
            ]
        );

        $this->assertCount(2, $bag);

        $seen = [];
        foreach ($bag as $key => $value) {
            $seen[$key] = $value;
        }

        $this->assertSame(
            [
                'one' => '1',
                'two' => '2',
            ],
            $seen
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagOffsetSetRejectsNullKey(): void
    {
        $bag = new AttributeBag();

        $this->expectException(NullKeyException::class);
        $this->expectExceptionMessage(
            'A null key is not allowed; bag elements must be '
            . 'written with a string key.'
        );

        $bag[] = 'value';
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagSetAllAndRemove(): void
    {
        $bag = new AttributeBag();

        $this->assertSame([], $bag->all());

        $bag->set('user', 'nikos');

        $this->assertTrue($bag->has('user'));
        $this->assertSame(['user' => 'nikos'], $bag->all());

        $bag->remove('user');

        $this->assertFalse($bag->has('user'));
        $this->assertSame([], $bag->all());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagTypedReaders(): void
    {
        $bag = new AttributeBag(
            [
                'flag'  => '1',
                'name'  => 'phalcon',
                'port'  => '443',
                'ratio' => '0.75',
                'tags'  => ['a', 'b'],
            ]
        );

        $this->assertTrue($bag->getBool('flag'));
        $this->assertSame('phalcon', $bag->getString('name'));
        $this->assertSame(443, $bag->getInt('port'));
        $this->assertSame(0.75, $bag->getFloat('ratio'));
        $this->assertSame(['a', 'b'], $bag->getArray('tags'));
        $this->assertSame([], $bag->getArray('name'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestBagTypedReadersUseDefaultsWhenMissing(): void
    {
        $bag = new AttributeBag();

        $this->assertFalse($bag->getBool('nope'));
        $this->assertTrue($bag->getBool('nope', true));
        $this->assertSame('', $bag->getString('nope'));
        $this->assertSame('x', $bag->getString('nope', 'x'));
        $this->assertSame(0, $bag->getInt('nope'));
        $this->assertSame(7, $bag->getInt('nope', 7));
        $this->assertSame(0.0, $bag->getFloat('nope'));
        $this->assertSame(1.5, $bag->getFloat('nope', 1.5));
        $this->assertSame([], $bag->getArray('nope'));
        $this->assertSame(['a'], $bag->getArray('nope', ['a']));
    }
}
