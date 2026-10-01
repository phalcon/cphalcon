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

use Phalcon\Filter\Filter;
use Phalcon\Filter\Sanitize\Trim;
use Phalcon\Filter\Sanitize\Upper;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Filter\InitFilter;
use Phalcon\Tests\Support\Service\HelloService;

final class InitTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testFilterFilterInitKeepsNumericKeys(): void
    {
        $locator = new Filter(['1' => Trim::class]);

        $this->assertTrue($locator->has('1'));
        $this->assertFalse($locator->has('0'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testFilterFilterInitKeepsOtherInstances(): void
    {
        $locator = new InitFilter(['helloFilter' => HelloService::class]);
        $first   = $locator->get('helloFilter');

        $locator->reinit(['upper' => Upper::class]);

        $this->assertSame($first, $locator->get('helloFilter'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testFilterFilterInitMergesServices(): void
    {
        $locator = new InitFilter(['trim' => Trim::class]);

        $locator->reinit(['upper' => Upper::class]);

        $this->assertTrue($locator->has('trim'));
        $this->assertTrue($locator->has('upper'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testFilterFilterInitReplacesServiceAndClearsInstance(): void
    {
        $locator = new InitFilter(['helloFilter' => HelloService::class]);
        $first   = $locator->get('helloFilter');

        $locator->reinit(['helloFilter' => Trim::class]);
        $second = $locator->get('helloFilter');

        $this->assertInstanceOf(HelloService::class, $first);
        $this->assertInstanceOf(Trim::class, $second);
    }
}
