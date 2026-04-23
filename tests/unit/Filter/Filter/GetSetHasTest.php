<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Filter;

use Closure;
use Phalcon\Filter\Filter;
use Phalcon\Tests\Support\Service\HelloService;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetHasTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterGetSetHasGetSame(): void
    {
        $locator = new Filter(['helloFilter' => HelloService::class]);
        $actual  = $locator->has('helloFilter');
        $this->assertTrue($actual);

        /** @var object $service */
        $expected = 'Hello Phalcon [count: 1]';
        $actual   = $locator->get('helloFilter')('Phalcon');
        $this->assertSame($expected, $actual);

        $expected = 'Hello Phalcon [count: 2]';
        $actual   = $locator->get('helloFilter')('Phalcon');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterGetSetHasHas(): void
    {
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Filter($services);

        $actual = $locator->has('helloFilter');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterGetSetHasSet(): void
    {
        $locator = new Filter();

        $actual = $locator->has('helloFilter');
        $this->assertFalse($actual);

        $locator->set(
            'helloFilter',
            function () {
                return new HelloService();
            }
        );
        $actual = $locator->has('helloFilter');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterGetSetHasSetClosure(): void
    {
        $locator = new Filter();

        $actual = $locator->has('testappend');
        $this->assertFalse($actual);

        $locator->set(
            'testappend',
            function ($input) {
                return $input . 'test';
            }
        );

        $value  = 'cheese';
        $actual = $locator->sanitize($value, 'testappend');

        $expected = $value . 'test';
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterLocatorGetSetHasGet(): void
    {
        $services = [
            'helloFilter' => function () {
                return new HelloService();
            },
        ];

        $locator = new Filter($services);
        $actual  = $locator->has('helloFilter');
        $this->assertTrue($actual);

        $class  = Closure::class;
        $actual = $locator->get('helloFilter');
        $this->assertInstanceOf($class, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterCall(): void
    {
        $locator = new Filter(
            [
                'trim' => \Phalcon\Filter\Sanitize\Trim::class,
            ]
        );

        $actual = $locator->trim('  hello world  ');
        $this->assertSame('hello world', $actual);
    }
}
